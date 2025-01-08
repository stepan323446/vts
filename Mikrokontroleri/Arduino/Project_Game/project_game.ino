#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27,  16, 2);

/////////////////////////
// Game Engine

// Config
const int rowDisplay = 2;
const int columnDisplay = 32;
const int maxGameObjects = 10;
const int gameSpeedIncrease = 1;
const int minGameSpeed = 50;
int gameSpeed = 200;


int lengthGameObjects = 0;
int gameOver = 0;
char* gameOverText = "Game Over";
int __gameOverOn = 0;

// LCD Display 2x16 (Game border is 2x32)
char gameDisplay[rowDisplay][columnDisplay];

// GameObject
struct GameObject {
  // Position
  int x;
  int y;
  // Render char
  char render;
};
// All objects on scene
struct GameObject objects[maxGameObjects];

// New game object on scene
GameObject* create_object(int x, int y, byte render) {
    GameObject obj = {x, y, (char)render};
    objects[lengthGameObjects++] = obj;
    return &objects[lengthGameObjects - 1]; 
}

// gameDisplay is empty (not LCD)
void clear_display() {
  for(int r = 0; r < rowDisplay; r++)
    for(int c = 0; c < columnDisplay; c++)
      gameDisplay[r][c] = ' ';
}

// Render gameDisplay and objects on LCD
void render_display() {
  clear_display();

  // Place gameObjects on gameDisplay
  for(int i = 0; i < lengthGameObjects; i++) {
    gameDisplay[objects[i].y][objects[i].x] = objects[i].render;
  }

  // Set gameDisplay on LCD
  lcd.setCursor(0, 0);
  lcd.print(gameDisplay[0]);
  lcd.setCursor(0, 1);
  lcd.print(gameDisplay[1]);
  lcd.setCursor(0, 0);

  // delay gameSpeed
  gameSpeed -= gameSpeedIncrease;
  if(minGameSpeed > gameSpeed)
    gameSpeed = minGameSpeed;

  delay(gameSpeed);
}

// only on setup()
void welcome_screen(char* welcome_row_1, char* welcome_row_2) {
  lcd.setCursor(0, 0);
  lcd.print(welcome_row_1);

  lcd.setCursor(0, 1);
  lcd.print(welcome_row_2);

  lcd.setCursor(0, 0);
}

void game_over_screen(int score) {
  // If gameOver is already on
  if(__gameOverOn)
    return;
  
  // gameOver is on
  __gameOverOn = 1;

  // clear all gameObjects from gameDisplay 
  clear_display();

  // set cleared gameDisplay on LCD
  lcd.setCursor(0, 0);
  lcd.print(gameDisplay[0]);
  lcd.setCursor(0, 1);
  lcd.print(gameDisplay[1]);

  // print gameOverText on LCD
  lcd.setCursor(0, 0);
  lcd.print(gameOverText);

  // print score
  if(score > 9999)
    score = 9999;

  char textScore[15];
  sprintf(textScore,"Score: %d", score);
  lcd.setCursor(0, 1);
  lcd.print(textScore);
}
/////////////////////////

// Distance from right side of display
int enemy1Distance = 3;
int enemy2Distance = 7;
int enemy3Distance = 12;
int enemy4Distance = 16;

// Display character for player
int byteEnemyNum = 1;
byte enemyRender[8] = {
  B01110,
  B11111,
  B10101,
  B11111,
  B11111,
  B11111,
  B10101,
  B10001
};
int bytePlayerNum = 2;
byte playerRender[8] = {
  B00000,
  B00000,
  B00100,
  B10110,
  B11111,
  B10110,
  B00100,
  B00000
};
int byteAidNum = 3;
byte aidKitRender[8] = {
  B00000,
  B11011,
  B11111,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000
};

// Player Stats
const int maxPlayerHealth = 3;
int playerHealth = maxPlayerHealth;
int score = 0;
// AidKit
const int maxTicksKit = 10;
int ticksKit = maxTicksKit;
int isKitDropped = 0;

int healthLED[maxPlayerHealth] = { 
  2, 3, 4
};

// Create Kits
GameObject* aidKit = create_object(16, random(2), byte(byteAidNum));

// Create enemies from right side and randomize row
GameObject* enemy1 = create_object(columnDisplay - enemy1Distance, random(2), byte(byteEnemyNum));
GameObject* enemy2 = create_object(columnDisplay - enemy2Distance, random(2), byte(byteEnemyNum));
GameObject* enemy3 = create_object(columnDisplay - enemy3Distance, random(2), byte(byteEnemyNum));
GameObject* enemy4 = create_object(columnDisplay - enemy4Distance, random(2), byte(byteEnemyNum));

// Create player
GameObject* player = create_object(0, 0, byte(bytePlayerNum));

void enemy_walk(GameObject* enemy);

// Arduino methods
void setup() {
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.noCursor();
  // Create char for GameObjects
  lcd.createChar(byteEnemyNum, enemyRender);
  lcd.createChar(bytePlayerNum, playerRender);
  lcd.createChar(byteAidNum, aidKitRender);

  // Health display
  for(int i=0; i < playerHealth; i++) {
    pinMode(healthLED[i], OUTPUT);
    digitalWrite(healthLED[i], HIGH);
  }

  pinMode(7, INPUT_PULLUP);
  randomSeed(analogRead(0));

  Serial.begin(9600);

  welcome_screen("You are airplane!", "Avoid the UFO!");
  delay(2000);
}
void loop() {
  // Control player (change row)
  player->y = !digitalRead(7);

  if(!gameOver) {
    // Move enemies
    enemy_walk(enemy1, 1);
    enemy_walk(enemy2, 2);
    enemy_walk(enemy3, 3);
    enemy_walk(enemy4, 4);

    // Move kit
    ticksKit--;
    if(ticksKit < 0)
      isKitDropped = 1;
    
    if(isKitDropped)
      dropAidKit();

    // Render game frame
    render_display();
  }
  else {
    // Game end
    game_over_screen(score);
  }
}
void dropAidKit() {
  aidKit->x -= 1;
  
  // If kit behind scene, back to right screen corner
  if(aidKit->x < 0) {
    aidKit->x = 16;
    aidKit->y = random(2);
    isKitDropped = 0;
    ticksKit = maxTicksKit;
  }
  // Pick up kit
  if(aidKit->x == player->x && aidKit->y == player->y) {
    playerHealth++;
    if(playerHealth > 3)
      playerHealth = 3;

    // Display health
    for(int i = 0; i < playerHealth; i++) {
      digitalWrite(healthLED[i], HIGH);
    }
  }
}
void enemy_walk(GameObject* enemy, int enemyNumber) {
  // Move player
  enemy->x -= 1;

  // If enemy behind scene, back to right screen corner
  if(enemy->x < 0) {
    enemy->x = 16;
    enemy->y = random(2);
  }
  // If an enemy bumps into a player
  if(enemy->x == player->x && enemy->y == player->y) {
    // Hit
    playerHealth -= 1;

    // Display health
    digitalWrite(healthLED[playerHealth], LOW);

    // Die
    if(playerHealth == 0)
      gameOver = 1;
  } 
  // If player and enemy in one column (and not hit) - score++
  else if (enemy->x == player->x) {
    score++;
  }
    
} 


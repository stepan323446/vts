#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27,  16, 2);

/////////////////////////
// Game Engine

// Config
const int rowDisplay = 2;
const int columnDisplay = 32;
const int maxGameObjects = 10;
const int gameSpeed = 500;

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
GameObject* create_object(int x, int y, char render) {
    GameObject obj = {x, y, render};
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

void game_over_screen() {
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
  lcd.setCursor(0, 0);

  // print gameOverText on LCD
  lcd.print(gameOverText);
}
/////////////////////////

// Distance from right side of display
int enemy1Distance = 3;
int enemy2Distance = 7;
int enemy3Distance = 12;
int enemy4Distance = 16;

// Create enemies from right side and randomize row
GameObject* enemy1 = create_object(columnDisplay - enemy1Distance, random(2), '0');
GameObject* enemy2 = create_object(columnDisplay - enemy2Distance, random(2), '0');
GameObject* enemy3 = create_object(columnDisplay - enemy3Distance, random(2), '0');
GameObject* enemy4 = create_object(columnDisplay - enemy4Distance, random(2), '0');

// Create player
GameObject* player = create_object(0, 0, 'x');

void enemy_walk(GameObject* enemy);

// Arduino methods
void setup() {
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.noCursor();

  pinMode(7, INPUT_PULLUP);
  randomSeed(analogRead(0));

  Serial.begin(9600);

  welcome_screen("You are X!", "Avoid the 0s!");
  delay(2000);
}

void loop() {
  // Control player (change row)
  player->y = !digitalRead(7);

  if(!gameOver) {
    // Move enemies
    enemy_walk(enemy1);
    enemy_walk(enemy2);
    enemy_walk(enemy3);
    enemy_walk(enemy4);

    // Render game frame
    render_display();
  }
  else {
    // Game end
    game_over_screen();
  }
}

void enemy_walk(GameObject* enemy) {
  // Move player
  enemy->x -= 1;

  // If enemy behind scene, back to right screen corner
  if(enemy->x < 0) {
    enemy->x = 16;
    enemy->y = random(2);
  }
  // If an enemy bumps into a player
  if(enemy->x == player->x && enemy->y == player->y) {
    gameOver = 1;
  }
}

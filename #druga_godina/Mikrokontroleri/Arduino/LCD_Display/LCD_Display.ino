#include <LiquidCrystal.h>

int packagesAmount = 1024;
int packages = 0;
int isCleared = 0;
int speed = 500;
int speedIncrease = 1;

LiquidCrystal lcd(12, 11, 2, 3, 4, 5);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.print("Install...");
  
  lcd.noCursor();
}

void loop() {
  lcd.setCursor(0, 1);
  if(packages == packagesAmount + 1) {
    lcd.setCursor(0, 0);
    if(!isCleared)
      lcd.print("                ");
    isCleared = 1;
    lcd.print("MiSide installed");
  }
  else {
    lcd.print("[");
    lcd.print(packages);
    lcd.print("/");
    lcd.print(packagesAmount);
    lcd.print("]");
    
    if(packages / 100 == speedIncrease) {
      speed -= 100;
      if(speed < 100)
        speed = 100;

      speedIncrease++;
    }
    packages++;

    delay(speed);
  }
}

// https://people.vts.su.ac.rs/~pmiki/DALJINSKA_NASTAVA_MIKROKONTROLERI/28.04/
#include <TimerOne.h>

int LED_Yellow_Status = 0;
int LED_Red_Status = 1;
const int RED_LED = 9;
const int YELLOW_LED = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);

  Timer1.initialize(1000000);
  Timer1.attachInterrupt(BlinkYellow);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RED_LED, LED_Red_Status);
  LED_Red_Status = !LED_Red_Status;
  delay(250);
}
void BlinkYellow() {
  digitalWrite(YELLOW_LED, LED_Yellow_Status);
  LED_Yellow_Status = !LED_Yellow_Status;
}

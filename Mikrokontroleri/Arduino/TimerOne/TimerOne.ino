// https://people.vts.su.ac.rs/~pmiki/DALJINSKA_NASTAVA_MIKROKONTROLERI/28.04/
#include <TimerOne.h>

// Software interrupt
int LED_Yellow_Status = 0;
int LED_Red_Status = 1;
const int RED_LED = 9;
const int YELLOW_LED = 10;

// Hardware interrupt
const int LET_OUT = 13;
const int LED_IN = 2; // Can only 2 or 3
int LED_is_on = 0;

void setup() {
  // Software interrupt
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);

  Timer1.initialize(1000000);
  Timer1.attachInterrupt(BlinkYellow);

  // Hardware interrupt
  pinMode(LET_OUT, OUTPUT);
  pinMode(LED_IN, INPUT);
  attachInterrupt(digitalPinToInterrupt(LED_IN), ButtonPressed, RISING);
}

void loop() {
  // Software interrupt
  digitalWrite(RED_LED, LED_Red_Status);
  LED_Red_Status = !LED_Red_Status;
  delay(250);
}

// Method for software interrupt: blink yellow LED
void BlinkYellow() {
  digitalWrite(YELLOW_LED, LED_Yellow_Status);
  LED_Yellow_Status = !LED_Yellow_Status;
}

// Method for hardware interrupt: when button is pressed, change LED_is_on
void ButtonPressed() {
    LED_is_on = !LED_is_on;
    digitalWrite(LET_OUT, LED_is_on);
}

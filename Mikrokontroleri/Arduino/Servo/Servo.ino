#include <Servo.h>
#include <stdlib.h>  // Для rand() и srand()
#include <time.h>    // Для time()

Servo myservo; 
int pos = 0;
int newPos = 0;   


void setup() {
  myservo.attach(9);
  
}


void loop() {
  int x = analogRead(A0);
  int pos = map(x, 0, 1023, 0, 180);

  myservo.write(pos);
}

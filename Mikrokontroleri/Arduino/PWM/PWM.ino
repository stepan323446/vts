int led1 = 9;
int led2 = 10;
int brightness = 0;

int fadeAmount = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(led1, brightness);
  analogWrite(led2, 255 - brightness);
  brightness += fadeAmount;

  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }

  delay(20);
}

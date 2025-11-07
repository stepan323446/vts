int ledPin = 9;
int ledPinReverse = 10;
int ADPin = A0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ledPinReverse, OUTPUT);
  pinMode(ADPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  int brightness = analogRead(ADPin) * 255.0 / 1023.0;
  analogWrite(ledPin, brightness);
  analogWrite(ledPinReverse, 255 - brightness);

  delay(20);
}
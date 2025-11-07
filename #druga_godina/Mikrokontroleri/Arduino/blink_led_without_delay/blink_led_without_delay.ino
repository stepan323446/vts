const int LEDPIN = 9;
const long INTERVAL = 1000;

int ledState = 0;
unsigned long previousMills = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMills = millis();

  if(currentMills - previousMills >= INTERVAL) {
    previousMills = currentMills;

    ledState = !ledState;

    digitalWrite(LEDPIN, ledState);
  }
}

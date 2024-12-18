const int ledLength = 4;
const int ledPins[ledLength] = { 8, 9, 10, 12 };
const int ledIntervals[ledLength] = { 1000, 500, 500, 500 };

long interval = 500;
int currentIndex = 0;
unsigned long previousMills = 0;

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < ledLength; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMills = millis();

  if(currentMills - previousMills >= interval) {
    previousMills = currentMills;

    for(int i = 0; i < ledLength; i++) {
      if(currentIndex == i)
        digitalWrite(ledPins[i], HIGH);
      else
        digitalWrite(ledPins[i], LOW);
    }
    interval = ledIntervals[currentIndex];

    currentIndex++;
    if(currentIndex > ledLength - 1)
      currentIndex = 0;

    
  }
}

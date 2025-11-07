void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Power On");
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long ms = millis();
  int secondAmount = ms / 1000;
  int seconds = secondAmount % 60; 
  int minutes = secondAmount / 60;
  Serial.print("Min: ");
  Serial.print(minutes);
  Serial.print(", ");
  Serial.print("Sec: ");
  Serial.println(seconds);

  delay(1000);
}

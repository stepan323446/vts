void setup() {
  pinMode(A0, INPUT);
  pinMode(12, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int x = analogRead(A0);
  
  Serial.print("AD out = ");
  Serial.print(x);
  Serial.print("; ");

  float volt = 5.0 * x / 1023.0;

  Serial.print("Volt = ");
  Serial.print(volt);
  Serial.print("; ");

  if(volt < 4.0) {
    Serial.print("Light On");
    digitalWrite(12, HIGH);
  }
  else {
    Serial.print("Light Off!");
    digitalWrite(12, LOW);
  }

  Serial.println("");
  delay(200);  
}

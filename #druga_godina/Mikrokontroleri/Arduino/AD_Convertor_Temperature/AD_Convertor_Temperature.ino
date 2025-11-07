void setup() {
  pinMode(A1, INPUT);
  
  // 5, 6, 7, 8
  for(int i = 5; i < 9; i++)
    pinMode(i, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int x = analogRead(A1);
  
  Serial.print("AD out = ");
  Serial.print(x);
  Serial.print("; ");

  float volt = 5.0 * x / 1023.0;

  Serial.print("Volt = ");
  Serial.print(volt);
  Serial.print("; ");

  float temp = 100.0 * (volt - 0.5);

  Serial.print("Temp = ");
  Serial.print(temp);
  Serial.print("C ");

  Serial.println("");

  delay(500);  
}

int y1 = 0;

void setup() {
  Serial.begin(9600); 
}

void loop() {
  Serial.println(y1);
  y1++;
  if(y1 == 255){
    y1 = 0;
  }
}
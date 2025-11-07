int default_delay = 500;
int a_constant_delay = 500;
int b_constant_delay = 1000;
int a_delay;
int b_delay;

int a = 1;    // 12
int b = 1;    // 13

void switchLED(int led_num, int value) {
  if(value)
    digitalWrite(led_num, HIGH);
  else
    digitalWrite(led_num, LOW);

  if(led_num == 12)
    a = value;
  else
    b = value;
}

void periodAB() {
  a_delay -= default_delay;
  b_delay -= default_delay;

  if(a_delay <= 0) {
    a_delay = a_constant_delay;
    switchLED(12, !a);
    Serial.println("LED 12 is switched");
  }
  if(b_delay <= 0) {
    b_delay = b_constant_delay;
    switchLED(13, !b);
    Serial.println("LED 13 is switched");
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);

  a_delay = a_constant_delay;
  b_delay = b_constant_delay;

  switchLED(12, a);
  switchLED(13, b);  

  Serial.begin(9600);
}

void loop() {
  periodAB();
  delay(default_delay);
}

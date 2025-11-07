#define BLYNK_TEMPLATE_ID "TMPL47mtvjnJt"
#define BLYNK_TEMPLATE_NAME "Control LED"
#define BLYNK_AUTH_TOKEN "-6N9LgQV4CUD77wkFWvF7ffb8C2pChHW"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

class AdvancedLed
{
  private:
    int defaultBrightness;
    int ledpin;
    
  public:
    AdvancedLed(int ledpin, int brightness = 255)
    {
      this->ledpin = ledpin;
      defaultBrightness = brightness;
    }
    void Blink(int delayMs = 1000)
    {
      delay(delayMs);
      analogWrite(ledpin, 0);
      delay(delayMs);
      analogWrite(ledpin, defaultBrightness);
    }
    void Disable()
    {
      analogWrite(ledpin, 0);
    }
    void Enable()
    {
      analogWrite(ledpin, 255);
    }
    void Brightness(int bridgt = 255)
    {
      analogWrite(ledpin, bridgt);
    }
};

char ssid[] = "304net";
char pass[] = "vts12345";

// Пины для светодиодов
AdvancedLed led1 = AdvancedLed(D3, 255);
AdvancedLed led2 = AdvancedLed(D4, 255);

void setup() {
  Serial.begin(115200);

  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

// Обработка виртуального пина V0
BLYNK_WRITE(V0) {
  int pinValue = param.asInt(); // получаем 0 или 1
  if(pinValue)
    led1.Enable();
  else
    led1.Disable();
}

// Обработка виртуального пина V1
BLYNK_WRITE(V1) {
  int pinValue = param.asInt();
  led2.Brightness(pinValue);
}

void loop() {
  Blynk.run();
}

#define SOUND_SPEED 0.034
#define PRECISION 20

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
};
class AdvancedSonicSensor
{
  private:
    int precisionMode = 0;
    int trigPin;
    int echoPin;
    long duration;

    int offsetPrecision = PRECISION;
    long offsetDurations[PRECISION];

    long _getSignal()
    {
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);

      return pulseIn(echoPin, HIGH);
    }

  public:
    AdvancedSonicSensor(int trigPin, int echoPin)
    {
      this->trigPin = trigPin;
      this->echoPin = echoPin;
    }

    void setup(int precisionMode = 0)
    {
      Serial.begin(115200);
      pinMode(trigPin, OUTPUT);
      pinMode(echoPin, INPUT);
      this->precisionMode = precisionMode;
    }
    void pulseSignal()
    {
      if(!precisionMode)
      {
        duration = _getSignal();
        return;
      }
      for(int i = 0; i < offsetPrecision; i++)
      {
        offsetDurations[i] = _getSignal();
      }
    }
    float getDistanceCm()
    {
      if(!precisionMode)
      {
        return duration * SOUND_SPEED/2;
      }
      int offsetCm = 0;
      for(int i = 0; i < offsetPrecision; i++)
      {
        offsetCm += offsetDurations[i] * SOUND_SPEED/2;
      }
      return offsetCm / offsetPrecision;
    }
};

AdvancedLed advLed = AdvancedLed(D4, 255);
AdvancedSonicSensor advSonic = AdvancedSonicSensor(14, 5);

const int distanceLed = 5;

void setup() {
  
}

void loop() {
  advLed.Blink();
}
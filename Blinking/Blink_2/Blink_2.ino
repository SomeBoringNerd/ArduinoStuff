#define LIGHT_SENSOR_PIN 36
#define LED_BUILTIN 2

void setup() 
{  
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() 
{
  float analogValue = analogRead(LIGHT_SENSOR_PIN);
  Serial.println(((analogValue / 4095) * 100));
  delay(150);
}

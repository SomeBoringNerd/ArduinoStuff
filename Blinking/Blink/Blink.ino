#define LED_BUILTIN 2

// s'execute au démarrage
void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
}

// s'execute en bouble
void loop()
{
    digitalWrite(LED_BUILTIN, HIGH);
    delay(FrequencyToMS(5));
    digitalWrite(LED_BUILTIN, LOW);
    delay(FrequencyToMS(5));
}

// converti une fréquence en ms afin que le programme 
int FrequencyToMS(int hz)
{
    return (1000 / hz) / 2;
}

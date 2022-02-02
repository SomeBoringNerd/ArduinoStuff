#define LED_BUILTIN 2

// s'execute au démarrage
void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(36, INPUT);
}

// s'execute en bouble
void loop()
{ 
    if(digitalRead(36)){
        digitalWrite(LED_BUILTIN, HIGH);
    }
    // note : ne pas utiliser le GND de la pate 18
    else {
        digitalWrite(LED_BUILTIN, LOW);
    }
}

#define LED_LIGHT 6

#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pixels(60, LED_LIGHT, NEO_GRB + NEO_KHZ800);

// s'execute au démarrage
void setup()
{
  pixels.begin();
  for (int i = 0; i < 56; i++) {
    pixels.clear();
    turn_light(i + 3, 255, 0, 0);
    turn_light(i + 2, 0, 255, 0);
    turn_light(i + 1, 0, 0, 255);
    turn_light(i, 255, 255, 0);
    pixels.show();
    delay(25);
  }
}

// s'execute en bouble
void loop()
{
  
}

/**
   @DESC : allume une lampe avec la couleur qu'on veut
   @PARAM color : une des 16 couleurs 16 bits
   @PARAM light_pos : quelle LED on veut modifier ? (int non nul, ni négatif, mais normalement, seul un débile ferai ça donc pas besoin de faire de fallback)
*/
void turn_light(int pos, int red, int blue, int green)
{
  pixels.setPixelColor(pos, pixels.Color(red, blue, green));
}

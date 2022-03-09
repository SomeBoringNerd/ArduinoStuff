#define LED_LIGHT 6
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel pixels(60, LED_LIGHT, NEO_GRB + NEO_KHZ800);

bool already_looping = false;

void setup()
{
  pixels.begin();
  pixels.clear();
  pinMode(2, INPUT);
}

void loop()
{
    // s'éxécute si le bouton est appuyé et que la routine ne tourne pas
    if(digitalRead(2) && !already_looping){
      loop_again();
    }
}

//boucle le programe quand on appuie sur le bouton pressoir et qu'il n'est pas déjà en train de tourner
// afin de ne pas réécrire le même code trop de fois
void loop_again()
{
  already_looping = true;
  for (int i = 0; i < 57; i++) {
    pixels.clear();
    turn_light(i + 3, 255, 0, 0); // rouge
    turn_light(i + 2, 0, 255, 0); // vert
    turn_light(i + 1, 0, 0, 255); // bleu
    turn_light(i, 255, 255, 0);   // jaune
    pixels.show();
    delay(25);
  }
  already_looping = false;
}

/**
   @DESC : allume une lampe avec la couleur qu'on veut (wrapper plus simple d'usage)
   @PARAM light_pos : quelle LED on veut modifier ? (int non nul, ni négatif, mais normalement, seul un débile ferai ça donc pas besoin de faire de fallback)
   @PARAM red, blue, green : couleur en RGB
*/
void turn_light(int pos, int red, int blue, int green)
{
  pixels.setPixelColor(pos, pixels.Color(red, blue, green));
}

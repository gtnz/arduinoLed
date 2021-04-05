#include "FastLED.h"
 
// Указываем, какое количество пикселей у нашей ленты.
#define LED_COUNT 8
 
// Указываем, к какому порту подключен вход ленты DIN.
#define LED_PIN 1
 
// Создаем переменную strip для управления нашей лентой.
CRGB strip[LED_COUNT];

int NLed(int a) {
  return(a%(LED_COUNT-1)); 
}

void RunUp() {
  for (int i = 0; i < LED_COUNT; i++) {
    if (i != 0) {
      strip[i-1] = CRGB::Black;
      strip[i] = CRGB::Red;
      strip[i+1] = CRGB::Red;
    }
    else {
      strip[LED_COUNT-1] = CRGB::Black;
      strip[i] = CRGB::Red;
    }
    FastLED.show();
    delay(500);
  }
}

void setup()
{
  // Добавляем ленту
  FastLED.addLeds<WS2812B, LED_PIN, RGB>(strip, LED_COUNT);
}
 
void loop()
{
  RunUp();
}

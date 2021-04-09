#include "FastLED.h"
 
// Указываем, какое количество пикселей у нашей ленты.
#define LED_COUNT 8
 
// Указываем, к какому порту подключен вход ленты DIN.
#define LED_PIN 1

// Задержка между переключениеми точек.
#define DELAY 200 

// Управляющие пины
#define CONTROL_PIN1=0
#define CONTROL_PIN2=4
 
// Создаем переменную strip для управления нашей лентой.

uint8_t n = 0;

CRGB strip[LED_COUNT];

void NextUp(uint8_t k) {
  for (int i = 0; i < LED_COUNT; i++) {
    strip[i] = CRGB::Black;
  }
  if (k == LED_COUNT-1){ 
    strip[k] = CRGB::Red;
    strip[0] = CRGB::Red;
    strip[1] = CRGB::Red;
  }
  if (k ==  LED_COUNT-2) {
    strip[k] = CRGB::Red;
    strip[k+1] = CRGB::Red;
    strip[0] = CRGB::Red;    
  }
  else {
    strip[k] = CRGB::Red;
    strip[k+1] = CRGB::Red;
    strip[k+2] = CRGB::Red;
  }
  FastLED.show();
}

void NextDown(uint8_t k) {
  for (int i = 0; i < LED_COUNT; i++) {
    strip[i] = CRGB::Black;
  }
  if (k == 0) {
    strip[k] = CRGB::Red;
    strip[LED_COUNT-1] = CRGB::Red;
    strip[LED_COUNT-2] = CRGB::Red;    
  }
  else {
    if (k == 1) {
        strip[k] = CRGB::Red;
        strip[k-1] = CRGB::Red;
        strip[LED_COUNT-1] = CRGB::Red;
    } else {
      strip[k] = CRGB::Red;
      strip[k-1] = CRGB::Red;
      strip[k-2] = CRGB::Red;
    }
  }
  FastLED.show();
}

void setup()
{
  // Добавляем ленту
  FastLED.addLeds<WS2812B, LED_PIN, RGB>(strip, LED_COUNT);
  pinMode(CONTROL_PIN1, INPUT);
  pinMode(CONTROL_PIN2, INPUT);
}
 
void loop()
{
//if (false) {
  if (digitalRead(CONTROL_PIN1) && !digitalRead(CONTROL_PIN2)) {
    if (n<=0)  
      n=LED_COUNT;
    n=n-1;
    NextDown(n);
    delay(DELAY);
  } else 
    if (!digitalRead(CONTROL_PIN1) && digitalRead(CONTROL_PIN2)) {
      if (n>=LED_COUNT-1)
        n=-1;
      n=n+1;
      NextUp(n);
      delay(DELAY);
    } else
      if (!digitalRead(CONTROL_PIN1) && !digitalRead(CONTROL_PIN2)) {
        for (int i = 0; i < LED_COUNT; i++) {
          strip[i] = CRGB::Red;
          FastLED.show();
        }
      } else
        for (int i = 0; i < LED_COUNT; i++) {
          strip[i] = CRGB::Green;
          FastLED.show();
      }
//  } 
}

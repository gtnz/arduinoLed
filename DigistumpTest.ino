#include "FastLED.h"
 
// Указываем, какое количество пикселей у нашей ленты.
#define LED_COUNT 8
 
// Указываем, к какому порту подключен вход ленты DIN.
#define LED_PIN 1
 
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
  }  
  else {
    strip[k] = CRGB::Red;
    strip[k+1] = CRGB::Red;
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
  }
  else {
    strip[k] = CRGB::Red;
    strip[k-1] = CRGB::Red;
  }
  FastLED.show();
}

void RunUp() {
  for (uint8_t i = 0; i < LED_COUNT; i++) {
    delay(500);
    if (i == 0) {
      strip[LED_COUNT-1] = CRGB::Black;
      strip[i] = CRGB::Red;
      strip[i+1] = CRGB::Red;
    }
    else 
    if (i == LED_COUNT-1){
      strip[i-1] = CRGB::Black;
      strip[i] = CRGB::Red;
      strip[0] = CRGB::Red;
    }  
    else {
      strip[i-1] = CRGB::Black;
      strip[i] = CRGB::Red;
      strip[i+1] = CRGB::Red;
    }
    FastLED.show();
   
  }
}

void RunDown() {
  uint8_t i = 0;
  for (uint8_t j = 0; j < LED_COUNT; j++) {
    delay(500);
    i = LED_COUNT-j-1;
    if (i == LED_COUNT-1) {
      strip[0] = CRGB::Black;
      strip[i] = CRGB::Red;
      strip[i-1] = CRGB::Red;
    }
    else 
    if (i == 0){
      strip[i+1] = CRGB::Black;
      strip[i] = CRGB::Red;
      strip[LED_COUNT-1] = CRGB::Red;
    }  
    else {
      strip[i-1] = CRGB::Red;
      strip[i] = CRGB::Red;
      strip[i+1] = CRGB::Black;
    }
    FastLED.show();
  }
}

void setup()
{
  // Добавляем ленту
  FastLED.addLeds<WS2812B, LED_PIN, RGB>(strip, LED_COUNT);
  pinMode(2, INPUT);
  pinMode(0, INPUT);
  pinMode(4, INPUT);
}
 
void loop()
{
  if (digitalRead(2) && !digitalRead(4)) {
    if (n<=0)  
      n=LED_COUNT;
    n=n-1;
    NextDown(n);
    delay(200);
  } else {
    if (!digitalRead(2) && digitalRead(4)) {
    n=n+1;
    NextDown(n);
    delay(200);
    if (n<=LED_COUNT)  
      n=0;
    } else
    if (!digitalRead(2) && !digitalRead(4)) {
      for (int i = 0; i < LED_COUNT; i++) {
        strip[i] = CRGB::Red;
        FastLED.show();
      }
    } else
      for (int i = 0; i < LED_COUNT; i++) {
        strip[i] = CRGB::Green;
        FastLED.show();
      }    
  }
}

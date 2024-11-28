#include "duckies.hpp"

#define LAYOUT_US_ENGLISH
#include <DigiKeyboard.h>

const char* quotes[] = { 
  "hello world!",
  "you are great!",
  "have a beautiful day!",
  "tea mate for life!",
  "may the grass always be soft",
  "you can do it!",
  "i believe in you",
  "virtual hugs!",
  "it always seems impossible until it is done",
  "it is always night before dawn",
  "people love you",
  "tea mate for life!",
  "stay hydrated!",
  "is it not a great day?",
  "don't worry, be happy",
  "do not let little stupid things break your happiness",
  "is it not the perfect day to have a great day?",
  "never give up!",
  "you deserve to be happy",
  "no rain, no flowers",
  "life is too short to spend it at war with yourself",
  "life is short. smile while you still have teeth",
  "we grow through what we go through",
  "you will be better soon",
  "nobody is perfect"
};


uint16_t get_random() {
  uint16_t val = analogRead(A1);
  uint16_t idx = (val >> 1) ^ (-(val & 0x01U) & 0xB400U);
  return idx;
}


void duckies::good(const long delay) {
  static bool done = false;
  if (!done) {
    DigiKeyboard.delay(5000);
    DigiKeyboard.sendKeyStroke(0, MOD_GUI_LEFT);
    DigiKeyboard.delay(200);
    DigiKeyboard.println("editor");
    DigiKeyboard.delay(2000);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(2000);
    unsigned int idx = get_random() % (sizeof(quotes) / sizeof(quotes[0]));
    DigiKeyboard.println(quotes[idx]);
    done = true;
  }
  DigiKeyboard.delay(delay);
  return;
}


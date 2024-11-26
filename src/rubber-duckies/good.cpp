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
};


uint16_t get_random() {
  uint16_t val = analogRead(A1);
  uint16_t idx = (val >> 1) ^ (-(val & 0x01U) & 0xB400U);
  return idx;
}


void good(const long delay) {
  static bool done = false;
  if (!done) {
    DigiKeyboard.delay(500);
    unsigned int idx = get_random() % (sizeof(quotes) / sizeof(quotes[0]));
    DigiKeyboard.println(quotes[idx]);
    //done = true;
  }
  DigiKeyboard.delay(delay);
  return;
}



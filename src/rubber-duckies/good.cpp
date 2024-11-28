#include "duckies.hpp"

#define LAYOUT_US_ENGLISH
#include <DigiKeyboard.h>
#include <avr/pgmspace.h>

const char m01[] PROGMEM = "hello world!";
const char m02[] PROGMEM = "you are great!";
const char m03[] PROGMEM = "have a beautiful day!";
const char m04[] PROGMEM = "tea mate for life!";
const char m05[] PROGMEM = "you can do it!";
const char m06[] PROGMEM = "i believe in you";
const char m07[] PROGMEM = "virtual hugs!";
const char m08[] PROGMEM = "it always seems impossible until it is done";
const char m09[] PROGMEM = "it is always night before dawn";
const char m10[] PROGMEM = "people love you";
const char m11[] PROGMEM = "tea mate for life!";
const char m12[] PROGMEM = "stay hydrated!";
const char m13[] PROGMEM = "is it not a great day?";
const char m14[] PROGMEM = "don't worry, be happy";
const char m15[] PROGMEM =
    "do not let little stupid things break your happiness";
const char m16[] PROGMEM = "is it not the perfect day to have a great day?";
const char m17[] PROGMEM = "never give up!";
const char m18[] PROGMEM = "you deserve to be happy";
const char m19[] PROGMEM = "no rain, no flowers";
const char m20[] PROGMEM = "life is too short to spend it at war with yourself";
const char m21[] PROGMEM = "life is short. smile while you still have teeth";
const char m22[] PROGMEM = "we grow through what we go through";
const char m23[] PROGMEM = "you will be better soon";
const char m24[] PROGMEM = "nobody is perfect";
const char m25[] PROGMEM = "may the grass always be soft";

const char *const quotes[] PROGMEM = {
    m01, m02, m03, m04, m05, m06, m07, m08, m09, m10, m11, m12, m13,
    m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25};

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
    DigiKeyboard.println("console");
    DigiKeyboard.delay(2000);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(2000);
    unsigned int idx = get_random() % (sizeof(quotes) / sizeof(quotes[0]));
    DigiKeyboard.println((__FlashStringHelper *)pgm_read_word(&quotes[idx]));
    done = true;
  }
  DigiKeyboard.delay(delay);
  return;
}

#include "vim-mode-leds.hpp"

#include <DigiCDC.h>
#include <Adafruit_NeoPixel.h>

static constexpr uint8_t NUM_LEDS = 1;
static constexpr uint8_t LED_PIN = 1;
static constexpr uint8_t BRIGHTNESS = 200;

uint32_t color = 0;
Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void vm_led::setup(const bool with_startup) {
  strip.begin();
  strip.setBrightness(BRIGHTNESS);
  strip.clear();
  strip.show();

  SerialUSB.begin();

  if (with_startup) {
    strip.setPixelColor(0, 0xff0000);
    strip.show();
    SerialUSB.delay(500);
    strip.clear();
    strip.show();
    SerialUSB.delay(500);
    strip.setPixelColor(0, 0xff0000);
    strip.show();
    SerialUSB.delay(500);
    strip.clear();
    strip.show();
    SerialUSB.delay(500);
    strip.setPixelColor(0, 0x00ff00);
    strip.show();
    SerialUSB.delay(800);
    strip.clear();
    strip.show();
  }
}

void vm_led::update() {
  if (SerialUSB.available()) {
    int32_t val = SerialUSB.read();

    SerialUSB.write(val);
    if (val != -1) {
      color = ((val & 0b11000000) << 24) | ((val & 0b110000) << 18) |
              ((val & 0b1100) << 12) | ((val & 0b11) << 6);
    }

    for (unsigned int i = 0; i < NUM_LEDS; i++) {
      strip.setPixelColor(i, color);
    }
    strip.show();
  }
}


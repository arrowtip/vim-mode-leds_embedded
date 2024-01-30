#include <Adafruit_NeoPixel.h>
#include <DigiCDC.h>

uint32_t color = 0;

#define RX 4
#define TX 3

Adafruit_NeoPixel strip(1, 1, NEO_GRB + NEO_KHZ800);

extern "C" void setup() {
  strip.begin();
  strip.clear();
  strip.setBrightness(255);

  SerialUSB.begin();

  strip.setPixelColor(0, 0xff00);
  strip.show();
  SerialUSB.delay(1000);
  strip.clear();
  strip.show();
}

extern "C" void loop() {
    if (SerialUSB.available()) {
        int val = SerialUSB.read();

        if (val != -1) {
          SerialUSB.write(color);
          color = ((val & 0b11000000) << 24) | ((val & 0b110000) << 18)
            | ((val & 0b1100) << 12) | ((val & 0b11) << 6);
        }

        strip.setPixelColor(0, color);
        strip.show();
    }
}

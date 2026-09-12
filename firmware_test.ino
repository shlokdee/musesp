#include <SPI.h>
#include "FS.h"
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <SdFat.h>
#include <Adafruit_ImageReader.h>

// ESP32-S3 to ILI9341 wiring in this project
#define TFT_CS 5
#define TFT_DC 15
#define TFT_SCK 18
#define TFT_MISO 16
#define TFT_MOSI 17

#define SD_CS 10


SdFat                SD;
Adafruit_ImageReader reader(SD);
Adafruit_ILI9341 tft(TFT_CS, TFT_DC, -1);

void setup() {
  Serial.begin(115200);
  delay(100);

  // Explicitly select the SPI pins used by the circuit.
  SPI.begin(TFT_SCK, TFT_MISO, TFT_MOSI, TFT_CS);
  pinMode(TFT_CS, OUTPUT);
  pinMode(TFT_DC, OUTPUT);

  tft.begin();


  if (!SD.begin(SD_CS, SD_SCK_MHZ(10))) {
    Serial.println(F("SD begin() failed"));
    for (;;);
  }
    Serial.println("SD Card initialized.");

    tft.fillScreen(ILI9341_BLUE);
  tft.setRotation(3);

  ImageReturnCode stat = reader.drawBMP("/wokwi.bmp", tft, 0, 0);
  reader.printStatus(stat);

}

void loop(void) {

}
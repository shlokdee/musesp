#include <SPI.h>
#include "FS.h"

#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <SdFat.h>
#include <Adafruit_ImageReader.h>
#include "ui.h"


// ESP32-S3 to ILI9341 wiring in this project
#define TFT_CS 9


#define TFT_DC 15
#define SD_CS 10


SdFat                SD;
Adafruit_ImageReader reader(SD);
Adafruit_ILI9341 tft(TFT_CS, TFT_DC, -1);


// [BEGIN lopaka generated]

// [END lopaka generated]

String randomSongs[] = {"Sajni Re", "Tum Hi Ho", "Kesariya", "Maan Meri Jaan", "Tera Yaar Hoon Main", "Kesariya", "Maan Meri Jaan", "Tera Yaar Hoon Main", "Kesariya", "Maan Meri Jaan", "Tera Yaar Hoon Main"};
String randomArtists[] = {"Arijit Singh", "Arijit ", "Arijit Singh", "Arijit Singh", "Arijit Singh", "Arijit Singh", "Arijit Singh", "Arijit Singh", "Arijit Singh", "Arijit Singh", "Arijit Singh"};

void setup() {
  Serial.begin(115200);
  delay(100);

  pinMode(TFT_DC, OUTPUT);
  pinMode(TFT_CS, OUTPUT);
digitalWrite(TFT_CS, HIGH);
pinMode(SD_CS, OUTPUT);
digitalWrite(SD_CS, HIGH);
    
  tft.begin();


  if (!SD.begin(SD_CS, SD_SCK_MHZ(10))) {
    Serial.println(F("SD begin() failed"));
    for (;;);
  }
    Serial.println("SD Card initialized.");
    


  ImageReturnCode stat = reader.drawBMP("/wokwi.bmp", tft, 0, 0);
  reader.printStatus(stat);

drawScreen_landscape(tft, "Sajni Re", "Arijit Singh");


}

void loop(void) {
  tft.fillRect(202, 188, seeklen, 11, 0xFFFF);
  delay(100);
  seeklen+=1;
}
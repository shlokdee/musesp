#include <SPI.h>
#include <FS.h>
#include <SD.h>

#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include "ui.h"
#include "debounce_helper.h"
#include "audio_player.h"


// ESP32-S3 to ILI9341 wiring in this project
#define TFT_CS 9


#define TFT_DC 15
#define SD_CS 10

#define up_btn 42
#define down_btn 41
#define fback_btn 40
#define pause_btn 39
#define ffront_btn 38

Button btnUp    = {up_btn};
Button btnDown  = {down_btn};
Button btnBack  = {fback_btn};
Button btnPause = {pause_btn};
Button btnFwd   = {ffront_btn};

Adafruit_ILI9341 tft(TFT_CS, TFT_DC, -1);



String randomSongs[] = {
    "Blinding Lights", "Pasoori", "Shape of You", "Jai Ho", 
    "As It Was", "Kahani Suno", "Levitating", "Tum Se Hi", 
    "Starboy", "Apna Bana Le", "Flowers"
};

String randomArtists[] = {
    "The Weeknd", "Ali Sethi", "Ed Sheeran", "A.R. Rahman", 
    "Harry Styles", "Kaifi Khalil", "Dua Lipa", "Mohit Chauhan", 
    "The Weeknd", "Arijit Singh", "Miley Cyrus"
};

int randomTimes[] = {
    20000, 35000, 15000, 40000, 
    25000, 30000, 20000, 45000, 
    30000, 15000, 25000
};

String randomfiles[] = {
    "/blinding_lights.mp3", "/pasoori.mp3", "/shape_of_you.mp3", "/jai_ho.mp3", 
    "/as_it_was.mp3", "/kahani_suno.mp3", "/levitating.mp3", "/tum_se_hi.mp3", 
    "/starboy.mp3", "/apna_bana_le.mp3", "/flowers.mp3"
};
void setup() {
  Serial.begin(115200);
  delay(100);

  pinMode(TFT_DC, OUTPUT);
  pinMode(TFT_CS, OUTPUT);
digitalWrite(TFT_CS, HIGH);
pinMode(SD_CS, OUTPUT);
digitalWrite(SD_CS, HIGH);

pinMode(up_btn, INPUT_PULLUP); 
pinMode(down_btn, INPUT_PULLUP);
pinMode(fback_btn, INPUT_PULLUP);
pinMode(pause_btn, INPUT_PULLUP);
pinMode(ffront_btn, INPUT_PULLUP);
    
  tft.begin();
  setupAudio();


  if (!SD.begin(SD_CS, SPI, 10000000)) {
    Serial.println(F("SD begin() failed"));
    for (;;);
  }
    Serial.println("SD Card initialized.");


drawScreen_landscape(tft);


}
int divisions= 96;
int i=0;
bool paused=true;
bool pauseChanged = false;
int stepNum=0;
bool songChanged=true;
unsigned long lastTimer=0;


void loop(void) {
audio.loop();
  if (pressed(btnPause)) {
    paused = !paused;
    pauseChanged = true;
    audio.pauseResume();
  }

  if (pressed(btnFwd)) {
    i++;
    if (i >= sizeof(randomSongs)/sizeof(randomSongs[0])) i = 0;
    stepNum = 0;
    songChanged = true;
  }
else if (pressed(btnBack)) {
    i--;
    if (i < 0) i = 0;
    stepNum = 0;
    songChanged = true;
  }

  if (songChanged) {
    drawText_landscape(tft, randomSongs[i], randomArtists[i]);
    playSong(randomfiles[i]);
    songChanged = false;
  }

if (pauseChanged) {
    drawPause_landscape(tft, paused);
    pauseChanged = false;
  }

  if (paused) {
    return;
  }

  

  int stepdelay = randomTimes[i] / divisions;
  if (millis() - lastTimer >= stepdelay) {
    lastTimer = millis();
    tft.fillRect(202, 188, stepNum, 11, 0xFFFF);
    stepNum++;
    if (stepNum > divisions) {
      stepNum = 0;
      i++;
      if (i >= sizeof(randomSongs)/sizeof(randomSongs[0])) i = 0;
      songChanged = true;
    }
}
}
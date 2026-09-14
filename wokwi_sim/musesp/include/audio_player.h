#pragma once
#include <Audio.h>
#include <SD.h>

#define I2S_BCLK 5
#define I2S_LRC  6
#define I2S_DOUT 4

Audio audio;

void setupAudio() {
audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
audio.setVolume(15);   // range is 0-21, not 0-100
}

void playSong(String filename) {
audio.connecttoFS(SD, filename.c_str());
}
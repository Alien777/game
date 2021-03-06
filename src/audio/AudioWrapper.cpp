//
// Created by adam on 09.01.2021.
//

#include "AudioWrapper.h"
#include "SD.h"
#include "FS.h"
#include "WString.h"

AudioWrapper::AudioWrapper(int i2sBclk, int i2sLrc, int i2sDout) {
    audio = new Audio(i2sBclk, i2sLrc, i2sDout);
}

void AudioWrapper::loop() {
    audio->loop();
}

void AudioWrapper::stop() {
    audio->stopSong();
}

void AudioWrapper::setVolume(uint8_t volume) {
    audio->setVolume(volume);
}

void AudioWrapper::play(String file) {

    audio->connecttohost(IP_SERVER + file);
}

AudioWrapper::~AudioWrapper() {
    delete audio;
}



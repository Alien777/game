//
// Created by adam on 09.01.2021.
//



#include "Common.h"
#include "WString.h"
#include "../../.pio/libdeps/node32s/ESP8266Audio/src/AudioGeneratorMP3.h"
#include "../../.pio/libdeps/node32s/ESP8266Audio/src/AudioFileSourceICYStream.h"
#include "../../.pio/libdeps/node32s/ESP8266Audio/src/AudioFileSourceBuffer.h"
#include "../../.pio/libdeps/node32s/ESP8266Audio/src/AudioOutputI2S.h"


#ifndef TF_AUDIO_H
#define TF_AUDIO_H

class AudioWrapper {
public:
    AudioGeneratorMP3 *mp3;
    AudioFileSourceICYStream *files;
    AudioFileSourceBuffer *buff;
    AudioOutputI2S *out;
    int i2sBclk;
    int i2sLrc;
    int i2sDout;
public:
    AudioWrapper(int i2sBclk, int i2sLrc, int i2sDout);

    ~AudioWrapper();

    void setVolume(uint8_t volume);

    void stop();



    void play( String file);

    void loop();

};

#endif //TF_AUDIO_H

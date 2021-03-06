//
// Created by adam on 09.01.2021.
//

#ifndef TF_SDCARD_H
#define TF_SDCARD_H

#include "SD.h"
#include "FS.h"

class SdCard {
public:
    SdCard(int sdCs, int spiSck, int spiMiso, int spiMosi);

};


#endif //TF_SDCARD_H

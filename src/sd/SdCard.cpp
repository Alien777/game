//
// Created by adam on 09.01.2021.
//

#include "SdCard.h"
#include "SD.h"

SdCard::SdCard(int sdCs, int spiSck, int spiMiso, int spiMosi) {
    pinMode(sdCs, OUTPUT);
    digitalWrite(sdCs, HIGH);
    SPI.begin(spiSck, spiMiso, spiMosi);
    SD.begin(sdCs);

}

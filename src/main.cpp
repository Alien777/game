#include <Arduino.h>
#include "SD.h"
#include "FS.h"
#include <audio/AudioWrapper.h>
#include <sd/SdCard.h>
#include <game/Game.h>
#include <SPIFFS.h>
#include "interface/DeviceInterface.h"
#include "PinDefinition.h"
#include "WiFi.h"


Game *game;
AudioWrapper *audio;
int a = 0;

String ssid = "2.4GWIFI-DOM";
String password = "narko1234";

void setup() {
    Serial.begin(115200);


//    new SdCard(SD_CS, SPI_SCK, SPI_MISO, SPI_MOSI);


    WiFi.disconnect();
    WiFi.softAPdisconnect(true);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid.c_str(), password.c_str());
    while (WiFi.status() != WL_CONNECTED) delay(500);

    audio = new AudioWrapper(I2S_BCLK, I2S_LRC, I2S_DOUT);

    game = new Game(audio);

}

void loop() {
    game->loop();
    audio->loop();
}
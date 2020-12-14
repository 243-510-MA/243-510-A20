#include "Arduino.h"
#include "Audio.h"
#include "SD.h"
#include "FS.h"

#define SD_CS         32
#define SPI_MOSI      15
#define SPI_MISO      13
#define SPI_SCK       21
#define I2S_DOUT      33
#define I2S_BCLK      12
#define I2S_LRC       27

Audio audio;
 
void setup() {
    pinMode(SD_CS, OUTPUT);      
    digitalWrite(SD_CS, HIGH);
    SPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI);
    if(!SD.begin(SD_CS))
    {
      while(true);  // end program
    }
    audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
    audio.setVolume(10); // 0...21
    audio.connecttoFS(SD,"/ok.mp3");
}
 
void loop()
{
    audio.loop();    
}

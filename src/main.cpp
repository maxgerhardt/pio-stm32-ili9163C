/*
Turn display ON/OFF - this command it's almost unusable since it doesn't control the backligh
It result in a white screen!
*/
 #include <arduino.h>
 #include <pins_arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <TFT_ILI9163C.h>
//#include "stm32f4xx.h"

// Color definitions
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

/*
Teensy3.x and Arduino's
 You are using 4 wire SPI here, so:
 MOSI:  11//Teensy3.x/Arduino UNO (for MEGA/DUE refere to arduino site)
 MISO:  12//Teensy3.x/Arduino UNO (for MEGA/DUE refere to arduino site)
 SCK:   13//Teensy3.x/Arduino UNO (for MEGA/DUE refere to arduino site)
 the rest of pin below:
 */

#define TFT_CS     PB9
#define TFT_RST    PA8
#define TFT_DC     PB6
#define TFT_SCLK   PB3
#define TFT_MOSI   PB5
#define TFT_brilho PC6
/*
Teensy 3.x can use: 2,6,9,10,15,20,21,22,23
 Arduino's 8 bit: any
 DUE: check arduino site
 If you do not use reset, tie it to +3V3
 */


TFT_ILI9163C tft = TFT_ILI9163C(TFT_CS, TFT_DC, TFT_RST);
                      //TFT_ILI9163C tft = TFT_ILI9163C(TFT_CS, TFT_DC, TFT_RST,TFT_MOSI,TFT_SCLK);
                      //SPIClass SPI_3(SPI3, TFT_MOSI, iso, TFT_SCLK);


void setup() {

  tft.begin();
  tft.fillScreen(0xF81F);


}


void loop(void) {
  tft.display(false);
  delay(1000);
  tft.display(true);
  delay(1000);
}

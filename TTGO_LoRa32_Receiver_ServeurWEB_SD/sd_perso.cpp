#include "pins_arduino.h"
/*
  SOLUTION 1 - PROJET RUCHE >> JACOPE Jules & JELITI Mehdi - BTS CIEL - 2024/2025

  
*/

#include <Arduino.h>
#include <SD.h>
#include <SPI.h>

#include "sd_perso.h"

SPIClass spiSD(HSPI);
#define SCK_SD 14
#define MISO_SD 2
#define MOSI_SD 15
#define CS_SD 13

sd_perso::sd_perso() {}

void sd_perso::start() {
  spiSD.begin(SCK_SD, MISO_SD, MOSI_SD, CS_SD); //sd
  if (!SD.begin(CS_SD, spiSD)) {
    Serial.println("Echec lors du montage de la SD");
    return;
  }
  uint8_t cardType = SD.cardType();
  if (cardType == CARD_NONE) {
    Serial.println("Aucune SD insérée");
    return;
  }
}

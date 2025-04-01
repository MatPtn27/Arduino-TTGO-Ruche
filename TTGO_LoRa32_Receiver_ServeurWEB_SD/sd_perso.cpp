/*
  SOLUTION 1 - PROJET RUCHE >> JACOPE Jules & JELITI Mehdi - BTS CIEL - 2024/2025

  
*/

#include <Arduino.h>
#include <SD.h>
#include <SPI.h>

#include "sd_perso.h"

#define REASSIGN_PINS
int sck_sd = 14;
int miso_sd = 2;
int mosi_sd = 15;
int cs_sd = 13;

sd_perso::sd_perso() {}

void sd_perso::start() {

#ifdef REASSIGN_PINS
  SPI.begin(sck_sd, miso_sd, mosi_sd, cs_sd);
  if (!SD.begin(cs_sd)) {
#else
  if (!SD.begin()) {
#endif
    Serial.println("Echec lors du montage de la SD");
    return;
  }
  uint8_t cardType = SD.cardType();
  if (cardType == CARD_NONE) {
    Serial.println("Aucune SD insérée");
    return;
  }
}

/*
  SOLUTION 1 - PROJET RUCHE >> JACOPE Jules & JELITI Mehdi - BTS CIEL - 2024/2025

  
*/

#include "lora_perso.h"

lora_perso::lora_perso() {}

void lora_perso::start() {

  Serial.println("LoRa - Recepteur");
  delay(500);

  // Initialisation du SPI
  SPI.begin(SCK_lora, MISO_lora, MOSI_lora, SS_lora);

  // Initialisation du LoRa
  LoRa.setPins(SS_lora, RST_lora, DIO0_lora);  // Définir les broches pour LoRa

  if (!LoRa.begin(868E6)) {  // Utiliser la même fréquence que l'émetteur, c-à-d 868 MHz
    Serial.println("Erreur de démarrage LoRa!");
    while (1)
      ;  //Bloquer la suite du programme
  }
}

void lora_perso::read_v1() {
  int packetSize = LoRa.parsePacket();

  if (packetSize) {

    Serial.print("Paquet reçu : '");

    //Lecture du paquet
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }

    //Intensité du signal
    Serial.print("' avec RSSI (Intensité du signal en dBm) : ");
    Serial.println(LoRa.packetRssi());
  }
}
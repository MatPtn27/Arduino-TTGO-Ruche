/*
  SOLUTION 1 - PROJET RUCHE >> JACOPE Jules & JELITI Mehdi - BTS CIEL - 2024/2025

  
*/

#include <Arduino.h>
#include <LoRa.h>
#include <SPI.h>

//------------------------------------------------------------------------------
//Définition des broches pour LoRa
#define SCK_lora 5
#define MISO_lora 19
#define MOSI_lora 27
#define SS_lora 18
#define RST_lora 23
#define DIO0_lora 26


//------------------------------------------------------------------------------
//Classes

#ifndef lora_h
#define lora_h

class lora_perso {
public:
  lora_perso();

  void start();

  void read_v1();
};

#endif
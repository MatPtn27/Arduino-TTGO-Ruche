/*
  SOLUTION 1 - PROJET RUCHE >> JACOPE Jules & JELITI Mehdi - BTS CIEL - 2024/2025

  
*/

#include "sd_perso.h"
sd_perso sdp;

#include "lora_perso.h"
lora_perso lorap;

#include "web_serv_perso.h"
web_serv webp;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  //sdp.start();
  lorap.start();
  webp.start_wifi_v1();
  webp.start_web();
}

void loop() {
  // put your main code here, to run repeatedly:
  lorap.read_v1();
  webp.loop_web();
}

/*
  SOLUTION 1 - PROJET RUCHE >> JACOPE Jules & JELITI Mehdi - BTS CIEL - 2024/2025

  
*/

#include <Arduino.h>

//WiFi
#include <WiFi.h>
#include <WebServer.h>

//OLED
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//SD
#include <SD.h>

#include "web_serv_perso.h"
#include "sd_perso.h"

// Remplacez par vos informations de réseau Wi-Fi
const char* ssid = "Box_Wifi_2.0";
const char* password = "nopememepasenreve";

WebServer server(80);
web_serv::web_serv() {}

void handleRoot(){
  // Lecture du fichier index.html depuis la carte SD
  File file = SD.open("/index.html");
  if (file) {
    Serial.println("Fichier index.html trouvé.");
    String line;
    while (file.available()) {
      line = file.readStringUntil('\n');
      server.sendContent(line);
    }
    file.close();
    server.send(200, "text/html", "");
  } else {
    Serial.println("Erreur : Fichier index.html non trouvé.");
    server.send(404, "text/plain", "Fichier non trouvé.");
  }
}

void web_serv::start_wifi_v1() {
  // Connexion au Wi-Fi
  Serial.print("Connexion à ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Connecté au Wi-Fi");
  Serial.print("Adresse IP : ");
  Serial.println(WiFi.localIP());
}

void web_serv::start_web(){
  server.on("/", handleRoot);  // Route pour la page d'accueil
  server.begin();
  Serial.println("Serveur web démarré");
}

void web_serv::loop_web() {
  server.handleClient();
}

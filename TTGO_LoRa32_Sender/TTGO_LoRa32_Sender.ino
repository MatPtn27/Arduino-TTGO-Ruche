#include <DHT.h>
#include <SPI.h>
#include <LoRa.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

// Définition des broches pour LoRa
#define SCK 5
#define MISO 19
#define MOSI 27
#define SS 18
#define RST 23
#define DIO0 26
#define SEALEVELPRESSURE_HPA (1013.25)

// Définir la broche à laquelle le DHT22 est connecté
#define DHTPIN 4
#define DHTTYPE DHT22
// Initialiser le capteur DHT22
DHT dht(DHTPIN, DHTTYPE);

Adafruit_BME280 bme; // I2C
//Adafruit_BME280 bme(BME_CS); // hardware SPI
//Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK); // software SPI

unsigned long delayTime;
int counter = 1;
String msg;

float h = 0;
float t = 0;
float T = 0;
float H = 0;
float P = 1013.25;

void setup() {
  Serial.begin(115200);
  pinMode(DHTPIN, DHTTYPE);
  dht.begin(); // Initialiser le capteur DHT22

  delay(1000);
  while (!Serial);

  Serial.println("LoRa Sender");

  // Initialisation du SPI
  SPI.begin(SCK, MISO, MOSI, SS);

  // Initialisation du LoRa
  LoRa.setPins(SS, RST, DIO0); // Définir les broches pour LoRa
  if (!LoRa.begin(868E6)) {
    Serial.println("Erreur de démarrage LoRa!");
    while (1);
  }

  if(!bme.begin(0x76)){
    Serial.println("Erreur avec le bme. Vérifier !");
    while(1);
  }
  Serial.println("BME OK !");
}

void loop() {

  DHT();
  BME();

  msg = "Température : " + String(t) + " | Humidité : " + String(h) + "| Préssion : " + String(P) + "| Température exterieur : " + String(T) + " | Humidité exterieur : " + String(H);
  
  //Moniteur série
  Serial.print("Envoi du paquet: '");
  Serial.print(msg + " | Paquet n°");
  Serial.print(counter);
  Serial.println("'");


  //Envoi du paquet
  LoRa.beginPacket();
  LoRa.print(msg);
  LoRa.endPacket();

  counter++; //compteur +1 pour le n° du message

  delay(5000);
}

void DHT() {
  // Délai recommandé entre les lectures (2 secondes ou plus)
  delay(2000);

  // Lire l'humidité et la température (en Celsius)
  h = dht.readHumidity();
  t = dht.readTemperature();


  // Afficher les valeurs sur le moniteur série
  Serial.print("Humidité: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Température: ");
  Serial.print(t);
  Serial.println(" °C");
}

void BME() {

  // Délai recommandé entre les lectures (2 secondes ou plus)
  delay(2000);

  H = bme.readHumidity();
  T = bme.readTemperature();
  P = bme.readPressure();

  Serial.print("Temperature = ");
  Serial.print(T);
  Serial.println(" °C");
  Serial.print("Pressure = ");
  Serial.print(P / 100.0F);
  Serial.println(" hPa");
  Serial.print("Humidity = ");
  Serial.print(H);
  Serial.println(" %");
}



//trame DHT 22 : 0000 0001 1001 0101 0000     0000 1101 1101 0111 0011
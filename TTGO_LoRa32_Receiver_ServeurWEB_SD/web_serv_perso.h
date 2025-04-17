/*
  SOLUTION 1 - PROJET RUCHE >> JACOPE Jules & JELITI Mehdi - BTS CIEL - 2024/2025

  
*/

#ifndef web_h
#define web_h

// Variables to save date and time
String formattedDate;
String day;
String hour;
String timestamp;

// Initialize variables to get and save LoRa data
int rssi;
String loRaMessage;
String temperature_in;
String temperature_out;
String humidity_in;
String humidity_out;
String pressure;
String weight;
String light;

// Replaces placeholder with DHT values
String processor(const String& var){
  //Serial.println(var);
  if(var == "TEMPERATURE_IN"){
    return temperature_in;
  }
  else if(var == "TEMPERATURE_OUT") {
    return temperature_out;
  }
  else if(var == "HUMIDITY_IN"){
    return humidity_in;
  }
  else if(var == "HUMIDITY_OUT"){
    return humidity_out;
  }
  else if(var == "PRESSURE"){
    return pressure;
  }
  else if(var == "WEIGHT"){
    return weight;
  }
  else if(var == "LIGHT"){
    return light;
  }
  else if(var == "TIMESTAMP"){
    return timestamp;
  }
  else if (var == "RRSI"){
    return String(rssi);
  }
  return String();
}

class web_serv {
public:

  web_serv();

  void start_wifi_v1();

  void start_wifi_v2();

  void start_web();

  void loop_web();
};

#endif



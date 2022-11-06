
#include <ESP8266WiFi.h>

#include <WiFiManager.h>
#include <strings_en.h>


#include <DNSServer.h>
#include <ESP8266WebServer.h>


void conectaWifi_EJC(){
  Serial.begin(9600);

  //creamos objeto de WiFiManager
  WiFiManager wifiManager;

  // Descomentar para resetar configuracion
  //wifiManager.resetSettings();

  //Creamos AP y portal cautivo

  wifiManager.autoConnect("MiHuertita");

  Serial.println("Ya estas conectado");

}
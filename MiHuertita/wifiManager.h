//incluimos todos los archivos de cabeceras necesarios
#include <ESP8266WiFi.h>
#include <WiFiManager.h>

#define WIFI_LED D5

//SETUP WIFIMANAGER
void setup_WIFI(){
  WiFiManager wifiManager;  //creo un objeto de la clase WiFiManager  
  //wifiManager.resetSettings(); // descomentar para resetear configuracion(borrar un wifi predeterminado)
  pinMode(WIFI_LED, OUTPUT); // configuramos el pin D5 como salida
  digitalWrite (WIFI_LED, HIGH);
  wifiManager.autoConnect("MiHuertita"); //se crea el punto de acceso y el portal cautivo

  digitalWrite (WIFI_LED, LOW);//prendemos un led verde para mostrar que ya se conecto a una red WiFi
  
  //Imprime en el monitor serial los datos de la red WiFi que se conecto
  Serial.println("***********************");
  Serial.print("Conectado a la red wifi: ");
  Serial.println(WiFi.SSID());
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
  Serial.println("***********************");

}

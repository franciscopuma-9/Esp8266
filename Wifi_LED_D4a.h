#include <ESP8266WiFi.h>

#include <WiFiManager.h>
#include <strings_en.h>


#include <DNSServer.h>
#include <ESP8266WebServer.h>


WiFiServer server(80);


void setup_WIFI(){
  //creamos objeto de WiFiManager
  WiFiManager wifiManager;

  // Descomentar para resetar configuracion
  //wifiManager.resetSettings();

  //Creamos AP y portal cautivo

  wifiManager.autoConnect("MiHuertita");

  Serial.println("Ya estas conectado");
  
  //Wifi
  Serial.println("***********************");
  Serial.print("Conectado a la red wifi: ");
  Serial.println(WiFi.SSID());
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("macAddress: ");
  Serial.println(WiFi.macAddress());
  Serial.println("***********************");
  server.begin();
}

void loop_Wifi(){
  WiFiClient client = server.available();
  if (!client){
    return;
  }
  Serial.println("Nuevo cliente...");
  while (!client.available()){
    delay(1000);
  }
  String peticion = client.readStringUntil('\r');
  Serial.println(peticion);
  client.flush();


  client.println("HTTP/1.1 200 OK");
  client.println("");
  client.println("");
  client.println("");
  client.println("");


//INICIA LA PAGINA
  client.println("<!DOCTYPE html><html lang='en'><head><meta charset='UTF-8'>");
  client.println("<meta name='viewport' content='width=device-width, initial-scale=1.0'>");
  client.println("<title>Temperatura y Humedad</title></head>");
  client.println("<body style='font-family: Century gothic; width: 800;'><center>");
  client.println("<div style='box-shadow: 0px 0px 20px 8px rgba(0,0,0,0.22); padding: 20px; width: 300px; display: inline-block; margin: 30px;'> ");
  client.println("<h2>Temperatura = "+ String(temperatura) +"°C </h2>");
  client.println("<h2>Humedad = "+ String(humedad)+" % </h2>");
  client.println("<h2>Humedad del suelo = "+ String(porcentajeHumedadSuelo) +" % </h2>");
  client.println("</div></center></body></html>");    




  Serial.println("Peticion finalizada");
  delay(2000);

}
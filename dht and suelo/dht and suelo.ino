#include <DHT.h>
#include <DHT_U.h>
#include <ESP8266WiFi.h>
#include <Ticker.h>

#define DHTPIN D2
#define ledWifi D4

// DHT 
DHT dht(DHTPIN, DHT22);
float hume, temp;

//SUELO
const int AirValue = 720;   //you need to replace this value with Value_1
const int WaterValue = 340;  //you need to replace this value with Value_2
int soilMoistureValue = 0;
int soilmoisturepercent=0;

//Wifi

String ssid = "Fibertel WiFi536";
String password = "0041615824";
WiFiServer server(80);

byte cont = 0;
byte max_intentos = 50;
//led
Ticker tic_WifiLed;

void parpadeoLedWifi(){
  byte estado = digitalRead(ledWifi);
  digitalWrite(ledWifi,!estado);
}

void setup() {
  //inicia Serial
  pinMode(ledWifi,OUTPUT); 
  Serial.begin(9600);
  Serial.println("\n");
  tic_WifiLed.attach(0.2,parpadeoLedWifi);

  //Wifi
  WiFi.begin(ssid,password);
  while (WiFi.status() != WL_CONNECTED and cont < max_intentos) {
    cont ++;
    delay (500);
    Serial.print("." );
  }
  Serial.println("");
  
  if(cont < max_intentos){
    Serial.println("***********************");
    Serial.print("Conectado a la red wifi: ");
    Serial.println(WiFi.SSID());
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
    Serial.print("macAddress: ");
    Serial.println(WiFi.macAddress());
    Serial.println("***********************");
  }
  else {
    Serial.println("---------------------------");
    Serial.println("Error de conexion");
    Serial.println("---------------------------");
  }
  tic_WifiLed.detach();
  digitalWrite(ledWifi,HIGH);

  server.begin();
  // DHT
  dht.begin();
  Serial.println("Reading From the Sensor ...");
  delay(2000);
}

void loop() {
  // DHT
  hume = dht.readHumidity();
  temp = dht.readTemperature();
  Serial.print("\nTemperatura: ");
  Serial.print(temp);
  Serial.print(" Humedad: ");
  Serial.print(hume);


  //SUELO
  soilMoistureValue = analogRead(A0);  //put Sensor insert into soil
  Serial.print(" Moisture Value: ");
  Serial.print(soilMoistureValue);
  Serial.print(" Moisture percent: ");
  soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
  if(soilmoisturepercent >= 100)
  {
    Serial.print("100 %");
  }
  else if(soilmoisturepercent <=0)
  {
    Serial.print("0 %");
  }
  else if(soilmoisturepercent >0 && soilmoisturepercent < 100)
  {
    Serial.print(soilmoisturepercent);
    Serial.print("%");    
  }
    
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
  client.println("<h2>Temperatura = "+ String(temp) +"°C </h2>");
  client.println("<h2>Humedad = "+ String(hume)+" % </h2>");
  client.println("<h2>Humedad del suelo = "+ String(soilmoisturepercent) +" % </h2>");
  client.println("</div></center></body></html>");    




  Serial.println("Peticion finalizada");
  delay(20000);

}

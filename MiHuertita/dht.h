#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN D3

DHT dht(DHTPIN, DHT22);
float humedad, temperatura;

// SETUP
void setup_DHT(){
  dht.begin();
  Serial.println("Reading From the Sensor ...");
  delay(2000);
  
}

//LOOP
void loop_DHT(){
  humedad = dht.readHumidity();
  temperatura = dht.readTemperature();
  Serial.print("\nTemperatura: ");
  Serial.print(temperatura);
  Serial.print(" Humedad: ");
  Serial.print(humedad);
}

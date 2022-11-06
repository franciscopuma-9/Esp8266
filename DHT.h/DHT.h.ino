#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN D3

DHT dht(DHTPIN, DHT22);
float hume, temp;

// SETUP
void setup_DHT(){
  dht.begin();
  Serial.println("Reading From the Sensor ...");
  delay(2000);
}

//LOOP
void loop_DHT(){
  hume = dht.readHumidity();
  temp = dht.readTemperature();
  Serial.print("\nTemperatura: ");
  Serial.print(temp);
  Serial.print(" Humedad: ");
  Serial.print(hume);
}

//incluimos todos los archivos de cabeceras necesarios
#include <DHT.h>
#include <DHT_U.h>

#define DHT_PIN D3

DHT dht(DHT_PIN, DHT22); //creo objeto dht y le paso los parametros del pin que se utilizo y el tipo de sensor DHT
float humedad, temperatura; 

// SETUP DHT
void setup_DHT(){
  dht.begin();//inicio el sensor DHT
}

//LOOP DHT
void loop_DHT(){
  humedad = dht.readHumidity(); //funcion para leer humedad relativa
  temperatura = dht.readTemperature(); //funcion para leer temperatura
  
  Serial.print("\nTemperatura: ");
  Serial.print(temperatura);
  Serial.print(" Humedad: ");
  Serial.print(humedad);
}

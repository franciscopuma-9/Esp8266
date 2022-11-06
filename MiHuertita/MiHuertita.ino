#include "dht.h"
#include "HumedadSuelo.h"
#include "Rele.h"
#include "Wifi_LED_D4.h"

void setup() {
  //inicia Serial
  Serial.begin(9600);
  Serial.println("\n");

  setup_WIFI(); //funcion setup para el WIFI

  setup_Rele(); //funcion para activar el pin del rele como salida

  setup_DHT(); //funcion setup DHT
  
  
}

void loop() {

  loop_DHT(); //funcion loop para leer datos en el DHT

  loop_HumedadSuelo();//funcion loop de humedad del suelo y mapeo para obtener valores entre 0 y 100

  loop_Rele();
  
  loop_Wifi();

}

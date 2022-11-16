//incluimos todos los archivos de cabeceras creados por nosotros para modularizar el proyecto
#include "dht.h"
#include "humedadSuelo.h"
#include "wifiManager.h"
#include "tipos.h"
#include "ubidots.h"
#include "motor.h"

void setup() {
  //inicia Serial para poder realizar pruebas
  Serial.begin(9600);

  setup_WIFI(); //funcion setup para el WIFI

  setup_Motor(); //funcion para activar el pin del rele como salida

  setup_DHT(); //funcion setup DHT
  
  setup_Ubidots(); //funcion setup de Ubidots
}

void loop() {

  loop_DHT(); //funcion loop para leer datos en el DHT

  loop_HumedadSuelo();//funcion loop de humedad del suelo y mapeo para obtener valores entre 0 y 100

  loop_Motor(); //funcion loop para el funcionamiento de la bombita de agua
  
  loop_Ubidots(); //funcion loop de Ubidots para ver los datos desde la web
}

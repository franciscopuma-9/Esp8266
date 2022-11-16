#include <Ubidots.h>
#include "WifiManager.h"
#include "tipos.h"

#define UBIDOTS_TOKEN "BBFF-6YfBodpjS7am9GD7EOGHyrQgDOPVPo"
#define DEVICE_LABEL "MiHuertita"

#define LAB_TEMP "Temperatura"
#define LAB_HUME "Humedad"
#define LAB_HUME_SUELO "Humedad del suelo"
#define LAB_ON_OFF "On/Off"
#define LAB_MENTA "Menta"
#define LAB_OREGANO "Oregano"
#define LAB_ALBAHACA "Albahaca"


Ubidots ubidots(UBIDOTS_TOKEN, UBI_HTTP);

  float var_temp;
  float var_humedad;
  int var_humedad_suelo;
  bool on_off;
  bool menta;
  bool oregano;
  bool albahaca;


void setup() {
  
  Serial.begin(9600);
  setup_WIFI();
  // ubidots.setDebug(true);

  var_temp = 40;
  var_humedad = 12;
  var_humedad_suelo = 18;
  on_off = true;
  menta = false;
  oregano = false;
  albahaca = false;
}

void loop() {
  
  ubidots.add(LAB_TEMP, var_temp);
  ubidots.add(LAB_HUME, var_humedad);
  ubidots.add(LAB_HUME_SUELO, var_humedad_suelo);
  ubidots.add(LAB_ON_OFF, on_off);

  menta = ubidots.get(DEVICE_LABEL, LAB_MENTA);
  oregano = ubidots.get(DEVICE_LABEL, LAB_OREGANO);
  albahaca = ubidots.get(DEVICE_LABEL, LAB_ALBAHACA);

  float tipo;
  if (menta == true){
    Menta menta;    
    tipo = menta.humedad_necesaria;
  }
  else{
    if (oregano == true){
      Oregano oregano;
      tipo = oregano.humedad_necesaria;
    }
    else {
      Albahaca albahaca;
      tipo = albahaca.humedad_necesaria;
    }
  }
  Serial.println(tipo);
  Serial.println(" Menta: " + String(menta));
  Serial.println(" Oregano: " + String(oregano));
  Serial.println(" Albahaca: " + String(albahaca));

  bool bufferSent = false;
  bufferSent = ubidots.send(DEVICE_LABEL);

  if (bufferSent){
    Serial.println("Los valores se enviaron al dispositivo");
  }
delay(1000);

}

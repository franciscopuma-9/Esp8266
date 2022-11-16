//incluimos el archivo de cabecera necesario
#include <Ubidots.h>

//variables simbolicas para utilizar en Ubidots
#define UBIDOTS_TOKEN "BBFF-6YfBodpjS7am9GD7EOGHyrQgDOPVPo"
#define DEVICE_LABEL "MiHuertita"
#define LAB_TEMP "Temperatura"
#define LAB_HUME "Humedad"
#define LAB_HUME_SUELO "Humedad del suelo"
#define LAB_ON_OFF "On/Off"
#define LAB_MENTA "Menta"
#define LAB_OREGANO "Oregano"
#define LAB_ALBAHACA "Albahaca"


Ubidots ubidots(UBIDOTS_TOKEN, UBI_HTTP); //creo un Objeto de la clave Ubidots donde paso por parametros el token de Ubidots y el protocolo de Iot

bool on_off;
bool menta;
bool oregano;
bool albahaca;
float humedad_final;

//funcion setup de Ubidots
void setup_Ubidots() {
  
  //setup_WIFI();
  on_off = false;
  menta = false;
  oregano = false;
  albahaca = false;
}

void loop_Ubidots() {
  
  //creamos variables para controlar el tipo de planta, estos valores se reciben desde Ubidots
  menta = ubidots.get(DEVICE_LABEL, LAB_MENTA);
  oregano = ubidots.get(DEVICE_LABEL, LAB_OREGANO);
  albahaca = ubidots.get(DEVICE_LABEL, LAB_ALBAHACA);

  //hacemos comparaciones para saber la humedad necesaria del tipo de planta que se eligio
  if (menta == true){
    Menta menta;    
    humedad_final = menta.getHumedad();
  }
  else{
    if (oregano == true){
      Oregano oregano;
      humedad_final = oregano.getHumedad();
    }
    else {
      Albahaca albahaca;
      humedad_final = albahaca.getHumedad();
    }
  }
  //hacemos comparaciones para aumentar o disminuir la humedad necesaria segun la temperatura
  if (temperatura < 15){
    humedad_final-=10;
  }
  else{
    if (temperatura > 25){
      humedad_final+=10;
    }
  }
  //hacemos comparaciones para saber si el motor se prendera y con eso poder mandarle los datos a Ubidots
  if (porcentaje_humedad_suelo <= humedad_final) { 
    on_off = true;     
  } 
  if (porcentaje_humedad_suelo > humedad_final) {   
    on_off = false;  
  }
  //agregamos las variables que se visualizaran en Ubidots
  ubidots.add(LAB_TEMP, temperatura);
  ubidots.add(LAB_HUME, humedad);
  ubidots.add(LAB_HUME_SUELO, porcentaje_humedad_suelo);
  ubidots.add(LAB_ON_OFF, on_off);

  ubidots.send(DEVICE_LABEL); //envia todas las variables que se agregaron con la funcion add
}
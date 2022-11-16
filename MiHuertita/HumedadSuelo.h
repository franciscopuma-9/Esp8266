#define ANALOG_PIN A0
#define VALOR_MAX 720
#define VALOR_MIN 340


int valor_humedad_suelo = 0;
int porcentaje_humedad_suelo = 0;

//LOOP SENSOR CAPACITIVO HUMEDAD DEL SUELO
void loop_HumedadSuelo(){
  valor_humedad_suelo = analogRead(ANALOG_PIN);  

  porcentaje_humedad_suelo = map(valor_humedad_suelo, VALOR_MAX, VALOR_MIN, 0, 100); //utilizo la funcion map para transformar el valor maximo y minimo del sensor en un rango entre 0 y 100 para representarlo como porcentaje.
  Serial.print('\n');
  //hacemos una comparacion para que no den valores negativos ni mayores a 100 del porcentaje
  if(porcentaje_humedad_suelo >= 100)
  {
    Serial.print("100 %");
    porcentaje_humedad_suelo = 100;
  }
  else if(porcentaje_humedad_suelo <=0)
  {
    Serial.print("0 %");
    porcentaje_humedad_suelo = 0;
  }
  else if(porcentaje_humedad_suelo >0 && porcentaje_humedad_suelo < 100)
  {
    Serial.print(porcentaje_humedad_suelo);
    Serial.print("%");    
  }
}

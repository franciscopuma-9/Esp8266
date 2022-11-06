const int valorMaximo = 720;   
const int valorMinimo = 340;  
int valorHumedadSuelo = 0;
int porcentajeHumedadSuelo = 0;


void loop_HumedadSuelo(){
  valorHumedadSuelo = analogRead(A0);  
  Serial.print(" Valor de Humedad del suelo: ");
  Serial.print(valorHumedadSuelo);
  Serial.print(" Porcentaje de Humedad del suelo: ");
  porcentajeHumedadSuelo = map(valorHumedadSuelo, valorMaximo, valorMinimo, 0, 100);
  if(porcentajeHumedadSuelo >= 100)
  {
    Serial.print("100 %");
    porcentajeHumedadSuelo = 100;
  }
  else if(porcentajeHumedadSuelo <=0)
  {
    Serial.print("0 %");
    porcentajeHumedadSuelo = 0;
  }
  else if(porcentajeHumedadSuelo >0 && porcentajeHumedadSuelo < 100)
  {
    Serial.print(porcentajeHumedadSuelo);
    Serial.print("%");    
  }
}

const int relay = 5;
const int valorMaximo = 720;   
const int valorMinimo = 340;  
int valorHumedadSuelo = 0;
int porcentajeHumedadSuelo = 0;

void setup() {
  Serial.begin(115200);
  pinMode(relay, OUTPUT);
}

void loop(){
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
  delay(1000);
  if ( porcentajeHumedadSuelo <=50) { 
  digitalWrite (relay, HIGH); 
  Serial.print(" Accionado");   
  } 

  if ( porcentajeHumedadSuelo> 50) { 
  digitalWrite (relay, LOW);
  Serial.print("Apagado");  
  }
  Serial.print("\n")
  delay(1000);
}

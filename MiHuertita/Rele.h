const int motorPin = D0;

void setup_Rele(){
  pinMode (motorPin, OUTPUT); 
  digitalWrite (motorPin, LOW); // mantener el motor apagado inicialmente 
}

void loop_Rele(){
  //funcionamiento rele
  if ( porcentajeHumedadSuelo <=50) { 
  digitalWrite (motorPin, HIGH); 
  Serial.print(" Accionado");   
  } 

  if ( porcentajeHumedadSuelo> 50) { 
  digitalWrite (motorPin, LOW);
  Serial.print("Apagado");  
  }
  delay(1000);
}


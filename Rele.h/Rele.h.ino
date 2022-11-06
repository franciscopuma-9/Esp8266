#define motorPin D1

void setup_Rele(){
  pinMode (motorPin, OUTPUT); 
  digitalWrite (motorPin, LOW); // mantener el motor apagado inicialmente 
}

void loop_Rele(){
  //rele 
  // mantener el motor apagado inicialmente 
  //funcionamiento rele
  if ( soilmoisturepercent <50) { digitalWrite (motorPin, HIGH); Serial.print(" Accionado");   } 
  if ( soilmoisturepercent> 50 && soilmoisturepercent <55) { digitalWrite (motorPin, HIGH); Serial.print(" Medio");   } 
  if ( soilmoisturepercent> 56) { digitalWrite (motorPin, LOW); Serial.print("Apagado");  }
  delay(1000);
}
#define MOTOR_PIN D1

//funcion setup de la bombita de agua
void setup_Motor(){
  pinMode (MOTOR_PIN, OUTPUT); //configuramos el pin D1 como salida
  digitalWrite (MOTOR_PIN, LOW); //mantemos la bombita de agua apagada
}

void loop_Motor(){
  //hacemos comparaciones para saber cuando prender y apagar la bombita de agua
  if ( porcentaje_humedad_suelo <= humedad_final) { 
    digitalWrite (MOTOR_PIN, HIGH); //prendemos la bombita de agua cuando los valores de humedad estan por debajo del permitido
    Serial.print(" Accionado");   
  } 

  if ( porcentaje_humedad_suelo > humedad_final) { 
    digitalWrite (MOTOR_PIN, LOW); //apagamos la bombita de aguacuando los valores de humedad estan por encima del permitido
    Serial.print(" Apagado");  
  }
}


const int AirValue = 720;   //you need to replace this value with Value_1
const int WaterValue = 340;  //you need to replace this value with Value_2
int soilMoistureValue = 0;
int soilmoisturepercent=0;


void loop_HumedadSuelo(){
  soilMoistureValue = analogRead(A0);  //put Sensor insert into soil
  Serial.print(" Moisture Value: ");
  Serial.print(soilMoistureValue);
  Serial.print(" Moisture percent: ");
  soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
  if(soilmoisturepercent >= 100)
  {
    Serial.print("100 %");
  }
  else if(soilmoisturepercent <=0)
  {
    Serial.print("0 %");
  }
  else if(soilmoisturepercent >0 && soilmoisturepercent < 100)
  {
    Serial.print(soilmoisturepercent);
    Serial.print("%");    
  }
}

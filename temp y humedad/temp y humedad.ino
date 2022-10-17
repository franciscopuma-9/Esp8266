#include <DHT.h>
#include <DHT_U.h>

DHT dht(D1, DHT22);

float hume, temp;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  hume = dht.readHumidity();
  temp = dht.readTemperature();

  Serial.println("Temperatura: " + String(temp) + "Humedad: " + String(hume) );

  delay(5000);
}

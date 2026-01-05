/*
 * DHT11 Sensor Test
 */

#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("DHT11 Test Started");
}

void loop() {
  delay(2000); // DHT11 is slow, wait 2 seconds between reads

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" % | Temperature: ");
  Serial.print(t);
  Serial.println(" C");
}

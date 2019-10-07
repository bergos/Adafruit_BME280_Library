#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Arduino.h>
#include <Wire.h>

Adafruit_BME280 bmeSensor;

void setup() {
  Serial.begin(115200);

  delay(5000);

  Serial.print("init BME280...");
  if (!bmeSensor.begin(0x76)) {
    Serial.println("failed");
  } else {
    Serial.println("done");
  }
}

void loop() {
#if 0
  Serial.print("temperature: ");
  Serial.println(bmeSensor.readTemperature());

  Serial.print("humidity: ");
  Serial.println(bmeSensor.readHumidity());
# else
  float temperature, pressure, humidity;

  bmeSensor.readAll(&temperature, &pressure, &humidity);

  Serial.print("temperature: ");
  Serial.println(temperature);

  Serial.print("pressure: ");
  Serial.println(pressure);

  Serial.print("humidity: ");
  Serial.println(humidity);
#endif
  delay(1000);
}
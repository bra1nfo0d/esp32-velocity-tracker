#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL343.h>

// Sensor-Objekt
Adafruit_ADXL343 accel = Adafruit_ADXL343(12345);

void setup() {
  Serial.begin(115200);
  // Prueft ob ADXL343 antwortet
  if (!accel.begin()) {
    Serial.println("ADXL343 nicht gefunden");
    while (true) delay(10);
  }
  // Messbereich
  accel.setRange(ADXL343_RANGE_8_G);
}

void loop() {
  unsigned long currentTimestamp = millis();
  sensors_event_t event;
  // Umrechnung Sensordaten in m/s^2
  accel.getEvent(&event);

  Serial.print(currentTimestamp);
  Serial.print(","); Serial.print(event.acceleration.x);
  Serial.print(","); Serial.print(event.acceleration.y);
  Serial.print(","); Serial.println(event.acceleration.z);

  delay(40);
}
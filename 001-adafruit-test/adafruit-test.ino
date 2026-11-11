#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL343.h>

const unsigned long INTERVALL_US = 10000; // 10 ms (100 Messungen pro Sekunde)
unsigned long naechsteMessung;

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
  naechsteMessung = micros();
}

void loop() {
  if (micros() - naechsteMessung >= INTERVALL_US) {
    naechsteMessung += INTERVALL_US;
    
    sensors_event_t event;
    accel.getEvent(&event); // Umrechnung Sensordaten in m/s^2

    Serial.print(millis());
    Serial.print(","); Serial.print(event.acceleration.x);
    Serial.print(","); Serial.print(event.acceleration.y);
    Serial.print(","); Serial.println(event.acceleration.z);
  }
}
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL343.h>

const unsigned long INTERVALL_US = 10000; // 10 ms (100 Messungen pro Sekunde)
unsigned long naechsteMessung;

const float OFFSET_X = 0.1267;
const float OFFSET_Y = 0.0838;
const float OFFSET_Z = 0.1236;

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
    // Umrechnung Sensordaten in m/s^2
    accel.getEvent(&event);

    // Offset abziehen
    float ax = event.acceleration.x - OFFSET_X;
    float ay = event.acceleration.y - OFFSET_Y;
    float az = event.acceleration.z - OFFSET_Z;

    Serial.print(millis());
    Serial.print(","); Serial.print(ax);
    Serial.print(","); Serial.print(ay);
    Serial.print(","); Serial.println(az);
  }
}
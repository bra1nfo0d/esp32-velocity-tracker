# Adafruit Test

Im Abschnitt `001-adafruit-test` werden die ersten Daten des **Adafruit ADXL343** Accelerometer erfasst. Ziel ist es ein ersten Einblick ueber die Werte zu bekommen.

## Uebersicht

Datei / Ordner|Beschreibung
-|-
`adafruit-test.ino`|Sketch fuer das auslesen der Werte des **ADXL343** Accelerometer
`adafruit-werte-ruhezustand.csv`|Werte die der **ADXL343** ausgegeben mit dem Sketch ausgegeben hat
`bilder/`|Bilder von Aufbau und Schaltplan

## Bilder

### Hardware-Umsetzung

![Testaufbau](bilder/001-adafruit-test-aufbau.jpeg)

### Schaltplan:

![Schaltplan](bilder/001-adafruit-test-schaltplan.png)

## Fazit

Anhand der Werte die der **ADXL343** ausgibt, laesst sich ablesen das der Sensor noch kalibriert werden muss. Das erkennt man daran das der Beschleunigungswert, im Stillstand, die x- und y-Achse weit von der 0 m/s^2 weg sind. Auch muesste die z-Achse eine Beschleunigung von rund 9,81 m/s^2 haben, von welcher sie noch weit entfernt ist.

---
**Naechster Abschnitt**: Die Kalibrierung des **ADXL343**.
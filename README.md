# Geschwindigkeitssensor für Krafttraining mit ESP32

Ein Geraet mit ESP32 und 3-Achsen-Beschleunigungssensor (Adarfruit ADXL343), das an der Hantel befestigt wird. Es zeigt den Beschleunigungsverlauf und zaehlt die Wiederholungen pro Satz. Dazu berechnet es Hubweg (ROM), Geschwindigkeit (v_peak, MCV) und den Geschwindigkeitsverlust im Satz.

## Aufbau

Die Projektrepo besteht aus nummerischen Ordnern. Diese Zeigen den Verlauf an, wie das Projekt umgesetzt wurden ist. Dabei hat jeder Ordner einen eigenes `README.md` Datei, welche die Herangehensweise und die Erkenntnisse des jeweiligen Schrittes naehr darbringen.

## Uebersicht

Nr.|Name|Beschreibung
-|-|-
001|adafruit-test|Sensordaten des **ADXL343** auslesen
002|kalibrierung|Accelerometer mittels Offset kalibrieren
003|zustands-erkennung|System erkennt Ruhe und Bewegung

---

*Projekt im Modul "Projekt: Embedded Systems, IoT, SmartX" der FOM.*

*Autor: Sergej Gurov*
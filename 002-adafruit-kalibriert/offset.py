import csv
import statistics
import math
from pathlib import Path
 
CSV_PFAD = Path(__file__).parent / "../001-adafruit-test/adafruit-werte-ruhend.csv"
G = 9.80665
 
# CSV-Datei auslesen
werte = []
with open(CSV_PFAD, newline="") as datei:
    for zeile in csv.reader(datei):
        try:
            x, y, z = map(float, zeile[-3:])
        except ValueError:
            continue
        werte.append((x, y, z))

if not werte:
    raise SystemExit("Keine Messwerte gefunden.")
 
# Offset berechnen
mittel = [statistics.fmean(achse) for achse in zip(*werte)] # Mittelwert fuer jede Achse
senkrecht = max(range(3), key=lambda i: abs(mittel[i])) # Index der Senkrechten Achse
soll = [0.0, 0.0, 0.0]
soll[senkrecht] = G if mittel[senkrecht] > 0 else -G # Soll der Senkrechten Achse auf +- G
offset = [m - s for m, s in zip(mittel, soll)] # mittel - soll = offset

# Offset Ergebnis
for name, o in zip("xyz", offset):
    print(f"Offset {name}: {o:+.4f} m/s^2")

# Offset Kontrolle
print("Betrag:", math.sqrt(sum(m*m for m in mittel))) # Betrag muss rund 9,81 betragen
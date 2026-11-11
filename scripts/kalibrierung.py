import csv
import statistics
from pathlib import Path
 
CSV_PFAD = Path(__file__).parent / "../001-adafruit-test/werte/adafruit-werte-stillstand.csv"
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
 
# Offset
mittel = [statistics.fmean(achse) for achse in zip(*werte)]
senkrecht = max(range(3), key=lambda i: abs(mittel[i]))
soll = [0.0, 0.0, 0.0]
soll[senkrecht] = G if mittel[senkrecht] > 0 else -G
offset = [m - s for m, s in zip(mittel, soll)]
 
for name, o in zip("xyz", offset):
    print(f"Offset {name}: {o:+.4f} m/s^2")

# Rauschen
rauschen = [statistics.pstdev(achse) for achse in zip(*werte)]
for name, r in zip("xyz", rauschen):
    print(f"Rauschen {name}: {r:.4f} m/s^2")

betrag = [(x * x + y * y + z * z) ** 0.5 for x, y, z in werte]
print(f"Ruheschwelle (Vorschlag): {4 * statistics.pstdev(betrag):.3f} m/s^2")
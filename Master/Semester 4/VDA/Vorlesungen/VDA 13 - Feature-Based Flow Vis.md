Grundidee: wir haben bereits eine Repräsentation von "interessanten" Features im Vektorfeld und wollen das visualisieren. Wir brauchen also nicht mehr das komplette Vektorfeld

## Vortex Core Lines

Vortex $:\approx$ Region mit viel Curl ([[VDA 11 - Geometry-based Flow Vis#^e3052b|Q-Kriterium]])
Vortex Core: Punkt, um den das Fektorfeld herumcurlt

Zwei Arten, Vortex Cores zu visualisieren:
- Regionbasiert (Regionen von hohem Curl)
- Linienbasiert (nur die linien der Vortex Cores)

### Prediction-Correction Scheme
Verfolge die Vortex Core Lines wie folgt:
![[Vortex Core Line Prediction Correction Scheme.png]]

- benötigt Seed Points
- Gradient Descent im Correction Step
- Stop-Kriterium (z.B. wenn Korrekturschritt zu groß)


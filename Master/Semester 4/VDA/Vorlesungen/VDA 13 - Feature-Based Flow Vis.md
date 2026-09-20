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

### Parallel Vectors Operator

Wir haben 2 unabhängige Vektorfelder.
Orte, an denen beide parallel sind, formen kontinuierliche Kurven *(PV-Lines)*
Zwei Vektoren sind parallel $\iff$ Kreuzprodukt ist 0
- Nimm Kreuzprodukt der Vektorfelder
- Im resultierenden Vektorfeld: nimm die 0-Iso-Oberflächen der drei Vektorkomponenten und finde die Schnittpunkte

Man kann nun die beiden Vektorfelder so wählen, dass die PV-Lines Kandidaten für Vortex Cores sind
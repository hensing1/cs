Datum: 12.04.

# Licht und menschliche Wahrnehmung

Wir beschränken uns in der Computergrafik fast ausschließlich auf das [[Optik#Strahlenmodell (Geometrische Optik)|Strahlenmodell]] (die Geometrische Optik).

Herausforderungen:
- die echte Welt hat eine sehr hohe dynamische Range, wir haben aber nur 255 Helligkeitswerte pro Farbkanal zur Verfügung
- da alte Bildröhren eine nichtlineare response haben, werden Farbwerte üblicherweise [[ISS - VL 1#Gamma-Korrektur|gammakorrigiert]] (z.B. mit $\gamma=2.2$) => noch weiterer Genauigkeitsverlust, da einige Werte auf 0 abgebildet werden
- das menschliche Sehen ist nichtlinear, kontextabhängig und von Person zu Person verschieden => nicht trivial zu modellieren
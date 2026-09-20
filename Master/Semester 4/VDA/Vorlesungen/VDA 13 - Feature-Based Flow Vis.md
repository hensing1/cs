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

Für unsteady vector fields nimmt man noch die Zeit-Dimension mit rein (Vektor ist nun $p=(u\ v\ w\ 1)^{t}$) und findet Vertex Core Lines im 4D-Vektorfeld

## Vector Field Topology

Arten von **kritischen Punkten** in Vektorfeldern: Quellen, Senken, Sattelpunkte

Sattelpunkte sind Quellen entlang einer Achse, aber Senken entlang einer zweiten.

Wir verbinden Quellen mit Sattelpunkten, und Sattelpunkte mit Senken, anhand der entsprechenden Streamlines. Das Resultat sind **Separatrices** - Linien, bei denen zur einer Seite die Stream Lines zu einer Senke, und auf der anderen Seite (von derselben Quelle) zu einer anderen Senke fließen.
Der Graph mit den kritischen Punkten als Knoten und Separatrices als Kanten ist die Topologie dieses Vektorfelds.

Einordnung von kritischen Punkten ($v(x_{0})=0$ und $v(x_{0}\pm \varepsilon) \neq 0$) mit Eigenvektoren von der Jakobi-Matrix. Ist der Imaginärteil der entsprechenden Eigenwerte ungleich null, curlt das Vektorfeld um diesen Punkt herum.
Die Separatrix kann man nun starten, indem man vom kritischen Punkt ein $\varepsilon$ in Richtung eines der Eigenvektoren geht und von da die Stream Line extrapoliert.

Meist ist das Vektorfeld begrenzt. An der Grenze fügen wir *Boundary Switch Points* ein. Das sind Punkte, bei denen es zwischen In-Flow in Out-Flow wechselt.
Wir fügen dann extra Separatrizen ein, um die Vektorfeldtopologie zu vervollständigen

Wenn man die Separatrizen von Quelle zu Sattelpunkt in einem Gradienten-Vektorfeld von einem Bild einfügt, erhält man die [[ISS - VL 6#Wasserscheidentransformation]]:
![[Watershed transform.png|348]]
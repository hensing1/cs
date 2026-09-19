[[vda-10-Direct-Volume-Rendering.pdf]]

## Transfer Function

Wir haben ein Volumen, das wir rendern wollen (z.B. CT Scan).
Im Direct Volume Rendering weist die Transfer Function einen *Farbwert* und *Opazität* jedem Punkt im Volumen zu.

**1D-Transferfunktion**
Skalarwert $\mapsto$ Farbe + Alpha

Probleme:
- Meist sind *Übergänge* zwischen Intensitätswerten die wichtigen, zu visualisierenden Features
- Wenn wir interpolieren (insb. zwischen Kanten), können Farben auftreten die wir nicht wollten

**2D-Transferfunktion**
Wir ziehen zusätzlich noch die Gradient Magnitude in Betracht.
Mit Intensität $f(p)$ auf der x-Achse (verschiedene Intensitäten entsprechen verschiedenen Gewebearten), und $| \nabla f|$ auf der y-Achse, sind die Übergänge zwischen Geweben als Bögen zu erkennen:
![[2D Transfer Function.png|264]] ^c1c2ba

**3D-Transferfunktion**
Wir nehmen zusätzlich die Richtungsableitung vom Gradienten in Griadientenrichtung mit dazu.
Die zweite Ableitung hat einen Nulldurchlauf, wenn der Gradient am stärksten ist (ergo wo der Materialübergang ist).

Mehrdimensionale Funktionen: zusätzlich Gradienten, zweite Ableitungen, Output von Segmentierungsalgorithmen verarbeiten

### Transferfunktion in zwei Schritten
Schritt 1: den Inputs 1-/2- oder 3-dimensional *Wahrscheinlichkeiten* für $n$ Gewebearten zuweisen
Schritt 2: den Wahrscheinlichkeiten Farbe und Opazität zuweisen

### Interpolation
Wir wollen zwischen zwei RGBA-Farben interpolieren.

*Straight Color Interpolation*
Wir machen lineare Interpolation direkt zwischen den RGBA-Vektoren.

*Accociated Color Interpolation*
Wir:
- multiplizieren die RGBs mit ihren eigenen Alphas (pre-multiplying)
- interpolieren dann die resultierende "associated color" separat vom Alpha
- teilen die interpolierte associated color durch das interpolierte Alpha, um den Farbwert in der Mitte zu erhalten
-> bewirkt, dass keine Farben mit $\alpha=0$ Einfluss auf das Ergebnis haben.

### Pre-Segmentation
Manchmal reichen auch hochdimensionale Transferfunktionen nicht aus.
Pre-Segmentierung wird manuell oder durch spezialisierte Segmentierungsalgorithmen ausgeführt, der Schritt 1 von oben ersetzt

### Pre- und Post-Classification
Besagt, ob Transferfunktion vor- oder nach dem Interpolieren angewandt wird.

Erst zu interpolieren und dann die Transferfunktion anzuwenden ist langsamer, liefert aber bessere Ergebnisse (als einfach die Farben zu interpolieren)

### Animieren
Wenn wir verschiedene Hypothesen haben, welches Material zu einem Voxel gehören könnte, können wir das Bild animieren und jedes Material für eine Zeitdauer proportional zu seiner Wahrscheinlichkeit anzeigen

## Transfer Function Design
Polygon (oder Paraboloid) in [[VDA 10 - Direct Volume Rendering#^c1c2ba|dem Bild oben]] (2D-Histogramm) einzeichnen, welcher Bereich von der Transfer Function wie eingefärbt werden soll

Man kann dort auch versuchen, Cluster zu finden um sie automatisiert voneinander abzugrenzen - Cluster können dann manuell gemergt und gesplittet werden

## Volume Rendering Integral
Wir möchten unser transferfunktionalisiertes Bild jetzt rendern.

**Optisches Modell:** jeder Punkt absorbiert einen Teil des Lichts, emittiert aber auch einen gewissen Teil selbst

Wir senden einen Strahl von einem Punkt $s_{0}$ aus und terminieren ihn bei $s_{b}$. Dann ist die Lichtintensität, die bei $s_{0}$ ankommt: $$I(s_{0})=\int_{s_{0}}^{s_{b}}q(s)e^{-\tau(s_{0},s)}\,ds$$
mit 

Ray Casting
Opacity Integral
siehe FOCVE

Opacity Peeling: statt early ray termination, zweites Bild anfangen zu rendern sobald sich Opazität ändert -> zeigt nur, was anderenfalls verborgen wäre


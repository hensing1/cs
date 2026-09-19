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
- $q(s)$ die Emission bei $s$
- $\tau(s_{0},s)=\int_{s_{0}}^{s}\kappa(s')\,ds'$
	- $\kappa(s)$ die Absorption bei $s$

Das approximieren wir mit $$\sum_{i=1}^{n}\tilde{C}_{i}\prod_{j=1}^{i-1}(1-A_{j})$$
-> **Front to Back Compositing:**
- $\tilde{C}_{i}$ ist die Farbe am Punkt $i$
- $A_{j}$ die Opazität
- akkumulierte Opazität ist $A_{i}'=A_{i-1}' + (1-A_{i-1}')A_{i}$
- akkumulierte Farbe ist $\tilde{C}_{i}' = \tilde{C}_{i-1}'+(1-A_{i-1}')\tilde{C}_{i}$
-> aufhören, sobald $A_{i}' \approx 1$

Wollen wir verschachtelte Volumen rendern, kann das mit Volume Rendering schwierig werden.
*Opacity Peeling:* statt early ray termination, zweites Bild anfangen zu rendern sobald 1. die akkumulierte Opazität sich 1 nähert und 2. die aktuelle Opazität unter einem Schwellwert liegt -> zweites Bild zeigt nur, was anderenfalls verborgen wäre

**Back to Front Compositing**
Mit $\tilde{C}_{n+1}'=0$ anfangen, und mit Alpha-Blending nach vorne arbeiten: $$\tilde{C}_{i}'=\tilde{C}_{i}+(1-A_{i})\tilde{C}_{i+1}'$$
## Accelerated Volume Rendering
Schnelleres Rendering, z.B. während man interaktiv das 3D-Modell dreht

Ansätze:
- step size erhöhen
- Pre-Integration, wo wir Volume Rendering Integrale im Voraus berechnen und in eine Lookup Table werfen
- Empty Space Skipping: homogene Regionen mit weniger Sample-Punkten approximieren
- Precomputing Gradients: Oberflächengradienten zusammen mit Intensität speichern
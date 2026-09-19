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
![[2D Transfer Function.png|264]]

**3D-Transferfunktion**
Wir nehmen zusätzlich die Richtungsableitung vom Gradienten in Griadientenrichtung mit dazu.
Die zweite Ableitung hat einen Nulldurchlauf, wenn der Gradient am stärksten ist (ergo wo der Materialübergang ist).

Mehrdimensionale Funktionen: zusätzlich Gradienten, zweite Ableitungen, Output von Segmentierungsalgorithmen verarbeiten

### Design for Transfer Functions
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
Pre-Segmentierung wird manuell oder durch spezialisierte Segmentierungsalgorithmen ausgeführt, um 

## Volume Rendering Integral

Ray Casting
Opacity Integral
siehe FOCVE

Opacity Peeling: statt early ray termination, zweites Bild anfangen zu rendern sobald sich Opazität ändert -> zeigt nur, was anderenfalls verborgen wäre


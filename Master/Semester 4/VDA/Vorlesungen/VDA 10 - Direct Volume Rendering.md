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



## Volume Rendering Integral

Ray Casting
Opacity Integral
siehe FOCVE

Opacity Peeling: statt early ray termination, zweites Bild anfangen zu rendern sobald sich Opazität ändert -> zeigt nur, was anderenfalls verborgen wäre


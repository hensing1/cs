[[vda-10-Direct-Volume-Rendering.pdf]]

## Transfer Function

Segmentierung durch Zuweisung eines *Farbwerts* und *Opazität* zu jedem Punkt im Volumen

*1D Transfer Function:* Skalarwerte -> Farbe + Alpha
Mehrdimensionale Funktionen: zusätzlich Gradienten, zweite Ableitungen, Output von Segmentierungsalgorithmen verarbeiten

1D Problem: wenn wir interpolieren (insb. zwischen Kanten), können Farben auftreten die wir nicht wollten


## Volume Rendering Integral

Ray Casting
Opacity Integral
siehe FOCVE

Opacity Peeling: statt early ray termination, zweites Bild anfangen zu rendern sobald sich Opazität ändert -> zeigt nur, was anderenfalls verborgen wäre


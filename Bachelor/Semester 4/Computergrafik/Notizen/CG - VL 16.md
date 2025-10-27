Datum: 17.06.
[[cgintro-14-Texturierung.pdf|Folien 1]]
[[cgintro-15-Texturfilterung.pdf|Folien 2]]

# Texturierung

Wir kleben ein Bild auf ein Objekt.

2D-Textur: $C_\text{tex}(u,v) = (r,g,b)$
Beim Rendering muss dieses Mapping invers gelöst werden

Alle Texturen können z.B. auf einer 2D-Karte leben (Texturatlas)

Es gibt auch 3D-Texturen (z.B. Jahresringe bei Baumstamm)

*Diskrete Textur:* Bilddatei, d.h. zweidimensionales Zahlenfeld
*Prozedurale Textur:* Farbwert für einen Punkt wird durch eine mathematische Funktion berechnet

Bump map: bezieht sich nur auf die Beleuchtung, nicht auf die Geometrie

Displacement Mapping: Geometrie wird mitberücksichtigt

# Texturfilterung

Hat man Texturen oberhalb der < Nyquist-Frequenz >, bekommt man Aliasing (unterabgetastetes Signal).

Mip-Mapping: äääh, Auflösungspyramide

geht nicht mit allem was nicht quadratsich ist

Alles nach Angular Maps "muss wirklich nicht sein"
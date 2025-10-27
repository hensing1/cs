Datum: 02.05.
[[pho1-08-geometric-trans.pdf|Folien]]

# Geometrische Transformation

Geometrische Transformationen können sein:
- Verzerrungen rückgängig machen
- Texture Mapping (Rendering)
- zwei verschieden verzerrte Bilder aneinander ausrichten

***Ansatz:***
- Jedes Bild hat eigenes Koordinatensystem
- die Position jedes Pixels ist ein Vektor
- Matrix für skalieren und rotieren
- additiver Vektor für Verschiebungen

Was wenn kein Integerwert? Dann:
## Resampling

Resampling heißt, eine Diskretisierung und Quantisierung der Werte durchzuführen.

*Nearest Neighbor*
- Nimm denselben Farbwert wie der nächste Nachbarpixel
- $\to$ Pixelpositionen werden gerundet

*Bilineare Interpolation*
- Mache eine lineare Interpolation erst entlang der x-Richtung, dann entlang der y-Richtung
- $\to$ gewichteter Durchschnitt der benachbarten Pixelwerte

*Bikubische Interpolation*
- Mache eine kubische Interpolation erst entlang der x-Richtung, dann entlang der y-Richtung
- $\to$ kubische [[Splines|Spline]]-Interpolation

![[Interpolation.png]]

## Forward/Backward Warping

*Forward Warping*
Jedes Pixel des Eingabebilds wird für sich genommen irgendwo hingeschoben. Dann wird wieder interpoliert, um ein Pixelgrid zurückzuerhalten.

Jedes Pixel hat also seine eigene Transformationsmatrix.

*Backward/Inverse Warping*
- Berechne durch die *inverse* Transformationsmatrix die Position der Outputpixel im Inputbild
- Durch Interpolation: berechne die Intensitätswerte an diesen *irregulären* Positionen

Backward Warping ist dem Forward Warping zu bevorzugen, weil sonst Pixel im Outputbild fehlen können.

## Bild-Subsampling

Bestimmung, inwiefern eine Transformationsmatrix $T=\begin{pmatrix}a & b \\ c & d\end{pmatrix}$ skaliert: $$m = \sqrt{\frac{1}{2}(a^{2}+b^{2}+c^{2}+d^{2})}.$$
$m<1$: Bild schrumpft, glätte das Bild vorher mit $\sigma \approx \frac{m}{2}$
$m=1$: Skalierung bleibt gleich, bilineare oder bikubische Interpolation verwenden
$m>1$: Bild wird aufgebläht, bikubische Interpolation verwenden
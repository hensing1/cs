[[iaan-04-Registration-Normalization.pdf]]

- Wir möchten Gehirnscans *alignen* - dieselbe Voxelposition soll derselben anatomischen Region entsprechen

Warum?
- Dieselbe Person über längeren Zeitraum betrachten (intra-modal, Vergleich derselben Modalität (z.B. MRI))
- Verschiedene Scans (MRI, fMRI, ...) derselben Person alignen (inter-modal)
- Mehrere Personen vergleichen (intra-modal)

Ansatz: man hat ein *Referenzbild* (bleibt unverändert) und ein *Floating Image*. Der Prozess wird auch **Normalisierung** genannt.

Zwei Arten der Registrierung:
- Linear (affin): erlaubt Rotation, Translation, Skalierung, Scherung
- Nichtlinear: erlaubt lokale Deformationen

Typisches Ähnlichkeitsmaß: Bildintensität jedes Voxels

Man kann eine *regressionsbasierte* Registrierung machen (zwei Bilder direkt alignen), z.B. mit Neuronalen Netzwerken
Man kann auch Registrierung anhand von (manuell markierten) anatomischen *Referenzpunkten* machen. Dann wird der *Target Registration Error* minimiert (durchschnittlicher bzw. maximale Distanz zwischen $m$ Referenzpunkten $r_{i}$ und beweglichen Punkten $p_{i}$): $$\begin{align}
\text{TRE}_{\text{mean}}&=\frac{1}{m} \sum_{i=1}^{m}\|r_{i}-T(p_{i}\| \\
\text{TRE}_{\text{max}} &= \max \{ \|r_{i}-T_{i}(p_{i}) \mid i=1,\dots,m \}
\end{align}$$
Wir können auch ohne Referenzpunkte die Konsistenz unserer Transformation überprüfen: wenn wir Referenz und floating image vertauschen, erwarten wir genau die Inverse der Transformation.

## Affine Transformationen

Siehe [[Homogene Koordinaten]] (perspektivische Verzerrung brauchen wir nicht).
Siehe auch [[Photo I - VL 6#^d1442e|backward warping]].

Achsenbelegung:
- Positives $x$: links oder rechts
- Positives $y$: anterior (vorne) oder posterior (hinten)
- Positives $z$: superior (oben) oder inferior (unten)

Welche Orientierung ein Voxel-Grid hat, wird dann mit Codes der Länge 3 angegeben: LAS für Left-Anterior-Superior oder RAS für Right-Anterior-Superior

Es kann vorkommen, dass voxel quaderförmig, aber nicht würfelförmig sind. Dann spricht man von *anisotropischen* Voxeln.

## Kostenfunktionen

- Least-Squares (durchschn. quadratische Differenz zwischen Voxeln)
- Normalized Cross-Correlation (wird maximiert statt minimiert)
- Local Cross-Correlation
	- Wie NCC, nur dass von jedem Voxel der lokale Mittelwert (z.B. in 5x5x5-Fenster) abgezogen wird
- Variance of Intensity Ratios
	- In homogenen Bereichen der Referenz sollte das bewegte Bild ebenfalls homogen sein
	- Wir suchen uns also einen homogenen Bereich, und die Standardabweichung des bewegten Bildes im selben Bereich ist unsere Zielfunktion 
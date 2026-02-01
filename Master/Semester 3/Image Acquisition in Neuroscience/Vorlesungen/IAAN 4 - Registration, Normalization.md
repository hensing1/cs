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
\text{TRE}_{\text{max}} &= \max \{ \|r_{i}-T_{i}(p_{i})\| \mid i=1,\dots,m \}
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

Wir bewerten das Alignment von zwei Bildern allein anhand der Intensitätswerte.
Wir berechnen die Kostenfunktion nur im Bezug auf den überlappenden Teil der Bilder. Dabei ist es wichtig, dass wir den *Durchschnitt* der pixelweisen Kosten nehmen, weil ansonsten die Bilder einfach voneinander weggeschoben werden (weniger Overlap -> Summe wird geringer).

Einfache Lösung: L2-Kosten (least squares, durchschn. quadratische Differenz zwischen Voxeln): $$C^{LS}=\frac{1}{N}\sum_{i=1}^{N}(x_{i}-y_{i})^{2}$$

*Diskontinuitäten in der Kostenfunktion* können vorkommen, weil Pixel sehr aprupt zur Kostenfunktion beitragen - sie sind entweder Teil der Überlappung oder nicht. 
Das ist ein großes Problem für Optimierungsalgorithmen, die leicht in lokalen Optima hängen bleiben.
Daher: Beitrag von Pixeln nahe der Grenze der Überlappung kontinuierlich verringern, um Kostenfunktion zu glätten.

Weitere Kostenfunktionen:
- Normalized Cross-Correlation (wird maximiert statt minimiert): $$S^{NC}=\frac{\sum_{i=1}^{N}x_{i}\cdot y_{i} }{\sqrt{ \sum_{i=1}^{N}x_{i}^{2} } \cdot \sqrt{\sum_{i=1}^{N}y_{i}^{2}}}$$
	- "Cosinus-Ähnlichkeit"
	- Kompensiert ungleichmäßige Bildintensitäten
	- Unzureichend für intermodale Registration
- Local Cross-Correlation
	- Wie NCC, nur dass von jedem Voxel der lokale Mittelwert (z.B. in 5x5x5-Fenster) abgezogen wird
	- Gut für inhomogene Bias-Felder im MRT-Bild
- Variance of Intensity Ratios
	- In homogenen Bereichen der Referenz sollte das bewegte Bild ebenfalls homogen sein
	- Haben wir also eine Intensität im Referenzbild, erwarten wir, dass die Standardabweichung derselben Voxel im angepassten Zielbild ebenfalls gering ist
	- Definition von VIR:
		- Partitioniere Intensitäten der Referenz $X$ in $K$ bins
		- Für bin $k$ enthält die Menge $Y_{k}$ die Intensitäten derselben Voxel im anderen Bild
		- Die Kostenfunktion ist die durchschnittliche, (anhand Anzahl der Bildpunkten und anhand des Mittelwertes) normalisierte Standardabweichung: $$C^{VIR}=\sum_{k=1}^{K} \frac{|Y_{k}|}{N} \frac{\sigma(Y_{k})}{\mu(Y_{k})}$$
		- Funktioniert (als erster Ansatz) für intermodale Registrierung

Wir können uns bei Registierung *multivariate* Histogramme anschauen, mit einem Bild auf der x- und dem anderen auf der y-Achse.
Zwei identische Bilder, die perfekt alignt sind, formen darauf eine diagonale Linie.

Gründe, warum $C^{VIR}$ nicht unbedingt für unterschiedliche Bilder funktioniert:
- Annahme, dass homogene Flächen übereinstimmen, wird z.B. bei CT vs. MRI verletzt (nicht-knöcherne Struktur ist im CT homogen, im MRT sind dort viel mehr Details)
- Skalierung: wird ein Bild so klein, dass es komplett in ein Voxel vom anderen Bild reinpasst, wird die $C^{VIR}$ minimiert


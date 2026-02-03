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

### Intra-Modal

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

Gründe, warum $C^{VIR}$ nicht unbedingt für unterschiedliche Bilder funktioniert:
- Annahme, dass homogene Flächen übereinstimmen, wird z.B. bei CT vs. MRI verletzt (nicht-knöcherne Struktur ist im CT homogen, im MRT sind dort viel mehr Details)
- Skalierung: wird ein Bild so klein, dass es komplett in ein Voxel vom anderen Bild reinpasst, wird die $C^{VIR}$ minimiert

### Inter-modal: Shannon-Entropie

Wir können uns bei Registierung *multivariate* Histogramme anschauen, mit einem Bild auf der x- und dem anderen auf der y-Achse.
Zwei identische Bilder, die perfekt alignt sind, formen darauf eine diagonale Linie.

Wir wollen also die "Entropie" der überlappten Bilder minimieren.
Idee der Entropie: "Informationsgehalt" des Auftreten eines Ereignisses $k$ ist höher, je seltener dieses Ereignis auftritt: $I(k)=-\log_{2}p_{k}$ , mit $p_{k}$ der W'keit von $k$.
Der *Erwartungswert* des Informationsgehaltes für alle Ereignisse, die vorkommen können, ist dann: $$H=-\sum_{k=1}^{K}p_{k}\log_{2}p_{k}$$
Ein "Ereignis" in unserem Fall wäre dann die Wahrscheinlichkeit, dass irgendein Pixel die Intensität $k$ hat.
Minimale Entropie wäre also ein uniformes Bild.

Die Entropie für ein 2D-Histogramm ist also: $$H(X,Y) = -\sum_{i=1}^{K_{X}}\sum_{j=1}^{K_{Y}}p_{ij}\log_{2}p_{ij}$$
Als Zielfunktion gefällt uns die **Mutual Information**: wir wollen die Entropie $H(X)$ und $H(Y)$ der einzelnen Bilder *maximieren* (passiert bei großem Overlap) und die gemeinsame Entropie $H(X,Y)$ *minimieren* (passiert wenn die BIlder gut alignt sind) -$$I(X,Y) = H(X)+H(Y) - H(X,Y) \to \max$$
Variation, die noch besser für unterschiedliche Overlaps funktioniert: **Normalized Mutual Information** - $$NMI(X,Y)=\frac{H(X)+H(Y)}{H(X,Y)} \to \max$$
**Fuzzy Binning**
Wir haben durch diskrete 2D-Histogramme *Diskontinuitäten* und dadurch viele kleine lokale Minima die wir nicht möchten.
Lösung: keinen harten Cutoff, ob eine Intensität zu einem Histogramm-Bin beiträgt, sondern gleichmäßiger Übergang

## Optimierungsprobleme bei der Registrierung

Wir haben nun:
- Referenz $y$
- Bewegliches Bild $x$
- Kostenfunktion $C$
- Erlaubte Transformationen $w$ in einem Raum $S_{T}$

Unser Optimierungsproblem: $$w^{\ast}=\arg\min_{w}\ C(y,T(x | w)).$$

### Multi-Scale Optimization

- Bild verkleinern und optimieren (z.B. Grid Search (Brute Force))
- Vergrößern und vorherige Lösung als Ausgangspunkt nehmen, lokal weitersuchen

### Pertubation and Re-Start

- Lokales Minimum finden
- Zufällig pertubieren und weitersuchen
- mit vorherigem Optimum vergleichen

### Ableitungsfreie Optimierung

Annahme: zu minimierende Zielfunktion $f: \mathbb{R}^{d}\to \mathbb{R}$ ist stetig, nicht unbedingt differenzierbar

#### Downhill Simplex Method
Wir haben eine Startposition $p_{0}$ und suchen $d$ umliegende Punkte, um einen $d$-dimensionalen *Simplex* aufzubauen (also mit $d+1$ Punkten).

![[downhillsimplex.GIF|500]]

**Initialisierung**
- $p_{i} = p_{0} + \Delta_{i}e_{i}$
- $\Delta_{i}$ ist Hyperparameter abhängig von der erwarteten Magnitude der Veränderung entlang $e_{i}$

**Reflektion**
- sei $p_{i}$ der Punkt mit dem höchsten $f$
- "Spiegele" $p_{i}$ an gegenüberliegender Ebene:
	- $\bar{p}:= \frac{1}{d}\sum_{j \neq i}p_{j}$
	- $p_{r} := p_{i}+2(\bar{p}-p_{i})$
- falls $p_{r}$ *nicht* der neue geringste Punkt ist, aber besser als der Zweitschlechteste: ersetze $p_{i}$ durch $p_{r}$, reflektiere erneut
- falls $p_{r}$ schlechter als der zweitschlechteste Punkt ist, würde er in der nächsten Iteration zurückreflektiert werden, also: Kontraktion
- falls $p_{r}$ der beste Punkt: Expansion

**Expansion**
- $p_{r}$ ist der neue niedrigste Punkt - vielleicht ist $p_{e}=p_{i}+3(\bar{p}-p_{i})$ *noch* niedriger
- falls $p_{e}$ besser als $p_{r}$, ersetze $p_{i}$ durch $p_{e}$ und mache die nächste Reflektion

**Kontraktion**
- setze 
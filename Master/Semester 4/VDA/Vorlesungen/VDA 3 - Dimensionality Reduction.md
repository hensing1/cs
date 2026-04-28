
Motivierendes Beispiel: 3D-Scan von einem Gesicht

3D-Scan: 10000 Punkte, aber Beschreibung von Gesicht entlang weniger Achsen möglich

## PCA

Finde (niederdimensionale) orthogonale Basis, damit Variation der Daten entlang der Basisvektoren maximiert wird, wenn auf diesen Untervektorraum projiziert wird (z.B. Ebene in 3D, Linie in 2D)
Alternativ: Summe des quadratischen Fehlers wird bei Projektion minimiert

Weiterer Effekt: *Dekorrelation*

- Ursprung des neuen Koordinatensystems: Durchschnitt der Punkte
- Summe der äußeren Produkte von $(x_{i}-\bar{x})$ (skaliert mit $\frac{1}{n-1}$)
- Eigendekomposition der resultierenden Matrix - höchste Varianz entlang Eigenvector mit größtem Eigenwert

Die Anzahl der großen Eigenwerte sagt einem etwas über die Dimensionalität der Verteilung

Caveat: verschiedene Attribute haben verschiedene Skalierungen
-> vorher normalisieren: $z_{i}=\frac{x_{i}-\mu}{\sigma}$, sonst sind die Principal Components entlang der Achse mit der kleinsten Einheit
es sei denn, die Attribute haben vorher schon dieselbe Einheit, oder haben sehr viel Rauschen das man nicht amplifizieren möchte

Cutoff für Eigenwerte finden: *cumulative ratio of variance*

$$r_{\sigma ^{2}}^{k}=\frac{ \sum_{i=1}^{k}\lambda_{i} }{\sum_{j=1}^{p}\lambda_{j}}$$
Kleinstes $k$ auswählen, sodass 90% der Varianz abgedeckt ist
"look for elbow in the curve"

### Statistical Shape Models

- Shapes alginen
- Jede Shape mit fester Anzahl von Datenpunkten beschreiben
- Durchschnitts-Shape daraus machen
- Für jedes Sample: Displacement Vektor vom Durchschnitt

Coole interaktive Visualisierungen möglich - an einem Punkt ziehen, schauen wie Shapes mit Variation an diesem Punkt sich an anderen Punkten verändern

### Was wenn weniger Punkte als Dimensionen?

Für Zahl der Samples $n$ und Anzahl der Dimensionen $p$: Anzahl der Eigenwerte ungleich null ist $\min(n-1,p)$
$k>n-1$ ergibt also keinen Sinn

Weil wir die Daten vorher zentrieren, verlieren wir einen Freiheitsgrad in der Varianz (1 Datenpunkt: immer zentriert, keine Varianz; 2 Datenpunkte: einziger Freiheitsgrad ist Distanz zwischen den beiden; usw.)

Falls sehr hohe Dimensionalität: Eigenwertproblem ist nicht lösbar (Matrix zu groß)
irgendein $\alpha$ aus den Datenpunkten berechnen


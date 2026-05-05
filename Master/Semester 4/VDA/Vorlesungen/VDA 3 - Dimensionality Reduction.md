
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

inneres Produkt statt äußeres Produkt verwenden

## Kernel PCA

Neue Dimension erfinden, dort normale lineare PCA machen
Feature space mapping: $x \mapsto \Phi(x)$

Kernel Trick: impiziter höherdimensionaler Featurespace, wieder mit innerem Produkt

**Nicht einfach zu interpretieren.**
Es ist nicht so, dass a priori die Hauptkomponenten zu irgendeiner Linearkombination der ursprünglichen Attribute haben.

Idee für Visualisierung:
- zeige Daten im KernelPCA-Koordinatensystem als Scatterplot
- lasse User interaktiv die ursprünglichen Dimensionen auswählen
- Für jeden Datenpunkt: zeige *Gradientenvektor* im Bezug auf die ursprüngliche Dimension
	- schaue nach Dimensionen, in denen diese Gradienten alle halbwegs in dieselbe Richtung zeigen

## Multidimensional Scaling (MDS)

- braucht keine Vektormäßige Beschreibung (z.B. Gensequenz)
- man braucht nur paarweise Distanzen

Input: große symmetrische Matrix mit paarweisen Distanzen (*dissimilarity matrix*)
muss nicht unbedingt Dreiecksungleichung erfüllen

Samples: $x_{1},\dots,x_{n}$
Distanzen: $\delta_{ij}=\delta(x_{i},x_{j})$

Output: Einbettung der Punkte in euklidischen Raum $y_{1},\dots,y_{n}$, sodass euklidische Distanz $d_{ij}=d(y_{i},y_{j}) \approx \delta_{ij}$

Mögliche Fehlerfunktionen:
- absolute Abweichungen minimieren: $$J_{ee}=\frac{\sum_{i < j}(d_{ij}-\delta_{ij})^{2}}{\sum_{i<j}\delta_{ij}^{2}}$$
	- Cluster schrumpfen gerne zusammen
- relative Abweichungen minimieren: $$J_{ff}=\sum_{i<j}\left( \frac{d_{ij}-\delta_{ij}}{\delta_{ij}} \right)^{2}$$
- Kompromiss zwischen den beiden: $J_{ef}$

Lösen mit gradient descent


[[05segmentation1_WS2425_slides.pdf]]

# Segmentierung

## Clustering in Feature-Spaces

- Segmentierung nach Histogramm
- Finde die Peaks im Histogramm durch [ k - means clustering ]
	- Jede Pixelintensität ist ein Datenpunkt
	- Für $k$ segmente, finde $k$ Cluster im Histogramm

Wir können in verschiedenen Feature-spaces clustering vornehmen:
- RGB-Space
- Intensität+Position (dreidimensional)
- Textur (z.B. 24-dimensionaler Feature-space durch "Textons")
	- Ordne jeden Pixel via Nearest-Neighbor seinem Cluster zu
	- Für Pixel-Nachbarschaft: erstelle Histogramm, wieviele Pixel welchen Clustern zugeordnet wurden
	- Material-Klassifizierung möglich, indem Histogramme für Beispieltexturen Bekannt sind

### Agglomeratives Clustering
1. Jeder Datenpunkt ist ein Cluster
2. Berechne Proximity-Matrix
3. Wiederhole bis nur noch ein Cluster vorhanden ist:
	1. Fasse zwei nächsten Cluster zusammen (auf Grundlage einer bestimmten Heuristik)
	2. Aktualisiere Proximity-Matrix

Verschiedene Heuristiken:
- Minimale Distanz zwischen zwei Punkten
- Maximale Distanz zwischen zwei Punkten
- Durchschnittliche Distanz
- Distanz zwischen Massezentren
- Ward-Methode
	- Abstand zwischen zwei Clustern ist SSD zum Massezentrum nach dem Zusammenfassen minus die SSDs der einzelnen Cluster
	- Hierarchisches Analog zu k-means

Das Ergebnis von agglomerativem Clustering ist ein *Dendrogramm*, dh. ein Baum, dessen Wurzel alle Punkte repräsentiert und ein Kindknoten immer eine Teilmenge des Elternknotens ist.

### Mean Shift
- Für jeden Pixel:
	- Betrachte Umkreis dieses Pixels im Feature-Space
	- Berechne Masseschwerpunkt in diesem Umkreis
	- Wiederhole mit neuem Umkreis um diesen Masseschwerpunkt
	- -> konvergiert irgendwann
- Ein Segment ist die Menge aller Pixel, die zum selben Schwerpunkt im Feature-Space konvergieren

Vorteile:
- Verschiedenförmige Cluster im Feature-Space können gefunden werden (nicht nur konvexe wie bei k-means)
- Ein Parameter (Größe des Umkreises)
- Generisch

Nachteile:
- Skaliert nicht gut mit Dimensionalität des Feature-Spaces

## Graph Cuts

- Jeder Pixel ist ein Knoten im Graph
- Kanten zwischen Pixelpaaren (normalerweise nur zwischen benachbarten Pixeln)
- Kantengewichte: Ähnlichkeitsmaß zwischen Pixeln ("Affinität"), z.B.:
	- $W_{ij}=\exp\left(- \frac{\|x_{i}-x_{j}\|^{2}}{2\sigma^{2}}\right)$
		- kleines Sigma: gruppiere nur sehr ähnliche Pixel
		- größeres Sigma: gruppiere auch unähnlichere Pixel
	- "Ähnlichkeit": Farbe, Position, ...
	- -> je ähnlicher, desto höher das Kantengewicht
- Clustering erfolgt durch das Entfernen von Kanten
- Entfernen aller Kanten mit geringer Ähnlichkeit
- Graph-cut mit geringsten Gesamtkosten

> [!note] Notation
> **Knotengrad** (Degree): Summe der *Gewichte* der inzidenten Kanten $$D(x_{i})=\sum_{j \in V}w_{ij}$$
> **Volumen** einer Knotenmenge $C$ = Summe der Knotengrade aller Knoten (jede interne Kante der Menge wird doppelt gezählt) $$Vol(C)=\sum_{i \in C}D(x_{i})$$
> Der **Schnitt** zwischen zwei Subgraphen ist die Summe der Kantengewichte, die getrennt werden:
> $$Cut(C_{1},C_{2}) =\sum_{{i}\in C_{1}}\sum_{{j}\in C_{2}}w_{ij}$$

Ein Min-Cut ist der geringste Cut, mit dem der Graph in zwei Teile geteilt werden kann.
Clustering wie folgt:
- Cut im Datensatz finden
- Kanten entfernen
- Wiederholen, bis $k$ Cluster gefunden sind

Leider ist ein solcher Min-Cut anfällig für Ausreißer -> sehr kleine Cluster bei Rauschen
-> Normalisierung durch Volumen der Cluster:
$$normCut(C_{1},C_{2})=Cut(C_{1},C_{2}) \cdot \left(\frac{1}{Vol(C_{1})} + \frac{1}{Vol(C_{2})}\right)$$
Leider wird durch die Normalisierung das ganze NP-schwer.

### Approximation durch Graph-Laplacian

Die *Graph-Laplacian* $L=D-W$ ist eine Matrix, welche den Graphen repräsentiert:
- $D_{ii}$: Knotengrad des Knotens $i$ ($D$ ist Diagonalmatrix)
- $W_{ij}$: Gewicht zwischen den Knoten $i$ und $j$

-> $L$ ist symmetrisch.

Mathemagie (nicht so wichtig):
$$\min_{x}normCut(x) = \min_{y} \frac{y^{T}(D-W)y}{y^{T}Dy}$$
mit $y$ ein Binärvektor ($y_{i} \in \{ 1,-b \}$), der uns sagt, ob der Pixel $i$ in das eine oder das andere Segment gehört.

Wenn wir beliebige Reellwerte für $y$ erlauben, erhalten wir ein [generalisiertes Eigenwertproblem](https://en.wikipedia.org/wiki/Eigendecomposition_of_a_matrix#Generalized_eigenvalue_problem):
$$
(D-W)y=\lambda Dy.
$$
Wir suchen hierbei nach dem Eigenvektor $y$ mit dem *kleinsten* Eigenwert. (Bzw. zweitkleinsten, denn der kleinste Eigenwert ist 0 - korrespondiert mit $y_{i}=1$ bzw. mit dem leeren Cut.)

Da $y$ reellwertig ist, haben wir nur eine Annäherung. Nun brauchen wir noch einen Schwellwert, mit dem wir den Vektor binarisieren und damit die Partitionierung haben.

Das Ganze löst man dann mit einem Eigensolver ("Lanczos method"), welcher ausnutzt, dass wir hauptsächlich 0-Einträge in der Matrix haben (nur benachbarte Pixel haben eine Kante), und weil wir nur einen Eigenwert suchen.
Die Laufzeit von sowas ist $\mathcal{O}(n^2)$.

#### Spectral Clustering
Mehr als 2 Cluster:

- Wir können die $k$ niedrigsten Eigenwerte berechnen
- Jeder Eigenwert repräsentiert eine alternativen Cut
- Wir schreiben unsere $k$ Eigenvektoren nebeneinander in eine $n \times k$-Matrix
- Pro Pixel haben wir jetzt eine *Zeile* mit $k$ einträgen, d.h. wir haben einen $k$-dimensionalen Wert pro Pixel
- In diesem $k$-dimensionalen Feature-Space können wir jetzt Clustern und erhalten dadurch unsere Bildsegmente

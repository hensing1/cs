Datum: 09.01.
[[ISS11_WS2324_Features_240109_240108.pdf|Folien]]

[[ISS_WS2324_Aufgabenblatt11.pdf|Aufgabenblatt]], [[Blatt 11|Lösungen]]
# Merkmale

Yippie Data Science: 
- Man hat einen *Trainable Classifier*. Dieser Classifier nimmt einen Satz von Merkmalen entgegen und bestimmt, zu welcher Objektklasse das Objekt mit diesen Merkmalen gehört.
- Ein Klassifizierer kann sowas sein wie MAP-Klassifikation
- Es gibt verschiedene Arten von Merkmalen, mit denen man einen Klassifizierer füttern kann:
	- Handcrafted Features / Low-Level Features direkt aus einem Feature Extractor
		- Lokale Merkmale
			- Werden an verschiedenen Orten des Segments ermittelt.
			- z.B. SIFT-Deskriptoren von Keypoints
		- Globale Merkmale
			- Beziehen sich auf das gesamte Segment.
			- Beispiele:
				- Formmerkmale
				- Textur, Farbe, Intensitäten
				- Hu-Momente
				- Local Binary Patterns
	- Mid-Level Features
		- werden auf Grundlage von Handcrafted Features erzeugt
		- Unüberwachte Ansätze:
			- Bag of Visual Words
			- Principal Component Analysis (PCA)
		- Überwachte Ansätze:
			- Multi-Layer Perceptrons (MLP)
			- Sparce Coding

## Handcrafted Features

### Local Binary Patterns

Für jedes Segmentpixel $g_c$ :
- $g_c$ sei Zentrumspixel
- Betrachte $P$ gleichmäßig im Kreis (Radius $R$) verteilte Umgebungspixel $g_p$
	- $0 \leq p \leq P-1$
- Erstelle $P$-stellige Binärzahl $LBP$:
	- Mit $g_0$ als Ostpixel, dann im Uhrzeigersinn: wenn $g_{p}\geq g_{c}$, dann $LBP \,\,+\!\!= 2^{p}$

Erstelle nun $2^P$-dimensionale Histogramm der LBP-Zahlen für alle Segmentpixel

Rotation Invariant Local Binary Patterns ($\text{LBP}^\text{ri}$): shifte jede $LBP$-Zahl solange, bis geringste Binärzahl herauskommt

Uniform Local Binary Patterns ($\text{LBP}^\text{riu2}$): betrachte nur diejenigen Patterns, in denen nur zwei Wechsel zwischen 0 und 1 vorkommen, und shifte sie zur geringsten Binärzahl $\to$ nur $P$ mögliche Codes

### Momente

Verallgemeinerte Bildmomente eines Segments $s$: $$\mu_{pq}(s) = \sum_{(i,j)\in s}(i-i_{\mu})^{p}(j-j_{\mu})^{q}$$

Für Skaleninvarianz normieren: $$\eta_{pq}(s) = \frac{\mu_{pq}(s)}{[\mu_{00}(s)]^{\gamma}}$$
mit $\gamma=\frac{p+q}{2}+1$ für $p+q \geq 2$.

#### Hu-Momente
Die Hu-Momente sind 7 Kennzahlen, die sich jeweils aus allen möglichen $\eta$'s berechnen. Sie sind robust gegenüber Skalierung, Rotation und Spiegelung

## Mid-Level Features

### Bag of (Visual) Words

Bag of Words in der Textverarbeitung: Histogramm für Dokument ausgehend von Wörterbuch

Wörterbuch für die visuelle Version:
- Grundlage: Bildmerkmale wie SIFT-Deskriptoren
- Clustering dieser Merkmale anhand von Trainingsdaten (z.B. mit k-Means)
- Zuordnung von im Bild gefundenen Merkmalen zu Clustern anhand der minimalen Distanz zum Clusterzentrum
- Anhand dieser Zuordnung: Erstellung von Histogramm

### Principal Component Analysis

Reduzierung von Dimensionen durch Erkennung von Korrelationen

Hauptkomponenten sind Vermischungen von Merkmalen -> Erklärbarkeit geht verloren

Vorgehen: 
- Gegeben: $n$ Segmente $s_i$ mit jeweils $k$ Merkmalen
- Für jedes Merkmal $z_j$:
	- Berechne Mittelwert $\mu_j$
	- Ersetze $z_{j}(s_i)$ durch $z_{j}(s_{i})-\mu_{j}$, sodass Erwartungswert $E(z)=0$
- Erstelle Kovarianzmatrix:
	- $C(z) = \begin{pmatrix}\sigma_{1}^{2} & \ldots & \sigma_{1}\sigma_{k} \\ \vdots & \ddots & \vdots \\ \sigma_{k}\sigma_{1} & \ldots & \sigma_{k}^{2}\end{pmatrix}$
	- 
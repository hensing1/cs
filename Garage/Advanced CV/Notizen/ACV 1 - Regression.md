[[02regressionSS25_slides.pdf]]

*Beispielaufgabe*
- Gegeben: Silhouette aus 50 Datenpunkten ($100 \times 1$-Vektor)
- Gesucht: Encoding von Körper-Pose als $55 \times 1$-Vektor, abhängig von der Silhouette

## Histogrammdeskriptoren

Lokale Deskriptoren: z.B. SIFT, andere Points of Interest

Die Menge der lokalen Deskriptoren hängen vom Bild ab. Also wollen wir sie zunächst zusammenfassen, um einen *einheitlichen* Deskriptor zu erhalten.

Herangehensweise:
- Typische Deskriptoren finden:
	- mit [[GdKI - VL 18#k-Means Clutering|k-Means-Clustering]] k Cluster im Feature space finden
	- **Codebook** erstellen: Mittelwerte der jeweiligen Cluster
- Histogramm erstellen: pro Codebook-Eintrag zählen, wieviele Deskriptoren in einem Bild ihm am nächsten sind

*Histogramm normalisieren:*
- nötig, weil nicht jedes Bild dieselbe Anzahl von Features hat
- Summe = 1
- Kleinere Histogrammwerte stärken: Quadrat- oder Kubikwurzel nehmen

*Histogramme vergleichen:*
- mit einer *Kernelfunktion* (vergleicht Histogrammwerte paarweise)
- Für Histogramme $h,h' \in \mathbb{R}^{K}$
	- Linearer Kernel: $k(h,h')=\sum_{j}h_{j}h'_{j}$
	- Histogramme als diskrete Wahrscheinlichkeitsverteilungen interpretieren:
		- Summe der Minima: $k_{HI}(h,h')=\sum_{j}\min(h_{j},h'_{j})$
		- Bhattacharya: $k_{\text{Bhattacharya}}(h,h')=\sum_{j}\sqrt{ h_{j}h'_{j} }$
		- Symmetrische Kullback-Leibler-Divergenz: $k_{\text{symKL}}(h,h')=\exp\left( - \frac{1}{2}(KL(h \mid h') + KL(h' \mid h)) \right)$
			- $KL(h \mid h') = \sum_{j}h_{j} \log \frac{h_{j}}{h'_{j}}$
		- Normalisierte Differenz: $k_{\chi ^{2}}=\exp\left( - \frac{1}{\gamma}\chi ^{2}(h,h') \right)$
			- $\chi ^{2}(h,h')=\sum_{j} \frac{(h_{j}-h'_{j})^2}{h_{j}+h'_{j}}$

Wir mögen $k_{HI}$ und $k_{\chi ^{2}}$, weil große Differenzen geschrumpft werden. Dadurch wird vermieden, dass wenige Bins die Ähnlichkeitsmetrik dominieren.

> [!example] Features für Silhouetten
> Situation: verschiedene Silhouetten können verschieden viele Datenpunkte haben, sollen aber anhand konstant-dimensionalem Feature-Vektor beschrieben werden
> 
> *Kontext* eines Punktes Beschreiben mit Histogramm:
> ![[Shape Context.png|400]]
> 
> Dann: in diesen ganzen 60-dimensionalen Histogrammen via k-Means Cluster finden (z.B. $k=100$), die einzelnen Silhouette-Punkte den Clustern zuordnen, dadurch pro Silhouette ein neues Histogramm generieren

## Einfache Regression

Annahme: zu vorhersagender Wert $w \in \mathbb{R}$ ist lineare Funktion der Messwerte $x \in \mathbb{R}^{d},$ Unsicherheit wird mit gleichbleibender Gaußkurve beschrieben.
Besteht $w$ aus mehreren Werten, modelliert man jeden Wert als unabhängiges Gauß-Modell:

$$P(w_{i} \mid x_{i}, \theta) = \text{Norm}_{w_{i}}[\phi_{0}+\phi^T x_{i}, \sigma ^{2}]$$
Die Parameter $\theta$ sind die Koeffizienten $\phi_{0} \in \mathbb{R},\phi \in \mathbb{R}^{d}$ der linearen Funktion und die Standardabweichung $\sigma \in \mathbb{R}$. $P(w_{i} \mid x_{i}, \theta)$ ist die *Likelihood*.

![[Linear Regression.png|300]]

Zusammenfassen der Koeffizienten: $$\begin{align}
x_{i} &\leftarrow \begin{bmatrix} 1 & x_{i}^{T}\end{bmatrix}^{T} \\
\phi &\leftarrow \begin{bmatrix} \phi_{0} & \phi^{T}\end{bmatrix}^{T} \\
\Rightarrow P(w_{i} \mid x_{i}, \theta) &= \text{Norm}_{w_{i}} [\phi^{T}x_{i}, \sigma ^{2}]
\end{align}$$

Für $I$ Trainingsdaten ist die Likelihood des kompletten Datensatzes das *Produkt* aus den Likelihoods für die einzelnen Daten.
Trainingsdaten zusammenfassen: $$X = \begin{bmatrix}x_{1} & x_{2} & \dots & x_{I}\end{bmatrix}, \quad w = \begin{bmatrix}w_{1} & w_{2} & \dots & w_{I}\end{bmatrix}^{T}$$
Likelihood: $$P(w \mid X, \theta) = \text{Norm}_{w}[X^{T}\phi, \sigma^2 \text{Id}]$$
### Ausrechnen

Wir hätten gerne $\hat{\theta}=\text{argmax}_{\theta}[P(w \mid X, \theta)]$.

Die Parameter $\hat{\phi}$ können direkt (unabhängig von der Unsicherheit $\sigma$) optimiert werden, denn mit $X^{T}\hat{\phi}=w$ bzw. $X^{T}\hat{\phi}-w \to\text{min}$ haben wir ein [[Numerik - VL 2|lineares Ausgleichsproblem]]:
$$\hat{\phi}=(XX^{T})^{-1}Xw$$
Die Standardabweichung lässt sich auch direkt berechnen:
$$\hat{\sigma}^{2}= \frac{(w-X^{T}\phi)^{T}(w-X^{T}\phi)}{I}$$

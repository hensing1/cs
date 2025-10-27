[[10shapes_WS2425_slides.pdf]]
# Shapes

Shape/Umriss := das was übrig bleibt, wenn man Ort, Größe und Rotation rausfiltert

Definiert durch Punktmenge

Wir hätten gern ein Modell, das immer einen Umriss produziert, der so aussieht wie das was wir modellieren wollen.
Eine Snake ist deshalb tendenziell ungeeignet.

## Template Model
- Landmark points $W=\{ w_{n} \}_{n=1}^{N}$ (bekannt), die den Umriss definieren
- Werden auf das Bild gemappt durch *Transformation* $\text{trans}[w,\Psi]$
- Transformation soll die Likelihood $P(x \mid W, \Psi)$ maximieren, bzw. die Distanz minimieren (vgl. [[CV 4 - Edges#^64866f|Distanztransformation]])
	- $P(x \mid W, \Psi) \propto \prod_{n=1}^{N} \exp[-(\text{dist}[x, \text{trans}[w_{n}, \Psi]])^{2}]$
- Darstellung der Transformation durch [[Homogene Koordinaten]] (Scherung, Verschiebung, Rotation, Skalierung, Spiegelung)

**Maximum Likelihood mit Ableitung**
- Analytische Lösung für globales Optimum gibt es nicht -> wir arbeiten mit Ableitungen der Distanzfunktion

Ableitung von $\text{dist}[x, \text{trans}[w_{n}, \Psi]]^{2}$ leicht durch Pixeldifferenz in $x$- und $y$-Richtung zu bestimmen.
Diese Methode kann bei suboptimaler Initialisierung leicht in lokalen Optima hängen bleiben.

### Iterative Closest Points
- nimm lose gefittete Shape im Bild
- für jeden Punkt der Shape:
	- finde nächsten Kantenpunkt im Bild entlang der Shape-Normalen
-> nun hat man Correspondences


Gegeben: Punkte $(x_{i},y_{i})$ und Korrespondenzen $(x_{i}', y_{i}')$
Gesucht: Affine Transformation mit Parametern $m_{1,\ldots,t}, t_{1,2}$ sodass
$$\begin{pmatrix}x_{i}' \\ y_{i}'\end{pmatrix} = \begin{pmatrix}m_{1} & m_{2} \\ m_{3} & m_{4}\end{pmatrix}\begin{pmatrix}x_{i} \\ y_{i}\end{pmatrix} + \begin{pmatrix}t_{1} \\ t_{2}\end{pmatrix}.$$

Daraus machen wir ein Gleichungssystem der Form $Ax=b$, sodass $x$ den gesuchten Parametern entspricht: $$\begin{pmatrix}& & \ldots & & &  \\ x_{i} & y_{i} & 0 & 0 & 1 & 0 \\ 0 & 0 & x_{i} & y_{i} & 0 & 1 \\ & & \ldots & & & \end{pmatrix} \begin{pmatrix}m_{1} \\ m_2 \\ m_3 \\ m_4 \\ t_{1} \\ t_{2}\end{pmatrix} = \begin{pmatrix}\vdots \\ x_{i}' \\ y_{i}' \\ \vdots \end{pmatrix}$$
Jetzt haben wir ein [[Numerik - VL 2|lineares Ausgleichsproblem]], das wir mit least squares oder SVD fitten können.
Weil diese Matrix nur dünn besetzt ist (50% der Einträge sind 0), gibt es auch optimierte Solver, die das ausnutzen (praktisch wenn man sehr viele Korrespondenzen hat).
## Statistical Shape Models
auch: "Active Shape Models"

Wir möchten unsere Shape lernen.
Dafür brauchen wir *Trainingsdaten*, die gut aligned sein müssen.

> **Procrustes Analysis**
> Gegeben: $I$ Shapes mit jeweils $N$ Landmark Points
> Gesucht: Alignment, sodass diese Shapes möglichst gut überlappen.
> 
> Zwischen den einzelnen Shapes haben wir außerdem *Korrespondenzen*, z.B. wenn alle Punkte immer in derselben Reihenfolge sind.
> 
> Vorgehen:
> - Nimm irgendeine Shape als Mittelwert
> - Löse für jede andere Shape die affine Transformation zu diesem Mittelwert (lineares Ausgleichsproblem, Konstruktion wie oben)
> - Neue Mittelwert-Shape setzt sich zusammen aus Mittelwerten aller Landmarks
> - Wiederhole ab 2.

*Ziel für Active Shape Model*
- Punkte darstellen als $$w_{i} = \mu + \Phi h_{i}+ \epsilon_{i}$$ wobei
	- $w_{i}$ ein *Vektor*, der die $x,y$-Koordinaten aller Landmark Points enthält
	- $\mu$ der Mittelwert der Trainingsdaten
	- $h_{i}$ ist ein Vektor in einem niedrig-dimensionalen ($K$-dim.) *Latent Space*
	- $\Phi=[\phi_{1},\phi_{2},\dots,\phi_{K}]$ ist Mapping vom Latent Space zu x-y-Koordinaten
	- $\epsilon$ ist normalverteiltes Rauschen

Idee: jeder Parameter $h$ soll eine gültige Shape generieren.
Man braucht mit diesem Ansatz überraschend wenig Parameter für gute Darstellungen

### PCA
Um so wenige Dimensionen wie möglich zu haben, schaut man sich an, in welche Richtung die Daten die geringste Varianz haben.
Für eine Punktmenge $X$ mit Mittelwert $\bar{x}$ erstellt man die Matrix $$A=\left[\sum_{x \in X}(x-\bar{x})(x-\bar{x})^{T}\right]$$
und macht eine Eigenvektor-Analyse.
Seine Datenpunkte stellt man dann in der Basis dieser Eigenvektoren dar, und schmeißt die Dimensionen raus, die zu den kleinsten Eigenwerten gehören.

Für unsere Shapes:
- Shape-Vektoren für alignte, $I$ Shapes: $\{ w_{i} \}_{i=1}^{I}$
- Berechne Mittelwert-Shape $\mu$
- Berechne $W=\begin{pmatrix}w_{1} - \mu & \dots & w_{I}-\mu\end{pmatrix}$
- Berechne Eigenwertzerlegung $WW^{T}=U \Sigma V^{T}V \Sigma U^{T}=UL^{2}U^{T}$
	- $u_{i}$ sind die Basisvektoren

Regel für die Anzahl der Eigenvektoren: behalte die Vektoren, die für $95 \%$ der Varianz sorgen.
In der Matrix $L$: setze $K$, sodass $\frac{\sum_{i=1}^{K}L_{ii}^{2}}{\sum_{i=1}^{D}L_{ii}^{2}} > 0.95$.

### Probabilistische PCA
dies das Ananas

## Inferenz
Wir haben unsere Shape mit Parametern $h$ gelernt. Nun möchten wir die Transformation $\Psi$ zusammen mit den Parametern $\hat{h}$ finden, die unser Shape Model mit einem Bild überlappt.

Normalerweise optimiert man $\Phi$ und $h$ abwechselnd.

> *Algorithmus*
> 1. Initialisiere Shape-Parameter als $b=\vec{0}$ (mean shape)
> 2. Generiere Shape-Punkte als $w_{i}=\mu+\Phi b$
> 3. Für Korrespondenzen $y$ im Bild: Finde Translationsvektor $t$, Skalar $s$ und Rotationswinkel $\theta$, sodass die Shape möglichst gut in das Bild passt (z.B. mit ICP) - als homogene Matrix $T=\begin{pmatrix}s \cos\theta & -s\sin \theta & t_{x} \\ s \sin \theta  & s \cos \theta & t_{y} \\ 0 & 0 & 1\end{pmatrix}$
> 4. Berechne $y'=T^{-1}y$ und projiziere die Korrespondenzen, die im Bild gefunden wurden, zurück in das Koordinatensystem der Shape
> 5. Aktualisiere Parameter: $b=\Phi^{T}(y'-\mu)$
> 6. Falls nicht konvergiert, zurück zu Schritt 2

Die Landmark Points müssen keine 2D-Punkte mit $x,y$-Koordinaten sein, sie können auch Pixel sein und unser Modell lernt die Intensitäten.
Ein Eigenvektor hat dann einen Wert pro Pixel, und gibt an, wie sich dieser Pixel in unserer Parametrisierung verändert.

Einfacher Test, ob ein Bild ein Objekt enthält, das wir durch unser Shape-Modell beschreiben können:
- Mappe das Bild in den Latent Space
- Shape-Modell kann durch den latent space nur Dinge in Form der trainierten Shape generieren
- Generiere ein Bild durch die im Mapping gefundenen Parameter
- Ist das Ergebnis ähnlich zum Originalbild?
	- Ja: Bild enthält Shape
	- Nein: Bild enthält etwas anderes

Wenn man möchte, dass seine Parameter tatsächlich bestimmte Eigenschaften abbilden (z.B. Körpergröße), kann man eine Regression mit entsprechend gelabelten Daten machen und Eigenvektor-Kombinationen diesen Eigenschaften zuweisen.
Datum: 24.10.
[[ISS02_WS2324_LinearFiltering_231024_231019.pdf|Folien]]

[[ISS_WS2324_Aufgabenblatt02.pdf]]
# Bildstörungen und lineare Operatoren

Wir befassen uns mit *deterministischen* und *stochastischen* Einflüssen auf die abgebildeten Information.

- Deterministische Einflüsse: berechenbare und wiederholbare Einwirkungen
- Stochastische Einflüsse: statistisch beschreibbare Einwirkungen

## Lineare Operatoren

Ein Operator $O(\cdot)$ heißt *linear*, wenn er die Homogenität und Additivität erfüllt, also als lineare Funktion beschreibbar ist.
Der Operator soll die Störung beschreiben. 

Ein linearer Operator kann nur die *gewichtete Summe der Pixel* sein.

Ein linearer Operator ist *verschiebungsinvariant*, wenn es egal ist, ob man erst das Bild verschiebt und dann den Operator anwendet, oder andersherum.
Beispiele für verschiebungsinvariante Einflüsse:
- Unschärfe durch Defokussierung
- Bewegungsunschärfe

### Konvolution
Die Konvolution (oder Faltung) ist eine Methode zur Anwendung eines linearen Operators.

> [!abstract] Definition *Konvolution (2D)*
> Seien $g,f: \mathbb{R}^{2} \supseteq D\to \mathbb{R}$ zwei Funktionen. Die Konvolution von $f$ und $g$ ist definiert als:$$(f \ast g)(x,y)=\sum_{u\in D}\sum_{v\in D} f(u,v) \cdot g(x-u,y-v).$$

^6f8c9c

Das Ergebnis $(f \ast g)$ ist also eine gewichtete Summe der Funktionswerte von $g$.

In der Bildverarbeitung ist die Konvolutionsfunktion in aller Regel eine $m\times m$-Matrix, genannt Konvolutions-/Faltungsmaske/-kern. Es ist also jeder Pixel die gewichtete Summe aus allen $m^2$ Pixeln im Umfeld dieses Pixels.

#### Randbehandlung
An den Bildrändern geht die Konvolutionsmaske über den Bildrand hinaus. Hierfür gibt es verschiedene Lösungsansätze:
1. Interpretierung der Pixel jenseits des Randes als:
	1. Schwarz
	2. Gleichfarbig wie der nächstgelegene Randpixel
	3. Gespiegelt am Bildrand
2. Vernachlässigung der Randpixel $\to$ Bilddimensionen schrumfen um Größe der Maske


#### Eigenschaften

Für Konvolution gilt neben Linearität und Verschiebungsinvarianz die Kommutativität und Assoziativität, es ist also egal, in welcher Reihenfolge man Konvolutionen ausführt, oder ob man zunächst die Konvolutionsmasken nacheinander auf das Bild anwendet, oder erst die Masken auf sich selbst anwendet.

Man spart also Rechenzeit, wenn man erst all seine Konvolutionen zu einer Maske zusammenfasst, und sie am Ende nur einmal auf das Bild anwendet.

Damit die Helligkeit des Bildes gleichbleibt, sollte die Summe über alle Matrixfelder gleich 1 sein.

## Deterministische Einflüsse
### Bewegungsunschärfe

Eine Vertikale Bewegungsunschärfe kann mit folgendem Filter modelliert werden: $$\begin{bmatrix}0 & 0 & 0,2 & 0 & 0 \\ 0 & 0 & 0,2 & 0 & 0 \\ 0 & 0 & 0,2 & 0 & 0 \\ 0 & 0 & 0,2 & 0 & 0 \\ 0 & 0 & 0,2 & 0 & 0\end{bmatrix}$$
Jeder Pixel des Ausgangsbilds halt also den Durchschnittswert des Pixels am Ursprungsbild an derselben Stelle und dessen beiden oberen und unteren Nachbarn.

Eine inverse Filterung hiervon ist das *Wiener-Filter*, welches also (Bewegungs-)Unschärfe in einem Bild rückgängig machen kann.

## Stochastische Einflüsse
### Quantenrauschen

Photonenrauschen ist eine zufällig verteile Störung im Bild, bei welcher Photonen "nicht an der richtigen Stelle" auf das Bild treffen. 

Dieses Rauschen verringert oder erhöht die Intensität jedes Pixels mit einer Wahrscheinlichkeit, die sich durch eine Gaußsche Normalverteilung modellieren lässt (Erwartungswert 0): $$I(x,y) = I_{u}(x,y) + \nu(x,y),$$
wobei die Stärke des Rauschens mit der Varianz $\sigma^{2}$ beschrieben wird ("Breite" der Gaußkurve von $\nu$).

#### Signal-to-Noise ratio
Ist eine Varianz $\sigma^{2}$ *gegeben*, lässt sich die SNR als Maß für die Signalstärke berechnen (größer ist besser):
- Unbekannter Bildinhalt:
	- $\text{SNR}_{\max}(I)$ $= I_{\text{max\_given}}/\sigma$
	- $\text{SNR}_\text{avg}(I) = \frac{1}{S \cdot Z} \sum_{x=0}^{S-1}\sum_{y=0}^{Z-1}I(x,y) / \sigma$
- Bekannter Bildinhalt:
	- Berechnung von $\text{SNR}_\text{OB}$ als Mittelwert der Bildstärke geteilt durch Mittelwert der Störung

### Impulsrauschen
- Störpixel haben entweder minimale oder maximale Helligkeit
- Nicht durch Gauß-Verteilung approximierbar
- Nur wenige Pixel gestört (z.B. 5%)
- In lokaler Umgebung von Störpixel meist keine anderen Pixel gestört
- schwer modellierbar

### Mittelwertfilter
Da stochastisches Rauschen zufällig ist, würde man am liebsten entlang der Zeitachse filtern. Das geht in aller Regel aber nicht, also nimmt man den Durchschnittswert in der unmittelbaren Umgebung des Pixels.

Ein Mittelwertfilter sieht also so aus (kann auch größer werden): $$\begin{bmatrix} \frac{1}{9} & \frac{1}{9} & \frac{1}{9} \\ \frac{1}{9} & \frac{1}{9} & \frac{1}{9} \\ \frac{1}{9} & \frac{1}{9} & \frac{1}{9}\end{bmatrix}$$
- Es glättet Quantenrauschen einigermaßen gut
- Das Bild wird unschärfer (insb. Kanten)
- Für Impulsrauschen weniger gut geeignet

### Gauß-Filter
Jeder Wert der Konvolutionsmaske ist so nah wie möglich an der Gauß-Funktion (hinterher wird normiert, sodass alle Werte in Summe 1 sind).

Eindimensionales Filter:
$$f_{G,\sigma}(u) = \frac{1}{\sqrt{2\pi \sigma^{2}}}\cdot e^{-u^{2}/2\sigma^{2}}$$
Zweidimensionales Filter (Produkt von eindimensionalen Filtern in x- und y-Richtung): $$f_{G,\sigma}(u,v) = \frac{1}{\sqrt{2\pi \sigma^{2}}}\cdot e^{-(u^{2}+v^2)/2\sigma^{2}}$$ ^1027d8
- Konvolutionskern ist groß genug zu wählen, dass die Werte der Gauß-Funktion hinreichend approximiert sind
- Mehr Sigma -> mehr Glättung

### Binomialfilter
Binomialfilter sind eine gute Approximation der Gauß-Filter, die aber effizient mit ganzzahligen Operationen berechnet werden können.

Eindimensionales Binomialfilter $B^k$ der Ordnung $k$ und Größe $k+1$: $$b_{i}^{k}=\binom{k}{i}$$
Normiert: $$\begin{align*}
B^{2}&=\frac{1}{4}\begin{pmatrix}1 & 2 & 1\end{pmatrix}\\
B^{4}&= \frac{1}{16}\begin{pmatrix}1 & 4 & 6 & 4 & 1\end{pmatrix}
\end{align*}$$

Die Zweidimensionale Version ist das [[Matrizen#Äußeres Produkt|äußere Produkt]] zweier eindimensionaler Filter gleicher Ordnung: $$B^{k,k}=B^{k} \cdot (B^{k})^t.$$

Ein Binomialfilter der Größe $k$ führt annähernd dieselbe Glättung durch wie ein Gauß-Filter mit $\sigma=k^{\frac{1}{2}}/2$.
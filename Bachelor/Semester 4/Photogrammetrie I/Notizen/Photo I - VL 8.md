Datum: 28.05.
[[pho1-10-features-keypoints.pdf|Folien 1]]
[[pho1-11-features-descriptors.pdf|Folien 2]]

# Finden von Keypoints

## Eckendetektoren

Wir berechnen die [[ISS - VL 8#^c5c220|Harris-Matrix]] (ohne Gewichtungsfunktion) - hier genannt *structure matrix* $M$.

Allgemein werden diese Detektoren bei *Grauwertbildern* angewandt, zudem ist es ratsam, die Bilder vorher zu *glätten*.

### Harris Corner Detector

Kriterium: $$\begin{align*}
R &= \det(M) - k (\text{spur}(M))^{2}\\
&= \lambda_{1}\lambda_{2}-k(\lambda_{1}+\lambda_{2})^{2}.
\end{align*}$$
Bedeutung des Kriteriums:
$$\begin{align*}
|R| &\approx 0 \Rightarrow \lambda_{1} \approx \lambda_{2} \approx 0 \Rightarrow \text{Homogene Region}\\
R&<0 \Rightarrow \lambda_{1} \gg \lambda_{2} \lor \lambda_{2}\gg \lambda_{1} \Rightarrow \text{Kante}\\
R &\gg 0 \Rightarrow \lambda_{1} \approx \lambda_{2} \gg 0 \Rightarrow \text{Ecke}
\end{align*}$$

### Shi-Tomasi

Betrachte den kleinsten Eigenwert: $$\lambda_\text{min}(M) = \frac{\text{spur}(M)}{2} - \frac{1}{2}\sqrt{(\text{spur}(M))^{2}-4\det(M)}$$
Ist $\lambda_\text{min}(M)\geq T$ für einen Schwellwert $T$: Ecke

### Förstner

- Verwendet die [[Matrizen#Inverse|Inverse]] von $M$
- Berechnet Kriterium ($R$ oder $\lambda_\text{min}$) in einer Region um die Ecke und sucht nach dem Maximum
- $\Rightarrow$ *Subpixel-Genauigkeit* für Ecken

## Blob Detector

Der [[ISS - VL 3#Difference-of-Gaussian-Filter|DoG-Filter]] findet Blobs. 

> **Blob**
> Region, die hauptsächlich konstant aber verschieden von ihrer Umgebung ist

Der DoG ist ein [[ISS - VL 7#^c556d4|Bandpassfilter]]. Er zieht gewissermaßen verschieden geblurrte Versionen desselben Bilds voneinander ab, und übrig bleiben nur die Frequenzen, die zwischen den beiden Blurs liegen.

-> response bei Ecken, Kanten und Blobs. Kanten möchten wir nicht, also machen wir eine Non-Maxima-Suppression und/oder(?) einen Eigenwerttest.

Wir suchen nach lokalen Maxima der DoG-Response bei verschiedenen Blur-Leveln.

# Feature Descriptors

Hat man einen Keypoint gefunden (z.B. mit [[Photo I - VL 8#Blob Detector|Blob Detector]]), möchten wir ihn auf einem ähnlichen Bild wiederfinden. Dafür brauchen wir feature descriptors.

## SIFT

Hallo [[ISS - VL 8#SIFT|SIFT]]!

Ein SIFT-Feature speichert die Werte $\langle p,s,r,f \rangle$ pro Keypoint:
- $p$ - Pixel-Position des Keypoints
- $s$ - Größenordnung (Skala, in welcher DoG den Blob gefunden hat)
- $r$ - Orientierung (Maximum aus Histogramm lokaler Gradienten)
- $f$ - 128-dimensionaler Deskriptor aus lokalen Gradienten (unabhängig vom Viewpoint)


Der Deskriptor wird auf Grundlage der ersten drei (viewpoint-abhängigen) Werte berechnet:
- Position $\to$ wo wird der Deskriptor berechnet
- Größenordnung $\to$ welche Nachbarschaft wird einbezogen
- Orientierung $\to$ relativ zu welcher Richtung wird der Deskriptor berechnet

Der Deskriptor ist ein Histogramm:
- nimm die Pixelumgebung gegeben durch die ersten drei Werte
- Berechne Gradienten für jedes Pixel
- fasse Gradienten in Histogramme zusammen, pro kleinen Bildberech in der Pixelumgebung

### Was wenn Mismatch?

Gegeben: Feature $q$ mit unklarem Matchpartner
1. Finde die beiden Features $p_{1},p_{2}$ mit minimaler euklidischer Distanz
2. Teste, ob $d(q,p_1)<T$ für einen Threshold $T$
3. Nimm $p_1$ nur dann, wenn $\frac{d(q,p_1)}{d(q,p_{2})}< \frac{1}{2}$, also $p_1$ wesentlich näher dran als $p_2$

## Binäre Deskriptoren

Deskriptoren nur mit Ja/Nein-Werten - nicht so gut wie SIFT, aber schneller (und ohne Patentprobleme).

*Anwendung:* z.B. live-Tracking von Kamerabewegungen, wenn Differenz zwischen zwei aufeinanderfolgenden Bildern nicht allzu groß ist.

Ein Binärwert entsteht durch den Vergleich der Intensitätswerte (heller/dunkler) - im Grunde also das Vorzeichen des Gradienten (auch robust gegenüber Änderungen in Lichtverhältnissen).

### BRIEF

*B*inary *R*obust *I*ndependent *E*lementary *F*eatures

Es werden zufällig Punkte aus einer Region gezogen und die Helligkeitswerte miteinander verglichen. Aus den Vergleichswerten wird dann der Deskriptor zusammengesetzt (es müssen natürlich immer dieselben Vergleiche in derselben Reihenfolge sein).

### ORB

*O*riented FAST *R*otated *B*RIEF

Eine Erweiterung für BRIEF, die rotationsinvariant ist und die optimalen Sample-Paare lernt.

Für einen Bildberech werden die [[ISS - VL 11#Momente|Momente]] Massezentrum ($C = \left(\frac{m_{10}}{m_{00}},\frac{m_{01}}{m_{00}}\right)$) und Orientierung ($\theta = \arctan2(m_{01},m_{10}$) berechnet.
Dann wird alles um $C$ herum mit $\theta$ rotiert und es werden die Binärdeskriptoren berechnet.

Die 256 Bildpaare werden so gelernt, dass sie untereinander unkorrelliert sind und eine hohe Varianz von Feature zu Feature haben. Trainiert wird mit einer Datenbank von Beispielbildern.
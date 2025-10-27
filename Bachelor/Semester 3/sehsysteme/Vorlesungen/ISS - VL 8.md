Datum: 05.12.
[[ISS08_WS2324_InterestPoints_231205-231129.pdf|Folien]]

[[ISS_WS2324_Aufgabenblatt08.pdf]]
# Skaleninvariante Erkennung und Beschreibung von markanten Punkten
## Punktinduzierte Merkmale

### Markante Punkte und ihre Erkennung

(Wieder-)Erkennung von markanten Punkten ist nützlich bei:
- Stereoanalyse
- Tracking
- Bildanschluss (image alignment), z.B. bei Panoramabildern
- Objekterkennung

> **Ecke**
> Treffpunkt zweier Kanten/Linien


> **Markante Punkte**
> - Ecken
> - Isolierte Punkte mit lokalem Intensitätsmaximum /-minimum
> - Kreuzungspuntke
> - Endpunkte von Kanten
> - lokale Krümmungsmaxima bei gekrümmten Linien oder Kanten

"Eckendetektoren" detektieren in der Praxis meistens markante Punkte.

### Harris Corner Detector

Der Harris-Operator ist ein einfacher Algorithmus zum Finden markanter Punkte.

Wir haben einen Bildausschnitt (ein Fenster) gegeben und möchten wissen, ob sich darin ein markanter Punkt befindent.

Wir berechnen die folgende gewichtete Summe:
$$S(x,y)=\sum_{u,v}w(u,v)[I(u+x, v+y) - I(u,v)]^{2}.$$

Hierbei ist:
- $u,v \in [-m,m]$ die Pixelkoordinaten in einem Fenster der Seitenlänge $2m$
- $w(u,v)$ eine Gewichtung, z.B. eine Gauss-Kurve
- $x,y$ ein (kleiner) Offset, um welchen das Bild verschoben und die unverschobene Variante subtrahiert wird.

> Ist der Bildinhalt des Fensters homogen, ist $S(x,y)$ klein für alle (kleinen) $x$ und $y$.
> Gibt es eine Kante entlang der $x$-Richtung, ist $S(x,y)$ groß für $|y| >0$ (und andersherum für eine Kante in $y$-Richtung).
> Gibt es eine Ecke, ist $S(x,y)$ groß für alle (kleinen) $x$ und $y$.

Approximierung des Verschobenen Bildes über Gradienten (Taylor-Näherung):[^1]

$$I(u+x, v+y) \approx I(u,v) + \frac{\partial I}{\partial x}(u,v)\cdot x + \frac{\partial I}{\partial y}(u,v)\cdot y$$

$$\begin{align*}
\Rightarrow S(x,y) &\approx \sum_{u,v}w(u,v) [I_x(u,v)x+I_y(u,v)y]^{2} \\
&= \begin{pmatrix}x & y\end{pmatrix}A\begin{pmatrix}x \\
y\end{pmatrix}
\end{align*}$$


[^1]: mit $\frac{\partial I}{\partial x}=I_x$

mit der *Harris-Matrix:* $$A = \sum_{u,v}w(u,v)\begin{bmatrix}I_{x}^{2} & I_{x}I_{y} \\ I_{y}I_{x} & I_{y}^{2}\end{bmatrix}=\begin{bmatrix}\langle I_{x}^{2}\rangle & \langle I_{x}I_{y}\rangle \\ \langle I_{y}I_{x} \rangle & \langle I_{y}^{2}\rangle\end{bmatrix}$$
Die Harris-Matrix beschreibt die gewichteten partiellen Ableitungen, aufsummiert für alle Punkte des Fensters.
Achtung: $I_{x}^{2}$ ist die quadrierte *erste* Ableitung in $x$-Richtung, nicht die zweite Ableitung. Das ist keine Hesse-Matrix. ^c5c220

Wir approximieren die beiden partiellen Ableitungen wie gehabt mit Kantenfiltern: 
$$\begin{align*}
I_{x}&\approx I \ast \begin{pmatrix}-1 & 0 & 1\end{pmatrix}\\
I_{y}&\approx I \ast \begin{pmatrix}1\\0\\-1\end{pmatrix}
\end{align*}$$

#### Analyse der Harris-Matrix

Letztendlich interessiert uns nicht $S(x,y)$, sondern nur die Harris-Matrix. Aus dieser ist alles abzuleiten.

Bildausschnitt enthält achsenparallele Ecke: $$A = \begin{bmatrix}\langle I_{x}^{2}\rangle & \langle I_{x}I_{y}\rangle \\ \langle I_{y}I_{x} \rangle & \langle I_{y}^{2}\rangle\end{bmatrix}=\begin{bmatrix}\lambda_{1} & 0 \\ 0 & \lambda_{2}\end{bmatrix}.$$
$\langle I_{x}I_{y}\rangle$ ist $0$, weil an den Punkten im Fenster, an denen eine Kante in $x$-Richtung verläuft, der Gradient in $x$-Richtung 0 ist, und an der anderen (orthogonalen) Kante ist der Gradient in $y$-Richtung 0. Also ist das Produkt der Gradienten an jedem Punkt 0, und die Summe über alle Punkte entsprechend auch.

Bildausschnitt enthält rotierte Ecke:
$$A = Q \begin{bmatrix}\lambda_{1} & 0 \\ 0 & \lambda_{2}\end{bmatrix}Q^{T}$$
wobei $Q$ eine Rotationsmatrix ist (vgl. [[Numerik - VL 3#^e8f823|Spektralsatz]]).

**Das Wichtige in beiden Fällen:**
- Große Eigenwerte $\lambda_{1}$ und $\lambda_{2}$ $\to$ Ecke (bzw. markanter Punkt)
- Nur ein Eigenwert groß $\to$ Kante
- Kein Eigenwert groß $\to$ homogene Fläche

Problem an der Sache: Eigenwertberechnungen sind aufwändig.

Deshalb wird in der Praxis die Matrix $A$ mit einer *Antwortfunktion* $R(A)$ untersucht:
$$R(A)=\det(A)-\kappa \cdot\text{spur}(A)^2$$
(vgl. [[Matrizen#Spur|Spur]]) mit einem heuristisch gewählten Wert $\kappa$ mit $0.04 \leq \kappa \leq 0.15$.

$R$ hat die gewünschten Eigenschaften:
- $R>0 \to$ Ecke (bzw. markanter Punkt),
- $R < 0 \to$ Kante,
- $|R|<t$ für einen bestimmten Schwellwert $t\to$ homogene Fläche.

#### Zusammenfassung

Für ein Bild berechnet man nun für jedes Pixel die Harris-Matrix $A$ und die Antwortfunktion $R(A)$, bezogen auf das Fenster, in dessen Zentrum dieses Pixel liegt.

> *Eigenschaften des Harris-Operators*
> - Robustheit gegenüber Rotation
> - Keine Skaleninvarianz
> 	- gekrümmte Kante wird erst als Ecke erkannt, wenn weit genug rausgezoomt ist

## Korrespondenzen

- Wir brauchen nicht nur Interest Points, sondern auch Interest Regions
- Wir brauchen Skaleninvarianz

*Naiver Ansatz*
Man untersucht verschiedene Umgebungsgrößen
$\to$ ineffizient

Lösung:
Man guckt sich für verschiedene Umgebungsgrößen Maße wie Mittelwerte an (in jedem Bild unabhängig). Dann könnte man sowas zuordnen wie lokale Maxima

### Blob Detection

Wir möchten die Position und Größe von Blobs in unserem Bild erkennen, damit wir sie in anderen Bildern mit demselben Subjekt wiedererkennen können.

LoG als Blob-Detektor:
ist der Hut so groß wie der Blob, ist die Antwort des LoG maximal

Man vergleicht die Blob-Antwort nicht nur mit den 8 Nachbarn auf derselben Skalierung, sondern auch mit den jeweils 9 in der Skalierung darüber / darunter -> wenn lokeles Maximum in dieser 26-Nachbarschaft, dann Blob gefunden

### SIFT

> **SIFT: Scale Invariant Feature Transform**
> $\Rightarrow$ Erstellung von skalierungs- und rotationsinvarianten Region Descriptors

*Funktionsweise:*
1. Erkennung von Extrema im Skalenraum
2. Lokalisierung von Keypoints
3. Bestimmung einer dominanten Orientierung
4. Erzeugung von Keypoint-Deskriptoren

Man nimmt nur den Gauss-Filter und macht einen DoG. Irgendwann ist das Sigma so groß, dass man Downsampling Machen kann (Gauss-Pyramide)

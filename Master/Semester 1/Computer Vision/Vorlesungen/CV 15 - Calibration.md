[[15calibration_WS2425_slides.pdf]]
# Kapitel 15 - Kalibrierung

**Ziel:** Wiederherstellen eines 3D-Modells von Kameraaufnahmen
-> nicht möglich durch nur ein Bild -> mehrere Kameras, oder Kamera bewegen

## Kameramodelle
### Pinhole Model

- Das *Loch* unserer Kamera ist beim *Ursprung*
	- bezeichnet als *Optical Center* $O$
- Die *Bildebene* ist parallel zur xy-Ebene (x zeigt zur Seite, y nach oben, z nach vorne)
- Abstand Bildebene zu Optical Center: **Brennweite $f$**
- Punkt $P$ wird auf $P'$ auf Bildebene projiziert: $$(x,y,z) \mapsto \left(x \frac{f}{z},y \frac{f}{z},f\right)$$, wobei die z-Koordinate der Projektion unwichtig ist.

Projektion mit homogenen Koordinaten: $$\begin{pmatrix}1 &  &  & 0 \\
 & 1 &  & 0 \\
 &  & \frac{1}{f} & 0 \end{pmatrix} \begin{pmatrix}
x \\
y \\
z \\
1
\end{pmatrix} = \begin{pmatrix}
x \\
y \\
\frac{z}{f}
\end{pmatrix} \asymp \begin{pmatrix}
x \frac{f}{z} \\
y \frac{f}{z}
\end{pmatrix}$$
Äquivalente Projektionsmatrix: $\begin{pmatrix}f &  &  & 0 \\  & f &  & 0 \\  &  & 1 & 0 \end{pmatrix}$

In der Praxis:
2D-Punkt = [ Kamera-zu-Pixelkoord ] (3x3) x [ Perspektivische Projektion ] (3x4) x [ Welt-zu-Kamerakoord. ] (4 x 4) x 3D-Punkt (4x1)

=> Computergrafik.

### Orthografische Projektion
Auch: parallele Projektion
$$
\begin{pmatrix}
x \\
y \\
z \\
1
\end{pmatrix}
\mapsto \begin{pmatrix}
x \\
y \\
1
\end{pmatrix}
$$

### Limse

Wenn das Loch der Pinhole-Kamera zu klein wird, hat man Diffraktion und das Bild wird wieder unscharf. Außerdem kommt wenig Licht durch und man braucht lange Belichtungszeiten.

Deshalb: Linse

Die Brennweite ist jetzt der *Abstand zwischen Linse und Brennpunkt*.
Der Brennpunkt ist der Punkt, an dem sich alle parallelen Strahlen (orthogonal auf die Linse treffend) bündeln.

Ob etwas scharf ist, hängt vom Brennpunkt und von der Distanz des Objekts zur Kamera ab:
- Distanz vom Optischen Zentrum (Linse) zu 3D-Punkt: $D$
- Distanz von Bildebene zu Optischem Zentrum: $D'$
- Brennweite: $f$
- **Bildpunkt ist scharf, wenn:** $$\frac{1}{D} + \frac{1}{D'}=\frac{1}{f} \quad \text{(Thin Lens Equation)}.$$
![[Thin_Lens_Equation.png|230]]

Kleinere Blende => größeres Depth of Field (Schärfentiefe, Größe des Bereichs zw. den gestrichelten Linien):
![[Schärfentiefe.png|400]]

Außerdem: je größer die Brennweite $f$, desto weiter zoomen wir rein (kleineres FoV). Mit Halbwinkel vom FoV $\varphi$ und Chip-Breite $d$:
$$
\varphi=\tan^{-1}\left( \frac{d}{2f} \right)
$$ 
Annäherung von orthografischer Projektion: Kamera weit weg, mit großer Brennweite und kleinem FoV.

### Ein besseres Kameramodell

1. wir hätten gerne den Punkt $(0,0)$ unten links, anstatt in der Mitte des Bildes. Also müssen wir den sog. *principal point* $p$ draufaddieren ($p$ liegt im neuen Koordinatensystem im Bildmittelpunkt):
$$
\begin{pmatrix}
f \frac{x}{z} + p_{x} \\
f \frac{y}{z} + p_{y}
\end{pmatrix} \asymp \begin{pmatrix}
fx+zp_{x} \\
fy+zp_{y} \\
z
\end{pmatrix} = \begin{pmatrix}
f &  & p_{x} & 0 \\
 & f & p_{y} & 0 \\
 &  & 1 & 0
\end{pmatrix} \begin{pmatrix}
x \\
y \\
z \\
1
\end{pmatrix}
$$
2. Wir separieren die Projektionsmatrix in
	- die *Kalibierungsmatrix* $K$ (intrinsische Kameramatrix, enthält Kameraparameter) und
	- die *extrinsische Kameramatrix* $[I|0]$ (definiert das Koordinatensystem, also die Position der Kamera) - wird benötigt, wenn man mehrere Kameras hat

$$
\begin{pmatrix}
f &  & p_{x} & 0 \\
 & f & p_{y} & 0 \\
 &  & 1 & 0
\end{pmatrix} = \begin{pmatrix}
f &  & p_{x} \\
 & f & p_{y} \\
 &  & 1
\end{pmatrix} \begin{pmatrix}
1 &  & &  0 \\
 & 1 &  & 0 \\
 &  & 1 & 0
\end{pmatrix}
$$
3. $f$ und $p_{x}$ sind noch in Metern angegeben, wir hätten sie aber gerne in Pixeln. Also nehmen wir die *Pixel pro Meter* $m_{x}$ und $m_{y}$ und verrechnen sie mit der alten Kameramatrix: $$
K=\begin{pmatrix}
m_{x} &  &  \\
 & m_{y} &  \\
 &  & 1
\end{pmatrix} \begin{pmatrix}
f &  & p_{x} \\
 & f & p_{y} \\
 &  & 1
\end{pmatrix} = \begin{pmatrix}
\alpha_{x} &  & \beta_{x} \\
 & \alpha_{y} & \beta_{y} \\
 &  & 1
\end{pmatrix}
$$
4. Hat man nicht-quadratische Pixel, kommt ein *Skew-Faktor* $\gamma$ dazu: $$K=\begin{pmatrix}
\alpha_{x} & \gamma & \beta_{x} \\
0 & \alpha_{y} & \beta_{y} \\
0 & 0 & 1
\end{pmatrix}
$$

Koordinatentransformation haben wir schon aus [[Robotik - VL 4#Transformationsmatrix|Robotik]]:
- $X_{\text{cam}}$: Punkt im Kamera-Koordinatensystem
- $R$: Rotationsmatrix von Weltkoordinaten zu Kamerakoordinaten
- $X$: derselbe Punkt im Weltkoordinatensystem
- $C$: Position der Kamera

$$X_{\text{cam}}=R(X-C)$$
$$
\begin{pmatrix}
X_{cam} \\
1
\end{pmatrix} = \begin{pmatrix}
R & -RC \\
0 & 1
\end{pmatrix} = \begin{pmatrix}
X \\
1
\end{pmatrix}
$$

Projektionsmatrix insgesamt: $P=K[R|t]$, $t=-RC$.

### Verzerrungen
Zum intrinsischen Kameramodell kommen noch Verzerrungen durch die Linse (Extrembeispiel Fisheye-Linsen) dazu.
Der Abstand zum principal point sei $r$. 
Radial Distortion model (polynomiell):
$L(r)=1+\kappa_{1}r+\kappa_{2}r^2+\kappa_{3}r^3 + \dots$

$\begin{pmatrix}x_{d} \\ y_{d}\end{pmatrix}=L(r)\begin{pmatrix}x \\ y\end{pmatrix}.$


## Kalibierung
### Kalibierungs-Target

so ein Dings

![[Kalibierungstarget.png|350]]

Die Punkte können wir per [[ISS - VL 8#Blob Detection|Blob detector]] finden.

### Lineare Methode

Wir kennen die *Position aller Punkte* auf dem Target relativ zur Kamera, und wissen die zugehörigen Projektionen (wir können die Punkte auf dem Bild zuordnen).

![[Punktprojektion.png|350]]

Wir haben also $\lambda x_{i}=PX_{i}$, wir suchen $P \in \mathbb{R}^{3 \times 4}$ und wir kennen $\lambda$ nicht, weil wir die Brennweite nicht kennen.

Lambda brauchen wir aber auch nicht, wenn wir das [[Vektoren#Kreuzprodukt|Kreuzprodukt]] ausnutzen: 
$$
x_{i} \times PX_{i}=0
$$
Das schreiben wir um wie folgt: 
$$
\begin{align}
x_{i} \times \begin{pmatrix}
P_{1}^T \\
P_{2}^T \\
P_{3}^T
\end{pmatrix} X_{i} &= \begin{pmatrix}
x_{i} \\
y_{i} \\
1
\end{pmatrix} \times \begin{pmatrix}
P_{1}^T X_{i} \\
P_{2}^T X_{i} \\
P_{3}^T X_{i}
\end{pmatrix} \\
&= \begin{pmatrix}
0 & -1 & y_{i} \\
1 & 0 & -x_{i} \\
-y_{i} & x_{i} & 0
\end{pmatrix} \begin{pmatrix}
X_{i}^T P_{1}  \\
X_{i}^T P_{2}  \\
X_{i}^T P_{3} 
\end{pmatrix}  \\
&= \begin{pmatrix}
0 & -1 & y_{i} \\
1 & 0 & -x_{i} \\
-y_{i} & x_{i} & 0
\end{pmatrix} \begin{pmatrix}
X_{i}^T &  &  \\
 & X_{i}^T &  \\
 &  & X_{i}^T
\end{pmatrix}\begin{pmatrix}
P_{1} \\
P_{2} \\
P_{3}
\end{pmatrix}\\
&= \begin{pmatrix}
0 & -X_{i}^T & y_{i}X_{i}^T \\
X_{i}^T & 0 & -x_{i}X_{i}^T \\
-y_{i}X_{i}^T & x_{i}X_{i}^T & 0
\end{pmatrix} \begin{pmatrix}
P_{1} \\
P_{2} \\
P_{3}
\end{pmatrix} = 0
\end{align}
$$
mit $\begin{pmatrix}P_{1} \\ P_{2} \\ P_{3}\end{pmatrix} \in \mathbb{R}^{12}$ und der Matrix davor in $\mathbb{R}^{3 \times 12}$.

Das Ding hat (wegen dem Kreuzprodukt) *zwei* linear unabhängige Gleichungen, also schmeißen wir die untere Zeile raus.

Jetzt können wir in der linken Matrix alle $X_{i}$'s die wir haben, untereinander kleben:
$$
Ap=\begin{pmatrix}
0 & X_{1}^T & -y_{1}X_{1}^T \\
X_{1}^T & 0 & -x_{1}X_{1}^T \\
 & \dots \\
0 & X_{n}^T & -y_{n}X_{n}^T \\
X_{n}^T & 0 & -x_{n}X_{n}^T \\
\end{pmatrix} \begin{pmatrix}
P_{1} \\
P_{2} \\
P_{3}
\end{pmatrix} = 0
$$
$P$ hat 11 Freiheitsgrade (12 Parameter und Skalierung ist egal), und pro Punkt haben wir zwei unabhängige Größen (s.o.), also brauchen wir auf dem Target *mindestens 6 Punkte*.

Haben wir 6 oder mehr Punkte, können wir das mith. Pseudoinverse, kleinster Quadrate-Methode usw. lösen.

**Vorteile:**
- einfach zu formulieren und zu lösen

**Nachteile:**
- Intrinsische und extrinsische Parameter sind in $P$ zusammengefasst, wissen also nicht direkt die intrinsischen Parameter
- Keine Verzerrung modelliert
- Man kann nichts einschränken, wenn man z.B. die Brennweite schon kennt
- Man muss vorher genau wissen, wo das Target steht
	- wenn man mehrere Kameras hat, muss man alles so ausrichten, dass das Target für alle Kameras gut sichtbar ist, und möglichst in der Mitte, um Verzerrungen zu minimieren

### Intrinsische Kalibrierung mit Schachbrett

#### Bestimmung der Kameramatrix mit Homographien

Man nimmt sich ein Muster, druckt es aus und zeigt es auf einer flachen Oberfläche ein paar Mal in die Kamera.

Jetzt tun wir so, als ob wir das Muster liegenlassen und stattdessen die Kamera bewegen. Dann definieren wir die Ebene vom Muster als die XY-Ebene mit Z=0.

Das heißt, aus der extrinsischen Matrix $[R \mid t] = [r_{1} \; r_{2} \; r_{3} \; t] \in \mathbb{R}^{3 \times 4}$ können wir eine $\mathbb{R}^{3 \times 3}$ machen: 
$$
K \begin{bmatrix}
r_{1} & r_{2} & r_{3} & t
\end{bmatrix} \begin{bmatrix}
X \\
Y \\
0 \\
1
\end{bmatrix} = K \begin{bmatrix}
r_{1} & r_{2} & t
\end{bmatrix} \begin{bmatrix}
X \\
Y \\
1
\end{bmatrix}
$$
Diese 3x3-Projektion $K \begin{bmatrix} r_{1} & r_{2} & t\end{bmatrix}$ heißt **Homographie** (projiziert eine Ebene (Musterebene) in eine andere (Sensorebene)).

Jetzt bekommt man *pro aufgenommenes Bild eine Homographie* $H=\begin{bmatrix}h_{1} & h_{2} & h_{3}\end{bmatrix} = \lambda K \begin{bmatrix}r_{1} & r_{2} & t\end{bmatrix}.$

Pro Homography löst man jetzt ein lineares Gleichungssystem, mit dem man $B=K^{-T}K^{-1}$ bestimmt (man erhält 6 Parameter).
Mithilfe der Einträge von $B$ kann man nun alle 5 intrinsischen Parameter in $K$ bestimmen.
Pro Bild können wir jetzt noch die extrinsischen Parameter bestimmen.

Am Ende kann man noch lokale Optimierungen vornehmen, um das Ergebnis zu verbessern.

Wenn man seinen Skew-Parameter $\gamma$ bestimmen will, braucht man mindestens 3 Bilder.
#### Bestimmung des Verzerrungs-Modells

kann man lösen

Sobald man diese Verzerrung bestimmt hat, kann man sie auch wieder rückgängig machen.

#### Reprojection Error
Man macht die urspüngliche Kalibrierung anhand von Punkt-Paaren (z.B. mit Harris-Corners gefunden).
Die gefundenen Punkte kann man mit seinem Modell wieder zurückprojizieren und sich die Differenz anschauen zu dem ursprünglichen Punkt.

Mit 2 Bildern kann man einen recht geringen Reprojection Error kriegen, auch wenn die Kalibrierung falsch ist.

## Geometrieprobleme

### Triangulierung

*Problem* man hat mehrere kalibrierte Kameras (oder Bilder aus mehreren Perspektiven), und man möchte die 3D-Position von jeweils sichtbaren Punkten bestimmen.

Zwei Projektionen vom selben Punkt $X$: 
$$
\begin{align}
\lambda_{1}x_{1}&=P_{1}X \\
\lambda_{2}x_{2} &= P_{2}X
\end{align}
$$
Wieder umformen mit dem Kreuzprodukt:
$$
\begin{align}
x_{1} \times P_{1} X &= 0 \\
x_{2} \times P_{2} X &= 0 \\
&\Downarrow \\
[x_{1 \times}]P_{1}X &= 0 \\
[x_{2 \times}]P_{2}X &= 0 \\
&\Downarrow \\
A_{1}X&=0 \\
A_{2}X&=0 \\
&\Downarrow \\
\begin{bmatrix}
A_{1} \\
A_{2}
\end{bmatrix} X &= 0 \implies \text{lösen.}
\end{align}
$$

Bei $A_{1}$ und $A_{2}$ kann man wieder je eine Zeile rausstreichen.

Im zweiten Schritt kann man dann lokal das $X$ so verändern, dass $d^2(x_{1},P_{1}X)+d^2(x_{2},P_{2}X)$ minimiert wird.

### Epipolargeometrie

*Problem:* für einen gefundenen Punkt, wo ist derselbe Punkt auf dem Bilder einer anderen Kamera?

Ansatz: 
- wir können die 3D-Position vom gefundenen Punkt auf eine Linie einschränken
- diese Linie können wir auf dem anderen Bild einzeichnen
- nun suchen wir im anderen Bild entlang dieser Linie.

Die Epipolargeometrie ist wie folgt:
![[Epipolare Geometrie.png|500]]

- $O,O'$ sind die beiden optischen Zentren der Kameras
- $\overline{OO'}$ heißt *Baseline*
- Die Ebene durch $O,O',X$ heißt *Epipolarebene*
- Der Schnittpunkte $e,e'$ der Baseline und der Bildebenen heißen *Epipole*
	- Die Epipole müssen nicht unbedingt im Bild liegen
	- Wenn beide Kameras exakt in dieselbe Richtung schauen, liegen die Epipole im Unendlichen
- Die Schnittlinien $l,l'$ der Epipolarebene mit den Bildlinien heißen *Epipolarlinien*.

Wir suchen im zweiten Bild entlang der Linie $l'$. Die Epipolarebene können wir mit $O$, $O'$ und $x$ bestimmen.

### Matrizen

Für kalibrierte Kameras:
- Intrinsische Matrix $K$ und extrinsische Matrix (Kamerapositionen) bekannt
- die erste Kamera definiert das Weltkoordinatensystem -> erhält Projektionsmatrix $[I \mid 0]$
- **Essential Matrix:**
	- 3x3-Matrix mit der Eigenschaft $x^{T}Ex'=0$
	- Berechnet als $E=[t]_{\times}R$
		- $t$ ist der Verschiebungsvektor von $O$ zu $O'$
		- $[t]_{\times}$ ist die Kreuzproduktmatrix von $t$
		- $R$ ist die Rotationsmatrix von der ersten zur zweiten Kamera
	- Eigenschaften:
		- $l=Ex'$
		- $l'=E^{T}x$
		- $Ee' = E^{T}e=0$
		- $E$ hat Rang 2

Für unkalibrierte Kameras:
- Intrinsische Matrizen $K, K'$ unbekannt
- Verwandtschaft zur essential Matrix: $K^{-T}EK'^{-1}$
- Auch hier gilt: $x^{T}Fx'=0$
- Kann mit 8-Punkt-Algorithmus bestimmt werden

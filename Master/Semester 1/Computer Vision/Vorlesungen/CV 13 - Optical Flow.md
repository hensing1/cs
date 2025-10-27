[[13opticalflow_WS2425_slides.pdf]]
# Optical Flow

Ziel: **zwischen zwei Frames die Bewegung der Objekte bestimmen**

Anwendungen:
- 3D-Strukturen schätzen
- Objektsegmentierung auf Grundlage von Bewegungen

Was passiert?
- Wir bauen ein *Motion Field*
- Das Motion Field ist die *Projektion* der tatsächlichen Bewegung auf die Bildebene
- Resultat: Vektorfeld, das angibt, welche Pixel sich wie stark in welche Richtung bewegen

> **Def. Optical Flow**
> Die *anscheinende* Bewegung von Helligkeitsmustern in unserem Bild

Idealerweise wäre der optical flow dasselbe wie das motion field.
Problem: wenn sich z.B. die Lichtquelle bewegt, die Objekte in der Szene aber nicht, erhält man trotzdem Bewegung im Optical Flow, obwohl die Szene statisch ist.

## Schätzung des Optical Flow

Wir schreiben die *Helligkeit* eines Bildpunktes $(x,y)$ zum Zeitpunkt $t$ als $I(x,y,t)$. 

Wir gehen davon aus, dass sich für einen Bildpunkt die Position, aber *nicht* die Helligkeit verändert: $$I(x,y,t-1) = I(x+u(x,y), y+v(x,y), t)\quad \text{(Brightness Constancy Equation)}$$
wobei $u$ und $v$ das Motion Field in $x$ bzw. $y$-Richtung zwischen zwei Frames darstellen.

*Linearisierung mit Gradienten:* $$I(x,y,t-1) \approx I(x,y,t) + I_{x}\cdot u(x,y) + I_{y} \cdot v(x,y)$$
Man schaut sich also in beiden Frames *denselben* Punkt an, und berechnet $u$ und $v$ über den Intensitätsgradienten.
Umformuliert: $I_{x} \cdot u + I_{y} \cdot v + I_{t} \approx 0$

Wir haben also eine Gleichung, aber zwei Unbekannte $u,v$.
Intuitiv bedeutet das: wenn sich eine Kante bewegt, können wir nur die Bewegung *senkrecht* zur Kante bestimmen, aber nicht parallel zur Kante (siehe: barber pole illusion).

### Lucas-Kanade Flow

Damit wir die Gleichung lösen können, gehen wir davon aus, dass sich alle Pixel in einer Umgebung (z.B. 5x5) in dieselbe Richtung bewegen: $$\begin{bmatrix}
I_{x}(p_{1}) & I_{y}(p_{1}) \\
I_{x}(p_{2}) & I_{y}(p_{2}) \\
\vdots & \vdots \\
I_{x}(p_{25}) & I_{y}(p_{25}) \\
\end{bmatrix} \begin{bmatrix}
u \\
v
\end{bmatrix} = -\begin{bmatrix}
I_{t}(p_{1}) \\
I_{t}(p_{2}) \\
\vdots \\
I_{t}(p_{25})
\end{bmatrix} \quad Ad=b$$
Nur lösbar, wenn der [[Lineare Funktionen#^a400ac|Rang]] von $A$ 2 ist.
Genauer:
Wir müssen die Gleichung $A^{T}Ad=A^{T}b$ für das lineare Ausgleichsproblem lösen.
Es ist nun $A^{T}A=\begin{bmatrix}\sum I_{x}I_{x} & \sum I_{x}I_{y} \\ \sum I_{x}I_{y} & \sum I_{y}I_{y}\end{bmatrix}$ - dieselbe Matrixform, die wir auch beim [[ISS - VL 8#Harris Corner Detector|Harris Corner Detector]] haben.
Die findet hier auch eine sehr ähnliche Anwendung:
- beide Eigenwerte klein -> homogene Region (kaum Gradienten), keine Bestimmung von Optical Flow möglich
- nur ein Eigenwert groß -> Kante, auch keine Bestimmung möglich (s.o.)
- beide Eigenwerte groß -> Ecke, die können wir wiederfinden.

Probleme:
- bei schneller Bewegung funktioniert es nicht mehr (wenn Bewegung nicht mehr durch lineare Annäherung dargestellt werden kann)
- wenn sich ein Punkt nicht wie seine Nachbarn bewegt, ist die Annahme der Gleichmäßigkeit in der Umgebung verletzt
- Brightness Constancy muss erhalten bleiben

### Shi-Tomasi Feature Tracker

Wir möchten ein Objekt über mehrere Frames hinweg tracken

- Finde gute Features durch die Eigenwerte der Matrix $A^{T}A$ (auch genannt second-moment matrix)
- Von Bild zu Bild: tracke diese Features mit Lucas-Kanade (Translationsmodell zwischen Frames)
- Überprüfe Konsistenz, indem eine *affine* Transformation vom Objekt in späteren Frames zum ersten Frame erstellt wird

## Dichter Optical Flow

Wir möchten einen Bewegungsvektor für jeden Pixel - jeder Pixel soll eine Korrespondenz im nächsten Bild finden.
-> lokal nicht möglich, wir müssen das für alle Pixel gleichzeitig machen

### Horn-Schunck-Modell

Neben der Brightness Constancy Equation machen wir die Annahme, dass das Optical Flow Field möglichst gleichmäßig sein soll, dh. dass der Gradient vom Optical Flow möglichst klein sein soll: $$\lvert \nabla u \rvert ^{2} + \lvert \nabla v \rvert ^{2} \to \text{min}.$$
Als Energiefunktion für das flow field: $$E(u,v) = \int_{\Omega}(I_{x}u+I_{y}v+I_{t})^{2}+\alpha(\lvert \nabla u \rvert ^{2}+\lvert \nabla v \rvert ^{2})\,dxdy.$$
Der Parameter $\alpha$ bestimmt, wie stark die Gleichmäßigkeit des Felds berücksichtigt werden soll.
Das ganze ist konvex und lässt sich exakt lösen.

Das resultiert in den Gleichungen $$\begin{align}
(I_{x}u + I_{y}v + I_{t})I_{x} - \alpha \Delta u &= 0  \\
(I_{x}u + I_{y}v + I_{t})I_{y} - \alpha \Delta v &= 0
\end{align}$$
wobei $\Delta u$ der Laplace-Operator auf $u$ ist (approximiert mit dem L4-Laplace-Kernel auf $u$).


Slides: [[atcg2-01-Parametric-Curves.pdf]]
vgl. [[CG - VL 7|Computergrafik - Parametrische Kurven]]

## Basics
*Parametrische Kurve:* Mapping $p$ von einem Invervall $I=[a,b]$ in den $\mathbb{R}^{d}$
Die Menge der Punkte $p(I) \subset \mathbb{R}^{d}$ nennen wir *trace* von $p$

Zwei Kurven können dieselbe Trace haben, aber unterschiedlich parametrisiert sein.

Ist das Mapping n-mal [[Differenzialrechnung#^5a34fe|stetig differenzierbar]], heißt die parametrische Kurve auch n-mal stetig differenzierbar.
Die Ableitung $p'(t)$ ist die Tangente am Punkt $p(t)$.
Eine Kurve, deren Tangente nie $0$ ist, heißt *regulär*. Reguläre Kurven sind generell "glatt".

Interpretation als Partikel, das sich mit fortschreitendem $t$ entlang der Kurve bewegt:
- Bewegugsrichtung: $p'(t)$
- Geschwindigkeit: $\|p'(t)\|$

### Kurvenbasen
Die *Polynomkurven* bilden eine Basis, und die Monome $1,\,t,\,t^{2},\,\dots,t^{n}$ sind eine [[LA - VL 9#^567731|Basis]] dafür. Allerdings beeinflussen die Koeffizienten dieser Basis direkt nur die Ableitungen bei 0, weswegen diese Basis für unsere Zwecke ungeeignet ist.

#### Lagrange-Polynome
*Interpolation von $n$ Kontrollpunkten $P_{i}$ mit Polynomkurven*
Man bastelt sich eine Basis aus $n$ Polynomen $L_{i}$, die jeweils bei Zeitpunkt $t_{i}$ den Wert 1 und zu allen anderen Zeitpunkten $t_{j \neq i}$den Wert 0 haben:

$$L_{i}(t)=\prod_{j=0,\, j\neq i}^{n} \frac{t-t_{j}}{t_{i}-t_{j}}$$
Der Zähler von $L_{i}$ hat bei jedem Punkt $t_{j \neq i}$ den Wert 0. Der Nenner von $L_{i}$ ist konstant, er hat den Wert vom Nenner am Punkt $t_{i}$.
Die Linearkombination $p(t)=\sum_{i=0}^{n}P_{i}L_{i}(t)$ ist dann die interpolierende Kurve für die Punkte $P_{i}$.

Man erhält für $n$ Punkte immer die eindeutig bestimmten Polynome mit geringstem Grad (also $n-1$). Für 2 Punkte erhält man z.B. eine lineare Interpolation.

#### Hermite-Polynome
Die Hermite-Interpolation ist eine Verallgemeinerung der Lagrange-Interpolation, die nicht nur die Punkte, sondern auch die *Ableitungen* der Kurve an diesen Punkten interpoliert.
Das passiert mit Polynomkurven mit dem gerinstmöglichen Grad.

Für Interpolation zwischen $t_{0}=0$ und $t_{1}=1$ sind die Basisfunktionen kubisch:
$$\begin{align}
H_{0}^{3}(t)&=(1-t)^{2}(1+2t) \\
H_{1}^{3}(t) &= t(1-t)^{2} \\
H_{2}^{3}(t) &= -t^{2}(1-t) \\
H_{3}^{3}(t) &= (3-2t)t^{2}
\end{align}$$

Es ist $H_{0}^{3}+H_{3}^{3}=1$.

$H_{0}^{3}$ und $H_{3}^{3}$ interpolieren die Punkte $p_{0}$ und $p_{1}$, $H_{1}^{3}$ und $H_{2}^{3}$ die Ableitungen $m_{0}$ und $m_{1}$: $$p(t)=p_{0}H_{0}^{3}+m_{1}H_{1}^{3}(t)+m_{2}H_{2}^{3}(t)+p_{1}H_{3}^{3}(t)$$
#### Bernstein-Basis und Bézierkurven
Mit Bernstein-Polynomen des Grades $n$ erhält man im Intervall $[0,1]$ eine *Zerlegung der 1* mit $n+1$ Polynomen.
Mit diesen $n+1$ Polynomen und $n+1$ *Kontrollpunkten* kann man die Bézierkurven definieren:
- Interpoliert den ersten ($P_{0}$) und letzten ($P_{n}$) Kontrollpunkt ($B_{0}^{n}(0)=1$, $B_{n}^{n}(1)=1$)
- $\overline{P_{0}P_{1}}$ definiert die Tangente am Punkt $P_{0}$
- $\overline{P_{n-1}P_{n}}$ definiert die Tangente am Punkt $P_{n}$
- Kurve verläuft in der [[Disco - VL 1#^719510|konvexen Hülle]] der Kontrollpunkte

Vgl. [[CG - VL 7#Bernsteinpolynome und Bézierkurven|Computergrafik]]

##### Ableitung einer Bézierkurve
Die $k$-te Ableitung einer Bézierkurve $n$-nten Grades wiederum eine Bézierkurve mit Grad $n-k$ :
$$p^{(k)}(t) = \frac{n!}{(n-k)!} \sum_{i=0}^{n-k}\Delta^{k}b_{i}B_{i}^{n-k}(t)$$
mit den Bernsteinpolynom-Koeffizienten $\Delta^{k}b_{i}$ rekursiv definiert: $$\begin{align}
\Delta^{0}b_{i}&=b_{i} \\
\Delta^{k}b_{i}&=\Delta^{k-1}b_{i+1}-\Delta^{k-1}b_{i}
\end{align}$$

Anschaulich spannen die Vektoren von einem Kontrollpunkt zum nächsten das neue Kontrollpolygon der Ableitung auf:
![[Bezierableitung.png|150]]

### Kurvenlänge
Die Länge einer Kurve ist definiert als das Integral über die Länge des Tangentenvektors: $$s: [a,b] \to [0, s(b)], \,u \mapsto s(u)=\int_{a}^{u}\|p'(t)\|\,dt$$
## Splines

vgl. [[CG VL 8 - Splines]]

Spline: parametrisierte Kurve für eine Menge Zeitpunkten *(knots)* $t_{0} \leq t_{1} \leq \dots \leq t_{n}$ , sodass jeder Abschnitt $q_{j}: [t_{j-1}, t_{j}] \to \mathbb{R}^{d}$ eine Polynomkurve ist.

Wir nennen den Vektor $T= \begin{pmatrix}t_{0} \\ t_{1} \\ \vdots  \\ t_{n}\end{pmatrix}$ den *knot vector*.

Die Polynomkurven treffen sich an den Knoten, haben aber dort nicht notwendigerweise dieselbe(n) Ableitung(en):


**$C^{n}$-Continuity:** die ersten $n$ Ableitungen stimmen überein, dh. $$q_{1}^{(k)}(b_{1})=q_{2}^{(k)}(a_{2}) \; \forall k=0,\dots,n$$
für zwei Kurven $q_{1}: [a_{1},b_{1}] \to \mathbb{R}^{n}$, $q_{2}: [a_{2},b_{2}] \to \mathbb{R}^{3}$.

**$G^{n}$-Continuity:** es existiert eine Kurve mit derselben Trace, die $C^{n}$-kontinuierlich ist (tatsächlich benötigt muss man bloß die erste Kurve umparametrisieren).

### Catmull-Rom-Spline
Die Catmull-Rom-Spline erhalten wir, indem wir kubische Hermite-Polynome aneinanderhängen. Die Ableitung an einem Punkt ist $m_{i}=\frac{1}{2}\,\overrightarrow{P_{i-1} P_{i+1}}$ .

Als Matrix ("FMILL method"):
![[Catmull-Rom.png]]

Die Catmull-Rom spline interpoliert die Punkte und ist $C^{1}$-kontinuierlich.

### B-Splines
Eine B-Spline kann man mit Basisfunktionen für die Kontrollpunkte definieren.
Für Grad $n$ sind die Basisfunktionen: $$\begin{align}
N_{i}^{0}&:= \begin{cases}
1 & \text{falls } t \in [t_{i}, t_{i+1}) \\
0 & \text{sonst}
\end{cases} \\
N_{i}^{r} &:= \frac{t-t_{i}}{t_{i+r}-t_{i}}N_{i}^{r-1}(t)+ \frac{t_{i+1+r}-t}{t_{i+1+r}-t_{i+1}}N_{i+1}^{r-1}(t) \,\text{für }1 \leq r \leq n.
\end{align}$$
Und der Spline: $$p(t)=\sum_{i=0}^{m}P_{i}N_{i}^{n}(t)$$


- wir brauchen mindestens $m\geq n+1$ Kontrollpunkte
- verwirrenderweise haben die Knots keine 1-zu-1-Korrespondenz zu den Kontrollpunkten. Stattdessen wird die *Basisfunktion* eines jeden Kontrollpunkts bestimmt von $n+2$ aufeinanderfolgenden Knoten
	- konkret ist $N_{i}^{n}(t)$ bestimmt von $t_{i},\dots,t_{i+n+1}$
	- wir brauchen also $m+n+2$ Knoten
- Sind die Knoten äquidistant, erhält man die Basisfunktionen für die [[CG VL 8 - Splines#B-Spline|"gewöhnliche" B-Spline]], die vor den Endpunkten aufhört (je höher der Grad, desto weiter vor den Endpunkten)
- Setzt man die ersten $n+1$ und die letzten $n+1$ Knoten auf denselben Wert ($t_{0}=\dots=t_{n}$ und $t_{m+1}=\dots=t_{m+n+1}$), dann werden die Endpunkte genau getroffen
- Die Kontrollpunkte heißen hier **de Boor-Punkte**
- Es ist $N_{i}^{n}(t)=0$ für $t \not\in [t_{i},t_{i+n+1}]$, also hat der zugehörige de Boor-Punkt nur *lokalen Einfluss* auf den Spline
- außerdem ist jedes $N_{i}^{n}(t)\geq 0$ und $\sum_{i}N_{i}^{n}(t)=1$ für alle $t$, dh. der Spline bleibt in der *konvexen Hülle* der de Boor-Punkte (also im Kontrollpolygon)
	- keine "overshoots"

> An einem Knotenpunkt $t_{j}$ ist der Spline mindestens $C^{n-1}$-kontinuierlich.

Sind $\mu$ aufeinanderfolgende Knotenpunkte gleich, ist der Spline dort mindestens $C^{n-\mu}$-kontinuierlich.

- Für $n=0$ sind die Basisfunktionen Box functions, also Springt die Kurve von Punkt zu Punkt (ist keine Kurve)
- Für $n=1$ erhält man die lineare Interpolation
	- Basisfunktionen sind Sawtooth, aka. Boxfunktion gefaltet mit sich selbst
- Für weitere $n$ faltet man die bisherige Basisfunktion wieder mit der Boxfunktion

## Arc Length Parametrization und Geometrie

Wir hätten gerne, dass $\|p'(t)\|=1$ für die gesamte Kurve gilt.
Das ist im Allgemeinen für Bézierkurven, B-Splines, etc. nicht der Fall.

Erzeugung: wir nehmen die *[[ATCG2 - 1 - Parametric Curves#Kurvenlänge|Kurvenlängenfunktion]]* $s(t)$. Da diese monoton steigend ist, existiert die Inverse $t(s)$ ("an welchem Zeitpunkt hat die Kurve die Länge $s$ ?").
Die Kurve $q(s)=p(t(s))$ ist nun nach Kurvenlänge parametrisiert.

Für nach Kurvenlänge parametrisierte Kurven können wir jetzt geometrische Eigenschaften anhand der Ableitungsvektoren bestimmen:

> [!abstract] Definition
> - Tangentenvektor (normalisierte Ableitung): $T(s) := p'(s)$
> - Krümmungsvektor: Ableitung des Tangentenvektors, $K(s) := T'(s) = p''(s)$
> 	- rechtwinklig zur Tangente
> - Normale: normalisierter Krümmungsvektor, $N(s) := \frac{T'(s)}{\|T'(s)\|}$
> - Krümmung: $\kappa(s) := \|T'(s)\|=\|p''(s)\|$
> - Radius der Krümmung: $r(s) := \frac{1}{\kappa(s)}$
> - Binormale: $B(s) := T(s) \times N(s)$
> 	- $\{ T,N,B \}$ erzeugen Koordinatensystem, an der Krümmung der Kurve ausgerichtet, am Punkt $p(s)$ (gennannt **Frenet-Frame**)

*Osculating Plane:* aufgespannt von Tangente und Normale
*Osculating Circle:* Kreis mit Radius $r(s)$ mit Zentrum $p(s)+T'(s)$ (schmiegt sich an Kurve an)

Änderungsrate der Binormalen: $B'(s) = T(s) \times N'(s)= \tau(s)N(s)$
$\tau(s)$ ist *Torsion*

Krümmung bei nicht nach Kurvenlänge parametrisierten Kurven: $$\kappa(t) := \frac{\|p''(t) \times p'(t)\|}{\|p'(t)\|^{3}}$$
Hierbei ist $K(s)=p''(s)$ eben auch nicht unbedingt rechtwinklig zu $T(s)=p'(s)$.
Und Torsion: $$\tau(t) := \frac{p'(t) \cdot (p''(t) \times p'''(t))}{\|p'(t) \times p''(t)\|^{2}} = \frac{\det \begin{pmatrix}p'(t) & p''(t) & p'''(t)\end{pmatrix}}{\|p'(t) \times p''(t)\|^{2}}$$
### Krümmungsenergie

Die Krümmungsenergie ist proportional zur Krümmung entlang der Kurve: $$E=c \int_{0}^{l}\kappa(t)\,dt \approx c \int_{0}^{l}p''(t)\,dt$$
mit $c$ konstant und $l$ Länge der Kurve.

Ein [[ATCG2 - 1 - Parametric Curves#Hermite-Polynome|Hermite-Polynom]] *minimiert* die Krümmungsenergie für die Rahmenbedingungen (zwei Punkte mit je einer Ableitung).

Die schnellste Weg, um die Länge (und die Krümmungsenergie) einer Kurve zu verringern, ist jeden Punkt proportional zur Krümmung entlang der normale zu verschieben: $q(t)=\kappa(t)N(t)$ (mit $q(t)$ Verschiebungsvektor am Punkt $p(t)$).

## Subdivision


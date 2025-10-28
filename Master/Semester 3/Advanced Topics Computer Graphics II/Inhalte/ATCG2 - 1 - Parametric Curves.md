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



### Arc Length Parametrization

Länge $p'(t)$ ist 1 für gesamte Kurve
Generierung mit *Inverse* der Kurvenlängenfunktion

Krümmungsvektor: Ableitung des Tangentenvektors
Falls arc length parameterized (Länge Tangente bleibt gleich): Krümmungsvektor ist rechtwinklig zu Tangentenvektor

Krümmung: Länge $p''(s)$

Leibnitz rule?

Osculating Plane: aufgespannt von Tangente und Normale
Binormal $B(s)$: Normal zu osculating plane

$B'(s) = \tau(s)N(s)$, $\tau(s)$ ist *Torsion*

Frenet frame
Datum: 10.05.
[Ein Youtube-Video](https://www.youtube.com/watch?v=jvPPXbo87ds)
[[cgintro-07-Parametrische Kurven.pdf|Ein Folien]] (ab S. )

# Splines

> [!abstract] Definition *Spline*
> Ein Spline $q$ verbindet eine Reihe von *Stützstellen* bei $t_{0}\leq t_{1} \leq \ldots \leq t_{n}$ mit stetig differenzierbaren Kurven: $$q: [t_{0},t_{n}]\to \mathbb{R}^{d}\quad q|_{[t_{i},t_{i+1}]}\in C^{\infty}\forall i.$$
> Ein Segment $q|_{[t_{i},t_{i+1}]}$ heißt *Spline-Segment*.

Splines unterscheiden sich vor allem in ihrer Stetigkeit an den Stützstellen.

## Spligenschaften

> **Parametrische Stetigkeit ($C^n$-Stetigkeit)** 
> Falls die ersten $n$ Ableitungen zweier Kurven $$q:[a_{1},b_{2}]\to \mathbb{R}^{d},r: [a_{2},b_{2}]\to \mathbb{R}^{d}$$ an einem gemeinsamen Punkt $b_1,a_2$ in Länge und Richtung übereinstimmen, ist dieser Übergang *$C^n$-stetig*: $$q^{(k)}(b_{1})=r^{(k)}(a_{2})\quad \forall k \in \set{0,\ldots,n}.$$

Für [[CG - VL 7#^6a2472|kubische Bézierkurven]]:
![[Bezier-Kontinuität.png|500]]
Kubische Bézierkurven kann man nicht $C^2$-stetig machen, ohen dabei lokale Kontrolle über die Ableitungen zu verlieren.
Für $C^3$-Stetigkeit gibt man auch die lokale Kontrolle über die Position der Stützstellen auf. Der gesamte Spline wird zu einem einzigen kubischen Bézier, bei dem der Parameter über den Wert 1 hinausgeht. Er wird damit auch $C^\infty$-stetig.

> **Geometrische Stetigkeit ($G^n$-Stetigkeit)**
>  Zwei $n$-mal stetig differenzierbare Kurven $$q:[a_{1},b_{1}]\to \mathbb{R}^{d},\,r:[a_{2},b_{2}]\to \mathbb{R}^{d}$$schließen an der Stelle $b_1,a_2$ mit $G^n$-Stetigkeit aneinander, falls es eine reguläre Umparametrisierung $r_{2}=r(\alpha(t))$ gibt, sodass $q,r_2$ mit $C^n$-Stetigkeit aneinanderschließen.

Man sieht einer Kurve also nicht ihre $C^n$-Stetigkeit an, ihre $G^n$-Stetigkeit aber schon.

![[Geometrische_Stetigkeit.png|500]]

- $G_1$-Stetigkeit: *Tangentenvektoren* zeigen in dieselbe Richtung ($\frac{q'(b_{1})}{\|q'(b_{1})\|}=\frac{r'(b_{1})}{\|r'(b_{1})\|}$)
- $G_2$-Stetigkeit: Die [[CG - VL 7#^9883bc|Krümmung]] ist stetig
- $G_3$-Stetigkeit: Der Änderungsgrad der Krümmung ist stetig

Der lustige Fächer an den Kurven oben heißt *Krümmungskamm* (curvature comb).

Geometrische Stetigkeit ist für Oberflächen wichtig. $G_{1}$-Stetigkeit vs. $G_{2}$-Stetigkeit:
![[G1-Stetigkeit.png|300]] ![[G2-Stetigkeit.png|300]]

Genau wie mit $C^n$-Stetigkeit, impliziert $G^n$-Stetigkeit auch $G^{n-1}$-Stetigkeit. Solange die Kurven [[CG - VL 7#^4e90d5|regulär]] sind, impliziert $C^{n}$- auch $G^n$-Stetigkeit.
![[Kurvenstetigkeit.png|300]]

## Mehr Splines

> Splines sind Kurvengeneratoren, keine Kurven. Alle untenstehenden Splines können dieselben Kurven erzeugen, die Kontrollpunkte sind aber jeweils anders.

### Hermite-Spline

> **Hermite-Spline**
> Ein Hermine-Spline erfüllt die vier Randbedingungen für Position und erste Ableitung an den Stützstellen: $$\begin{align*}
P(0)=P_{0},\,P(1)=P_{1}\\
P'(0)=v_{0},\,P'(1)=v_{1}
\end{align*}$$

Er ist damit $C^1$, aber nicht $C^2$-stetig.
Das ganze ergibt ein Polynom dritten Grades mit folgender Matrixschreibweise: ![[Hermite-Spline-Matrixform.png|300]]

Der linke Zeilenvektor mal die charakteristische Matrix in der Mitte ergeben ergibt die Basisfunktionen für die Hermite-Spline (wie die [[CG - VL 7#^979732|Bernsteinpolynome]] für Bézierkurven): 
![[Hermite-Basispolynome.png]]

Umformung von Hermite in Bézier: 
$$\begin{align*}
B_0&=P_0\\
B_1&=P_0+v_0/3\\
B_2&=P_1-v_1/3\\
B_3&=P_1
\end{align*}$$

### Kardinaler Spline

Der Kardinale Spline ist ein Hermite-Spline, bei dem der Ableitungsvektor an einem Punkt $P_n$ gegeben ist durch $s \cdot \overrightarrow{P_{n-1} P_{n+1}}$.
Damit der Spline auch $P_0$ und $P_n$ interpoliert, können $P_1$ und $P_{n-1}$ jeweils an $P_0$ bzw. $P_n$ gespiegelt werden.

Für $\lim\limits_{\alpha \to 0}$ wird der Spline zu e iner linearen Interpolation.

![[Cardinal Spline.png]]

### Catmull-Rom Spline

Der Catmull-Rom Spline ist ein kardinaler Spline mit $s=0.5$.

- Interpolation aller Punkte
- $C^1$- und $G^1$-stetig

![[Catmull-Rom Spline.png|500]]

### B-Spline

Der B-Spline ist ein kubischer Spline mit $C^2$-Stetigkeit. Er interpoliert aber nicht.

![[B-Spline.png]]

## Zusammenfassung

![[Splines.png]]
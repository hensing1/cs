Datum: 06.05.
[[cgintro-07-Parametrische Kurven.pdf|Folien]] bis S. 35
# Parametrische Kurven

Kurven sind interessant für Objektmodellierung und Objektbewegungen. Wir stellen unsere Kurven *explizit* als Formeln dar.

Beispiel für eine Gerade zwischen Punkten $P_{1}$ und $P_2$:
$$p(t) = t \cdot P_{2} + (1-t) \cdot P_1$$

> [!abstract] Definition *Parametrisierung einer Kurve*
> Eine Parametrisierung einer Kurve ist eine Abbildung $p: [a,b]\to\mathbb{R}^{n}$ auf die Punkte der Kurve im $\mathbb{R}^{n}$.

Eine Parametrisierung kann (stetig) differenzierbar sein. Die erste Ableitung einer Parametrisierung an einer Stelle $x \in [a,b]$ ist der Tangentialvektor an der Stelle $p(x)$.
Die Normalisierte Ableitung $p'/\|p\|$ heißt Tangente.

> [!abstract] Definition *Regularität von Kurven*
> Eine parametrisierte Kurve heißt regulär, falls ihre Ableitung immer ungleich Null ist.

^4e90d5

Ist die Ableitung gleich Null, kann es sein, dass die Kurve einen Knick hat.

> [!abstract] Definition *Bogenlängenfunktion einer Kurve*
> Für eine Kurve $p: [a,b] \to \mathbb{R}$ heißt die Funktion $\hat s: [a,b]  \to [0, \infty)$ mit $$\hat s(t) := \int_{a}^{t}\|p'(\tau)\|_{2}\,d\tau$$ Bogenlängenfunktion von $p$.

**Parametrisierung nach Bogenlänge:**
Umparametrisierung von $p(t)$ auf $p_{s}(s):= p(\hat s^{-1}(s))$ $\Rightarrow$ *jeder Schritt entlang der Kurve hat Länge 1*.

Das bedeutet, dass die Ableitung normiert ist. Der Krümmungsvektor ist gleich der zweiten Ableitung.
$$\begin{align*}
T(s) &:= p'(s) & \text{Tangentialvektor}\\
K(s) &:= p''(s) & \text{Krümmungsvektor}\\
\kappa(s) &:= \|p''(s)\| & \text{Krümmung}
\end{align*}$$

^9883bc

Geometrisch:
![[Kurve.png]]

## Polynomkurven

### Lagrange-Polynom
Polynom (maximal) $k$-ten Grades, welches genau durch $n=k+1$ vorgegebene Punkte verläuft. Es *interpoliert* also zwischen gegebenen Punkten.

Die Punkte $t_0,t_1,\ldots,t_n$, an denen das Polynom durch die Punkte $P_0,\ldots,P_n$ verlaufen soll, heißen *Stützstellen*.

Für jeden Punkt nimmt man sich ein Polynom in der Form: $$L_{i}^{n}(t)=\prod_{\stackrel{j=0}{j\neq i}}^{n}\frac{t-t_{j}}{t_{i}-t_{j}}$$
An allen Punkten $t_k$ ist $L_{i}^{n}(t_{k})=\begin{cases}1 & \text{falls }i=k \\0 & \text{sonst.}\end{cases}$
Diese Lagrange-Polynome bilden eine [[Vektorräume#Basis|Basis]] für den Polynomraum.

Die Interpolation wird also erreicht durch: $$p(t) = \sum_{i=0}^{n}P_{i}L_{i}^{n}(t).$$
Problem: bei höheren Polynomgraden wird die Kurve äußerst wellig.

### Hermite-Polynom
Mit einem Hermite-Polynom dritten Grades kann man zwei Punkte $p_0,p_1$ interpolieren, welche an diesen Punkten eine vorgegebene *Ableitung* $m_0,m_1$ haben sollen.

### Bernsteinpolynome und Bézierkurven

> [!abstract] Definition *Bernsteinpolynome*
> Die Polynome $$B_{i}^{n}(t)=\binom{n}{i}t^{i}(1-t)^{n-i}\quad t_{i}\in[0,1]$$heißen Bernsteinpolynome über dem Intervall $[0,1]$ vom Grad $n$.

^979732

Bernsteinpolynome bilden eine [[Vektorräume#Basis|Basis]] des $(n+1)$-dimensionalen Polynomraums.

- Die Summe der Bernsteinpolynome von $0$ bis $n$ ist 1 (*Zerlegung der 1*)
- Bernsteinpolynome sind von 0 bis 1 nie negativ
- Symmetrie: $B_{i}^{n}(t)=B_{n-i}^{n}(1-t)$
- $B_{0}^{n}(0)=1$, $B_{n}^{n}(1)=1$

![[Bernsteinpolynome.png]]

> [!abstract] Definition *Bézierkurve*
> Die Kurve $$p(t)=\sum_{i=0}^{n}b_{i}B_{i}^{n}(t)\quad t\in [0,1]\;b_{i}\in \mathbb{R}^{d}$$heißt Bézierkurve über dem Intervall $[0,1]$ vom Grad $n$.
> Die Punkte $b_i$ heißen *Bézier-* oder *Kontrollpunkte* und bilden das *Bezier-* oder *Kontrollpolygon*, in dessen konvexen Hülle die Bézierkurve verläuft.

^6a2472

Kubische Bézierkurve:
![[Bezierkurve.png|300]]

Die Strecke $\overline{b_{0}\,b_{1}}$ ist tangential zur Bézierkurve am Punkt $b_0$, die Strecke $\overline{b_{2}\,b_{3}}$ ist tangential zur Kurve am Punkt $b_3$.

#### Algorithmus von de Casteljau

*Algorithmus, um eine Bézierkurve zu zeichnen.*

Um $p(t)$ zu bestimmen:
- Bestimme neue Punkte $b^1$ zwischen den Kontrollpunkten $b_0$:
	- $b_{0}^{1}=t \cdot b_{0}^{0} + (1-t)b_{1}^{0}$
	- ...
- Wiederhole dies zwischen den neuen Kontrollpunkten

In jeder Iteration erhält man einen neuen Kontrollpunkt weniger. Der letzte bestimmte Punkt ist $p(t)$.
![[De_Casteljau.png]]

### Rationale Kurven

Mit rationalen Kurven kann man z.B. Kreise oder Ellipsen darstellen. Das geht mit Polynomen nicht.


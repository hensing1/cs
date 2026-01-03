zu Deutsch: Differentialformen

## Grundlagen

Bei Differentialformen geht es um Darstellungen von Oberflächen und Volumen *unabhängig von einer Koordinatendarstellug*.

> [!abstract] Definition *Mannigfaltigkeit*
> Eine $n$-dimensionale Mannigfaltigkeit ist ein geometrisches Objekt, welches *lokal* so aussieht wie der euklidische Raum $\mathbb{R}^{n}$. [^1]
> Die **Mannigfaltigkeit $\mathbb{R}^{n}$** (Manifold $\mathbb{R}^{n}$) ist die Menge aller *Punkte* $p \in \mathbb{R}^{3}$.

Ein Punkt in der Mannigfaltigkeit existiert *unabhängig* von seinen Koordinaten. Wenn wir möchten, können wir ihm welche zuweisen:

> **Koordinatenfunktion**
> $$\begin{align}
x &: \text{(Manifold)} \mathbb{R}^{n} \to \mathbb{R} \\
p &\mapsto x(p)
\end{align}$$
> -> gibt die x-Koordinate von $p$ zurück.

Wir könnten aber auch $r(p)$ und $\theta(p)$ für Kugelkoordinaten definieren.

Jeder Punkt $p$ in der Mannigfaltigkeit $\mathbb{R}^{n}$ hat einen *Tangentialraum*.
- Dieser Tangentialraum ist der [[Vektorräume|Vektorraum]] $\mathbb{R}^{n}$.
- Der Ursprung dieses Vektorraums ist $p$.
- Wir bezeichnen ihn mit $T_{p}(\mathbb{R}^{n})$ oder $T_{p}\,\mathbb{R}^{n}$.

![[Tangent Space.png]]

Einen Vektor im Tangentialraum von $p$ bezeichnen wir mit $v_{p}$.

Beispiel: $$\begin{bmatrix}
1 \\
1
\end{bmatrix}_{(-2, -3)} \in T_{(-2, -3)}\, \mathbb{R}^{2}$$heißt: der Vektor $\begin{bmatrix}1 \\ 1\end{bmatrix}$ mit Ursprung $(-2, -3)$ im Tangentialraum des Punktes $(-2, -3)$ im Manifold $\mathbb{R}^{2}$.

- Man kann eine $n$-dimensionale Mannigfaltigkeit zusammen mit seinen $n$-dimensionalen Tangentialräumen zu einer $2n$-dimensionalen Mannigfaltigkeit *bündeln*.

> [!abstract] Definition *Vektorfeld*
> Sei $M$ eine Mannigfaltigkeit. Hat man pro Punkt $p \in M$ *einen* Vektor $v_{p}$ aus dem jeweiligen Tangentialraum $T_{p}\,M$.
> Gibt es für all diese Vektoren eine diff.bare Kurve durch $M$, zu der sie tangential sind, heißt das Vektorfeld *glatt* (smooth).

### Richtungsableitungen

Sei $f: \mathbb{R}^{n} \to \mathbb{R}$ eine Funktion auf der Mannigfaltigkeit $\mathbb{R}^{n}$.
Seien $p=\begin{bmatrix}p^{1} \\ p^{2}\end{bmatrix} \in \text{(Manifold)}\,\mathbb{R}^{2}$ und $v_{p}=\begin{bmatrix}v^{1} \\ v^{2}\end{bmatrix} \in T_{p}\,\mathbb{R}^{2}$.

Die Richtungsableitung von $f$ in Richtung $v_{p}$ definiert sich, anders als in der Inifinitesimalrechnung, über den Tangentialraum:
$$\begin{align}
v_{p}[f]&:= \left.\frac{d}{dt}(f(p + tv_{p}))\right|_{t=0} \\
&= \frac{d}{dt}\left.f\left(\begin{bmatrix}
p^{1}+tv^{1} \\
p^{2}+tv^{2}
\end{bmatrix}\right)\right|_{t=0} \\
&= \sum_{i=1}^{n}v^{i} \,\left.\frac{ \partial f }{ \partial x^{i} } \right|_{p} .
\end{align}$$

*Ist $\|v_{p}\|=1$, erhält man denselben Wert wie in der Analysis (die Steigung der Tangente in Richtung $v_{p}$).*

Der Vektor $v_{p}$ wird zu einem *Operator* für die Funktion $f$.

> Die Euklidischen Basisvektoren $e_{i}$ sind die partiellen Ableitungsoperatoren $\frac{ \partial  }{ \partial x_{i} }$: $$e_{i}[f]=\frac{ \partial  }{ \partial x_{i} } (f).$$

Also:
$$\begin{align}
v&=\begin{bmatrix}
2 \\
-3 \\
1
\end{bmatrix} \\
&=2e_{1}-3e_{2}+e_{3} \\
&=2\frac{ \partial  }{ \partial x_{1} } -3 \frac{ \partial  }{ \partial x_{2} } +\frac{ \partial  }{ \partial x_{3} }.
\end{align}$$
Notation, wenn wir noch einen Basispunkt $p$ nehmen: $$v_{p}=v_{1}\left. \frac{ \partial }{ \partial x_{1} } \right|_{p} + v_{2}\left. \frac{ \partial }{ \partial x_{2} } \right|_{p}+v_{3}\left. \frac{ \partial }{ \partial x_{3} } \right|_{p}.$$

### Rechenregeln

Distributivität:
$$(a v_{p}+b w_{p})[f]=av_{p}[f] + bw_{p}[f]$$

Linearität:
$$v_{p}[af+bg]=av_{p}[f] + bv_{p}[g]$$

Leibnitz-Regel 🍪 (Version der Produktregel): $$v_{p}[f\cdot g]=v_{p}[f] \cdot g(p)+f(p) \cdot v_{p}[g].$$
## One-Form

> [!abstract] Definition *Differential One-Form* (Pfaffsche Form)
> Eine pfaffsche Form $\alpha$ auf dem Manifold $\mathbb{R}^{n}$ ist ein lineares [[Glossar#Funktional|Funktional]] für die Menge der Tangentenvektoren vom Manifold $\mathbb{R}^{n}$.
> Das heißt, für jeden Punkt $p$ vom Manfold $\mathbb{R}^{n}$ ist $$\alpha: T_{p}(\mathbb{R}^{n})\to \mathbb{R}$$ und $$\begin{align}\alpha(v_{p}+w_{p})&=\alpha(v_{p}) + \alpha(w_{p})\\
\alpha(av_{p})&=a\cdot\alpha(v_{p}).
\end{align}$$

Es ist $\alpha \in T_{p}^{\ast}(\mathbb{R}^{n})$. $T_{p}^{\ast}(\mathbb{R}^{n})$ ist der [[Dualraum]] vom Tangentialram $T_{p}(\mathbb{R}^{n})$.
Der Dualraum $T_{p}^{\ast}\mathbb{R}^{3}$ von $T_{p}\mathbb{R}^{3}$ heißt auch Kotangenzialraum.

Das Ding heißt *One-Form*, weil es nur *einen* Vektor als Input nimmt.



Wedge Product

[^1]: Beispiel Kugeloberfläche: wenn man reinzoomt, sieht es lokal aus wie $\mathbb{R}^{2}$

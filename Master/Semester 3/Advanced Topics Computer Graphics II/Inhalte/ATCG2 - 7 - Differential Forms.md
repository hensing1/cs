zu Deutsch: Differentialformen
[[atcg2-07-differential-forms.pdf]]

## Grundlagen

Bei Differentialformen geht es um Darstellungen von Oberflächen und Volumen *unabhängig von einer Koordinatendarstellug*.

> [!abstract] Definition *Mannigfaltigkeit*
> Eine $n$-dimensionale Mannigfaltigkeit ist ein geometrisches Objekt, welches *lokal* so aussieht wie der euklidische Raum $\mathbb{R}^{n}$. [^1]
> Die **Mannigfaltigkeit $\mathbb{R}^{n}$** (Manifold $\mathbb{R}^{n}$) ist die Menge aller *Punkte* $p \in \mathbb{R}^{3}$.

[^1]: Beispiel Kugeloberfläche: wenn man reinzoomt, sieht es lokal aus wie $\mathbb{R}^{2}$

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

Es ist $\alpha \in T_{p}^{\ast}(\mathbb{R}^{n})$. $T_{p}^{\ast}(\mathbb{R}^{n})$ ist der [[Dualraum]] vom Tangenzialram $T_{p}(\mathbb{R}^{n})$.
Der Dualraum $T_{p}^{\ast}\mathbb{R}^{3}$ von $T_{p}\mathbb{R}^{3}$ heißt auch Kotangenzialraum.

Das Ding heißt *One-Form*, weil es nur *einen* Vektor als Input nimmt.

Die kanonische Basis von $T_{p}^{\ast}\mathbb{R}^{n}$ schreiben wir $$\{ dx_{1},dx_{2},\dots,dx_{n} \}.$$
Sie ist dasselbe wie die [[Dualraum#^442317|kanonische Basis vom Dualraum]] - dh. $$dx_{i}\left(\begin{bmatrix}
v_{1} \\ v_{2} \\ \vdots \\ v_{n}
\end{bmatrix}\right) = v_{i}.$$
Jede Differenzielle Eins-Form ist eine Linearkombination aus diesen Basisfunktionen $dx_{1},dx_{2},\dots,dx_{n}$.
Die Basiselemente $dx_{i}$ sind also jeweils *auch* Differenzielle Eins-Formen.

Die Funktion $dx_{i}$ *projiziert* die $i$-te Komponente des Tangenzialvektors $v_{p}$ auf die Achse $\frac{ \partial  }{ \partial x_{i} }$:
![[Eins-Form.png|500]]

Die Eins-Form $\alpha=a \cdot dx_{1}+b \cdot dx_{2} + c \cdot dx_{3}$, angewandt auf einen Tangenzialvektor $v \in T_{p}\mathbb{R}^{3}$ verhält sich exakt wie das Skalarprodukt $\langle \alpha' \mid v \rangle$ mit $\alpha'=\begin{pmatrix}a \\ b \\ c\end{pmatrix}$.
Deshalb schreiben wir auch gerne $\alpha=\begin{bmatrix}a & b & c\end{bmatrix}$.
Eine Eins-Form ist also ein Kovektor.

Genau wie Vektorfelder, können wir auch Kovektorfelder haben, mit einem anderen Kovektor an jedem Punkt des Manifolds.

Wir können mit einer Eins-Form das **Differenzial** ausdrücken. Zur Erinnerung:
- $v_{p}$ ist ein Tangenzialvektor am Punkt $p$
- $v_{p}[f] \in \mathbb{R}$ ist die Richtungsableitung von einer Funktion $f$ in Richtung $v_{p}$
- Ist $f: \mathbb{R}^{n}\to \mathbb{R}$, dann ist $$df(v_{p})=v_{p}[f]$$das Differenzial $df$ von $f$.
	- $df$ hängt ab von einem Vektor ($v_{p}$) und gibt einen reellen Wert zurück, ist also eine Eins-Form.

Es ist $$df(v_{p})=v_{1}\left. \frac{ \partial f }{ \partial x } \right|_{p} + v_{2}\left. \frac{ \partial f }{ \partial y } \right|_{p}+v_{3}\left. \frac{ \partial f }{ \partial z } \right|_{p}$$
und $$v_{1}=dx(v_{p}),\ v_{2}=dy(v_{p}),\ v_{3}=dz(v_{p}).$$
$df_{p}$ ist gewissermaßen die **ineare Annäherung an $f$ am Punkt $p$**. Man gibt einen Vektor $v_{p}$ rein, und $df(v_{p})$ sagt einem, wie weit die Tangenzialebene von $f$ am Punkt $p$ ansteigt/abfällt.
![[Differenzial.png|500]]

## Wedge-Produkt

> [!abstract] Definition *Wedge-Produkt*
> Das Wedge-Produkt zwischen zwei Eins-Formen ist definiert als $$dx_{i} \wedge dx_{j}(v_{p},w_{p}) \equiv \begin{vmatrix} dx_{i}(v_{p}) & dx_{i}(w_{p}) \\ dx_{j}(v_{p}) & d x_{j}(w_{p}) \end{vmatrix}.$$

Die 1-Form $dx_{1}(v_{p})$ nimmt den Vektor $v_{p}\in T_{p}\mathbb{R}^{n}$ und projiziert ihn auf die $\left.\frac{ \partial }{ \partial x_{1} }\right|_{p}$-Achse. 
Man erhält also gewissermaßen ein 1-dimensionales Volumen von einem Vektor entlang einer Achse.

Mit dem Wedge-Produkt erhält man eine **2-Form**.
Man nimmt zwei Vektoren $v_{p},w_{p} \in T_{p}\mathbb{R}^{n}$. Das Wedge-Produkt der beiden 1-Formen $dx_{i},dx_{j}$ berechnet *die Fläche des **Parallelogramms**, das von $v_{p}$ und $w_{p}$ aufgespannt wird, projiziert auf die Ebene $\left.\frac{ \partial  }{ \partial x_{i} }\right|_{p},\left.\frac{ \partial  }{ \partial x_{j} }\right|_{p}$.*

Es ist $dx_{i} \wedge dx_{j}=-(dx_{j} \wedge dx_{i})$ (schiefsymmetrisch).

Jede *Linearkombination* von mehreren 2-Formen ist auch eine 2-Form.
Beispiel mit den kanonischen 2-Formen im $\mathbb{R}^{3}$:
$$\begin{gather}
dx_{1} \wedge dx_{2} \\
dx_{2} \wedge dx_{3} \\
dx_{1} \wedge dx_{3}
\end{gather}$$
Linearkombination: $$a\ dx_{1} \wedge dx_{2} + b\ dx_{2} \wedge dx_{3} + c\ dx_{1} \wedge dx_{3}.$$
Wenn wir im $\mathbb{R}^{2}$ unterwegs sind, ist das (kanonische) Wedge-Produkt von $v_{1}$ und $v_{2}$ einfach die Fläche des Parallelograms mit Seiten $v_{1},\ v_{2}$.

> **Wedge-Produkt von drei 1-Formen**
> $$dx_{i} \wedge dx_{j} \wedge dx_{k}(u,v,w) = \begin{vmatrix}
dx_{i}(u) & dx_{i}(v) & dx_{i}(w) \\
dx_{j}(u) & dx_{j}(v) & dx_{j}(w) \\
dx_{k}(u) & dx_{k}(v) & dx_{k}(w)
\end{vmatrix}.$$

Im $\mathbb{R}^{3}$ ist das einfach das Volumen des Parallelepipeds[^2], der von $u,v,w$ aufgespannt wird.

[^2]: Quader mit Parallelogrammen als Seitenflächen

Im allgemeinen:
![[Wedge-Produkt.png|600]]

Wenn irgendwelche der $x_{i}$'s gleich sind, ist das gesamte Wedge-Produkt 0.


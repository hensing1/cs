Vektoren sind die Elemente eines Vektorraums:

![[Vektorräume#^1ba9f8]]


## Lineare Unabhängigkeit

![[LA - VL 9#^9b8d50]]

![[LA - VL 9#^ae0c6d]]

## Norm

![[Numerik - VL 1#Vektornorm]]

## Operationen

### Skalarprodukt
> [!abstract] Definition *Skalarprodukt*
> Für zwei *Spaltenvektoren* $x,y \in \mathbb{C}^{m}$ ist das Skalarprodukt definiert als $$\langle x,y \rangle := \langle x \mid y \rangle := x ^{\ast} \cdot y = \begin{pmatrix}\bar{x}_1 & \ldots & \bar{x}_{m}\end{pmatrix}\begin{pmatrix}y_{1} \\ \vdots \\ y_{m}\end{pmatrix}=\sum\limits_{i=1}^{m}\bar{x}_{i}y_{i}.$$

^c43bcf

Für $x ^{\ast}$ siehe [[Matrizen#Adjungierte Matrix]].

> **Rechenregeln für das Skalarprodukt:** 
> - Distributivität: $(u+v) ^{\ast} w = u ^{\ast} w + v ^{\ast} w$
> - Kommutativität: $u ^{\ast} v = v ^{\ast} u$
> - Winkel: $u ^{\ast} v = \|u\|\cdot\|v\|\cos(\angle(u,v))$

> Ein Paar von Vektoren heißt ***orthogonal***, g.d.w. $\langle x,y \rangle = 0$.
> Eine Menge $S=\set{v_{1},\ldots,v_{n} \mid v_{i}\neq 0}$ heißt orthogonal, wenn ihre Elemente paarweise orthogonal sind.
> Die Menge $S$ heißt *orthonormal*, falls sie orthogonal ist und $\forall v \in S$ gilt: $\|v\|=1$.
^88ba7f

### Kreuzprodukt

> [!abstract] Definition *Kreuzprodukt*
> Für zwei Vektoren $u,v \in \mathbb{R}^{3}$ ist das Kreuzprodukt: $$u \times v := \begin{pmatrix}u_{2}v_{3}-u_{3}v_{2} \\ u_{3}v_{1}-u_{1}v_{3} \\ u_{1}v_{2}-u_{2}v_{1}\end{pmatrix}$$

Es gilt:
- $u \times v \bot (u,v)$
	- hat man eine [[Rotationen#Rotationsmatrizen|Rotationsmatrix]] $R = \begin{bmatrix}r_{1} & r_{2} & r_{3}\end{bmatrix}$, dann ist $r_{1} \times r_{2} = r_{3}.$
- $\|u\times v\|=\|u\|\|v\||\sin(\angle(u,v))|$ (der Flächeninhalt des von $u$ und $v$ aufgespannten Parallelogramms)
	- => $u,v$ kolinear $\implies u \times v=0$.

Rechte-Hand-Regel:
![[Kreuzprodukt_rechte_Hand.png|150]]

Als lustige Matrix: ![[Robotik - VL 6#^a9b165]]

## Vektorfeld

Ein Vektorfeld ist ein $\mathbb{R}^{n}$, bei dem für jeden Punkt in diesem $n$-dimensionalen Raum ein $n$-dimensionaler Vektor definiert ist: $$F: \mathbb{R}^{n} \to \mathbb{R}^{n}.$$
> **Divergenz**
> Die Divergenz eines $n$-dimensionalen Vektorfelds $F=\begin{bmatrix}F_{1}(x) \\ F_{2}(x) \\ \vdots \\ F_{n}(x)\end{bmatrix}$ im $\mathbb{R}^{n}$ ist definiert als $$\nabla \cdot F=\frac{ \partial F_{1} }{ \partial x_{1} } + \frac{ \partial F_{2} }{ \partial x_{2} } +\dots+\frac{ \partial F_{n} }{ \partial x_{n} }. $$

^fc6a9b

Intuitiv sagt einem die Divergenz, wie sehr an einem bestimmten Punkt die Vektoren auseinanderlaufen.
$\nabla \cdot F >0$: man befindet sich nahe einer "Quelle", die Vektoren laufen auseinander
$\nabla \cdot F=0$: das Vektorfeld ist glatt, dh. nahegelegene Vektoren zeigen grob in dieselbe Richtung
$\nabla \cdot F<0$: man befindet sich nahe einer "Senke", die Vektoren laufen zusammen

Es ist gewissermaßen das Skalarprodukt zwischen einem Vektor aus dem Vektorfeld, und dem Vektor $\nabla$ mit den partiellen Ableitungsoperatoren - $\nabla = \begin{bmatrix}\frac{ \partial  }{ \partial x_{1} }&\frac{ \partial  }{ \partial x_{2} }& \dots\end{bmatrix}^{T}$. 

Die punktweise Multiplikation von $\nabla$ mit $F$ ergäbe den [[Analysis - VL 17#^71f57b|Gradienten]], deshalb schreibt man $\nabla F$ für den Gradienten und $\nabla \cdot F$ für die Divergenz.
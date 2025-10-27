Datum: 10.11.

# QR-Zerlegung
*Kapitel 4 - Fortsetzung*

## Das Gram-Schmidt-Verfahren

Mit dem Gram-Schmidt-Verfahren berechnet man eine QR-Faktorisierung.

### Das klassische Gram-Schmidt-Verfahren

> `for` $j=1 \to n$:
> > $v_{j}=a_{j}$
> > 
> > `for` $i=1 \to j-1$:
> > > $r_{ij}=q_{i}^{\ast}a_{j}$
> > > $v_{j}=v_{j}-r_{ij}q_{i}$
> > 
> > $r_{jj}=\|v_{j}\|_{2}$
> > $q_{j}=v_{j}/r_{jj}$

$q_{j}$ ist gleich $a_j$ projiziert entlang des Raums $\set{q_{1},\ldots,q_{j-1}}$ und dann normiert, d.h. mit $P_{j}=I-\hat Q_{j-1}\hat Q_{j-1}^{\ast}$ ist $q_{j}= \frac{P_{j}a_{j}}{\|P_{j}a_{j}\|_{2}}$.
Auf diese Weise wird es vom klassischen Gram-Schmidt-Verfahren auch berechnet.

Dieses Verfahren ist *numerisch instabil*, weil Rundungsfehler fortgeführt werden. Errechnete Lösungen können dadurch deutlich von der tatsächlichen Lösung abweichen. Deshalb gibt es:

### Das modifizierte Gram-Schmidt-Verfahren

> `for` $i=1 \to n$:
> > $v_{i}=a_{i}$
> 
> `for` $i=1\to n$:
> > $r_{ii}=\|v_{i}\|_{2}$
> > $q_{i}=v_{i}/r_{ii}$
> > 
> > `for` $j=i+1 \to n$:
> > > $r_{ij}=q_{i}^{\ast}v_j$
> > > $v_{j}=v_{j}-r_{ij}q_{i}$

Laufzeit von beiden: $\mathcal{O}(mn^2)$


## Householder-Triangularisierung

Die Householder-Triangularisierung ist eine Alternative zum Gram-Schmidt-Verfahren, berechnet also auch eine QR-Zerlegung.

Es ist numerisch stabiler und effizienter als beide Gram-Schmidt-Verfahren.

Ansatz für $A \in \mathbb{R}^{m \times n}$: $$\begin{align*}
A &= QR\\
\iff  Q ^{\ast}A&=R
\end{align*}$$
da $Q$ unitär ist. 

Man schreibt $Q ^{\ast}=Q_{n} \cdot \ldots \cdot Q_{2} \cdot Q_{1}$, und die Bildung von $R$ läuft wie folgt:
![[Householder.png|600]]

$Q_{k}$ ist eine orthogonale Matrix in der Form $$Q_{k}=\begin{bmatrix}I & 0 \\ 0 & H\end{bmatrix}$$
mit
- Identitätsmatrix $I \in \mathbb{R}^{(k-1)\times (k-1)}$ 
- Householder-Reflektor $H \in \mathbb{R}^{(m-k+1) \times (m-k+1)}$

Durch den $I$-Block bleiben die ersten $k-1$ Reihen unverändert.

$H$ ist eine unitäre (d.h. symmetrische bzw. hermitesche und orthonormale) Matrix, die die unteren $m-k+1$ Reihen beeinflusst. 

Sei $x \in \mathbb{R}^{m-k+1}$ der Vektor mit den Einträgen $k$ bis $m$ in der $k$-ten Spalte. Dann soll 
1. $\|Hx\|_{2}=\|x\|_{2}$, da $H$ orthogonal
2. nur der erste Eintrag von $x$ ungleich 0 sein.

D.h.: $$x = \begin{bmatrix} \times \\ \times \\ \vdots
 \\ \times\end{bmatrix} \longrightarrow Hx = \begin{bmatrix}\|x\|_{2} \\ 0 \\ \vdots \\ 0\end{bmatrix}=\|x\|_{2}e_{1}$$
Geometrisch:
![[Householder_Reflektor.png|350]]

$v^{\bot}$ ist ein Unterraum, welcher orthogonal zu $v = \|x\|e_{1}-x$ ist. Insbesondere "halbiert" $v^\bot$ den Vektor $v$.

Um einen Punkt auf $v^\bot$ zu projizieren, brauchen wir einen [[Numerik - VL 4#Projektion mit orthonormaler Basis|Projektor]] $P$, der orthogonal zu $v$ projiziert, also $P = I - \frac{vv ^{\ast}}{v ^{\ast}v}$.

Damit $x$ auf der $e_1$-Achse landet, muss er an $v^\bot$ gespiegelt werden. Damit ergibt sich $H$ als:

> **Householder-Projektor**
> Die Matrix $$H = I - 2 \frac{vv ^{\ast}}{v ^{\ast}v}$$ heißt Householder-Projektor oder Householder-Transformation.

Nun gibt es leider zwei Möglichkeiten, $x$ auf die $e_1$-Achse zu spiegelt:
![[Doppelhouseholder.png|400]]

Für numerische Stabilität wählen wir diejenige Variante, die $x$ über eine größere Distanz spiegelt.

Also setzen wir $v = -\text{sign}(x_1)\|x\|e_{1}-x = \text{sign}(x_1)\|x\|e_{1}+x$, wobei $\text{sign}(x_1)$ das Vorzeichen des ersten Eintrags von $x$ ist.
Heißt: wenn $x_1$ positiv ist, wird $x$ auf $-\|x\|e_1$ gespiegelt, und umgekehrt.

Der folgende Algorithmus macht aus der Matrix $A \in \mathbb{R}^{m \times n}$ die obere Dreiecksmatrix $R$ aus der $QR$-Zerlegung: 

> **Householder QR-Faktorisierung**
> 
> `for` $k = 1 \to n$:
> > $x = A_{k:m,k}$
> > $v_{k} = \text{sign}(x_{1})\|x\|_{2}e_{1}+x$
> > $v_{k}=v_{k}/\|v_{k}\|_{2}$
> > $A_{k:m,k:n} = A_{k:m,k:n}-2v_{k}v_{k}^{\ast}A_{k:m,k:n}\quad$*// $A_{k:m,k:n}$ \*= $H$ bzw. $A$ \*= $\begin{pmatrix}I &  \\ & H\end{pmatrix}$*

In der Praxis braucht man $Q$ häufig nicht, daher wird bei diesem Algorithmus nicht berechnet.

*Die Householder-Transformation ist numerisch extrem stabil, da unitäre Transformationen keinerlei Fehlerverstärkung hervorrufen.*
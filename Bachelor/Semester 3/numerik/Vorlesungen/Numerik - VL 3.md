Datum: 27.10.
[[Slides_2023_01_26.pdf|Folien]] Seiten 56 bis 74 (Kapitel 5 und 6)

# Die Singulärwertzerlegung
*Kapitel 3*
## Einführung in die SVD

### Eigenschaften symmetrischer Matrizen

> Sei $(V, \langle \cdot, \cdot \rangle)$ ein [[Vektorräume#Euklidischer Vektorraum|euklidischer Vektorraum]].
> Ein [[Lineare Funktionen#^b41f20|Endomorphismus]] heißt **selbstadjungiert**, falls für alle $v,w$ gilt: $$\langle f(v), w \rangle=\langle v, f(w) \rangle.$$

Schnappe man sich eine [[Matrizen#^88ba7f|Orthonormalbasis]] $B$ für $V$. Dann gilt für $A = \text{DM}_{B}(f)$: $$f \text{ selbstadjungiert} \iff A ^{\ast}=A$$
Eine selbstadjungierte Matrix ist also symmetrisch (bzw. im komplexen hermitesch).


> **Spektralsatz**
> Sei $f: V \to V$ ein selbstadjungierter Endomorphismus.
> Dann besitzt $V$ eine Orthonormalbasis, die aus Eigenvektoren von $f$ besteht.

^e8f823

Die Eigenwerte sind hierbei alle reell und sie dürfen auch Null sein.

Zusammengefasst:
- $A$ ist selbstadjungiert
- $\iff$ die Eigenvektoren von $A$ sind senkrecht zueinander
- $\iff$ $A$ streckt/staucht nur entlang der Eigenvektoren (d.h. $A$ rotiert nicht)
- $\iff$ $A$ ist symmetrisch
- und: $\exists$ unitäre Matrix $T$, sodass $T ^{\ast}A T = \begin{pmatrix}\lambda_{1} & & & \\ & \lambda_{2} & &  \\ & & \ddots &  \\ & & & \lambda_{n}\end{pmatrix}$

$T$ rotiert also die Basisvektoren so, dass sie von $A$ nur noch gestreckt werden, und rotiert sie dann wieder zurück (das Inverse einer Orthogonalmatrix $T$ ist $T ^{\ast}$).

## Singulärwertzerlegung

Nun nehme man sich eine *beliebige* Matrix $A \in \text{Mat}(m \times n)$. 
> $A \cdot A^T$ ist *immer symmetrisch* (bzw. sogar hermitesch). Außerdem ist $A \cdot A^T$ *positiv semidefinit*, d.h. alle Eigenwerte sind $\geq 0$.

Für $A^{T}\cdot A$ gilt es natürlich genauso.

Sei:
- $p$ der [[Lineare Funktionen#^a400ac|Rang]] von $A$,
- $S_{L}=A \cdot A^{T} \in \text{Mat}(m \times m)$,
- $S_{R}=A^{T} \cdot A \in \text{Mat}(n \times n)$.

Betrachte die absteigend sortierten Eigenwerte von $S_{L}$ und $S_{R}$:
$$\begin{align*}
\lambda_{L_{1}} &\geq \lambda_{L_{2}} \geq \ldots \geq \lambda_{L_{p}} > \lambda_{L_{p+1}} = \ldots= \lambda_{L_{m}} = 0\\
\lambda_{R_{1}} &\geq \lambda_{R_{2}} \geq \ldots \geq \lambda_{R_{p}} > \lambda_{R_{p+1}} = \ldots \ldots= \lambda_{R_{n}} = 0
\end{align*}$$
Es ist $\lambda_{L_{i}} = \lambda_{R_{i}} \forall i \in \set{1,\ldots,p}$.

> Die Werte $\sigma_{1} = \sqrt{\lambda_{1}}, \ldots, \sigma_{p} = \sqrt{\lambda_{p}} \neq 0$ heißen **Singulärwerte** von $A$.

**Die Singulärwertzerlegung ist nun:**
$$A = U \cdot \Sigma \cdot V^T$$
wobei:
- $U \in \text{Mat}(m \times m)$ spaltenweise die *normierten Eigenvektoren von $S_L$*[^1] enthält (absteigend nach Eigenwerten sortiert)
- $\Sigma = \begin{pmatrix}\sigma_{1} & & \\ & \ddots &  \\ & & \sigma_{n} \\ & & & \end{pmatrix} \in \text{Mat}(m \times n)$
- $V \in \text{Mat}(n \times n)$ spaltenweise die *normierten Eigenvektoren von $S_R$*[^2] enthält (absteigend nach Eigenwerten sortiert).

[^1]: genannt Linkseigenvektoren
[^2]: genannt Rechtseigenvektoren

Ist $m>n$, wird $U$ mit irgendwelchen orthonormalen Vektoren aufgefüllt. Dann sind die Spalten von $U$ also eine Orthonormalbasis für den $\mathbb{K}^m$, und die von $V$ eine Orthonormalbasis für den $\mathbb{K}^{n}$.

Die Matrizen machen folgendes:
- $V^T$ *rotiert* die (orthonormalen) Rechtseigenvektoren zur kanonischen Basis,
- $\Sigma$ *projiziert* sie in den $\mathbb{K}^{n}$ und *streckt* sie entlang der Basisvektoren (mit den Singulärwerten),
- $U$ *rotiert* die skalierten Basisvektoren zu den (orthonormalen) Linkseigenvektoren.

Graphisch:
![[SVD.png]]

Da $\sigma_{1}$ die Länge der größten Halbachse der resultierenden (verallgemeinerten) Ellipse ist, ist $\|A\|_{2}=\sup \frac{\|Ax\|_{2}}{\|x\|_{2}}=\sigma_{1}$.

Schließlich ist $$A=\sum_{i=1}^{p}u_{i}\sigma_{i}v ^{\ast}_{i}.$$
$\hat A(k) := \sum_{i=1}^{k}u_{i}\sigma_{i}v ^{\ast}_{i}$ heißt *Rank-k Approximation* von $A$.

### Algorithmus für Singulärwertzerlegung

1. Berechne $S_R = A^{T}A$
2. Berechne Eigenwerte von $S_{R}$: $\lambda_{1} \geq \ldots \lambda_{p} > \lambda_{p+1} = \ldots = 0$
3. Berechne zugehörige normierte Eigenvektoren $\set{v_{1},\ldots,v_{p}}$ und setze $V = \left[v_{1},\ldots,v_{p}\right]$
4. Bilde Diagonalmatrix $\Sigma$ aus den Singulärwerten von $A$: $\sigma_{i}=\sqrt{\lambda_{i}}$
5. Finde $U$ durch $u_{i}=\frac{1}{\sqrt{\lambda_{i}}}Av_{i}$ für $i \leq p$. Ergänze diese Vektoren nach Basisergänzungssatz zu Basis von $\mathbb{K}^{m}$.
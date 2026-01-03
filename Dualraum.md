> [!abstract] Definition *Dualraum*
> Sei $V$ ein [[Vektorräume|Vektorraum]] über einem [[Ringe und Körper#Körper|Körper]] $\mathbb{K}$. Der **Dualraum** von $V$ ist definiert als $$V^{\ast}= \{ f: V \to \mathbb{K}\ |\ f\ \text{ist linear.} \},$$also die Menge aller [[Glossar#Funktional|Funktionale]] auf $V$.

Es gilt:
- $V^{\ast}$ ist ein Vektorraum.
- Ist $V$ endlichdimensional, ist $\text{dim}(V^{\ast}) = \text{dim}(V)$.
- Für die kanonische Basis $e_{1},e_{2},\dots,e_{n}$ von $V$, ist die kanonische Basis von $V^{\ast}$: $$e^{i}(e_{j})=\delta_{j}^{i}=\begin{cases}
1 & \text{falls}\ i=j \\
0 & \text{sonst}.
\end{cases}$$
Also: $e^{i}$ ist eine Funktion, die für einen Vektor $v \in V$ die $i$-te Koordinate auswirft: $$e^{2}\left(\begin{bmatrix}
2 \\
4 \\
6
\end{bmatrix}\right) = 4.$$
Die Elemente von $V^{\ast}$ heißen auch **Kovektoren**.

Ist $V=\mathbb{R}^{n}$, ist für $v^{\ast} \in V^{\ast}$ und $v \in V$ $$v^{\ast}(v) = \langle v^{\ast} \mid v \rangle $$
einfach das [[Vektoren#Skalarprodukt|Skalarprodukt]].
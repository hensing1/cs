[[FOCVE___02_Cameras.pdf]]

## Pinhole Model

Brennweite $f_{0}$: Distanz Bildebene zu optischem Zentrum
$$\begin{pmatrix}
x & y & z
\end{pmatrix}^{T}\mapsto\begin{pmatrix}
\frac{f_{0}x}{z} & \frac{f_{0}y}{z} & f_{0}
\end{pmatrix}^{T}$$

**Intrinsische Kameramatrix:**
$$K=\begin{pmatrix}
f_{x} & 0 & c_{x} \\
0 & f_{y} & c_{y} \\
0 & 0 & 1
\end{pmatrix}$$
mit
- $f_{x}=\frac{|P_{x}|}{W}f_{0}$
- $f_{y}=\frac{|P_{y}|}{H}f_{0}$
- $c_{x}=\frac{|P_{x}|}{W}x_{0}$
- $c_{y}=\frac{|P_{y}|}{H}y_{0}$

mit $x_{0},y_{0}$ die Koordinaten von der Bildmitte.

$\pi(x,y,z)=\left( \frac{x}{z},\ \frac{y}{z} \right)^{T}$ ist die perspektivische Division (homogene Koordinaten -> Bildkoordinaten)

Projektion: $\mathbb{R}^{2} \ni p = \pi(K \cdot x)$
Un-Projektion: $x = K^{-1}\cdot (p_{x},p_{y},1)^{T} \cdot z$

**Extrinsische Kameramatrix:** $4 \times 4$ Rotations- und Translationsmatrix in homogenen Koordinaten (Weltkoordinaten -> Kamerakoordinaten)
Bei nur einer Kamera die Identität, bei mehreren Kameras z.B. aus dem Referenz-Frame der ersten Kamera

## Verzerrungen

Radial: z.B. 3 Parameter, $k_{1}\ k_{2}\ k_{3}$
Tangential: 2 Parameter, $p_{1}\ p_{2}$

$p_{\text{radial}}=p(1+k_{1}r^{2}+k_{2}r^{4}+k_{3}r^{6})$, $p$ relativ zum Bildmittelpunkt

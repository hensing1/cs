[[FOCVE_02_Cameras.pdf]]

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

## Kalibrierung

### Verzerrung
Radial: z.B. 3 Parameter, $k_{1}\ k_{2}\ k_{3}$
Tangential: 2 Parameter, $p_{1}\ p_{2}$

$p_{\text{radial}}=p(1+k_{1}r^{2}+k_{2}r^{4}+k_{3}r^{6})$, $p$ relativ zum Bildmittelpunkt

$x_{\text{tangential}}=x+(2p_{1}xy+p_{2}(r^{2}+2x^{2}))$
$y_{\text{tangential}}=y+(2p_{2}xy+p_{1}(r^{2}+2y^{2}))$

### Homographie

Homography für Kamerakalibrierung: 8 Freiheitsgrade (3x3-Matrix, Skalierung egal)
- ist intrinsische mal extrinsische Kameramatrix
- extrinsischer Teil ist $3 \times 3$-Matrix $\begin{bmatrix}r_{1} & r_{2} & t\end{bmatrix}$
- man braucht mind. 4 Punkte (je mit x, y-Koordinaten)
- $s \cdot \begin{pmatrix}p_{x,i} \\ p_{y,i} \\ 1\end{pmatrix} = H \begin{pmatrix}v_{x,i} \\ v_{y,i} \\ 1\end{pmatrix}$
	- $v_{i}$ ist 3d-Punkt auf dem Kalibrierungs-Target, mit $z=0$
		- wir sagen, die Kamera bewegt sich relativ zum Target, nicht andersherum
	- $p_{i}$ ist derselbe Punkt in Pixelkoordinaten

### Triangulierung

Disparity: Differenz in Koordinaten desselben Punkts in zwei verschiedenen Kamerabildern $l$ und $r$, dh. $x_{l}-x_{r}$
Optische Zentren der Kameras: $o_{l}$ bzw. $o_{r}$

$z$-Koordinate: $$z=f \cdot (o_{l}-o_{r})$$

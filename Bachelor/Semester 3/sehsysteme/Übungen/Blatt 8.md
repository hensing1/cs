# Übungsblatt 8
- Henning Lehmann

## Aufgabe 1

$$\begin{align*}
\langle I_{x}^{2}\rangle &= \sum_{u,v} w(u,v)I_{x}^{2}\\
&= \sum_{u=-1}^{1}\sum_{v=-1}^{1}I_{x}^{2}\\
&= 0^{2}+0^{2}+1^2+\\
&\quad-1^{2}+0^{2}+1^2+\\
&\quad0^2+0^2+0^2\\
&=3
\end{align*}$$
$$\begin{align*}
\langle I_{y}^{2}\rangle &= \sum_{u,v} w(u,v)I_{y}^{2}\\
&= \sum_{u=-1}^{1}\sum_{v=-1}^{1}I_{y}^{2}\\
&= -1^2+0^2+-1^2+\\
&\quad-1^2+-1^2+-1^2+\\
&\quad0^2+-1^2+0^2\\
&=6
\end{align*}$$

$$\begin{align*}
\langle I_{x}I_{y}\rangle &= \sum_{u,v} w(u,v)I_{x}I_{y}\\
&= \sum_{u=-1}^{1}\sum_{v=-1}^{1}I_{x}I_{y}\\
&= 0\cdot(-1)+0\cdot0+1\cdot(-1)+\\
&\quad(-1)\cdot(-1)+0\cdot(-1)+1 \cdot(-1)+\\
&\quad0\cdot0+0\cdot(-1)+0\cdot0\\
&=-1
\end{align*}$$

$$\Rightarrow A = \begin{pmatrix}3 & -1 \\ -1  & 6\end{pmatrix}.$$

$$\begin{align*}
R &= \det(A) - \kappa \cdot\text{trace}(A)\\
&= 3 \cdot 6 - (-1)\cdot(-1) - 0,1 (3+6)^{2}\\
&=18 - 8,1\\
&=9,9.
\end{align*}$$


## Aufgabe 3

Histogramm für die obere Teilregion:

$$\begin{align*}
0°&: 0\\
45°&: 10 + 1 + 20 = 31\\
90°&: 1\\
135°&: 1\\
180°&: 0\\
225°&: 0\\
270°&: 0\\
315°&: 0
\end{align*}$$

Histogramm für die untere Teilregion:
$$\begin{align*}
0°&: 0\\
45°&: 1\\
90°&: 20 + 1 + 10 = 31\\
135°&: 0\\
180°&: 0\\
225°&: 1\\
270°&: 1\\
315°&: 0
\end{align*}$$

Der Descriptor für diesen Keypoint besteht aus diesen beiden Histogrammen.
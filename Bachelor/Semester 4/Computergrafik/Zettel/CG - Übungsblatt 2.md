# Übungsblatt 2

- Henning Lehmann, 50045776
- Florian Barth, 50045734

*Gegeben:*
- $p_{0},p_{1},p_{2},p\in \mathbb{R}^2$
- $\lambda_{0}p_{0}+\lambda_{1}p_{1}+\lambda_{2}p_{2}=p$
- $\left\|\begin{pmatrix}\lambda_{0} \\ \lambda_1 \\ \lambda_{2}\end{pmatrix}\right\|_{1}=1$

*Zu zeigen:*
$\lambda_{i}=\frac{A_{i}}{A_{0}+A_{1}+A_{2}}$

*Beweis:*
Lineares Gleichungssystem: $$\begin{pmatrix}p_{0x} & p_{1x} & p_{2x} \\ p_{0y} & p_{1y} & p_{2y} \\ 1 & 1 & 1\end{pmatrix}\begin{pmatrix}\lambda_0 \\ \lambda_1 \\ \lambda_2\end{pmatrix}=\begin{pmatrix}p_{x} \\ p_{y} \\ 1\end{pmatrix}.$$
Seien $p_{0h}, p_{1h}, p_{2h}, p_{h} \in \mathbb{R}^3$ die gegebenen Punkte in homogenen Koordinaten. Dann ist das Gleichungssystem: $$\begin{pmatrix}p_{0h} & p_{1h} & p_{2h}\end{pmatrix}\begin{pmatrix}\lambda_{0} \\ \lambda_1 \\ \lambda_2\end{pmatrix}=p_{h}$$
Lösung mit Cramerscher Regel: $$\begin{align*}
\lambda_{0} &= \frac{\det \begin{pmatrix}p_{h} & p_{1h} & p_{2h}\end{pmatrix}}{\det \begin{pmatrix}p_{0h} & p_{1h} & p_{2h}\end{pmatrix}} \\
\lambda_{1} &= \frac{\det \begin{pmatrix}p_{1h} & p_{h} & p_{2h}\end{pmatrix}}{\det \begin{pmatrix}p_{0h} & p_{1h} & p_{2h}\end{pmatrix}} \\
\lambda_{2} &= \frac{\det \begin{pmatrix}p_{h} & p_{1h} & p_{2h}\end{pmatrix}}{\det \begin{pmatrix}p_{0h} & p_{1h} & p_{h}\end{pmatrix}}
\end{align*}$$

Die Dreiecksfläche ist translationsinvariant: $$A(\Delta(p_{0},\,p_{1},\,p_{2})) = A(\Delta(0,\,p_{1}-p_{0},\,p_{2}-p_{0}))$$
Daher: $$A(\Delta(p_{0},\,p_{1},\,p_{2})) = \frac{1}{2}\left|\det\begin{pmatrix}p_{1}-p_{0} & p_{2}-p_{0}\end{pmatrix}\right|$$
Betrachte Determinante: $$\begin{align*}
\det\begin{pmatrix}p_{1}-p_{0} & p_{2}-p_{0}\end{pmatrix} &= \det \begin{pmatrix}p_{1x}-p_{0x} & p_{2x}-p_{0x}\\
p_{1y}-p_{0y} & p_{2y}-p_{0y}\end{pmatrix}\\
&= (p_{1x}-p_{0x})(p_{2y}-p_{0y}) - ((p_{2x}-p_{0x})(p_{1y}-p_{0y}))\\
&= p_{1x}p_{2y}+p_{0x}p_{0y}-p_{1x}p_{0y}-p_{0x}p_{2y}-(p_{2x}p_{1y}+p_{0x}p_{0y}-p_{2x}p_{0y}-p_{0x}p_{1y})\\
&= p_{0x}p_{1x}+p_{1x}p_{2y}+p_{2x}p_{0y}-p_{2x}p_{1y}-p_{0x}p_{2y}-p_{1x}p_{0y}\\
&= \det \begin{pmatrix}p_{0x} & p_{1x} & p_{2x}\\
p_{0y} & p_{1y} & p_{2y}\\
1 & 1 & 1\end{pmatrix}\\
&= \det \begin{pmatrix}p_{0h} & p_{1h} & p_{2h}\end{pmatrix}
\end{align*}$$
Einsetzen in $\lambda$s von oben: $$\begin{align*}
\lambda_{0} &= \frac{\det \begin{pmatrix}p_{h} & p_{1h} & p_{2h}\end{pmatrix}}{\det \begin{pmatrix}p_{0h} & p_{1h} & p_{2h}\end{pmatrix}}\\
&= \frac{\det \begin{pmatrix}p_{1}-p & p_{2}-p\end{pmatrix}}{\det \begin{pmatrix}p_{1}-p_{0} & p_{2}-p_{0}\end{pmatrix}}\\
&= \frac{\frac{1}{2}\det \begin{pmatrix}p_{1}-p & p_{2}-p\end{pmatrix}}{\frac{1}{2}\det \begin{pmatrix}p_{1}-p_{0} & p_{2}-p_{0}\end{pmatrix}}\\
&= \frac{A(\Delta(p,\,p_{1},\,p_{2}))}{A(\Delta(p_{0},\,p_{1},\,p_{2}))}
\end{align*}$$
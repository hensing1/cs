# Übungsblatt 11

- Henning Lehmann

## Aufgabe 1

1. $$\begin{align*}
\begin{bmatrix}18 & 12 & 10 \\ 4 & 10 & 6 \\ 5 & 4 & 5\end{bmatrix} &\Rightarrow \begin{bmatrix}1 & 1 & 1 & 1 & 1 & 0 & 0 & 0\end{bmatrix} \Rightarrow 2^{7}+2^6+2^5+2^4+2^3=248\\\\
\begin{bmatrix}10 & 11 & 14 \\ 8 & 9 & 13 \\ 5 & 8 & 14\end{bmatrix} &\Rightarrow \begin{bmatrix}0 & 0 & 1 & 1 & 1 & 0 & 0 & 0\end{bmatrix} \Rightarrow 2^5+2^4+2^3=56
\end{align*}$$

2. $$\begin{align*}
\begin{bmatrix}1 & 1 & 1 & 1 & 1 & 0 & 0 & 0\end{bmatrix} &\Rightarrow \begin{bmatrix}0 & 0 & 0 & 1 & 1 & 1 & 1 & 1\end{bmatrix} \Rightarrow 2^4+2^3+2^2+2^1+2^0=31\\\\
\begin{bmatrix}0 & 0 & 1 & 1 & 1 & 0 & 0 & 0\end{bmatrix} &\Rightarrow \begin{bmatrix}0 & 0 & 0 & 0 & 0 & 1 & 1 & 1\end{bmatrix} \Rightarrow 2^2+2^1+2^0=7
\end{align*}$$
3. 

| 0 | 0 | 0 | 1 | 0 | 1 | 0 | 0 | 0 | 0 |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |

## Aufgabe 2

### 1.
Fläche:
$F = 12$

Schwerpunkt:
$i_{\mu}=\frac{1}{12} \cdot 3 \cdot 1 + 2 \cdot 2 + 2 \cdot 3 + 2 \cdot 4 + 3 \cdot 5 = 3$
$j_{\mu}=\frac{1}{12} \cdot 5 \cdot 1 + 2 \cdot 2 + 5 \cdot 3 = 2$

$\Rightarrow (i_\mu,j_\mu)=(3,2)$

### 2.
$$\begin{align*}
\mu_{20}(s) = \sum_{(i, j) \in s}(i - 3)^{2} = 28 \\
\mu_{02}(s) = \sum_{(i, j) \in s}(j - 2)^{2} = 10
\end{align*}$$

### 3.
$\gamma=\frac{2+0}{2}+1=2$

$$\begin{align*}
\eta_{20}(s) = \frac{\mu_{20}(s)}{F^{\gamma}} = \frac{28}{12^{2}} \approx 0,194\\
\eta_{02}(s) = \frac{\mu_{02}(s)}{F^{\gamma}} = \frac{10}{12^{2}} \approx 0,069
\end{align*}$$
### 4.
$\varphi_{1}(s) = \eta_{20}(s) + \eta_{02}(s) \approx 0,264$
$\varphi_{1}'(s) = \text{sign}(\varphi_{1}(s)) \cdot \log_{10}(|\varphi_{1}(s)|) \approx -0.579$

## Aufgabe 3

Plot der Nächste-Nachbar-Zuordnung (farblich dargestellt, Punkte aus $D$ als $\star$ dargestellt):
![[scatter_nn.png]]

Nicht-normalisiertes Histogramm: $$\begin{pmatrix}2 \\ 1 \\ 2 \\ 2\end{pmatrix}$$
Normalisiert: $$BoW(s) = \begin{pmatrix} \frac{2}{7} \\ \frac{1}{7} \\ \frac{2}{7} \\ \frac{2}{7}\end{pmatrix}$$

## Aufgabe 4

Rotationsmatrix $E = \begin{pmatrix}0.734 & -0.679 \\ 0.679 & 0.734\end{pmatrix}$

$$\begin{align*}
w_{1} &= (z_{1} - E(z)) \cdot E = \begin{pmatrix}-5.48 \\ 2.62\end{pmatrix}\\
w_{2} &= (z_{2} - E(z)) \cdot E = \begin{pmatrix}-3.90 \\ -1.57\end{pmatrix}\\
w_{3} &= (z_{3} - E(z)) \cdot E = \begin{pmatrix}-0.34 \\ -2.14\end{pmatrix}\\
w_{4} &= (z_{4} - E(z)) \cdot E = \begin{pmatrix}3.84 \\ -0.56\end{pmatrix}\\
w_{5} &= (z_{5} - E(z)) \cdot E = \begin{pmatrix}5.88 \\ 1.64\end{pmatrix}
\end{align*}$$

Merkmale sind unkorrelliert $\iff$ Kovarianz ist gleich Null.

Per Konstruktion gilt für den Mittelwert der Merkmalsvektoren $w_{i}$: $\mu(w)=(0,0)$.

Daher ergibt sich für die Kovarianz: $$\text{Cov}(w_{j})=\sum_{i=1}^{5}w_{i1}\cdot w_{i2}\approx 0,025 \approx 0.$$
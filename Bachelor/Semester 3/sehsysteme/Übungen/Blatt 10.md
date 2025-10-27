# Übungsblatt 10
- Henning Lehmann

## Aufgabe 1
Die Klassifikation funktionierte leider nur für die Floppy-Disk und die Schiebelehre. Ich weiß nicht warum, die Merkmale werden genauso berechnet wie letzte Woche auch.

$sim$-Werte:
### Diskette
- Hammer: $0.0$
- Sliding_Caliper: $0.0$
- Floppy: $0.3891$
- Bit: $0.0$
- Allen_Key: $0.0$

### Schiebelehre
- Hammer: $0.0$
- Sliding_Caliper: $0.6237$
- Floppy: $0.0$
- Bit: $0.0$
- Allen_Key: $0.3317$

## Aufgabe 2
Flächeninhalt:
$$F(s) = 9$$
Schwerpunkt:
$$i_{\mu}=\frac{1}{9} \cdot (0 + 2 + 6 + 6 + 4) = 2$$
$$j_{\mu}=\frac{1}{9} \cdot (0 + 3 + 6) = 1$$

Trägheitsmomente:
$$\begin{align*}
m_{x}(s) &= 3 \cdot (0-1)^{2} + 3 \cdot (1-1)^{2} + 3 \cdot (2 - 1)^{2}\\
&= 3+0+3\\
&= 6
\end{align*}$$
$$\begin{align*}
m_{y}(s) &= (0 - 2)^{2}+ 2 \cdot (1-2)^{2} + 3 \cdot (2-2)^{2}+ 2 \cdot (3-2)^{2}+(4-2)^{2}\\
&=4 + 2 + 0 + 2 + 4\\
&= 12
\end{align*}$$

$$\begin{align*}
m_{xy}(s) &= (0-2)(0-1) + (1-2)(0-1) + (2-2)(0-1)\\
&\quad+(1-2)(1-1) + (2-2)(1-1) + (3-2)(1-1) \\
&\quad+(2-2)(2-1) + (3-2)(2-1) + (4-2)(2-1)\\
&= 2 + 1 + 1 + 2\\
&= 6
\end{align*}$$
Drehwinkel:
$$\begin{align}
\alpha &= \arctan\left(\frac{2 \cdot 6}{12-6}\right)/2\\
&\approx 31.72°
\end{align}$$

## Aufgabe 3
$$\mu_{0}=\mu(A) = \begin{pmatrix}2 \\ 8 \\ -1\end{pmatrix}$$
$$\mu_{1}=\mu(B) = \begin{pmatrix}6 \\ 2 \\ -2\end{pmatrix}$$
$$\mu_{2}=\mu(C) = \begin{pmatrix}13 \\ -3 \\ 1\end{pmatrix}$$

$$S_{w} = \frac{1}{15} \cdot \sum_{k=0}^{2}\sum_{s\in T_{k}}\|m(s) - \mu_{k}\|^{2}=6,266$$

$$S_{b} = \frac{1}{\binom{3}{2}} (\|\mu(A)-\mu(B)\|^{2}+\|\mu(A)-\mu(C)\|^{2} + \|\mu(B)-\mu(C)\|^{2}= 127,33$$

## Aufgabe 4

$$\begin{matrix}
\mu_{1,1}=0.85 & \sigma_{1,1}^{2}=0.005 \\
\mu_{1,2}=0.65 & \sigma_{1,2}^{2}=0.005 \\
\mu_{2,1}=0.7 & \sigma_{2,1}^{2}=0.005 \\
\mu_{2,2}=0.85 & \sigma_{2,2}^{2}=0.005
\end{matrix}$$

$$\sigma=\sqrt{\sigma^{2}}=0.0707$$

$$P(m(s) \mid s=C_{1})=0.21$$
$$P(m(s)\mid s=C_{2})=24.79$$
$$\begin{align*}
P_{C_{1}}=\frac{P(m(s)\mid s=C_{1})\cdot P(C_{1})}{abc}&\approx 2\%\\
P_{C_{2}}=\frac{P(m(s)\mid s=C_{2})\cdot P(C_{2})}{abc}&\approx 98\%
\end{align*}$$
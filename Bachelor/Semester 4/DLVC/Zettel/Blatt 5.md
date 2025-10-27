# DLVC - Übungsblatt 5

- Henning Lehmann (s88jlehm)
- Jiawei Mao

## a)

### 1.

Ein Layer $i$ mit $n \times n$ Neuronen hat das folgende Receptive Field $R_i$: $$R_{i}(n) = \begin{cases}
n^{2}, & \text{falls}\,i=0 \\
R_{i-1}(k_{i}+(n-1)\cdot s_{i}) & \text{sonst.}
\end{cases}$$

Unter der Annahme, dass auf dem Übungsblatt $k_3$ und $k_4$ vertauscht sind, ergibt sich für das Beispiel: $$\begin{align*}
R_{4}(n) &= R_{3}(2+(n-1) \cdot 2) = R_{3}(2n)\\
&= R_{2}(3+(2n-1)\cdot 1) = R_{2}(2n+2)\\
&= R_{1}(5+(2n+1) \cdot 1) = R_{1}(2n+6)\\
&= R_{0}(7+(2n+5) \cdot 1)\\
&= (2n+12)^{12}.
\end{align*}$$

### 2.
Ein $n \times n$-Eingangsbild hat die folgende Outputgröße $O$: $$O(n) = \frac{n+2p_{i}-\lceil k_{i}/2\rceil}{2}$$

## b)

Die Batch-Normalisierung für zweidimensionale Daten funktioniert analog zur eindimensionalen Variante, nur dass $H$ ein dreidimensionaler Tensor ist, der pro Minibatch die zweidimensionalen Aktivierungen enthält: $H \in \mathbb{R}^{n \times h \times b}$, wobei $n$ die Anzahl der Samples des Minibatches und $h$ und $b$ die Höhe bzw. Breite der Layer-Aktivierungen ist.

Mittelwert und Standardabweichung sind nun Matrizen statt Vektoren: $$\mu=\frac{1}{n}\sum_{i=1}^{n}H_{i,:,:}$$
$$\sigma=\sqrt{\delta+ \frac{1}{n}\sum_{i=1}^{n}(H_{i,:,:}-\mu)^{2}}$$

Und die Normalisierung ergibt sich wieder als $$H'=\frac{H-\mu}{\sigma}.$$
Batch-Normalisierung kann bei der Verarbeitung von sequenziellen Daten durch Recurrent Neural Nets nicht gut verwendet werden, da die Daten unabhängig vom zeitlichen Kontext normalisiert werden. Stattdessen kann in diesem Anwendungsfall Layer-Normalisierung verwendet werden.

## c)

### 1.

$$\begin{align*}
\frac{\partial E(o,y)}{\partial w_{s,t}} &= \sum_{i,j=1}^{n_{o}}\frac{\partial E(o,y)}{\partial o_{i,j}}\frac{\partial o_{i,j}}{\partial w_{s,t}} & (o_{i,j}\,\text{sind unabhängig})\\
&= \sum_{i,j=1}^{n_{o}} \frac{2}{n_{o}^{2}}(o_{i,j}-y_{i-j}) \frac{\partial o_{i,j}}{\partial w_{s,t}}\\
&= \sum_{i,j=1}^{n_{o}} \frac{2}{n_{o}^{2}}(o_{i,j}-y_{i-j}) x_{i-s,j-t} & \left(\frac{\partial w_{k.l}\cdot x_{i-k,j-l}}{\partial w_{s,t}} = 0 \text{ für } (k,l) \neq (s,t)\right)
\end{align*}$$

### 2.
Ableitung von $o'$: $$\frac{\partial o'_{u,v}}{\partial x_{i,j}}=\begin{cases}
1 & \text{wenn } x_{i,j}=p_{2}(x)_{u,v} \\
0 & \text{sonst.}
\end{cases}$$
$$\begin{align*}
\frac{\partial E(o',y')}{\partial x_{i,j}} &= \sum_{u,v=1}^{n_{o'}}\frac{\partial E(o',y')}{\partial o'_{u,v}}\frac{\partial o'_{u,v}}{\partial x_{i,j}}\\
&= \sum_{u,v=1}^{n_{o'}} \frac{2}{n_{o}^{2}}(o'_{u,v}-y_{u,v})\frac{\partial o'_{u,v}}{\partial x_{i,j}}\\
&= \begin{cases}
\sum_{u,v=1}^{n_{o'}} \frac{2}{n_{o}^{2}}(o'_{u,v}-y_{u,v}) & \text{wenn }x_{i,j}=p_{2}(x)_{u,v}\\
0 & \text{sonst.}
\end{cases}
\end{align*}
$$
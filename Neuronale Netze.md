# Künstliche Neuronale Netze (KNNs)

## Feed-Forward Networks

### Neuron

Nichtlineare Funktion der Form $$f(a)=f\left(\sum_{i}w_{i}x_{i}+b\right)$$ mit:
- $x_i$ Eingangswerte (Netzwerkinput oder andere Neuronen)
- $w_{i}$ Gewichtung der jeweiligen Eingangswerte
- $b$ Aktivierungs-Bias
- $f$ nichtlineare Aktivierungsfunktion, z.B. Sigmoid $\sigma(x) = \frac{1}{1+e^{-x}}$.

$a$ heißt *Aktivierung* des Neurons.

### Multilayer Perceptron

*Einfaches Multilayer Perceptron (MLP):*
![[MLP.png]]

### Layer

Ein Layer fasst $M$ Neuronen mit jeweils denselben $D$ Eingabewerten zusammen: $$a_{j}=\sum_{i=1}^{D}w_{ji}\cdot x_{i}+b_{j},\quad j=1,\ldots,M.$$
Die Ausgabe ist wieder $z_{j} = f(a_{j})$.

Das Layer in Matrixschreibweise:
$$\begin{align*}a = Wx+b\\
z=f(a)
\end{align*}$$
mit $W \in \mathbb{R}^{M\times D}$ (enthält zeilenweise die Gewichte pro Neuron), $x_{i} \in \mathbb{R}^{D}$ und $a, b \in \mathbb{R}^{M}$.
Noch kompakter ist $a=\begin{bmatrix}b & W\end{bmatrix}\begin{bmatrix}1 \\ x\end{bmatrix}=\hat W \hat x$.

Mit Eingabevektor $x$, Ausgabevektor $y$ und $N$ Layern ist ein MLP: 

$$\begin{align*}
a^{(1)}&=W^{(1)}\cdot x + b^{(1)},&z^{(1)}=f^{(1)}(a^{(1)})\\
a^{(2)}&=W^{(2)}\cdot z^{(1)} + b^{(2)},&z^{(2)}=f^{(2)}(a^{(2)})\\
&\vdots\\

a^{(N)}&=W^{(N)}\cdot z^{(N-1)} + b^{(N)},&y=f^{\text{out}}(a^{(N)})\\
\end{align*}$$
Zusammengefasst ergibt das eine parametrisierte Funktion $nn_{\theta}(x) = f^{\text{out}}(W^{(N)} \cdot f^{(N-1)}(\ldots)+b^{(N)})$, wobei die Parameter $\theta$ die Gewichtsmatrizen und Biasvektoren sind.

### Aktivierungsfunktionen

> Wir benötigen nichtlineare Aktivierungsfunktionen, da unser Netzwerk sonst nicht über die Mächtigkeit eines linearen 1-Layer-Netzwerks hinauskäme.

#### Aktivierungsfunktionen für Hidden Units

*Sigmoid:* $$\sigma(x) = \frac{1}{1+e^{-x}}$$
*Tangens Hyperbolcus:* $$\tanh(x) = \frac{e^{x}-e^{-x}}{e^{x}+e^{-x}}=2\sigma(2x)-1$$
*Hard tanh:* $$h(x)=\max(-1,\min(1,x))$$
*Rectified Linear Unit (ReLU):* $$\text{ReLU}(x)=\max(x,0)$$
*Leaky ReLU:* $$\text{LReLU}(x)=\max(x,0)+\alpha \min (x,0)$$mit typischem Wert $\alpha=0.01$.
*Parametric ReLU*: LReLU, jedoch wird $\alpha$ als lernbarer Parameter behandelt.

*Softplus:* $$\zeta(x)=\log(1+e^{x})$$
*Exponential Linear Unit (ELU):* $$\text{ELU}(x)=\begin{cases}x & \text{wenn}\,x\geq 0 \\
e^{x}-1 & \text{wenn}\,x<0.\end{cases}$$
*Gaussian Error Linear Unit (GELU):* $$\text{GELU}(x)=\frac{x}{2}(1+\text{erf}\left(\frac{x}{\sqrt{2}}\right))$$
#### Aktivierungsfunktionen für Output Units
*Linear Unit:* $$l(x)=x$$
- Nützlich als Ausgabe für Regressionsprobleme

*Softmax:* $$\text{softmax}(x)=\frac{\exp(x_{i})}{\sum_{j}\exp(x_{j})}$$ ^04fda6
- Invariant bezüglich skalarer Addition: $\text{softmax}(x)=\text{softmax}(x+c)$
- Numerisch stabile Version: $\text{softmax}_\text{stable}(x)=\text{softmax}(x-\max_{i}(x))$

### Symmetrien und Universal Approximation Theorem

Es gibt viele Möglichkeiten für die Parametrisierung $\theta$ eines MLP, um dieselbe Funktion darzustellen:
- $M$ Neuronen pro Layer $\to$ $M!$ äquivalente Permutationen pro Layer
- Bei symmetrischer Aktivierungsfunktion (z.B. $\tanh(x)=-\tanh(-x)$): $2^{M}$ Möglichkeiten pro Layer (jede Zeile der Gewichtsmatrix $W$ kann mit -1 multipliziert werden)

Das ist relevant, weil damit beim Training kein globales Minimum gefunden werden muss. Es gibt viele äquivalente lokale Minima, die sehr gut sind.

> [!info] Universal Approximation Theorem
> Ein 2-Layer-Netzwerk kann bei ausreichend vielen hidden units jede kontinuierliche Funktion auf einer kompakten Domäne mit beliebiger Genauigkeit approximieren.


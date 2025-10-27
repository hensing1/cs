# Übungsblatt 7

- Henning Lehmann
- Jiawei Mao

## a)

Für beide Netzwerke gilt $$\frac{\partial h_{n}}{\partial h_{l}}=\frac{\partial h_n}{\partial h_{n-1}} \cdot \frac{\partial h_{n-1}}{\partial h_{n-2}} \cdot \ldots \cdot \frac{\partial h_{l+1}}{\partial h_l}.$$

Für das einfache Netz:
$$\begin{align*}
h_{i}&=W_{i}\cdot h_{i-1}\\
\implies \frac{\partial h_{i}}{\partial h_{i-1}} &= W_{i}\\
\implies \frac{\partial h_{n}}{\partial h_{j}} &= W_{n} \cdot W_{n-1} \cdot \ldots \cdot W_{j}
\end{align*}$$

Für das Residualnetz:
$$\begin{align*}
h'_i &= h'_{i-1} + W_i \cdot h'_{i-1} = (I + W_i) \cdot h'_{i-1}\\
\implies \frac{\partial h'_i}{\partial h'_{i-1}} &= I + W_i\\
\implies\frac{\partial h'_{n}}{\partial h'_{l}} &= (I + W_n) \cdot (I + W_{n-1}) \cdot \ldots \cdot (I + W_{l+1})
\end{align*}$$

Vergleich:

Bei tiefen Netzwerken kann das Produkt der Gewichtsmatrizen dazu führen, dass Gradienten sehr klein werden (vanishing gradients). Bei Residualnetzen hingegen addieren wir die Identitätsmatrix, was den Gradientenfluss verbessert und das Vanishing Gradient Problem reduziert.
Analog kann das Produkt der Gewichtsmatrizen bei tiefen Netzwerken zu sehr großen Gradienten führen (exploding gradients). Residualnetze helfen, dies zu mildern, indem die Identitätsmatrix hinzugefügt wird, was die Größe der Gradienten kontrolliert.

## c)

### 1.

$$
P = \{P(0) = 0.1, \; P(1) = 0.2, \; P(2) = 0.25, \; P(3) = 0.25, \; P(4) = 0.15, \; P(5) = 0.05\}
$$

$$
Q = \{Q(0) = 0.05, \; Q(1) = 0.1, \; Q(2) = 0.15, \; Q(3) = 0.25, \; Q(4) = 0.25, \; Q(5) = 0.2\}
$$

Die KLD wird für jede Kategorie $i$ berechnet:

 $i = 0$:
$$
P(0) = 0.1, \quad Q(0) = 0.05
$$
$$
P(0) \log \frac{P(0)}{Q(0)} = 0.1 \log \frac{0.1}{0.05} = 0.1 \log 2
$$

 $i = 1$:
$$
P(1) = 0.2, \quad Q(1) = 0.1
$$
$$
P(1) \log \frac{P(1)}{Q(1)} = 0.2 \log \frac{0.2}{0.1} = 0.2 \log 2
$$

 $i = 2$:
$$
P(2) = 0.25, \quad Q(2) = 0.15
$$
$$
P(2) \log \frac{P(2)}{Q(2)} = 0.25 \log \left(\frac{25}{15}\right) = 0.25 \log \left(\frac{5}{3}\right)
$$

 $i = 3$:
$$
P(3) = 0.25, \quad Q(3) = 0.25
$$
$$
P(3) \log \frac{P(3)}{Q(3)} = 0.25 \log \frac{0.25}{0.25} = 0.25 \log 1 = 0
$$

 $i = 4$:
$$
P(4) = 0.15, \quad Q(4) = 0.25
$$
$$
P(4) \log \frac{P(4)}{Q(4)} = 0.15 \log \left(\frac{15}{25}\right) = 0.15 \log \left(\frac{3}{5}\right)
$$

 $i = 5$:
$$
P(5) = 0.05, \quad Q(5) = 0.2
$$
$$
P(5) \log \frac{P(5)}{Q(5)} = 0.05 \log \left(\frac{5}{20}\right) = 0.05 \log \left(\frac{1}{4}\right)
$$

sum:
$$
D_{KL}(P \| Q) = 0.1 \log 2 + 0.2 \log 2 + 0.25 \log \left(\frac{5}{3}\right) + 0.15 \log \left(\frac{3}{5}\right) + 0.05 \log \left(\frac{1}{4}\right)$$
$$
D_{KL}(P \| Q) = 0.0301 + 0.0602 + 0.05545 - 0.03327 - 0.030105 = 0.082375
$$

Die Kullback-Leibler-Divergenz zwischen den beiden Verteilungen $P$ und $Q$ beträgt etwa 0.0824.


### 2.

Die KLD ist nicht symmetrisch, z.b. :
    $$
    P = \left( \frac{1}{2}, \frac{1}{2} \right), \quad Q = \left( \frac{1}{4}, \frac{3}{4} \right)
    $$
 KLDs:
$$
\begin{align*}
D_{KL}(P \| Q) &= \frac{1}{2} \log \frac{\frac{1}{2}}{\frac{1}{4}} + \frac{1}{2} \log \frac{\frac{1}{2}}{\frac{3}{4}}\\
&= \frac{1}{2} \log 2 + \frac{1}{2} \log \frac{2}{3}\\
&= \frac{1}{2} (\log 2 + \log \frac{2}{3})\\
&= \frac{1}{2} \log \frac{4}{3}
\end{align*}
$$
$$
\begin{align}
D_{KL}(Q \| P) &= \frac{1}{4} \log \frac{\frac{1}{4}}{\frac{1}{2}} + \frac{3}{4} \log \frac{\frac{3}{4}}{\frac{1}{2}} \\
 &= \frac{1}{4} \log \frac{1}{2} + \frac{3}{4} \log \frac{3}{2}\\
 &= \frac{1}{4} (-\log 2) + \frac{3}{4} (\log 1.5)\\
 &= -\frac{1}{4} \log 2 + \frac{3}{4} \log 1.5
\end{align}
$$

Die Kullback-Leibler-Divergenz ist keine Metrik, da die Symmetrie nicht erfüllt ist.

## d)

Beweis:

Die Dichtefunktionen sind:
$$
f(h \mid \mu_1, \Sigma_1) = \frac{1}{(2\pi)^{n/2} \det(\Sigma_1)^{1/2}} \exp \left( -\frac{1}{2} (h - \mu_1)^T \Sigma_1^{-1} (h - \mu_1) \right)
$$
$$
f(h \mid 0, I) = \frac{1}{(2\pi)^{n/2}} \exp \left( -\frac{1}{2} h^T h \right)
$$

dazu ist:
$$
\log f(h \mid \mu_1, \Sigma_1) = -\frac{n}{2} \log(2\pi) - \frac{1}{2} \log \det(\Sigma_1) - \frac{1}{2} (h - \mu_1)^T \Sigma_1^{-1} (h - \mu_1)
$$
$$
\log f(h \mid 0, I) = -\frac{n}{2} \log(2\pi) - \frac{1}{2} h^T h
$$


$$
\log \frac{f(h \mid \mu_1, \Sigma_1)}{f(h \mid 0, I)} = -\frac{1}{2} \log \det(\Sigma_1) - \frac{1}{2} (h - \mu_1)^T \Sigma_1^{-1} (h - \mu_1) + \frac{1}{2} h^T h
$$

Erwartungswert

$$
\mathbb{E}_{P} \left[ -\frac{1}{2} \log \det(\Sigma_1) - \frac{1}{2} (h - \mu_1)^T \Sigma_1^{-1} (h - \mu_1) + \frac{1}{2} h^T h \right]
$$

Da $\log \det(\Sigma_1)$ eine Konstante ist:
$$
-\frac{1}{2} \log \det(\Sigma_1)
$$

verwenden wir den Hinweis:
$$
\mathbb{E}_{P}[(h - \mu_1)^T \Sigma_1^{-1} (h - \mu_1)] = \mathbb{E}_{P}[h]^T \Sigma_1^{-1} \mathbb{E}_{P}[h] + \text{tr}(\Sigma_1^{-1} \Sigma_1) = \mu_1^T \Sigma_1^{-1} \mu_1 + n
$$

Da $\Sigma_1$ diagonal ist:
$$
\mu_1^T \Sigma_1^{-1} \mu_1 = \sum_i \frac{\mu_i^2}{\sigma_i^2}
$$
$$
\text{tr}(\Sigma_1^{-1} \Sigma_1) = n
$$

Für  $\mathbb{E}_{P}[h^T h]$:
$$
\mathbb{E}_{P}[h^T h] = \mathbb{E}_{P}[(h - \mu_1 + \mu_1)^T (h - \mu_1 + \mu_1)] = \mathbb{E}_{P}[(h - \mu_1)^T (h - \mu_1)] + \mathbb{E}_{P}[\mu_1^T (h - \mu_1)] + \mathbb{E}_{P}[(h - \mu_1)^T \mu_1] + \mu_1^T \mu_1
$$
Da $\mathbb{E}_{P}[h - \mu_1] = 0$:
$$
\mathbb{E}_{P}[h^T h] = \text{tr}(\Sigma_1) + \mu_1^T \mu_1 = \sum_i \sigma_i^2 + \sum_i \mu_i^2
$$

Zusammen:

$$
D_{KL}(N(\mu_1, \text{diag}(\sigma_1^2, \ldots, \sigma_n^2)) \| N(0, I)) = \frac{1}{2} \left[ - \log \det(\Sigma_1) + \sum_i \sigma_i^2 + \sum_i \mu_i^2 - n \right]
$$

Da $\log \det(\Sigma_1) = \sum_i \log(\sigma_i^2)$:

$$
D_{KL}(N(\mu_1, \text{diag}(\sigma_1^2, \ldots, \sigma_n^2)) \| N(0, I)) = \frac{1}{2} \left[ - \sum_i \log(\sigma_i^2) + \sum_i \sigma_i^2 + \sum_i \mu_i^2 - n \right]
$$

Da $-n = - \sum_i 1$:

$$
D_{KL}(N(\mu_1, \text{diag}(\sigma_1^2, \ldots, \sigma_n^2)) \| N(0, I)) = \frac{1}{2} \left[ - \sum_i (\log(\sigma_i^2) + 1) + \sum_i \sigma_i^2 + \sum_i \mu_i^2 \right]
$$

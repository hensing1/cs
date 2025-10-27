[[07segmentation2_WS2425_slides.pdf]]

# Rauschreduzierung mit Markov Random Fields

Situation: 
- diskrete Intensitätswerte
- manche Pixel haben zufällig ihre Intensitätswerte geändert
- *unverrauschtes Bild hat weniger Intensitätsübergänge*

Beobachtung $x$, gesuchtes Original $w$

> [!abstract] Definition *Markov Random Field*
> - Menge von **Orten** *(sites)* $\mathcal{S}=\set{1,\ldots,N}$
> - Pro Ort $n$:
> 	- **Zufallsvariable** $w_{n}$
> 	- Menge von **Nachbarn** $\mathcal{N_{n}}$
> 
> Zudem muss die *Markov-Eigenschaft* erfüllt sein: $$P(w_{n}\mid w_{\mathcal{S}\setminus n})=P(w_{n}\mid w_{N_{n}})$$

D.h. die Variable $w_{n}$ hängt in einem Markov Random Field ausschließlich von den Nachbarn $\mathcal{N}_{n}$ ab.

In diesem Fall ist:
- jeder Pixel ein Ort $n$
- $w_{n}$ das Label von $n$
- $\mathcal{N}_{n}$ die 4-Nachbarschaft von $n$

Einen **Prior**, d.h. ein $P(w)$ unabhängig von bekannten Pixelwerten, modellieren wir jetzt als MRF. Wir sagen: die Wahrscheinlichkeit eines Labels $w$ ist das Produkt der Wahrscheinlichkeiten aller Konfigurationen, in denen das entsprechende Pixel enthalten ist. Eine Konfiguration sind hierbei bloß zwei benachbarte Pixel.
Der Prior ist also:
$$\begin{align}
P(w) &= \frac{1}{Z}\prod_{j=1}^{J}\phi_{j}[w_{\mathcal{C}_j}]\\
&= \frac{1}{Z}\exp\left[-\sum_{j=1}^{J}-\log[\phi_{j}[w_{\mathcal{C}_j}]]\right] \\
&= \frac{1}{Z}\exp\left[-\sum_{j=1}^{J}\psi_{j}[w_{\mathcal{C}_j}]\right] \\
\end{align}$$
wobei:
- $\mathcal{C}$ eine [[Graphen#^961695|Clique]], hier: nur eine Kante
- $J$ die Anzahl aller Cliquen, in der das Pixel enthalten ist
- $w_\mathcal{C}$ die Variablen dieser Clique
- $\phi(w_\mathcal{C})\geq 0$ eine Potentialfunktion abhängig von den Variablenwerten (W'keit einer Labelkonfiguration)
- $\psi[\bullet] = -\log[\phi[\bullet]] \in \mathbb{R}$ (Kosten einer Labelkonfiguration)
- $Z$ eine Normalisierungskonstante
Wir formen das ganze um, damit wir mit einer Summe statt mit einem Produkt rechnen können.

Wir können für $\phi$ nun irgendwelche Gewichtungen für Labelkonfigurationen festlegen, z.B. können gleiche Labels wahrscheinlicher sein als verschiedene Labels -> unverrauschtere Bilder werden bevorzugt

Problem: Normalisierungskonstante ist sehr schwer zu Berechnen

Nur mit Prior (maximum Likelihood-Schätzung, $\arg\max_{w}\prod_{i}P(x_{i}\mid w$): kein Denoising; verrauschtes Bild (als Original) hat höchste Wahrscheinlichkeit, die verrauschte Beobachtung hervorgerufen zu haben (unter der Annahme, dass Änderung unwahrscheinlicher ist als keine Änderung).

Wir möchten stattdessen den maximalen Posterior $P(w \mid x)$ berechnen: gegeben Messung $x$, welcher Ground Truth $w$ ist am wahrscheinlichsten?
Dafür brauchen wir nach Bayes unseren Prior (MRF, s.o.) und die Likelihood (gegeben $w$, welche Messung machen wir wahrscheinlich).

Maximum A Posteriori: $P(w \mid x)$
$$\begin{align*}
\hat w &= \arg\max_{w}[P(w \mid x_{1\ldots I})]\\
&= \arg\max_{w}\left[\frac{P(x_{1\ldots I}\mid w)P(w)}{P(x_{1\ldots I})}\right]\\
&= \arg\max_{w}\left[\frac{\prod_{i=1}^{I}P(x_{i}\mid w)P(w)}{P(x_{1\ldots I})}\right] & \text{(Annahme der Unabhängigkeit)}\\
&= \arg\max_{w}\left[\prod_{i=1}^{I}P(x_{i}\mid w)P(w)\right] & \text{(Normalisierung ist egal)}
\end{align*}$$
Können wir $\hat w$ berechnen, haben wir tatsächlich ein unverrauschtes Bild.

## Binärbilder
*Modellierung der Likelihood*
Hat man nur zwei Label, können wir bei gegebenem $w$ unser Problem als [[Bernoulli-Verteilung]] modellieren:
- $P(x\mid w=\text{weiß}) = \text{Bern}_{x}[\rho]$
- $P(x\mid w=\text{schwarz}) = \text{Bern}_{x}[1-\rho]$

Wir schreiben $\rho$ für die Wahrscheinlichkeit, dass das Label beim Verrauschen vertauscht wird.

*Lösen von MAP*
Wir stellen fest: die Likelihood $P(x|w)$ hängt nur von einem einzelnen Pixel hab (ist also *unär*), während der Prior sich aus Pixelpaaren zusammensetzt (*paarweise*). 
Wir können also unseren Posterior als Summe von unären Termen $U$ und paarweisen Termen $P$ ausdrücken:
$$
\begin{align}
\hat{w}_{1\dots N}&=\arg\max_{w_{1\dots n}} [P(w_{1\dots N} \mid x_{1\dots N})] \\
&= \arg \max_{w_{1\dots n}} \left[\prod_{n=1}^N P(x_{n} \mid w_{n})P(w_{1\dots N})\right] \\
&= \arg \max_{w_{1\dots n}} \left[\sum_{n=1}^N \log [P(x_{n} \mid w_{n})] + \log[P(w_{1\dots N})]\right] \\
&= \arg \max_{w_{1\dots n}} \left[\sum_{n=1}^N \log[P(x_{n} \mid w_{n})] - \sum_{(m,n) \in C} \psi[w_{m},w_{n}, \theta]\right] \\
&= \arg \min_{w_{1\dots n}} \left[\sum_{n=1}^N -\log[P(x_{n} \mid w_{n})] + \sum_{(m,n) \in C} \psi[w_{m},w_{n}, \theta]\right] \\
&= \arg \min_{w_{1\dots n}} \left[\sum_{n=1}^N U_{n}(w_{n}) + \sum_{(m,n) \in C}P_{m,n}(w_{m},w_{n})\right] \\
\end{align}
$$

Das ist praktisch, denn jetzt können wir unsere Optimierung als [[Flussprobleme|Flussproblem]] modellieren:
- Jeder Pixel erhält einen Knoten
- Nachbarpixel sind in beide Richtungen mit Kanten verbunden
- Jeder Pixelknoten hat eine Kante von Quelle $s$ und zur Senke $t$
- *Jeder Knoten, der von der Quelle getrennt wurde, enthält das Label $0$, und jeder der von der Senke getrennt wurde das Label $1$.*

![[MAP-Flussproblem.png|400]]

### Kantengewichtung: Nulldiagonale
Damit das Flussproblem dieselbe Lösung wie MAP hat, müssen die Kanten die unären und paarweisen Terme (s.o.) als Gewichtung erhalten:
![[MAP-Kantengewichtung_1.png|250]]

Hierbei wird zunächst die Annahme gemacht, dass $P_{mn}(0,0) = P_{mn}(1,1) = 0$.

Wird z.B. $a=0,b=1,c=1$ zugewiesen, werden die Kanten $\overline{sa}, \overline{ba},\overline{bt},\overline{ct}$ durchtrennt und es entstehen Kosten $U_{a}(0)+P_{ab}(0,1)+U_{b}(1)+U_{c}(1)$.

### Kantengewichte: allgemein (Submodularität)

Generell können wir allgemeine paarweise Kosten haben:
$$
\begin{align}
P_{mn}(0,0)&=\theta_{00} & P_{mn}(1,0)&=\theta_{10} \\
P_{mn}(0,1)&=\theta_{01} & P_{mn}(1,1)&=\theta_{11}
\end{align}
$$

Die extra Kantengewichte $P(0,0)$ und $P(1,1)$ bauen wir wie folgt ein:
![[MAP-Kantengewichtung_2.png|250]]

Für ein Flussproblem dürfen die Kantengewichte nicht negativ werden, was hierbei mit der Kante $\overline{ab}$ problematisch werden kann.
Wir können zumindest den Graphen reparametrisieren, sodass jede Lösung um eine Konstante $\beta$ größer wird (und somit die optimale Lösung identisch bleibt):
![[MAP-Kantengewichte_3.png|250]]

Damit erhalten wir
$$
\begin{align}
\theta_{10}-\theta_{11}-\theta_{00}-\beta &\geq 0 \\
\theta_{01}+\beta  & \geq 0
\end{align}
$$

und zusammengenommen:
> **Submodularität (binär)**
> $$\theta_{10}+\theta_{01}-\theta_{11}-\theta_{00}\geq 0$$
> Ist diese Gleichung erfüllt, heißt unser MRF *submodular* und kann in Polynomialzeit gelöst werden.
> Falls nicht, ist das Problem NP-schwer.

Normalerweise sind wir in der Bildverarbeitung submodular, weil wir gleichmäßige Lösungen bevorzugen (höhere Kosten für Übergänge $\theta_{10},\theta_{01}$, geringere Kosten für gleichbleibende Pixelwerte $\theta_{11},\theta_{00}$).

## Multilabel-Bilder

Haben wir $k$ mögliche Label pro Pixel, erweitern wir unseren Graphen auf $k+1$ Knoten pro Pixel.
Ein Pixel erhält nun das Label $l$, wenn die ersten $l$ Knoten noch mit der Quelle verbunden sind, aber der Knoten $l+1$ nicht mehr.

Für ein Pixel $a$ erhalten:
- die Kanten $\overline{a_{i}a_{i+1}}$ die Unären Kosten $U_{a}(i)$,
- die Kanten $\overline{sa_{1}}$ und $\overline{a_{k}t}$, sowie die Aufwärtskanten $\overline{a_{i}a_{i-1}}$ das Gewicht $\infty$, sodass diese niemals durchtrennt werden.

Zwischen zwei Pixelknoten $a_{i},b_{j}$ hat eine Kante die Kosten $$C_{ab}(i,j)=P_{ab}(i,j-1)+P_{ab}(i-1,j)-P_{ab}(i,j)-P_{ab}(i-1,j-1)$$
Merke: dieselbe Struktur wie bei der Submodularität oben.

Damit ergeben sich für Label $I,J$ die Kosten: $$\sum_{i=1}^I \sum_{j=J+1}^{K+1}C_{ab}(i,j)$$
Beispiel:
![[MRF-Multilabel_1.png|250]]

Wir können die Anzahl der Kanten reduzieren, indem wir feststellen, dass z.B. für $a=1$ immer die Kante $C_{ab}(1,5)$ geschnitten wird (egal welcher Wert für $b$), weswegen wir das Gewicht auch zum Unary-Term $U_{a}(1)$ hinzufügen können:
![[MRF-Multilabel_2.png|300]]

> **Submodularität (Multilabel)**
> Aus
> $$P_{ab}(i,j-1)+P_{ab}(i-1,j)-P_{ab}(i,j)-P_{ab}(i-1,j-1) \geq 0$$
> folgt für $\beta > \alpha$ und $\delta > \gamma$: $$P_{ab}(\beta, \gamma) + P_{ab}(\alpha, \delta), - P_{ab}(\beta, \delta) - P_{ab}(\alpha, \gamma) \geq 0.$$

Nun gibt es verschiedene Modelle, um paarweise Kosten für zwei Label $w_{m},w_{n}$ zu definieren:
![[Paarweise_Kosten.png|500]]

Problem: nur das quadratische ist submodular, und dies verursacht verschwommene Kanten:
![[verschwommen.png|400]]

### Approximierung: Alpha Expansion

Wenn wir z.B. mit dem Potts-Modell arbeiten $\left(P(\alpha, \beta)= \begin{cases}0 & \text{falls } \alpha=\beta \\ \kappa & \text{sonst}\end{cases} \right)$, brauchen wir eine Approximierung, weil unser Problem NP-schwer ist.

Ansatz: optimiere ein Label $\alpha$ nach dem anderen, in dem es expandiert wird (ein Pixel erhält entweder das Label $\alpha$ oder es bleibt so). Das wiederholt man so oft, bis keine Veränderungen mehr passieren (lokales Optimum).
Jede Iteration ist also ein binäres Problem, welches wir exakt lösen können.
Man kann zeigen, dass das eine 2-Approximierung ist, und häufig verhält sich das noch besser.

Einzige Voraussetzung: die paarweisen Kosten bilden eine [[Glossar#Metrik|Metrik]].

Konstruktion:
![[Alpha-Expansion.png|550]]

- Falls Nachbarpixel $\alpha,\alpha$
	- keine paarweisen Kosten -> keine Kante
- Falls Nachbarpixel $\alpha,\beta$
	- Falls $\beta$ zu $\alpha$ wird, keine Kosten -> keine Kante
	- Falls es so bleibt, Kosten $P(\alpha,\beta)$
- Falls Nachbarpixel $\beta,\beta$
	- Falls Resultat $\alpha,\alpha$ oder $\beta,\beta$, keine Kosten
	- Falls unterschiedlich, Kosten $P(\alpha,\beta)$ bzw. $P(\beta,\alpha)$
- Fals Nachbarpixel $\beta,\gamma$
	- Falls es so bleibt, Kosten $P(\beta,\gamma)$ (neuer Knoten eingefügt)
	- Falls $\alpha,\gamma$: $P(\alpha,\gamma)$
	- Falls $\beta,\alpha$: $P(\beta,\alpha)$
	- Falls beides $\alpha$: keine Kosten


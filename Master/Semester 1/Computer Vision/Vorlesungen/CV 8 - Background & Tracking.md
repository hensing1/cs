[[08background_WS2425_slides.pdf]]

# Erkennung von Hintergründen

*Anwendung:* Grab cut (Nutzer wählt groben Umriss eines Objektes aus, Objekt wird segmentiert)

Die Inferenz ist wie folgt:
- $w$ ist unser Label (hier: Vorder- und Hintergrund)
- $x$ sind unsere Daten
Satz von Bayes: $$P(w_{1,\ldots,N} \mid x_{1,\ldots,N}) = \frac{\prod_{n}P(x_{n} \mid w_{n}) P(w_{1,\ldots,N})}{P(x_{1,\ldots,N})}$$
$P(w)$ (der Prior) ist wieder ein [[CV 7 - Markov Random Fields|Markov Random Field]].
$P(x \mid w)$ (die Likelihood) ist dieses mal ein *Gaussian Mixture Model*.

Der Grab Cut passiert via Iteration:
- eine Vordergrund-Region wird grob angegeben
- Farbverteilung zwischen Vorder- und Hintergrund wird durch GMM gelernt
- Graph Cut inferiert eine neue Segmentierung

##  Gaussian Mixture Models

*Annahme:* die Punktwoken unserer Vordergrund- bzw. Hintergrundpixel können jeweils als Summe verschiedener Gauß-Kurven modelliert werden: $$\large P(x_{n} \mid w=j) = \sum_{k=1}^{K}\lambda_{jk}\,\text{Gauß}_{\mu_{jk},\Sigma_{jk}}(x_n),$$
wobei:
- $j$ Label für Vorder- bzw. Hintergrund
- $\lambda$ Gewichtung der Gauß-Kurve, $\sum_{k}\lambda_{k}=1$
- $\mu$ Mittelwert
- $\Sigma$ Kovarianzmatrix
- $K$ Hyperparameter für die Anzahl der Gauß-Kurven

Wir führen eine verborgene Variable $h \in \set{1,\ldots,k}$ für die einzelnen Gauß-Kurven ein, über die wir [[Wahrscheinlichkeitsrechnung#^70b256|marginalisieren]].

$$\begin{align}P(x \mid \theta) &= \sum_{k=1}^{K}P(x,h=k \mid\theta) \\
&= \sum_{k=1}^{K}P(x \mid h=k,\theta)\cdot P(h=k \mid \theta)\\
&= \sum_{k=1}^{K}\lambda_k\, \text{Gauss}_{\mu_{k},\Sigma_{k}}(x).
\end{align}$$

$P(h_{k} \mid \theta)$ ist genau die Gewichtung $\lambda_{k}$.
$\theta$ sind die Parameter für die Gauß-Kurven.

## Expectation Maximization-Algorithmus
Algorithmus zur Bestimmung des GMM, gegeben eine Punktwolke (Samples von unserem GMM).

Starte initial mit $\lambda$ uniform, $\Sigma$ Einheitsmatrix, $\mu$ z.B. durch $k$-means.

Zwei Schritte werden iteriert:
- *Expectation* (E)
	- Gegeben unsere bisher angenommenen Gaussians (mit Parametern $\theta^{[t]}$) und einen Punkt $x_{i}$, was ist die Wahrscheinlichkeit, dass dieser Punkt durch die $k$-te Gaußkurve gesampelt wurde? $$P(h_{i}=k \mid x_{i}, \theta^{[t]}) = \frac{\lambda_{k}\text{Gauß}_{\mu_{k}\Sigma_{k}}(x_{i})}{\sum_{j=1}^{K}\lambda_{j}\text{Gauß}_{\mu_{j},\Sigma_{j}}(x_{i})}=r_{ik}$$
	- Allgemeine Gleichung: $$\hat{q}_{i}(h_{i}) = P(h_{i} \mid x_{i}, \theta^{[t]})=\frac{P(x_{i} \mid h_{i}, \theta^{[t]})P(h_{i} \mid \theta^{[t]})}{P(x_{i})}$$
		- $\hat{q}$ ist die Wahrscheinlichkeitsverteilung über alle Datenpunkte.
		- Der Rest ist einfach der Satz von Bayes.
	- Der Wert $r_{ik}$ kann nun als *Gewichtung* verstanden werden: um die Gaussian $k$ zu updaten, wieviel trägt der Punkt $i$ dazu bei?
	- $\sum_{k}r_{ik}=1.$

- *Maximization* (M)
	- Erstelle neue Gauß-Kurven auf Grundlage der im E-Schritt gewichteten Punkte: $$\begin{align*}
\hat\theta^{[t+1]}&= \arg\max_\theta\left[\sum_{i}\sum_{k}r_{ik}\log[P(x_{i},h_{i}=k \mid \theta^{[t]}]\right]\\
&= \arg\max_\theta\left[\sum_{i}\sum_{k}r_{ik}\log[\lambda_{k} \text{Gauß}_{\mu_{k}, \Sigma_{k}}(x_{i})]\right]
\end{align*}$$
	- Konkret: $$\begin{align*}
\lambda_{k}^{[t+1]} &= \frac{\sum_{i}r_{ik}}{\sum_{j=1}^{K}\sum_{i}r_{ij}} & \text{Anteil der Gauß-Gewichtungen}\\
\mu_{k}^{[t+1]} &= \frac{\sum_{i}r_{ik}x_{i}}{\sum_{i}r_{ik}} & \text{Mittelwert von gewichteten }x\\
\Sigma_{k}^{[t+1]} &= \frac{\sum_{i}r_{ik}(x_{i}-\mu_{k}^{[t+1]})(x_{i}-\mu_{k}^{[t+1]})^{t}}{\sum_{i}r_{ik}} & \text{Varianz von gewichteten }x
\end{align*}$$

*Noch allgemeiner: was machen die E- und M-Schritte?*
E-Step: maximiert den Lower Bound 
# DLVC - Übungsblatt 4

- Jiawei Mao, s6jimaoo
- Henning Lehmann, s88jlehm

## a)

### 1.

$$\begin{align*}
\text{Bias}(\hat \theta_{m})^{2} + \text{Var}(\hat \theta_{m}) &\stackrel{\text{def.}}= (\mathbb{E}[\hat \theta_{m}]- \theta)^{2}+\mathbb{E}[\hat \theta_{m}^{2}]-\mathbb{E}[\hat \theta_{m}]^{2}\\
&= \mathbb{E}[\hat \theta_{m}]^{2}-2\mathbb{E}[\hat \theta_{m}]\theta+\theta^{2}+\mathbb{E}[\hat \theta_{m}^{2}]-\mathbb{E}[\hat \theta_{m}]^{2}\\
&= \mathbb{E}[\hat \theta_{m}^{2}]-2\mathbb{E}[\hat \theta_{m}]\theta + \theta^{2}\\
&\stackrel{\mathbb{E}\text{ ist linear}}=  \mathbb{E}[\hat \theta_{m}^{2}]-\mathbb{E}[2\hat \theta_{m}\theta] + \theta^{2}\\
&\stackrel{\theta \text{ ist konstant}}= \mathbb{E}[\hat \theta_{m}^{2}]-\mathbb{E}[2\hat \theta_{m}\theta] + \mathbb{E}[\theta^{2}]\\
&\stackrel{\mathbb{E} \text{ ist linear}}= \mathbb{E}[\hat \theta_{m}^{2}-2\hat \theta_{m}\theta+\theta^{2}]\\
&= \mathbb{E}[(\hat \theta_{m}-\theta)^{2}]\\
&\stackrel{\text{def.}}=\text{MSE}(\hat \theta_{m}).
\end{align*}$$
### 2.

Die fehlende Generalisierung kann aufgrund von Overfitting oder Underfitting passieren.

Ein Grund für Underfitting kann eine zu geringe Modellkapazität sein, dh. wir haben nicht genügend Parameter in $\theta$, um den zugrundeliegenden Sachverhalt zu erfassen. In diesem Fall ist der Bias im Allgemeinen zu hoch, weil das Modell bereits nicht in der Lage ist, die Trainingsdaten gut zu fitten. 
Da das Modell als Ganzes weniger komplex ist, ist die Varianz niedrig.

Eine zu hohe Modellkapazität führt hingegen zu Overfitting: das Modell versucht, die Trainingsdaten möglichst gut zu fitten (inkl. etwaigem Rauschen) und verliert dadurch an Generalisierbarkeit. Als Resultat steigt die Varianz der Ergebnisse, während der Bias gering wird.

<div style="page-break-after: always;"></div>

## b)

$$\begin{align*}
\theta_\text{MAP} &= \underset{\theta}{\operatorname{argmax}} p(\theta|X,Y)\\
&= \underset{\theta}{\operatorname{argmax}} p(\theta|X\land Y)\\
&= \underset{\theta}{\operatorname{argmax}} \frac{p(\theta\land X \land Y)}{p(X\land Y)}\\
&= \underset{\theta}{\operatorname{argmax}} p(\theta\land X \land Y) & (\text{X und Y unabhängig von }\theta)\\
&= \underset{\theta}{\operatorname{argmax}} p(Y |X, \theta) p(X,\theta)\\
&= \underset{\theta}{\operatorname{argmax}} p(Y|X,\theta)p(X)p(\theta) & X,\,\theta\,\text{unabhängig}\\
&= \underset{\theta}{\operatorname{argmax}} p(Y|X,\theta)p(\theta)\\
&= \underset{\theta}{\operatorname{argmax}} \log[p(Y|X,\theta)p(\theta)]\\
&= \underset{\theta}{\operatorname{argmax}} \left[\log p(Y|X,\theta) + \log p(\theta)\right]\\
&= \underset{\theta}{\operatorname{argmax}} \left[\sum_{i=1}^{m}\log p(y^{(i)}|x^{(i)},\theta)+\log p(\theta)\right].
\end{align*}$$

## c)

Um zu zeigen, dass die Minimierung des Mean Squared Error (MSE) mit L2-Regularisierung äquivalent zur maximalen a-posteriori-Schätzung (MAP) mit einem Gauß-Prior für die Gewichte ist, folgen wir den gegebenen Annahmen und leiten die Beziehung her.

***Gegebene Annahmen:***

1. Wir haben i.i.d. Stichproben ($\{(x^{(i)}, y^{(i)})\}_{i=1}^m$ ).
2. Unsere Daten werden durch ein Gaußmodell $p(y | x, \theta) = \mathcal{N}(y | f(x; \theta), \sigma^2)$ beschrieben, wobei $\sigma^2$ bekannt ist.

***Schritt 1: Maximum-Likelihood (ML) Schätzung***

Die Likelihood für die gesamten Daten ist:

$$
p(\{y^{(i)}\} | \{x^{(i)}\}, \theta) = \prod_{i=1}^m p(y^{(i)} | x^{(i)}, \theta)
$$

Da die Daten normalverteilt sind:

$$
p(y^{(i)} | x^{(i)}, \theta) = \frac{1}{\sqrt{2 \pi \sigma^2}} \exp\left( -\frac{1}{2 \sigma^2} (y^{(i)} - f(x^{(i)}; \theta))^2 \right)
$$

Die Log-Likelihood ist dann:

$$
\log p(\{y^{(i)}\} | \{x^{(i)}\}, \theta) = \sum_{i=1}^m \log p(y^{(i)} | x^{(i)}, \theta)
$$

$$
= \sum_{i=1}^m \left[ -\frac{1}{2} \log(2 \pi \sigma^2) - \frac{1}{2 \sigma^2} (y^{(i)} - f(x^{(i)}; \theta))^2 \right]
$$

$$
= -\frac{m}{2} \log(2 \pi \sigma^2) - \frac{1}{2 \sigma^2} \sum_{i=1}^m (y^{(i)} - f(x^{(i)}; \theta))^2
$$

Das Maximieren der Likelihood ist äquivalent zum Minimieren des negativen Log-Likelihoods. Da der erste Term unabhängig von $\theta$ ist, maximieren wir:

$$
\text{Minimiere } \frac{1}{2 \sigma^2} \sum_{i=1}^m (y^{(i)} - f(x^{(i)}; \theta))^2
$$

Das ist äquivalent zur Minimierung des Mean Squared Error (MSE):

$$
\text{MSE}(\theta) = \frac{1}{m} \sum_{i=1}^m (y^{(i)} - f(x^{(i)}; \theta))^2
$$

***Schritt 2: MAP-Schätzung mit Gauß-Prior***

Nehmen wir an, dass wir einen Gauß-Prior für die Gewichte $\theta$ haben:

$$
p(\theta) = \mathcal{N}(\theta | 0, \tau^2 I)
$$

Das bedeutet:

$$
p(\theta) = \frac{1}{(2 \pi \tau^2)^{d/2}} \exp\left( -\frac{1}{2 \tau^2} \|\theta\|^2 \right)
$$

Die MAP-Schätzung maximiert die a-posteriori Wahrscheinlichkeit:

$$
\theta_{\text{MAP}} = \arg\max_{\theta} p(\theta | \{x^{(i)}, y^{(i)}\})
$$

$$
= \arg\max_{\theta} p(\{y^{(i)}\} | \{x^{(i)}\}, \theta) p(\theta)
$$

$$
= \arg\max_{\theta} \left( \log p(\{y^{(i)}\} | \{x^{(i)}\}, \theta) + \log p(\theta) \right)
$$

Setzen wir die Log-Likelihood und den Log-Prior ein:

$$
= \arg\max_{\theta} \left( -\frac{1}{2 \sigma^2} \sum_{i=1}^m (y^{(i)} - f(x^{(i)}; \theta))^2 - \frac{1}{2 \tau^2} \|\theta\|^2 \right)
$$

Das Minimieren des negativen Logarithmus ist äquivalent zu:

$$
\arg\min_{\theta} \left( \frac{1}{2 \sigma^2} \sum_{i=1}^m (y^{(i)} - f(x^{(i)}; \theta))^2 + \frac{1}{2 \tau^2} \|\theta\|^2 \right)
$$

***Schritt 3: Verknüpfen mit L2-Regularisierung***

Wenn wir den MSE und die L2-Regularisierung betrachten:

$$
\frac{1}{m} \sum_{i=1}^m (y^{(i)} - f(x^{(i)}; \theta))^2 + \lambda \|\theta\|^2
$$

Für geeignete Werte von $\lambda$ und $\tau$ (nämlich $\lambda = \frac{1}{2 \tau^2}$ und $\sigma^2 = \frac{1}{m}$), sehen wir, dass die beiden Optimierungsprobleme äquivalent sind.

Daher ist die Minimierung des MSE mit L2-Regularisierung äquivalent zur maximalen a-posteriori Schätzung mit einem Gauß-Prior für die Gewichte.

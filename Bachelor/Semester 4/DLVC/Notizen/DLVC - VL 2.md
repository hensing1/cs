Datum: 17.04.
[[Slides 02.pdf|Folien]]

# Learning Algorithms und Wahrscheinlichkeitstheorie

## Grundlagen Machine Learning

> **Lernender Algorithmus**
> Wir haben eine Aufgabenklasse $T$. Wenn ein Computerprogramm duch Erfahrung $E$ besser wird, $T$ auszuführen (gemessen an einem Performanzmaß $P$), sagen wir, dass das Programm von $E$ lernt.

### Probleme für Machine Learning

Die Aufgabenklasse $T$ kann wie folgt aussehen:
- **Klassifikation**
	- Bestimme die Kategorie einer Eingabe, z.B. $f: \mathbb{R}^{n} \to \set{1,\ldots,k}$.
- **Regression**
	- Sage numerische Werte vorraus, z.B. $f: \mathbb{R}^{n} \to \mathbb{R}^{m}$.
- **Dichteschätzung**
	- Lerne eine *Wahrscheinlichkeitsdichtefunktion* $p_\text{model}: \mathbb{R}^{n}\to R$.
- **Synthese**
	- Generiere neue Samples, die ähnlich zu den Trainingsdaten sind.
- **Entrauschen**
	- Erstelle entrauschtes Sample $x \in \mathbb{R}^{n}$ von korrumpiertem Sample $\tilde x \in \mathbb{R}^{n}$.
- **Lochfüllung**
	- Erstelle eine Füllung für ein Sample $x \in \mathbb{R}^{n}$ mit fehlenden Einträgen.

### Erfahrung
Die Erfahrung $E$ besteht üblicherweise aus einem *data set*, das mehrere *data points* enthält.

#### Supervised Learning
Jeder Datenpunkt $x$ im Datenset hat ein **Label** $y$. Dieses Label soll vorhergesagt werden: $$p_\text{data}(y \mid x).$$
#### Unsupervised Learning
Es gibt keine Label, stattdessen werden die Datenpunkte als Zufallsvariable modelliert und die zugrundeliegende Wahrscheinlichkeitsverteilung soll gelernt werden: $$p_\text{data}(x).$$

### Performanz
Das Performanzmaß $P$ misst die Leistung des Modells auf *bislang ungesehenen Daten*, die **Test Set** genannt werden. Die übrigen Datenpunkte bilden das **Training Set**.

### Generalisierung
Generalisierung unterscheidet Machine Learning von klassischen Optimierungsproblemen.

**Underfitting:** Das Modell hat einen großen Trainingsfehler.
**Overfitting:** Das Modell hat einen kleinen Trainingsfehler, aber einen großen Testfehler ($\to$ *generalisation gap*).

Eine zu geringe Modellkapazität (zu wenige Parameter) führt im Allgemein zu underfitting. 
Ein Modell mit zu hoher Kapazität lernt die Trainingsdaten oft auswendig und overfittet schnell.
![[Underfitting_Overfitting.png]]

**Hyperparameter:** parametrisierte Einstellung des Lernalgorithmus, z.B. Modellgröße, Learning Rate, etc.

Hyperparameter sollten *nicht* anhand der Testdaten justiert werden. Schlauer ist es, einen *validation fold* (Teilmenge der Testdaten) dafür beiseitezustellen.

*Cross validation:* optimiere Hyperparameter für verschiedene validation folds und nimm den Durchschnitt.

## Stochastik

### Grundlagen

**Grundbegriffe:**
- *Ergebnisraum* $\Omega$
	- Mögliche Resultate von Zufallsexperiment
- *Ereignis* $A \subseteq \Omega$
	- Teilmenge des Ergebnisraums
- *Sigma-Algebra* $\mathcal{A} \subseteq 2^\Omega$
	- Ereignis-System - Teilmenge der Potenzmenge von $\Omega$ - mit folgenden Eigenschaften:
		- das sichere Ereignis ist enthalten: $\Omega \in \mathcal{A}$
		- Abgeschlossenheit unter Komplementbildung: $A \in \mathcal{A} \Rightarrow \Omega\setminus A \in \mathcal{A}$
		- Abgeschlossenheit unter Vereinigung: $A_{1}, A_{2}, \ldots \in \mathcal{A} \Rightarrow \bigcup_{i} A_{i} \in \mathcal{A}$.
- *Messraum* $(\Omega, \mathcal{A})$
	- $\Omega$ ist ein Ergebnisraum
	- $\mathcal{A}$ ist dazugehörige Sigma-Algebra

**Zufallsvariable:**
Seien $(\Omega, \mathcal{A})$ und $(\Omega', \mathcal{A}')$ Messräume. 

Die Abbildung $X: \Omega \to \Omega'$ heißt Zufallsvariable, wenn: $$\forall A' \in \mathcal{A}': X^{-1}[A'] \in \mathcal{A}.$$
Es gibt also zu jedem Ereignis $A'$ ein passendes Ereignis $X^{-1}[A']$.
Die Zielmenge $\Omega'$ ist oft eine Zahlenmenge.

Der Sinn einer Zufallsvariablen ist es, Aussagen über z.B. Erwartungswert und Varianz zu treffen, wenn dies ad hoc mit Ereignissen aus $\Omega$ nicht geht.

**Wahrscheinlichkeits(-dichte-)funktion:** Wahrscheinlichkeit eines Resultats
Falls $\Omega$ diskret ist: $$P: \Omega \to [0,1] \text{ mit }\sum_{\omega\in\Omega}p(\omega)=1$$
Falls $\Omega$ kontinuierlich ist: $$P: \Omega \to [0,\infty) \text{ mit } \int p(\omega)\,d \omega=1$$
**Wahrscheinlichkeitsverteilung:** Wahrscheinlichkeit eines Ereignisses
$$P: \mathcal{A} \to [0,1]$$
$P$ ist normiert, d.h. $P(\Omega)=1$, und es gilt *$\sigma$-Additivität:* für paarweise disjunkte Ereignisse ist $P(\sqcup A_{i})=\sum P(A_{i})$.

Eine Wahrscheinlichkeitsfunktion $p$ eines diskreten Ergebnisraums $\Omega$ kann man leicht in eine Wahrscheinlichkeitsverteilung machen: $\forall A \in \mathcal{A} : P(A) = \sum_{\omega\in A}p(\omega)$.

### Multivariate Wahrscheinlichkeit

$p(x,y)$ ist die Wahrscheinlichkeit, dass zwei Ereignisse $x \in X$ und $y \in Y$ gemeinsam auftreten. $X$ und $Y$ können jeweils kontinuiertlich oder diskret sein.

*Marginalisierung:*
Falls $Y$ diskret: $p(x) = \sum_{y}p(x,y)$

Falls $Y$ kontinuierlich: $p(y) = \int p(x,y)\,dy$.

Bedingte Wahrscheinlichkeit: $p(x \mid y=y ^{\ast}) \Large = \frac{p(x,y=y ^{\ast})}{\int p(x,y=y ^{\ast})\,dx} = \frac{p(x,y=y ^{\ast})}{p(y=y ^{\ast})}$
Oder kompakt: $$\begin{align*}
p(x \mid y) &= \frac{p(x,y)}{p(y)}\\
\iff p(x,y) &= p(x \mid y) \cdot p(y) = p(y \mid x) \cdot p(x)
\end{align*}$$
![[Bedingte_Wahrscheinlichkeit.png|400]]

*Unabhängigkeit:*
Sind zwei Variablen $x,y$ unabhängig, ist $p(x \mid y) = p(x)$. Demnach ist $p(x,y) = p(x)p(y)$.
Daten $x_{1},x_{2},x_{3},\ldots$ werden *unabhängig und identisch verteilt (u.i.v., independent and identical distributed (i.i.d.))* gemessen, wenn sie unabhängig voneinander aus der gleichen Verteilung gezogen werden. Dann ist $p(x_{1},x_{2},x_{3},\ldots)=p(x_{1})p(x_{2})p(x_{3})\ldots = \prod_{i}p(x_{i})$ (Ziehen mit Zurücklegen).

> [!important] Satz von Bayes
> Bedingte Wahrscheinlichkeiten können mithilfe der umgekerten Bedingung bestimmt werden: $$\begin{align*}p(y \mid x) &= \frac{p(x \mid y)p(y)}{p(x)}\\&=\frac{p(x \mid y) p(y)}{\int p(x,y)\,dy}\\&=\frac{p(x \mid y)p(y)}{\int p(x \mid y)p(y)\,dy}\end{align*}$$
> Dabei heißt:
> - $p(y \mid x)$ *Posterior* (was wir über die Verteilung von $y$ wissen, nachdem wir $x$ gesehen haben)
> - $p(x \mid y)$ *Likelihood* (Wahrscheinlichkeit für Wert von $x$ gegeben Wert von $y$)
> - $p(y)$ *Prior* (was wir über $y$ wissen, bevor wir $x$ gesehen haben)
> - $\int p(x \mid y)p(y)\,dy$ *Evidenz* (Normierungskonstante)

### Erwartungswert und Varianz

> [!abstract] Definition *Erwartungswert*
> Mittelwert einer Funktion $f(x)$ unter Berücksichtigung einer Verteilung $p(x)$.
> 
> Im Diskreten: $$\mathbb{E}[f(x)] = \sum_{x}f(x)p(x)$$
> Im Kontinuierlichen: $$\mathbb{E}[f(x)]=\int f(x)p(x)\,dx$$

> [!abstract] Definition *Bias*
> Der Bias gibt an, wie weit der Erwartungswert eines Punktschätzers $\hat \theta_{m}$ vom wahren Parameter $\theta$ abweicht: $$\text{Bias}(\hat \theta_{m}) = \mathbb{E}[\hat \theta_{m}]-\theta.$$

> [!abstract] Definition *Varianz* und *Standardabweichung*
> Die Varianz ist die erwartete quadrierte Abweichung zum Mittelwert einer Funktion $f(x)$ unter der Berücksichtigung einer Verteilung $p(x)$:$$\begin{align*}\\
Var(f(x)) &= \mathbb{E}[f(x)-\mathbb{E}[f(x)]^{2}]\\
&=\mathbb{E}[f(x)^{2}]-\mathbb{E}[f(x)]^{2}
\end{align*}$$
> Die Standardabweichung ist die Quadratwurzel der Varianz und hat dieselbe Einheit wie die Zufallsvariable $x$.

^799858

### Shannon-Entropie

Shannon-Entropie $H(p)$: was ist die geringste durchschnittliche Anzahl an Bits, um Samples aus einer Wahrscheinlichkeitsfunktion $p$ zu beschreiben?
$$H(p) = \mathbb{E}[-\log_{2}(p(X))] = -\sum_{x \in X}p(x)\log_{2}(p(x))$$
d.h.: wir benötigen im Durschnitt mindestens $-\log_{2}(p(x))$ Bits zur Kodierung eines Samples $x$.

### Kreuzentropie
Sei $q$ eine Wahrscheinlichkeitsfunktion über demselben Ergebnisraum $X$ wie die W.funktion $p.$ 
Nun kodiert man die Samples $x \in X$ optimal im Bezug auf $q$.

Die Kreuzentropie $H(p,q)$ sagt: wieviele Bits werden nun im Durchschnitt verwendet, wenn die Samples durch $p$ gezogen werden?
$$H(p,q) = \mathbb{E}_{p}[-\log_{2}(q(X))]=-\sum _{x\in X}p(x) \log_{2}(q(x)).$$

Es ist $H(p,q)\geq H(p)$ und es ist $H(p,q)=H(p)$, wenn $p=q$.
$D_{KL}(p,q)=H(p,q)-H(p)$ heißt *Kullback-Leibler-Divergenz*.
## Statistische Schätzer

### Punktschätzer

*Gegeben:* Datenpunkte $\set{x_{1},\ldots,x_{m}}$ i.i.d., welche durch Wahrscheinlichkeitsfunktion $p(x \mid \theta)$ generiert wurde. $\theta$ sei jedoch unbekannt.

*Gesucht:* Schätzung $\hat \theta_{m} = g(x_{1},\ldots,x_{m})$ von Parameter $\theta$.

$g$ könnte nun z.B. ein Lernalgorithmus sein, der $\hat \theta$ lernen soll, der bestmöglich $\theta$ approximiert.

Da $\hat \theta$ aus zufällig gezogenen Samples berechnet wird, kann $\hat \theta$ nun bei konstantem $g$ selbst als Zufallsvariable angesehen werden.

Hat man nun $\hat \theta$ $m$-mal gezogen, lässt sich ein Schätzer wie folgt bewerten:
- Bias: durchschnittliche Abweichung von $\hat\theta_m$ zu $\theta$ ($\text{Bias}(\hat\theta_{m})=\mathbb{E}[\hat \theta_{m}]-\theta$)
- Varianz: Streuung von $\hat\theta_{m}$ ($\text{Var}(\hat\theta_{m})=\mathbb{E}[(\hat \theta_{m}-\mathbb{E}[\hat \theta_{m}])^{2}]=\mathbb{E}[\hat\theta_{m}^{2}]-\mathbb{E}[\hat\theta_{m}]^{2}$)

Kombination von Bias und Varianz als *Mean Squared Error* (MSE): $$\text{MSE}(\hat \theta_{m})=\mathbb{E}[(\hat \theta_{m}-\theta)^{2}]=\text{Bias}(\hat \theta_{m})^{2}+\text{Var}(\hat \theta_{m})$$
**Generell:**
- $g$ hat zu geringe Kapazität $\Rightarrow$ Underfitting und *hoher Bias*
- $g$ hat zu hohe Kapazität $\Rightarrow$ Overfitting und *hohe Varianz*


Ein Punktschätzer heißt *konsistent*, wenn die Vorhersage $\hat \theta$ mit steigender Anzahl $m$ von Datenpunkten zu $\theta$ konvergiert: $$p\!-\!\lim_{\!\!\!\!\!\!\!\!m \to \infty}\hat \theta_{m}=\theta$$
d.h. der MSE geht bei konsistenten Schätzern mit steigendem $m$ gegen 0.

### Maximum-Likelihood-Schätzer

Der Maximum-Likelihood-Schätzer ist die Implementierung eines Punktschätzers: $$\hat \theta_{ML} = \underset{\theta}{\operatorname{arg\,max}} \,p_\text{model}(X|\theta)\stackrel{\text{i.i.d.}}{=}\underset{\theta}{\operatorname{arg\,max}}\prod_{i=1}^{m}p_\text{model}(x_{i}|\theta).$$
Es wird gewissermaßen der Satz von Bayes angewandt: es wird der Wert für $\theta$ gewählt, der den Likelihood-Term $p(x|\theta)$ maximiert.

> Der ML-Schätzer ist konsistent und konvergiert schnell.

Anstatt die Likelihood zu maximieren, kann man die **Negative Log-Likelihood (NNL)** *minimieren:* $$\begin{align*}
\hat \theta_{ML}&= \underset{\theta}{\operatorname{arg\,max}}\;\log\left(\prod_{i=1}^{m}p_\text{model}(x_{i}|\theta)\right)\\
&= \underset{\theta}{\operatorname{arg\,max}}\sum_{i=1}^{m}\log p_\text{model}(x_{i}|\theta)\\
&= \underset{\theta}{\operatorname{arg\,min}}\sum_{i=1}^{m}-\log p_\text{model}(x_{i}|\theta)
\end{align*}$$
Das machen wir, um numerische Probleme (underflow/overflow) zu vermeiden, und weil Optimierer üblicherweise minimieren.

> Die Minimierung der negativen Log-Likelihood entspricht der Minimierung der *Kreuzentropie* $H(p_\text{data}, p_\text{model})$ zwischen $p_\text{model}(x|\theta)$ und der wahren Wahrscheinlichkeitsfunktion $p_\text{data}(x)$.

Verallgemeinerung für bedingte Verteilungen $p(Y|X, \theta)$ (z.B. Label $y$ für ein Bild $x$): $\hat \theta_{ML}=\underset{\theta}{\operatorname{arg\,min}}\sum_{i=1}^{m}-\log p_\text{model}(x_{i}|y_{i},\theta)$

### Kreuzentropie zur Klassifikation/Segmentierung

Ein neuronales Netz lernt üblicherweise direkt eine Wahrscheinlichkeitsfunktion $p_\theta(y|x)$. Eine Lossfunktion dafür ist der *Cross-Entropy Loss*, der direkt aus der NLL hervorgeht: $H=\frac{1}{m}\sum_{i=1}^{m}-\log p_{\theta}(y_i|x_i).$

Will man ein Bild segmentieren, gibt ein Netzwerk *pro Pixel* eine Wahrscheinlichkeitsverteilung über alle Klassen an. Der Loss könnte dann die gemittelte Kreuzentropie über alle Pixel sein.

Der Maximum-A-Posteriori maximiert anstatt der Likelihood den Posterior, also die Likelihood mal Prior durch Evidenz. 
Die Evidenz hängt aber nicht von $\theta$ ab, also können wir sie auch rauslassen und maximieren log-likelihood plus log-prior. Das kann praktisch sein, wenn wir Prior-Informationen mit in das Training einfließen lassen möchten - z.B. bei Regularisierung, wenn wir von vorne herein wissen, dass Netzwerkgewichte nicht allzu hoch sein sollten. Dann können wir die Wahrscheinlichkeit hoher Gewichte durch den Prior gering halten.
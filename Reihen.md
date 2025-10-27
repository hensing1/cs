# Reihen

> [!abstract] Definition **Reihe**
> Sei $(a_k)$ eine [[Folgen|Folge]] in $\mathbb{R}$ oder in $\mathbb{C}$. Für $n \in \mathbb{N}$ sei $$S_{n}:=\sum\limits_{k=1}^{n}a_{k}.$$
> Die Folge $(S_n)$ heißt **Reihe**. $S_n$ heißt *$n$-te Partialsumme* dieser Reihe.
> Man schreibt auch $$\sum\limits_{n=1}^{\infty}a_{n}$$ und meint damit
> - die gesamte Folge $(S_n)$ der Partialsummen, oder
> - den Grenzwert der Folge $(S_n)$, falls er existiert.
>
> Falls die Folge $(S_n)$ konviergiert, heißt die Reihe ebenfalls konvergent.

^417841

## Wichtige Reihen

> **Geometrische Reihe**
> $$\sum\limits_{n=0}^{\infty}q^{n}=1+q+q^{2}+q^{3}+\ldots$$

Für $|q|\geq 1$ divergiert die geometrische Reihe.
Für $|q|<1$ gilt: $\sum\limits_{k=0}^{\infty}q^{k}=\frac{1}{1-q}$, bzw. allgemeiner: $\sum\limits_{k=0}^{\infty}a \cdot q^{k}= \frac{a}{1-q}$ für $a \in \mathbb{R}$.

> **Harmonische Reihe**
> $$\sum\limits_{n=1}^{\infty} \frac{1}{n}$$

Die harmonische Reihe[^1] divergiert.
Die $n$-te Partialsumme der harmonischen Reihe heißt *n-te harmonische Zahl* oder $H_{n}$. Die $n$-te harmonische Zahl verhält sich asymptotisch wie der natürliche Logarithmus $\ln(n)$: $\ln(n+1)\leq H_{n} \leq \ln(n)+1$. ^75c659


[^1]: Eselsbrücke zur Unterscheidung zw. harmonischer und geometrischer Reihe: die Flageoletttöne auf einem Saiteninstrument schwingen auf der Länge $1/n$.

Die Reihe $$\sum\limits_{n=1}^{\infty} \frac{1}{n^{q}}$$ konvergiert für alle $q \in \mathbb{R}^{+}$ mit $q > 1$.
 
## Eigenschaften von Reihen

> **Linearkombination**
> Sind $\sum\limits_{n=1}^{\infty}a_n$ und $\sum\limits_{n=1}^{\infty}b_{n}$ konvergente Reihen, dann ist auch die Linearkombination dieser Reihen konvergent: $$\sum\limits_{n=1}^{\infty}(a_{n}+\lambda b_{n})=\sum\limits_{n=1}^{\infty}a_n+\lambda\sum\limits_{n=1}^{\infty}b_n.$$

> **Leibniz-Kriterium**
> Ist $(a_k)$ eine *monotone Nullfolge* in $\mathbb{R}$, dann ist $$\sum\limits_{k=1}^{\infty}(-1)^{k}a_k$$ *konvergent*.

## Absolute Konvergenz

> [!abstract] Definition
> Eine Reihe $\sum\limits_{k=1}^{\infty}a_k$ heißt **absolut konvergent**, wenn die Reihe $\sum\limits_{k=1}^{\infty}|a_k|$ konvergent ist.

> **Dreiecksungleichung für absolut konvergente Reihen**
> Für den Grenzwert einer absolut konvergente Reihe gilt: $$\left|\sum\limits_{k=1}^{\infty}a_{k}\right|\leq\sum\limits_{k=1}^{\infty}|a_k|$$

> **Majoranten- und Minorantenkriterium**
> Seien $(a_n)$ und $(b_n)$ zwei Folgen mit $|a_n|\leq|b_n|$ für alle $n \in \mathbb{N}$.
> 
> > *Majorantenkriterium:*
> > $\sum_{k=1}^{\infty}b_{k} \text{ absolut konvergent} \Rightarrow \sum_{k=1}^{\infty}a_{k} \text{ absolut konvergent.}$
> 
> > *Minorantenkriterium:*
> > $\sum_{k=1}^{\infty}a_{k} \text{ divergent} \Rightarrow \sum_{k=1}^{\infty}b_{k} \text{ divergent.}$

> **Vergleichskriterium**
> Seien $(a_{n})$ und $(b_n)$ zwei Folgen in $\mathbb{R}$ mit $$\lim\limits_{n \to\infty}\left| \frac{a_n}{b_{n}}\right|>0,$$
> dann konvergiert die Reihe $\sum_{k=1}^{\infty}a_{k}$ genau dann absolut, wenn die Reihe $\sum_{k=1}^{\infty}b_{k}$ absolut konvergiert.

> **Quotientenkriterium**
> Sei $(a_n)$ eine Folge in $\mathbb{R}$ oder $\mathbb{C}$ mit $a_{n}\neq 0$ für alle $n \geq n_0$.
> Falls es eine Zahl $\theta$ mit $0 < \theta < 1$ gibt, sodass für alle $n \geq n_0$ gilt: $$\left| \frac{a_{n+1}}{a_{n}}\right|\leq\theta,$$dann konvergiert die Reihe $\sum_{n=1}^{\infty}a_{n}$ absolut.

> **Wurzelkriterium**
> Sei $(a_n)$ eine Folge in $\mathbb{R}$ oder $\mathbb{C}$.
> Falls es eine Zahl $\theta$ mit $0<\theta<1$ gibt, sodass für alle $n \geq n_0$ gilt: $$\sqrt[n]{|a_n|}\leq\theta,$$dann konvergiert die Reihe $\sum_{n=1}^{\infty}a_{n}$ absolut.

## Cauchy-Produkt

> [!abstract] Definition **Cauchy-Produkt**
> Seien $(a_n)$ und $(b_n)$ Folgen in $\mathbb{R}$ oder $\mathbb{C}$.
> Dann heißt die Reihe $$\sum\limits_{k=1}^{\infty}\left(\sum\limits_{j=1}^{k}a_{j}b_{k-j+1}\right)$$ das **Cauchy-Produkt** der Reihen $\sum_{n=1}^{\infty} a_n$ und $\sum_{n=1}^{\infty} b_n$.

^0f6c76

> Das Cauchy-Produkt ist das Produkt der Grenzwerte der Reihen $\sum_{n=1}^{\infty} a_n$ und $\sum_{n=1}^{\infty} b_n$, sofern diese Reihen absolut konvergent sind.

^0eac68

## Potenzreihen

> [!abstract] Definition **Potenzreihe**
> Eine **Potenzreihe** ist eine Reihe der Form $$\sum\limits_{n=0}^{\infty}a_{n}(x-x_{0})^{n}.$$
> Hierbei heißt $(a_n)$ die *Koeffizientenfolge* und $x_{0}$ heißt *Entwicklungspunkt*.

^7dce3b

### Konvergenzradius von Potenzreihen
> Konvergiert die Reihe $$\sum\limits_{n=0}^{\infty}a_{n}(x-x_{0})^{n}$$für ein $x \neq x_0$, dann konvergiert sie auch für jedes $a$ mit $|a-x_{0}|<|x-x_{0}|$.

Das bedeutet: in der komplexen Ebene liegt der Konvergenzbereich kreisförmig um den Entwicklungspunkt. 
Das heißt, für jede Potenzreihe kann man einen Konvergenz*radius* $R$ bestimmen. Dann gilt:
- Für $|x-x_{0}|<R$ konvergiert die Potenzreihe.
- Für $|x-x_0|>R$ divergiert die Potenzreihe.
- Für $|x-x_0|=R$ ist keine Aussage möglich.

Falls die Potenzreihe für alle $x$ konvergiert, ist $R=\infty$. Divergiert sie für alle $x \neq x_0$, dann ist $R=0$.
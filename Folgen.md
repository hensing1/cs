# Folgen

> [!abstract] Definition *Folge*
> Sei $M$ eine Menge. Eine **Folge in $M$** ist eine [[Funktionen|Abbildung]]
> $$\begin{align*}
a : \mathbb{N}&\rightarrow M\\
n&\mapsto a(n).
\end{align*}$$
> Meint man die gesamte Folge, schreibt man $(a_{n})_{n\in \mathbb{N}}$, $(a_{n})_{n\geq 1}$ oder schlicht $(a_n)$.
> Für $a(n)$ schreibt man $a_n$. Das Element $a_n$ heißt $n$-tes *Folgeglied* der Folge $(a_n)$.

^731648

---
> [!abstract] Definition *Grenzwert einer Folge*
> Für eine *reelle Zahlenfolge* $(a_n)$ heißt eine Zahl $a$ **Grenzwert**, wenn sich die Folge (nach endlich vielen Folgegliedern) beliebig annähert: $$\forall \epsilon>0 \space\exists n_{0} \in \mathbb{N} \space \forall n \geq n_{0} : |a_{n} - a|< \epsilon.$$
> 
> Eine Folge mit Grenzwert heißt *konvergent*, eine Folge ohne Grenzwert heißt *divergent*.
> Ist $a$ ein Grenzwert, sagt man, $(a_n)$ konvergiert gegen $a$.

^e9b4d1

Da diese Definition mit der Betragsfunktion arbeitet, gilt sie für $\mathbb{R}$ genauso wie für $\mathbb{C}$ oder $\mathbb{R}^n$.

---
> [!abstract] Definition *Monotonie*
> Eine reelle Zahlenfolge $(a_n)$ heißt:
> - **monoton wachsend**, wenn $a_{n}\leq a_{n+1}$ für alle $n\in \mathbb{N}$,
> - **monoton fallend**, wenn $a_{n}\geq a_{n+1}$ für alle $n\in \mathbb{N}$,
> - **streng monoton wachsend**, wenn $a_{n} < a_{n+1}$ für alle $n\in \mathbb{N}$,
> - **streng monoton fallend**, wenn $a_{n} > a_{n+1}$ für alle $n\in \mathbb{N}$.
> 
> Eine Folge heißt *monoton*, wenn sie monoton wachsend oder monoton fallend ist.

^4895db

---
> [!abstract] Definition: *Teilfolge*
> Sei $(a_n)$ eine beliebige *Folge* und $(n_k)$ eine Folge in $\mathbb{N}$ mit $n_1<n_2<\ldots$.
> Dann heißt $(a_{n_{k}})=(a_{n_{1}},a_{n_{2}},a_{n_{3}},\ldots)$ eine **Teilfolge** der Folge $(a_n)$.

^56f523

---
> [!abstract] Definition: *Cauchy-Folge*
> Eine Folge $(a_n)$ in $\mathbb{R}$ heißt **Cauchy-Folge**, wenn es zu jedem $\epsilon>0$ eine Zahl $n_{0}\in \mathbb{N}$ gibt, sodass $|a_n-a_m|<\epsilon$ für alle natürlichen Zahlen $m,n\geq n_0$ gilt.

^5ce5ef

Eine Folge (in $\mathbb{R}$ und $\mathbb{C}$) ist genau dann eine Cauchy-Folge, wenn sie konvergent ist.

## Beschränktheit

> Sind alle Glieder einer Folge kleiner als ein Wert $K$, heißt die Folge *nach oben beschränkt*.
> Sind sie alle größer als ein Wert $k$, heißt sie *nach unten beschränkt*.
> Ist der Betrag aller Folgeglieder kleiner als ein Wert $M$, heißt sie *beschränkt*.

Eine beschränkte Zahlenfolge ist also nach oben und nach unten beschränkt.

*Wichtig:*
> Jede konvergente relle Zahlenfolge ist beschränkt.

Das liegt daran, dass es, bevor der Abstand zum Grenzwert beliebig klein wird, nur endlich viele Folgeglieder gibt. Eine endliche Menge von Zahlen ist trivialerweise in beide Richtungen beschränkt.

## Rechenregeln für Grenzwerte

> Es seien $(a_n)$ und $(b_n)$ konvergente Folgen mit Grenzwerten $a$ und $b$. Es gelten folgende Rechenregeln:
> - Die Folge $(a_{n}+b_{n})$ konvergiert gegen $a+b$.
> - Die Folge $(a_{n}-b_{n})$ konvergiert gegen $a-b$.
> - Die Folge $(a_{n}\cdot b_{n})$ konvergiert gegen $a \cdot b$. Allgemein konvergiert für ein festes $\lambda\in\mathbb{R}$ die Folge $(\lambda \cdot a_n)$ gegen $\lambda \cdot a$.
> - Ist $a \neq 0$, konvergiert die Folge $\left(\frac{1}{a_{n}}\right)$ gegen $\frac{1}{a}$.
> - Die Folge $(|a_{n}|)$ konvergiert gegen $|a_{n}|$.
> - Die Folge $(\sqrt{a_n})$ konvergiert gegen $\sqrt{a}$.

Quotienten zweier divergenter Folgen können konvergieren:

$$\begin{align*}
\frac{n^{2}+3n-2}{4n^{2}-n+2023}&=\frac{n^{2}\cdot(1+\frac{3}{n}- \frac{2}{n^{2}})}{n^{2}\cdot(4-\frac{1}{n}+ \frac{2023}{n^{2}})}\\
&=\frac{1+\frac{3}{n}- \frac{2}{n^{2}}}{4-\frac{1}{n}+ \frac{2023}{n^{2}}} \rightarrow \frac{1+0-0}{4-0+0}=\frac{1}{4}.
\end{align*}$$

## Theoreme für die Grenzwertberechnung

> **Satz der monotonen Konvergenz**
> Jede beschränkte, monotone reelle Zahlenfolge $(a_n)$ konvergiert.

^863038

> **Satz der Intervallschachtelung**
> Gegeben zwei Folgen $(a_n)$ und $(b_n)$, und die folgenden Bedingungen:
> - $\forall n\in \mathbb{N} : I_{n} := \left[x_{n},y_{n}\right] \neq \emptyset$
> - $\forall n \in \mathbb{N} : I_{n} \supseteq I_{n+1}$
> - $\lim \limits_{n \to \infty} y_{n} - x_{n} = 0$
> 
> dann existiert *genau ein* $a\in \mathbb{R}$, welches in sämtlichen Intervallen $\left[x_{n},y_{n}\right]$ enthalten ist.

^ec6401

> **Satz von Bolzano-Weierstraß**
> Jede *beschränkte* Folge $(a_{n})$ in $\mathbb{R}$ besitzt eine konvergente Teilfolge.

^04716a

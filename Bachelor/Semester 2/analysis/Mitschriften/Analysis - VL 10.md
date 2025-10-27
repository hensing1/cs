Datum: 10.05.
[Annotiertes Skript](https://ecampus.uni-bonn.de/goto_ecampus_file_3039288_download.html)
[Notizen aus der Vorlesung](https://ecampus.uni-bonn.de/goto_ecampus_file_3039287_download.html)

# Mehr zu Stetigkeit

> Seien $f,g: D \to \mathbb{R}$ stetige Funktionen in $a\in D$, sowie $\lambda \in \mathbb{R}$. Dann sind die Funktionen:
> $$\begin{align*}
(f+g)(x)&=f(x)+g(x),\\
(\lambda f)(x) &= \lambda \cdot f(x),\\
(fg)(x)&=f(x)\cdot g(x),\\
(fg^{-1})(x)&= \frac{f(x)}{g(x)}\text{, sofern }g(a)\neq 0,\\
(f\circ g)(x)&=g(f(x))\end{align*}$$
> 
> ebenfalls in $a$ stetig.

> **$\epsilon$-$\delta$-Stetigkeit**
> Eine Funktion $f : D \to \mathbb{R}$ ist genau dann stetig in $a \in D$, wenn gilt:
> 
> Für alle $\epsilon>0$ existiert ein $\delta>0$, sodass für alle $x \in D$ mit $|x-a|<\delta$ folgt: $$|f(x)-f(a)|<\epsilon.$$

^3a4602

![[epsilon-delta-Stetigkeit.png|400]]



## Berührpunkte und Grenzwerte bei Funktionen
> **Berührpunkt**
> Gibt es eine Folge $(a_n)$ in $D \subseteq \mathbb{R}^{r}$, sodass $\lim_{n \to\infty}a_n=a$, dann heißt $a$ *Berührpunkt von $D$*.

Ist $D=\left]a, b\right[$, so ist jedes $x \in [a, b]$ ein Berührpunkt von $D$.

> [!info] **Grenzwerte bei Funktionen**
> Seien $D \subseteq \mathbb{R}^{r}$, $f : D \to \mathbb{R}^{r}$ eine Funktion, $a \in \mathbb{R}^r$ ein Berührpunkt von $D$ und $b \in \mathbb{R} \cup \set{\pm\infty}$.
> - Gilt für *jede* Folge $(a_n)$ in $D \setminus \set{a}$, welche gegen $a$ konvergiert, dass $$\lim\limits_{n \to\infty}f(a_n)=b,$$dann schreibt man $$\lim\limits_{x \to a}f(x)=b$$als den Grenzwert der Funktion $f$ gegen $a$.
> 
> Für $r=1$:
> - Konvergiert $(a_n)$ von oben nach $a$, d.h. wenn $a_{n}>a$ für alle $n$, dann schreibt man $$\lim\limits_{x\searrow a}f(x)=b$$bzw. von unten: $$\lim\limits_{x\nearrow a}f(x)=b$$sofern für jede dieser Folgen $\lim_{n \to\infty}f(a_n)=b$ gilt.
> 
> - Gilt für jede nach $+\infty$ bzw. $-\infty$ divergente Folge $(a_n)$, dass $\lim_{n \to\infty}f(a_n)=b$, schreibt man $$\lim\limits_{x \to \infty}f(x)=b$$bzw. $$\lim\limits_{x \to -\infty}f(x)=b.$$

> Ist $a \not\in D$ ein Berührpunkt von $D$ und $f : D \to \mathbb{R}$ eine stetige Funktion, dann ist $f$ *stetig fortsetzbar in $a$*, wenn der Grenzwert $\lim_{x \to a}f(x)=b$ existiert.
> 
> Die Funktion $\tilde{f} : D \cup \set{a}\to \mathbb{R}$ mit $\tilde{f}(a):=b$ und $\tilde{f}(x):=f(x) \space\forall x \in D$ heißt *(stetige) Fortsetzung von $f$ in $a$*.

Beispiel: die Funktion $f(x)= \frac{\exp(x)-1}{x}$ ist durch die Festsetzung $f(0):=1$ stetig fortsetzbar in $0$.
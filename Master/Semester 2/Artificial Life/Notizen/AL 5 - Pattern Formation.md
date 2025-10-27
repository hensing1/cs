[[ALSS25_05_Pattern_Formation.pdf]]

## Iterated Functions

Eine iterierte Funktion ist eine rekursiv definierte [[Folgen|Folge]] der Form $$a(n+1)=f(a(n)).$$

Beispiele:
- Collatz-Folge
	- $a(0)$ wird frei gewählt
- Look-and-Say sequence
	- d, 1d, 2d, 1211d, 11122d, 31221d, ... für $a(0)=d$
	- Mit $L_{i}$ die Länge der $i$-ten Zahl in der Look-and-Say-Sequence gilt: $\lim_{ i \to \infty } \frac{L_{i+1}}{L_{i}}=\lambda \approx 1.304$

**Verhaltensformen iterierter Funktionen**
- divergent
- konvergent
- periodisch
- chaotisch

### Logistic Map

Iterierte Funktion mit Parameter $a$:
$$x(i+1)=a x(i)(1-x(i))$$
Je nach $a$ passieren verschiedene Dinge:
- $0<a\leq1$: konvergiert zu 0
- $1 < a < 3$: konvergiert zu Fixpunkt ungleich 0
- $3<a<4$: Oszillation zwischen 2, 4, 8, ... bis hin zu chaos
- $a=4$: Chaos
- $a>4$: divergiert

### Logistisches Wachstum

$$x(i+1)=x(i)+a\,(M-x(i))\,x(i)$$
- $M$ ist Menge der verfügbaren Ressourcen
- $a\,(M-x(i))$ ist Wachstumsterm mit Wachstumsrate $a$
- Für $x(i) \ll M$, annähernd exponentielles Wachstum
- Maximales Wachstum für $x(i)=\frac{M}{2}$
- Für $x(i) \approx M$, kein Wachstum mehr
- -> Sigmoid-Kurve

### Activator-Inhibitor-Systeme

Man hat zwei Populationen $X$ (Aktivator) und $Y$ (Inhibitor).
Die Differenzialgleichtung ist $$\begin{align}
X(i+1)=X(i) + aX(i) - bY(i) \\
Y(i+1)=Y(i) + cX(i) - dY(i)
\end{align}$$
## Reaction-Diffusion-Systeme

Reaction diffusion systems sind eine Art kontinuierliche Version von CAs.
Man hat zwei Chemikalien $V$ und $W$. Die Verteilung dieser Chemikalien über Zeit ist jeweils gegeben durch einen *Diffusionsterm* (nur Abhängig von $V$ bzw. $W$) und einen *Reaktionsterm* (abhängig von $V$ und $W$): $$\begin{align}
\frac{ \partial V }{ \partial t } &=\mu \nabla ^{2}V + f_{V}(V,W) \\
\frac{ \partial W }{ \partial t } &=\mu \nabla ^{2}W + f_{W}(V,W)
\end{align} $$

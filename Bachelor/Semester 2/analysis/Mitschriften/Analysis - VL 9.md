Datum: 08.05.
[Notizen aus der Vorlesung](https://ecampus.uni-bonn.de/goto_ecampus_file_3036529_download.html)
[Annotiertes Skript](https://ecampus.uni-bonn.de/goto_ecampus_file_3036530_download.html)

# Die komplexe Exponentialfunktion

> [!abstract] Definition **Exponentialfunktion**
> Die durch die [[Reihen#Potenzreihen|Potenzreihe]]  $$\begin{align}
> \exp : \mathbb{C} &\to \mathbb{C}\\
> x &\mapsto \sum\limits_{n=0}^{\infty} \frac{x^{n}}{n!}\end{align}$$
> definierte Funktion heißt **Exponentialfunktion**.

Es gilt:
> - $\exp(0)=1$[^1]
> 
> - $\forall x,y \in \mathbb{C} : \exp(x)\cdot\exp(y)=\exp(x+y)$ *(Funktionalgleichung der Exponentialfunktion, auch Additionstheorem)*[^2]
> 	- entsprechend: $\exp(x)^{y}=\exp(x \cdot y)$
> - $\forall z \in \mathbb{C} : \exp(-z) = \frac{1}{\exp(z)}$


[^1]: Man setzt bei der Definition voraus, dass $0^{0}=1$ ist.
[^2]: Der Beweis hierfür arbeitet mit dem < Cauchy-Produkt >

Die *Euler'sche Zahl* $e$ ist definiert als $$e := \exp(1)=\sum\limits_{n=0}^{\infty} \frac{1}{n!}=1+ 1+ \frac{1}{2}+ \frac{1}{6}+ \frac{1}{24} + \ldots$$
Es gilt: $\exp(n)=e^{n}.$

## Restgliedabschätzung
*"Wie gut approximiert mein Polynom die Exponentialfunktion?"*

> Es gilt für alle $x \in \mathbb{R}$ und $n \in \mathbb{N}_0$ mit $|x|\leq 1 + \frac{n}{2}$ : $$\left|\exp(x)-\sum\limits_{k=0}^{n} \frac{x^{k}}{k!}\right|<2 \frac{|x|^{n+1}}{(n+1)!}.$$

Das bedeutet: das Polynom bestehend aus den ersten $n$ Termen der Potenzreihe von $\exp$ weicht nicht mehr als einen konstanten Term von $e^x$ ab, solange man sich im Intervall $[-1- \frac{n}{2},1+ \frac{n}{2}]$ befindet. 

## Komplexe Exponentialfunktion und trigonometrische Funktionen

> Für $x \in \mathbb{R}$ gilt: $|\exp(ix)|=1$

Joa, ist halt so.

> Weiterhin sind $\sin, \cos : \mathbb{R} \to \mathbb{R}$ definiert als:
> $$\begin{gather}\sin(x):=\mathfrak{Im}(\exp(ix))\\\cos(x):=\mathfrak{Re}(\exp(ix))\end{gather}$$und demnach: $$\exp(ix)=\cos(x)+i\sin(x).$$

Nun kann man auch die komplexe Exponentalfunktion mittels rellwertiger Funktionen ausdrücken:
$$\begin{align*}
\exp(x+iy) &= \exp(x) \cdot \exp(iy)\\
&=e^{x} (\cos(y) + i \sin(y))\\
&= e^{x} \cos(y) + i e^{x} \sin(y)
\end{align*}$$

Man kann die Potenzreihe von $\exp$ in ihre Reell- und Imaginärkomponente aufteilen. Anhand dessen sind die komplexen Sinus- und Kosinusfunktionen definiert:
$$\begin{align*}
\sin(z)&=\sum\limits_{n=0}^{\infty} \frac{(-1)^{n}}{(2n+1)!}z^{2n+1}\\
\cos(z)&=\sum\limits_{n=0}^{\infty} \frac{(-1)^{n}}{(2n)!}z^{2n}
\end{align*}$$

# Stetigkeit

> [!abstract] Definition **Stetigkeit**
> Eine Funktion $f$ heißt **stetig in $a$**, wenn für jede Folge $(a_n)$ mit Grenzwert $a$ gilt: $$\lim\limits_{n \to \infty}f(a_{n})=f\left(\lim\limits_{n \to \infty}a_{n}\right).$$
> Hierbei muss $D \in \mathbb{R}^{r}$ der Definitionsbereich von $f$ sein, sowie $(a_{n})$ eine Folge in $D$.
> Die Funktion $f$ heißt **stetig**, wenn sie in jedem Punkt $a \in D$ stetig ist.

^ca29df

Eine stetige Funktion ist also mit dem Grenzwertprozess für Folgen verträglich. Es macht also keinen Unterschied, ob man zuerst die Funktion auf alle Folgeglieder anwendet und dann den Grenzwert dieser neuen Folge betrachtet, oder ob man direkt die Funktion auf den ursprünglichen Grenzwert anwendet.

Beispiel: die Funktion $$f(x)=\left\{ \begin{align*}
1&, \text{ falls }x> 0\\
0&, \text{ falls }x\leq0
\end{align*}\right.$$ist nicht stetig in $0$, da $\lim_{n \to\infty}f( \frac{1}{n})=1$, jedoch $f(0)=0$.
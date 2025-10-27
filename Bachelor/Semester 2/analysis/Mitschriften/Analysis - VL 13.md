Datum: 22.05.
[Annotiertes Skript](https://ecampus.uni-bonn.de/goto_ecampus_file_3048877_download.html)
[Notizen aus der Vorlesung](https://ecampus.uni-bonn.de/goto_ecampus_file_3048878_download.html)

*Kapitel 3*
# Der Rest der Stetigkeit
## Ein paar Grenzwerte

- $\lim\limits_{n \to\infty}\sqrt[n]{a}=\lim\limits_{n \to\infty}a^{\frac{1}{n}}=1$
- $e^x$ wächst schneller als jedes Polynom, da es im Grunde ein Polynom unendlichen Grades ist:
	- $\lim\limits_{x \to \infty} \frac{e^{x}}{x^{k}}=\infty$
	- $\lim\limits_{x \to \infty} x^{k}e^{-x}=0$
- Entsprechend wächst der Logarithmus langsamer als jedes Polynom.
	- $\lim\limits_{x \searrow 0}x^{\alpha}\log(x)=0$ für $\alpha>0$

### Alternative Definition der Exponentialfunktion
$$e^{x}=\lim\limits_{n \to \infty}\left(1+ \frac{x}{n}\right)^{n}$$

Oder allgemeiner:
$$e^{x}=\lim\limits_{y \to 0}\left(1+xy\right)^{\frac{1}{y}}$$

Somit kann man für $y$ eine beliebige Nullfolge einsetzen (oben: $\frac{1}{n}$). Es geht aber genauso z.B. $\frac{-1}{x^{2}}$: $e^{x}=\lim\limits_{n \to\infty}\left(1-\frac{x}{n^{2}}\right)^{-n^{2}}$.



## Asymptoten
> [!abstract] **Asymptote** (schräge und horizontale) 
> Die Gerade $y=mx+b$ heißt *Asymptote* der Funktion $f : D \to \mathbb{R}$, wenn $\lim\limits_{x \to \infty} f(x)-mx-b=0$ oder $\lim\limits_{x \to -\infty} f(x)-mx-b=0$.
> Für $m=0$ heißt $b$ *horizontale Asymptote von $f$*, ansonsten spricht man von einer *schrägen Asymptote*.

> [!abstract] **Asymptote** (vertikale)
> Für eine Funktion $f : D \to \mathbb{R}$ und einen Berührpunkt $a \not\in D$ von $D$ heißt die Gerade $x=a$ eine *vertikale Asymptote* von $f$, wenn mindestens eine der folgenden Bedingungen zutrifft: $$\lim\limits_{x\nearrow a}f(x)=+\infty, \space\lim\limits_{x\nearrow a}f(x)=-\infty, \space\lim\limits_{x\searrow a}f(x)=+\infty, \space\lim\limits_{x\searrow a}f(x)=-\infty.$$

*Kapitel 4*
# Differenzial- und Integralrechnung

## Differenzierbarkeit und Ableitungen

![[Differenzialrechnung#^5a34fe]]

Das ganze bedeutet also, dass die Funktion $f$ in der Nähe von $x_0$ so aussieht wie die Gerade $g(x)=f(x_{0})+a(x-x_{0})$.
Es gilt: $$a = \lim\limits_{x \to x_0}\frac{f(x)-f(x_0)}{x-x_{0}}.$$

> Ist $f$ in $x_0$ differenzierbar, dann ist sie auch in $x_0$ stetig.

Die Umkehrung gilt (natürlich) nicht: $f(x)=|x|$ ist in $0$ nicht differenzierbar.

### Ableitungsregeln

Seien $f,g : I \to \mathbb{R}$ in $x_{0} \in I$ differenzierbare Funktionen. Dann gelten:

> **Linearität**
> $$\begin{align*}(f+g)'(x_0)&=f'(x_0)+g'(x_0)\\
(\lambda\cdot f)'(x_0)&=\lambda \cdot f'(x_0)
\end{align*}$$
> **Produktregel**
> $$(f \cdot g)'(x_0)=f'(x_{0})\cdot g(x_{0})+f(x_{0})\cdot g'(x_{0})$$
> **Quotientenregel**
> Für $g(x_{0})\neq 0$:
> $$\left(\frac{f}{g}\right)'(x_{0})=\frac{f'(x_{0})g(x_{0})-f(x_{0})g'(x_{0})}{(g(x_{0}))^{2}}$$
> **Kettenregel**
> Für zwei differenzierbare Funktionen $f : I \to J$ und $g: J \to \mathbb{R}$ gilt: $$(g\circ f)'(x_0)=g'(f(x_{0})) \cdot f'(x_{0}).$$

^c9d29c


### Ein paar Ableitungen

| $f(x)$                                          | $f'(x)$                | Definitionsbereich |
| ----------------------------------------------- | ---------------------- | ------------------ |
| $x^{n}, n \in \mathbb{N}$                       | $nx^{n-1}$             | $x \in \mathbb{R}$ |
| $\lambda \cdot \exp(x), \lambda \in \mathbb{R}$[^1] | $\lambda \cdot\exp(x)$ | $x \in \mathbb{R}$ |
| $\ln(x)$                                        | $\frac{1}{x}$          | $x>0$              |
| $x^{\alpha},\alpha\in \mathbb{R}$               | $\alpha x^{\alpha-1}$  | $x>0$              |
| $\sin x$                                        | $\cos x$               | $x \in \mathbb{R}$ |
| $\cos x$                                        | $- \sin x$             | $x \in \mathbb{R}$ |

[^1]: Die Menge $\set{\lambda \cdot \exp \mid \lambda \in \mathbb{R}}$ ist die komplette Menge aller Funktionen, welche diese Eigenschaft haben.
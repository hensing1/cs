Datum: 16.05.

# ***$$\Huge \text{Guten Morgen}$$***

[[ThR_LA_Skript.pdf|Skript:]] Ab Seite 50 bis 59

Wir geigen Beispiel 5.20 durch: $1, \sqrt{2}$ und $\sqrt{3}$ sind im $\mathbb{Q}$-Vektorraum $\mathbb{R}$ linear unabhängig. Da es unendlich viele irrationale Zahlen gibt, welche sich paarweise nicht durch rationale Zahlen ineinander überführen lassen, ist der $\mathbb{Q}$-Vektorraum $\mathbb{R}$ unendlich-dimensional.

**Der Polynomraum $\mathbb{K}[x]$**
Den Vektorraum aller Polynome $n$-ten Grades kann man als polymorph betrachten zum $\mathbb{R}^{n}$, indem man $(x^{n},x^{n-1},\ldots,x^{0})$ als kanonische Basis betrachtet.

Will man also ein paar Polynome $$\begin{align*}
p_{1}(x)&=a_{1,n}\cdot x^{n}+a_{1,n-1}\cdot x^{n-1}+\ldots+a_{1,0}\\
p_{2}(x)&=a_{2,n}\cdot x^{n}+a_{2,n-1}\cdot x^{n-1}+\ldots+a_{2,0}\\
&\vdots\\
p_{k}(x)&=a_{k,n}\cdot x^{n}+a_{k,n-1}\cdot x^{n-1}+\ldots+a_{k,0}
\end{align*}$$ auf lineare Unabhängigkeit prüfen, sind diese polymorph zu $$v_{1}=\begin{pmatrix}a_{1,n}\\a_{1,n-1}\\\vdots\\a_{1,0}\end{pmatrix},v_{2}=\begin{pmatrix}a_{2,n}\\a_{2,n-1}\\\vdots\\a_{2,0}\end{pmatrix},\ldots,v_{k}=\begin{pmatrix}a_{k,n}\\a_{k,n-1}\\\vdots\\a_{k,0}\end{pmatrix}$$ und man hat entsprechend das LGS: $$\left.\begin{matrix}
    a_{1,n}   & a_{2,n}   & \ldots & a_{k,n}\\
    a_{1,n-1} & a_{2,n-1} & \ldots & a_{k,n}\\
    \vdots    & \vdots    & \ & \vdots \\
    a_{1,0}   & a_{2,0}   & \ldots & a_{k,0}
\end{matrix}\quad\right\vert\quad\begin{matrix}0\\0\\\vdots\\0\end{matrix}$$
Man hat also die Gleichung $\lambda_{1}p_{1}(x)+\lambda_{2}p_{2}(x)+\ldots+\lambda_{k}p_{k}(x)=0$ umgeformt zu $x^{n}(\lambda_{1}a_{1,n}+\lambda_{2}a_{2,n}+\ldots+\lambda_{k}a_{k,n})+\ldots+x^{0}(\lambda_{1}a_{1,0}+\lambda_{2}a_{2,0}+\ldots+\lambda_{k}a_{k,0})$ und hat dabei ausgenutzt, dass $x^{n},x^{n-1},\ldots,x^{0}$ linear unabhängig sind.

# Lineare Abbildungen

![[Lineare Funktionen#^955b6a]]
![[Lineare Funktionen#^014f88]]


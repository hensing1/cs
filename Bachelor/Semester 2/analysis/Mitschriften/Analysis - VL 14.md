Datum: 05.06.
[Annotiertes Skript](https://ecampus.uni-bonn.de/goto_ecampus_file_3056732_download.html)
[Notizen aus der Vorlesung](https://ecampus.uni-bonn.de/goto_ecampus_file_3056733_download.html)

*Kapitel 4: Differenzial- und Integralrechnung*
# Mehr Ableitung

> **Kettenregel**
> Sind zwei Funktionen $f : I \to J$ und $g: J \to \mathbb{R}$ differenzierbar, dann ist $(g \circ f)$ auch differenzierbar und es gilt $$(g \circ f)'=g'(f(x)) \cdot f'(x).$$

Dabei heißt $g'(f(x))$ *äußere Ableitung* und $f'(x)$ *innere Ableitung*.

> **Ableitung der Umkehrfunktion**
> Für eine *bijektive Funktion* $f : I \to J$, welche im Punkt $y_{0}$ differenzierbar ist mit $f'(y_{0})\neq 0$, dann ist für $x_{0}:=f(y_0)$:
> $$(f^{-1})'(x_{0})=\frac{1}{f'(y_{0})}=\frac{1}{f'(f^{-1}(x_{0}))}$$

$f'(y_{0})\neq 0$ ist wichtig, da ansonsten die Ableitung der Umkehrfunktion an der entsprechenden Stelle unendlich wäre. Beispiel: $\sqrt{x}$ ist an der Stelle 0 zwar stetig, aber nicht differenzierbar, da $(x^2)'(0)=0$.

## Raum der stetig differenzierbaren Funktion

> Kann man eine Funktion $f : I \to \mathbb{R}$ $n$-mal ableiten, schreibt man die $n$-te Ableitung als $f^{(n)}$.
> Ist $f^{(n)}$ *stetig*, dann heißt $f$ *$n$-mal stetig differenzierbar*.
> 
> Die *Menge der $n$-mal stetig differenzierbaren Funktionen* nennen wir $$C^{n}(I):=\set{f: I \to \mathbb{R} \mid f  \space n\text{-mal stetig differenzierbar}}.$$
> Außerdem: $$C^{\infty}(I):=\set{f: I \to \mathbb{R} \mid f \text{ ist beliebig oft differenzierbar}}=\bigcap\limits_{n\in \mathbb{N}}C^{n}(I).$$
> $C^{n}$ und $C^{\infty}$ sind [[Vektorräume#Vektorräume|Vektorräume]].


## Implizite Differentation

Gegeben sei eine Gleichung wie $x^2+y^2=9$, also ein Kreis um den Nullpunkt mit Radius 3. Uns interessiert die Tangentensteigung an einem Punkt auf dem Kreis, z.B. $(2,\sqrt{5})$.

*Impliziertes Ableiten* geht so:
- Schreibe die Gleichung so, dass es nur noch eine unabhängige Variable gibt - in diesem Fall setze $y=y(x)$.
- Leite beide Seiten ab:
	- $\frac{d}{dx}(x^{2}+y(x)^{2})=\frac{d}{dx}9$
	- $2x+2y(x)y'(x)=0$
- Forme nach der Ableitung um:
	- $y'(x)=- \frac{2x}{2y(x)}=- \frac{x}{y}$.

Nun kann man für $x$ und $y$ beliebige Punkte einsetzen, die die obige Gleichung erfüllen, und bekommt die Steigung raus. 
Im obigen Beispiel ist die Ableitung für jeden Kreis dieselbe.

Wenn man implizit ableiten kann, kann man sich durch *logarithmisches Ableiten* manche Ableitungen einfacher machen:
Sei $f(x)=x^{x}$ gegeben. Man kann von beiden Seiten den Logarithmus nehmen, und dann implizit ableiten:
$$\begin{gather}
\ln f(x)=x \ln x\\
\frac{d}{dx}(\ln f(x))= \frac{d}{dx} (x \ln x)\\
\frac{f'(x)}{f(x)}=\ln x + x \cdot \frac{1}{x}=1+\log x\\
f'(x)=f(x)(1+\ln x)=x^{x}(1+\ln x).
\end{gather}$$

## Sätze über differenzierbare Funktionen

> An einer Extremstelle ist die Ableitung 0.
> Hat eine Funktion an zwei Stellen denselben Funktionswert, dann muss irgendwo dazwischen die Ableitung 0 sein (Satz von Rolle).

> **Satz von Taylor**
> Sei $f: I \to \mathbb{R}$ $(n+1)$-mal differenzierbar und $x_{0} \in I$. Dann existiert für alle $x$ ein $\xi \in \left]x,x_{0}\right[$ bzw. $\xi \in \left]x_{0},x\right[$, sodass $$f(x)=\sum\limits_{k=0}^{n}\frac{f^{(k)}(x_{0})}{k!}(x-x_{0})^{k}+ \frac{f^{(n+1)}(\xi)}{(n+1)!}(x-x_{0})^{n+1}.$$

> **Taylorpolynom**
> Sei $f : I \to \mathbb{R}$ $n$-mal differenzierbar und $x_{0}\in I$. 
> $$T_{f,n}(x)=\sum\limits_{k=0}^{n} \frac{f^{(k)}(x_{0})}{k!}(x-x_{0})^{k}$$ heißt dann *Taylorpolynom vom Grad $n$* der Funktion $f$ um den *Entwicklungspunkt $x_{0}$*.

Je höher der Grad $n$, desto besser schmiegt sich das Taylorpolynom $T_{f,n}$ um $x_{0}$ herum an den Graphen von $f$ an.

Im Satz von Taylor hat man also ein Taylorpolynom, und man kann den Fehler mit der $n+1$ten Ableitung abschätzen. Je näher $x$ an $x_0$ dran ist, desto kleiner wird der Bereich, in dem das $\xi$ liegen kann, und desto kleiner wird der Faktor $(x-x_{0})^{n+1}$, mit dem der Fehler multipliziert wird.

Es ist aber im allgemeinen *nicht* so, dass $f=T_{f,\infty}$ gilt.
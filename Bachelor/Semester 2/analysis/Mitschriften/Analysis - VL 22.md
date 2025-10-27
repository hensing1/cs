Datum: 03.07.
[[Skript Analysis - SS2023 - Welter.pdf|Skript]] - Seiten 222 bis 234

# Der Hauptsatz der Differential- und Integralrechnung

> **Mittelwertsatz der Integralrechnung**
> Sei $f: [a,b] \to \mathbb{R}$ eine *stetige* und $g: [a,b]\to \mathbb{R}$ eine *Regel*funktion mit $g\geq 0$. Dann gibt es ein $\zeta\in [a,b]$ mit $$\int_{a}^{b}f(x)g(x)\,dx=f(\zeta)\int_{a}^{b}g(x)\,dx.$$Für $g=1$ gilt: $$\int_{a}^{b}f(x)\,dx = f(\zeta)(b-a).$$

> [!important] *Hauptsatz der Differential- und Integralrechnung*
> Sei $f: [a,b]\to \mathbb{R}$ eine stetige Funktion. 
> Für $x \in [a,b]$ definiere $F: [a,b]\to \mathbb{R}$ durch $$F(x):=\int_{a}^{x}f(t)\,dt.$$
> Dann gilt:
> - Die Funktion $F$ ist eine < Stammfunktion> von $f$, d.h. für alle $x \in [a,b]$ gilt: $F'(x)=f(x)$.
> - Ist $G$ eine beliebige Stammfunktion von $f$, so gilt $$\int_{a}^{b}f(x)\,dx=G(b)-G(a)=:G(x)|_{a}^{b}.$$

> [!info] *Mehr Räschenregeln*
> > **Produktregel**
> > Für $u,v: I \to \mathbb{R}$ gilt: $$\int_{a}^{b}u(x)v'(x)\,dx=u(x)v(x)|_{a}^{b}-\int_{a}^{b}u'(x)v(x)\,dx.$$
> 
> > **Substitutionsregel**
> > Für $f: I \to \mathbb{R}$ und $g: [a,b] \to I$ gilt: $$\int_{a}^{b}f(g(x))g'(x)\,dx=\int_{g(a)}^{g(b)}f(t)\,dt.$$


# Uneigentliche Integrale

> **Unendliche Integrationsgrenze**
> Sei $f: \left[a,\infty\right[ \to \mathbb{R}$ eine Funktion, die auf jedem Intervall $[a,R],a<R<\infty$ eine < Regelfunktion> ist. Dann setze $$\int_{a}^{\infty}f(x)\,dx:=\lim\limits_{R \to \infty}\int_{a}^{R}f(x)\,dx,$$falls dieser Grenzwert existiert.
> Die Definition für $-\infty$ als untere Integrationsgrenze ist analog.

> **Integrand ist an einer Grenze nicht definiert**
> Sei $f: \left]a,b\right]$ eine Regelfunktion auf jedem Intervall $[a+\epsilon,b]$. Dann setze $$\int_{a}^{b}f(x)\,dx=\lim\limits_{\epsilon\searrow0}\int_{a+\epsilon}^{b}f(x)\,dx,$$falls dieser Grenzwert existiert.

> **Beide Grenzen nicht definiert**
> Sei $f: \left]a,b\right[ \to \mathbb{R}$ mit $a \in \mathbb{R}\cup \set{-\infty}$ und $b \in \mathbb{R}\cup \set{\infty}$ eine Regelfunktion auf jedem Intervall $[\alpha,\beta]\subset \left]a,b\right[$ und sei $c \in \left]a,b\right[.$ Definiere $$\int_{a}^{b}f(x)\,dx:=\int_{a}^{c}f(x)\,dx+\int_{c}^{b}f(x)\,dx,$$falls die beiden rechten Integrale existieren.

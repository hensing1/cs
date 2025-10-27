Datum: 19.06.
[Annotiertes Skript](https://ecampus.uni-bonn.de/goto_ecampus_file_3067955_download.html)
[Notizen aus der Vorlesung](https://ecampus.uni-bonn.de/goto_ecampus_file_3067956_download.html)

> [!info] Methode der kleinsten Quadrate
> Es gibt < Extremwertprobleme> auch beim Finden einer Regressionsgerade: 
> 
> Man hat Messpunkte und möchte eine Gerade $g(x)=ax+b$ finden, die die Distanz zu allen Punkten minimiert. 
> Man summiert also die einzelnen Fehler auf. Man nimmt aber nicht die Betragsfunktion, da sie analytisch nicht so praktisch ist (sie ist nicht differenzierbar). Also nimmt man die Quadratfunktion. 
> 
> Der Fehler für einen Punkt $(x_i,y_i)$ ist also $(y_{i}-g(x_{i}))^{2}=(y_{i}-a-bx_{i})^{2}$. Das heißt, wir suchen die Minimalstellen für die Funktion $F(a,b)=\sum\limits_{i=1}^{n}(y_{i}-a-bx_{i})^{2}$.
> Die resultierende Gerade nennt man auch *Ausgleichsgerade*.

puh

# Stammfunktionen

> [!abstract] Definition
> Für eine Funktion $f: I \to \mathbb{R}$ heißt eine differenzierbare Funktion $F: I \to \mathbb{R}$ **Stammfunktion** oder **unbestimmtes Integral** von $f$, falls $$F'(x)=f(x)$$ gilt. Mit $\int f(x) \,dx$ bezeichnet man eine (*nicht eindeutig bestimmte*) Stammfunktion von $f$.

Alle Stammfunktionen einer Funktion unterscheiden sich nur durch eine Konstante.

> [!important] ***Räsch*enregeln**
> *Linearität:*
> $$\int af(x)+bg(x) \,dx=a \int f(x)\,dx+b\int g(x)\,dx$$
> 
> *Partielle Integration:*
> $$\int f(x)g(x)\,dx=F(x)g(x)-\int F(x)g'(x)\,dx$$
> *Substitutionsregel:*
> $$\int f(g(x))g'(x)\,dx=F(g(x))$$

Diese Regeln folgen direkt aus:
- der Linearität der Ableitung,
- der < Produktregel>, und
- der < Kettenregel>.

Von der Produktregel zur partiellen Integration:
$$\begin{align*}
(F \cdot g)'&=F'\cdot g + F \cdot g'\\
&=f \cdot g + F \cdot g'\\
\iff F(x) \cdot g(x) &= \int f(x) g(x) + F(x) g'(x) \,dx\\
&=\int f(x) g(x)\,dx + \int F(x) g'(x) \,dx\\
\iff \int f(x)g(x) \,dx &= F(x) g(x) - \int F(x)g'(x)\, dx.
\end{align*}$$

Wir integrieren die Funktion $f(x)=x \cdot e^{x^{2}}$.

Wir stellen fest: $x=\frac{1}{2}(x^{2})'$. Also substituieren wir mit $t=t(x)=x^{2}$ und erhalten: $$\begin{align*}
\int x e^{x^{2}} \, dx &=\int \small\frac{1}{2}\normalsize  t'(x) \cdot e^{t(x)}\, dx\\
&=\frac{1}{2}\int t'(x) \cdot e^{t(x)}\, dx =\frac{1}{2}e^{t(x)}=\frac{1}{2}e^{x^{2}}.
\end{align*}$$
Das geht auch mit einem "hässlichen Physikertrick": man sagt, $t'(x)=\frac{dt}{dx}=2x$, also ist $dt=2xdx$, man behandelt $\frac{dt}{dx}$ also also Bruch, obwohl es eigentlich keiner ist.
Nun setzt man $\int x e^{x^{2}} \, dx= \int \frac{1}{2} e^{x^{2}}\cdot 2xdx=\int \frac{1}{2} e^{t} \,dt = \frac{1}{2}e^{t}=\frac{1}{2} e^{x^{2}}$.
#bruh


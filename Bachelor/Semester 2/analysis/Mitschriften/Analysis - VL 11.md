Datum: 15.05.
[Notizen aus der Vorlesung](https://ecampus.uni-bonn.de/goto_ecampus_file_3043304_download.html)
[Annotiertes Skript](https://ecampus.uni-bonn.de/goto_ecampus_file_3043305_download.html)

*Kapitel 3: Stetigkeit*
# Extremstellen

*Übrigens*
Nullstellenberechnung mit Zwischenwertsatz ist einfach eine binäre Suche.

> **Verallgemeinertes Intervall**
> Sei $I \subseteq \mathbb{R}$. $I$ heißt verallgemeinertes Intervall, wenn $\forall a,b,c \in \mathbb{R}: ((a<b<c) \land (a,c \in I)) \Rightarrow b \in I$.

Ein verallgemeinertes Intervall wird von einer stetigen Funktion immer auf ein anderes verallgemeintertes Intervall abgebildet.
Solche Verallgemeinerungen sind z.B. für mehrdimensionale Strukturen praktisch.

Eine Funktion ist beschränkt, wenn ihr Bild beschränkt ist. Der Beschränktheitsbegriff von Mengen kann also 1:1 auf Funktionen übertragen werden.

> Die *Extremstelle* (also *Minimal-* oder *Maximalstelle*) einer Funktion meint die *globalen* Minima bzw. Maxima. Also der Punkt $x_0 \in D$ für eine Funktion $f : D \to \mathbb{R}$, für den $f(x_{0})\leq f(x)$ bzw. $f(x_{0})\geq f(x)$ für alle $x \in D$ gilt.

> Ist das Urbild einer Funktion ein *abgeschlossenes* Intervall, dann ist die Funktion beschränkt und es gibt entsprechend eine Maximal- und eine Minimalstelle. Das Bild ist dann also ebenfalls ein abgeschlossenes Intervall.

# Folgen von Funktionen

## Konvergenz von Funktionenfolgen

Wir unterscheiden punktweise Konvergenz von gleichmäßiger Konvergenz. 
Die gleichmäßige Konvergenz ist der stärkere Begriff. 

### Punktweise Konvergenz

> [!abstract] **Punktweise Konvergenz**
> Eine Folge $(f_n)$ von Funktionen $f_{n}: I \to \mathbb{R}$ mit $I \subseteq \mathbb{R}$ heißt *punktweise konvergent* gegen eine Funktion $f : I \to \mathbb{R}$, falls $$\lim\limits_{n \to \infty}f_n(x)=f(x)$$ für alle $x \in I$ gilt.

*Beispiel*
Die Funktionenfolge $(f_n)$ mit $f_{n}:\left[0,1\right]\to \mathbb{R}, x \mapsto x^{n}$ konvergiert punktweise gegen $$f(x):=\left\{\begin{align*}
0, &\quad x \in \left[0,1\right[\\
1, &\quad x=1.
\end{align*}\right.$$
Die Stetigkeit von Funktionen überträgt sich also im Allgemeinen *nicht* auf den Grenzwert einer Funktionsfolge.

### Gleichmäßige Konvergenz

Um die gleichmäßige Konvergenz zu definieren, benötigt man die:

> **Supremumsnorm**
> Für eine Funktion $f: I \to \mathbb{R}$ heißt $$\|f\|_{I} := \sup\set{|f(x)|\mid x \in I}$$die *Supremumsnorm von $f$ auf $I$*.

Ist $I := \left[a, b\right]$ und $f$ stetig, so gilt $$\|f\|_I = \max\set{|f (x)| \mid x \in I}.$$
Man spricht dann auch von der Maximumsnorm.


> [!abstract] **Gleichmäßige Konvergenz**
> Eine Folge $(f_n)$ von Funktionen $f_{n}: I \to \mathbb{R}$ mit $I \subseteq \mathbb{R}$ heißt *gleichmäßig konvergent* gegen eine Funktion $f : I \to \mathbb{R}$, falls $$\lim\limits_{n \to \infty}\|f_n(x)-f(x)\|_{I}=0.$$

Die gleichmäßige Konvergenz sieht also definitionsmäßig so ähnlich aus wie die Konvergenz von Zahlenfolgen.

Man kann sie sich auch so ähnlich vorstellen: gleichmäßige Konvergenz verlangt, dass für jedes $\epsilon>0$ irgendwann alle Funktionen in der Folge vollständig in den $\epsilon$-Schlauch um die Grenzfunktion fallen.
Damit konvergiert die Folge aus dem obigen Beispiel *nicht* gleichmäßig, da $x^{n}$ für jedes $n$ irgendwann z.B. den Wert $0.5$ annimmt und damit für jedes $\epsilon<0.5$ nicht mehr vollständig im $\epsilon$-Schlauch ist.

Allgemein gilt:
> Konvergiert eine Folge stetiger Funktionen $(f_n)$ *gleichmäßig* gegen eine Funktion $f$, dann ist $f$ **ebenfalls stetig**.

## Mehr über Potenzreihen

### Stetigkeit von Potenzreihenfunktionen

> Sei $\sum_{n=0}^{\infty}a_{n}(x-x_{0})^n$ eine Potenzreihe mit Konvergenzradius $R>r>0$. Dann gilt:
> Die Funktionenfolge $$\begin{align*}
f_{n}: \left[x_{0}-r,x_0+r\right]& \to \mathbb{R}\\
x &\mapsto \sum\limits_{k=0}^{n}a_{k}(x-x_{0})^{k}
\end{align*}$$konvergiert *gleichmäßig* gegen $$\begin{align*}
f: \left[x_{0}-r,x_0+r\right]& \to \mathbb{R}\\
x &\mapsto \sum\limits_{k=0}^{\infty}a_{k}(x-x_{0})^{k}.
\end{align*}$$

Damit ist jede Grenzwertfunktion $P(x)=\sum_{n=0}^{\infty}a_{n}(x-x_{0})^{n}$ einer Potenzreihe in allen Punkten $x \in \left]x_{0}-R,x_{0}+R\right[$ stetig.

### Identitätssatz für Potenzreihen

Dieser Satz wird irgendwann mal für Differenzialgleichungen wichtig.

> **Identitätssatz für Potenzreihen**
> Sei $P(z)=\sum_{n=0}^{\infty}a_{n}z^{n}$ eine Potenzreihe mit Entwicklungspunkt $0$ und Konvergenzradius $R>0$. Sei zudem $(\alpha_k)$ eine *Nullfolge* mit $\alpha_{k}\neq 0$. Dann gilt:
> 
> Falls $P(\alpha_{k})=0$ für alle hinreichend großen $k$, dann ist jedes $a_{n}=0$.

*Alternative Formulierung*
> Sind $P(z)=\sum\limits_{n=0}^{\infty}a_{n}z^{n}$ und $Q(z)=\sum\limits_{n=0}^{\infty}b_{n}z^{n}$ zwei Potenzreihen mit positivem Konvergenzradius, $(a_{k})$ eine Nullfolge mit $a_{k}\neq 0$ und $P(\alpha_k)=Q(\alpha_k)$ für alle hinreichend großen $k$, dann gilt $a_n=b_n$ für alle $n \in \mathbb{N}_{0}$.

O-Ton von Hr. Welter: Wenn Sie die Potenzreihe nahe 0 kennen, dann kennen Sie sie überall.
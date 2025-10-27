Datum: 14.06.
[Annotiertes Skript](https://ecampus.uni-bonn.de/goto_ecampus_file_3063788_download.html)
[Notizen aus der Vorlesung](https://ecampus.uni-bonn.de/goto_ecampus_file_3063789_download.html)

# Funktionen mit mehreren Veränderlichen

Wir betrachten Funktionen der Form $f: \mathbb{R}^{n}\to \mathbb{R}$.

> [!abstract] Definition *Norm auf $\mathbb{R}^{n}$*
> Die 2-Norm für $v=(v_{1},\ldots,v_{n})\in \mathbb{R}^{n}$ ist definiert als $$\| v\|_{2}:=\sqrt{\sum\limits_{i=1}^{n}v_{i}^{2}}.$$

Die Norm auf $\mathbb{R}^n$ funktioniert wie die für die komplexen Zahlen, nur verallgemeinert.
Für $n=1$ erhält man die Betragsfunktion für die reellen Zahlen.

> [!abstract] Definition *Lokale Minima und Maxima im $\mathbb{R}^{n}$*
> Ein Punkt in $a \in D \subseteq \mathbb{R}^{n}$ heißt Maximum einer Funktion $f : D \to \mathbb{R}$, wenn für alle Punkte $x$ in einer $\epsilon$-Umgebung $$x \in U_{\epsilon}(a):=\set{x \in \mathbb{R}^{n} \mid \,\| a-x\|_{2}<\epsilon}\subseteq D$$ gilt, dass $f(x)\leq f(a)$.
> Die Definition für ein Minimum ist analog.

Wieder erhält man für $n=1$ genau die Definition für lokale Minima und Maxima von Funktionen in den reellen Zahlen.

> Ein Punkt im $\mathbb{R}^{n}$ heißt *innerer Punkt*, wenn es für ihn eine nichtleere $\epsilon$-Umgebung gibt, d.h. wenn er nicht auf dem Rand liegt.

Uns interessieren innere Punkte, damit wir uns ihm von jeder Seite annähern können.

> Eine Menge, die nur innere Punkte enthält, heißt *offene Menge* (analog zu offenem Intervall).


> [!abstract] Definition *Partielle Ableitung*
> In einem Punkt $a \in D \subseteq \mathbb{R}^{n}$ heißt eine Funktion $f: D \to \mathbb{R}$ **in $a$ bzgl. $x_{i}$ differenzierbar**, wenn die Funktion $f_{i}(x_{i}):=f(a_{1},\ldots,a_{i-1},x_{i},a_{i+1},\ldots a_{n})$, in welcher also $x_{i}$ als einzige Veränderliche vorkommt, im Punkt $a_{i}$ differenzierbar ist. 
> 
> Die partielle Ableitung nach der $i$-ten Komponente im Punkt $a$ schreibt man als $$\frac{\partial f}{\partial x_{i}}(a):=f_{i}'(a_{i}).$$
> 
> Ist $f$ überall nach $x_{i}$ differenzierbar, dann heißt die Funktion $\frac{\partial f}{\partial x_{i}}$ die *partielle Ableitung von $f$ nach $x_{i}$*.
> $f$ heißt auf $D$ *partiell differenzierbar*, falls sie für alle $x_{i}$ eine partielle Ableitung besitzt. Sind all diese Ableitungen stetig, heißt $f$ *stetig partiell differenzierbar*.

^0e4ade

## Bestimmung von Extrema im $\mathbb{R}^{n}$

### Kritische Punkte

Um die *Kandidaten* für ein Extremum zu finden, bestimmt man alle Punkte, an denen alle partiellen Ableitungen gleich null sind. Diese Kandidaten heißen dann *kritische Punkte*.

*Beispiel: $\mathbb{R}^{2}$*
Man fixiert zuerst das $y$, und dann schaut man für welche $x$ die Ableitung nach $x$ den Wert 0 hat (man behandelt $y$ also wie eine Konstante). 
Dann macht man es umgekehrt (man leitet nach $y$ ab). 

Für die Ableitung nach $x$ schreibt man $\frac{\partial f}{\partial x}(x,y)$ und für die nach $y$ schreibt man $\frac{\partial f}{\partial y}(x,y)$.

Setzt man beide Ableitungen gleich null, erhält man zwei Gleichungen, die durch denselben Punkt $(x,y)\in \mathbb{R}^{2}$ erfüllt sein müssen. Man erhält also ein < lineares Gleichungssystem>.

> [!abstract] Definition *Gradient*
> Sei $f: \mathbb{R}^{n}\to \mathbb{R}$ eine partiell differenzierbare Funktion. Dann heißt der Vektor $$\nabla f(a):= \text{grad}(f)(a):=\begin{pmatrix}\frac{\partial f}{\partial x_{1}}(a)\\\vdots\\ \frac{\partial f}{\partial x_{n}}(a)\end{pmatrix}$$ der **Gradient von $f$ an der Stelle $a$**.

^71f57b

> Ein Punkt ist also genau dann ein kritischer Punkt, wenn dort der Gradient der Nullvektor ist.

Die (Hyper-)Ebene, die den Graphen an einem Punkt $a$ schneidet und dort dieselbe Steigung wie der Graph hat, heißt *Tangentialebene*. Der Gradient liegt innerhalb der Tangentialebene und zeigt quasi in die "steilste" Richtung.


### Prüfung eines kritischen Punktes auf eine Extremstelle

Ähnlich wie mit Sattelpunkten in $\mathbb{R}$, prüft man kritische Punkte, indem man sich die zweite Ableitung in diesem Punkt ansieht.

Man kan die zweite Ableitung wieder nach allen $x_{i}$ ableiten. Für die $k$-te Ableitung schreibt man $$\frac{\partial^{k}f}{\partial x_{i_{k}}\partial x_{i_{k-1}}\ldots\partial x_{i_{1}}}(a)$$und meint damit, dass man zunächst nach $x_{i_{1}}$, dann nach $x_{i_{2}}$, und zuletzt nach $x_{i_{k}}$ ableitet. Man liest es also von rechts nach links.

> **Satz von Schwarz**
> Ist $f$ zweimal stetig partiell differenzierbar, dann gilt für alle inneren Punkte $a \in D$ und alle $i,j \in \set{1,\ldots,n}$ $$\frac{\partial^{2}f}{\partial x_{i}\partial x_{j}}(a)=\frac{\partial^{2}f}{\partial x_{j}\partial x_{i}}(a).$$

^a548c8

Es ist also egal, ob ich erst nach $x$ und dann nach $y$ ableite oder andersrum. Eine zweimal ableitbare Funktion $f : \mathbb{R}^{2}\to \mathbb{R}$ hat also höchstens 3 verschiedene zweite Ableitungen insgesamt.

> [!abstract] Definition *Hesse-Matrix*
> Sei $D \subseteq \mathbb{R}^{n}$ offen, $a \in D$ und $f: D \to \mathbb{R}$ zweimal stetig partiell differenzierbar. Dann heißt die Matrix $$H_{f}(a):=\left(\frac{\partial^{2}f}{\partial x_{j}\delta x_{i}}(a)\right)_{1 \leq i,j \leq n}\in \text{Mat}(n\times n, \mathbb{R})$$ die **Hesse-Matrix** von $f$ an der Stelle $a$.

^c87f05

Wegen dem Satz von Schwarz ist diese Matrix symmetrisch. 

Für den $\mathbb{R}^{2}$ gilt also:
$$H_{f}(x_{0},y_{0}):=\begin{pmatrix}\frac{\partial^{2}}{\partial x^{2}}(x_{0},y_{0})&\frac{\partial^{2}}{\partial x\partial y}(x_{0},y_{0})\\\frac{\partial^{2}}{\partial y\partial x}(x_{0},y_{0})&\frac{\partial^{2}}{\partial y^{2}}(x_{0},y_{0})\end{pmatrix}.$$

Man kommt auf diese Matrix im $\mathbb{R}^{2}$, wenn man den < Satz von Taylor > einmal auf $x_{0}$ und einmal auf $y_{0}$ anwendet. Dies gibt einem eine Annäherung für $f(x_{0}+h, y_{0}+k)$ für kleine $h,k$:
Mit $v:=\begin{pmatrix}h\\ k\end{pmatrix}$ ist nämlich $$f(x_{0}+h,y_{0}+k)=f(x_{0},y_{0})+ \frac{1}{2}v^{t}\cdot H_{f}(x_{0},y_{0})\cdot v + \text{THO}$$, wobei $\text{THO}$ = Terme höherer Ordnung, die für kleine $h,k$ irrelevant werden.

Diese Abschätzung sagt einem also folgendes:
Wenn der Term $v^{t}\cdot H_{f}(x_{0},y_{0})\cdot v$ für alle $v \neq 0$ positiv ist, dann ist $(x_{0},y_{0})$ ein *Minimum*, denn für $v=0$ ist der Term gleich 0.
Andersherum ist der Term genau dann negativ, wenn $(x_0,y_0)$ ein Maximum ist.

Wann ist der Term positiv?
$\to$ Wenn die Hesse-Matrix < *positiv definit* > ist.

Wann ist er negativ?
$\to$ Wenn die Hesse-Matrix < *negativ definit* > ist.

> **Definitheit einer Matrix**
> Eine Matrix $$A=\begin{pmatrix}a&b\\ b&d\end{pmatrix}$$ heißt:
> - *positiv definit* genau dann, wenn $ad-b^{2}>0$ und $a>0$.
> - *negativ definit* genau dann, wenn $ad-b^{2}>0$ und $a < 0$.
> - *indefinit* genau dann, wenn $ad-b^{2}<0$.

*Zusammengefasst:*

> [!important] *Prüfung eines kritischen Punktes auf Extremstelle*
> Sei $D \subseteq R^{n}$ offen, $f: D \to \mathbb{R}$ zweimal stetig differenzierbar und $a \in D$ ein kritischer Punkt von $f.$ Dann gilt:
> - Ist die Hessematrix $H_{f}(a)$ *positiv definit*, dann hat $f$ in $a$ ein **isoliertes, lokales Minimum**.
> - Ist $H_{f}(a)$ *negativ definit*, dann hat $f$ in $a$ ein **isoliertes, lokales Maximum**.
> - Ist $H_{f}(a)$ *infinit*, dann hat $f$ in $a$ einen **Sattelpunkt**.


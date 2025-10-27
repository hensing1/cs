## Beschreibung

> [!abstract] Beschreibung
> Bei der **abzählenden Kombinatorik** geht es darum, die Anzahl von möglichen Anordnungen und Auswahlen verschiedener Objekte zu zählen.

## Binomialkoeffizient
### Definition
$$\binom{n}{k}=\frac{n!}{k! \cdot(n-k)!}$$
Da $0!=1$, gilt:
$$\binom{n}{0}=1$$
Außerdem gelte für $k > n$ oder $k < 0$: $\binom{n}{k}=0$.

> $\binom{n}{k}$ beschreibt die *Anzahl verschiedener $k$-Teilmengen einer $n$-Elementigen Menge*.

### Binomischer Lehrsatz
$$(x+y)^{n} = \sum\limits_{k=0}^{n}\binom{n}{k}x^{n-k}y^{k}$$
Für $n=2$ erhält man die altbekannte binomische Formel: $(x+y)^{2} = x^{2} + 2xy + y^{2}$.

Intuitiv: man hat $n$ Terme $(x+y)$, die man miteinander multipliziert. 
Für jeden Summanden des resultierenden Polynoms hat man $k$ mal das $y$ aus diesen $n$ Klammern gewählt, und aus dem Rest jeweils das $x$. 
Wieviele Möglichkeiten gibt es, $k$ Elemente aus $n$ Objekten zu wählen?
$\rightarrow \binom{n}{k}$.

### Nützliche Formeln
$$\binom{n}{k}=\binom{n}{n-k}$$
$$\binom{n}{k-1}+\binom{n}{k}=\binom{n+1}{k}$$
$$\sum\limits_{k=0}^{n}\binom{n}{k}=2^{n}$$

## Urnenmodell
### Berechnung
Wieviele Möglichkeiten gibt es, $k$ Ziehungen aus einer Urne mit $n$ Kugeln zu machen?

|                  | ohne Zurücklegen | mit Zurücklegen      |
| ---------------- | ---------------- | -------------------- |
| ohne Reihenfolge | $$\binom{n}{k}$$ | $$\binom{n+k-1}{k}$$ |
| mit Reihenfolge  | $$\frac{n!}{(n-k)!}$$    | $$n^k$$              | 

### Details
#### Ohne Zurücklegen, mit Reihenfolge

> Wieviele $k$-*Tupel* kann ich aus einer $n$-Elementigen Menge bilden, sodass alle Stellen des Tupels verschieden sind?

Es gibt $n$ Möglichkeiten für die erste Stelle des Tupels, $n-1$ für die zweite, usw.
Für die $k$-te Stelle Stelle gibt es $n-k+1$ Möglichkeiten.

$n \cdot n-1 \cdot \ldots n-k+1 = n! / (n-k)!$

#### Ohne Zurücklegen, ohne Reihenfolge

> Wieviel $k$-*Teilmengen* einer $n$-elementigen Menge gibt es?

Das ist die Anzahl der $k$-Tupel (siehe [[Abzählende Kombinatorik#Urnenmodell#Ohne Zurücklegen, mit Reihenfolge|oben]]) geteilt durch die Anzahl der *Permutationen* von $k$ Elementen (also $k!$):
$\left(\frac{n!}{(n-k)!}\right)/k!=\binom{n}{k}$

#### Mit Zurücklegen, mit Reihenfolge

> Wieviele $k$-*Tuplel* kann ich aus einer $n$-elementigen Menge bilden?

$n$ Möglichkeiten für $k$ Stellen $\rightarrow n^{k}$

#### Mit Zurücklegen, ohne Reihenfolge

> Wieviele $k$-*Multimengen* kann ich aus einer $n$-elementigen Menge bilden?

Eine Ziehung in diesem Szenario kann man als einen Vektor aus dieser Menge darstellen:
$$M=\left\{(x_{1},x_{2},\ldots,x_{n})\in \mathbb{N}_{0}^{n} : \sum\limits_{i=1}^{n}x_{i}=k\right\}$$
$x_i$ beschreibt hierbei die Anzahl, wie oft das Element $i$ gezogen wurde.
Zur Beantwortung der obigen Frage muss man also die Kardinalität dieser Menge bestimmen.

Das ist äquivalent zu der Frage, wieviele Wege es durch ein Gitter der Größe $k \times (n-1)$ gibt:
![[Weg_durchs_Gitter.png]]

Das heißt, man muss insgesamt $k+n-1$ Schritte gehen, und davon $k$ nach oben.
$k$ Auswahlen aus einer Menge mit $k+n-1$ Elementen:
$\large\binom{k+n-1}{k}$ Multimengen.
# Definition der Booleschen Algebra
Es sei gegeben: eine Menge $V$ und zwei Operatoren $\cdot$ und $+$ (jeweils $V \times V \rightarrow V$).
Diese Schreibweise mit $\cdot$ und $+$ nennt sich auch *algebraische Schreibweise*. Hier gilt Punkt vor Strich und der Punkt kann auch weggelassen werden.

V ist dann eine boolesche Algebra, wenn die folgenden vier Kriterien (*Huntington'schen Axiome*) gelten.
## Huntingtonschen Axiome
Durch diese Axiome kann man alle anderen Rechenregeln der booleschen Algebra herleiten.
### Kommutativgesetze (K)
- $a \cdot b = b \cdot a$
- $a+b=b+a$

### Distributivgesetze (D)
- $a \cdot (b+c)=(a \cdot b)+(b \cdot a)$
- $a + (b\cdot c)=(a + b)\cdot (b + a)$

### Neutrale Elemente (N)
- $\exists e \in V : a \cdot e = a$
- $\exists n \in V : a+n=a$

### Inverse Elemente (I)
- $\forall a \in V: \exists a' \in V$
	- $a \cdot a'=n$
	- $a+a'=e$

## Rechenregeln
![[Rechenregeln Boolesche Algebra.png]]

### Resolutionsregel
> Zwei verknüpfte Monome, welche sich nur in genau einer komplementären Variable unterscheiden, können durch ihren gemeinsamen Teil ersetzt werden.

$$
\begin{aligned}
f(x_{1},x_{2},x_{3})&=x_{1}'x_{2}x_{3}+x_{1}x_{2}x_{3}\\
&=(x_{1}'+x_{1})x_{2}x_{3}\\
&=x_{2}x_{3}
\end{aligned}
$$
Aufgrund der Idempotenz geht das sogar mehrfach mit demselben Monom:
$$
\begin{aligned}
f_{2}(x_{1},x_{2},x_{3})&=x_{1}'x_{2}x_{3}+x_{1}x_{2}x_{3}'+x_{1}x_{2}x_{3}\\
&=(x_{1}x_{2}'x_{3}+x_{1}x_{2}x_{3})+(x_{1}x_{2}x_{3}'+x_{1}x_{2}x_{3})\\
&=x_{2}x_{3}+x_{1}x_{3}
\end{aligned}
$$

## Mengenalgebra
Mit [[Mengen#Operationen auf Mengen|Mengenoperatoren]] lässt sich eine boolesche Algebra definieren (Mengenalgebra)!

| Boolesche Algebra | Mengenalgebra    |                   |
| ----------------- | ---------------- | ----------------- |
| V                 | $\mathcal{P}(T)$ | Potenzmenge von Trägermenge T |
| $\cdot$           | $\cap$           | Durchschnitt      |
| $+$               | $\cup$           | Vereinigung       |
| $n$               | $\emptyset$      | Leere Menge       |
| $e$               | T                | Trägermenge       |
| $a'$              | $T \setminus A$  | Komplementärmenge |

Anwendung des Distributivgesetzes aus den Huntingtonschen Axiomen:
$$A \cup (B \cap C) = (A \cup B) \cap (A \cup C)$$
## Schaltalgebra
Die Schaltalgebra ist eine einfache Umsetzung von (und meistens synonym mit) der booleschen Algebra.

| Boolesche Algebra | Schaltalgebra |                          |
| ----------------- | ------------- | ------------------------ |
| V                 | $\set{1,0}$   | Menge aus True und False |
| $\cdot$           | $\land$       | UND-Verknüpfung          |
| $+$               | $\lor$        | ODER-Verknüpfung         |
| $n$               | 0             | False                    |
| $e$               | 1             | True                     |
| $a'$              | $\lnot a$     | Negation                 |

Dass die Schaltalgebra allen huntintonschen Axiomem folgt, lässt sich mit Wahrheitstabellen zeigen.

Die Schaltalgebra folgt natürlich auch allen Regeln der [[Aussagen]].

# Boolesche Funktionen
## Definition
Eine Schaltfunktion ist eine Funktion, welche $n$ Eingangsbits in $m$ Ausgangsgangsbits umwandelt.
$$
f:B^{n}\rightarrow B^{m},B=\set{0,1} \text{ und }m,n \in \mathbb{N}
$$
Eine boolesche Funktion ist eine Schaltfunktion mit $m=1$.
Man kann eine beliebige Schaltfunktion mit $m$ booleschen Funktionen darstellen.

Für $n$ Eingangsbits gibt es $2^{2^{n}}$ mögliche boolesche Funktionen. Diese kann man mit Wahrheitstabellen darstellen. Beispeil für $n=2$:
![[Alle_booleschen_Funktionen_n=2.png]]

Eine boolesche Funktion $f$ heißt:
- *erfüllbar*, wenn $x_1,\ldots,x_n$ existieren mit $f(x_{1},\ldots,x_{n})=1$
- *unerfüllbar*, wenn für alle $x_1,\ldots,x_n$ gilt: $f(x_{1},\ldots,x_{n})=0$
- *allgemeingültig*, wenn für alle $x_1,\ldots,x_n$ gilt: $f(x_{1},\ldots,x_{n})=1$ 
	- Ein allgemeingültiger Term heißt auch *Tautologie*.

Jede boolesche Funktion kann auch mit einem [[Syntaxdiagramm.png|Syntaxdiagramm]] oder als Baum dargestellt werden, bei welchem jeder Operand, jede Variable und jede Konstante ein Knoten ist. Die Teilbäume eines Operanden sind die Terme, welche durch diesen Operanden verknüpft werden.

## Theoreme
### Negationstheorem
> [!abstract] Theorem
> Es gilt:
> $$\lnot(f(0,1,x_{1},\ldots,x_{n},\land,\lor,\lnot))=f(1,0,\lnot x_{1},\ldots,\lnot x_{n},\lor,\land,\lnot)$$
> für einen beliebigen booleschen Ausdruck $f$.

[[TI - VL 6#Beispiel: Negationstheorem|Beweis mit struktureller Induktion]]

### Dualitätsprinzip der booleschen Algebra
Es folgt aus dem [[Boolesche Algebra#Negationstheorem|Negationstheorem]]:
> [!abstract] Theorem
> Sei
> $$\phi(0,1,x_{1},\ldots,x_{n},\land,\lor,\lnot)=\psi(0,1,x_{1},\ldots,x_{n},\land,\lor,\lnot)$$
> ein Gesetz der booleschen Algebra. Dann ist
> $$\phi(1,0,x_{1},\ldots,x_{n},\lor,\land,\lnot)=\psi(1,0,x_{1},\ldots,x_{n},\lor,\land,\lnot)$$
> ebenfalls ein Gesetz der booleschen Algebra.

### Entwicklungssatz von Shannon
> [!abstract] Theorem
> Für eine beliebige boolesche Funktion $f$ gilt:
> $$f(x_{1},\ldots,x_{n})=(x_{i}\land f_{x_{i}=1})\lor (\lnot x_{i}\land f_{x_{i}=0}).$$

## Begriffsdefinitionen
### Literal
> Variable oder invertierte Variable

### Monom
> Konjunktion (UND-Verknüpfung) beliebig vieler Literale

### Polynom
> Disjunktion (ODER-Verknüpfung) von Monomen

### Vollständiges Monom (Minterm)
> Monom, in dem alle $x_{i}$ mit $1\leq i\leq n$ genau einmal vorkommen.

Heißt deshalb Minterm, da in der Wahrheitstabelle nur eine einzige 1 steht (ist halt ein Monom (UND-Verknüpfung)).

### Vollständiges Polynom
> Polynom, in welchem jedes Monom vollständig ist.

## Normalformen

### Disjunktive Normalform (DNF)

> [!abstract] Satz:
> *Jede* boolesche Funktion lässt sich als vollständiges Polynom formulieren.

Bis auf die Reihenfolge der Monome ist die Darstellung durch ein vollständiges Polynom eindeutig.

Wie mach ich das?
- Man schnappt sich die Wertetabelle von der Booleschen Funktion, die ich umformen will.
- Jede Zeile, bei der die Funktion 1 ist, wird zu einem Minterm
- Am Ende verknüpft man alle entstandenen Minterme mit einem $\lor$, und schon hat man ein vollständiges Polynom

### Konjunktive Normalform (KNF)
Aus dem Dualitätsgesetz folgt: 
Man kann auch einen Haufen Maxterme (Terme aus ODER-Verknüpfungen, die dann in der Wahrheitstabelle nur eine einzige 0 hat) nehmen, und all diese Terme mit einem $\land$ verknüpfen. Das Ergebnis ist dann eine umgekehrte DNF, aber algebraisch Äquivalent.

### ROBDDs
Eine weitere Normalform bekommt man mit [[Binäre Entscheidungsdiagramme|binären Entscheidungsdiagrammen]].

## Vollständige Operatorensysteme
Man kann nun jede Schaltfunktion als DNF oder KNF darstellen - meistens nimmt man die DNF, aber die KNF ist einfacher wenn man hauptsächlich Einsen in seiner Schaltfunktion hat.

Damit ist auch gezeigt, dass sich jeder Ausdruck mit $\land$, $\lor$ und $\lnot$ beschreiben lässt. Damit ist $\set{\land,\lor,\lnot}$ ein *Vollständiges Operatorensystem*.

Ein weiteres vollständiges Operatorensystem ist $\set{\text{NAND}, \text{NOR}}$, und sogar $\set{\text{NAND}}$ und $\set{\text{NOR}}$. Das ist für die Technische Informatik einigermaßen signifikant, da man z.B. eine komplette CPU aus NAND-Gattern zusammenbauen kann.
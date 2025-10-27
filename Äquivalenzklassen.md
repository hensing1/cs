# Äquivalenzklassen
## Definition
In einer [[Relationen#Äquivalenzrelation|Äquivalenzrelation]] ist die Äquivalenzklasse eines Elements $a$ die *Menge aller Objekte, die mit $a$ in Relation stehen*.

$$
[\![a]\!]_{R} := \set{b \in M \space | \space b \mathrel{R} a} :\iff \text{Äquivalenzklasse von }a\text{ bezüglich}\mathrel{R}
$$
$a$ ist dann der *Repräsentant* der Äquivalenzklasse.

Statt $[\![a]\!]_R$ schreibt man auch $[\![a]\!]$ oder $\bar{a}$, wenn der Kontext klar ist.

## Eigenschaften
### Disjunktive Abdeckung
Bei einer Äquivalenzrelation auf M wird die komplette Menge durch die Äquivalenzklassen disjunkt abgedeckt.
#### Disjunktivität
Zwei Äquivalenzklassen bezüglich $R$ sind entweder identisch oder disjunkt.
$$
\forall a,b \in M : ([\![a]\!]_{R}=[\![b]\!]_{R}) \space \oplus \space ([\![a]\!]_{R} \cap [\![b]\!]_{R} = \emptyset)
$$
#### Abdeckung
Für eine Äquivalenzrelation $R$ auf $M$ gilt:
$$
\bigcup_{a \in M}[\![a]\!]=M
$$

## Beispiele für Äquivalenzklassen
### Restklassen
Für die Relation $\equiv_{n}$ auf $\mathbb{Z}$ ist **$\mathbb{Z}/n\mathbb{Z}$** oder **$\mathbb{Z}_n$** die *Menge der Äquivalenzklassen dieser Relation*. 
$$
\mathbb{Z}_{n}=\mathbb{Z}/n\mathbb{Z}=\set{[\![0]\!],[\![1]\!],[\![2]\!],\ldots,[\![n-1]\!]}=\set{\bar{0},\bar{1},\bar{2},\ldots,\overline{n-1}}
$$

### Rationale Zahlen
Alle Brüche, welche sich auf den selben Bruch kürzen lassen, bilden eine Äquivalenzklasse:
$$
\frac{a}{b} \mathrel{R} \frac{c}{d} :\iff a \cdot d = b \cdot c
$$
Heißt: $[\![\frac{4}{6}]\!]=[\![\frac{2}{3}]\!]$

## Arithmetik
Wenn man sich seine Operatoren richtig definiert, kann man mit Äquivalenzklassen Arithmetik betreiben.

### Restklassenarithmetik
Für zwei Klassen $A,B \in \mathbb{Z}_{n}$ ($A=[\![a]\!]$ und $B=[\![b]\!]$):
$$
\oplus_{n}(A,B):=[\![a+b]\!]
$$
$$
\otimes_{n}(A,B):=[\![a\cdot b]\!]
$$

Man schreibt auch $A \oplus_{n} B$ und $A \otimes_{n} B$.

Mit diesen Operatoren bildet $(\mathbb{Z}_n,\oplus_n,\otimes_n)$ den **Restklassen[[Ringe und Körper#Ring|ring]] modulo $n$**.

Weiterhin: 
$$
([\![a]\!]=[\![a']\!]) \land ([\![b]\!]=[\![b']\!])\Rightarrow [\![a+b]\!]=[\![a'+b']\!]
$$
$$
([\![a]\!]=[\![a']\!]) \land ([\![b]\!]=[\![b']\!])\Rightarrow [\![a\cdot b]\!]=[\![a'\cdot b']\!]
$$

### Arithmetik mit rationalen Zahlen
Addition:
$$
+\left(\left[\!\!\left[\frac{a}{b}\right]\!\!\right],\left[\!\!\left[\frac{c}{d}\right]\!\!\right]\right):=\left[\!\!\left[\frac{a\cdot d+c\cdot b}{b \cdot d}\right]\!\!\right]
$$
Multiplikation:
$$
\times\left(\left[\!\!\left[\frac{a}{b}\right]\!\!\right],\left[\!\!\left[\frac{c}{d}\right]\!\!\right]\right):=\left[\!\!\left[\frac{a\cdot c}{b \cdot d}\right]\!\!\right]
$$
# Definition

> Für Mengen $M,N$ ist eine Relation $R$ eine Teilmenge von $M \times N$.
> *Heißt:*
> "$a \in M$ steht in Relation zu $b \in N$" oder $a\mathrel{R}b$, falls $(a,b)\in R$.

z.B. wenn $R_<:=\set{(x,y)\in\mathbb{R}\times\mathbb{R}|\text{"x ist echt kleiner als y"}}$, dann $(1,2)\in R_<$.

Wenn $M=N$, sagt man: "$R$ ist Relation auf $M$".
Z.B. ist $R_<$ eine Relation auf $\mathbb{R}$.

**Verallgemeinerung:**
Es gibt auch $n$-stellige Relationen als Teilmenge von $M_{1}\times M_{2}\times ...\times M_{n}$.
Typischerweise ist $n=2$, dann spricht man von einer "binären Relation".

# Relationsbegriffe
## Eigenschaften binärer Relationen
### Reflexive Relation
Alle Werte der Domain haben eine Relation zu sich selbst:
$$R\text{ ist reflexiv}:\iff\forall a\in M:a\mathrel{R}a$$

### Symmetrische Relation
Alle Relationspaare sind umgekehrt ebenfalls gültig:
$$R\text{ ist symmetrisch}:\iff\forall a,b\in M:(a\mathrel{R}b\Rightarrow b\mathrel{R}a)$$

### Antisymmetrische Relation
$$R\text{ ist antisymmetrisch}:\iff\forall a,b\in M:(a\mathrel{R}b\land b\mathrel{R}a\Rightarrow a=b)$$
Antisymmetrische Relationen *können* reflexiv sein.

### Asymmetrische Relation
$$R\text{ ist asymmetrisch}:\iff\forall a,b\in M:a\mathrel{R}b\Rightarrow a\not\mathrel{R}b)$$
(wie Antisymmetrisch, aber kann nicht reflexiv sein)
Asymmetrische Relationen sind **immer** antisymmetrisch

### Transitive Relation
$$R\text{ ist transitiv}:\iff\forall a,b,c\in M:(a\mathrel{R}b\land b\mathrel{R}c\Rightarrow a\mathrel{R}c)$$

### Äquivalenzrelation
$$\mathrel{R}\text{ist Äquivalenzrelation}:\iff \mathrel{R}\text{ist reflexiv, symmetrisch, und transitiv}$$
Äquivalenzrelationen definieren [[Äquivalenzklassen]].

---

### Totale Relation
Für alle Elemente $a, b$ gilt: $a \mathrel{R} b$ oder $b \mathrel{R} a$

### Partielle Ordnung
Relation ist reflexiv, antisymmetrisch, und transitiv

### Totale Ordnung
Relation ist total, antisymmetrisch, und transitiv

## Anderer Kram
### Definitionsbereich / Domain
Geschrieben als dom(R) einer Relation R

### Werte/-Zielbereich / Co-Domain
Geschrieben als codom(R)

### Pre-Image
Alle Werte einer Domain, für welche eine Relation existiert
Geschreiben als preim(R)

### Image
Alle Werte der Co-Domain, für welche eine Relation existiert
Geschrieben als im(R)

---

# Relationsbeispiele
## Kongruenz
$$
\equiv_{n}\space:=\set{(a,b)\in\mathbb{Z}\times\mathbb{Z}\space|\space\text{a ist kongruent zu b modulo n}}
$$
$a\equiv_{n}b:\iff$ $a$ und $b$ haben den gleichen Rest bei Division mit $n$.

Kongruenz ist auch definiert für negative Zahlen.
- Mit $(k-1)n\leq a<k\cdot n$:
	- $a=(k-1)\cdot n+r$ (eindeutige Darstellung von $a$ für alle $a\in\mathbb{Z}$)
	- $\Rightarrow a\equiv_{n}r$

## Teilbarkeitsrelation
$$
|\space:=\set{(v,w)\in\mathbb{Z}^{2}\space|\space\exists c\in\mathbb{R}:v\cdot c=w}
$$
$v|w:\iff$ $v$ teilt $w$.

## Teilmengenrelation
Für Menge $M$ ist $\subseteq$ eine Relation auf $\mathcal{P}(M)$.

## Ordnungsrelation
Für einen [[Ringe und Körper#Körper|Körper]] $(K, +, \cdot)$ mit Nullelement $\mathbb{0}$ heißt eine Relation $\leq$ **Ordnungsrelation**, falls:
1. $a \leq b \lor b \leq a$ - *Vergleichbarkeit*
2. $(a \leq b \land b \leq a) \Rightarrow a = b$ - *Identitätseigenschaft*
3. $(a \leq b \land b \leq c) \Rightarrow a \leq c$ - *Transitivität*
4. $a \leq b \Rightarrow a+c \leq b+c$ - *Monotonie*
5. $(\mathbb{0} \leq a \land \mathbb{0} \leq b) \Rightarrow \mathbb{0} \leq a \cdot b$ - *Monotonie*

# Darstellung
## Graphen
Darstellung von binären Relationen auf endliche Mengen.
### Gerichteter Graph
Darstellung für $R\subseteq M\times M$
![[Gerichteter_Graph.png]]
### Bipartiter Graph
Darstellung für $R\subseteq M\times N$, insbesondere wenn $R:M\rightarrow N$
![[Bipartiter_Graph.png|200]]

# Sonderformen
Eine spezielle Art von Relationen sind [[Funktionen]].
Die Gerade $y=x-1$ als Relation ausgedrückt:
$G=\set{(x,y)\in\mathbb{R}\times\mathbb{R}|x-y=1}$
Datum: 15.12.
Kapitel: *Algebraische Strukturen*
[[19VL-Scan-Algebraische-Strukturen.pdf|Folien]]

# Ausgezeichnete Elemente
## Definitionen
![[Verknüpfung#Neutrales Element]]

![[Verknüpfung#Inverses Element]]

## Beispiele
**Addition auf $\mathbb{R}$ (schreibe: $(\mathbb{R}, +)$):**
- Neutrales Element ist die Null: $x+0=x=0+x$.
- Inverses Element zu $x$ ist $-x$: $x + (-x) = 0 = -x + x$

**Für die Multiplikation auf $\mathbb{R}$ $(\mathbb{R}, \cdot)$:**
- Neutrales Element ist 1
- Inverses Element zu $x \in \mathbb{R} \setminus \set{0}$ ist $x^{-1}=1/x$
	- $\rightarrow \mathbb{R} \setminus \set{0}$ ist die Menge der invertierbaren Elemente

**Für $(\mathbb{Z}, \cdot)$:**
- Neutrales Element ist 1
- Invertierbaren Elemente sind $\set{1,-1}$ - beide sind invers zu sich selbst ($1 \cdot 1 = (-1) \cdot (-1) = 1$)

**Für $(\mathcal{P}(M), \cap)$ für beliebige Menge $M$:**
- $M$ ist neutrales Element: $M' \cap M = M' = M \cap M'$
- $M$ ist das einzige invertierbare Element ($M \cap M = M \Rightarrow M = M^{-1}$)

**Für die Komposition von Abbildungen $(\text{Abb}(x),\circ)$ mit $f \circ g = f(g(x))$:**
- Neutrales Element ist Identitätsfunktion $id_{x}(x) := x$: $(f \circ id_{x})(x) = f(id_{x}(x)) = f(x) = id_{x}(f(x)) = (id_{x} \circ f)(x)$.
- Die Menge der invertierbaren Elemente ist $\set{f \in \text{Abb}(x) \mid f \text{ ist bijektiv}}$ (denn: nur [[Funktionen#Bijektive Funktion|bijektive Funktionen]] haben eine Umkehrfunktion)

---

# Halbgruppen, Monoide, Gruppen

![[Gruppe#Definition]]

## Beispiele#
**Abelsche Gruppen:**
- $(\mathbb{R},+)$
- $(\mathbb{Z},+)$
- $(\mathbb{R} \setminus \set{0}, \cdot)$

**Nicht-abelsche Gruppe:**
Verknüpfung von bijektiven Funktionen auf eine Menge $X$:
- $(\text{Per}(X), \circ)$ 

**Halbgruppe:**
- $(\mathbb{N},+)$

**Monoide:**
- $(\mathbb{Z}, \cdot)$
- $(\mathcal{P}(M), \cap)$

![[Gruppe#Rechenregeln]]

Außerdem gilt für einen Moniden $(M, \circ)$ und zwei Elemente $a,b$ mit Inversen $a^{-1}, b^{-1}$: $$(a \circ b) \circ (a^{-1} \circ b^{-1}) = e$$
,also ist $(a^{-1}\circ b^{-1})$ invers zu $(a \circ b)$.

Schließlich kann man einen Monoiden $(M, \circ)$ zu einer Gruppe $(G, \star)$ machen, indem man $G \subseteq M$ als Menge der invertierbaren Elemente und $\star$ als Einschränkung von $\circ$ auf $G$ definiert.
## Definition
Zusammenfassung von wohlunterschiedbaren Objekten ("Elementen")

## Grundlegendes
Schreibweise für die Menge M der Zahlen 1, 2 und 3
$M=\set{1,2,3}$

Die Reihenfolge ist irrelevant.
$M=\set{1,2,3}=\set{2,1,3}$

Man kann Abkürzungen verwenden, wenn "eindeutlich ersichtlich" ist, was gemeint ist.
$M'=\set{1,2,3,...,100}$

Mengen können ebenfalls Objekte sein.
$M''=\set{1,\set{1},\set{1,2,3}}$

**Explizite Angabe einer Menge:** $M=\set{1,2,3}$

**Implizite Angabe einer Menge:** $M=\set{x \; | \; A(x)}$
-> "M ist definiert als: alle x, für die gilt: x besitzt Eigentschaft A"

Leere Menge: $\set{} = \emptyset$
Falls die [[Mengen#Schnittmenge|Schnittmenge]] von zwei Mengen $A,B$ die leere Menge ist, sind $A$ und $B$ *disjunkt*.

### Kardinalität
#### Definition
Für eine [[Glossar#Endliche Menge|endliche Menge]] $M$ ist $|M|$ die Kardinalität, d.h. die Anzahl der Elemente in $M$.

Zwei endliche oder unendliche Mengen $A$ und $B$ haben dieselbe Kardinalität, wenn es eine [[Funktionen#Bijektive Funktion|bijektive Abbildung]] $f : A \rightarrow B$ gibt (man kann jedes $a \in A$ genau einem $b \in B$ zuordnen).

Zwei Mengen mit gleicher Kardinalität heißen auch *gleichmächtig*.

#### Abzählbare und überabzählbare Mengen
> [!Definition]
> Eine Menge $M$ heißt:
> - **abzählbar unendlich**, wenn sie dieselbe Kardinalität hat wie $\mathbb{N}$; d.h. es gibt eine [[Funktionen#Bijektive Funktion|bijektive Funktion]] von $\mathbb{N}$ auf $M$
> - **abzählbar**, wenn sie endlich oder abzählbar unendlich ist
> - **überabzählbar**, wenn sie unendlich und *nicht* abzählbar unendlich ist

##### Theoreme
###### Abzählbarkeit von Zahlenmengen
**Theorem:**
> $\mathbb{Z}$, $\mathbb{N} \times \mathbb{N}$ und $\mathbb{Q}$ sind abzählbar unendlich.
> $\mathbb{R}$ ist überabzählbar unendlich.

**Beweise:**
- [[LudS - VL 15#Abzählbarkeit von $ mathbb{Z}$|Abzählbarkeit der ganzen Zahlen]]
- [[LudS - VL 15#Abzählbarkeit von $ mathbb{N} times mathbb{N}$|Abzählbarkeit von N x N]]
- [[LudS - VL 15#Abzählbarkeit von $ mathbb{Q}$|Abzählbarkeit aller Brüche]]
- [[LudS - VL 15#Überabzählbarkeit von $ mathbb{R}$|Überabzählbarkeit der reellen Zahlen]]

###### Teilmengen
**Theorem:**
> Teilmengen von abzählbar unendlichen Mengen sind abzählbar.

**Beweis:**
[[LudS - VL 15#Abzählbarkeit von Teilmengen]]

###### Vereinigungen und Kreuzprodukte
> Wenn zwei Mengen $A$ und $B$ abzählbar sind, dann sind $A \cup B$ sowie $A \times B$ ebenfalls abzählbar.

###### Surjektive Abbildungen
> Seien $A,B$ Mengen und $A$ abzählbar unendlich. Existiert eine [[Funktionen#Arten von Funktionen#Surjektive Funktion|surjektive Abbildung]] $f : A \rightarrow B$, dann ist $B$ abzählbar.

## Wichtige Zahlenmengen
##### Natürliche Zahlen
$\mathbb{N} =\set{1,2,3,...}$
.. mit Null:
$\mathbb{N}_{0}=\set{0,1,2,3,...}$

##### Ganzzahlen
$\mathbb{Z}=\set{0,1,-1,2,-2,...}$

##### Rationale Zahlen
$\mathbb{Q}$
-> Alle Brüche

##### Reelle Zahlen
$\mathbb{R}$
-> Menge der rationalen Zahlen plus die Menge der irrationalen Zahlen

## Symbole und deren Bedeutung
$x \in M$: "x ist Element von M"
$x \notin M$: "x ist kein Element von M"

### Teilmenge
$A \subseteq B$: "A ist Teilmenge von B"
$A \subsetneq B$: "A ist *echte* Teilmenge von B" (mindestens ein Element in B, das nicht in A ist)

Das Symbol $\subset$ ist mehrdeutig. Je nach Mathematiker kann es $\subseteq$ oder $\subsetneq$ heißen.

### Operationen auf Mengen
#### Schnittmenge
$$
A \cup B := \set{x|x \in A \lor x \in B}
$$

*"A geschnitten B"*, auch genannt Konjunktion (logisches UND)

Schnittmenge von Mengen $A_1,A_2,A_3,...,A_n$: $\bigcap\limits_{i=1}^n A_i$

#### Vereinigung
$$
A \cap B := \set{x|x\in A \land x\in B}
$$
"A vereinigt mit B", auch genannt Disjunktion (logisches ODER)

Vereinigung von Mengen $A_1,A_2,A_3,...,A_n$: $\bigcup\limits_{i=1}^n A_i$

#### Differenz
$$
A \setminus B := \set{x|x\in A \land x\notin B}
$$
"A ohne B"

#### Symmetrische Differenz
$$A \Delta B := (A \cup B) \setminus (A \cap B) = (A \setminus B) \cup (B \setminus A)$$

#### Kartesisches Produkt
$$
A\times B := \set{(a,b)|a\in A \land b\in B}
$$
$(a,b)$ sind hierbei geordnete Tupel ($(a,b)\neq (b,a)$).
Das Resultat eines Kartesischen Produktes von $n$ Mengen ist eine Menge von n-Tupeln:
$A_{1}\times A_{2}\times ... \times A_{n}:=\set{(a_{1},a_{2},...,a_{n})|a_{i}\in A_{i}}$

Außerdem:
$|A_{1}\times A_{2}\times ... \times A_{n}|=|A_{1}|\cdot |A_{2}|\cdot ... \cdot |A_{n}|$

### Intervalle
#### Abgeschlossenes Intervall
$$\left[a,b \right] := \set{x\in\mathbb{R} \mid a \leq x \leq b}$$
Man nennt diese Menge *das abgeschlossene Intervall von $a$ bis $b$*. 
#### Offenes Intervall
$$(a,b) = \left]a,b \right[ := \set{x\in\mathbb{R} \mid a < x < b}$$
#### Halboffenes Intervall
**Rechtsoffen:**
$$\left(a,b \right] = \left] a,b \right]:= \set{x\in\mathbb{R}\mid a < x \leq b}$$
**Linksoffen:**
$$\left[a,b \right) = \left[ a,b \right[:= \set{x\in\mathbb{R}\mid a \leq x < b}$$

#### Abgeschlossene/Offene Mengen
Die Definitionen für [[Mengen#Abgeschlossenes Intervall|abgeschlossene]] und [[Mengen#Offenes Intervall|offene Intervalle]] lassen sich analog auf das Mehrdimensionale, d.h. $\mathbb{R}^{n}$, verallgemeinern. In diesem Fall spricht man *abgeschlossenen/offenen Mengen*.

#### Kompakte Mengen
Eine Menge $D \in \mathbb{R}^{m}$ ist *kompakt* g.d.w. sie [[Mengen#Abgeschlossene/Offene Mengen|abgeschlossen]] und *begrenzt* ist ($\exists r \geq 0: \|x\|\leq r$ für alle $x \in D$).

#### Uneigentliche Intervalle
$$\begin{gather}
\left[ a,+\infty \right[:= \set{x\in\mathbb{R}\mid x \geq a} \\
\left] a,+\infty \right[:= \set{x\in\mathbb{R}\mid x > a} \\
\left] -\infty,a \right]:= \set{x\in\mathbb{R}\mid x \leq a} \\
\left] -\infty,a \right[:= \set{x\in\mathbb{R}\mid x < a}
\end{gather}$$

## Weitere Mengen
### Potenzmenge
$$\mathcal{P}(M):=\set{X\;|\;X\subseteq M}$$
-> Die Menge aller Teilmengen von M

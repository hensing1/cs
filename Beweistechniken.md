# Begriffe
## Invariante
Eine Invariante beschreibt einen Zustand, welcher sich im Verlauf eines Algorithmus nicht verändert. Dieser Zustand heißt dann auch *invarianter Zustand*.

# Direkte und indirekte Beweise
**Direkter Beweis:**
> Herleiten der zu beweisenden Aussage durch Axiome, bzw. Umformung der Behauptung zu einer Tautologie.

**Indirekter Beweis:**
> Beweis der Behauptung durch eine andere, äquivalente Aussage.

Beispiel: man beweist $A \Rightarrow B$, indem man zeigt, dass $\lnot B \Rightarrow \lnot A$ gilt.

**Widerspruchsbeweis:**
> Man geht davon aus, dass die zu beweisende Aussage falsch ist, und leitet daraus einen Widerspruch her. 

Wenn man bei einem Widerspruchsbeweis einen Widerspruch hergeleitet hat, markiert man diesen üblicherweise mit einem ↯.

---
# Vollständige Induktion
> Beweistechnik für Aussagen über natürliche Zahlen.

z.B. $\forall n \in \mathbb{N} : A(n)$

## Grundlegendes Axiom
> [!abstract] Vollständige Induktion
> Sei $A$ Teilmenge der natürlichen Zahlen und gelten die folgenden beiden Eigenschaften:
> - *Induktionsvoraussetzung:* $1 \in A$
> - *Induktionsschritt:* $n \in A \Rightarrow n+1 \in A$
> 
> dann gilt: $A=\mathbb{N}$.

Dieses Axiom ist äquivalent zu dem folgenden Axiom:
> [!abstract] Wohlordnungsprinzip
> Jede nicht-leere Teilmenge $A$ der natürlichen Zahlen besitzt ein kleinstes Element, also
> $$A \subseteq \mathbb{N}, A \neq \emptyset \Rightarrow \exists a \in A : \forall b \in A : a \leq b$$

## Prinzip
### Induktionsanfang
für ein $k \in N_0$:
	Zeige, dass $A(k)$ gilt.

### Induktionsannahme ("Induktionsvoraussetzung")
$A(n)$ gilt für **ein** $n\geq k$ 
($n$ ist beliebig, aber fest)

### Induktionsschluss ("Induktionsschritt")
Zeigen, dass unter der Induktionsannahme gilt: $A(n)\Rightarrow A(n+1)$
Dies reicht, um zu zeigen, dass $A$ für alle $n\geq k$ gilt, denn $A(k)\land (A(k)\Rightarrow A(k+1))\Rightarrow A(k+1)$

## Strukturelle Induktion
Man kann das Induktionsprinzip auch auf alle möglichen diskreten Strukturen anwenden - zum Beispiel, wenn man beweisen will, dass eine Struktur, die gemäß festen Regeln konstruiert wird, für eine beliebige Form und Größe eine bestimmte Eigenschaft hat. 
Ein Beispiel hierfür wäre der [[LudS - VL 4#Beispiel: Euler'sche Formel über planare Graphen|Beweis, dass die Euler'sche Formel für beliebige planare Graphen gilt]].

## Alternatives Induktionsprinzip
Man kann die Induktionsannahme folgendermaßen anpassen:
Statt: 
> $A(n)$ gilt für *ein* $n\geq k$

Nimmt man:
> $A(n')$ gilt für *alle* $n'$ mit $k\leq n'\leq n$.

Der Induktionsschluss ist dann: wenn $A$ für alle Zahlen von $k$ bis $n$ gilt, dann gilt auch $A(n+1)$ (denn $n$ kann ja beliebig gewählt werden). Somit gilt $A(n)$ für alle $n\geq k$.

---
# Mengen und Funktionen
## Beidseitige Inklusion
Um zu zeigen, dass zwei [[Mengen]] $A,B$ identisch sind, können unabhängig voneinander $A\subseteq B$ und $B\subseteq A$ gezeigt werden, wenn dies einfacher ist.
$$A=B \iff A \subseteq B \land B \subseteq A$$
Anschauliches Beispiel [[LudS - VL 2#Beispiel|hier]].

## Beweis von Surjektivität
![[Funktionen#Surjektive Funktion]]

Man muss nun beweisen, dass es ein $a \in A$ gibt, für das gilt: $f(a) = b$. Dafür muss man dieses $a$ konkret angeben, und zwar in Abhängigkeit von $b$ (sodass man für jedes beliebige $b$ das zugehörige $a$ ausrechnen kann).

## Beweis von Injektivität
![[Funktionen#Injektive Funktion]]

Man muss die in der Definition beschriebene Implikation beweisen, d.h. die Formel $f(a)=f(a')$ umformen in $a=a'$. 

## Schubfachprinzip
### Definition
*Engl.: pigeonhole principle*

Idee: Wenn man $n \in \mathbb{N}$ Objekte hat, und diese auf höchstens $n-1$ Schubladen verteilen möchte, dann muss in mindestens einer Schublade mehr als zwei Objekte untergebracht werden.

Formal:
> Für zwei Mengen $A,B$ mit $|A|>|B|$ gibt es keine [[Funktionen#Arten von Funktionen#Injektive Funktion|Injektive Abbildung]] $f : A \rightarrow B$.
> Das heißt, für jede Abbildung $f : A \rightarrow B$ gibt es Elemente $a,a' \in A$ mit $a \neq a'$ und $f(a)=f(a')$.

### Anwendung
Beispielhaft: Wenn sich 13 Leute in einem Raum befinden, dann müssen mindestens zwei von ihnen im selben Monat Geburtstag haben.

Ansonsten:
- [[Endliche Automaten#"Pumping-Lemma" für DFAs|Pumping-Lemma]]

## Cantor'sches Paarungsprinzip
Beweis dafür, dass $\mathbb{N} \times \mathbb{N}$ (und damit auch $\mathbb{Q}$) abzählbar ist.

Dies wird gezeigt mit der [[Funktionen#Arten von Funktionen#Bijektive Funktion|bijektiven Funktion]] $g : \mathbb{N} \times \mathbb{N} \rightarrow \mathbb{N}, \space g(x,y) = \frac{(x+y-2)(x+y-1)}{2} + y$.

Diese Zuweisung sieht dann folgendermaßen aus:
![[Cantor Paarung.png]]

## Diagonalisierung
Dieses Beweisprinzip wird angewendet, um die Überabzählbarkeit von Mengen nachzuweisen.

Man hat eine Menge $A$, die überabzählbar ist. Beispiele für so eine Menge wären $\mathbb{R}$ oder $\mathcal{P}(\mathbb{N})$. Man führt nun einen Widerspruchsbeweis. 
Wäre $A$ abzählbar, dann gäbe es eine Funktion $f : \mathbb{N} \rightarrow A$. Man kann aber ein Element $e \in A$ bilden, das nicht im Abbild von $f$ ist, indem man alle $f(i)$ an der Stelle $i$ für alle $i \in \mathbb{N}$ manipuliert und dann zu einem neuen Element konkateniert. Dieses neue Element unterscheidet sich an mindestens einer Stelle von einem beliebigen Wert aus dem Abbild von $f$.

Anwendungsbeispiel: [[LudS - VL 15#Beweis, dass etwas nicht abzählbar ist|Überabzählbarkeit der reellen Zahlen]]

# Entscheidbarkeit von Sprachen
## Reduktionen

![[Reduktionen#^f49894]]

![[Reduktionen#^27d8a2]]

![[Reduktionen#^94ab81]] ^cc7bcb
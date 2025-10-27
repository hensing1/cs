Auch genannt *Abbildungen*.
# Definition
## Funktion / Abbildung
Für zwei Mengen $A$ und $B$ heißt eine [[Relationen|Relation]] $f \subseteq A \times B$ **Funktion** (oder **Abbildung**), falls es für *jedes* $a \in A$ *genau ein* $b \in  B$ gibt mit $(a,b) \in f$ (also $f(a)=b$).

Es müssen also die folgenden Eigenschaften erfüllt sein:
1. *Linksvollständigkeit:* $\forall a \in A \space \exists b \in B : (a,b) \in f$
2. *Rechtseindeutigkeit:* $\forall a \in A \space \forall b, c \in B : (a,b) \in f \land (a,c) \in f \Rightarrow b = c$

Statt $f \subseteq A \times B$ schreibt man $f : A \rightarrow B$.

Eine Relation, die rechtseindeutig, aber nicht linksvollständig ist, heißt auch **partielle Funktion**.
Eine partielle Funktion $f$ kann als Funktion $\bar{f}$ modelliert werden: $$\bar{f}:A \to B \cup \set{\bot}, a \mapsto \left\{ \begin{aligned}f(a)&\text{ falls } a \in \text{Def}(f) \\ \bot&\text{ sonst.}\end{aligned}\right.$$
## Definitions- und Wertebereich
Für $f : A \rightarrow B$ heißt:
- $A$ Definitionsbereich (oder Definitionsmenge), und
- $B$ Wertebereich (oder Zielbereich/Zielmenge).

## Bild und Urbild
Die Menge $f(A) := \set{b \in B \space | \space \exists a \in A : f(a) = b} \subseteq B$ heißt "Bild von $A$ unter $f$" (d.h. jedes Element aus $B$, auf das auch tatsächlich abgebildet wird).

Nimmt man eine Menge $A' \subseteq A$, dann ist $f(A')$ das "Bild von $A'$ unter $f$".

Andersherum ist die Menge $f^{-1}(B') := \set{a \in A \space | \space f(a) \in B'} \subseteq A$ das "Urbild von $B'$ unter $f$" (d.h. jedes Element aus $A$, welches durch $f$ auf $B'$ abgebildet wird).

## Graph
Der Graph $G(f)$ einer Funktion $f : A \rightarrow B$ ist definiert als $G(f) := \set{(a,f(a)) \space | \space a \in A}$. Alle diese Tupel kann man dann - Überraschung - grafisch darstellen.

## Monotonie
> Sei $D \subseteq \mathbb{R}$. Die Funktion $f : D \to \mathbb{R}$ heißt *monoton wachsend* genau dann, wenn für $x,x'\in D$ mit $x<x'$ die Ungleichung $f(x)\leq f(x')$ gilt.
> Gilt sogar die strikte Ungleichung $f(x)<f(x')$, so heißt $f$ *streng monoton wachsend*.

Die Begriffe *monoton fallend* und *streng monoton fallend* sind analog definiert.

# Schreibweise
Eine Funktion $f : \mathbb{R} \rightarrow \mathbb{R}$, welche jedes $x \in \mathbb{R}$ auf $x^{2}+5$ abbildet, schreibt man als $f(x)=x^{2}+5$ oder $f : x \xmapsto{} x^{2}+5$.

# Arten von Funktionen
## Surjektive, Injektive und Bijektive Funktionen
Darstellung für endliche Mengen:
![[injektiv_surjektiv_bijektiv.png#]]
### Surjektive Funktion
Wenn eine Funktion $f : A \rightarrow B$ auf die komplette Menge $B$ abbildet, ist die Funktion surjektiv.
$$
f\text{ ist surjektiv} \iff \forall b \in B : \exists a \in A : f(a) = b.
$$

### Injektive Funktion
Wenn keine zwei verschiedene Elemente aus $A$ auf dasselbe $b \in B$ abbilden, ist die Funktion injektiv.
$$
f \text{ ist injektiv} \iff \forall a,a' \in A : (f(a)=f(a') \Rightarrow a = a').
$$

### Bijektive Funktion
Wenn es für jedes $b$ genau ein $a$ gibt mit $f(a)=b$, ist die Funktion bijektiv.
$$
f \text{ ist bijektiv} \iff f \text{ ist injektiv und surjektiv.}
$$

## Umkehrfunktion

> [!abstract] **Umkehrfunktion**
> Für eine Funktion $f : I \to \mathbb{R}$ mit $I \subseteq \mathbb{R}$ heißt $f^{-1}$ *Umkehrfunktion*, wenn für alle $x \in I$ gilt: $$(f^{-1} \circ f)(x)=x.$$

^2568b3

Genau dann, wenn eine Funktion [[Funktionen#Bijektive Funktion|bijektiv]] ist, besitzt sie auch eine Umkehrfunktion. Also gilt auch insbesondere: $(f^{-1} \circ f)(y)=y$. ^109abb

## Verknüpfung
Für eine Menge $M$ heißt eine Funktion $\circ : M \times M \rightarrow M$ eine [[Verknüpfung|Verknüpfung]] auf $M$.


# Funktionen mit mehreren Veränderlichen

## Gradient, Jacobi-Matrix, Hesse-Matrix

Aus [[INF 022 - Analysis]]:
![[Analysis - VL 17#^71f57b]]

Der Gradient enthält alle [[Analysis - VL 17#^0e4ade|partiellen Ableitungen]] einer Funktion $f: \mathbb{R}^{n}\to \mathbb{R}$. Er liegt also im $\mathbb{R}^{n}$ und zeigt in die Richtung, in die $f$ am steilsten anwächst.
Es ist gewissermaßen die Verallgemeinerung der ersten Ableitung an der Stelle $a$.

![[Analysis - VL 17#^c87f05]]

Die Hesse-Matrix enthält alle *zweiten Ableitungen* einer Funktion $f: \mathbb{R}^{n}\to \mathbb{R}$.

Die *Richtungsableitung zweiter Ordnung* entlang eines Richtungsvektors $u$ ist gegeben durch $u^{t}H_{f}u$. 

Anders gesagt enthält sie alle ersten partiellen Ableitungen des Gradienten $\nabla f: \mathbb{R}^{n} \to \mathbb{R}^{n}$. Damit ist die Hesse-Matrix eine quadratische Spezialform der Jacobi-Matrix:

> [!abstract] Definition *Jacobi-Matrix*
> Die Jacobi-Matrix $J_{f}$ einer Funktion $f: \mathbb{R}^{m} \to \mathbb{R}^{n}$ enthält alle partiellen Ableitungen von $f:$ $$(J_{f}(\theta))_{i,j} = \frac{\partial}{\partial \theta_{j}}f(\theta)_{i}.$$


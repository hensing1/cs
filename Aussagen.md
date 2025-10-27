Diese Datei befasst sich mit allgemeinen Aussagen, welche einen eindeutigen Wahrheitswert besitzen. Für das Teilgebiet der mathematischen Logik siehe [[Aussagenlogik]].

# Wahrheitswert
Für eine Aussage $A$ ist $w(A)$ der *Wahrheitswert* von $A$.
$$
w(A)=\begin{cases*}
1 & wenn A wahr ist,\\
0 & wenn A falsch ist.
\end{cases*}
$$
Zum Beispiel:
$P(n):=$ "$n$ ist eine Primzahl"
- $w(P(5))=1$
- $w(P(7))=1$
- $w(P(8))=0$

# Logische Operatoren
Operatoren verknüpfen logische Aussagen miteinander, wobei eine neue Aussage entsteht.

| Operator    | Geschrieben      | Gesprochen                 |
| ----------- | ---------------- | -------------------------- |
| Konjunktion | $A\land B$       | "$A$ und $B$"              |
| Disjunktion | $A\lor B$        | "$A$ oder $B$"             |
| Negation    | $\lnot A$        | "nicht $A$"                |
| Äquivalenz  | $A\iff B$        | "$A$, genau dann wenn $B$" |
| Implikation | $A\Rightarrow B$ | "$A$ impliziert $B$"                           |

## Anmerkungen
- Wenn $A$ falsch ist, dann ist $A\Rightarrow B$ wahr ("aus Falschem darf alles folgen")
- Wenn $B$ wahr ist, dann ist $A\Rightarrow B$ wahr
- $(\lnot B\land(A\Rightarrow B))\Rightarrow\lnot A$
- $\lnot B\Rightarrow\lnot A\iff A\Rightarrow B$ (Kontraposition)
- $(A\iff B) \iff (A\Rightarrow B)\land (B\Rightarrow A)$
- Transitivität:
	- $((A\Rightarrow B)\land(B\Rightarrow C))\Rightarrow (A\Rightarrow C)$
	- $((A\iff B)\land(B\iff C))\Rightarrow (A\iff C)$

## Beweisführung
### Hinreichende und notwendige Bedingungen
Gibt es eine Konsequenz $K$, dann ist Bedingung $B$:
- hinreichend, wenn gilt: $B\Rightarrow K$.
- notwendig, wenn gilt: $K\Rightarrow B$.
- hinreichend und notwendig, wenn gilt: $B\iff K$.

# Wahrheitstabellen
Abbildung aller möglichen Kombinationen von miteinander verknüpften Aussagen.

Beispiel (Definition von Implikation und Äquivalenz):

| A   | B   | $A\Rightarrow B$ | $A\iff B$ |
| --- | --- | ---------------- | --------- |
| 0   | 0   | 1                | 1         |
| 0   | 1   | 1                | 0         |
| 1   | 0   | 0                | 0         |
| 1   | 1   | 1                | 1         |

# De Morgan'sche Gesetze
$$
\lnot(A\land B)\iff \lnot A\lor\lnot B
$$
$$
\lnot(A\lor B)\iff \lnot A\land\lnot B
$$
$$
A\Rightarrow B\iff\lnot A\lor B
$$

# Bindungsregeln
Konventionellerweise gilt folgende Reihenfolge, welche Operatoren bzw. Quantoren wie stark binden:
$\lnot$ vor $\lor,\land$ vor $\Rightarrow,\Leftrightarrow$ vor $\exists,\forall$


# Quantoren
**Allquantor:**
- $\forall \space n \in N : n \geq k \Rightarrow A(n)$ -> "Für alle $n \in \mathbb{N}$"

**Existenzquantor:**
- $\exists \space n \in \mathbb{N}$ -> "Es existiert mindestens ein $n \in \mathbb{N}$"
- $\exists! \space n \in \mathbb{N}$ -> "Es existiert *genau* ein $n \in \mathbb{N}$"

## De Morgan'sche Gesetze für Quantoren
- $\lnot(\exists x \in M:A(x)) \Leftrightarrow \forall x \in M: \lnot A(x)$
- $\lnot(\forall x \in M:A(x)) \Leftrightarrow \exists x \in M: \lnot A(x)$
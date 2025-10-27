Datum: 26.05.
[[Folien-2023-5-26.pdf|Folien]]
[Video](https://uni-bonn.sciebo.de/s/YVfBpu1J5oiqZGj#/files_mediaviewer/Vorlesung-07.mp4)
[[Skript AlgoII.pdf|Skript]]: Seiten 56 bis 67

# NP-Vollständigkeit

## Polynomielle Reduktionen

Uns interessiert zunächst, wie man die [[Komplexitätstheorie|Laufzeit]] zur Entscheidung verschiedener Sprachen in Relation setzen kann.

![[Reduktionen#^94ab81]]

> Gilt $A \leq_{p} B$, dann gilt $A \in P$ genau dann, wenn $B \in P$ gilt.

Konkret läuft diese Reduktion wie folgt ab:
- Für die Eingabe $x$, berechne die Many-One-Reduktion $f(x)$ in $\mathcal{O}(p(n))$ für ein Polynom $p$ und Eingabelänge $n$.
- Entscheide $f(x) \in B$  in $\mathcal{O}(p(n)+q(p(n)+n))$ für ein weiteres Polynom $q$.[^1]

Insgesamt erhält man also polynomielle Laufzeit.

[^1]: $q(p(n)+n)$ deshalb, weil die Turingmaschine zur Berechnung von $f(x)$ nicht mehr als ein Zeichen pro Rechenschritt zur Eingabe hinzugefügt haben kann.

### Beispiel: Cliquenproblem und Vertex-Cover-Problem
**Eingabe**: Ungerichteter Graph $G=(V,E)$, Zahl $k \in \mathbb{N}$
**Frage**: Gibt es für $k$ eine Teilmenge $V' \subseteq V$ mit $|V'|\leq k$, sodass jede Kante aus $E$ zu mindestens einem Knoten aus $V'$ inzident ist?

> Man kann das [[Cliquenproblem]] polynomiell auf das Vertex-Cover-Problem reduzieren, es gilt also $\text{CLIQUE}\leq_{p}\text{VC}$.

*Wie?*
![[Cliquenproblem#Reduktion auf Vertex-Cover-Problem]]

### Beispiel: Rucksackproblem

![[Rucksackproblem#Reduktion auf Kürzeste-Wege-Problem]]

## Definition
![[Komplexitätstheorie#^e3c746]]

![[Aussagenlogik#Satisfiability Problem (SAT)]]

![[Komplexitätstheorie#^024b2b]]

Findet man also z.B. einen Polynomialzeitalgorithmus für SAT, dann ist $\text{P}=\text{NP}$.

![[Komplexitätstheorie#^9201b6]]
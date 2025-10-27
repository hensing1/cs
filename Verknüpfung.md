# Verknüpfung
## Definition

> [!abstract] Definition
> Eine *[[Funktionen|Abbildung]]* $\circ : M \times M \rightarrow M$ für eine Menge $M$ heißt **Verknüpfung** auf $M$.
> Für $a,b \in M$ schreibt man statt $\circ(a,b)$ auch $a \circ b$.
> - Verknüpfung ist *assoziativ* :$\iff a \circ (b \circ c) = (a \circ b) \circ c$
> - Verknüpfung ist *kommutativ* :$\iff a \circ b = b \circ a$

^1f8fe7

## Ausgezeichnete Elemente
### Neutrales Element

> [!abstract] Definition
> Sei $\circ$ Verknüpfung auf $M$.
> $e \in M$ heißt **neutrales Element** für $\circ$, falls gilt: $e \circ a = a = a \circ e$.

Neutrale Elemente sind *immer eindeutig* (falls sie existieren). Es gibt also keine zwei neutralen Elemente.[^1]

[^1]: Beweis: Seien $e$ und $e'$ beides neutrale Elemente. Dann gilt lt. Definition: $e = e \circ e' = e'$.
### Inverses Element

> [!abstract] Definition
> Sei $M$ Menge mit *Verknüpfung* $\circ$ und *neutralem Element* $e$. Für ein $x \in M$ heißt $y \in M$ **inverses Element zu $x$**, falls gilt: $x \circ y = e = y \circ x$.
> $x \in M$ heißt *invertierbar*, falls ein inverses Element zu $x$ existiert.

Notation für inverses Element zu $x$: $x^{-1}$ oder $-x$.

Inverse Elemente sind (sofern sie existieren) eindeutig bei *assoziativer* Verknüpfung. Für ein beliebiges Element gibt es also nur ein inverses Element.[^2]

[^2]: Beweis: Seien $b$ und $b'$ inverse Elemente zu $a$. Dann gilt: $b = e \circ b = (b' \circ a) \circ b = b' \circ (a \circ b) = b' \circ e = b'$.
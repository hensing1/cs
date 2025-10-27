# Set Cover
## Definition
`Set Cover` ist ein [[Komplexitätstheorie#NP-Vollständigkeit|NP-vollständiges]] Problem.

> [!abstract] Definition *Set Cover*
> Treffe eine Auswahl aus gegebenen Teilmengen, um die Gesamtmenge vollständig abzudecken.
> 
> *Eingabe:*
> - Grundmenge $S$ mit $n$ Elementen
> - $m$ Teilmengen $S_{1}, \ldots, S_{m} \subseteq S$ mit $\bigcup\limits_{i=1}^{m}S_{i} = S$
> - Kosten $c_{1},\ldots,c_{m}\in \mathbb{N}$ pro Teilmenge
>   
> *Lösungen:* alle $A \subseteq \set{1,\ldots,m}$ mit $\bigcup\limits_{i \in A}S_{i} = S$
> *Zielfunktion:* minimiere $c(A)=\sum\limits_{i\in A}c_{i}$.

Set Cover ist eine Verallgemeinerung von [[Vertex Cover]].

## Approximation
### Greedy-Algorithmus

> **Greedy-SC**
> 1. $A := \emptyset$  `// Menge der ausgewählten Mengen`
> 2. $C := \emptyset$  `// Menge der abgedeckten Elemente`
> 3. while ($C \neq S$):
> 	1. Wähle eine Menge $S_{i}$ mit minimalen *relativen Kosten* $r_{i}(C)=\frac{c_{i}}{|S_{i}\setminus C|}.$  `// "Kosten pro neues Element"`
> 	3. $A := A \cup \set{i}; \space C := C \cup S_{i};$
> 4. return $A$

> Greedy-SC ist $H_{n}$-Approximation, wobei $H_{n}=\sum\limits_{i=1}^{n} \frac{1}{i}$ die $n$-te [[Reihen#^75c659|Harmonische Zahl]] ist. 
> Man kann somit auch sagen, dass Greedy-SC einen Approximationsfaktor von $\mathcal{O}(\log(n))$ erreicht.



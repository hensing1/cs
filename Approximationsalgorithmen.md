## Definition

> [!abstract] Definition *Optimierungsproblem*
> Ein **Optimierungsproblem** $\Pi$ besteht aus:
> - Menge $\mathcal{I}_{\Pi}$ von *Instanzen* oder *Eingaben*
> - für jedes $I \in \mathcal{I}_{\Pi}$ eine Menge $\mathcal{S}_{I}$ von *Lösungen*
> - für jedes $I \in \mathcal{I}_{\Pi}$ eine *Zielfunktion* $f_{I}: \mathcal{S}_{I}\to \mathbb{R}_{\geq 0}$, die jeder Lösung einen reellen Wert zuweist
> - Angabe, ob die Zielfunktion minimiert oder maximiert werden soll.

^8e2c91

Den Wert einer optimalen Lösung einer Instanz $I$ nennen wir $OPT(I)$.

Ein **Approximationsalgorithmus** $A$ für $\Pi$ ist ein Polynomialzeitalgorithmus, der zu jeder Instanz $i$ irgendeine Lösung aus $\mathcal{S}_{I}$ ausgibt.

> [!abstract] Definition *Approximationsgüte*
> Die **Approximationsgüte** beschreibt das Verhältnis zwischen dem Wert der Lösung, die von $A$ berechnet wird, und $\text{OPT}(I)$.
> 
> Sei $A(I)$ die Lösung von $A$ auf Eingabe $I$. Dann heißt $A$ ein *$r$-Approximationsalgorithmus*, wenn für alle Eingaben $I \in \mathcal{I}_{\Pi}$ gilt, dass $f_{I}(A(I))\leq r \cdot OPT(I)$ (falls $\Pi$ Maximierungsproblem) bzw. $f_{I}(A(I))\geq r \cdot OPT(I)$ (falls $\Pi$ Minimierungsproblem) ist.
> $A$ erreicht dann einen *Approximationsfaktor* oder eine *Approximationsgüte* von $r$.

Ist $\text{P}\neq \text{NP}$, gibt es für $\text{NP}$-schwere Probleme keinen 1-Approximationsalgorithmus.

## Beispiele
### Greedy-Algorithmen
- [[Rucksackproblem#$ frac{1}{2}$-Approximation per Greedy-Verfahren|Rucksackproblem]]
- [[Scheduling auf identischen Maschinen]]: Least Loaded und LPT

## Approximationsschema

### Definition

> [!abstract] Definition *Approximationsschema*
> Ein Approximationsschema $A$ für ein [[Approximationsalgorithmen#^8e2c91|Optimierungsproblem]] $\Pi$ ist ein Algorithmus, welcher eine Eingabe $I \in \mathcal{I}_{\Pi}$ und eine Approximationsgüte $\epsilon>0$ entgegennimmt und eine Lösung $A(I,\epsilon)$ berechnet, für deren Wert $w_A(I,\epsilon)=f_I(A(I,\epsilon))$ gilt: $$\begin{align*}&w_{A}(I,\epsilon)\leq (1+\epsilon) \cdot OPT(I) \text{ (Minimierungsproblem), bzw.}\\ &w_{A}(I,\epsilon)\geq (1-\epsilon) \cdot OPT(I) \text{ (Maximierungsproblem).}\end{align*}$$
> 
> Ein Approximationsschema heißt **polynomielles Approximationsschema** ***(PTAS)***, wenn die Laufzeit von $A$ für jede feste Wahl von $\epsilon>0$ polynomiell in $|I|$ nach oben beschränkt ist.
> Ein Approximationsschema heißt **voll-polynomielles Approximationsschema** ***(FPTAS)***, wenn die Laufzeit von $A$ polynomiell in $|I|$ und in $1/\epsilon$ nach oben beschränkt ist.

^d721dc

*Zum Beispiel:*
- $\Theta(|I|^{1/\epsilon})$ $\to$ PTAS, aber kein FPTAS
	- für $\epsilon=\frac{1}{10}$ : Laufzeit von $\Theta(|I|^{10})$
- $\Theta(|I|^{3}/\epsilon^{2})$ $\to$ FPTAS
	- für $\epsilon = \frac{1}{10}$ : Laufzeit von $\Theta(100 \cdot |I|^{3})$

> Jedes FPTAS ist auch ein PTAS.

Ein PTAS ist im Allgemeinen eher ein theoretisches Werkzeug.
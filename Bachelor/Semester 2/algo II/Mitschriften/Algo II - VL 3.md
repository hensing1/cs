Datum: 21.04.
[[Folien-2023-4-21.pdf|Folien]] bis S. 59
[[Skript AlgoII.pdf|Skript:]] Seiten 25 bis 32

*Kapitel 3*
# Berechenbarkeit
## Universelle Turingmaschine

### Motivation

Um Aussagen über die [[Berechenbarkeitstheorie|Entscheidbarkeit von Sprachen]] zu treffen, entwerfen wir eine universelle Turingmaschine, welche das Verhalten einer beliebigen Turingmaschine simulieren kann. 
Wir machen das, damit wir einen Rechner haben, der mit derselben Hardware beliebige Programme ausführen kann.

### Konzeption

Eine universelle Turingmaschine arbeitet (hier) mit dem Eingabealphabet $\Sigma=\set{0,1}$ und dem Bandalphabet $\Gamma=\set{0,1,\square}$. 
Die Eingabe ist in der Form $\langle M \rangle w$, wobei $\langle M \rangle$ die Kodierung einer Turingmaschine $M$ und $w$ die Eingabe für $M$ ist.

### Gödelnummerierung

Wir kodieren die Turingmaschine mit einer Gödelnummer.
> [!abstract] Definition
> Eine [[Funktionen#Injektive Funktion|injektive Abbildung]] aller Turingmaschinen auf $\set{0,1}^{*}$ heißt **Gödelnummerierung**.
> 
> Sie heißt *präfixfrei*, wenn kein echtes Präfix selbst eine Gödelnummer ist. 

Die Präfixfreiheit ist wichtig, damit wir genau wissen, wann die Gödelnummer aufhört und die Eingabe anfängt.

> [!info]- Konkrete Gödelnummerierung
> Kodiert wird eine Turingmaschine mit $t$ Zuständen $Q=\set{q_1,q_2,\ldots,q_t}$, dem Eingabealphabet $\Sigma=\set{X_1,X_2}$ und dem Bandalphabet $\Gamma=\Sigma \cup \set{X_3}$. 
> 
> Die Zustandsübergangsfunktion $\delta(q_i,X_j)=(q_k,X_l,D_m)$ ist definiert für $t-1$ Zustände und 3 Buchstaben. Es gibt also $3(t-1)$ Übergänge. Ein Übergang in der obigen Form wird kodiert als $0^{i}10^{j}10^{k}10^{l}10^{m}$. 
> 
> Es werden nun all diese Übergänge hintereinandergeschrieben und jeweis mit $11$ voneinander getrennt. Vorneweg schreiben wir $11$, und hintenan $111$.
> Wir legen fest, dass $q_1$ der Startzustand und $q_2$ der Terminalzustand ist. Dadurch reicht es aus, wenn wir nur die Übergänge hinschreiben.
> Da $111$ nirgendwo sonst vorkommt, ist diese Gödelnummerierung präfixfrei.

### Simulation

> Man kann für jede Turingmaschine $M$ eine universelle Turingmaschine $U$ konstruieren, welche das Verhalten von $M$ auf einer Eingabe $w$ simuliert.
> Verglichen mit der Laufzeit von $M$ auf $w$ ist die Laufzeit von $U$ auf $\langle M \rangle w$ nur um einen konstanten Faktor größer, d.h. sie hängt von $M$, aber nicht von $w$ ab.

Konkret kann die Simulation durch eine 3-Band-Turingmaschine erfolgen. Dabei steht auf dem ersten Band die Eingabe (bzw. den Bandinhalt von $M$), auf dem zweiten Band die Gödelnummer und auf dem dritten Band der Zustand von $M$.

## Unentscheidbarkeit des Halteproblems
Wir können allen Gödelnummern durch die [[Glossar#Lexikografische und kanonische Ordnung|kanonische Ordnung]] eine Reihenfolge geben. Damit bezeichnet $M_i$ die Turingmaschine, die gemäß dieser Ordnung an $i$-ter Stelle kommt.
Genauso kann man alle möglichen Eingabeworte durchnummerieren.

Da diese Ordnung eine Bijektion der natürlichen Zahlen auf die Menge aller Turingmaschinen bzw. Eingabewörter ist, kann man nicht nur den Index einer bestimmten Maschine bestimmen, sondern auch zu einem Index die entsprechende Maschine herausfinden.

![[Berechenbarkeitstheorie#Diagonalsprache]]

### Halteproblem
![[Berechenbarkeitstheorie#^37924f]]

![[Berechenbarkeitstheorie#^787d78]]

Diese Art von Beweis nennt man [[Beweistechniken#Reduktionen|Reduktionsbeweis]].

Der Programmablauf von $M_D$ sieht folgendermaßen aus:
- Input: beliebiges Wort $w$
- Bestimme den Index $i$ von $w$, sodass $w_i=w$
- Bestimme die Gödelnummer $\langle M_{i}\rangle$
- Simuliere das Verhalten von $M_H$ auf der Eingabe $\langle M_{i} \rangle w_i$ (finde also heraus, ob $M_i$ auf $w_i$ terminiert)
- Falls $M_H$ die Eingabe $\langle M_{i} \rangle w_i$ verwirft (falls $M_i$ also nicht auf $w_i$ terminieren wird):
	- akzeptiere $w$
- Falls doch:
	- Simuliere $M_i$ auf der Eingabe $w_i$
		- Falls $M_i$ das Wort $w_i$ akzeptiert:
			- verwirf $w$
		- sonst:
			- akzeptiere $w$.

Das ganze funktioniert deshalb, weil $M_H$ das Halteproblem entscheidet und somit insbesondere auf jede Eingabe terminiert. 

Da wir aber wissen, dass $M_D$ nicht existieren kann (die Diagonalsprache ist nicht entscheidbar), kann auch $M_H$ nicht existieren.
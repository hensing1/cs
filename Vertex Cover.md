# Vertex Cover
Vertex Cover ist ein [[Komplexitätstheorie#NP-Vollständigkeit|NP-vollständiges]] Problem für [[Graphen#Ungerichteter Graph|ungerichtete Graphen]].
> [!abstract] Definition *Vertex Cover*
> Finde eine möglichst kleine Knotenmenge, sodass jede Kante zu mindestens einem der Knoten inzident ist.
> 	
> *Eingabe*: ungerichteter Graph $G=(V,E)$
> *Lösungen*: alle $V' \subseteq V$, sodass $\forall e=(u,v)\in E: u \in V' \lor v \in V'$
> *Zielfunktion*: Minimiere $|V'|$

^d00c45

## Approximation

> **2-Approximation per Greedy-Verfahren**
> 1. Berechne ein inklusions-maximales [[Graphen#^f91500|Matching]] $M \subseteq E$
> 	1. *Greedy-Algorithmus*
> 	   Für jede Kante: falls beide Endpunkte noch nicht zu einer Kante im Matching gehören, füge sie dem Matching hinzu.
> 2. Sei $V(M)$ die Menge aller Knoten, die zu einer Kante aus $M$ inzident sind. 
   Gibt $V(M)$ aus.

> Gibt einen gültigen Vertex Cover für einen Graphen $G=(V,E)$ aus mit Approximationsgüte 2.
> Laufzeit: $\mathcal{O}(|V|+|E|)$ für Graphen in [[Graphen#Adjazenzliste|Adjazenzlistendarstellung]].

Einen besseren Approximationsalgorithmus als diesen hier kennt man tatsächlich nicht.

Bemerkung: welches Matching der Greedy-Algorithmus ausspuckt, hängt von der Reihenfolge der betrachteten Kanten ab. Er kann also, je nachdem, ein größeres oder kleineres Matching ausgeben (kleiner ist besser).

#### Korrektheit
Angenommen $e = (u,v) \in E$ würde nicht von $V(M)$ abgedeckt. Das heißt: Weder $u \in V(M)$ noch $v \in V(M)$. 
$M \cup \set{e}$ wäre also ein Matching, das größer wäre als das inklusions-maximale Matching aus Schritt 1.

#### Approximationsfaktor
Sei $V ^{\ast}$ ein minimales Vertex Cover. $V ^{\ast}$ muss alle Kanten abdecken, insbesondere für alle $e=(u,v) \in M$ gilt: $u \in V ^{\ast}$ oder $v \in V ^{\ast}$. Weil keine Zwei Kanten in $M$ denselben Endpunkt haben: $|V ^{\ast}|\geq |M|$.
Für unsere Lösung gilt: $|V(M)|=2|M|$. Also $|V(M)|\leq 2|V ^{\ast}|$.
$\square$

## Bezug zu Matchings

> **Theorem von König**
> In einem [[Graphen#^c50cc7|bipartiten Graphen]] $G=(V,E)$ gibt es ein Matching $M \subseteq E$ und einen Vertex Cover $A \subseteq V$, sodass $|M| = |A|$.

^4bf3dd

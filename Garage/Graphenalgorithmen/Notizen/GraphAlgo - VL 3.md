Datum: 23.04.

# Matchings

![[Graphen#^f91500]]

## Alternierende Pfade

> **Alternierende Pfade**
> Gegeben: ungerichteter Graph $G=(V,E)$, Matching $M \subseteq E$
> Ein [[Graphen#^9076aa|Pfad]] $P = (v_{0},\ldots,e_{k},v_{k})$ mit $k \geq 1$, bei dem sich $M$-Kanten und freie Kanten abwechseln, heißt *M-alternierender Pfad*.
> Ist $P$ ein [[Graphen#^9076aa|Weg]] (also kreisfrei) und sowohl $v_0$ als auch $v_k$ sind exponiert, ist $P$ ein *M-augmenteriender* (verbessernder) Pfad.

Hat man einen $M$-augmentierenden Pfad $P$, ist $M' = M \Delta P$ ($\Delta$ ist [[Mengen#Symmetrische Differenz|symmetrische Differenz]]) ein Matching mit $|M'|=|M|+1$. 
Alle freien Kanten in $P$ werden also zu Matching-Kanten und umgekehrt.

> **Theorem von Berge (1957)**
> Ein Matching $M$ in $G$ ist ein maximum Matching genau dann, wenn kein $M$-augmentierender Pfad in $G$ existiert.

## Schranken
Es kann kein Matching geben, das eine höhere Kardinalität hat als ein [[Vertex Cover]], also $|M|\leq|A|$ für alle Matchings $M$ und alle Vertex Cover $A$. Die Knoten aus $A$ decken nämlich schon alle Kanten aus $M$ ab, und es können per Definition nicht zwei Matching-Kanten am selben Knoten liegen.

Für bipartite Graphen gilt:
![[Vertex Cover#^4bf3dd]]


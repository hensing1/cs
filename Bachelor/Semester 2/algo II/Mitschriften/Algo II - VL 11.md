Datum: 21.06.
[[Folien-2023-6-21.pdf|Folien]]
[[Skript AlgoII.pdf|Skript]] - Seiten 80 bis 94
[Video](https://uni-bonn.sciebo.de/s/YVfBpu1J5oiqZGj#/files_mediaviewer/Vorlesung-09-10.mp4) (ab 46:00)

*Kapitel 5: Approximationsalgorithmen*
# Traveling Salesman Problem

## Allgemeines TSP
> **Eingabe:**
> - Menge $V=\set{v_{1},\ldots,v_{n}}$ von Knoten
> - Symmetrische Distanzfunktion $d: V \times V \to R_{\geq 0}$[^1]
> 
> **Lösungen:**
> Alle Permutationen $\pi: \set{1,\ldots,n}\to \set{1,\ldots,n}$
> 
> **Zielfunktion:**
> Minimiere $\sum\limits_{i=1}^{n-1}d(v_{\pi(i)},v_{\pi(i+1)})+d(v_{\pi(n)},v_{\pi(1)})$.

[^1]: "Symmetrisch" bedeutet, dass $d(u,v)=d(v,u)$ für alle $u,v \in V$ gilt.

### Nichtapproximierbarkeit

> Für das allgemeine TSP gibt es unter der Annahme $\text{P}\neq \text{NP}$ nicht einmal einen Approximationsalgorithmus mit *exponentiell großer* Approximationsgüte.

Das liegt daran, dass sich das [[Komplexitätstheorie#NP-Vollständigkeit|NP-vollständige]] Hamiltonkreis-Problem polynomiell auf einen solchen Approximationsalgorithmus reduzieren lässt:
- Im Hamiltonkreis-Problem sucht man in einem ungerichteten Graphen einen Kreis, welcher alle Knoten genau einmal enthält (sog. Hamiltonkreis)
- Hat man z.B. einen $2^{n}$-Approximationsalgorithmus für das allg. TSP, kann man die Distanzfunktion $d$ für einen Graphen $G=(V,E)$ wie folgt definieren: $$\forall u,v \in V, u \neq v: d(u,v)=\left\{\begin{align}1& \text{ falls } \set{u,v}\in E\\n2^{n+1}& \text{ sonst.}\end{align}\right.$$
- Nur eine TSP-Tour, die keine $n2^{n+1}$-Kante enthält, kann die Approximationsgüte erreichen. Somit müsste der Approximationsalgorithmus in polynomieller Zeit das Äquivalent eines Hamiltonkreises finden.

Eine solche Herangehensweise ist üblich, wenn man eine untere Schranke für eine Approximationsgüte zeigen möchte.

## Metrisches TSP

Beim metrischen TSP bildet die Distanzfunktion eine [[Glossar#Metrik|Metrik]] auf die Knotenmenge, d.h. insbesondere, dass die Dreiecksungleichung erfüllt ist.

Das Hamiltonkreisproblem kann nicht mehr polynomiell auf dieses TSP reduziert werden.

> Das metrische TSP ist immernoch #NP-vollständig. Es kann jedoch polynomiell approximiert werden.

### Doppelbaum-TSP

> Der Algorithmus **Doppelbaum-TSP** ist eine 2-Approximation für das metrische TSP.

**Eingabe:**
Knotenmenge $V$ und eine Metrik $d$ auf $V$.
**Algorithmus:**
1. Sei $G=(V,E)$ ein vollständiger ungerichteter Graph mit der Eingabe-Knotenmenge. Berechne einen [[Minimaler Spannbaum|minimalen Spannbaum]] $T$ von $G$ bezüglich der Distanzen $d$.
2. Erzeuge einen Multigraphen $G'$, welcher genau die Kanten von $T$ zweimal enthält. Also hat jeder Knoten in $G'$ einen geraden Grad.
3. Finde einen [[Graphen#Wege und Kreise#Weitere Begriffe|Eulerkreis]] $A$ in $G'$.[^2]
4. Gib die Knoten in der Reihenfolge ihres ersten Auftretens in $A$ aus. 

[^2]: wichtig: es gibt einen Eulerkreis genau dann, wenn jeder Knotengrad gerade ist.

![[Doppelbaum-TSP.png|400]]

Dieser Algorithmus nutzt also aus, dass ein Eulerkreis in einem zusammenhängenden Graphen zwingenderweise auch alle Knoten besucht. Er findet also den kleinsten Eulerkreis und macht daraus einen Hamiltonkreis.

*Warum ist das eine 2-Approximation?*
- Die Länge der optimalen TSP-Tour kann nicht kürzer sein als die Summe der Kanten aus dem minimalen Spannbaum. Denn wenn man eine beliebige Kante aus einem Hamiltonkreis entfernt, ist das Resultat ja ein Spannbaum. Dieser kann nicht minimaler sein als der MST.
- Der berechnete Eulerkreis im Doppelbaum hat exakt die doppelte Länge vom MST.
- Der Hamiltonkreis, der aus dem Eulerkreis generiert wird, kann nicht länger sein als der Eulerkreis. Dies liegt an der Dreiecksungleichung: ein Weg von $A$ zu $C$ kann nicht kürzer werden, wenn ich anstelle des direkten Weges einen Umweg über einen Knoten $B$ mache. Andersherum kann ein Pfad nicht länger werden, wenn ich Knoten herausnehme und stattdessen den direkten Weg nehme.

### Christofides-Algorithmus
Der Christofides-Algorithmus ist eine Verbesserung von Doppelbaum-TSP.

Um im Doppelbaum-TSP sicherzustellen, dass jeder Knotengrad gerade ist, wurde jede Kante im MST verdoppelt. Die wesentliche Beobachtung von Christofides war jedoch, dass dies verschwenderisch ist: es kann nämlich durchaus sein, dass im MST viele Knoten bereits einen geraden Grad besitzen.

Also greift sich der Christofides-Algorithmus nur die Knoten heraus, welche einen *ungeraden Grad* haben.[^3] Unter diesen Knoten wird ein [[Graphen#^f91500|perfektes Matching]] mit *minmalem Gewicht* berechnet. Dies geht in polynomieller Zeit.

Zu jedem dieser Knoten kommt also eine Kante hinzu. Vereint mit dem MST hat man also einen Multigraphen, in welchem es auf jeden Fall einen Eulerkreis gibt.

Aus diesem Eulerkreis macht man dann, wie schon im Doppelbaum-TSP, einen Hamiltonkreis.

[^3]: Da die Summe aller Knotengrade $2\cdot |E|$ ergeben muss, also gerade ist, kann es nur gerade viele Knoten mit ungeradem Grad geben.

> Der Christofides-Algorithmus berechnet eine $\frac{3}{2}$-Approximation für das metrische TSP.

Das liegt wieder daran, dass das berechnete Matching kein höheres Gewicht haben kann als die Hälfte der optimalen TSP-Tour. [^4]
Die berechnete Tour ist also höchstens das Gewicht vom MST plus das Gewicht vom Matching, also höchstens $OPT+ \frac{1}{2}OPT$.

[^4]: Beweis: nimm die optimale TSP-Tour. Überspringe alle Knoten, welche bereits einen geraden Grad im MST hatten. Nun hat man einen Hamiltonkreis für alle Knoten ungeraden Grades, und sein Gewicht ist aufgrund der Dreiecksungleichung höchstens das der TSP-Tour. Diesen Hamiltonkreis kann man in zwei perfekte Matchings unterteilen (die Kanten werden abwechselnd dem einen und dem anderen Matching zugeordnet). Diese Matchings können nicht beide mehr als die Hälfte des Gesamtgewicht dieses Hamiltonkreises haben. $\square$

## Rucksackproblem

Wir definieren zuerst, was ein *Approximationsschema* ist:
![[Approximationsalgorithmen#Approximationsalgorithmen#Definition]]

### PTAS für das Rucksackproblem

Wir beschreiben ein Approximationsschema für das Rucksackproblem.

Der Ansatz ist der folgende:
- Entwerfe ein dynamisches Programm, welches die optimale Lösung für eine KP-Instanz berechnet. Die Laufzeit dieses Programms hängt jedoch nicht vom maximalen Gewicht, sondern vom maximalen *Nutzen* $P$ eines Objekts ab. Konkret liegt die Laufzeit in $\mathcal{O}(n^{2}P)$ anstatt in $\mathcal{O}(n^{2}W)$.
- Teile alle Nutzenwerte der Objekte durch einen Faktor, welcher von $\epsilon$ abhängt, und runde ab.
- Rufe das oben definierte Programm mit den abgerundeten Nutzenwerten auf.

![[Rucksackproblem#Dynamisches Programm]]
![[Rucksackproblem#FPTAS]]
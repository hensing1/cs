# Begriffsdefinitionen
## Arten von Graphen
### Gerichteter Graph
#### Definition

> Ein **gerichteter Graph** $G = (V,E)$ besteht aus einer endlichen Menge von *Knoten* $V$ und einer Menge von *gerichteten Kanten* $E \subseteq V \times V$.
> Eine Kante $e = (u,v)$ verläuft von Knoten $u$ nach Knoten $v$. $u$ heißt Start- und $v$ heißt Zielknoten.

#### Begriffe für gerichtete Graphen
- Eine Kante $(u,v)$ heißt für Knoten $v$ **ausgehende Kante** und für Knoten $w$ **eingehende Kante**.
- Gibt es eine Kante $(u,v)$, dann ist $v$ **direkter Vorgänger** von $w$ und $w$ ist **direkter Nachfolger** von $v$.
- Für einen Knoten $v$ beschreibt der **Outgrad $d^{+}(v)$** die Anzahl der von $v$ ausgehenden Kanten und der **Ingrad $d^{-}(v)$** die Anzahl der in $v$ eingehenden Kanten.

### Ungerichteter Graph
#### Definition

> Ein **ungerichteter Graph** $G = (V,E)$ besteht aus einer endlichen Menge von *Knoten* $V$ und einer Menge von *ungerichteten Kanten* $E \subseteq \set{\set{u,v} \space | \space u,v \in V}$.
> Eine Kante $e = \set{u,v}$ verbindet die Knoten $u$ und $v$. 

Ist aus dem Kontext klar, dass $G$ ungerichtet ist, schreibt man oft für eine Kante auch $(u,v)$ statt $\set{u,v}$.

#### Begriffe für ungerichtete Graphen
- Zwei Knoten $u,v \in V$ heißen **ajdazent**, wenn es eine Kante $\set{u,v} \in E$ gibt.
- Ein Knoten $u \in V$ und eine Kante $\set{u,v} \in E$ heißen **inzident**.
- Für einen Knoten $u \in V$ ist die *Anzahl der zu $u$ inzidenten Kanten* der **Grad $d(u)$**.

### Geometrischer Graph

> [!abstract] Definition
> Ein **Geometrischer Graph** $G=(V,E)$ besteht aus:
> - einer Knotenmenge $V$ als endliche *Punktemenge* in der Ebene[^1]
> - einer Kantenmenge $E$: eine Kante $\set{u,v}$ wird betrachtet als die Menge aller Punkte, die auf der Geraden zwischen $u$ und $v$ liegen[^2]

> - Zwei Kanten $e \neq e'$ *kreuzen* sich, wenn es einen Schnittpunkt gibt, der nicht einer der Endpunkte von $e$ oder $e'$ ist.
> - Man trifft die Annahme, dass keine drei Punkte aus $V$ auf einer gemeinsamen Geraden liegen.
> - Ein kreuzungsfreier Graph unterteilt die Ebene in mehrere *Flächen*.

[^1]: ein Knoten ist also ein Vektor von zwei reellen Zahlen
[^2]: formal ist das die Strecke $\bar{uv}=\set{(1-t)u+tv \mid t \in [0,1]}$

## Wege und Kreise

> [!abstract] Definition *Weg* (V. 1)
> Ein Weg ist eine Folge von *Kanten* $e_{1},e_{2},\ldots,e_{l}$, sodass für zwei Kanten $e_{j}=(u_{j},v_{j}), \space e_{j+1}=(u_{j+1},v_{j+1})$ gilt: $v_{j} = u_{j+1}$.
> Ein Weg der Länge $l$ besitzt $l$ Kanten und durchläuft $l+1$ Knoten.

^cac772

> [!abstract] Definition *Weg* (V. 2) 
> Ein Weg ist eine Folge von *Knoten* $v_{0},\ldots,v_{l}$, bei welcher $v_{i-1},v_{i} \in E$ für alle $i \in \set{1,\ldots,l}$ gilt. Die Knoten $v_1,\ldots,v_{l-1}$ nennt man auch *Zwischenknoten* dieses Weges.
> 
> Ein Weg heißt **Kreis**, wenn gilt: $v_{0}=v_{l}$ und $l \geq 1$ (bzw. $l \geq 3$ und einfach in ungerichteten Graphen).
> Ein Kreis heißt **einfach**, wenn sein Pfad knotendisjunkt ist.

^df5d2f

> [!abstract] Definition *Weg* (V. 3) - Alpro
> Ein Weg in einem *ungerichteten Graph* ist eine alternierende Folge von Knoten und Kanten $v_{0},e_{1},v_{1},e_{2},v_{2},\ldots,e_{l},v_{l}$, sodass:
> - $\forall i \in \set{1,\ldots,l} : e_{i}=\set{v_{i-1},v_{i}}$
> - $\forall i,j \in \set{1,\ldots,l}, i \neq j : v_{i} \neq v_{j}$
> 
> Ein Weg der Länge $n$ besitzt $n$ Kanten und $n+1$ Knoten.

^c287af

> [!abstract] Definition *Pfad, Weg* (V. 4) - GraphAlgo
> Ein Pfad in einem gerichteten oder ungerichteten Graphen ist eine alternierende Folge von Knoten und Kanten.
> Ein Weg ist ist ein Pfad, in dem alle Knoten verschieden sind.

^9076aa

### Weitere Begriffe
- Ein Weg (bzw. Kreis) $v_{0},\ldots,v_{l}$ heißt **einfach**, wenn alle Knoten auf dem Weg paarweise verschieden sind (bzw. verschieden von $v_{0}=v_{l}$).
- Ein Graph, der keinen Kreis enthält, heißt **kreisfrei**, **azyklisch** oder **Wald**.
- Ein ungerichteter Graph heißt **zusammenhängend**, wenn es zwischen jedem Paar von Knoten einen Weg gibt. Ein zusammenghängender Graph, der keinen Kreis besitzt, heißt **Baum**.
	- Man kann einen ungerichteten Graphen $G$ in **Zusammenhangskomponenten** einteilen.
	  Formal definiert man dafür eine [[Relationen#Äquivalenzrelation|Äquivalenzrelation]] $v \rightsquigarrow u :\iff \text{ Es gibt einen Weg von } v \text{ nach }u.$
	  Die [[Äquivalenzklassen]] von $\rightsquigarrow$ sind die Zusammenhangskomponenten von G. ^9c3af1
- Ein Kreis heißt **Hamiltonkreis**, wenn er *jeden Knoten* genau einmal enthält.
- Ein Kreis heißt **Eulerkreis**, wenn er *jede Kante* genau einmal enthält.
	- Ein zusammenhängender Graph enthält genau dann einen Eulerkreis, wenn jeder Knoten einen geraden Grad besitzt.

## Kantengewichte
> Durch eine Funktion $w : E \rightarrow \mathbb{R}$ wird jeder Kante $e \in E$ ein **Gewicht** $w(e)$ zugewiesen.

# Lemmata und Theoreme

## Ungerichtete Graphen

> *Obere Schranke für Kantenanzahl* in ungerichtetem Graph (ohne Schleifen und Mehrfachkanten): $|E|\leq \frac{1}{2}|V|(|V|-1)$.

> *Ungerade Knotengrade*
> In einem ungerichteten Graphen ist die Anzahl der Knoten mit ungeradem Knotengrad gerade.



# Datenstrukturen für Graphen
## Adjazenzmatrix
Man hat eine Matrix $A = n \times n$ und speichert an der Stelle $a_{ij}$ eine 1, wenn von Knoten $i$ zu $j$ eine Kante verläuft. Bei gewichteten Graphen kann man auch gleich das Gewicht $w((v_{i},v_{j}))$ dort abspeichern. Falls keine Kante an der Stelle $ij$ existiert, speichert man in $a_{ij}$ 0 bzw. $\bot$ (undefiniert).
Für ungerichtete Graphen ist diese Matrix symmetrisch.

Speicherplatzbedarf: $\Theta(n^{2})$, Laufzeit: $\Theta(1)$, außer für Iteration über Nachbarknoten ($\mathcal{O}(n)$)

## Adjazenzliste
Man hat ein Feld der Länge $n=|V|$, in der man für jeden Knoten $v$ eine verkettete Liste (bzw. in der Praxis eher ein dynamisches Array) mit allen zu $v$ adjazenten Knoten, bzw. alle direkten Nachfolger von $v$ im Falle eines gerichteten Graphen.

Speicherplatzbedarf: $\Theta(n+m)$, Laufzeit linear mit der Anzahl der adjazenten Konten. Die Adjazenzliste ist aber schneller als die Adjazenzmatrix, wenn man z.B. alle adjazenten Knoten eines Knoten selektieren möchte.

## Adjazenzarray
Zwei Arrays:
- Ein Kantenarray der Länge $|E|$, das für jeden Knoten nacheinander alle adjazenten Knoten enthält.
- Ein Knotenarray der Länge $|V|$, das für jeden Knoten den Index im Kantenarray enthält, ab welchem die eigenen adjazenten Knoten anfangen.

*Speicherplatz:* $\mathcal{O}(n+m)$

*Operationen:*
- Iteration über Nachbarn von $v$: $\mathcal{O}(\delta^{+}(v))$
- Abfrage von Kante $(v,w)$: $\mathcal{O}(\delta^{+}(v))$
- Kante addieren: $\mathcal{O}(m)$
- Kante entfernen: $\mathcal{O}(\delta^{+}(v))$ für die Suche, $\mathcal{O}(m)$ fürs Entfernen

# Suche
## Breitensuche
### Einfache Breitensuche
*Ansatz:* Man arbeitet nacheinander die Nachbarknoten des derzeitigen Knoten ab. Neue Knoten, die man dabei findet, packt man in eine Warteschlange.

Diese Implementierung bestimmt die Menge der Knoten, welche von einem Startknoten $s$ aus erreichbar sind.

```
def breitensuche(V,E,s):
	Erstelle leere Ergebnisfolge F und Warteschlange Q
	Füge s in Q und F ein
	Markiere s als erkundet
	while Q nicht leer:
		n = Q.pop()
		for Kanten (u,v) in E mit u == n und w unerkundet:
			Füge w an das Ende von Q
			Markiere w als erkundet
```

### Erweiterte Breitensuche
#### Funktionsweise
Man benutzt eine Queue genau wie in der einfachen Breitensuche, man merkt sich jedoch keine Ergebnisfolge, sondern man speichert für jeden Knoten $u$ folgende Attribute:
- $u.\text{color} \in \set{\text{weiß, grau, schwarz}}$ (bedeutet: unerkundet, in Bearbeitung, fertiggestellt)
- $u.\pi$: Vorgängerknoten
- $u.d$: Distanz zum Startknoten

Holt man einen Knoten aus der Queue heraus, setzt man die Farbe auf grau. Hat man ihn abgearbeitet, setzt man die Farbe auf schwarz.
Bevor man einen neuen Knoten $v$ in die Queue einfügt, setzt man $v.\pi$ auf den aktuellen Knoten $u$ und $v.d = u.d + 1$.

#### Laufzeit
Die Laufzeit der Breitensuche in einem Graphen $G = (V,E)$ beträgt $\mathcal{O}(|V|+|E|)$ ($\mathcal{O}$ statt $\mathcal{\Theta}$, weil man unter Umständen nicht den vollständigen Graphen erkundet).
Voraussetzung: Graph ist als [[Graphen#Adjazenzliste|Adjazenzliste]] gegeben.

#### Kürzeste Wege
Für ungewichtete Graphen (bzw. Graphen mit $w(i,j)=1$ für alle $i,j$) werden durch die Breitensuche die kürzesten Wege von $s$ zu allen von $s$ erreichbaren Knoten berechnet. Man jeden dieser Wege rückwärts konstruieren, indem man von jedem Knoten $v$ stets zu seinem Vorgänger $v.\pi$ geht.
Außerdem ist für jeden Knoten $v$ die Distanz $v.d$ die Länge des kürzesten Wegs von $s$ nach $v$.

## Tiefensuche
### Einfache Tiefensuche
*Ansatz:* Man folgt an jedem Knoten dem ersten unerkundeten Nachbarn den man findet, sonst geht man einen Schritt zurück.

Diese Implementierung bestimmt die Menge der Knoten, welche von einem Startknoten $s$ aus erreichbar sind.

```
def tiefensuche(V,E,s):
	Füge s der Ergebnisfolge F hinzu
	Markiere s als erkundet
	for Kanten (u,v) in E mit u == s und v unerkundet:
		tiefensuche(V,E,s)
```

### Erweiterte Tiefensuche
#### Funktionsweise
Man speichert für jeden Knoten $u$ zusätzlich folgende Attribute:
- Farbe $u.\text{color} \in \set{\text{weiß, grau, schwarz}}$ (bedeutet: unerkundet, in Bearbeitung, fertiggestellt)
- Vorgänger $u.\pi$
- Entdeckungszeitpunkt $u.d$ (d steht für discovery)
- Fertigstellungszeitpunkt $u.f$

```
def tiefensuche(V,E,u):
	time++
	u.d = time
	u.color = grau
	for Kanten (u,v) mit v.color == weiß:
		v.pi = u
		tiefensuche(V,E,v)
	u.color = schwarz
	time++
	u.f = time
```

Annahme: Knoten $u$ ist auch beim ersten Aufruf von `tiefensuche` immer weiß.
Man kann `tiefensuche` auch mehrfach initial aufrufen, solange noch weiße Knoten im Graphen verbleiben.

#### Einteilung der Kanten
Im folgenden gerichteten Graphen wurde `tiefensuche` einmal oben links, und danach einmal unten rechts aufgerufen:

![[DFS-completed.png|450]]

Jeder Knoten $u$ ist beschriftet mit $u.d$/$u.f$.

Die Kantenbeschriftungen für eine Kante $(u,v)$ haben folgende Bedeutungen:
- $T$: $v.\pi=u$ (T steht für Tree).
- $B$: $v$ war zum Untersuchungszeitpunkt der Kante grau, die Kante zeigt also in die entgegengesetzte Richtung der T-Kanten (B steht für Back).
- $F$: $v$ war zum Untersuchungszeitpunkt der Kante schwarz und es existiert ein anderer Weg von $u$ nach $v$ (also ist $u.d < v.d$). Die Kante zeigt also in dieselbe Richtung wie die T-Kanten (F steht für forward).
- $C$: $v$ war zum Untersuchungszeitpunkt der Kante schwarz und es existiert kein anderer Weg von $u$ nach $v$ (also ist $u.d > v.d$). Das nennt man dann Kreuzkante zwischen zwei von der Tiefensuche erzeugten Bäumen (das C steht für Cross).

Ein Knoten $v$ heißt *DFS-Nachfolger* von Knoten $u$, wenn es einen Weg über T-Kanten von $u$ nach $v$ gibt.

Nun gilt für für jede zwei Knoten $u,v \in V$ genau eine der folgenden Aussagen:
> 1. Die Intervalle $[u.d,u.f]$ und $[v.d,v.f]$ sind disjunkt, und kein Knoten ist DFS-Nachfolger vom anderen.
> 2. $[u.d,u.f]\subseteq [v.d,v.f]$ sowie $u$ ist DFS-Nachfolger von $v$, oder andersherum.

> [!abstract] Eigenschaften der Kanten
> - In einem ungerichteten Graphen erzeugt die Tiefensuche nur $T$- und $B$-Kanten.
> 
> - Sowohl ein gerichteter als auch ein ungerichteter Graph ist genau dann kreisfrei, wenn die Tiefensuche keine $B$-Kante erzeugt.
> - In einem ungerichteten Graphen bilden die $T$-Kanten einen *Wald*, dessen *Zusammenhangskomponenten* genau die Zusammenhangskomponenten des Graphen sind.

#### Laufzeit
Die Laufzeit der vollständigen Tiefensuche in einem Graphen $G = (V,E)$ beträgt $\mathcal{\Theta}(|V| + |E|)$, wenn der Graph als [[Graphen#Datenstrukturen für Graphen#Adjazenzliste|Adjazenzliste]] gespeichert ist.

# Glossar
> [!abstract] Definition *Unabhängige Knotenmenge*
> Eine unabhängige Knotenmenge eines Graphen $G=(V,E)$ ist eine Menge $S \subseteq V$, sodass keine zwei Knoten aus $S$ mit einer Kante verbunden sind.

^ce5eb6

> [!abstract] Definition *Induzierter Teilgraph*
> Sei $G=(V,E)$ ein gerichteter oder ungerichteter Graph. 
> $G[V']$ ist der durch $V'\subseteq V$ induzierte Teilgraph $G'=(V',E')$ der Teilgraph, der alle Kanten enthält, die innerhalb der Menge $V'$ verlaufen, d.h. $E'=\set{(u,v)\in E \mid u,v \in V'}$.
> $G[E'']$ ist analog der durch $E'' \subseteq E$ induzierte Teilgraph $G''=(V'',E'')$ mit allen Knoten, die zu $E''$ inzident sind.

^f27dcc

> [!abstract] Definition *Clique*
> Eine Clique in einem ungerichteten Graphen $G=(V,E)$ ist eine Teilmenge $V' \subseteq V$ von Knoten, für die zwischen jedem Knotenpaar $u,v \in V'$ eine Kante in $E$ gibt.
> Eine Clique $V'$ mit $k=|V'|$ heißt *$k$-Clique von $G$*.

^961695

^7fbf96
> [!abstract] Definition *Matching*
> Ein Matching $M \subseteq E$ eines ungerichteten Graphen $G=(V,E)$ ist eine Teilmenge der Kanten, sodass es keinen Knoten gibt, der zu mehr als einer Kante aus $M$ inzident ist.
> 
> Ein Matching heißt *inklusions-maximal*, wenn man keine weitere Kante hinzufügen kann. Ein größtes Matching in einem Graphen heißt *maximum Matching*.
> Ein Matching $M$ mit $|M|=\frac{|V|}{2}$ heißt *perfektes Matching*.
> 
> - Eine Kante in $E \setminus M$ heißt frei.
> - Ein Knoten heißt *überdeckt*, falls er inzident zu einer Kante aus $E$ ist, und ansonsten *exponiert* (oder frei).
> - Mit $\nu(G)$ wird die Kardinalität eines maximum Matchings in $G$ bezeichnet.
> - Die kleinste Anzahl exponierter Knoten $\text{def}(G) = |V|-2 \nu(G)$ heißt Defizit.

^f91500

> [!abstract] Definition *Bipartiter Graph*
> Ein Graph $G = (V,E)$ ist *bipartit*, wenn $V$ in zwei Mengen $V_1$ und $V_2$ aufgeteilt werden kann, sodass alle Kanten zwischen $V_1$ und $V_2$ verlaufen: $$\forall e = (u,v) \in E: (u \in V_{1}\land v \in V_{2}) \lor (u \in V_{2} \land v \in V_{1}).$$
> Ein Graph ist bipartit genau dann, wenn er keine ungeraden Kreise (im ungerichteten Sinne) enthält.

^c50cc7

> [!abstract] Definition *Dünne und dichte Graphen*
> Sei $G = (V,E)$ ein Graph ohne Mehrfachkanten.
> - $G$ heißt *dünn* (en. sparse), wenn $|E|\in \mathcal{O}(|V|\log(|V|))$ ist.
> - $G$ heißt *dicht* (en. dense), wenn $|E|\in \mathcal{\Omega}(|V|^2)$ ist.

^a00f13



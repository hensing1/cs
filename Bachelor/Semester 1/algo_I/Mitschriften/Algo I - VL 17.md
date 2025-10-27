Datum: 17.01.
[Vorlesungsvideo](https://uni-bonn.sciebo.de/s/z5hWSb4qsDyhZSL) (Passwort: algo1)
[[algo_I_06_1.pdf|Folien - Kapitel 6.1]]
[[algo_I_06_2.pdf|Folien - Kapitel 6.2]]

# Inkrementeller Algorithmus
*Fortsetzung*

## Korrektheit

> **Stern-Lemma:**
> 1.  Nach jeder Iteration i müssen alle Dreiecke, die in dieser Iteration dazugekommen sind, den Punkt `p_i` als einen Eckpunkt haben.
> 2.  Jedes Dreieck, das vor dieser Iteration nicht mit `p_i` in Konflikt stand, ist nach der Iteration noch enthalten. 

Außderdem sind, da wir bei jedem neu hinzugefügten Dreieck die Delauney-Eigenschaft überprüft haben, alle Dreiecke, die `p_i` als Eckpunkt haben, konfliktfrei sein.
Zusammen mit dem Stern-Lemma zeigt das also die Korrektheit des Algorithmus.

## Hinzufügen eines neuen Punktes
Bevor wir `Restore_Delauney` aufrufen können, muss zunächst mit dem neuen Punkt `p_i` eine Triangulation gebildet werden.

Vorgehen:
- Finde die Fläche in der Triangulation, die `p_i` enthält.
	- Führe hierzu eine Breitensuche über die Kanten der Triangulation durch.
	- Teste für jede Kante die maximal zwei inzidenten Dreiecke.
- Falls die Fläche ein Dreieck ist:
	- füge drei Kanten von `p_i` zu allen Knoten des Dreiecks hinzu
- Falls nicht:
	- `p_i` ist Teil der äußeren Fläche
	- Gehe jede Halbkante entlang der äußeren Fläche durch
		- Falls diese Halbkante zusammen mit `p_i` ein Dreieck bildet, das *gegen den Uhrzeigersinn* verläuft, dann füge dieses Dreieck der Triangulation hinzu
		- ![[Triangulation_neuer_Punkt.png|400]]

## Laufzeit
> Für $n$ Punkte in allgemeiner Lage berechnet der inkrementelle Algorithmus die Delauney-Triangulation in Laufzeit $\mathcal{O}(n^2)$.

- Das Einfügen eines neuen Knotens geht in $\mathcal{O}(n)$[^1]
	- Da es nur linear viele Kanten gibt, geht die Breitensuche in linearer Zeit
	- Auch wenn der neue Knoten außerhalb liegt, kommen nur linear viele Kanten dazu
- Da `Restore_Delauney` höchstens einmal pro Kante aufgerufen wird, geht auch die innere For-Schleife in $\mathcal{O}(n)$
- Da die äußere For-Schleife auch $n$-mal durchlaufen wird, liegt die Gesamtlaufzeit in $\mathcal{O}(n^2)$.

[^1]: Theoretisch geht das auch schneller, aber das besprechen wir an dieser Stelle nicht. Da (s.u.) man im Erwartungswert nur konstant viele Flips pro Iteration benötigt, kriegt man mit dieser Verbesserung sogar eine Laufzeit von $\mathcal{O}(n \log n)$ hin.

### Erwartungswert für Anzahl der Flips
Gesamt-Anzahl der zurchzuführenden Flips lässt sich mit $\mathcal{O}(n^2)$ abschätzen. Geht man davon aus, dass die Reihenfolge der hinzugefügten Punkte zufällig ist, kann man jedoch im Erwartungswert von linear vielen Flips ausgehen:
- Wir gehen davon aus, dass die Permutation der ausgewählten Punkte rückwärts generiert wird
	- Man wählt also am Anfang einen Punkt $p_n$ zufällig gleichverteilt aus der Gesamtmenge, dann $p_{n-1}$ aus der Restmenge, usw.
- Nun gilt für *jeden Knoten* in einer *beliebigen Triangulation*:
	- da die Gesamtzahl der Kanten linear abhängig ist von der Gesamtzahl der Knoten, hat jeder Knoten **unabhängig von der Größe des Graphen konstant viele Kanten**.
	- dies gilt also auch für den Knoten, den wir zufällig für unsere Permutation ausgewählt haben.
- Da laut Stern-Lemma nur Flips für Kanten durchgeführt werden, die am Ende inzident zu dem neuen Knoten sind, und der Knotengrad im Erwartungswert konstant ist, ist auch die erwartete Anzahl von Flips für jeden Knoten konstant.

Das heißt, wir können die Gesamtzahl der durchgeführten Flips tatsächlich mit $\mathcal{O}(n)$ abschätzen, und damit die erwartete Laufzeit von `Restore-Delauney()` mit $\mathcal{O}(1)$.

# Nächste-Nachbarn-Suche
Wir betrachten das Problem der *Nächste-Nachbarn-Suche*: welchem Punkt aus einer gegebenen Punktemenge ist ein gegebener Punkt (bzw. Standort) $q$ am nächsten?

Die Distanz zwischen zwei Punkten definieren wir als den euklidischen Abstand:
> Für $a = (a_{1},a_{2}) \in \mathbb{R}^{2}$ und $b = (b_{1},b_{2}) \in \mathbb{R}^2$ ist $||b-a||=\sqrt{(b_{1}-a_{1})^2+(b_2-a_2)^2}$.

Gesucht ist nun eine Datenstruktur, die für eine beliebige Punktemenge $S$ die folgende Operation unterstützt:
Gegeben einen Punkt $q$, finde einen nächsten Nachbarn (mit minimalem euklidischen Abstand) von $q$ in $S$.

Dieses Problem ist eng verwandt mit der *Punktlokalisierung*. Gegeben eine Triangulation sowie einen Punkt $q$: in welchem Dreieck der Triangulation ist $q$ enthalten?

## Voronoi-Diagramm
Ein Voronoi-Diagramm teilt die Ebene $\mathbb{R}^2$ für $n$ Punkte in $S$ in $n$ *Voronoi-Regionen* auf. Für einen Punkt $p \in S$ die Voronoi-Region $\mathcal{V}(p,S)$ die Menge der Punkte, die $p$ am nächsten liegen:
$$\mathcal{V}(p,S)=\set{x \in \mathbb{R}^{2} \mid \forall q \in S \setminus \set{p} : \space ||x-p||\space < \space||x-q||}$$

Betrachte zunächst den **Bisektor** $B(p,q)$zwischen zwei Punkten $p$ und $q$. Dies ist eine *Gerade*, welche aus allen Punkten besteht, die denselben Abstand zu $p$ und $q$ haben (Mittelsenkrechte zwischen $p$ und $q$).

Ein Bisektor $B(p,q)$ unterteilt die Ebene in die Mengen
$$\begin{align*}
B_{-}(p,q) = \set{x \in \mathbb{R}^{2} \mid \space ||p-x||\space < \space||q-x||}\\
B_{+}(p,q) = \set{x \in \mathbb{R}^{2} \mid \space ||p-x||\space > \space||q-x||}
\end{align*}$$
sowie den Bisektor selbst.

Nun können wir die Voronoi-Region von einem Punkt $p$ wie folgt definieren:
$$\mathcal{V}(p,S)=\bigcup\limits_{q \in S \setminus \set{p}}B_{-}(p,q).$$
Die Voronoi-Regionen sind nun die Flächen eines kreuzungsfreien geometrischen Graphen $G$, der als *Voronoi-Diagramm* bezeichnet wird.

Die Kanten von $G$ heißen *Voronoi-Kanten* und die Knoten von $G$ heißen *Voronoi-Knoten*.

Manche Voronoi-Kanten sind Strahlen (sie sind also unbeschränkt). Für diese Kanten definiert man einen abstrakten Voronoi-Knoten im Unendlichen als Endpunkt.

![[Voronoi-Diagramm.png|250]]

### Zusammenhang mit Delauney-Triangulationen
> Sei S eine endliche Menge von Punkten in allgemeiner Lage in der Ebene. Für den Graph des Voronoi-Diagramms von S und den Graph der Delaunay-Triangulation von S gilt:  
> 1. $p, q, r \in S$ bilden ein Delaunay-Dreieck genau dann, wenn es einen Voronoi-Knoten gibt, der zu $\mathcal{V}(p, S),  \mathcal{V}(q, S), \mathcal{V}(r , S)$ inzident ist.  
> 2. $p, q \in S$ sind genau dann durch eine Delaunay-Kante verbunden, wenn es eine Voronoi-Kante gibt, die $\mathcal{V}(p, S)$ und $\mathcal{V}(q, S)$ voneinander abgrenzt.

![[Delauney_plus_Voronoi.png|250]]

Der Voronoi-Knoten ist dabei der *Umkreismittelpunkt* des entsprechenden Delauney-Dreiecks.[^2] 

Eine Kante ist dann eine Delauney-Kante, wenn ein Punkt existiert, für den die beiden Endpunkte die nächsten Nachbarn sind. Die Voronoi-Kante ist die Menge von genau diesen Punkten.

[^2]: Der Umkreismittelpunkt des Dreiecks hat dieselbe Distanz zu allen drei Punkten, ist also der Schnittpunkt der drei Bisektoren. Außerdem sind diese drei Punkte die nächsten Nachbarn zu dem Umkreismittelpunkt, es kann also keinen weiteren Punkt innerhalb dieses Dreiecks geben (siehe Delauney-Eigenschaft).

### Berechnung des Voronoi-Diagramms
Gegeben sei eine Punktemenge $S$.
- Berechne die Delauney-Triangulation $T$ von $S$
- Führe eine Breitensuche auf Graph von $T$ durch:
	- Für Kante $(p,q)$ von $T$, berechne Voronoi-Kante $e$ inzident zu $\mathcal{V}(p,S)$ und $\mathcal{V}(q,S)$
	- Endpunkte von $e$ sind Umkreismittelpunkte der beiden zu $(p,q)$ inzidenten Dreiecke in $T$
	- Falls die Kante zu der äußeren Fläche inzident ist, ist sie zu dieser Seite unbeschränkt

Da die Breitensuche wieder lineare Laufzeit benötigt, ist die Laufzeit maßgeblich abhängig von der Berechnung der Delauney-Triangulation.

## Punktlokalisierung
Man möchte herausfinden, in welchem Dreieck einer Triangulation $T$ ein Punkt $q$ enthalten ist.

### Lineare Suche
Man iteriert über alle Kanten der Triangulation und überprüft, ob der Punkt in einer der beiden inzidenten Flächen enthalten ist.
- Speicherplatz der linearen Suche: $\mathcal{O}(n)$
- Anfragezeit der linearen Suche: $\mathcal{O}(n)$

### Doppelte Binäre Suche
- Speichere die X-Koordinaten aller Punkte in einem Array
- Berechne die Schnittpukte zwischen den Vertikalkanten dieser Punkte und den Kanten der Triangulation
- Sortiere diese Kanten nach ihren Y-Start- und Endpunkten
- Speichere diese Kantenmengen in einem verallgemeinerten Suchbaum (< bitte Link>), sodass sie zwischen ihren entsprechenden X-Koordinaten zu finden sind
- Speichere zudem das Dreieck der Triangulation, das zu dem Zwischenraum zwischen zwei Kanten gehört

Nun kann man, wenn man einen Punkt abfragen will, zunächst eine binäre Suche auf seine X-Koordinate machen, und dann (auch nach binärem Suchprinzip) prüfen, zwischen welchen Kanten sich der Punkt befindet. Ein Punkt $q$ ist oberhalb einer Kante $(u,v)$, wenn das Tupel $(u,v,q)$ *gegen den Uhrzeigersinn* orientiert ist.

![[Punktlokalisierung-Doppelte_Binäre_Suche.png]]

- Speicherplatz: $\mathcal{O}(n^2)$
- Anfragezeit: $\mathcal{O}(\log n)$


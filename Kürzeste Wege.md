# Kürzeste Wege
## Single-Source Shortest Path Problem (SSSP)
Gegeben: gerichteter Graph $G=(V,E)$ mit Kantengewichten $w : E \rightarrow \mathbb{R}$, sowie ein Startknoten $s \in V$. Gesucht ist ein kürzester Weg von $s$ nach $v$ für jeden Knoten $v \in V$ und die Entfernung $\delta(s,v)$.

Ein [[Graphen#Wege und Kreise|Weg]] zwischen zwei Knoten heißt kürzester Weg, wenn die Summe seiner Kantengewichte minimal ist.

Falls $\forall e \in E : w(e) = 1$, so löst die [[Graphen#Breitensuche|Breitensuche]] das SSSP.

**Wichtige Eigenschaft von kürzesten Wegen:**
> In einem kürzesten Weg $s_0,s_1,\ldots,s_k$ von $s_0$ nach $s_k$ ist auch jeder Teilweg $s_i,\ldots,s_j$ mit $0≤i≤j≤k$ der kürzeste Weg von $s_i$ nach $s_j$.

Generell sind auch *negative Kantengewichte erlaubt*. Man muss dann jedoch aufpassen, dass man keine *[[Graphen#Wege und Kreise#Allgemeine Definition|Kreise]] mit negativem Gesamtgewicht* in seinem Graphen hat - dann könnte man nämlich diesen Kreis beliebig oft ablaufen, und alle Knoten des Kreises sowie alle von diesem Kreis erreichbaren Knoten hätten eine Distanz von $- \infty$.

Wenn kein solcher Kreis existiert, sind alle kürzesten Wege *einfach*.[^1]

[^1]: Im Sinne von: kein Knoten kommt doppelt vor.

### Dijkstra-Algorithmus
Der Dijkstra-Algorithmus löst das SSSP. 
Negative Kantengewichte sind hierbei nicht erlaubt.

#### Kürzeste-Wege-Baum
> Der Teilgraph $G'=(V',E')$ mit $V' \subseteq V$ und $E' \subseteq E$ heißt **Kürzeste-Wege-Baum**, wenn:
> - $V'$ die Menge der Knoten ist, die von $s$ aus in $G$ erreichbar sind
> - $G'$ ein *gewurzelter Baum* mit Wurzel $s$ ist (heißt: $G'$ ist azyklisch, auch wenn man die Kanten als ungerichtet betrachtet)
> - Für alle $v \in V'$ ist der eindeutige Weg von $s$ zu $v$ in $G'$ ein kürzester Weg von $s$ nach $v$ in $G$.

Der Dijkstra-Algorithmus berechnet damit einen Kürzeste-Wege-Baum. Der Speicherverbrauch liegt hierbei in $\mathcal{O}(|V|)$, da für jeden Knoten lediglich der Vorgänger gespeichert wird.

#### Implementierung und Laufzeit
Wir benötigen eine Datenstruktur, die die Menge $V \setminus S$ verwalten kann, und in der wir effizient die Entfernung zu den Knoten in dieser Menge speichern können, sowie das entsprechende Minimum selektieren als auch die Entfernung aktualisieren können.

Konkret brauchen wir die folgenden drei Operationen:
- `Insert(x,d)`: Füge ein neues Element $x$ mit Schlüssel $d \in \mathbb{R}$ ein
- `Extract-Min()`: Extrahiere das Element mit dem kleinsten Schlüssel
- `Decrease-Key(x, d1, d2)`: Ändere den Schlüssel des Objektes $x$ von $d_{1}$ auf $d_{2}<d_{1}$.

Dies lässt sich mit einer [[Heaps#Prioritätswarteschlange|Prioritätswarteschlange]] umsetzen, die im inneren allerdings einen Min-Heap anstatt eines Max-Heaps hat.

```
def Dijkstra(G,w,s):
	for v in V: 
		v.d = inf
		v.pi = null
		v.color = weiß

	s.d = 0
	s.color = grau
	queue = Priority_Queue()
	queue.insert(s,0)

	while queue.size > 0:
		u = queue.extract_min()
		for (u,v) in u.outgoing_edges:
			if v.color == weiß:
				v.color = grau
				v.d = u.d + w(u,v)
				v.pi = u
				queue.insert(v, v.d)
			else if u.d + w(u,v) < v.d:
				queue.decrease_key(v, v.d, u.d + w(u,v))
				v.d = u.d + w(u,v)
				v.pi = u
		u.color = schwarz
```

Da die Prioritätswarteschlange all diese Operationen mit Laufzeit $\mathcal{O}(\log n)$ unterstützt, ergibt sich für den Dijkstra-Algorithmus insgesamt eine Laufzeit von $\mathcal{O}((n+m)\log n)$, sofern der Graph als [[Graphen#Datenstrukturen für Graphen#Adjazenzliste|Adjazenzliste]] gegeben ist.
Das liegt daran, dass für höchstens jede der $m$ Kanten einmal `Decrease-Key` und für höchstens jeden der $n$ Knoten einmal `Extract-Min` aufgerufen wird. 


## All-Pairs Shortest Path Problem (APSP)
Beim APSP haben wir lediglich einen Graphen $G=(U,V)$ mit Gewichtung $w$ gegeben, und wir möchten für jedes Paar $u,v \in V$ einen kürzesten Weg von $u$ nach $v$ und dessen Länge $\delta(u,v)$ berechnen.

### Floyd-Warshall-Algorithmus
Der Floyd-Warshall-Algorithmus löst das ASPS mittels [[Algorithmen#Methoden zum Entwurf von Algorithmen#Dynamische Programmierung|Dynamischer Programmierung]].

#### Definition der Teilprobleme
Man nummeriert erst mal seine Knoten durch von $1$ bis $n$.
Die Teilprobleme sehen nun aus wie folgt:
> Finde einen kürzesten i-j-Weg $P_{ij}^{k}$, der nur [[Graphen#Wege und Kreise#Allgemeine Definition|Zwischenknoten]] aus $\set{1,\ldots,k}$ benutzen darf.

Dann lässt man das $k$ nach und nach von $0$ nach $n$ laufen. Wenn man alle Teilprobleme $P_{ij}^{n}$ gelöst hat, hat man auch das APSP gelöst.

#### Rekursive Berechnung der Teilprobleme
Mal angenommen, man hat schon alle Teilprobleme $P_{ij}^{k-1}$ berechnet. Den Weg $P_{ij}^{k}$ kann man mithilfe dessen auf folgende Weise zusammensetzen:

**1. Fall:** Der Knoten $k$ ist *nicht* als Zwischenknoten in $P_{ij}^{k}$ enthalten.
In diesem Fall ist $P_{ij}^{k}=P_{ij}^{k-1}$.

**2. Fall:** $P_{ij}^{k}$ enthält den Knoten $k$ als Zwischenknoten.
In diesem Fall ist $P_{ij}^{k}=$ $i \xrightarrow{P_{ik}^{k-1}} k \xrightarrow{P_{kj}^{k-1}} j$, da $P_{ij}^{k}$ ein *einfacher Weg* ist und als solcher $k$ nicht zweimal vorkommen kann.

Damit kann man die Distanz $\delta_{ij}^{(k)}$ für den Weg $P_{ij}^{k}$ wie folgt berechnen:
$$
d_{ij}^{(k)}=
\left\{
\begin{array}{ll}
w(i,j) & \text{ für }k=0,\\
\text{min} \set{\delta_{ij}^{(k-1)},\delta_{ik}^{(k-1)}+\delta_{kj}^{(k-1)}} & \text{ für }k>0.
\end{array}
\right.
$$
Dabei sei $w(i,j)=\infty$ für $(i,j)\not\in E$.

#### Implementierung
Sei `W` die [[Graphen#Datenstrukturen für Graphen#Adjazenzmatrix|Adjazenzmatrix]] für unseren Graphen $G$ und `D[k]` die Matrix mit den Distanzen $\delta_{ij}^{(k)}$ für alle $(i,j) \in \set{1,\ldots,n} \times \set{1,\ldots,n}$.

```
def Floyd-Warshall(W):
	D[0] = W
	for k in {1,...,n}:
		D[k] = (n x n)-Nullmatrix
		for (i,j) in {1,...,n} x {1,...,n}:
			D[k][i,j] = min{ D[k-1][i,j], D[k-1][i,k] + D[k-1][k,j] }
	return D[n]
```

#### Negative Kreise
Prinzipiell sind *negative Kantengewichte* für den Floyd-Warshall-Algorithmus kein Problem.

Gibt es einen *negativen Kreis*, macht das kürzeste-Wege-Problem eigentlich keinen Sinn mehr, da man ja unendlich oft diesen negativen Kreis entlanggehen könnte, und damit alle Knotenverbindungen, die über diesen Kreis verlaufen, die Entfernung $-\infty$ haben.
Der Floyd-Warshall-Algorithmus berechnet Entfernungen in Graphen mit negativen Kreisen ==nicht korrekt==.

Man kann aber immerhin feststellen, ob ein solcher negativer Kreis existiert: 
> G enthält negativen Kreis mit Knoten aus $i \cup \set{1,\ldots,k}$, g.d.w. $\delta_{ii}^{(k)}<0$.

#### Laufzeit
> Der Floyd-Warshall-Algorithmus löst das APSP für Graphen ohne Kreise mit negativem Gesamtgewicht, die als Adjazenzmatrix dargestellt werden, in Zeit $\Theta(n^3)$.

Das geht eigentlich direkt aus der Implementierung hervor: man hat drei geschachtelte For-Schleifen, und der Rest geht in $\Theta(1)$.

##### Vergleich mit dem Dijkstra-Algorithmus
Man kann das APSP natürlich auch lösen, indem man den Dijkstra-Algorithmus $n$ mal aufruft (1 mal für jeden Knoten, jeweils mit Laufzeit $\mathcal{O}(m \log n$).
Damit ergibt sich eine Laufzeit von $\mathcal{O}(nm \log n)$.

Das heißt, welche Variante besser ist, hängt von der Menge der Kanten ab: ist $m \in \mathcal{o}(n^{2}/\log n)$, ist Dijkstra besser; sind es mehr Kanten, ist Floyd-Warshall besser.

Das ergibt auch intuitiv Sinn - der Floyd-Warshall-Algorithmus klappert ja jeden Eintrag der Adjazenzmatrix ab, egal, ob dort eine Kante vorhanden ist oder nicht.
Dijkstra wiederum arbeitet mit einer Adjazenzliste, insofern werden nichtexistente Kanten auch nicht berücksichtigt.

Zu beachten ist jedoch, dass FW mit negativen Kantengewichten zurechtkommt, Dijkstra jedoch nicht.

#### Rekonstruktion der Pfade
Um die eigentlichen kürzesten Wege rauszufinden, muss man sich merken, ob $\delta_{ij}^{(k)}$ durch $\delta_{ij}^{(k-1)}$ oder durch $\delta_{ik}^{(k-1)}+\delta_{kj}^{(k-1)}$ entstanden ist: im ersten Fall ist der Vorgängerknoten von $j$ der auf dem Pfad $P_{ij}^{(k-1)}$, im zweiten Fall der auf dem Pfad $P_{kj}^{(k-1)}$.

Sei also $\pi_{ij}^{(k)}$ der Vorgänger von $j$ auf $P_{ij}^{(k)}$.

$$
\pi_{ij}^{(0)}=
\left\{
\begin{array}{ll}
\text{NULL} & \text{falls }i=j \text{ oder }w_{ij}=\infty,\\
i & \text{sonst}.
\end{array}
\right.
$$
$$
\pi_{ij}^{(k)}=
\left\{
\begin{array}{ll}
\pi_{ij}^{(k-1)} &
\text{falls } \delta_{ij}^{(k)}=\delta_{ij}^{(k-1)},\\
\pi_{kj}^{(k-1)} &
\text{falls } \delta_{ij}^{(k)}<\delta_{ij}^{(k-1)}.
\end{array}
\right.
$$

## Beschränktes Kürzeste-Wege-Problem

Gegeben einen Graphen $G=(V,E)$ mit $w: E \to \mathbb{N}_{0}$ und $c: E \to \mathbb{N}_0$, sowie Start- und Zielknoten $s,t\in E$ und Konstanten $W,C \in \mathbb{N}_{0}:$ gibt es einen Weg $P$ von $s$ nach $t$, sodass das Gesamtgewicht $\sum_{e\in P}w(e)$ höchstens $W$ und die Gesamtkosten $\sum_{e\in P}$ höchstens $C$ sind?

Dieses Problem ist eng verwandt mit dem [[Rucksackproblem]].
Datum: 12.01.
[Vorlesungsvideo](https://uni-bonn.sciebo.de/s/AiOlBaXCDSSUlsm) (Passwort: algo1)
[[algo_I_06_1.pdf|Folien]] (Seiten 74 bis 125)

# Fortune-Algorithmus
## Numerische Prüfungen
### Orientierung eines Dreiecks
Sei $(a,b,c)$ ein Dreieck in unserer Triangulation. Wir wollen zunächst wissen, ob dieses Dreieck mit oder gegen den Uhrzeigersinn orientiert ist:
![[Dreiecksorientierung.png|350]]

Wenn man die Punkte $a=(a_{1},a_{2}),\space b=(b_{1},b_{2}), \space c=(c_{1},c_{2})$ wie folgt in eine $3 \times 3$-Matrix schreibt:$$\begin{pmatrix}a_{1}&a_{2}&1\\b_{1}&b_{2}&1\\c_{1}&c_{2}&1\end{pmatrix}$$
dann beschreibt die [[Matrizen#Determinante|Determinante]] dieser Matrix die *doppelte Dreiecksfläche* von $(a,b,c)$.[^1] Ferner ist dieser Wert *negativ*, genau dann wenn das Dreieck *im Uhrzeigersinn* orientiert ist.[^2]

Wir legen die Konvention fest, dass Dreiecke positiv orientiert sind.

[^1]: $\begin{gather}\frac{1}{2}\det \begin{pmatrix}a_{1}&a_{2}&1\\b_{1}&b_{2}&1\\c_{1}&c_{2}&1\end{pmatrix}=\\\frac{(c_{1}-a_{1})(c_2+a_2)+(b_1-c_1)(b_2+c_2)+(a_1-b_1)(a_2+b_2)}{2}\end{gather}$
[^2]: Man könnte die Orientierung der Dreiecke auch mit Winkelfunktionen bestimmen, die möchte man in diesem Kontext jedoch tendenziell vermeiden, da sie zu numerischen Fehlern führen können (vermutlich wegen Gleitkommazahlen). Die Determinante hingegen ist sehr einfach zu berechnen.

### Orientierung eines Punktes zu einem Dreieck
Gegeben seien drei Punkte $a,b,c$ sowie eine Gerade, die durch $a$ und $b$ verläuft und die in Richtung *von $a$ nach $b$ orientiert* ist.
Dann liegt der Punkt $c$ genau dann *links* von der Geraden, wenn das Dreieck $(a,b,c)$ *positiv* orientiert ist (also gegen den Uhrzeigersinn verläuft).

Hiermit kann man nun auch testen, ob ein Punkt innerhalb eines Dreiecks liegt:
sei $(a,b,c)$ ein (positiv orientiertes) Dreieck und $q$ ein beliebiger Punkt in der Ebene. $q$ ist genau dann in dem Dreieck, wenn er jeweils links von den Geraden durch $a$ und $b$, $b$ und $c$, sowie $c$ und $a$ liegt.

### Zulässigkeit eines Flips
Ein Flip ist genau dann zulässig, wenn die beiden entstehenden Dreiecke nachher genauso orientiert sind wie die beiden vorherigen Dreiecke:
![[Unzulässiger_Flip.png|350]]
Dieser Flip ist also unzulässig.

### Orientierung eines Punktes zu einem Kreis
Ein Punkt $q=(q_1,q_2)$ befindet sich genau dann in einem Kreis mit Mittelpunkt $p=(p_1,p_2)$ und Radius $r$, wenn gilt: $$(p_1-q_1)^2+(p_2-q_2)^2<r^2.$$
## Halbkanten-Datenstruktur
Mit einer Halbkanten-Datenstruktur lassen sich Triangulationen speichern und manipulieren.

Man hat pro Knoten ein Objekt und für jede Kante zwei Objekte (eine Halbkante in jede Richtung).
Jede Halbkante ist implizit mit der Fläche assoziiert, die zu ihrer linken Seite liegt.

Eine Halbkante (half-edge) speichert folgende Zeiger:
- `start` - der Startknoten der Halbkante
- `twin` - die andere Halbkante, welche genau in die entgegengesetzte Richtung verläuft
- `next` - die nächste Halbkante, welche entlang der Fläche zur Linken verläuft
	- dadurch sind Halbkanten, die einem Dreieck zugeordnet sind, zyklisch gegen den Uhrzeigersinn entlang des Randes der Fläche angeordnet
	- Halbkanten entlang der äußeren Fläche verlaufen mit dem Uhrzeigersinn
- `outer` - boolesche Variable, die angibt, ob die Fläche zur Linken die äußere Fläche der Triangulation ist

![[Halbkantenobjekt.png|350]]

Ein Punkt (node) speichert folgende Zeiger:
- `coords` - Die Koordinaten des Punktes
- `edge` - eine der Halbkanten, die diesen Knoten als Startknoten haben

Sei nun die Kante $e$ (siehe Bild oben) gegeben. Wie finden wir heraus, ob es sich um eine Delauney-Kante handelt?

```python
def Is_Locally_Delauney(Halfedge e):
	if (e.outer or e.twin.outer):
		return true  # äußere Kanten sind immer Delauney-Kanten
	
	a = e.start  # Punkte: siehe Grafik oben
	c = e.next.start
	d = e.next.next.start
	b = e.twin.next.next.start

	return (d not in C(a,b,c) and b not in C(a,c,d))  # diesen zweiten Test kann
													  # man auch weglassen
```

Ein Flip wird wie folgt realisiert:
``` python
def Flip(Halfedge ac):
	# Wir möchten die Kante ac durch die Kante bd ersetzen (s.o.)

	b = ac.twin.next.next.start
	d = ac.next.next.start

	# Initialisiere neue Zwillingskanten
	bd = Halfedge(b,d)
	db = Halfedge(d,b)
	bd.twin = db
	db.twin = bd

	# Finde die übrigen Kanten
	cd = ac.next
	da = cd.next
	ab = ac.twin.next
	bc = ab.next

	# Hänge die next-Zeiger um
	bd.next = da, da.next = ab, ab.next = bd  # Dreieck (b,d,a)
	db.next = bc, bc.next = cd, cd.next = db  # Dreieck (d,b,c)

	# Entferne alte Diagonale von Punkten a und c
	a.edge = ab
	c.edge = cd

	return bd
```

![[Flip.png]]

Nun können wir den Greedy-Algorithmus von Fortune implementieren:

Input: eine Triangulation und eine beliebige Halbkante $e$ (konventionellerweise eine, die am Rand liegt)
- Führe vom Startknoten von $e$ eine *Breitensuche* aus
	- Führe für jede besuchte Kante `Is_Locally_Delauney` aus
		- falls diese Funktion `false` zurückgibt, führen wir `flip` aus
		- dann starten wir die Breitensuche von vorne
- Falls während der Breitensuche keine Nicht-Delauney-Kante gefunden wurde, sind wir fertig

**Laufzeit:**
Die Laufzeit des Greedy-Algorithmus von Fortune liegt für $n$ Knoten in $\mathcal{O}(n^3)$.

Die Laufzeit von `Is_Locally_Delauney` und `Flip` liegt jeweils in $\mathcal{O}(1)$.
Die Breitensuche benötigt im schlimmsten Fall Laufzei $\mathcal{O}(n+e)=\mathcal{O(n)}$[^3], um einen Delauney-Flip zu finden bzw. um festzustellen, dass keiner existiert.

Da höchstens $\mathcal{O}(n^2)$ Flips durchgeführt werden müssen, und wir für jeden die Laufzeit $\mathcal{O}(n)$ benötigen, liegt die Laufzeit insgesamt in $\mathcal{O}(n^3)$.

[^3]: $e \in \mathcal{O}(n)$

# Inkrementeller Algorithmus
Dieser inkrementelle Algorithmus fügt nach und nach Punkte zur Triangulation hinzu, und stellt nach jedem Hinzufügen die Delauney-Eigenschaft wieder her.

```
def Delauney_Triangulation(Punktemenge S):
	Seien p_1,...,p_n die Punkte in S
	T = Triangulation mit Dreieck (p_1,p_2,p_3)

	for (i = 4; i <= n; i++):
		Füge p_i in T ein und ergänze Kantenmenge zu Triangulation

		foreach (Halfedge e, die mit p_i ein Dreieck in T bildet):
			Restore_Delauney(e)
```

`Restore_Delauney` stellt hierbei die Delauney-Eigenschaft rekursiv wieder her:
```
def Restore_Delauney(e):
	if (not Is_Locally_Delauney(e)):
		Halfedge g = Flip(e)
		Restore_Delauney(g.next.next)
		Restore_Delauney(g.twin.next)
```

Wenn man sich das etwas genauer anguckt, sind `g.next.next` und `g.twin.next` genau die beiden Kanten, die von den Endpunkten von `e` jeweils zu dem Punkt verlaufen, der *nicht* der ursprüngliche Punkt `p_i` ist (und damit mit `p_i` wieder ein Dreieck bilden).
![[Restore_Delauney.png]]
Es werden mit den rekursiven Aufrufen also die einzigen Dreiecke betrachtet, die bei dem vorhergegangenen Flip entstanden sein konnten.

> **Stern-Lemma:**
> 1. Nach jeder Iteration $i$ müssen alle Dreiecke, die in dieser Iteration dazugekommen sind, den Punkt `p_i` als einen Eckpunkt haben.
> 2. Jedes Dreieck, das vor dieser Iteration nicht mit `p_i` in Konflikt stand, ist nach der Iteration noch enthalten.
## Aufgabe
Speichere *[[Mengen#Grundlegendes|disjunkte Mengen]]* $S_{1},\ldots,S_{k}$ und für jede Menge $S_{i}$ *Repräsentanten* $s_{i}\in S_{i}$.

## Operationen
- `Make-Set(x)`: Erzeugt eine neue Menge $\set{x}$ mit Repräsentant $x$. Dabei darf $x$ nicht bereits in einer anderen Menge enthalten sein.
- `Union(x,y)`: Falls zwei Mengen $S_x$ und $S_y$ mit $x \in S_{x}$ und $y \in S_y$ existieren, so werden diese entfernt und durch die Menge $S_{x}\cup S_{y}$ ersetzt. Der neue Repräsentant von $S_{x}\cup S_{y}$ kann ein beliebiges Element dieser vereinigten Menge sein.
- `Find(x)`: Liefert den Repräsentanten der Menge $S$ mit $x \in S$ zurück.

## Implementierung
Man nehme:
- Ein Feld $A$ der Länge $n$, wobei $A[i]$ den Repräsentanten von dem Element $i$ enthält.
- Ein Feld $L$ der Länge $n$, wobei $L[i]$ eine verkettete Liste mit den Elementen ist, die $i$ repräsentiert.
- Ein Feld $\text{size}$ der Länge $n$, wobei $\text{size}[i]$ die Länge von $L[i]$ ist.

Die Methode `Init(n)` initialisiert nun $A[i]=i$, $L[i]\rightarrow i \rightarrow \text{null}$ und $\text{size}[i]=1$. Das ist dann äquivalent zu: `for i from 0 to n-1: Make-Set(i)`.

`Find(x): return A[x]`

```python
Union(x,y):
	i = Find(x)
	j = Find(y)
	
	# mache i zum Repräsentanten der kleineren Menge
	if (size[i] > size[j]):
		Vertausche i und j 

	# Setze die Repräsentanten der Elemente in der kleineren Menge auf den Repräsentanten der größeren Menge
	for (z in L[i]):
		A[z] = j

	Hänge L[i] an L[j] an
	size[j] += size[i]
	size[i] = 0
	L[i] = null
```


## Laufzeit
- Laufzeit von `Union`: $\Theta(min\set{\text{size}[i],\text{size}[j]})$
- Laufzeit von $n-1$ Union-Operationen: $\mathcal{O}(n \log n)$, vorausgesetzt, man startet mit einelementigen Mengen.
- Laufzeit von `Find`: $\Theta(1)$
# Minimale Spannbäume

> [!abstract] Definition
> Für einen [[Graphen#Ungerichteter Graph|ungerichteten zusammenhängenden Graphen]] $G=(V,E)$ mit positiven Kantengewichten $w : E \rightarrow \mathbb{R}_{>0}$ heißt eine Kantenmenge $T \subseteq E$ **Spannbaum** von $G$, wenn der Graph $(V,T)$ ein Baum ist. 
> Ein Spannbaum heißt **minimaler Spannbaum** von G, wenn es keinen Spannbaum von $G$ mit einem kleineren Gewicht als $w(T)$ gibt[^1].

^58aa96

[^1]: für $E' \subseteq E$ ist $w(E')=\sum\limits_{e\in E'}w(e)$.

## Algorithmus von Kruskal
Der Algorithmus von Kruskal findet in einem Graphen, sofern er zusammenhängend ist, einen minimalen Spannbaum. Das ganze passiert per [[Algorithmen#Methoden zum Entwurf von Algorithmen#Greedy-Algorithmen|Greedy-Verfahren]].

Zur Umsetzung nimmt man eine [[Union-Find-Datenstruktur]].

```
Kruskal(G,w):
	Teste mittels DFS, ob G zusammenhängend ist. Falls nicht, Abbruch
	for v in V: Make-Set(v)
	T={}
	Sortiere die Kanten in E nach Gewicht
	for e in E:
		if (Find(e.start) != Find(e.end)):
			T += e
			Union(e.start, e.end)
	return T
```

Dieser Algorithmus sucht sich also nacheinander die kleinsten Kanten raus, und verbindet sie, sofern sie noch nicht zur selben Zusammenhangskomponente von $(V,T)$ gehören.
Diese Zusammenhangskomponenten werden in der Union-Find-Datenstruktur gespeichert.

Laufzeit:
- DFS: $\mathcal{O}(|V|+|E|)=\mathcal{O}(|E|)$, denn $G$ ist zusammenhängend und daher $|E|\geq |V|-1$
- Sortieren: $\mathcal{O}(|E|\log |E|)$
- for-Schleife: wird $|E|$-mal durchlaufen
	- $2 |E|$ `Find`-Operationen -> $\Theta(|E|)$
	- $|E|-1$ `Union`-Operationen -> $\Theta(|E| \log |E|)$
- $\Rightarrow$ insgesamt $\Theta(|E| \log |E|)$.
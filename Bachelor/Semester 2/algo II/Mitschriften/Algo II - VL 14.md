Datum: 05.07.

# Exponentialzeitalgorithmen

Wir schauen uns Algorithmen für NP-schwere Probleme mit "akzeptabler" exponentieller Laufzeit an.

## Held-Karp-Algorithmus

Löst das Traveling Salesman Problem.

Anzahl Lösungen: $n!$ Touren

$D_{V,j}:=$ Länge eines kürzesten Weges von Knoten 1 nach Koten $j$, der jeden Knoten aus $V$ genau einmal enthält.

$D_{S,j}=\min\limits_{k\in S\setminus \set{1,j}}(D_{S \setminus \set{j},k}+d_{kj})$

## Parametrisierte Algorithmen

### Vertex-Cover-Problem
Wir möchten eine Knotenmenge aus einem Graphen wählen, sodass jede Kante zu mindestens einem dieser Knoten inzident ist.

$\binom{n}{k}\approx n^{k}$ verschiedene Möglichkeiten

- Nimm eine Kante $(u,v)$ raus
- Nimm die beiden [[Graphen#^f27dcc|induzierten Teilgraphen]], die durch das Entfernen von $u$ oder $v$ entstehen
- Rufe mit jedem dieser Teilgraphen den Algorithmus mit $k-1$ auf

Laufzeit von $\mathcal{O}(2^{k}(n+m))$
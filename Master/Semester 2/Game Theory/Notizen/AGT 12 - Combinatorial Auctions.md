[[lecturenotes12.pdf]]

> [!abstract] Definition *Combinatorial Auction*
> Auktion mit $n$ Bietenden $N$, unter denen $m$ Objekte $M$ versteigert werden.
> 
> Mögliche Zuordnungen von Objekten zu Bietern (*feasible allocations*): $S=(S_{1},\dots,S_{n})$ mit $S_{i} \subseteq M$ und $S_{i} \cap S_{i'} = \emptyset$.
> 
> Jeder Bieter hat pro *Kombination* von Objekten eine eigene Bewertung: $$v_{i}: 2^{M} \to  \mathbb{R}_{\geq 0}$$

^745125

Wir nennen einen Bieter **single-minded**, wenn es *nur eine* Kombination $S_{i}^{*} \subseteq M$ von Items gibt, die ihn glücklich macht (er darf auch mehr bekommen): $$v_{i}(T) = \begin{cases}
v_{i} & \mathrm{falls} & T \supseteq S_{i}^{*} \\
0 & \mathrm{sonst.}
\end{cases}$$
Annahme: die gewünschten Item-Bündel $S_{i}^{*}$ sind für alle bekannt, die Bewertung $v_{i}$ aber nicht.
Problem: die maximierung der social welfare unter single-minded Bietern ($\sum_{i \in N}v_{i}(x)$) ist **NP-schwer**.
Reduktion von Independent set:
- $G=(V,E)$
- Jeder Knoten $v \in V$ wird ein Spieler
- Jede Kante $(i,j) \in E$ wird ein Item, das sowohl Spieler $i$ als auch Spieler $j$ haben wollen
- $v_{i}=1 \,\forall i$
- Gültige Zuweisung von Items -> Independent set
- Social welfare $\geq k$ g.d.w. independendent set $\geq k$

## Greedy Algorithms

**Greedy-by-Value**
- Ordne Gebote, sodass $b_{1} \geq b_{2} \geq \dots \geq b_{n}$
- Setze Menge von Gewinnern $W := \emptyset$
- For $i=1$ to $n$:
	- If $S_{i}^{*} \cap \bigcup_{j \in W}S_{j}^{*} = \emptyset$: $W := W \cup \{ i \}$.

Greedy-by-Value ist *truthful*.

> Für $d=\max_{i \in N} |S_{i}^{*}|$ ist Greedy-by-Value eine $d$-Approximation der optimalen Social Welfare.


**Greedy-by-Sqrt-Value-Density**
Wie Greedy-by-Value, nur mit der Ordnung $\frac{b_{1}}{\sqrt{ |S_{1}^{*}| }}, \frac{b_{1}}{\sqrt{ |S_{1}^{*}| }}, \dots, \frac{b_{2}}{\sqrt{ |S_{n}^{*}| }}$.

> Greedy-by-Sqrt-Value-Density ist eine $\sqrt{ m }$-Approximation der opt. Social Welfare ($m$: Anzahl der Objekte).


## Allgemein

**Strategy Profile** (state)
Auswahl von Strategien, die alle Spieler (oder alle Spieler außer $i$ ) getroffen haben.

**Dominant-strategy incentive compatible** (DSIC)
Anderer Name für einen *ehrlichen Mechanismus* (ehrliches Gebot ist die dominante Strategie).
## Auktionen

**Combinatorial Auction** ^5cbbcc
- $n$ Bieter $N$, $m$ Objekte $M$
- Mögliche Zuordnungen von Objekten zu Bietern (*feasible allocations*): $S=(S_{1},\dots,S_{n})$ mit $S_{i} \subseteq M$ und $S_{i} \cap S_{i'} = \emptyset$.
- Bewertungsfunktion für jede Kombination von Objekten (pro Bieter): $v_{i}: 2^{M}\to \mathbb{R}_{\geq_{0}}$

*Unit-demand function:*
Bewertungsfunktion in combinatorial auction; Bewertung für Set ist gleich Bewertung für wertvollstes Item: $v_{i}(S)=\max_{j \in S}v_{i,j}$. ^8a2087

*Single-Mindedness:*
Ein Bieter möchte nur eine bestimmte Menge von Items (oder eine Obermenge davon), ansonsten hat er Bewertung 0.
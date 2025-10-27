Datum: 11.05.
[[ThR_LA_Skript.pdf|Skript]] von Seite 48 bis Seite 50

# Dimension eines Vektorraums

## Definition

Zunächst: 
> Für einen gegebenen, endlich erzeugten $\mathbb{K}$-Vektorraum $V$ enthält jede beliebige Basis genau dieselbe Anzahl von Vektoren.

> [!abstract] **Dimension**
> Sei $V$ ein endlich erzeugter $\mathbb{K}$-Vektorraum. Dann ist die *Dimension* von $V$ die Anzahl $n$ der Vektoren in einer Basis von $V$.
> $V$ heißt dann $n$-dimensional, und die Dimension von $V$ wird mit $\dim(V)$ oder auch $\dim V$ dargestellt.

Der Begriff "endlich erzeugt" ist gleichbedeutend mit dem Begriff "endlich-dimensional". 
Ein nicht endlich erzeugter Vektorraum ist unendlich-dimensional und man schreibt $\dim V=\infty$.

> **Endliche Grundkörper**
> Sei $V$ ein $n$-Dimensionaler $\mathbb{K}$-Vektorraum, wobei $\mathbb{K}$ $r$ Elemente enthält. Dann enthält $V$ $r^{n}$ Elemente.


> [!info] Änderung des Grundkörpers
> Die Dimension eines Vektorraums hängt entscheident von dem gewählten Grundkörper ab. Für die Dimension eines $\mathbb{K}$-Vektorraums $V$ schreibt man daher gerne auch $\dim_\mathbb{K} V$.
> Es gelten:
> - $\dim_\mathbb{R}\mathbb{C}=2$
> - $\dim_\mathbb{C}\mathbb{C}=1$
> - $\dim_\mathbb{Q}\mathbb{C}=\infty$
> - $\dim_\mathbb{Q}\mathbb{R}=\infty$

## Untervektorräume

Sei $U \subseteq V$ ein Untervektorraum eines endlich-dimensionalen $\mathbb{K}$-Vektorraums $V$.
Dann ist $U$ ebenfalls endlich-dimensional und es gilt: $$\dim U \leq \dim V.$$
Weiterhin gilt für $U \subseteq V$:
$$U \neq V \iff \dim U < \dim V.$$

Diese Erkenntnis ist sehr praktisch, wenn man z.B. die Gleichheit von zwei Unterräumen $U$ und $U'$ zeigen möchte.
Wenn $U \subseteq U'$ und zusätzlich $\dim U = \dim U'$, dann gilt: $U=U'$.
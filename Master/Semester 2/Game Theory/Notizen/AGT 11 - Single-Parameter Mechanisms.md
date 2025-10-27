[[lecturenotes11.pdf]]

Ein *single-parameter* Mechanismus hat:
- $n$ Bieter
- eine Menge $X$ von möglichen Zuteilungen von Objekten auf die Bieter, $X \ni x = (x_{1}, \dots, x_{n})$
- pro Bieter $i$ eine Bewertung $v_{i}$ (der eine gemeinte Parameter) pro "Menge an Objekten", dh. $v_{i}(x) = v_{i} \cdot  x_{i}$.

Die in der [[AGT 10 - Mechanism Designs|letzten VL]] eingeführte Vickrey-Auktion ist ein Beispiel für einen Single-Parameter-Mechanismus. 

## Myersons Lemma

> [!abstract] Definition *Realisierbarkeit*
> Wir nennen eine Resultatsfunktion $f$ *realisierbar* (implementable), wenn es eine Bezahlfunktion $p$ gibt, sodass der resultierende Mechanismus $\mathcal{M}=(f,p)$ [[AGT 10 - Mechanism Designs#^a1f30f|DSIC]] (ehrlich) ist.

Beispiel: die Funktion $f$, die ein einzelnes Objekt dem Höchstbietenden zuweist, ist realisierbar, weil durch die Zweitpreis-Auktion ($p$ weißt dem Gewinner das zweithöchste Gebot als Preis zu) der Mechanismus DSIC wird (das ehrliche Gebot, bei dem jeder genau das bietet, was ihm das Objekt wert ist, ist die bestmögliche (dominante) Strategie).

> [!abstract] Definition *Monotone Resultatsfunktion*
> Eine Resultatsfunktion $f$ ist monoton, wenn für fixe $i$ und andere Gebote $b_{-i}$ die Zuweisung $f(b_{i}, b_{-i})$ bei steigendem Gebot $b_{i}$ nicht geringer wird.

Man kann also nicht mehr bieten und dadurch weniger bekommen.
Eine Auktion, bei der das zweithöchste Gebot gewinnt, wäre also nicht monoton.

> **Myersons Lemma**
> In einem single-parameter Setting gilt:
> 1. Eine Resultatsfunktion $f$ ist *realisierbar, genau dann wenn* sie *monoton* ist.
> 2. Wenn $f$ monoton ist, und $b_{i}=0 \implies p_{i}(b)=0$, dann gibt es *genau eine* Zahlfunktion $p$, sodass $\mathcal{M}=(f, p)$ DSIC ist.
> 3. Diese Zahlfunktion ist gegeben durch $$p(b_{i}, b_{-i})= b_{i} \cdot f_{i}(b_{i}, b_{-i}) - \int_{0}^{b_{i}}f_{i}(t, b_{-i})\,dt.$$

^203433

Visualisiert:
![[Myersons-Lemma.png]]
- Bewertung: blau ($v_{i}$ x Anzahl erhaltener Items)
- Zahlung: rot (gegeben durch Myersons Lemma)
- Utility: grün (Bewertung - Zahlung)

Der Mechanismus ist *ehrlich*, weil die Utility bei ehrlihem Gebot (links) maximiert ist, dh. $f$ ist realisierbar.
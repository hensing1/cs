[[lecturenotes18.pdf]]

# Posted Prices with Incomplete Information

Wir haben [[Game Theory - Glossar#^5cbbcc|Combinatorial Auction]] mit unit-demand, aber die Bewertungen $v_{i}: 2^{M} \to \mathbb{R}_{\geq 0}$ sind *privat*. Wir kennen nur die Verteilung $\mathcal{D}_{i}$, aus der Käufer $i$ die Bewertung zieht.

Wir wollen Preise für die $m$ Items finden.

*Posted-Prices Mechanism*
- Wir fragen die Käufer in der Reihenfolge $i=1,\dots,n$
- Käufer $i$ kauft dasjenige $S_{i}$, welches die Utility $v_{i}(S_{i})-\sum_{j \in S_{i}}p_{j}$ maximiert, für $\sum_{j \in S_{i}}p_{j}$.

Da der Käufer seine eigene Utility maximiert und selbst sein $S_{i}$ wählt, ist dieser Mechanismus *truthful* - egal, wie die $p_{j}$ gewählt sind.

> **Theorem** *(Feldman/Gravin/Lucier, 2015)*
> Es gibt für alle unit-demand valuations eine Wahl von Preisen, sodass die *erwartete Social Welfare* die **Hälfte** von der *erwarteten optimalen Social Welfare* ist.

## Single-Item Case

Wir setzen $p= \frac{1}{2}E[\max_{i}v_{i}]$.

## Multiple Items

Wir schreiben:
- $(i,j) \in \mathrm{OPT}(v)$, falls Käufer $i$ das Item $j$ in einer optimalen Zuweisung bekommt
- $v_{\mathrm{OPT},j}=v_{i,j}$ falls $(i,j) \in \mathrm{OPT}(v)$
- $v_{\mathrm{OPT},j}=0$, falls $j$ nicht zugewiesen wird.

Für $p_{j}=\frac{1}{2} E[v_{\mathrm{OPT},j}]$ erhalten wir eine erwartete Welfare von $\frac{1}{2}E\left[ \sum_{j \in M} v_{\mathrm{OPT},j} \right].$


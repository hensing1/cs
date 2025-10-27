[[lecturenotes05.pdf]]

- Jedes endliche Spiel hat ein MNE
- Jedes Congestion Game hat ein PNE
- Wir haben leider keinen Algorithmus, um diese effizient zu berechnen
## Complexity Classes

Wir definieren die Klasse PLS:
![[Komplexitätstheorie#^bb9267]]

**Local Search Algorithm**
- Nutze Algorithmus 1, um eine Lösung $s \in \mathcal{F}(I)$ zu finden.
- Nutze iterativ Algorithmus 3, um eine bessere Lösung $s' \in N(s, I)$ zu finden, bis ein lokales Optimum erreicht ist.

## PNEs in Congestion Games

Das finden eines *Pure Nash Equilibriums* in *congestion games* ist **[[Komplexitätstheorie#PLS#Reduktion|PLS-Vollständig]]**.

Wir zeigen das mit $\text{Max-Cut} \leq_{\mathrm{PLS}} \text{PNE in congestion games.}$


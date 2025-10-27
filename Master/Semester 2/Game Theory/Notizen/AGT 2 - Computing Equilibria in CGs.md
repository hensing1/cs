[[lecturenotes02.pdf]]

> Pure Nash Equilibria sind die *lokalen Minima* des Rosenthal-Potentials $\Phi$.

Ein Network Congestion Game ist symmetrisch, wenn alle Spieler sich denselben Start und dasselbe Ziel teilen.

> **Theorem**
> Für *symmetrische* Network Congestion Games kann man $\arg\min_{S}\Phi(S)$ in *polynomieller Zeit* berechnen. 

Ansatz:
- Im Graphen jede Kante $e$ durch $n$ Kanten ersetzen, die jeweils die Kosten $d_{e}(1),\dots,d_{e}(n)$ haben
- [[Flussprobleme#Algorithmus von Edmonds und Karp|Minimum-Kosten-Flow]] berechnen
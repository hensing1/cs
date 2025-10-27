[[lecturenotes01.pdf]]
## Congestion Games

> [!abstract] Definition *Congestion Game*
> Tupel $\Gamma = (N,R,\Sigma_{i}, d_{r})$, wobei:
> - $N \{ 1,\dots,n \}$ eine Menge von Spielern
> - $R, |R|=m$ eine Menge von Ressourcen
> - $\Sigma_{i} \subseteq 2^{R}$ Menge von Strategien von Spieler $i$
> - $d_{r} : \{ 1,\dots,n \} \to \mathbb{Z}$ eine *delay function* der Ressource $r \in R$
> 
> Ziel von Spieler $i$: Strategie $S_{i} \in \Sigma_{i}$ wählen, sodass Kosten abhängig von $d_{r}$ minimiert werden.

Beispiel: **Network Congestion Game**
- Graph $G=(V,E)$
- Kanten sind die Ressourcen: $E = R$
- Jeder Spieler hat Start- und Zielknoten: $s_{i} \in V, t_{i} \in V$
- $\Sigma_{i}$ ist Menge aller Pfade von $s_{i}$ nach $t_{i}$ in $G$
- $d_{e}(x)$ beschreibt die Kosten der Kante $e$ je nachdem, wieviele Spieler sie benutzen

Für eine gewählte Strategie $S$ ist $n_{r}(S)$ die Anzahl der Spieler, die eine Ressource $r$ benutzen:
- $n_{r}(S) = | \{ i \in N \mid r \in S_{i} \}|$

Dann ist der Delay einer Ressource: $d_{r}(n_{r}(S))$

Und die Kosten eines Spielers $i$: $c_{i}(S) = \sum_{r \in S_{i}}d_{r}(n_{r}(S))$

> [!abstract] Definition *Best Response*, *Equilibrium*
> Die Strategie $S_{i}$ ist eine *best response* eines Spielers $i$ gegen $$S_{-i} := (S_1, \dots , S_{i-1},S_{i+1}, \dots, S_{n})$$ ($S_{-i}$ bezeichnet Strategien aller Spieler außer $i$) , wenn $$c_{i}(S_{i}, S_{-i}) \leq c_{i}(S_{i}',S_{-i})$$ für alle $S_{i}' \in \Sigma_{i}.$
> Eine Strategie $S=(S_{1},\dots,S_{n})$ ist ein *Pure Nash Equilibrium*, wenn jedes $S_{i}$ eine best response gegen $S_{-i}$ ist.

Es gibt für ein solches Problem **immer** ein Pure Nash Equilibrium.

Ein Zustandspaar $(S,S')$ ist eine Verbesserung, wenn für einen Spieler $i$ gilt: $c_{i}(S') < c_{i}(S)$ und $S_{-i}'=S_{-i}$ ($i$ ist der einzige Spieler, der eine Verbesserung vornimmt).
Eine Verbesserungssequenz $S^{(0)}, S^{(1)}, \dots$ ist Verbesserungssequenz, wenn $(S^{(t)}, S^{(t+1)})$ eine Verbesserung ist.

> **Theorem** (Rosenthal 1973)
> *Jede* Verbesserungs-Sequenz in einem Congestion Game ist *endlich*.

Am Ende jeder Verbesserungs-Sequenz steht ein Pure Nash Equilibrium.

Beweis des Theorems mit *Rosenthal-Potential* einer Strategie $S$: $$\Phi(S) = \sum_{r \in R}\sum_{k=1}^{n_{r}(S)} d_{r}(k)$$
In Worten: wenn man die Spieler nacheinander hinzufügt, und immer die Kosten des gerade neuen Spielers dazuaddiert, erhält man das Rosenthal-Potential.

Daraus folgt die Haupt-Eigenschaft des Rosenthal-Potentials: $$\Phi(S_{i}', S_{-i})-\Phi(S) = c_{i}(S_{i}', S_{-i}) - c_{i}(S)$$ dh. wenn Spieler $i$ von Strategie $S_{i}$ auf $S_{i}'$ wechselt, ändert sich das Rosenthal-Potential genau um die Differenz der Kosten zwischen $S_{i}$ und $S_{i}'$.

Da die Delay-Werte Ganzzahlen sind, sinkt $\Phi$ bei jeder Verbesserung um mindestens 1.

Außerdem können wir $\Phi$ eingrenzen mit $$-\sum_{r \in R}\sum_{i=1}^{n}|d_{r}(i)| \leq \Phi(S) \leq \sum_{r \in R}\sum_{i=1}^{n}|d_{r}(i)|,$$
also ist keine Verbesserungs-Sequenz länger als $2 \sum_{r \in R}\sum_{i=1}^{n}|d_{r}(i)|$.
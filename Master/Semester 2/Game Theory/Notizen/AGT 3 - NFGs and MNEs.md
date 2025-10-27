[[lecturenotes03.pdf]]
## Normal Form Games

> [!abstract] Definition *Normal-Form Cost Minimization Game*
> Ein Tripel $(N, (S_{i}), (c_{i}))$, wobei:
> - $N$ die Menge der Spieler, $|N|=n$, meist $N = \{ 1,\dots,n \}$
> - Für jeden Spieler $i$:
> 	- $S_{i}$ die Menge der (reinen) Strategien
> 	- $c_{i}: S \to \mathbb{R}$ eine Kostenfunktion ($S=\prod_{i \in N}S_{i}$) - in Zustand $s \in S$, $s=(s_{1},\dots,s_{n})$ hat Spieler $i$ Kosten $c_{i}(s)$.

Das [[AGT 1 - Congestion Games#Congestion Games|Congestion Game]] ist also ein Sonderfall eines Normal Form games - $c_{i}$ wird dabei mit Ressourcen und Delay-Funktionen realisiert.

Wir können ein Normal Form game mit zwei Spielern in Bimatrix-Schreibweise schreiben: ein Spieler kann als Strategie eine Spalte wählen, der andere eine Zeile.

Hat Spieler 1 bereits eine Wahl getroffen, ist das Minimum in der jeweils gewählten Zeile die *best response* für Spieler 2.
Wenn zwei Best Responses im selben Feld landen, hat man ein Pure Nash Equilibrium:
![[Bimatrix_PNE.png|200]]

## Mixed Nash Equilibria

> **Gemischte Strategie**
> Ein Spieler $i$ wählt aus seinen Strategien $S_{i}$ nicht mehr eine Strategie $s_{i}$, sondern eine Wahrscheinlichkeitsverteilung $\sigma_{i}$ über die Menge $S_{i}$.

Jede reine Strategie ist auch eine gemischte Strategie.
Die Kosten $c_{i}$ sind dann die erwarteten Kosten über alle $\sigma_{i}$: $$c_{i}(\sigma)=\mathbf{E}_{s_{1}\sim \sigma_{1},\dots,s_{n} \sim \sigma_{n}}[c_{i}(s)]=\sum_{s_{1} \in S_{1}}\cdots \sum_{s_{n} \in S_{n}} \sigma_{1,s_{1}} \cdot \ldots \cdot \sigma_{n,s_{n}} \cdot c_{i}(s)$$
mit $s=(s_{1},\dots,s_{n})$.

Eine gemischte Strategie $\sigma_{i}$ ist eine *best response* gegen $\sigma_{-i}$, wenn $c_{i}(\sigma_{i},\sigma_{-i}) \leq c_{i}(\sigma_{i}',\sigma_{-i})$ für alle $\sigma_{i}'$.
Ist in einem Zustand $\sigma$ jedes $\sigma_{i}$ eine best response, haben wir ein **Mixed Nash Equilibrium** (MNE). ^3cbea7

> Eine gemischte Strategie $\sigma_{i}$ ist eine best response gegen $\sigma_{-i}$ genau dann, wenn sie (mindestens) so gut ist wie die beste reine Strategie: $c_{i}(\sigma_{i},\sigma_{-i}) \leq c_{i}(s_{i}', \sigma_{-i})$.

Heißt auch: jedes PNE ist auch ein MNE.

### W'keitsverteilung über Pure Best Responses

> $\sigma_{i}$ ist eine Best-Response-Strategie, g.d.w. für jedes $s_{j} \in S_{i}$ , dessen Wert $\sigma_{i,s_{j}}>0$ ist, eine pure best response ist.

**Berechnung**
Ein MNE tritt dann ein, wenn jeder Spieler seine W'keiten so wählt, dass die Strategien des anderen Spielers gleichwertig sind.
Bimatrix-Spiel oben: Zeilenspieler wählt $p$, sodass $c_{\mathrm{row}}(A, (1-p, p))=c_{\mathrm{col}}(B, (1-p, p))$.

[[lecturenotes17.pdf]]

Wir haben diesmal keine Gebote, sondern *wir möchten einen Preis bestimmen*. Ein Käufer kann ein Objekt zu einem Preis kaufen, oder eben nicht.

Wir haben wieder das Setting einer [[Game Theory - Glossar#^5cbbcc|combinatorial auction]]. Wir reden über ein **Walras-Equilibrium**, wenn jeder Käufer genau diejenigen Objekte bekommt, die seine Utility maximieren:
$$v_{i}(S_{i})-\sum_{j \in S_{i}}q_{j}\geq v_{i}(S_{i}')-\sum_{j \in S_{i}'}q_{j}\quad \forall S_{i}'\in M,$$
und $j \not\in \bigcup_{i \in N}S_{i} \implies q_{j}=0$ (Items die nicht vergeben werden haben Preis 0 - um unendliche Preise zu vermeiden).

> [!example] Beispiel
> - Gibt es nur ein Item, und $v_{1} \geq v_{2} \geq \dots \geq v_{n}$, dann ist irgendein $q_{1} \in [v_{2},v_{1}]$ und $S_{1}=\{ q_{1} \}$  ein Walras-Equilibrium (für alle anderen Spieler ist das Item zu teuer und nur Käufer 1 erhält nicht-negative Utility).

> **First Welfare Theorem**
> Ist $(q,S)$ ein Walras-Equilibrium, dann maximiert $S$ die Social Welfare.

## Verbindung zu VCG

Haben Käufer eine [[Game Theory - Glossar#^8a2087|unit-demand function]] als Bewertungsfunktion, können wir den [[AGT 13 - VCG Mechanisms#^440374|VCG-Mechanismus]] anwenden, um Preise zu bestimmen:
- Sei $S$ eine Zuweisung, die Social Welfare maximiert
- Sei $S^{-i}$ eine Zuweisung, die Social Welfare für $N\setminus \{ i \}$ maximiert
- Wegen unit-demand hat jede Zuweisung in $S$ und $S^{-i}$ nur ein Item
- Wird Item $j$ Käufer $i$ zugeordnet, setze den Preis von $j$ auf die VCG-Zahlung von $i$: $$q_{j}=p_{i}(v)=\sum_{i' \neq i}v_{i}'(S_{i'}^{-i})-\sum_{i' \neq i}v_{i'}(S_{i'}).$$
> Mit einer beliebigen Zuweisung $S$ und den zugehörigen Preisen des VCG-Mechanismus entsteht ein *Walras-Equilibrium*.


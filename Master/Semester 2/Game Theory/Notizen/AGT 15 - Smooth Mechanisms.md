[[lecturenotes15.pdf]]


> [!abstract] Definition *Smooth Mechanism*
> Ein Mechanismus $\mathcal{M}=(f,p)$ ist $(\lambda,\mu)$-smooth, wenn für jeden Gebotsvektor (bid profile) $b \in B$ und für jeden Bewertungsvektor (valuation profile) $v \in V$ jeder Spieler $i \in N$ ein alternatives Gebot $b_{i}^{*}$ hat, sodass $$\sum_{i \in N}u_{i}((b_{i}^{*}, b_{-i}), v_{i}) \geq \lambda \cdot \mathrm{OPT}(v)-\mu \sum_{i \in N}p_{i}(b).$$

^ec5d66

$\mathrm{OPT}(v)$ ist die maximale social welfare (Zuweisung, die die Summe aller Bewertungen maximiert).
Wir betrachten also die Summe aller Utilities in Relation zur bestmöglichen Bewertung minus das, was alle zahlen müssen.

***Wofür?***

Smoothness ermöglicht uns, Aussagen über den Price of Anarchy[^1] zu treffen: 

> **Theorem** (Syrgkanis und Tardos, 2013)
> Ist ein Mechanismus $\mathcal{M}$ $(\lambda, \mu)$-smooth, und haben Spieler die Möglichkeit, sich aus dem Mechanismus zurückzuziehen, dann gilt für den Price of Anarchy: $$\mathrm{PoA}_{\mathrm{PNE}} \leq \frac{\max\{\mu, 1\}}{\lambda}.$$

Zurückziehen bedeutet, ein Spieler erhält freiwillig Utility 0.



[^1]: $PoA_{\mathrm{Eq}}=\max_{v \in V}\max_{\mathcal{B} \in \mathrm{Eq}(v)} \frac{\mathrm{OPT}(v)}{\mathbf{E}_{b \sim \mathcal{B}}[\mathrm{SW}_{v}(b)]} \geq 1$ ist für ein Äquilibrium-Konzept (wie z.B. ein Pure Nash Equilibrium) das schlechteste mögliche Verhältnis zwischen dem optimalen social welfare und dem erwarteten social welfare.

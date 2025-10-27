[[lecturenotes06.pdf]]

## Correlated Equilibria

In einem MNE ist es so, dass jeder Spieler seine W'keitsverteilung *unabhängig* wählt. Die Wahrscheinlichkeit, dass irgendeine Kombination von Strategien eintritt, ist also das *Produkt* aller Wahrscheinlichkeiten, dass ein Spieler diese Strategie wählt.

Bei einem **korrellierten Equilibrium** (correlated equilibrium, CE) gibt ein Dritter eine Wahrscheinlichkeitsverteilung $p$ über *alle* Strategieprofile $S=\prod_{i \in N}S_{i}$. 
$p$ ist für alle bekannt.
Dann wird ein Profil $s$ aus $p$ gezogen, und jedem Spieler $i$ wird seine Strategie $s_{i}$ privat verraten.
Ein korrelliertes Equilibrium besteht dann, wenn kein Spieler den Anreiz hat, die Strategie zu wechseln - unter der Annahme, dass alle Spieler dem dritten trauen und davon ausgehen, dass die jeweils anderen Spieler auch der Empfehlung gehorchen.
Formal: $$\mathbf{E}_{s \sim p}[c_{i}(s) \mid s_{i}] \leq \mathbf{E}_{s \sim p}[c_{i}(s_{i}', s_{-i}) \mid s_{i}]$$
mit $s_{i}$ der empfohlenen Strategie und $s_{i}'$ einer Ausweichstrategie für Spieler $i$.

Ein **grob korrelliertes Equilibrium** (coarse correlated eqiulibrium, CCE) ist dasselbe, nur dass die gezogene Strategie $s$ allen bekanntgegeben wird: $$\mathbf{E}_{s \sim p}[c_{i}(s)] \leq \mathbf{E}_{s \sim p}[c_{i}(s_{i}', s_{-i})]$$

Jedes MNE ist ein CE, und jedes CE ist ein CCE.
$$\mathrm{PNE} \subseteq \mathrm{MNE} \subseteq \mathrm{CE} \subseteq \mathrm{CCE}.$$

> Ein CE kann in Laufzeit *polynomiell* in der Anzahl der Strategieprofile berechnet werden.

## No-regret Dynamics


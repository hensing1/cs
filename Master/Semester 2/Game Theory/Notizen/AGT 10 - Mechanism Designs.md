[[lecturenotes10.pdf]]

Mechanism Design: wir möchten ein Spiel so *entwerfen*, dass bestimmte Equilibria auf jeden Fall existieren.
## Erstpreis-Auktion

> Es wird *ein Objekt* unter $n$ Spielern versteigert.
> Jeder Bieter $i$ lässt sein Gebot $b_{i}$ verdeckt dem Auktionär zukommen.
> Sobald der Auktionär alle Gebote hat, wird das Objekt an den Bieter mit dem höchstem Gebot zu diesem Preis versteigert.

Für jeden Bieter $i$:
- *Zahlungsbereitschaft* (value) $v_{i} \in \mathbb{R}_{\geq 0}$
- *Utility* $u_{i}=v_{i}-b_{i}$, bzw. $u_{i}=0$ falls $i$ das Objekt nicht bekommt

Angenommen, alle Bieter kennen alle anderen $v_{i}$'s. 
Wenn alle genau ihr $v_{i}$ bieten, ist das allgemein kein Nash Equilibrium, da alle Utility 0 haben und ggf. einseitig ihre Strategie zu eigenen Gunsten verändern können.

Für den Fall, dass ein Unentschieden dadurch gelöst wird, dass derjenige mit dem höheren $v_{i}$ gewinnt, gibt es ein pure Nash equilibrium:
Ist $i= \arg\max v_{i}$, dann ist $b_{i}=\max_{j \neq i} v_{j}$ und $b_{j}=v_{j}$ ein PNE.

## Zweitpreis-Auktion

> Jeder Bieter $i$ lässt sein Gebot $b_{i}$ verdeckt dem Auktionär zukommen.
> Das Objekt wird an den Bieter mit dem höchsten Gebot *zum Preis vom zweithöchsten Gebot* versteigert.

> [!abstract] Definition *Dominante Strategie*
> Ein Gebotsprofil $b$ ist eine *dominante Strategie* für Value-Profil $v$, falls jedes $b_{i}$ eine (schwach) dominante Strategie ist.
> Ein Gebot $b_{i}$ ist (schwach) dominant, wenn für alle anderen möglichen Gebote $b_{i}'$ und Gebote der übrigen Spieler $b_{-i}$ gilt: $u((b_{i}, b_{-i}), v_{i}) \geq u_{i}((b_{i}', b_{-i}), v_{i}).$

> **Theorem** (Vickrey 1961):
> In einer Zweitpreisauktion ist $b_{i}=v_{i}$ ==(ehrliches Gebot)== eine dominante Strategie.

Bietet jeder sein $v_{i}$, dann ist immer $u_{i} \geq 0$.

## Mechanismus-Design mit Geld

Die Auktion ist ein Beispiel für ein Mechanismus-Designproblem mit Geld.
Notation:
- Menge $N$ von $n$ Spielern
- Mögliche Resultate: $X$
- Bewertungsfunktion $v_{i}: X \to  \mathbb{R}$ (privat)
- Menge möglicher Gebote pro Spieler: $B_{i}$
- Menge aller Gebotsprofile: $B = B_{1} \times \dots \times B_{n}$
- **Mechanismus:** $\mathcal{M}=(f,p)$
	- $f: B \to X$ Resultats-Funktion (welcher Spieler erhält wieviel)
	- $p: B \to  \mathbb{R}^{n}$ Zahlungsfunktion (welcher Spieler bezahlt wieviel)
	- -> aus Geboten $b = ( b_{1}, \dots, b_{n} )$ wird Resultat $f(b)$ und Bezahlungen $(p_{1}(b), \dots, p_{n}(b))$ berechnet
- Die Utility ist dann $u_{i}^{\mathcal{M}}(b, v_{i}) = v_{i}(f(b)) - p_{i}(b)$.
### Beispiele:
- Auktion mit einem Objekt (s.o.)
	- Resultatmenge: z.B. $X \subseteq \{ 0, 1 \}^{n}$ mit $\sum x_{i}=1$, mit $x_{i}=1$ falls $i$ das Objekt erhält
	- Ziel: der Spieler mit dem höchsten $v_{i}$ soll das Objekt erhalten
- Kombinatorische Auktion (siehe [[AGT 12 - Combinatorial Auctions#^745125|VL 12]])

Oft ist es sinnvoll, dass die möglichen Gebote genau den möglichen Bewertungen entsprechen. Sei also $V_{i}$ die Menge aller möglichen Bewertungsfunktionen für Spieler $i$, dann ist $B_{i} = V_{i}$. Ein solcher Mechanismus heißt **direkter Mechanismus**.

## Wünschenswerte Eigenschaften von Auktionen

1. **DSIC:** Ist für jeden Spieler $i$ die *ehrliche* Strategie $b_{i}=v_{i}$ dominant, dann heißt der zugehörige Mechanismus $\mathcal{M}=(f,p)$ **dominant-strategy incentive compatible** (DSIC) oder schlicht **ehrlich** (truthful). ^a1f30f
2. Wir möchten die *social welfare* maximieren: $\sum_{i \in N} v_{i}(x) \to \mathrm{max}$
3. Wir möchten alles in *Polynomialzeit* berechnen können.

Für die Zweitpreis-Auktion (auch Vickrey-Auktion genannt) ist alles drei gegeben.
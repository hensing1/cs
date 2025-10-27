Datum: 13.12.
Kapitel: *Abzählende Kombinatorik, Algebraische Strukturen*
[[18VL-Scan-Wahrscheinlichkeiten-Algebraische-Strukt.pdf|Folien]]

# Beispiele zur abzählenden Kombinatorik
Link: [[Abzählende Kombinatorik]]
## Geburtstagsparadoxon
> Was ist die Wahrscheinlichkeit, dass unter 23 Leuten zwei am selben Tag Geburtstag haben?

Annahmen: 
- Geburtstage sind gleichverteilt übers Jahr
- Es gibt keine Schaltjahre

Ausrechnen via Komplementärwahrscheinlichkeit:
Wie wahrscheinlich ist es, dass *keine* zwei Personen denselben Geburtstag haben?

Sei $M$ die Menge aller möglichen Geburtstage: $M=\set{1,2,\ldots,365}$

Darstellung der 23 Geburtstage als Vektor: $(7,8,64,\ldots,255)\in M^{23}$

Das heißt: insgesamt $365^{23}$ verschiedene Geburtstagsvektoren.
Wieviele von diesen Vektoren haben komplett verschiedene Einträge?

Es gibt 365 Möglichkeiten für die erste Person, 364 für die zweite, usw.
$\Rightarrow P(\text{Keine zwei Personen teilen einen Geburtstag}) = n! / (n-k)!$ 

Insgesamte Gegenwahrscheinlichkeit: $\frac{365!}{(365-23)!} / 365^{23} \approx 0,493$ 

Bedeutet: bei 23 Personen liegt die Wahrscheinlichkeit bei über 50%, dass zwei am selben Tag Geburtstag haben.

### Fallstrick: Gleichverteilung
Alternativer Ansatz: man nimmt Vektor mit 365 Einträgen:
$(x_{1},x_{2},\ldots,x_{365})$
Alle Vektoren mit $\sum\limits_{i=1}^{365}x_{i}=23$: Alle Möglichkeiten, wie sich 23 Geburtstage verteilen können
Davon gibt es $\binom{n+k-1}{k}$ Stück - aber nicht alle haben dieselbe Wahrscheinlichkeit!

Positive Fälle: 23 Positionen des Vektors mit 1 belegt -> $\binom{n}{k}$ Stück
Gegenwahrscheinlicheit wäre nach diesem Ansatz: $\binom{365}{23} / \binom{365+23-1}{23}$, das ist aber *falsch*
Denn: der Vektor $(365,0,0,\ldots)$ z.B. ist *nicht* so wahrscheinlich wie $(1,0,3,\ldots)$.

## Kniffel
Man würfelt mit 5 Würfeln. Man darf jetzt keine Multimengen zählen (davon gibt es ja $\binom{n+k-1}{k}$): z.B. die Multimenge $\set{1,1,1,2,5}$ kann ja entstehen durch $(1,2,1,1,5)$ oder $(1,1,1,2,5)$.

Was ist die Wahrscheinlichkeit einer Straße ($\set{1,2,3,4,5}$ oder $\set{2,3,4,5,6}$)?
Man muss die **Tupel** zählen, die diese Multimengen erzeugen, und *nicht* die Multimengen selbst.

Jede Multimenge kann von $5!$ verschiedenen Tupeln erzeugt werden -> WS für Straße ist 
$\frac{2 \cdot 5!}{6^{5}} \approx 0,031$.

# Algebraische Strukturen
## Verknüpfungen
![[Verknüpfung#Definition]]

## Beispiele
### Verknüpfungen auf $\mathbb{R}$
- Addition und Multiplikation: jeweils assoziative und kommutative Verknüpfung
- Subtraktion: weder assoziativ noch kommutativ
- Division: keine Verknüpfung, da $\frac{x}{0}$ für $x \in \mathbb{R}$ nicht definiert
- $\star : \mathbb{R} \times \mathbb{R} \rightarrow \mathbb{R}$ mit $\star(x,y) := x$:
	- nicht kommutativ: $\star(1,2) = 1 \not= 2 = \star(2,1)$
	- assoziativ: $\star(\star(a,b),c)=\star(a,c)=a=\star(a,b)=\star(a,\star(b,c))$

### Verknüpfungen auf $\mathbb{N}$
- Addition und Multiplikation: jeweils assoziative und kommutative Verknüpfung
- Subtraktion, Division: keine Verknüpfungen, da nicht immer auf $\mathbb{N}$ verwiesen wird (z.B. $1-2 \not\in \mathbb{N}$ und $\frac{1}{2} \not\in \mathbb{N}$)

### Verknüpfung auf Abbildungen
Sei $\text{Abb}(X) := \set{f : X \rightarrow X \mid f \text{ ist Abbildung}}$ die Menge aller Abbildungen auf eine Menge $X$.
Dann ist $\circ : \text{Abb}(X) \times \text{Abb}(X) \rightarrow \text{Abb}(X)$ mit $(f \circ g)(x) = f(g(x))$ die *Verknüpfung* zweier Funktionen $f \in \text{Abb}(X)$ und $g \in \text{Abb}(X)$.
- $\circ$ ist assoziativ: $((f \circ g) \circ h)(x)=(f \circ g)(h(x)) = f(g(h(x))) = f((g \circ h)(x)) = (f \circ (g \circ h))(x)$
- $\circ$ ist nicht kommutativ für $|X| \geq 2$

## Ausgezeichnete Elemente
Zum Beispiel ist 0 das neutrale Element für + und 1 das neutrale Element für $\cdot$ .
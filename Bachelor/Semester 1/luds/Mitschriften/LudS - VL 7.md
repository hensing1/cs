Datum: 03.11.
[[7VL-Scan-Bijektionen-Kardinalitaet-Aequivalenzrelation.pdf|Folien]]

# Bijektivität und Kardinalität
Wenn es eine bijektive Funktion zwischen zwei Mengen $A$ und $B$ gibt, gilt: $|A| = |B|$, d.h. $A$ und $B$ sind gleichmächtig (haben dieselbe [[Mengen#Kardinalität|Kardinalität]]).
Das gilt auch für unendliche Mengen.

## Beispiel
Die Menge der geraden Zahlen hat die gleiche Mächtigkeit wie $\mathbb{N}$. Das kann man durch folgende Funktion zeigen:
$f : \mathbb{N} \rightarrow M$ mit $M=\set{0,2,4,6,\ldots}=\set{2 \cdot i \space | \space i \in \mathbb{N}_0}$ und $f(j)=2(j-1)$.

Um die Gleichmächtigkeit zwischen $M$ und $\mathbb{N}$ zu zeigen, reicht es, zu beweisen, dass $f$ eine Bijektion ist.

### Beweis
#### Beweis für Surjektivität
Nach [[Beweistechniken#Beweis von Surjektivität|diesem Schema]].

> Für $i \in \mathbb{N}_0$ gilt:
> - $y=2 \cdot i$, und
> - $f(x) = 2(x-1) = 2 \cdot i$, da $(x-1) \in \mathbb{N}_0$.
> $\iff x=i+1$.

Was haben wir nun gezeigt? 
-> Man kann jedes beliebige $y$ in ein $x$ umrechnen, für das $f(x)=y$ gilt, und zwar indem man $y$ als $2 \cdot i$ ausdrückt, dann ist das entsprechende $x$ nämlich $i+1$.
(Drückt quasi dasselbe aus wie $x=\frac{y}{2} + 1$, nur dass man damit deutlicher macht dass das resultierende $x$ tatsächlich eine natürliche Zahl ist.)

#### Beweis für Injektivität
Nach [[Beweistechniken#Beweis von Injektivität|diesem anderen Schema]].

> Gegeben: $j,j' \in \mathbb{N}$ mit $f(j)=f(j')$.
> $f(j)=f(j') \iff 2(j-1)=2(j'-1) \iff j=j'$.


# Äquivalenzrelationen und -klassen
## Wiederholung zu Äquivalenzrelationen
Zur Erinnerung:
![[Relationen#Äquivalenzrelation]]

### Grafische Darstellung
![[LudS - VL 6#Auswirkungen der Relationseigenschaften auf Graphdarstellung]]
#### Typische Klausuraufgabe
Gegeben sei ein gerichteter Graph einer Relation:
![[Relationsgraph.png|400]]

Aufgabe: Erweitern sie den Relationsgraph *minimal* auf den Graphen einer Äquivalenzrelation!
![[Relationsgraph_äquivalent.png|400]]

Hier hat man nun drei Äquivalenzklassen (s.u.): $\set{1,2,3,4}$, $\set{5,6}$ und $\set{7}$.

## Äquivalenzklassen
![[Äquivalenzklassen#Definition]]

### Beispiel
$\equiv _2$ hat zwei Äquivalenzklassen:
- $[\![0]\!]_{\equiv _{2}}=\set{\ldots,-4,-2,0,2,4,6,\ldots}=[\![28]\!]_{\equiv _{2}}$
- $[\![1]\!]_{\equiv _{2}}=\set{\ldots,-3,-1,1,3,5,7,\ldots}=[\![35]\!]_{\equiv _{2}}$

![[Äquivalenzklassen#Disjunktive Abdeckung]]

Man kann jetzt mit Klassen rechnen!
### Äquivalenzklassen und Arithmetik
![[Äquivalenzklassen#Restklassen]]
#### Beispiel $\mathbb{Z}_{4}$
- $\bar{0}=\set{\ldots,-4,0,4,8,\ldots}$
- $\bar{1}=\set{\ldots,-3,1,5,9,\ldots}$
- $\bar{1}=\set{\ldots,-2,2,6,10,\ldots}$
- $\bar{3}=\set{\ldots,-5,-1,3,7,\ldots}$

#### Arithmetik mit Restklassen
Man kann nun Klassen miteinander addieren und multiplizieren.
![[Äquivalenzklassen#Arithmetik#Restklassenarithmetik]]

---

![[Äquivalenzklassen#Beispiele für Äquivalenzklassen#Rationale Zahlen]]
![[Äquivalenzklassen#Arithmetik mit rationalen Zahlen]]

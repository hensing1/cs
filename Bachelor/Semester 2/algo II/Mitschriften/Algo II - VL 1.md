Datum: 14.04.
[[Folien-2023-4-14.pdf|Folien]]
[[Skript AlgoII.pdf|Skript:]] Seiten 1 bis 14

# Grundlagen
## Probleme und Funktionen

Wir unterscheiden zunächst zwischen [[Algorithmen#Definition|Algorithmen]] und Problemen.

### Probleme

Unter einem *Problem* verstehen wir in dieser Vorlesung eine Relation, welche den gewünschten Zusammenhang zwischen Eingabe und Ausgabe für jede Eingabe erfasst.

Analog zur Definition einer [[Formale Sprachen und Grammatiken|formalen Sprache]] definieren wir die Relation für die Menge aller möglichen Worte $\Sigma ^{*}$ für ein Alphabet $\Sigma$. Üblicherweise enthält $\Sigma$ bei uns $0$ und $1$, kann aber je nach Problem um weitere nützliche Buchstaben erweitert werden.

![[Berechenbarkeitstheorie#^dbdbaf]]

Ein Algorithmus *löst ein Problem*, wenn er für jedes $x\in \Sigma ^{*}$ das entsprechende $y \in \Sigma ^{*}$ aus der zugehörigen Relation $R$ produziert. 
Kann dieses Problem auch als eine Funktion $f$ beschrieben werden, sagen wir, dass der Algorithmus die Funktion $f$ berechnet.

### Entscheidungsprobleme

![[Berechenbarkeitstheorie#^78018b]]

![[Berechenbarkeitstheorie#^75cb89]]

### Semantik
Für ein Wort $x \in \set{0,1}^{*}$ schreiben wir $\text{val}(x)$ für die durch $x$ kodierte Zahl.
Andersherum meinen wir mit $\text{bin}(n)$ den Textstring der Zahl $n$ in Binärdarstellung ohne führende Nullen. Damit hat $n$ eine eindeutige Darstellung in $\Sigma ^{*}$.

## Rechnermodelle
### Turingmaschine
![[Turingmaschine#Definition]]

![[Turingmaschine#Funktion einer Turingmaschine]]

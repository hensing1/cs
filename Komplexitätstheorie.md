## P
### Beschreibung
Die Klasse P enthält diejenigen Probleme, welche im Worst Case in polynomieller Zeit berechenbar sind. Sie ist für die meisten gängigen Rechner(-modelle), darunter insbesondere Turing- und Registermaschinen[^1], gleich. 
Generell ist die Klasse P damit gleichzusetzen mit der Klasse der effizient lösbaren Probleme. Auch wenn es prinzipiell Algorithmen in P gibt, welche auch für realistische Eingabegrößen äußerst hohe Laufzeiten erreichen und umgekehrt, hat sich diese Abstraktion in der Praxis als sinnvoll herausgestellt.

> Ein Entscheidungsproblem $L$ gehört genau dann zu der Komplexitätsklasse $\text{P}$, wenn es eine [[Turingmaschine#Turingmaschine|Turingmaschine]] $M$ gibt, die $L$ entscheidet, und eine Konstante $k \in \mathbb{N}$, für die $t_M(n)=\mathcal{O}(n^k)$ gilt.

[^1]: Vorausgesetzt wird das *logarithmische Kostenmaß* für Registermaschinen, also die Annahme, dass die Laufzeit einzelner Operationen linear von der Eingabelänge abhängt.

### Probleme der Klasse P
Zur Klasse P gehören:
- Zusammenhang eines Graphen (mittels [[Graphen#Tiefensuche|Tiefensuche]])
	- Ist der Graph als Adjazenzmatrix gegeben, liegt die Laufzeit der Tiefensuche in $\mathcal{O}(n^{2}\log(n))$ für $n$ Knoten. Der Faktor $\log(n)$ kommt dazu, weil wir das logarithmischen Kostenmaß ansetzen und zumindest der Index des aktuellen Knotens irgendwo abgespeichert werden muss, welcher wiederum von 1 bis $n$ reicht und $\log_2(n)$ Bits belegt. Dies ist aber für die Einteilung in die Klasse P nicht schlimm, da die Laufzeit trotzdem mit $\mathcal{O}(n^3)$ polynomiell grob nach oben abgeschätzt werden kann.
- Minimaler Spannbaum (mittels [[Minimaler Spannbaum#Algorithmus von Kruskal|Kruskal]])
- [[Rucksackproblem#Abwandlung: Fraktionales Rucksackproblem|Fraktionales Rucksackproblem]]

## NP
### Definition mittels nichtdeterministischer Turingmaschien
> Ein Entscheidungsproblem $L$ gehört genau dann zur Komplexitätsklasse $\text{NP}$, wenn es eine [[Turingmaschine#Nichtdeterministische Turingmaschine|nichtdeterministische Turingmaschine]] $M$ gibt, die $L$ entscheidet, und eine Konstante $k \in \mathbb{N}$, für die $t_M(n)=\mathcal{O}(n^{k})$ gilt.

$\text{NP}$ steht also für *nichtdeterministisch polynomiell*.

Da jede deterministische Turingmaschine auch als NTM aufgefasst werden kann, welche keinen Gebrauch von dem Nichtdeterminismus der Übergangsrelation macht, folgt direkt, dass die Klasse $\text{P}$ eine *Teilmenge* der Klasse $\text{NP}$ ist.

### Definition mittels Verifizierer
> Eine Sprache $L \subseteq \Sigma ^{\ast}$ ist genau dann in der Klasse $\text{NP}$ enthalten, wenn es eine deterministische Turingmaschine $V$ (einen Verifizierer) gibt, deren Worst-Case-Laufzeit polynomiell beschränkt ist, und ein Polynom $p$, sodass für jede Eingabe $x \in \Sigma ^{\ast}$ gilt: $$x \in L \iff \exists y \in \set{0,1} ^{\ast} : |y|\leq p(|x|) \text{ und } V \text{ akzeptiert }x \#y.$$
> Dabei sei $\#$ ein beliebiges Zeichen, das zum Eingabealphabet des Verifizierers, aber nicht zu $\Sigma$ gehört.

$y$ heißt hierbei das *Zertifikat*. Das Zertifikat kodiert in dieser Definition die nichtdeterministischen Schritte der NTM aus der anderen Definition. Man kann $y$ auch als Lösungskandidaten erfassen.

Zusammengefasst enthält $\text{NP}$ also alle Probleme, für die ein Lösungskandidat in polynomieller Zeit überprüft werden kann.

### Probleme der Klasse NP
- Alle Probleme der Klasse P
- [[Cliquenproblem]]
- [[Rucksackproblem]]

### Unterteilungen
> Algorithmen, deren Laufzeiten polynomiell von der Eingabelänge *und* den in der Eingabe vorkommenden Zahlen abhängen, heißen auch *pseudopolynomiell*.

Zum Beispiel ist das [[Rucksackproblem]] pseudopolynomiell, da es nur mit sehr großen Eingaben exponentiell lange dauert (Laufzeit $\mathcal{O}(n^{2}W$).

> $\text{NP}$-schwere Probleme, in deren Eingaben Zahlen vorkommen und die für Eingaben mit polynomiell großen Zahlen polynomiell lösbar sind, nennt man *schwach $\text{NP}$-schwere* Probleme. 
> Benötigt man auch für polynomiell begrenzte Eingabegrößen exponentielle Laufzeit, heißt das Problem *stark $\text{NP}$-schwer*.

Das [[Travelling Salesman Problem]] ist stark $\text{NP}$-schwer.

## FP und FNP
FNP und FP behandeln *Suchprobleme* (anders als Entscheidungsprobleme in P und NP).

Ein Suchproblem ist in FP, falls in Polynomialzeit eine Lösung gefunden werden kann.
Es ist in FNP falls, gegeben eine Probleminstanz und eine vorgeschlagene Lösung, man diese Lösung in polynomieller Zeit überprüfen kann.

Zu jedem FNP-Suchproblem gibt es ein NP-Entscheidungsproblem. 

## PLS
PLS ist eine Subklasse von [[Komplexitätstheorie#FP und FNP|FNP]]: $$\mathrm{FP}\subseteq \mathrm{PLS} \subseteq \mathrm{FNP}.$$
> [!abstract] Definition *Suchprobleme und lokale Optima*
> Ein Suchproblem $\Pi$ hat eine Menge von Instanzen $\mathcal{I}_{\Pi}$.
> Jede Instanz $I \in \mathcal{I}_{\Pi}$ hat eine endliche Menge von Lösungen $\mathcal{F}(I)$ und eine Bewertungsfunktion $c: \mathcal{F}(I)\to \mathbb{Z}$.
> Jede Lösung $s \in \mathcal{F}(I)$ hat eine Nachbarschaft von Lösungen $N(s, I) \subseteq \mathcal{F}(I)$.
> Eine Lösung $s$ ist ein *lokales Optimum*, falls $c(s) \leq c(s')$ für alle $s' \in N(s,I)$.

^77f8e6

> [!abstract] Definition *PLS* (Polynomial Local Search)
> Ein [[Komplexitätstheorie#^77f8e6|Suchproblem]] gehört in die Klasse PLS, falls die drei folgenden Polynomialzeitalgorithmen existieren:
> 1. Gegeben eine Instanz $I \in \mathcal{I}_{\Pi}$, gib eine Lösung $s \in \mathcal{F}(I)$ zurück
> 2. Gegeben eine  Instanz $I \in \mathcal{I}_{\Pi}$ und eine Lösung $s \in \mathcal{F}(I)$, berechne $c(s)$
> 3. Gegeben eine  Instanz $I \in \mathcal{I}_{\Pi}$ und eine Lösung $s \in \mathcal{F}(I)$, bestätige dass $s$ ein lokales Opimum ist oder gib ein $s' \in N(s,I)$ mit einem besseren $c(s')$ zurück
^bb9267

Allgemein wird davon ausgegangen, dass es Probleme in PLS gibt, die nicht in polynomieller Zeit gelöst werden können.
### Reduktion
> Ein PLS-Problem $\Pi_{1}$ kann auf ein PLS-Problem $\Pi_{2}$ *PLS-reduziert* werden (geschrieben $\Pi_{1} \leq_{\mathrm{PLS}} \Pi_{2}$), wenn:
> - Jede Instanz $I \in \mathcal{I}_{\Pi_{1}}$ in polynomieller Zeit in eine Instanz $f(I) \in \mathcal{I}_{\Pi_{2}}$ transformiert werden kann
> - Jedes lokale Optimum $s$ von $f(I)$ zu einem lokalen Optimum $g(s)$ von $I$ transformiert werden kann.

$\Pi_{1} \leq_{\mathrm{PLS}}\Pi_{2}$ bedeutet soviel wie "$\Pi_{1}$ ist nicht schwerer als $\Pi_{2}$".

> Ein Problem $\Pi^{*}$ ist **PLS-vollständig**, falls für jedes Problem $\Pi \in \mathrm{PLS}$ gilt: $\Pi \leq_{\mathrm{PLS}} \Pi^{*}$.

Ein PLS-vollständiges Problem ist *Max-Cut* (teile einen gewichteten Graphen in zwei Partitionen, sodass die zerschnittenen Kanten maximales Gewicht haben).
Max-Cut kann man dann auf weitere Probleme reduzieren, um deren PLS-Vollständigkeit zu zeigen.

# P versus NP
Aus der Definition der beiden Komplexitätsklassen folgt direkt: $\text{P} \subseteq \text{NP}$.

Es gibt Sprachen, welche zu $\text{NP}$ gehören, jedoch möglicherweise nicht zu $\text{P}$. Jedoch ist $\text{NP}$ nicht beliebig mächtig: jede NTM kann in exponenzieller Laufzeit durch eine TM simuliert werden (in dem jedes mögliche Zertifikat durchgegangen wird). Also sind NTMs im Hinblick auf die Berechenbarkeit nicht mächtiger als deterministische TMs. 

Es ist jedoch nicht bekannt, ob die Klassen $\text{P}$ und $\text{NP}$ tatsächlich verschieden sind; d.h. es hat noch niemand ein entscheidbares Problem gefunden, welches definitiv nicht von einer deterministischen Turingmaschine in polynomieller Zeit gelöst werden kann. 

# NP-Vollständigkeit

> [!abstract] Definition
> Eine [[Formale Sprachen und Grammatiken#Formale Sprachen|Sprache]] $L$ heißt **NP-schwer**, wenn für *jede* Sprache $L'\in \text{NP}$ gilt: $L'\leq_{p}L$ (vgl. [[Reduktionen#^94ab81|polynomielle Reduktion]]).
> Sie heißt zusätzlich **NP-vollständig**, wenn ebenfalls $L \in \text{NP}$ gilt.

^e3c746

> Gibt es eine *NP-schwere* Sprache $L \in \text{P}$, dann gilt $\text{P}=\text{NP}$.

^024b2b

> Eine *NP-vollständige* Sprache $L$ ist genau dann in $\text{P}$, wenn $\text{P}=\text{NP}$ gilt.

^9201b6

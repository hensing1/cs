Datum: 07.06.
[[Folien-2023-6-07.pdf|Folien]]
[[Skript AlgoII.pdf|Skript]] - Seiten 67 bis 74
[Video](https://uni-bonn.sciebo.de/s/YVfBpu1J5oiqZGj#/files_mediaviewer/Vorlesung-08.mp4)

# NP-vollständige Probleme

## 3-SAT

Das 3-SAT-Problem ist ein Speziallfall von [[Aussagenlogik#Satisfiability Problem (SAT)|SAT]], bei welchem man einschränkt, dass jede Klausel aus höchstens drei Literalen besteht.

> Man kann SAT polynomiell auf 3-SAT reduzieren.

$\Rightarrow$ 3-SAT ist #NP-vollständig. 

Mit 2-SAT geht das nicht mehr. 2-SAT kann man aber auch in polynomieller Zeit lösen.

### Reduktion von SAT auf 3-SAT
Sei die Instanz $\varphi$ von SAT in KNF gegeben. Um eine Instanz $\varphi'$ für 3-SAT zu erhalten, müssen lediglich die Klauseln mit Länge $k \geq 4$ aus $\varphi$ umgeformt werden. 

Dies geht wie folgt:
Ersetze jede Klausel $C=\ell_{1}\lor \ldots\lor\ell_{k}$ aus $\varphi$ durch Polynom $P=(\ell_{1}\lor\ell_{2}\lor y_{1}^{C})\land(\lnot y_{1}^{C}\lor \ell_{3}\lor y_{2}^{C})\land \ldots \land (\lnot y_{k-3}^{C}\lor\ell_{k-1}\lor\ell_{k})$ in $\varphi'$.

Ist $\ell_{1}=1$ oder $\ell_{2}=1$ Teil einer erfüllenden Belegung für $\varphi$, dann ist dies zusammen mit $y_{1}^{C}=\ldots=y_{k-3}^{C}=0$ eine erfüllende Belegung für $P$.

Ist $\ell_{i}=1$ mit $i \geq 3$ Teil einer erfüllenden Belegung für $\varphi$, dann ist dies zusammen mit $y_{1}^{C}=\ldots=y_{i-2}^{C}=1$ und $y_{i-1}^{C}=\ldots=y_{k-3}^{C}=0$ eine erfüllende Belegung für $P$.

Gibt es keine erfüllende Belegung für $C$, ist $\ell_{1}=\ldots=\ell_{k}=0$. Demnach muss $y_{1}^{C}=\ldots=y_{k-3}^{C}=1$ sein und die letzte Klausel von $P$ ist unerfüllt.

## Clique
> $3\text{-SAT}\leq_{p}\text{Clique}\Rightarrow \text{Clique}$ ist #NP-vollständig.

### Reduktion von 3-SAT auf Clique
Sei $\varphi$ die Eingabe für 3-SAT. Erstelle einen Knoten pro Literal in $\varphi$.

Füge eine Kante zwischen allen Knoten ein, die:
- nicht zur selben Klausel gehören, und
- sich nicht gegenseitig ausschließen, d.h. nicht zwischen $a$ und $\lnot a$ für eine Variable $a$.

Sei $k$ nun die Anzahl der Klauseln in $\varphi$. Falls es eine $k$-Clique im oben konstruierten Graphen gibt, dann bedeutet das, dass es $k$ Variablen gibt, die sich jeweils in verschiedenen Klauseln befinden und die sich nicht gegenseitig ausschließen: das heißt, $\varphi$ ist erfüllbar. 

## SubsetSum
*Eingabe:* Zahlen $a_{1},\ldots,a_{n}\in \mathbb{N}$ und $b \in \mathbb{N}$
*Frage:* kann man $b$ als Summe über eine Teilmenge aus $\set{a_{1},\ldots,a_{n}}$ darstellen?

SubsetSum ist in #NP, da man mit einer NTM zuerst eine Zahlenmenge zufällig auswählt und dann prüft, ob die Summe gleich $b$ ist.

Ebenfalls gilt:
> $3\text{-SAT}\leq_{p}\text{SubsetSum}\Rightarrow \text{SubsetSum}$ ist #NP-vollständig.

### Reduktion von 3-SAT auf SubsetSum
Die Reduktion einer Eingabe $\varphi$ für 3-SAT läuft wie folgt ab:
- Erstelle für jede der $n$ *Variablen* $x_{i}$ (nicht Literale!) aus $\varphi$ zwei Zahlen, $a_{i}$ und $\bar{a_{i}}$. Jedes $a_{i}$ und $\bar{a_{i}}$ hat an der Stelle $i$ eine 1.
- Falls die Variable $x_{i}$ in der Klausel $C_{j}$ vorkommt, hat $a_{i}$ an der Stelle $n+j$ eine 1. Falls $\lnot x_{i}$ in $C_{j}$ vorkommt, hat $\bar{a_{i}}$ dort eine 1.
- Alle übrigen Ziffern von $a_{i}$ und $\bar{a_{i}}$ sind gleich 0.
- Für jede der $m$ Klauseln $C_{j}$ erstellen wir noch 2 Hilfsvariablen $h_{j}$ und $h_{j}'$ die jeweils an der Stelle $n+j$ eine 1 haben und überall sonst 0 sind.
- Die ersten $n$ Stellen von $b$ sind 1, alle $m$ folgenden sind 3.

Allgemein treten keine Überträge auf, auch wenn man sämtliche Zahlen aufaddiert. Man kann also alle Ziffern separat betrachten.

![[3SAT_SubsetSum.png|400]]

Ist die derart formulierte Eingabe für SubsetSum lösbar, dann genau ist auch $\varphi$ erfüllbar:
- Man muss entweder $a_{i}$ oder $\bar{a_{i}}$ auswählen, um $b$ an der Stelle $i$ auf 1 zu bekommen. Das ist äquivalent dazu, dass $x_{i}$ entweder wahr oder falsch ist.
- In jeder Klausel $C_{j}$ muss mindestens eine Variable erfüllt sein, es muss also mindestens ein $a_{i}$ ausgewählt werden, das an der Stelle $n+j$ eine 1 hat. Dann kann man noch höchstens 2 Hilfsvariablen pro Klausel mit dazu nehmen, damit die Ziffer von $b$ an der Stelle $n+j$ gleich 3 ist.

## Partition
Es gilt: 
> $\text{SubsetSum} \leq_{p} \text{Partition}\Rightarrow \text{Partition}$ ist #NP-vollständig.

Reduktion:
Sei $A=\sum\limits_{i=1}^{n}a_{i}$ die Summe der Eingabe für SubsetSum (ohne $b$). Füge dieser Eingabe noch die Werte $a_{n+1}=2A-b$ und $a_{n+2}=A+b$ hinzu.
Es gilt: $\sum_{i=1}^{n+2}a_{i}=4A$, also muss Partition die Zahlen so aufteilen, dass beide Partitionen jeweils die Summe $2A$ haben. Da $a_{n+1}+a_{n+2}=3A$, können nicht beide dieser Zahlen in derselben Partition sein.

Betrachte die Partition, in der $a_{n+1}=2A-b$ enthalten ist. Die übrigen Zahlen haben die Summe $b$. Damit ist eine Lösung für SubsetSum gefunden.

## Rucksackproblem
Es gilt:
> $\text{SubsetSum}\leq_{p}\text{KP}\Rightarrow \text{KP}$ ist #NP-vollständig.

Reduktion:
Aus einer Eingabe für SubsetSum mit $n$ Zahlen wird eine Eingabe für das KP mit $n$ Objekten, bei denen der Nutzen gleich dem Gewicht ist: $p_{i}=w_{i}=a_{i}$. Gesucht ist dann eine Belegung für den Rucksack, sodass das Gewicht höchstens $b$ und der Nutzen mindestens $b$ ist.

# Einteilung von NP-schweren Problemen

![[Komplexitätstheorie#Unterteilungen]]
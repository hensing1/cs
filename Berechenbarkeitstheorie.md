## Probleme (formal)

> [!abstract] Definition *Problem*
> Unter einem Problem verstehen wir eine [[Relationen|Relation]] $R \subseteq \Sigma ^{*} \times \Sigma ^{*}$ mit der Eigenschaft, dass es für jede Eingabe $x \in \Sigma ^{*}$ mindestens eine Ausgabe $y \in \Sigma ^{*}$ mit $(x,y)\in R$ gibt.
> 
> Gibt es zu jeder Eingabe eine eindeutige Ausgabe, so können wir das Problem auch als [[Funktionen|Funktion]] $f : \Sigma ^{*} \rightarrow \Sigma ^{*}$ beschreiben.

^dbdbaf
### Unterteilungen

> [!abstract] Definition *Entscheidungsproblem*
> Ein Entscheidungsproblem wird definiert durch eine Funktion in der Form $f: \Sigma ^{*} \rightarrow \set{0,1}$.

^78018b

Jedes Entscheidungsproblem kann man als [[Formale Sprachen und Grammatiken#Formale Sprachen#Definition|Sprache]] $L_{f}=\set{x\in \Sigma ^{*} \mid f(x)=1}$ modellieren. 
Umgekehrt kann jede Sprache $L \subseteq \Sigma ^{*}$ als Funktion $f_{L}: \Sigma ^{\ast} \rightarrow \set{0,1}$ eines Entscheidungsproblem modelliert werden. In diesem Fall heißt die Funktion $f_{L}$ die *charakteristische Funktion* der Sprache $L.$ ^75cb89

Entsprechend nennt man ein Entscheidungsproblem auch *Wortproblem*.

## Automatentheorie

Es besteht folgender Zusammenhang zwischen der Hierarchie [[Formale Sprachen und Grammatiken|formaler Grammatiken]] und den Rechnermodellen, durch die sie entschieden werden können.

| Chomsky-Hierarchie          | Automatenmodell                                                                                                                         |
| --------------------------- | --------------------------------------------------------------------------------------------------------------------------------------- |
| Typ 0 (keine Einschränkung) | [[Turingmaschine]], [[Turingmaschine#Nichtdeterministische Turingmaschine\|Nichtdeterministische TM]], Registermaschinen                |
| Typ 1 (kontextsensitiv)     | Nichtdeterministische, linear beschränkte TM                                                                                            |
| Typ 2 (kontextfrei)         | [[Kellerautomat]]                                                                                                                       |
| Typ 3 (regulär)             | [[Endliche Automaten#Endliche Deterministische Automaten\|DFAs]], [[Endliche Automaten#Endliche Nichtdeterministische Automaten\|NFAs]] |

## Church-Turing-These
*Einfach:* 
> Jede "intuitiv berechenbare" Funktion kann durch eine Turing-Maschine berechnet werden.

"Intuitiv berechenbar" ist hierbei nicht formal definiert, was es unmöglich macht, diese These zu beweisen oder zu wiederlegen.

*Physikalisch:* 
> Mit unseren Gesetzen der Physik kann man keine Maschine bauen, welche eine Funktion berechnet, die nicht auch von einer Turingmaschine berechnet werden kann.

Diese These ist zumindest prinzipiell beweisbar. Man geht davon aus, dass sie stimmt.

*Erweitert:*
> Die Klasse der in polynomieller Zeit berechenbaren Funktionen ist für jedes realistisches Maschinenmodell dieselbe.

Diese These wird wegen Quantencomputern angezweifelt. Sie können Primzahlen in polynomieller Zeit faktorisieren; man geht aber davon aus, dass dies mit einer Turing- bzw. Registermaschine nicht möglich ist.

## Unentscheidbare Probleme
### Existenzbeweis

**Theorem:**
> Es gibt Funktionen $f : \mathbb{N} \rightarrow \mathbb{N}$, welche durch kein Programm berechnet werden können.

**Beweis:**
Die Menge aller Programme in einer beliebigen Programmiersprache ist *[[Mengen#Kardinalität#Abzählbare und überabzählbare Mengen|abzählbar unendlich]]*.

Denn: ein Programm besteht aus einer endlichen Anzahl von Zeichen aus einem Alphabet $\Sigma$. Das heißt, alle syntaktisch korrekten Programme $P$ sind Teilmenge von $\Sigma^{\ast}$.

Man kann eine [[Funktionen#Bijektive Funktion|Bijektion]] $f : \mathbb{N} \rightarrow \Sigma^{*}$ definieren, indem man alle Wörter aus $\Sigma ^{*}$ erst der Länge nach und dann lexikografisch ordnet (für $\Sigma = \set{0,1}$: $\epsilon, 0, 1, 00, 01, 10, 11, 000, 001, \ldots$).

$\Sigma^{*}$ ist also abzählbar unendlich, deshalb gibt es auch nur abzählbar unendlich viele Programme (vgl. [[Mengen#Theoreme#Teilmengen|dieses Theorem]]).

Die Menge aller Funktionen ist *überabzählbar unendlich*. Dies kann man per [[Beweistechniken#Diagonalisierung|Diagonalisierung]] zeigen: sei $f_{1},f_{2},f_{3},\ldots$ eine Nummerierung aller Funktionen. Nun kann man mit $$g(n) = \left\{\begin{array}{ll}1 & \text{falls } f_{n}(n)\neq 1, \\ 2 & \text{falls } f_{n}(n)=1\end{array}\right.$$ eine Funktion definieren, welche nicht in dieser Nummerierung vorhanden ist.

Demnach kann es keine [[Funktionen#Surjektive Funktion|surjektive]] Funktion geben, welche jedem Programm eine zugehörige Funktion zuweist. Also muss es Funktionen geben, zu welchen kein Programm geschrieben werden kann.

### Diagonalsprache

Seien $\langle M\rangle_{1}, \langle M\rangle_{2}, \langle M\rangle_{3}, \ldots$ die [[Algo II - VL 3#Gödelnummerierung|Gödelnummern]] aller erdenklichen [[Turingmaschine|Turingmaschinen]] in [[Glossar#Lexikografische und kanonische Ordnung|kanonischer Ordnung]], und $w_{1}, w_{2}, w_{3}, \ldots$ die Worte aus $\set{0,1}^{\ast}$ in kanonischer Ordnung.

Die Diagonalsprache sei definiert als: $$D=\set{w_{i}\in \set{0,1}^{*} \mid M_{i} \text{ akzeptiert } w_{i} \text{ nicht}}.$$
> Die Diagonalsprache ist nicht entscheidbar. 

Gäbe es nämlich eine Turingmaschine $M$, welche die Diagonalsprache entscheidet, hätte sie auch einen eindeutig zuordenbaren Index $i$. 
Müsste $M_i$ nun $w_i$ verarbeiten, kann sie dieses Wort nicht akzeptieren. Würde sie es akzeptieren, wäre es nicht Teil der Diagonalsprache, und die Akzeptanz wäre falsch. Sie kann es aber auch nicht verwerfen, denn würde sie es verwerfen, wäre es wieder Teil der Diagonalsprache und der Verwurf wäre falsch.
Wir haben also einen Widerspruch und folgern, dass die Diagnoalsprache nicht entscheidbar ist.

### Reduktionen
Um die Unentscheidbarkeit von Sprachen zu zeigen, nutzt man [[Reduktionen]]. Insbesondere nutzt man folgende Implikation: ![[Reduktionen#^cd6bde]]
### Halteproblem
Das Halteproblem ist definiert als die folgende Sprache: $$H = \set{\langle M \rangle w \mid M \text{ hält auf } w} \subseteq \set{0,1}^{*}.$$ ^37924f
> Das Halteproblem ist nicht entscheidbar.
> Gäbe es nämlich eine Turingmaschine $M_H$, die das Halteproblem entscheidet, könnte man damit eine andere Turingmaschine $M_D$ bauen, welche die [[Berechenbarkeitstheorie#Diagonalsprache|Diagonalsprache]] entscheidet.

^787d78

Man kann also $D$ auf $H$ [[Reduktionen|reduzieren]] ($D \leq H$).

### Semantische Eigenschaften von Turingmaschinen (Satz von Rice)

> [!abstract] Satz von 🍚
> Gegeben sei eine nicht-triviale[^1] Menge von Funktionen, welche von einer Turingmaschine berechnet werden können.
> Dann kann man nicht automatisch verifizieren, ob eine gegebene Turingmaschine eine Funktion berechnet, welche in dieser Menge enthalten ist.

[^1]: d.h. nicht die leere Menge, und auch nicht die Menge aller Funktionen, die von einer Turingmaschine berechnet werden können

Dieser Satz gilt natürlich auch dann, wenn $S$ einelementig ist. Also: gegeben eine beliebige Funktion $f$, z.B. $f(x)=x^2$, dann kann man keinen Compiler bauen, der eine beliebige Turingmaschine $M$ entgegennimmt und bestimmt, ob $f_M=f$ ist.

*Formal:*
Sei $$\mathcal{R}=\set{f: \Sigma ^{\ast} \to \Sigma ^{\ast} \cup \set{\bot} \mid \exists \text{ Turingmaschine }M \text{ mit } f_M=f}$$die Menge aller Funktionen, die von Turingmaschinen berechnet werden können.

Sei $S \subseteq \mathcal{R}$ und sei $$L(S)=\set{\langle M \rangle \mid f_{M} \in S}$$ die Menge der Gödelnummern aller Turingmaschinen, welche eine Funktion aus $S$ berechnen.

Dann besagt der Satz von Rice:
> Für jede Menge $S \subsetneq \mathcal{R}$ mit $S \neq \emptyset$ ist die **Sprache $L(S)$ nicht entscheidbar.**

## Semi-Entscheidbarkeit
![[Turingmaschine#^0f2a29]]

![[Reduktionen#^5e4d90]]

> Seien $L_{1}\subseteq \Sigma ^{\ast}$ und $L_{2}\subseteq \Sigma ^{\ast}$ zwei *rekursiv aufzählbare Sprachen*. 
> Dann sind die Sprachen $L_{1}\cup L_{2}$ und $L_{1}\cap L_{2}$ ebenfalls rekursiv aufzählbar.

^a14b13

> Ist sowohl die Sprache $L \subseteq \Sigma ^{\ast}$ als auch ihr Komplement $\bar{L} = \Sigma ^{\ast} \setminus L$ *rekursiv aufzählbar*, dann ist $L$ entscheidbar.

^0b12fe

# Aussagenlogik
Die Aussagenlogik befasst sich mit einer Menge von *atomaren Aussagen*, welche durch Anwenden von *Verknüpfungen* zu neuen Aussagen kombiniert werden können.

## Syntax
Die Syntax der Aussagenlogik definiert, was eine gültige aussagenlogische Formel ist und was nicht. Die Semantik spielt hierfür keine Rolle.

> [!abstract] Definition
> Die atomaren Aussagen werden dargestellt durch eine abzählbar unendliche Menge $AV$ von **Aussagenvariablen**: $$AV = \set{x_1,x_2,\ldots}.$$
> 
> Die Menge **$AL$** der **aussagenlogischen Formeln** ist die *kleinste Sprache* über dem Alphabet $AV \cup \set{0,1,\land,\lor,\lnot,\rightarrow,\leftrightarrow, (, )}$ mit folgenden Eigenschaften:
> 1. $0 \in AL$, $1 \in AL$
> 2. $\forall x \in AV: x \in AL$
> 3. Für $\varphi_1,\varphi_2\in AL$ ist:
> 	1. $\lnot \varphi_1 \in AL$ (Negation)
> 	2. $(\varphi_{1} \land \varphi_{2}) \in AL$ (Konjunktion)
> 	3. $(\varphi_{1} \lor \varphi_{2}) \in AL$ (Disjunktion)
> 	4. $(\varphi_{1} \rightarrow \varphi_{2}) \in AL$ (Implikation)
> 	5. $(\varphi_{1} \leftrightarrow \varphi_{2}) \in AL$ (Äquivalenz)

Die Klammern sind hierbei wichtig. Formeln aus $AL$ sind also $\lnot x$ oder $(x_{1}\land x_2)$, aber nicht $\lnot (x)$ oder $x_{1}\land x_{2}$.

Regeln zum Weglassen von Klammern müssen explizit vereinbart werden. Diese Regeln sind hier die Operatorpräzedenz ($\lnot$ vor $\land / \lor$ vor $\rightarrow/\leftrightarrow$), das Weglassen der äußersten Klammern, und das Verzichten auf Klammern bei Disjunktionen und Konjunktionen von mehr als zwei Formeln.
Also ist z.B. $x_{1}\land\lnot x_{2} \rightarrow x_3$ eine *Abkürzung* für den Ausdruck $((x_{1}\land\lnot x_{2} )\rightarrow x_3)$.

## Eigenschaften von aussagenlogischen Formeln
### Induktion über den Formelaufbau
[[Beweistechniken#Strukturelle Induktion|Strukturelle Induktion]] erlaubt das Nachweisen von einer beliebigen Eigenschaft $E$ für *jede* aussagenlogische Formel $\varphi \in AL$.

*Induktionsanfang:*
Die Formeln $0$, $1$ und jede Formel $x \in AV$ erfüllen Eigenschaft $E$.

*Induktionsschritt:*
Erfüllen zwei Formeln $\varphi_1,\varphi_{2} \in AL$ die Eigenschaft $E$, erfüllen auch $\lnot \varphi_1$, $(\varphi_{1}\lor \varphi_{2})$, $(\varphi_{1}\land \varphi_{2})$, $(\varphi_{1}\rightarrow \varphi_{2})$ und $(\varphi_{1}\leftrightarrow \varphi_{2})$ Eigenschaft $E$.

> [!example] Beispiel
> Induktive Definition der **Menge $\text{Var}(\varphi)$ der in $\varphi$ vorkommenden Variablen:**
> - $\text{Var}(0)=\text{Var}(1)=\emptyset$
> - $\forall x \in AV: \text{Var}(x) = \set{x}$
> - Für Verknüpfung $\circ \in \set{\land, \lor, \rightarrow, \leftrightarrow}$ und Formeln $\varphi_1,\varphi_{2}\in AL$ ist $\text{Var}((\varphi_{1}\circ \varphi_{2}))=\text{Var}(\varphi_{1})\cup \text{Var}(\varphi_{2})$.

### Eindeutige Zerlegbarkeit
Man kann eine aussagenlogische Formeln immer *eindeutig zerlegen*:
$\varphi = (\varphi_{1} \circ \varphi_{2}) = (\varphi_{1}' \circ' \varphi_{2}') \Rightarrow \circ = \circ', \space \varphi_{1}=\varphi_{1}', \space \varphi_{2} = \varphi_{2}'$.

Das heißt, man kann eine solche Aussage eindeutig in einen eindeutigen **Syntaxbaum** umwandeln.
Ein Syntaxbaum beschreibt den Aufbau einer aussagenlogischen Formel. Die Blätter sind hierbei die atomaren Aussagen, und die inneren Knoten verknüpfen ihre Kindknoten zu einer neuen aussagenlogischen Formel.

Induktive Definition der Tiefe $d$ eines Syntaxbaums:
1. $d(0) = d(1) = d(x) = 0$
2. $\varphi \in AL \Rightarrow d(\lnot \varphi) = d(\varphi) + 1$
3. $\varphi_{1},\varphi_{2} \in AL, \space \circ \in \set{\land, \lor, \rightarrow, \leftrightarrow} \Rightarrow d(\varphi_{1} \circ \varphi_{2})=\text{max}\set{d(\varphi_{1}),d(\varphi_{2})}+1$.

## Semantik
> [!abstract] Definition
> Die **Bewertung** einer Variablenmenge $X \subseteq AV$ ist eine Abbildung $B : X \rightarrow \set{0,1}$.
> $B$ heißt *passend* für eine Formel $\varphi\in AL$, wenn $\text{Var}(\varphi)\subseteq X$.
> 
> Der **Wahrheitswert** $[\![\varphi]\!]_{B} \in \set{0,1}, \varphi \in AL$ bezüglich einer passenden Bewertung $B$ ist wie folgt definiert:
> - $[\![0]\!]_{B}:=0$, $[\![1]\!]_{B}:=1$, $\forall x \in X: [\![x]\!]_{B}:=B(x)$
> - $[\![\lnot \varphi]\!]_{B}:=1-[\![\varphi]\!]_{B}$
> - $[\![\varphi_{1}\land \varphi_{2}]\!]_{B}:=\text{min}\set{[\![\varphi_{1}]\!]_{B},[\![\varphi_{2}]\!]_{B}}$
> - $[\![\varphi_{1}\lor \varphi_{2}]\!]_{B}:=\text{max}\set{[\![\varphi_{1}]\!]_{B},[\![\varphi_{2}]\!]_{B}}$
> - $[\![(\varphi_{1}\rightarrow \varphi_{2})]\!]_{B}:=[\![(\lnot\varphi_1\lor\varphi_{2})]\!]_{B}$
> - $[\![(\varphi_{1}\leftrightarrow \varphi_{2})]\!]_{B}:=\left\{\begin{array}{ll}1 & \text{falls } [\![\varphi_{1}]\!]_{B}=[\![\varphi_{2}]\!]_{B}\\0 & \text{sonst.}\end{array}\right.$
^48f28f

Indem man diese Definitionen rekursiv auf eine aussagenlogische Formel anwendet, kann man ihren Wahrheitswert automatisiert bestimmen. ^a5a1c8

### Erfüllbarkeit

> [!abstract] Definitionen
> #### Modell
> Eine zu einer aussagenlogischen Formel $\varphi$ passende [[Aussagenlogik#^48f28f|Bewertung]] $B$ heißt **Modell** von $\varphi$, falls $[\![\varphi]\!]_{B}=1$.
> Man sagt dann, dass $B$ die Formel $\varphi$ *erfüllt* und schreibt $B \models \varphi$.
> 
> Für eine *Formelmenge* $\Phi\subseteq AL$ ist *$B$ ein Modell für $\Phi$* ($B \models \Phi$), falls $B$ *alle* Formeln dieser Formelmenge erfüllt.
> 
> #### Erfüllbarkeit
> Eine Formel $\varphi$ heißt **erfüllbar**, wenn es ein *Modell* für sie gibt.
> 
> #### Gültigkeit
> Eine Formel $\varphi$ heißt **gültig**, wenn sie durch jede für sie passende Bewertung erfüllt wird. Dann heißt $\varphi$ auch *Tautologie* und man schreibt $\models \varphi$.
^73b223

> Eine Formel $\varphi$ ist genau dann erfüllbar, wenn $\lnot \varphi$ keine Tautologie ist.
^b6f785

#### Satisfiability Problem (SAT)
Beim SAT-Problem geht es darum, algorithmisch festzustellen, ob eine gegebene aussagenlogische Formel *erfüllbar* ist. Dieses Problem ist #NP-vollständig.

Das SAT-Problem ist deshalb interessant, weil man das Verhalten einer [[Turingmaschine#Nichtdeterministische Turingmaschine|nichtdeterministischen Turingmaschine]] für eine Eingabe $x$ in einer AL-Formel kodieren kann, sodass:
- die Länge der resultierenden Formel polynomiell von der Laufzeit der TM abhängt, und
- die Formel genau dann erfüllbar ist, wenn die TM die Eingabe $x$ akzeptiert.

Wie genau das geht, steht im [[Skript AlgoII.pdf|Skript für Algo II]] auf Seite 62. Wichtig ist am Ende nur, dass die Erzeugung der Formel polynomielle Zeit dauert, solange die Anzahl der Rechenschritte der TM polynomiell begrenzt sind.

Das alles bedeutet, dass sich alle Probleme aus [[Komplexitätstheorie#NP|NP]] polynomiell auf SAT [[Beweistechniken#^cc7bcb|reduzieren]] lassen. Zusätzlich damit, dass SAT selbst in NP ist, zeigt dies also, dass SAT [[Komplexitätstheorie#NP-Vollständigkeit|NP-vollständig]] ist.
Dies dient gewissermaßen als Brücke, wenn man für andere Probleme NP-Vollständigkeit zeigen will. Hierfür muss man nun bloß noch SAT polynomiell auf dieses Problem reduzieren.

### Äquivalenz
> [!abstract] Definition
> Zwei Formeln $\varphi_{1},\varphi_{2} \in AL$ heißen **logisch äquivalent**, wenn $$[\![\varphi_1]\!]_{B}=[\![\varphi_2]\!]_{B}$$
> für jede zu $\varphi_1$ und $\varphi_2$ passende Bewertung $B$.
> 
> Schreibweise: $\varphi_{1} \equiv \varphi_{2}$.

Offensichtlicherweise ist $\equiv$ eine [[Relationen#Äquivalenzrelation|Äquivalenzrelation]].

### Rechenregeln und Umformungen
Wie auch z.B. bei der [[Boolesche Algebra|booleschen Algebra]] gelten für Umformungen:
- Idempotenz - $(\varphi\land\varphi)\equiv(\varphi\lor\varphi)\equiv\varphi$
- Kommutativität bzgl. $\land$ und $\lor$
- Assoziativität bzgl. $\land$ und $\lor$
- Elimination der doppelten Negation
- Die De-Morgan'schen Regeln: $\lnot(\varphi_{1}\land\varphi_{2})\equiv(\lnot\varphi_{1}\lor\lnot\varphi_{2}), \space \lnot(\varphi_{1}\lor\varphi_{2})\equiv(\lnot\varphi_{1}\land\lnot\varphi_{2})$
- Distributivgesetze
- Absorption
- Kontraposition
- Elimination der Implikation: $(\varphi_{1}\rightarrow\varphi_2)\equiv(\lnot\varphi_{1}\lor\varphi_{2})$
- Elimination der Äquivalenz: $(\varphi_{1}\leftrightarrow\varphi_2)\equiv((\varphi_{1}\rightarrow\varphi_2)\land(\varphi_{2}\rightarrow\varphi_1))$

## Normalformen

> Eine Formel der Form $x$ oder $\lnot x$ heißt *Literal*.

> [!abstract] Definition *Konjunktive und Disjunktive Normalform*
> Eine aussagenlogische Formel $\varphi$ ist in **konjunktiver Normalform** (*KNF*), wenn sie eine *Konjunktion von Disjunktionen* von Literalen ist, d.h. wenn sie die Gestalt $$\varphi=\bigwedge\limits_{i=1}^{n}\left(\bigvee\limits_{j=1}^{m_{i}}\ell_{i,j}\right)$$ für $n,m_{1},\ldots,m_{n}\in \mathbb{N}$ und Literale $\ell_{i,j}$ hat.
> 
> Die Teilformeln $\bigvee_{j=1}^{m_{i}}\ell_{i,j}$ heißen *Klauseln* von $\varphi$.
> 
> $\varphi$ ist in **disjunktiver Normalform** (DNF, Disjunktion von Konjunktionen), falls:
>$$\varphi=\bigvee\limits_{i=1}^{n}\left(\bigwedge\limits_{j=1}^{m_{i}}\ell_{i,j}\right)$$

*Jede* aussagenlogische Formel lässt sich in die KNF und die DNF umformen.


# Endliche Automaten
## Definition
Ein endlicher Automat ist ein einfaches Rechnermodell. Mit einem endlichen Automaten können genau die [[Formale Sprachen und Grammatiken#Chomsky-Hierarchien#Definition|regulären Sprachen]] entschieden werden (siehe [[Berechenbarkeitstheorie]]).

## Endliche Deterministische Automaten
> [!Definition]
> Ein **Endlicher Deterministischer Automat** (DFA für Deterministic Finite Automaton) ist ein 5-Tupel $M=(Q,\Sigma,\delta,q_{0},F)$, derart dass:
> - $Q$: endliche Menge von Zuständen
> - $\Sigma$: Eingabealphabet
> - $\delta$: Übergangsfunktion, $\delta : Q \times \Sigma \rightarrow Q$
> - $q_0$: Startzustand
> - $F \subseteq Q$: Menge der akzeptierenden Zustände

### Arbeitsweise
Ein beliebiges Wort ist die Eingabe, und der Automat arbeitet dieses Wort von links nach rechts ab und sagt mir am Ende, ob dieses Wort akzeptiert wird oder nicht.

- Man hat ein Eingabewort $w=w_1,w_2,\ldots,w_n$
- Man liest dieses Wort von links nach rechts ein:
	- Werte $\delta(q_{0},w_{1})=q_{1}$ aus
	- Werte $\delta(q_{1},w_{2})=q_{2}$ aus
	- $\vdots$
	- Werte $\delta(q_{n-1},w_{n})=q_{n}$ aus
	- Falls $q_{n} \in F$, dann ist das Wort "akzeptiert"

Heißt: $d(q,a)=q'$ bedeutet: Beim Lesen von Buchstabe $a$ in Zustand $q$ ist der Folgezustand $q'$.

Nun interessiert uns ja eigentlich nur der Endzustand $q_n$. Wir definieren uns also eine Funktion $\delta^*$, für die gilt: $\delta^{*}(q_{0},w)=q_{n}$. Formal macht man das folgendermaßen:
- $\delta^{*}(q,\epsilon):=q$
- $\delta^{*}(q,a):=\delta(q,a)$
- $\delta^{*}(q,aw):=\delta^{*}(\delta(q,a),w)$.

### Begriffsdefinitionen
- **"$M$ verwirft Wort $w$"**, wenn am Ende $q_{n} \not \in F$
- **"$M$ akzeptiert Wort $w$"**, wenn $q_{n}\in F$
- **Die akzeptierte Sprache von $M$**: $L(M):=\set{w\in \Sigma^{*} \space | \space \delta^{*}(w)\in F}$, also die Menge aller Worte, die von unserem DFA akzeptiert werden.
	- -> "$M$ akzeptiert/entscheidet $L(M)$"

### Anschauliche Darstellung
Ein DFA kann als Übergangsgraph dargestellt werden.[^1] Untenstehend ist ein DFA, welcher entscheidet, ob ein Wort mit $\Sigma=\set{0,1}$ eine gerade Anzahl an einsen und eine gerade Anzahl an Nullen hat. (Formal: $L(M)=\set{w \in \Sigma^{*} |\space |w|_{0} \text{ ist gerade und } |w|_{1} \text{ ist gerade}}$).

![[Uebergangsgraph_DFA.png]]

Der akzeptierende Zustand ist hierbei mit einem Doppelkreis markiert. Der Startzustand wird mit einem zusätzlichen Pfeil gekennzeichnet. Im obigen Fall ist der Startzustand auch der akzeptierende Zustand.

[^1]: Wenn man diese Darstellung mit Latex machen will, geht das mit dem Modul `tikzpicture`

### Was kann ein DFA?
Ein DFA kann links- und rechtslineare Sprachen entscheiden, aber keine nichtregulären Sprachen.

z.B.: die Sprache $L=\set{0^{n}1^{n}|n\in\mathbb{N}}$ kann durch keinen DFA entschieden werden, da der Automat ja das Wort von links nach rechts abarbeitet, aber nicht zählen kann wie viele Nullen / Einsen er schon gesehen hat. Man hat also nie genug Zustände, um Worte einer beliebigen Länge zu entscheiden.

### "Pumping-Lemma" für DFAs
Für einige Sprachen ist es schwierig, direkt zu beweisen, dass sie von keinem DFA entschieden werden können. 
Als Hilfsmittel gibt es das Pumping-Lemma. Das Pumping-Lemma ist eine *notwendige* Bedingung dafür, dass eine Sprache von einem DFA entschieden werden kann. Das heißt: gilt das Pumping-Lemma nicht für eine Sprache $L$, dann kann $L$ auch nicht von einem DFA entschieden werden.

> [!abstract] Pumping-Lemma
> Sei $L$ eine Sprache, die von DFAs akzeptiert wird. Dann gilt:
> Es existiert eine Konstante $n$, sodass alle Worte $z$, welche mindestens die Länge $n$ haben, in drei Teile $z=uvw$ geteilt werden können mit $|uv|\leq n$ und $v \neq \epsilon$, sodass man $v$ beliebig oft wiederholen ("aufpumpen") kann, und das resultierende Wort $uv^{i}w$ immer noch in der Sprache $L$ ist (für alle $i \geq 0$).

#### Wieso ist das so?
Naja, ein DFA hat nun mal nur endlich viele Zustände. Wenn es also ein Wort gibt, das von dem DFA akzeptiert wird und das mindestens so viele Buchstaben enthält wie es Zustände im DFA gibt, dann muss der DFA beim Akzeptieren dieses Wortes mindestens einen Zustand mehrfach durchlaufen haben (ohne Zustandswiederholung kann man mit $n$ Zuständen ein Wort der Länge $n-1$ entscheiden).

Und wenn ein Zustand (nennen wir ihn mal $q_{r}$) mehrfach wiederholt werden kann, dann muss es auch einen Weg geben, von $q_{r}$ wieder zurück nach $q_{r}$ zu gelangen. Und diesen Weg kann man beliebig oft gehen. 
Das Teilwort $u$ in dem Pumping-Lemma beschreibt, wie man den Automaten vom Startzustand in Zustand $q_{r}$ bekommt ($\delta^{*}(q_{0},u)=q_{r}$). Das Teilwort $w$ beschreibt, wie man von $q_{r}$ in einen akzeptierenden Zustand gelangt. 
Das Teilwort $v$ beschreibt, wie man, wenn man in $q_{r}$ ist, zurück nach $q_{r}$ kommt ($\delta^*(q_{r},v)=q_{r}$). Das kann man beliebig oft machen (auch 0-mal), und deshalb kann man das Wort $uvw$ beliebig oft mit $v$ aufpumpen.

> [!attention] Achtung Vorsicht
> Wenn es keine Worte in $L$ gibt, die mindestens so lang sind wie die Anzahl der Zustände in unserem DFA (bzw. wenn es keine Zustände im DFA gibt, die sich wiederholen können), dann gilt das Pumping-Lemma *trotzdem*. Es macht ja nur eine Aussage darüber, falls es solche Worte in $L$ gibt.

## Endliche Nichtdeterministische Automaten
### Definition
Ein Nichtdeterministischer Endlicher Automat (NFA, Non-deterministic Finite Automaton) funktioniert genau wie ein DFA, nur dass auf einen Zustand nach Einlesen desselben Buchstaben verschiedene Zustände folgen können.

Konkret bedeutet das, dass sich im Vergleich zum DFA nur die Zustandsübergangsfunktion $\delta$ ändert: sie ist nun definiert als $\delta : Q \times \Sigma \rightarrow \mathcal{P}(Q)$, d.h. $\delta(q,a)$ ist die *Menge aller möglichen erreichbaren Zustände* beim Einlesen von $a$.
Achtung: $\delta(q,a)$ kann auch die leere Menge sein. In diesem Fall terminiert der Automat vorzeitig und verwirft das Wort.

$\delta^{*}$ ist wie folgt definiert:
- $\delta^{*}(q,\epsilon)=\set{q}$
- $\delta^{*}(q,a)=\delta(q,a)$
- $\delta^{*}(q,w)=\bigcup\limits_{q'\in\delta(q,w_{1})}\delta^{*}(q',w_{2},\ldots,w_{n})$.

$M \text{ ``akzeptiert" } w :\iff \delta^{*}(q_{0},w)\cap F \not = \emptyset$

### Nutzen und Mächtigkeit
Ein NFA kann keine Sprachen entscheiden, die ein DFA nicht auch entscheiden könnte. Der Vorteil ist jedoch, dass ein NFA unter Umständen wesentlich weniger Zustände benötigt.

> Zu jedem NFA mit $n$ Zuständen gibt es einen DFA mit $2^{n}$ Zuständen, der dieselbe Sprache entscheidet.

### Umformung von NFA in DFA

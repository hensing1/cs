Datum: 02.05.
[[AI08_SS24_SitCalcul_240502_240502.pdf|Folien]]

# PL1-Inferenz

Wir möchten aus einer PL1-KB mittels [[GdKI - VL 7#Generalisierter Modus Ponens (GMP)|GMP]] eine (atomare) Aussage $\alpha$ ableiten.

Vorwärts- und Rückwärtsableitung werden z.B. durch die Programmiersprache Prolog umgesetzt.

## Vorwärtsableitung (Forward Chaining)

Wir leiten so lange mit dem GMP neue Aussagen ab, bis wir entweder die Zielaussage gefunden haben oder nichts neues mehr ableiten können.
Die KB darf nur definite Klauseln enthalten, muss sich also als Implikation schreiben lassen können.

> **FOL-FC-Ask**: $\text{KB}, \alpha \mapsto \textbf{a substitution} \text{ or }\textbf{fail}$
> `do:`
> > $\text{new} \leftarrow \set{}$
> > 
> > `foreach sentence r in KB:`
> > > $(p_{1} \land \ldots \land p_{n} \Rightarrow q) \leftarrow$ `Standardize(r)`
> > > 
> > > `foreach` $\theta$, sodass `Substitute(`$\theta, p_{1} \land \ldots \land p_{n}$`) = Substitute(`$\theta, p'_{1} \land \ldots \land p'_{n}$`)` für irgendein $p_{1}', \ldots, p_{n}'$ aus `KB:`
> > > > $q' \leftarrow$ `Substitute`$(\theta, q)$
> > > > 
> > > > `if` $q'$ kommt noch nicht in $\text{new}$ oder KB vor:
> > > > > $\text{new} \,+\!\!= q'$
> > > > > $\varphi \leftarrow$ `Unify`$(q', \alpha)$ *// Zieltest*
> > > > > `if` $\varphi$ `!= fail then return `$\varphi$
> > 
> > `KB += new`
> 
> `while new != {}`
> 
> `return false`

Allgemein können hier Endlosschleifen entstehen. Die Frage, ob mit Vorwärtsableitung aus einer beliebigen KB eine beliebige Aussage abgeleitet werden kann, ist [[Berechenbarkeitstheorie#Unentscheidbare Probleme|unentscheidbar]].

Welche Regeln in der inneren Schleife ausgewählt werden müssen, um ans Ziel zu gelangen, ist ein [[Komplexitätstheorie#NP-Vollständigkeit|NP-schweres]] Problem.

## Rückwärtsableitung

Die Rückwärtsableitung fängt mit der zu zeigenden Aussage an und generiert alle Prämissen, die gemäß der KB dafür erfüllt sein müssen. Dies wird via [[Graphen#Tiefensuche|Tiefensuche]] fortgeführt, bis alle Prämissen in der KB gefunden wurden, oder nichts weiter abgeleitet werden kann.

![[Rückwärtssuche.png]]

Das alles ist ebenfalls unentscheidbar und NP-schwer.

## Binäre PL1-Resolution mit Faktorisierung

*Binäre Resolution in PL1:* 
- Gegeben: zwei Klauseln $L = \set{l_{1},\ldots,l_{k}}$ und $M = \set{m_{1},\ldots,m_{n}}$
- Wir resolvieren über zwei Literale $l_{i}$ und $m_{j}$, für die gilt: $\text{Unify}(l_{i},\lnot m_{j}) = \theta$
- Resolvente: $(L \cup M \setminus \set{l_{i},m_{j}})\theta$

Beispiel:
- Gegeben: $\lnot \text{Rich}(x) \lor \text{Unhappy}(x)$ und $\text{Rich(Ken)}$
- $\theta = \set{x/\text{Ken}}$
- Resolvente: $\text{Unhappy(Ken)}$.

*Faktorisierung in PL1:*
Die Faktorisierung macht aus einer Klausel $a \lor b \lor b \lor c$ die Resolvente $a \lor b \lor c$.

> Die binäre Resolution zusammen mit Faktorisieung (aka. *vollständige prädikatenlogische Resolution*) auf die Konjunktive Normalform $\text{KB} \land \lnot a$ ist **korrekt** und **widerspruchsvollständig** (d.h. wenn es einen Widerspruch gibt, wird dieser gefunden).

# Situationskalkül

Wir hätten gerne einen Agenten, der etwas mehr kann als nur reflexartig auf Situationen zu reagieren - d.h. unser Agent braucht ein **Weltmodell**.

Eine Möglichkeit, um mit PL1 eine dynamische Welt zu modellieren, ist das Situationskalkül.

> [!abstract] Definition *Situationskalkül*
> - Die **Welt** ist eine *Folge von Zuständen*
> - Ein **Zustand** ist ein *[[GdKI - VL 7#^27b8d9|Term]]*
> - Ein Zustandsübergang $s \to s'$ geht nur mit der Funktion $s' = \text{do}(a,s)$
> 	- $a$ ist eine Aktion
> - Eine **Aktion** ist eine Funktion und wird beschrieben durch *Vorbedingungen* und *Effekte*
> - Ein Prädikat eines Objekts $x$, welches sich *ändern* kann, nimmt zusätzlich einen Zustand $s$ entgegen und heißt *Fluent*

Die Zustände heißen auch Situationen, die Prädikate heißen auch Relationen.

> **Beschreibung einer Aktion**
> Formulierung einer Vorbedingung: $$\forall x, s: \text{Poss}(\text{action}(x),s) \iff \text{Prädikat}_{1}(x,s) \land \text{Prädikat}_{2}(x) \land \ldots$$
> Formulierung eines Effekts: $$\begin{align*}
 \text{Positives Effektaxiom: }&\forall x,s: \text{Poss}(\text{action}(x),s) \Rightarrow \text{Prädikat}(x, \text{do}(\text{action}(x),s))\\
 \text{Negatives Effektaxiom: }&\forall x,s: \text{Poss}(\text{action}(x),s) \Rightarrow \lnot\text{Prädikat}(x, \text{do}(\text{action}(x),s))
 \end{align*}$$

Ist eine Aktion immer möglich, kann man die Vorbedingung beim Effektaxiom auch weglassen.

Zusätzlich zur Aktionsbeschreibung muss man auch spezifizieren, welche Fluents durch eine Aktion *nicht* geändert werden. Diese Aufgabe heißt **Rahmenproblem**.

> **Lösung des Rahmenproblems durch Rahmenaxiome**
> Alle Aktionen außer $\text{action}$ lassen $\text{Prädikat}$ *unverändert*:
> $$\forall a,x,s: \text{Prädikat}(x,s) \land [a \neq \text{action}(s) \lor \lnot \text{Poss}(\text{action}(x),s)] \implies \text{Prädikat}(x, \text{do}(a,s))$$

Die Spezifikation der Rahmenaxiome kann aufwändig werden, da bei $F$ Fluents und $A$ Aktionen $\mathcal{O}(|F \times A|)$ Axiome entstehen können.

> **Lösung des Rahmenproblems durch Nachfolgezustands-Axiome**
> Aufzählungen aller Aktionen, die $\text{Prädikat}$ *wahr machen* ($\text{action}_1$) oder *nicht falsch werden lassen*: $$\begin{align*}
\forall a,x,s: \text{Prädikat}(x, \text{do}(a,s)) \iff& (a = \text{action}_{1} \land \text{Poss}(a,s)) \,\lor\\
&(\text{Prädikat}(x,s) \land a \neq \text{action}_{2}(x))
\end{align*}$$

Die Nachfolgezustands-Axiome können automatisch aus Rahmen- und Effektaxiomen generiert werden, unter der Annahme, dass nur die aufgezählten Effekte auftreten und sonst keine.

## Exploration

Diagnostische Regeln: Axiome, die aus Eigenschaften eines *Zustands* (z.B. wenn ein Agent an einem bestimmten Ort ist und ein Perzept wahrnimmt) *allgemeingültige Eigenschaften* (Prädikate ohne Zustand) schließen

Kausale Regeln: Axiome, die Ursachen von Perzepten erklären

## Aktionsauswahl
Man kann Präferenzen für Aktionen kodieren: 
$$\begin{gather}
\forall s: \text{Poss}(\text{action}_{1},s) \Rightarrow \text{Great}(\text{aktion}_{1},s)\\
\forall a,s: \text{Great}(a,s) \Rightarrow \text{PreferredAction}(a,s)\\
\forall a,s: \text{Good}(a,s)\land\lnot \exists b \,\text{Great}(b,s) \Rightarrow \text{PreferredAction}(a,s)\\
\ldots
\end{gather}$$

## Einschränkungen

- Keine explizite Spezifizierung von *Zeit*
	- man kann nicht ausdrücken, wie lange eine Aktion dauert
- Nur eine Aktion gleichzeitig
- Nur der Agent kann Zustände verändern
- Aktionen sind deterministisch

# Turingmaschine
## Definition
Eine Turingmaschine (abgekürzt mit TM) ist ähnlich zu einem [[Endliche Automaten|endlicher Automaten]] mit einem Band mit unendlich vielen Speicherzellen.

Es gibt zusätzlich einen *Lese-/Schreibkopf*, welcher sich über einer Zelle befindet und mit dieser interagieren kann. 
In jeder Speicherzelle steht ein Zeichen aus einem *Bandalphabet* $\Gamma$. Dabei enthält $\Gamma$ insbesondere das Leerzeichen $\square$. Es gilt $\Sigma \subset \Gamma$ und $\square \not\in \Sigma$.

Genau wie ein endlicher Automat hat auch die Turingmaschine eine endliche Zustandsmenge. Dazu gehört ein Startzustand $q_{0}$ und ein Endzustand $\bar{q}$ (anstelle eines akzeptierenden Zustands).

*Programmablauf:*
Zu Beginn steht lediglich die Eingabe auf dem Band, alle Zellen links und rechts davon enthalten das Leerzeichen $\square$. Der Kopf steht auf dem ersten Zeichen der Eingabe.

In jedem Rechenschritt liest nun der Kopf das Zeichen der aktuellen Zelle. Abhängig von diesem Zeichen und dem aktuellen Zustand wird ein neues Zeichen geschrieben, der Zustand gewechselt, und/oder der Kopf um eine Stelle bewegt.

Erreicht die Turingmaschine den Endzustand, werden alle Zellen von der aktuellen Kopfposition bis zum ersten Zeichen aus $\Gamma\setminus\Sigma$ als Ausgabe interpretiert.

*Formal:*
> [!abstract] Definition
> Eine **Turingmaschine** $M$ ist ein 7-Tupel $(Q, \Sigma, \Gamma, \square, q_{0}, \bar{q}, \delta)$, bestehend aus folgenden Komponenten:
> - Endliche Zustandsmenge $Q$
> - Endliches Eingabealphabet $\Sigma \supseteq \set{0,1}$
> - Endliches Bandalphabet $\Gamma \supset \Sigma$
> - Das Leerzeichen $\square \in \Gamma  \setminus \Sigma$
> - Startzustand $q_0$
> - Endzustand $\bar{q}$
> - Zustandsübergangsfunktion $\delta: (Q \setminus \set{\bar{q}}) \times \Gamma \rightarrow Q \times \Gamma \times \set{L,N,R}$

^a9ba8f

## Funktion einer Turingmaschine
Das Verhalten jeder Turingmaschine $M$ kann man mit einer Funktion $f_M:\Sigma ^{*} \rightarrow \Sigma ^{*}\cup \set{\bot}$ beschreiben. 

Produziert die Turingmaschine für eine Eingabe $a$ aus $\Sigma ^{*}$ in endlicher Zeit eine Ausgabe $b$, gilt $f_M(a)=b$.
Falls die Turingmaschine für die Eingabe $a$ nicht hält (nicht terminiert), definieren wir $f_M(a)=\bot$.

> [!abstract] **Berechenbarkeit einer Funktion**
> Eine Funktion $f:\Sigma ^{*} \rightarrow \Sigma ^{*}$ heißt **berechenbar** (oder rekursiv[^1]), wenn es eine Turingmaschine $M$ mit $f_M=f$ gibt.
> Das heißt insbesondere, dass $M$ auf jede Eingabe terminiert.

[^1]: "rekursiv" heißt hier nur berechenbar, und nicht, dass sie z.B. rekursiv definiert ist.

## Akzeptanzverhalten
> Eine Turingmaschine $M$ *akzeptiert* eine Eingabe $w \in \Sigma ^{*}$, wenn die Ausgabe mit einer $1$ beginnt. Sie *verwirft* die Eingabe, wenn die Ausgabe mit einer $0$ beginnt.
> 
> Beide Fälle treten nur dann ein, wenn $M$ auch terminiert.

> Eine Turingmaschine *entscheidet* eine [[Formale Sprachen und Grammatiken#Definition|Sprache]] $L \subseteq \Sigma ^{*}$, wenn sie jedes Wort $w \in L$ akzeptiert und jedes Wort $w \in \Sigma ^{*} \setminus L$ verwirft.
> Eine Sprache $L \subseteq \Sigma ^{*}$ heißt **entscheidbar** oder **rekursiv**, wenn es eine Turingmaschine $M$ gibt, die $L$ entscheidet. $M$ heißt dann *Turingmaschine für die Sprache $L$*. Eine solche Turingmaschine terminiert auf jede Eingabe.

> Eine Turingmaschine *erkennt* eine Sprache $L \subseteq \Sigma ^{\ast}$, wenn sie jedes Wort $w \in L$ akzeptiert und jedes Wort $w \in \Sigma ^{\ast} \setminus L$ entweder verwirft oder darauf nicht terminiert.
> Eine Sprache $L \subseteq \Sigma ^{*}$ heißt **semi-entscheidbar** oder **rekursiv aufzählbar**, wenn es eine Turingmaschine $M$ gibt, die $L$ erkennt.

^0f2a29

### Modellierung eines endlichen Automaten
Man kann mit einer Turingmaschine einen [[Endliche Automaten|endlichen Automaten]] modellieren, indem man nach jeder Eingabe nach rechts geht und entsprechend den Zustand aktualisiert. Erreicht man ein Leerzeichen, schreibt man die Ausgabe (1 oder 0) abhängig davon, ob der derzeitige Zustand ein akzeptierender Zustand ist oder nicht.

## Methoden zum Entwurf einer Turingmaschine

> [!info]- **Variablen**
> Variablen (und deren Belegung) können bei Turingmaschinen durch Zustände modelliert werden:
> - Sei $K$ die endliche Wertemenge, welche die Variable annehmen können soll.
> 	- Sie muss endlich sein. Das heißt aber auch, dass z.B. die Länge der Eingabe nicht als Variable abgespeichert werden kann.
> - Dann kann die Zustandsmenge $Q$ auf $Q'=Q \times K$ erweitert werden.
> - Ein Zustand aus $Q'$ ist also ein Paar $(q,a)$, wobei $q$ den eigentlichen Zustand der TM beschreibt und $a$ den Wert der Variablen. Die Zustandsüberführungsfunktion kann diesen Wert berücksichtigen und ggf. ändern.
> - Da $K$ endlich ist, kann $Q'$ wieder in eine übliche Zustandsmenge überführt werden.

> [!info]- **Mehrspur-Turingmaschine**
> - In jeder Zelle können mehrere (endlich viele) Zeichen aus $\Gamma$ stehen.
> - Die Zeichen können alle gleichzeitig eingelesen und geschrieben werden.
> - Formal kann man das erweiterte Bandalphabet als $\Gamma'=\Sigma\cup\Gamma^{k}$ definieren, wobei $k$ eine Konstante ist.
> - Nun hat man den Vorteil, dass man mehrere Zeichenfolgen untereinander Schreiben kann, und dann z.B. bitweise Operationen sehr effizient durchführen kann.
> - Am Ende muss man seine mehrspurigen Zellen wieder in das einspurige Ausgabealphabet $\Sigma$ übersetzen.

> [!info]- **Variablen mit beliebiger Länge**
> - Wenn man eine Spur für eine bestimmte Variable (oder einen bestimmten Variablentyp) reserviert, kann man Variablen mit beliebiger Länge umsetzen.
> - Dabei kommt eine Variable zeichenweise in eine Spur. 
> - Mehrere Variablen können durch Trennzeichen auf einer Spur abgespeichert werden.

> [!info]- **Unterprogramme**
> Auch Unterprogramme sind mit etwas Aufwand (auf umständliche und unelegante Weise) realisierbar:
> - eigene Teilmenge von Zuständen für ein bestimmtes Unterprogramm
> - eigener Speicherbereich, z.B. weit rechts auf dem Band
> - Aufrufstack muss verwaltet werden

> [!info]- **For- und While-Schleifen**
Schleifen können auf verschiedene Arten realisiert werden, z.B. auch als spezielle Art von Unterprogramm.

### Mehrband-Turingmaschine
Wir erweitern das Modell der Turingmaschine, sodass es mehrere Bänder mit jeweils einem Kopf gibt. Formal ist eine solche $k$-Band-Turingmaschine identisch zu der gewöhnlichen TM, mit Ausnahme der Zustandsübergangsfunktion:
$$\delta: (Q\setminus \set{\bar{q}})\times\Gamma^{k}\to Q\times\Gamma^{k}\times \set{L,N,R}^{k}$$
Die $k$-Band-TM hat also weiterhin nur einen Zustand, aber jeder Kopf kann sich unabhängig von den anderen bewegen und Zeichen lesen und schreiben.

# Nichtdeterministische Turingmaschine

## Definition
Eine *Nichtdeterministische Turingmaschine* (NTM) ist zunächst identisch definiert wie eine [[Turingmaschine#^a9ba8f|deterministische Turingmaschine]], mit dem einen Unterschied, dass die Zustandsüberführungs*funktion* ersetzt wird durch eine Zustandsüberführungs*relation*: $$\delta\subseteq((Q \setminus \set{\bar{q}})\times \Gamma) \times (Q \times \Gamma \times \set{L,N,R}).$$
Ein Tupel aus aktuellem Zustand und gelesenem Zeichen $(q \in Q \setminus \set{\bar{q}}, a \in \Gamma)$ steht also in Relation zu beliebig vielen Tripel aus Folgezustand, geschriebenem Zeichen und Kopfbewegung.

> Nichtdeterministische Turingmaschinen sind kein Modell für physikalisch realisierbare Rechnermodelle. Vielmehr dienen sie als theoretisches Hilfsmittel, insbesondere um die [[Komplexitätstheorie#NP|Komplexitätsklasse NP]] formal zu definieren.

## Verhalten
Ähnlich wie ein [[Endliche Automaten#Endliche Nichtdeterministische Automaten|NFA]] wählt eine NTM stets zufällig einen durch die Zustandsüberführungsrelation definierten Übergang. Wird der Endzustand erreicht oder ist kein passender Übergang in $\delta$ definiert, so hält die NTM.

Die Kombination aus aktuellem Zustand, Bandinhalt und Kopfposition heißt *Konfiguration* einer Turingmaschine. Die Konfigurationen, welche bei einer gegebenen NTM aufeinander folgen können, können in einem Rechenbaum dargestellt werden:
![[Rechenbaum_NTM.png|600]]

Hierbei ist der Wurzelknoten die Startkombination, eine Kante ein erlaubter Übergang, und ein Blatt eine Konfiguration ohne erlaubten Übergang in $\delta$. Ein Rechenweg ist der Pfad von der Wurzel zu einem Blatt.

> Eine NTM $M$ **akzeptiert** eine Eingabe $w \in \Sigma ^{\ast}$, wenn es einen Rechenweg von $M$ gibt, der bei der Eingabe $w$ zu einer akzeptierenden Endkonfiguration führt.
> 
> Sei $L(M)\in \Sigma ^{\ast}$ die Menge der von $M$ akzeptierten Eingaben.
> $M$ **entscheidet** die Sprache $L(M)$, wenn sie für *jede* Eingabe auf *jedem* Rechenweg hält.


## Laufzeit
Die Laufzeit $t_M(w)$ einer nichtdeterministischen TM $M$ auf einer Eingabe $w \in \Sigma ^{\ast}$ ist definiert als die **Länge des längsten Rechenweges** von $M$ bei Eingabe $w$.
Für Eingaben der Länge $n$ ist $t_M(n)=\max_{w\in\Sigma^{n}}t_M(w)$ die Worst-Case-Laufzeit.
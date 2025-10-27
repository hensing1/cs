Datum: 29.04.
[[AI07_SS24_PredLogic_240429_240426.pdf|Folien]]

# Prädikatenlogik

Letzte VL: Aussagenlogik, mit der man die Welt mit atomaren Aussagen modelliert, denen man Wahrheitswerte zuweist. 
Mit der Aussagenlogik kann man jedoch keine Attribute von Objekten, oder Zusammenhänge zwischen Objekten beschreiben. Das limitiert die Art der Schlüsse, die man mit der AL machen kann.

Wir erweitern also auf eine "objektorientierte" Sprache der Logik, die Prädikatenlogik.

> [!abstract] Definition *Prädikatenlogik 1. Stufe*
> Die Prädikatenlogik erster Stufe (PL1) hat folgende **Symbole**:
> - die logische Operatoren $\lnot,\,\land,\,\lor,\,\Rightarrow,\,\iff$
> - Variablen
> - Klammern
> - Funktionen
> - Prädikate
> - Quantoren: $\forall, \exists$
> 
> Ein **Term** ist eine *Variable* oder eine mit Termen belegte *Funktion*. Ein Term repräsentiert ein Objekt.
> 
> Eine **atomare Formel** ist ein mit Termen belegtes *Prädikat*. Eine Formel repräsentiert eine Aussage über ein Objekt.
> Für zwei Terme $t_1,t_2$ ist $t_1=t_2$ ebenfalls eine atomare Formel.

^27b8d9

Unter einer semantischen Interprätation (s.u.):
- ist eine Variable ein Objekt
- nimmt eine Funktion $n$ Objekte entgegen und gibt ein Objekt zurück
	- z.B. `vater-von(x)`
- nimmt ein Prädikat $n$ Objekte entgegen und gibt einen Wahrheitswert zurück
	- z.B. `ist-blond(x)`

$\to n \in \mathbb{N}$ heißt dann **Stelligkeit** der Funktion bzw. des Prädikats.

- Eine 0-stellige Funktion ist eine **Konstante**.
- Ein 0-stelliges Prädikat ist ein **Aussagenlogisches Atom**.

Prädikate sind großgeschrieben, Funktionen sind kleingeschrieben.

## Interpretation und Variablenbelegung

Man nehme eine Menge von Objekten $D$ (genannt Domänenmenge) und eine Interpretationsfunktion $\cdot ^{I,\alpha}$, welche:
- jedem $n$-stelligen Funktionssymbol eine Funktion $f^{I}:D^{n}\to D$ zuweist
- jeder Konstante $a$ ein Objekt aus $D$ zuweist: $a^{I}\in D$
- jedem $n$-stelligen Prädikatensymbol $P$ eine Objekt(-tupel)menge $P^{I} \subseteq D^{n}$ zu, für welche dieses Prädikat wahr ist

Die Funktion $\alpha$ weist jeder Variable $v \in V$ ein Objekt zu: $\alpha : V \to D$

Interpretation atomarer Formeln: $I, \alpha \models P(t_{1},\ldots,t_{n}) \iff (t_{1}^{I},\ldots,t_{n}^{I}) \in P^{I}$.

Die Begriffe *Modell*, *Äquivalenz*, *Erfüllbarkeit* etc. sind durch Interpretationen analog zur Aussagenlogik definiert.

## Freie und gebundene Variablen

Wenn ein Quantor Bezug auf eine Variable $x$ nimmt, dann heißt $x$ im Wirkungsbereich dieses Quantors *gebunden*:
- $\forall x ( \ldots )$ $\leftarrow x$ ist innerhalb der Klammer durch $\forall$ gebunden
- $\exists y(\ldots)$ $\leftarrow y$ ist innerhalb der Klammer durch $\exists$ gebunden

Eine nicht gebundene Variable heißt *frei*.

Eine Formel, deren Variablen alle gebunden sind, heißt *geschlossene Formel*.

> Sind alle Variablen einer Formel gebunden, dann sind die Begriffe Äquivalenz, Erfüllbarkeit etc. unabhängig von der Variablenbelegung.

## Normalformen

### Pränex-Normalform

Eine Formel ist in der Pränex-NF, wenn am Anfang alle Quantoren stehen und dahinter der gesamte (quantorenfreie) Rest.

Umformung:
- Eliminiere $\Rightarrow$ und $\iff$ (analog zur AL)
- Schiebe $\lnot$ nach innen
- Schiebe $\forall$ und $\exists$ nach außen

Dieselbe Variable darf nicht an zwei verschiedene Quantoren gebunden sein.
Ggf. müssen wir also bei der Umformung Variablen umbenennen. Eine Formel $\varphi$, in der wir jeden Term $x$ durch den Term $t$ ersetzen, schreiben wir $\varphi[x/t]$.

### Skolem-Normalform

In der Skolem-NF gibt es keine Quantoren mehr:
- Existenzquantoren werden durch Funktionen ersetzt, die ein Element zurückgeben, für das die Existenzaussage gilt
- Alle verbleibenden Variablen werden als allquantiziert angenommen

Eine Formel in Pränex-NF kann durch die Quantorentfernung (Skolemisierung) in Skolem-NF gebracht werden.

> *Die Skolemisierung erhält nur die Erfüllbarkeit. Sie ist keine Äquivalenzumformung.*

Insbesondere ist sie nicht Modellerhaltend: eine Interpretation, welche die ursprüngliche Formel erfüllt, erfüllt nicht notwendigerweise aud die skolemisierte Formel.

## Inferenz

Aus der Aussagenlogik haben wir zwei Inferenzregeln:
- *Modus Ponens:* gelten die Aussage $\varphi$ und die Regel $\varphi \Rightarrow \psi$, dann gilt auch $\psi$.
- *Resolution:* siehe letzte VL

Die können wir auch in der Prädikatenlogik anwenden, wenn die Aussagen dieselbe Variablenbelegung haben.

Die Belegung einer Variable $v$ mit einem Term $t$ bezeichnen wir mit $\set{v/t}$. Eine Menge aus Variablenbelegungen (genannt Substitutionskomponenten) wird mit $\theta$ bezeichnet. 

Mit $\theta=\text{Unify}(p,q)$ versuchen wir, durch Substitutionen einen Ausdruck $p$ in einen Ausdruck $q$ umzuwandeln. Dabei sollten die Variablennamen in unterschiedlichen Ausdrücken auch unterschiedlich sein, damit man pro Ausdruck geeignete Substitutionen vornehmen kann.
Gelingt das, schreibt man $p \theta = q \theta$.

### Generalisierter Modus Ponens (GMP)

Voraussetzung: $p_{1}',\ldots,p_{n}'$ und $p_{1}\land \ldots \land p_{n} \Rightarrow q$ sind erfüllt, und $p_{i}'\theta = p_{i}\theta \, \forall i$
Folgerung: $q \theta$.

Der GMP ist bei definiten Klauselmengen - d.h., Mengen von Klauseln, die jeweils genau ein positives Literal haben und sich damit als Implikation schreiben können[^1] - vollständig, korrekt und effizient.

[^1]: $(\lnot p_{1} \lor \lnot p_{2} \lor \ldots \lor \lnot p_{n-1} \lor p_{n}) = (p_{1} \land p_{2} \land \ldots \land p_{n-1} \Rightarrow p_{n})$

Da man dieselbe Klausel nicht mit verschiedenen Variablen belegen kann, sie aber ggf. für mehrere Inferenzen braucht, muss man in diesen Fällen Kopien der Klauseln machen.
# Mathematik
## Größter gemeinsamer Teiler
> [!abstract] *Formale Definition*
> Für zwei ganze Zahlen $x,y \in \mathbb{Z}$ heißt $d \in \mathbb{N}$ **größter gemeinsamer Teiler $\text{ggT}(x,y)$**, wenn die folgenden beiden Bedingungen erfüllt sind:
> 1. Die Zahl $d$ ist ein gemeinsamer Teiler von $x$ und $y$, d.h. $d \mid x$ und $d \mid y$.
> 2. Jeder gemeinsame Teiler $d'$ von $x$ und $y$ ist auch ein Teiler von $d$, also $$\forall d' \in \mathbb{Z} : ((d' \mid x) \land (d' \mid y)) \Rightarrow d' \mid d.$$

## Horner-Schema
Alternative Darstellungsweise eines Polynoms beliebigen Grades:
$$ax^4+bx^3+cx^2+dx+e=(((ax+b)x+c)x+d)x+e$$

## Kongruenz
$x \equiv a \!\!\mod n$ schreibt man auch $x \equiv_{n} a$ und bedeutet, dass $x$ und $a$ bei Division durch $n$ denselben Rest lassen, bzw. wenn $n$ ein Teiler der Differenz $x-a$ ist.
Man sagt dann: *"$x$ ist **kongruent** zu $a$"*.

## Metrik
> [!abstract] Definition *Metrik*
> Sei $X$ eine *Menge* und $d: X \times X \to \mathbb{R}_{\geq 0}$ eine *Funktion*.
> $d$ heißt **Metrik** auf $X$, wenn die folgenden drei Eigenschaften für alle $x,y,z \in X$ erfüllt sind:
> - $d(x,y)=0 \iff x=y$ (positive Definitheit)
> - $d(x,y)=d(y,x)$ (Symmetrie)
> - $d(x,z) \leq d(x,y) + d(y,z)$ (Dreiecksungleichung)
> 
> Das Paar $(X,d)$ heißt *metrischer Raum*.

^dbdb6e

## Norm
![[Numerik - VL 1#^5ed8e6]]

## PQ-Formel
$$x^{2}+px+q=0$$
$$\Rightarrow x_{1,2}=-\frac{p}{2}\pm\sqrt{\frac{p^{2}}{4}-q}$$

Oder allgemein:
$$\begin{gather}ax^2+bx+c=0\\
\Rightarrow x_{1,2}=\frac{-b \pm \sqrt{b^2-4ac}}{2a}\end{gather}$$

## Simplex
Ein $n$-dimensionales geometrisches Objekt (Polytop) mit $n+1$ Ecken.
Jede Facette eines Simplex ist ebenfalls ein Simplex.

## Standardabweichung

![[DLVC - VL 2#^799858]]

## Tensor

Ein Tensor ist eine multilineare Abbildung, d.h. eine Abbildung, die in jeder Variablen [[Lineare Funktionen|linear]] ist.

# Allgemeines
## Analog & Diskret
**Analog**: Begriff für kontinuierliche Größen - Gegensatz ist **Diskret**, d.h. stufenweise

## Big-Endian
Vgl. [[Glossar#Little-Endian, Big-Endian]]

## Bits, Bytes, Worte
- Bit: Darstellung von zwei sich ausschließenden Zuständen
- Bitfolge: Folge von $n$ Bits und demnach $2^n$ verschiedenen Zuständen
	- Um eine Zahl $x$ in Basis 2 darzustellen, benötigt man $\lfloor\log_2(x)\rfloor+1$ viele Bits
- Hexziffer: Ziffer in Basis 16
	- 4 Binärziffern lassen sich direkt umrechnen in eine Hexziffer
	- 3 Binärziffern -> eine Ziffer in Basis 8 (Oktaldarstellung)
- Oktett: Tupel von 8 Bit
- Byte: ursprünglich Bite, heutzutage synonym mit Oktett, auch wenn es mal Systeme mit 5-, 7-, und 9-Bit-Bytes gab
- Wort: Gruppe von Bytes
	- Auf 16-Bit-Rechnern ist ein Wort 2 Bytes, auf 32-Bit-Rechnern 4 Bytes
	- Entsprechend gibt es jeweils auch Halbwort, Doppelwort und Quadwort

## Lemma
Ein mathematischer Hilfssatz, z.B. um ein Theorem zu beweisen.

## Lexikografische und kanonische Ordnung
Für zwei Wörter $x,y$ derselben Länge heißt *$x$ lexikografisch kleiner als $y$*, wenn für die ersten Buchstaben $x_i$ und $y_i$, an dem sich $x$ und $y$ unterscheiden, gilt, dass $x_i$ vor $y_i$ kommt (vorausgesetzt, man hat für die Buchstaben eine Ordnung definiert).

Für eine Menge $\Sigma ^{*}$ aller Wörter über einem Alphabet $\Sigma$ kann die *kanonische Ordnung* definiert werden. In der kanonischen Ordnung werden alle Worte aus $\Sigma ^{*}$ zuerst nach der Länge und dann lexikografisch sortiert. 

Für $\Sigma=\set{0,1}$: $\epsilon,0,1,00,01,10,11,000,001,010,011,\ldots$

## Little-Endian, Big-Endian
Wenn man Datentypen hat, welche über die Länge eines Bytes hinausgehen, hat man zwei Möglichkeiten es abzuspeichern:
- Little-Endian := ich speichere das niederwertigste Byte zuerst (innerhalb des Bytes ist weiterhin das niederwertigste Bit am Ende)
	- Ist für manche Prozessorarchitekturen praktischer, da z.B. Addition mit den niederwertigsten Bytes anfängt
	- Wird bis heute in Intel-Prozessoren verwendet
- Big-Endian := ich speichere das höchstwertige Byte zuerst
	- sieht insgesamt natürlicher aus, da alle Bits insgesamt in der richtigen Reihenfolge

Wieso ist das wichtig?
-> Wenn mehrere Prozesse / Computer miteinander reden, muss sich auf irgendwas geeinigt werden.

## Moore's Law
Beobachtung von Gordon Moore aus 1965: alle 12 bis 24 Monate verdoppelt sich die Anzahl der Transistoren pro integrierter Schaltung.
Dieser Trend lässt sich bis heute beobachten.

## Ordnungstyp
Für ein sortierbares Feld $a$ ist der Ordnungstyp $(l_{1},\ldots,l_{n})$ die Reihenfolge, in der ich die Felder von $a$ hinschreiben muss, sodass $a$ sortiert ist; also dass gilt: $a[l_1]<\ldots<a[l_n]$.

## Planarer Graph
Eine Sammlung von Knoten in einer Ebene, die evtl. mit Kanten verbunden sind. Die Kanten dürfen sich hierbei nicht Schneiden.
### Fläche
Zwei Punkte auf einer Ebene mit einem planaren Graphen gehören dann zur selben Fläche, wenn man zwischen ihnen hin- und herlaufen kann, ohne dabei eine Kante zu überqueren.
### Komponente
Zwei Knoten eines planaren Graphen gehören dann zur selben Komponente, wenn sie irgendwie (auch über andere Knoten) durch Kanten miteinander verbunden sind.

## Rechnerklassifikation nach Flynn
Man kann Rechner danach unterteilen, ob man einen oder mehrere Datenströme gleichzeitig verarbeitet, und ob man einen oder mehrere Befehle gleichzeitig verarbeitet.

- SISD - Single Instruction stream, Single Data stream
	- Normaler Einzelprozessor, der einzeln nacheinander die auszuführenden Befehle abarbeitet
- SIMD
	- Dieselbe Instruktion steuert mehrere Rechenwerke
	- Jedes Rechenwerk hat seinen eigenen Datenstrom
	- Beispiele: Vektorcomputer, GPUs
- MISD
	- kann man drüber streiten, ob es das überhaupt gibt
	- Zum beispiel könnte man fehlertolerante Systeme dort einordnen, wie z.B. Satelliten
	- Ein Chip davon kostet gerne mal 400.000€, obwohl sie nicht so leistungsfähig sind
- MIMD
	- jeder Prozessor hat sein eigenes Programm und seine eigenen Daten
	- z.B. Mehrkern-Prozessoren

---
# Funktionen
## Logarithmen
![[Logarithmen#Definition]]
## Allgemeine Begriffe
### Asymptotisch Positiv
Eine Funktion ist asymptotisch positiv, wenn sie ab irgendeinem Punkt $n_0$ immer positiv ist
($\forall n > n_{0} : f(n)>0$)

---
# Informatik
## Technische Informatik
- Befasst sich mit der Bereitstellung der Hardware
- Fließende Grenze zur Elektrotechnik
- Anpassung der Hardware an die jeweiligen Probleme (Massenverarbeitung, Mikrochips etc.)
## Praktische Informatik
- Bereitstellung der Software auf der untersten Ebene
- "Brücke" zwischen primitiven Operationen der Hardware & Anwendungsprogrammen
- Beispiele
	- Betriebssysteme
	- Netzwerke
	- Compilerbau
## Theoretische Informatik
- Grundlagen und Machbarkeitsfragen
- Entwicklung von Algorithmen
- Formale Sprache und Automatentheorie
- etc
## Angewandte Informatik
- Entwicklung von Anwendungen (va. für Endanwender)
- Eng verwandt mit praktischer Informatik

---
# Mengen
## Endliche Menge
Menge mit endlicher Anzahl von Elementen


---
# Programme & Prozesse
## Computerprogramm
Folge von Anweisungen in der Sprache des Computermodells

## Prozess
Ein Programm, das gerade ausgeführt wird
### Betriebssystemprozess
- Ihm stehen alle priviligierten und unpriviligierten Anweisungen der CPUs zur Verfügung.
### Nutzerprozess
- Ihm stehen alle unpriviligierten Anweisungen zur Verfügung
	- hat also keine besonderen Rechte
- Hat einen eigenen virtuellen Namensraum zur Verfügung
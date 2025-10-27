Kapitel 6: *Algorithmische Geometrie*
[Vorlesungsvideo](https://uni-bonn.sciebo.de/s/2FFBRQ8vW3J88f3) (Passwort: algo1)
[[algo_I_06_1.pdf|Folien]] (Seiten 1 bis 73)

> Wir behandeln Algorithmen, die als Eingabe irgendwelche geometrischen Informationen haben.

Dafür erweitern wir zunächst unser formales Rechnermodell:
jedes Register kann nun eine *reelle Zahl* statt einer natürlichen Zahl speichern.

# Kapitel 6.1: Delauney-Triangulation

## Geometrische Graphen
![[Graphen#Geometrischer Graph]]

### Eulersche Polyederformel

> Sei $G=(V,E)$ ein kreuzungsfreier geometrischer Graph mit $v$ Knoten, $e$ Kanten, $f$ Flächen und $c$ Zusammenhangskomponenten. Dann gilt: $$v+f = e+c+1.$$

Der Beweis funktioniert über *strukturelle Induktion*, das gab es schon in [[LudS - VL 4#Beispiel: Euler'sche Formel über planare Graphen|LudS]].

### Wachstum der Kanten und Flächen
> In einem zusammenhängenden, kreuzungsfreien geometrischen Graphen mit $v$ Knoten $e$ Kanten und $f$ Flächen gilt:$$e \in \mathcal{O}(v) \text{ und } f \in \mathcal{O}(v).$$

Konkret gilt für einen zusammenhängenden Graphen, dass $$3f \leq \sum\limits_{i=1}^{f}d_{i} \leq 2e,$$
wobei $f$ die Anzahl der Flächen, $d_i$ die Anzahl der zu einer Fläche $f_{i}$ inzedenten Kanten, und $e$ die Gesamtanzahl der Kanten ist.
Das liegt daran, dass zu jeder Fläche $f_i$ mindestens drei Kanten adjazent sind ($d_{i}\geq 3$), und dass zu jeder Kante maximal zwei Flächen inzident sind:

![[Geometrischer Graph - Kanten und Flächen.excalidraw|300]]

Umgeformt ergibt sich $f\leq \frac{2}{3}e$. Da $c=1$, ergibt sich gemäß der Eulerformel:$$e=v+f-2 \leq v+ \frac{2}{3}e - 2 \iff \frac{1}{3}e+2 \leq v \Rightarrow e \in \mathcal{O}(v).$$
Da $f \leq \frac{2}{3}e$, folgt: $f \in \mathcal{O}(v)$.

Die Anzahl der Kanten und Flächen wächst also linear mit der Anzahl der Knoten, im gegensatz zu "normalen" gerichteten oder ungerichteten Graphen, bei denen die Anzahl der Kanten quadratisch zur Anzahl der Knoten sein kann.

### Triangulation
> [!abstract] Definition
> Eine **Triangulation** einer Menge von Punkten $S$ ist ein kreuzungsfreier geometrischer Graph $(S,E)$, wobei $E$ eine *inklusions-maximale* Kantenmegne ist. 
> Dies beschreibt einen Graphen, für den keine Kante eingefügt werden kann, ohne dass dabei eine Kreuzung entsteht.[^1]

Damit sind alle Flächen (bis auf die äußere) Dreiecke.
Eine Triangulation ist nicht eindeutig.

Zwei mögliche Triangulationen von sechs festgelegten Punkten:
![[Triangulation.png|450]]

[^1]: Man hat also einen kreuzungsfreien Graphen mit einer maximalen Anzahl von Kanten (glaub ich).

### Allgemeine Lage
> [!abstract] Definition
> Eine endliche Punktemenge $S \subset \mathbb{R}^2$ ist in **allgemeiner Lage**, wenn:
> 1. keine *vier Punkte* aus $S$ auf einem gemeinsamen *Kreis* liegen
> 2. keine *drei Punkte* aus $S$ auf einer gemeinsamen *Geraden* liegen.

### Delauney-Triangulation
> [!abstract] Definition
> Eine *Triangulation* einer Menge von Punkten $S$ in der Ebene ist eine **Delauney-Triangulation**, wenn für jedes *Dreieck* der Triangulation gilt, dass sein *Umkreis* keine Punkte aus $S$ in seinem Inneren enthält.

![[Delauney-Triangulation.png|300]]

Die Delauney-Triangulation ist *eindeutig*.
Außerdem maximiert sie die einzelnen Innenwinkel der Dreiecke, das beweisen wir hier aber nicht (das ist aber sinnvoll für verschiedene Anwendungen).

> [!abstract] Definition
> Eine Kante $(p,q)$ zwischen zwei Punkten der Menge $S$ heißt **Delauney-Kante**, genau dann wenn ein Kreis existiert, sodass $p$ und $q$ auf dessen Rand liegen und sich keine weiteren Punkte in seinem Inneren befinden.

Sind die Punkte aus $S$ in *allgemeiner Lage*, dann können sich keine zwei Delauney-Kanten kreuzen.[^2]

> Eine Delauney-Triangulation erzeugt genau die Delauney-Kanten.

- Jede Kante der Delauney-Triangulation ist eine Delauney-Kante, da jede Kante Teil eines Dreiecks ist, dessen Umkreis keine weiteren Punkte enthält.
- Es gibt keine Delauney-Kante, die nicht Teil der Delauney-Triangulation ist, da man keine Kante zu einer Triangulation hinzufügen kann, ohne dass sie sich mit einer weiteren Kante kreuzt (und Delauney-Kanten können sich nicht kreuzen, s.o.)

[^2]: Sonst läge nämlich mindestens ein Endpunkt von einer Kante innerhalb des Kreises der anderen Kante.

### Flip
> [!abstract] Definition
> Seien $(a,b,c)$ und $(b,c,d)$ benachbarte Dreiecke in einer Triangulation $T$.
> Dadurch wird ein Viereck $(a,b,c,d)$ mit *Diagonale* $(b,c)$ gebildet.
> Ein **Flip** ersetzt in $T$ die Diagonale $(b,c)$ durch $(a,d)$. 
> $(a,d)$ heißt dann *Flip-Diagonale von $(b,c)$ in $T$*.

> Ein Flip heißt *Delauney-Flip*, wenn dadurch eine Delauney-Kante entsteht.

In der obigen Definition wäre $(a,d)$ eine Delauney-Kante, genau dann wenn $a$ im Umkreis von $(b,c,d)$ bzw. $d$ im Umkreis von $(a,b,c)$ enthalten ist.[^3]

[^3]: Das heißt dann nämlich wiederum, dass $b$ und $c$ *nicht* im Umkreis von $(a,c,d)$ bzw. $(a,b,d)$ liegen und es somit einen Kreis mit $a$ und $d$ auf dem Rand gibt, der keine weiteren Punkte in seinem Inneren hat.

## Greedy-Algorithmus von Fortune
Berechnet die Delauney-Triangulation für eine Menge von Punkten.

	def fortune(Triangulation T):
		while (Kante e existiert, die Delauney-Flip erlaubt):
			ersetze e durch Flip-Diagonale in T

### Korrektheitsbeweis
Sei für eine Triangulation $T$ die Funktion $$\Phi(T)=\sum\limits_{(a,b,c)=\text{Dreieck in }T}|\set{p \in S \mid p \in C(a,b,c)}|$$ die *Anzahl der Konflikte* in $T$. 
Hierbei ist $C(a,b,c)$ der Umkreis des Dreiecks $(a,b,c)$. Wenn ein Punkt $p$ also innerhalb dieses Kreises liegt, ist er mit dem Dreieck in Konflikt.

> Im Laufe des Algorithmus von Fortune verringert sich die Anzahl der Konflikte mit jedem Delauney-Flip.

**Erstes Lemma:**
> Für einen Delauney-Flip, der in einem Viereck $(a,b,c,d)$ die Diagonale $(a,c)$ mit $(b,d)$ ersetzt, gilt:
> 1. $C(a,b,d) \cup C(b,c,d) \subseteq C(a,b,c) \cup C(a,c,d)$
> 2. $C(a,b,d) \cap C(b,c,d) \subseteq C(a,b,c) \cap C(a,c,d)$

![[Delauney-Flip_Lemma.png|500]]

**Zweites Lemma:**
> Sei $T'$ die Triangulation nach einem Delauney-Flip in $T$. Es gilt: $\Phi(T') \leq \Phi(T) - 2$.

Es werden nämlich mindestens die beiden Endpunkte der neuen Delauney-Kante von Konflikten befreit (im Beispiel oben $d$ und $b$).
Es kommen auch keine Konflikte dazu:
- Punkte, die mit *einem* der beiden neuen Dreiecke in Konflikt stehen, standen vorher mit *mindestens einem* der alten Dreiecke im Konflikt (dunkelgrauer Bereich links)
- Punkte, die mit *beiden* neuen Dreiecken im Konflikt stehen, waren auch mit *beiden* alten Dreiecken im Konflikt (dunkelgrauer Bereich rechts)
- Alle anderen Konflikte bleiben unberührt.

**Drittes Lemma:**
> Solange $\Phi(T)>0$, gibt es zwei benachbarte Dreiecke in $T$, die einen Delauney-Flip erlauben.

Sei $d$ ein Punkt, der mit einem Dreieck $(a,b,c)$ in Konflikt steht und der den Abstand zwischen Punkt und Dreieck minimiert. Sei er der Kante $(a,c)$ am nächsten.

- Falls es das Dreieck $(d,a,c)$ in $T$ gibt, gibt es einen Delauney-Flip.
- Ansonsten gibt es einen Punkt $e$, sodass $(e,a,c) \in T$
	- wenn $e \in C(a,b,c)$, existiert ein Delauney-Flip $(a,c) \rightarrow (e,b)$
	- wenn $e \not\in C(a,b,c)$, steht $d$ im Konflikt mit $(e,a,c)$

![[Delauney-Flip_Lemma_2.png|200]]

**Viertes Lemma:**
> Für eine Triangulation $T$ von $n$ Punkten terminiert der Greedy-Algorithmus von Fortune nach $\mathcal{O}(n^2)$ Delauney-Flips.

Die Anzahl der Dreiecke in $T$ liegt ja logischerweise in $\mathcal{O}(n)$, und damit kann es höchstens $\mathcal{O}(n^{2})$ Konflikte geben, da jedes Paar von Dreieck und Punkt höchstens einen Konflikt erzeugt.
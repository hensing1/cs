# Flussprobleme
## Begriffsdefinitionen
### Fluss und Flussnetzwerk
Man hat einen gerichteten Graphen $G=(V,E)$ mit einer *Quelle* $s \in V$ und einer *Senke* $t \in V$.
Zudem weist man jedem Knotenpaar $u,v \in V$ eine *Kapazität* $c(u,v)$ zu, mit $c(u,v)=0$ für alle $(u,v) \not\in E$.
Sei zudem jeder Knoten von der Quelle aus erreichbar.
$(G,s,t,c)$ heißt dann **Flussnetzwerk**.

> [!abstract] Definition
> Ein **Fluss** in einem *Flussnetzwerk* ist eine Funktion $f : V \times V \rightarrow \mathbb{R}$, welche die folgenden beiden Bedingungen einhält:
> 1. *Flusserhaltung*: In jeden Knoten (außer Quelle und Senke) darf nur so viel reinfließen, wie auch rausfließt. Formal: $$\forall u \in V \setminus \set{s,t}: \sum\limits_{v\in V} f(v,u) = \sum\limits_{v \in V}f(u,v).$$
> 2. *Kapazitätsbeschränkung*: die Kapazität jedes Knotenpaares darf nicht nicht überschritten werden.$$\forall u,v \in V: 0 \leq f(u,v) \leq c(u,v).$$

Der **Wert** $|f|$ eines Flusses $f$ ist nun die Anzahl an Einheiten, die ein Fluss aus der Quelle in die Senke transportiert: $$|f|=\sum\limits_{v\in V}f(s,v)-\sum\limits_{v\in V}f(v,s) = \sum\limits_{v\in V}f(v,t) - \sum\limits_{v\in V}f(t,v).$$
Anschaulich sähe ein Fluss mit Wert 2 z.B. so aus:
![[flussproblem.png|400]]
Jede Kante $(u,v)$ ist hierbei mit $f(u,v)/c(u,v)$ beschriftet.

### Restfunktion, Restnetzwerk, Flussvergrößernder Weg
Die **Restfunktion** eines Flusses $f$ ist definiert wie folgt:
$$
\text{rest}_f(u,v)=
\left\{
\begin{array}{ll}
c(u,v)-f(u,v) & \text{falls } (u,v) \in E,\\
f(v,u) & \text{falls } (v,u) \in E,\\
0 & \text{sonst.}
\end{array}
\right.
$$
Mit den Knoten $V$ aus dem Flussnetzwerk $G=(V,E)$ sowie dieser Restfunktion kann man nun ein **Restnetzwerk** $G_{f}=(V,E_{f})$ definieren - zwischen zwei Knoten $u,v$ gibt es im Restnetzwerk eine Kante, wenn $\text{rest}_{f}(u,v) > 0$. Formal:$$E_f=\set{(u,v) \in V \times V \mid \text{rest}_{f}(u,v)>0}$$
Dadurch hat man zwischen zwei Knoten $u,v$ im Restnetzwerk eine Hin-Kante, wenn $f(u,v) < c(u,v)$ und eine Rück-Kante, wenn $f(u,v) > 0$:
![[Restnetzwerk.png]]

Ein **flussvergrößernder Weg** ist ein einfacher $s$-$t$-Weg im Restnetzwerk $G_{f}$.

> Ein Fluss $f$ ist genau dann maximal, wenn es im Restnetzwerk $G_f$ keinen flussvergrößernden Weg gibt.

#### Erhöhung des Flusses
Um einen Fluss zu vergrößern, kann man nun folgendermaßen vorgehen:
- Man sucht sich einen $s$-$t$-Weg im Restnetzwerk
- Wenn die entsprechende Kante im Ursprungsgraph in dieselbe Richtung zeigt, addiert man den minimalen Wert aus diesem Weg drauf
- Zeigt sie in die Gegenrichtung, zieht man diesen Wert ab.

Formale Definition:
> Sei $G$ ein Flussnetzwerk, $f$ ein Fluss und $P$ ein einfacher Weg im Restnetzwerk $G_f$ von $s$ nach $t$.
> $f \uparrow P : V \times V \rightarrow \mathbb{R}$ ist **der Fluss, der entsteht, wenn $f$ entlang $P$ erhöht wird.**
> Dieser Fluss ist definiert durch: $$(f\uparrow P)(u,v)=\left\{
\begin{array}{ll}
f(u,v)+\delta & \text{falls } (u,v) \in P \text{ und } (u,v) \in E,\\
f(u,v)-\delta & \text{falls } (v,u) \in P \text{ und } (u,v) \in E,\\
f(u,v) & \text{ sonst,}
\end{array}
\right.$$
> wobei $\delta = \text{min}_{e\in P}(\text{rest}_f(e))$.

Es gilt: $|f \uparrow P| = |f| + \delta$.

Anschauliches Beispiel:
![[Flusserweiternder_Weg.png|300]]

Kanten $e \in P$ mit $\text{rest}_f(e) = \delta$ heißen *Flaschenhalskanten*. Sie sind in $E_{f \uparrow P}$, also den Kanten des Restnetzwerks nach der Erhöhung, nicht mehr vorhanden.

### Schnitt
> [!abstract] Definition
> > Ein **Schnitt** eines *Flussnetzwerks* $G=(V,E)$ ist eine Unterteilung der Knotenmenge $V$ in zwei Teilmengen $S$ und $T$, sodass die Quelle in der einen und die Senke in der anderen Menge ist ($s \in S, t \in T$).
> 
> Die Summe der Kapazität aller Kanten, die direkt von $S$ nach $T$ führen, ist die *Kapazität* des Schnittes $(S,T)$: $c(S,T)=\sum\limits_{u \in S}\sum\limits_{v \in T} c(u,v)$.
> 
> Ein Schnitt $S,T$ heißt *minimal*, wenn es keinen Schnitt $(S',T')$ mit $c(S',T')<c(S,T)$ gibt.
> 
> Für einen Fluss $f$ und einen Schnitt $(S,T)$ sei $f(S,T)=\sum\limits_{u \in S}\sum\limits_{v \in T}f(u,v) - \sum\limits_{u \in S}\sum\limits_{v \in T} f(v,u)$ der *Fluss über den Schnitt*.

#### Wichtige Eigenschaften
1. Für einen *beliebigen* Schnitt $(S,T)$ ist der Fluss über den Schnitt gleich dem Wert des Flusses: $f(S,T) = |f|$.

2. Es gibt einen Schnitt $(S,T)$ mit $c(S,T) = f(S,T) = |f|$ genau dann, wenn der Fluss $f$ *maximal* ist. Die Menge $S$ setzt sich hierbei genau aus den Knoten zusammen, die im Restnetzwerk $G_f$ von $s$ aus erreichbar sind.
   Für diesen Schnitt gilt: für alle Kanten $\overrightarrow{e}$ des Flussnetzwerks von $S$ nach $T$ ist $f(\overrightarrow{e}) = c(\overrightarrow{e})$ und alle Kanten $\overleftarrow{e}$ von $T$ nach $S$ ist $f(\overleftarrow{e})=0$.[^1]

[^1]: Dies folgt aus $c(S,T) = f(S,T) = |f|$. Wäre dies nicht der Fall, gäbe es im Restnetzwerk eine Kante von $S$ nach $T$.
## Problemstellung

**Maximaler Fluss:**
> Gegeben sei ein Flussnetzwerk $G$. Berechne einen *maximalen Fluss* in $G$, d.h. einen Fluss $f$ mit *größtmöglichem Wert $|f|$*.

*Wichtige Eigenschaft eines maximalen Flusses:* sind alle Kapazitäten ganzzahlig, dann ist der maximale Fluss auch ganzzahlig. 

### Anwendungsbeispiel
Mal angenommen man hat mehrere Häfen $A_1,\ldots,A_p$ mit Waren, die an Zielhäfen $B_{1},...,B_q$ verschifft werden sollen.
Seien $r_i$ die verfügbaren Einheiten an $A_i$ und $d_j$ die angeforderten Einheiten an $B_j$. Habe zudem eine Schifffahrtslinie zwischen $A_i$ und $B_j$ die Kapazität $c(A_i,B_j)$.

Kurzum hat man also mehrere Quellen und mehrere Senken. Das kann man trotzdem als Flussproblem modellieren, wie es oben definiert wurde, indem man die Quelle $s$ mit allen $A_i$s verbindet ($c(s,A_i)=r_i$) und alle Zielhäfen mit der Senke $t$ ($c(B_j,t)=d_j$):
![[flussproblem_2.png|400]]

Mit diesem Modell kann man nun folgende Fragen beantworten:
1. Ist es möglich, alle Anforderungen zu erfüllen?
	- Ist für den maximalen Fluss $|f|=\sum\limits_{j=1}^{q}d_j$?
2. Falls nein, wieviele Einheiten können maximal zu den Zielhäfen transportiert werden?
	- $\rightarrow |f|$
3. Wie sollen die Waren verschifft werden?
	- Siehe $f(A_i,B_j)$ im maximalen Fluss $f$

## Lösende Algorithmen
### Algorithmus von Ford und Fulkerson

*Annahme:* Es gibt für kein Paar $u,v \in V$ die Kanten $(u,v)$ und $(v,u)$.
```
def Ford-Fulkerson(G,c,s,t):
	for e in E:
		f[e] = 0
	while (Flussvergrößernder Weg P existiert):
		erhöhe f entlang P
	return f
```

Referenzen: [[Flussprobleme#Fluss und Flussnetzwerk|Fluss]], [[Flussprobleme#Restfunktion, Restnetzwerk, Flussvergrößernder Weg|Flussvergrößernder Weg]]

#### Laufzeit
> Sei $C$ die ganzzahlige[^4] Summe aller Kapazitäten in einem Flussnetzwerk ($C=\sum\limits_{e \in E}c(e)$) und $m=|E|$.
> Dann ist die Laufzeit von `Ford-Fulkerson` nach oben beschränkt durch $\mathcal{O}(mC)$. [^2]

**Begründung:**
$C$ ist obere Schranke für $|f|$, und $|f|$ wird in jeder Iteration der While-Schleife um eins erhöht. Also hat man maximal $C$ while-Durchläufe.
Ein while-Durchlauf dauert $\mathcal{O}(m)$:
- Das Restnetzwerk $G_f$ kann in $\mathcal{O}(m)$ berechnet werden (jede Kante wird genau einmal im Hinblick auf Fluss und Kapazität betrachtet)
- Via [[Graphen#Tiefensuche|Tiefensuche]][^3] kann ein $s$-$t$-Weg $P$ in $G_f$ in $\mathcal{O}(m)$ gefunden werden
- Der Fluss $f \uparrow P$ kann in $\Theta(|P|) \in \mathcal{O}(m)$ berechnet werden

*Problem:* $C$ kann exponenziell groß im Vergleich zur Anzahl der Eingabebits sein, wir haben also im Worst Case auch eine exponenzielle Laufzeit.[^6] Der Algorithmus von Edmonds und Karp ist in dieser Hinsicht besser.

[^4]: Wenn $C$ reelwertig ist, terminiert der Algorithmus unter Umständen gar nicht.
[^2]: Strenger könnte man $C$ auch definieren als die Summe der Kapazität aller ausgehenden Kanten von $s$
[^3]: oder Breitensuche
[^6]: So eine Laufzeit heißt auch *pseudopolynomiell*.

### Algorithmus von Edmonds und Karp

*Annahme:* Es gibt für kein Paar $u,v \in V$ die Kanten $(u,v)$ und $(v,u)$.
```
def Edmonds-Karp(G,c,s,t):
	for e in E:
		f[e] = 0
	while (Flussvergrößernder Weg P existiert):
		Wähle P als flussvergrößernden Weg mit so wenig Kanten wie möglich
		erhöhe f entlang P
	return f
```

Bis auf die Wahl von P ist `Edmonds-Karp` identisch zu `Ford-Fulkerson`. Diese Änderung bewirkt jedoch eine polynomielle Laufzeit anstatt einer exponenziellen.

Darüber hinaus terminiert `Edmonds-Karp` auch mit reelwertigen Kapazitäten.

#### Laufzeit
> Die Laufzeit von `Edmonds-Karp` beträgt auch für reelwertige Kapazitäten $\mathcal{O}(m^2n)=\mathcal{O}(n^5)$.[^5]

**Begründung:**
- Ein Schleifendurchlauf benötigt (mit Breitensuche) immer noch $\mathcal{O}(m)$.
- Es gibt höchstens $n \cdot m$ Schleifendurchläufe:
	- Im Verlaufe des Algorithmus kann im Restnetzwerk die Distanz von $s$ zu einem anderen Knoten *nie* verkürzt werden, da immer nur Rück-Kanten eingefügt werden.
	- In jedem Durchlauf werden alle Flaschenhalskanten aus dem Restnetzwerk entfernt (davon gibt es mindestens eine).
	- Wird eine Kante $(u,v)$ irgendwann wieder eingefügt, kann dies nur passieren, wenn man den Fluss entlang der vorher entstandenen Rück-Kante $(v,u)$ erhöht - da die Distanz zu $u$ in der Zwischenzeit nicht verringert worden sein kann, ist sie nun mindestens 2 länger als ursprünglich.
	- Da die Distanz zu einem beliebigen Knoten höchstens $n-1$ ist (alle kürzesten Wege sind einfach), kann jede Kante höchstens $n/2$-mal entfernt werden.
	- In jeder Iteration wird mindestens eine Kante entfernt und es gibt $2m$ potenzielle Kanten im Restnetzwerk. Damit ist die Anzahl der while-Durchläufe nach oben beschränkt durch $\frac{n}{2} \cdot 2m = nm$.

[^5]: $m=|E|$ und $n=|V|$. Da zwischen zwei Knoten keine zwei Kanten in die selbe Richtung gehen können, gilt $m \leq n^2$.
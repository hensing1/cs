Datum: 13.05.
[[cgintro-08-Parametrische Flaechen.pdf|Folien]]
[[cgintro-09-SubdivisionSurfaces.pdf|Folien 2]]

# Parametrische Fläche

> [!abstract] Definition *Parametrische Fläche*
> Eine parametrische Fläche ist eine glatte (dh. bel. oft differenzierbare) Abbildung $$q: \mathbb{R}^{2}\supset D \to \mathbb{R}^{n}$$ ($D$ ist zweidimensionales Intervall).

Hält man einen Parameter fest, hat man eine [[CG - VL 7#Parametrische Kurven|parametrische Kurve]]: $p(u) := q(u, v_{0})$ für konstantes $v_0$ ist eine parametrische Kurve.

*Differenzierbarkeit:* pro Parameter erhält man eine Tangente.
$q_{u}(u,v) := \frac{\partial q(u,v)}{\partial u}$ heißt $u$-Tangente, $q_{v} := \frac{\partial q(u,v)}{\partial v}$ heißt $v$-Tangente der Stelle $(u,v)$.

> Eine Fläche heißt *regulär*, wenn beide Tangenten immer existieren und linear unabhängig sind.

Z.B. Kugel ist am Nord- und Südpol nicht regulär, da der Vektor für den Breitengrad Null wird.

> Der *Normalen(einheits)vektor* $n(u,v) := \frac{q_{u}(u,v)\times q_{v}(u,v)}{\|q_{u}(u,v)\times q_{v}(u,v)\|_{2}}$ definiert die *Tangentialebene* am Punkt $q(u,v)$.

Die Basisfunktionen im 2D (wie [[CG - VL 7#Bernsteinpolynome und Bézierkurven|Bernsteinpolynome für Beziérkurven]]) lassen sich auf 3D erweitern:

> [!abstract] Definition *Tensorproduktraum*
> Sind $\set{F_{i}^{m},i=0,\ldots,m}$ und $\set{G_{j}^{m},j=0,\ldots,n}$ Basen zweier Funktionsräume $R_1$ und $R_2$ mit reellwertigen univariaten Funktionen über den Intervallen $I$ bzw. $J$, bilden die bivariaten Funktionen $$F_{i}^{m}G_{j}^{n}(u,v) := F_{i}^{m}(u) \cdot G_{j}^{n}(v)\quad (u,v) \in I \times J$$eine *Basis* des *Tensorproduktraums* $R_{1}\otimes R_2$ der Dimension $(m+1)(n+1)$.

![[Tensorproduktflächen.png]]

Addiert man diese Basisfunktionen für Koordinaten $c_{ij}\in \mathbb{R}^3$ auf, erhält man eine *Tensorproduktfläche*:$$q(u,v)=\sum_{i=0}^{m}\sum_{j=0}^{n}c_{ij}\cdot F_{i}^{m}(u)\cdot G_{j}^{n}(v).$$
Sind $F$ und $G$ Bernsteinpolynome, dann sind $c_{ij}$ die Beziérpunkte, die das Kontrollnetz aufspannen. Die Tensorproduktfläche liegt dann in der konvexen Hülle des Kontrollnetzes.

Entlang einer Dimension der Fläche erhält man dann wieder eine Beziérkurve.
Man kann zur Darstellung wieder den Algorithmus von [[CG - VL 7#Algorithmus von de Casteljau|de Casteljau]] doppelt anwenden: man berechnet für einen Punkt $(u_0,v_0)$ zuerst die Kurven entlang einer Dimension (für alle $i \in \set{0,\ldots,m}$ am Punkt $u_0$), und diese errechneten Punkte ergeben die Kontrollpunkte für die zweite Dimension.

Da man für jeden Kontrollpunkt genau eine Basisfunktion hat, kann man die Punkte  mit $w_{ij}\in \mathbb{R}$ gewichten und erhält eine *rationale Beziérfläche*: $$R(u,v)=\frac{\sum_{i=0}^{m}\sum_{j=0}^{n}\tilde b_{ij}\cdot B_{i}^{m}(u) \cdot B_{j}^{n}(v)}{\sum_{i=0}^{m}\sum_{j=0}^{n}w_{ij}\cdot B_{i}^{m}(u) \cdot B_{j}^{n}(v)}$$
Dabei müssen $w_{ij}>0$ und $w_{n0}=w_{0m}=1$ erfüllt sein.

## 3D-Splines

Flächen können genauso wie Kurven aneinander angeschlossen werden. 
Dafür kann man z.B. [[CG VL 8 - Splines#B-Spline|B-Splines]] verwenden: Nimm normalisierte B-Splines und spanne damit eine Tensorproduktbasis auf. Nun kann man diese mit Kontrollpunkten multiplizieren und erhält eine Fläche.

## Getrimmte Tensorproduktflächen

Wir möchten nicht nur ein Rechteck als Rand haben, sondern eine Randkurve.

- Randkurven sind geschlossen
- schneiden sich nicht
- Kindkuven verlaufen entgegengesetzt zu ihren Eltern

Die Kurven verlaufen in der $u$-$v$-Ebene

# Subdivision Surfaces

Wir haben eine Oberfläche aus ein paar wenigen Dreiecken und wollen daraus eine glatte Oberfläche machen.

In 2d:
- mache Kurve als Interpolation aus Punkten
- schneide Ecken ab
- wiederhole unendlich oft
- am Ende kommt quadratisches B-Spline raus (C1-stetig)

oder:
- Füge neue Punkte in Geradenmitte ein
- jeder Punkt wandert zu je 1/4 zu seinen Nachbarn (Binomialkoeffizient)
- wiederhole
- kubisches B-Spline fällt raus (C2-stetig überall)


## Loop Subdivision

Nach Charles Loop. Ansatz für Dreiecks-Mesh-Oberflächen.

- Für jedes Dreieck:
	- teile es in vier Dreiecke, indem in jedem Kantenmittelpunkt ein Vertex eingefügt wird
- Für jeden Punkt:
	- Punkt hat sechs Nachbarn:
		- $\text{Neue Position} = \frac{1}{4} \cdot \text{alte Position} + \sum_\text{Nachbarn} \frac{1}{8} \cdot \text{Nachbarsposition}$
	- Punkt hat $n \neq 6$ Nachbarn (außerordentlicher Vertex):
		- $a = \frac{(3+2 \cos (2 \pi /n))^{2}}{32}- \frac{1}{4}$
		- $b=\frac{1-a}{n}$
		- Gewichtungen: $a$ für Ursprungsvertex, $b$ für Nachbarsverteces.

Das resultiert in $C^2$-Stetigkeit überall, außer bei außerordentlichen Verteces ($C^{1}$).
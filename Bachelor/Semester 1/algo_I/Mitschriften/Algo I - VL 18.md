Datum: 19.01.
[Vorlesungsvideo](https://uni-bonn.sciebo.de/s/RsTEGA6lR4MmfWj)
[[algo_I_06_2.pdf|Folien]]

# Datenstrukturen für Punktlokalisierung
## Triangulationshierarchie
### Prinzip
> Gegeben eine Triangulation $T$, ist eine **Triangulationshierarchie** ist eine *Sequenz von Triangulationen* $T_0,\ldots,T_h$, in der die *Anzahl der Dreiecke*, ausgehend von $T_0=T$, in jedem Schritt reduziert wird.

$T_h$ ist dann schließlich die äußere Fläche.

Hieraus erstellt man die folgende Suchstruktur:
Man hat einen Baum $G$, welcher pro Triangulation $T_i$ in der Triangulationshierarchie eine Ebene hat. Ein Knoten stellt eine Fläche in einer Triangulation dar. Man fängt mit $T_h$ an, das heißt die Wurzel von $G$ repräsentiert die äußere Fläche.
Zwei Knoten $a,b$ mit $a \in T_i$ und $b \in T_{i+1}$ sind in $G$ mit einer Kante verbunden, wenn sich die Flächen von $a$ und $b$ überlappen.

Sei also die folgende Triangulationshierarchie gegeben:
![[Triangulationshierarchie.png]]

Dann wird daraus der folgende Graph erstellt:
![[Triangulationshierarchie_2.png|550]]

### Abfrage
Nun kann man eine Abfrage für eine Punktlokalisierung folgendermaßen realisieren:
- Starte im Wurzelknoten
- Solange nicht in der untersten Ebene angekommen:
	- Prüfe alle Kindsknoten darauf, ob ihr jeweiliges Dreieck den gesuchten Punkt enthält
	- Sobald ein solcher Knoten gefunden wurde, wechsle zu ihm

### Laufzeit
Für eine Triangulationshierarchie mit Graph $G$, welcher Höhe $h$ und einen maximalen Outgrad $d$ besitzt, liegt die Laufzeit in $\mathcal{O}(dh)$.

### Berechnung
Um die Laufzeit gering zu halten, möchten wir eine Triangulationshierarchie berechnen, die einerseits eine möchlichst geringe Anzahl an Triangulationen besitzt (um den resultierenden Baum niedrig zu halten), und andererseits pro Knoten einen möglichst geringen Outgrad hat, damit während der Suche so wenig Flächen wie möglich überprüft werden müssen.

Hierzu möchten wir in jeder Triangulation $T_i$ für $T_{i+1}$ eine größtmögliche *[[Graphen#^ce5eb6|unabhängige Knotenmenge]]* entfernen.
Auf diese Weise bleiben nämlich die Kanten zwischen diesen Knoten erhalten. Dadurch wird letztendlich der Outgrad einzelner Knoten limitiert, denn die Zahl der Flächen, mit der sich ein resultierendes Dreieck überlappt, ist höchstens der Knotengrad des entfernten Knoten.

#### Entfernung eines Knoten
Ein Knoten kann nur dann entfernt werden, wenn er einen Knotengrad von 3 hat - ansonsten wäre die zurückgelassene Fläche kein Dreieck, und der resultierende Graph keine Triangulation.

Also werden, bis ein Knotengrad von 3 erreicht wurde, Kanten vom Knoten entfernt, indem Flips durchgeführt werden.[^1]

[^1]: Dass es immer zulässige Flips gibt, ist geometrisch garantiert durch die Summe der Innenwinkel.

Die neue Triangulation besteht also aus den neuen Dreiecken, die durch die durchgeführten Flips entstehen, minus die entfernten Knoten:
![[Iteration Kirkpatrick.png|300]]

#### Berechnung der unabhängigen Knotenmenge
Mithilfe der eulerschen Formel kann man zeigen, dass es in einer Triangulation von $n$ Knoten es mindestens $\lceil \frac{n}{2} \rceil$ Knoten gibt, die einen Knotengrad von höchstens 11 haben.[^2]

[^2]: Konkret haben mindestens $\lceil \frac{k-5}{k+1} n \rceil$ Knoten einen Knotengrad von höchstens $k$.

Diese Knoten wählen wir als potenziell zu entfernende Knoten aus, da wir so den Knotengrad auf eine Konstante beschränken können und außerdem genug Knoten zur Auswahl haben, um die Anzahl der Dreiecke pro Iteration sinnvoll einzuschränken. 

Konkret wird die unabhängige Knotenmenge wie folgt generiert:

```
def Independent_Set(Triangulation T):
	W := Teilmenge der Konten aus T mit Knotengrad <= 11
	U = {}
	while |W| > 4:
		v := innerer Knoten aus W
		U += v
		W -= v sowie alle benachbarten Konten von v
	return U
```

Wir sagen `while |W| > 4`, da wir davon ausgehen, dass die äußere Fläche ein Rechteck ist (wir also 4 äußere Knoten haben) und wir keine äußeren Knoten auswählen wollen, da wir sonst das Rechteck kaputt machen.

Dadurch, dass wir pro Schritt höchstens 12 Konten aus `W` entfernen, und `|W|` am Anfang mindestens $n/2$ ist, kann man ausrechnen, dass für $n \geq 251$ mindestens $\frac{1}{25}$ aller Konten in `T` am Ende in `U` enthalten sind, also entfernt werden.[^3]

[^3]: $5 > \frac{n}{2} - 12m \iff m > \frac{n}{24} - \frac{5}{12}$. Für $n\geq 251$ gilt $\frac{n}{24}-\frac{5}{12}> \frac{n}{25}$.

#### Genaue Laufzeit
Wir wissen, dass, solange $n \geq 251$ ist, die Knotenmenge in jedem Schritt mindestens um den Faktor $\frac{24}{25}$ schrumpft. Da man es danach nicht mehr garantieren kann, hören wir (der Einfachheit halber) auf, sobald wir in der Hierarchie eine Triangulation mit weniger als $C=251$ Knoten generiert haben.

Das heißt, für die Höhe $h$ des resultierenden Baumes gilt letztendlich:
$$\begin{align*}
&\left(\frac{24}{25}\right)^{h}n \leq C\\
\iff & \left( \frac{25}{24}\right)^{h} \geq \frac{n}{C}\\
\iff & h=\left\lceil\log_{\frac{25}{24}}\left(\frac{n}{C}\right)\right\rceil \in \mathcal{O}(\log n)
\end{align*}$$
Da die Outgrade durch eine Konstante beschränkt sind, spielen sie in der O-Notation keine Rolle mehr.
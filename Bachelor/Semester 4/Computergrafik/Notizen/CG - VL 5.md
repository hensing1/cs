Datum: 29.04.
[[cgintro-04-Raytracing.pdf|Folien]] (ab S. 9)

# Raytracing

Renderinggleichung:

![[CG - VL 4#^b35b91]]

## Lösen der Renderinggleichung - Direkte Beleuchtung
- Wir haben ein paar Punktlichtquellen mit jeweils einer Position und einer Intensität
	- Andere Lichtquellen gibt es nicht $\to$ der emissive Term $L_{e}$ der Renderinggleichung fällt weg
- Der Integrand $\int_\Omega$ ist an fast allen Stellen Null
	- $\to$ wir müssen nur die Lichtquellen nacheinander betrachten und ihren Beitrag zur Beleuchtung des Punktes berechnen

$$L_{o}(\vec x, \vec \omega_{o}) = \sum_{k}f(\vec \omega_{k}, \vec \omega_{o}) \frac{I_{k}}{(\vec x_{k}-\vec x)^{2}}V(\vec x, \vec x_{k}) \langle \vec \omega_{k}, \vec n \rangle$$
- $f$ ist wieder die Reflektanz
- der Bruch ist die Emission der Punktlichtquelle $k$, die quadratisch mit der Distanz zum Zielpunkt abnimmt
- $V$ ist entweder 0 oder 1, je nachdem, ob $k$ von $x$ aus sichtbar ist

## Schritte des Raytracings

![[Raytracing.png|400]]

1. Strahlerzeugung
	- Schieße einen Strahl aus dem Augpunkt durch die Bildebene
2. Berechne den Schnittpunkt mit der Szene
3. Berechne, ob die Lichtquelle diesen Punkt sehen kann
### Strahlenerzeugung

> **Strahl**
> Startpunkt $\vec p$ und Richtungsvektor $\vec d$: $\vec x(t) = \vec p + t \vec d$
> $\vec d$ ist üblicherweise ein Einheitsvektor.

Richtungsvektor: 
- man braucht einen Punkt in der Bildebene $\vec p_\text{img} (u,v)$
- man braucht den Augpunkt

$$\vec d = \frac{\vec p_\text{img}-\vec p_\text{eye}}{|\vec p_\text{img}-\vec p_\text{eye}|}$$

#### Kameraparameter
- Der Augpunkt ist $\vec o$ (Kameraposition)
- Den Vektor von $\vec o$ zur Mitte der Bildebene nennen wir **Brennweite** $\vec f$
- Die Kamera hat einen Up-Vektor $\vec{\text{up}}$
- $\vec x$, $\vec y$ spannen die Bildebene auf

Zur Berechnung von $\vec d$ verwendet man $\vec f$ und addiert die Pixelposition innerhalb der Bildebene: 
![[Strahlenerzeugung.png|499]]

### Schnittpunktberechnung

Das Objekt, mit dem wir den Schnittpunkt bestimmen wollen, ist in aller Regel ein Dreieck.

Theoretisch:
- Bestimme Ebene, in der sich das Dreieck befindet
- Bestimme den Schnittpunkt von Strahl und Ebene (löse Gleichungssystem für Strahlparameter $t$)
- Prüfe, ob sich dieser Schnittpunkt im Dreieck befindet

Praktisch:
Nimm die optimierte Variante aus $\text{Fast, Minimum Storage Ray/Triangle Intersection}$ von Möller/Trumbore (1997)

Einen echten Schnittpunkt erhält man nur für $t>0$ (bzw. $t > \epsilon$ - wenn wir den Strahl von Objektpunkt zu Lichtquelle zur Schattenbestimmung berechnen, möchten wir nicht, dass die Ebene einen Schatten auf sich selbst wirft).

Haben wir mehrere Schnittpunkte, nehmen wir den mit kleinstem $t$ (wir sehen nur den Punkt, der sich am nächsten an der Kamera befindet).

> Der *Normalenvektor* einer implizit gegebenen Oberfläche ist der *Gradient*.
> Objektoberfläche ist Isofläche einer Funktion $\to$ Gradient steht senkrecht zu dieser Fläche (siehe [[Numerik - VL 13#^2dab39|Numerik]])

#### Schattentest

Hat man den Schnittpunkt des Objekts, kann man dasselbe Verfahren noch einmal anwenden, um zu testen, ob ein Schnittpunkt im Strahl zwischen Objekt und Lichtquelle vorliegt.
Falls ja, färbt man das Objekt an diesem Punkt mit einer vordefinierten Schattenfarbe ein (wir berechnen ja keine indirekte Beleuchtung).

#### Beschleunigung

Grundsätzlich haben wir das Problem, dass wir mit obigem Ansatz für jeden Strahl (jeden Pixel) jedes einzelne Dreieck auf einen Schnittpunkt testen müssen (Laufzeit ist bestenfalls linear in der Anzahl der Dreiecke).

Das lässt sich zwar gut parallelisieren, da alle Strahlen unabhängig voneinander berechnet werden können, ist aber dennoch ineffizient.

*Vorsortieren der Daten:*
- Speichere die Objekte so, dass ein näherliegendes Objekt immer vor einem dahinterliegenden gespeichert wird
	- $\to$ hierarchische Suchstruktur mit Suchkomplexität $\mathcal{O}(\log n)$ für Schnittkandidaten
- bei dynamischen Szenen: zuerst fragen, ob es sich lohnt, diese Suchstruktur immer neu aufzubauen
- Worst case: linear
- Sortierung auch Relevant für Occlusion oder Transparenz

##### Sammelobjekte

Man hat eine Gruppe von Objekten zugeordnet zu einer Bounding Box. Dann wird zuerst geschaut, ob der Strahl die Bounding Box trifft, und wenn nicht, können alle Objekte darin verworfen werden.

Mögliche Bounding Volumes:
- Kugel
	- einfache Schnittberechnung
	- meistens zu groß
- Axis-Aligned Bounding Box (AABB)
	- speichert minimale und maximale x- und y-Koordinate
	- sehr einfach Schnittberechnung
	- manchmal zu groß
- Object-aligned bounding box (OBB)
	- Box passt sich dem Objekt an
	- passt besser
	- recht schwer zu berechnen
- Slabs
	- Paare von Halbräumen, die jeweils den Raum entzwei teilen
	- Man hat eine feste Zahl dieser Paare mit je einer festen Orientierung
	- einigermaßen effizient zu berechnen

***Bounding Volume Hierarchy:***
Ein Bounding Volume enthält keine Objekte, sondern kleinere Bounding Volumes.
Man darf aber nicht sofort den erstern Schnittpunkt zurückgeben: es könnte sein, dass eine nähere Bounding Box ebenfalls einen Schnittpunkt enthält.

##### Gitter

Man teilt seinen Raum in $n$ Gitterzellen (Voxel) mit Auflösung $\sqrt[d]{n}$ pro Dimension. Objekte werden beim Einfügen einer Gitterzelle zugeordnet (gibt es Überlappungen mit mehreren Zellen, wird das Objekt dupliziert).

Nun wandert man mit seinem Strahl an den geschnittenen Voxeln entlang. Enthält ein Voxel ein Objekt, wird eine präzise Schnittberechnung durchgeführt. 

Hierbei kann man den ersten Schnittpunkt direkt zurückgeben.

Um sich an Szenen mit inhomogener Objektdichte anzupassen, kann man hierarchische Gitter verwenden.

##### Quadtrees und Octrees

Hierarchische Unterteilung: teile die Zelle, wenn sie nicht leer ist (oder mehr als N Primitives enthält).

In zwei Dimensionen: Quadtree
In drei Dimensionen: Octree

$\to$ passt sich dynamisch der Szene an
Traversierungsalgorithmen sind recht komplex.

##### BSP- und kd-Bäume

Binary Space Partition: Raum wird rekursiv mit Ebenen in beliebiger Position halbiert
Erstellen von BSP-Tree: an *Objektkanten* wird der Raum unterteilt. Ggf. müssen Objekte gesplittet werden, wenn sie durch die entstandene Ebene geteilt werden. Die Geometrie liegt also nicht nur an den Blättern, sondern auch an den Knoten des Baums.

kd-Baum: Spezialfall von BSP (mit achsenorientierten Ebenen)
Optimale Platzierung der Ebenen: schneide pro Ebene möglichst viel leeren Raum ab (benötigt Schnittwahrscheinlichkeiten und benötigte Kosten der Kindsknoten)

### Schattierung

Zurück zur Renderinggleichung: $f$ ist die *Bidirektionale Reflektanz-Verteilungsfunktion* **(BRDF)**: $$f(\vec \omega_{i}, \vec \omega_{o}) = \frac{dL_{o}(\vec \omega _{o})}{dE_{i}(\vec \omega_{i})}$$
$\to$ Verhältnis von ausfallender Radianz zu einfallender Irradianz

Diffuse Oberfläche: $f = \frac{k_{d}}{\pi}$ (konstanter Term) - das Integral von $f$ mal Kosinus-Term über die gesamte Hemisphäre darf höchstens 1 sein, deshalb teilt man durch $\pi$.

Spekulare Reflexion (Licht wird hauptsächlich in Spiegelrichtung, teils aber auch diffus reflektiert): modelliert z.B. mit Blinn-Phong: $f(\vec w_{i}, \vec w_{o}) = \frac{k_{d}}{\pi} + k_{s} \frac{(\vec n \cdot \vec h)^{p}}{\vec n \cdot \vec \omega_{i}}$ - mehr $p$ $\to$ mehr Glanz

Datum: 25.01.
[[Robotik_14_Verhaltenssteuerung__Pfadplanung.pdf|Folien]]

# Pfadplanung und Hindernisvermeidung

## Potentialfelder

- anziehend
	- Vektorfeld in Richtung eines Objekts
	- Vektorlänge abhängig von der Distanz
- abstoßend
	- Vektorfeld von einem Objekt weg
	- Je näher am Objekt, desto länger der Vektor
- Tangential
- Uniform
	- z.B. Schwerkraft

Man hat anziehende und abstoßende Objekte. Kombiniert man deren Potentialfelder, kann man den resultierenden Vektoren folgen und erstellt damit einen Pfad, welcher Hindernissen ausweicht und auf Ziele zufährt

> [!example] *Beispielhafte Berechnung*
> ...

Problem: Roboter kann in lokalen Minima steckenbleiben

## Subsumptionsarchitektur

Hierarchie:
- Kartierung
- Exploration
- Bewegung
- Hindernisvermeidung

wird von unten nach oben mit [[Endliche Automaten|endlichen Automaten]] abgearbeitet
obere Schichten können untere Schichten überstimmen
$\to$ erreichbares Verhalten ist begrenzt

## Dual Dynamics

## Hierarchiegedöns

Problem mit "erster Schritt"-Ansatz: Kamerabild zu verrauscht/verwackelt, um immer vernünftig den nächsten Schritt zu planen

# Pfadplanung

Ansätze
 - Routengraph (planar)
 - Zelldekomposition
- Sichtbarkeitsgraph
	- kürzester Pfad
	- Hindernisse werden durch Roboterradius verbreitert
- Voronoi-Routengraph
	- Knoten und Kanten sind zu den nächsten Hindernissen gleich weit entfernt
	- Pfad maximiert Abstand zu Hindernissen
- Zelldekomposition mit Kosten
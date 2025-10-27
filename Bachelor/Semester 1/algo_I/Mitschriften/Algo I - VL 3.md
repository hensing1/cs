# Greedy-Algorithmen
Überkapitel: *Methoden zum Entwurf von Algorithmen*

![[Algorithmen#Methoden zum Entwurf von Algorithmen#Greedy-Algorithmen]]

## Beispiele
### Wechselgeldproblem
- Man hat eine beliebige Menge an Münzen
- Man möchte einen Betrag zusammenstellen
- Dabei möchte man möglichst wenige Münzen verwenden

#### Lösung per Greedy-Algorithmus
- Man schnappt sich immer die größte Münze, die noch in den noch fehlenden Betrag passt
- Z.B. für den Betrag 1,49€: 1€, 20ct, 20ct, 5ct, 2ct, 2ct
- Dieser Algorithmus ist für die Euro-Münzen optimal, da:
	- man zeigen kann, dass die Greedy-Lösung durch eine bestimmte Eigenschaft[^1] eindeutig für einen beliebigen gewünschten Betrag ist
	- man auch zeigen kann, dass die optimale Lösung dieselbe Eigenschaft besitzt wie die Greedy-Lösung.
- Achtung Vorsicht: es gibt Münzkonfigurationen, mit denen der Greedy-Algorithmus nicht funktioniert, z.B. $M=\set{1,3,4}$:
	- Greedy-Lösung für Betrag 6: $(4, 1, 1)$
	- Optimale Lösung für Betrag 6: $(3, 3)$

[^1]: Besagte Eigenschaft (für $M$ als Menge der verfügbaren Münzen):
	Für $i\in M$ sei $x_i$ die Anzahl an Münzen mit Wert $i$ in der Greedy-Lösung. Für $i>1$ gilt:
	$$\sum\limits_{j\in M,j<i}jx_j<i$$
### Interval Scheduling
Man hat einen Haufen Aufgaben $S=\{A_1,A_2,...,A_n\}$, die alle einen vorbestimmten Start- und Endzeitpunkt haben:
![[Aufgabenscheduling.png|450]]

Aus diesen Aufgaben möchte man nun die größtmögliche Teilmenge auswählen, sodass sich die darin enthaltenen Aufgaben nicht überlappen. (Gleichzeitiger End- und Startpunkt zweier Aufgaben sind ok.)

#### Lösung per Greedy-Algorithmus
Man nimmt sich immer die Aufgabe raus, die den frühesten **End**zeitpunkt hat, und löscht alle Aufgaben raus die mit dieser Aufgabe kollidieren.

Das ist optimal, weil es immer eine optimale Lösung gibt, in der die zu allererst fertig werdende Aufgabe $A_1$ enthalten ist[^2].
Dann kann man quasi rekursiv S verkleinern, indem man $A_1$ und alle damit kollidierenden Aufgaben rausnimmt, und dann für das verkleinerte S wieder die optimale Lösung sucht, für die wiederum die o.g. Aussage gelten muss.

[^2]: Enthält eine optimale Lösung nicht $A_1$, ist es garantiert, dass man die erste Element aus der Lösung durch $A_1$ ersetzen kann, ohne dass irgendwelche Kollisionen in der Lösung entstehen.

### Rucksackproblem (Knapsack Problem (KP))
![[Rucksackproblem#Definition]]

Dieses Problem ist in dieser Form NP-schwer zu lösen - heißt, es gibt anscheinend keine (bekannte) effiziente Lösung.

![[Rucksackproblem#Abwandlung: Fraktionales Rucksackproblem]]

#### Rückabwandlung auf das KP
Man kann die Lösung für das fraktionale Rucksackproblem nun auf das eigentliche KP anwenden, indem man einfach das zerstückelte Element ignoriert und komplett rauslässt. Dieser Ansatz kann allerdings ein beliebig schlechtes Ergebnis liefern:
Mit Kapazität $t=M>2$:

| Objekt $i$ | Nutzen $p_{i}$ | Gewicht $w_{i}$ |
| ---------- | -------------- | --------------- |
| 1          | 2              | 1               |
| 2          | $M$            | $M$             | 

Hier packt der Greedy-Algorithmus das Element 1 ein, obwohl das Element 2 (dessen Nutzen hier beliebig hoch, aber größer als 2 ist) die optimale Lösung wäre.

Wenn man den Algorithmus so anpasst, dass er *entweder* das Ergebnis des Greedy-Algorithmus, *oder* das Element mit dem höchsten Nutzen, sofern dieser Nutzen höher ist als der Gesamtnutzen der Lösung des Greedy-Algorithmus, dann hat man eine $\frac{1}{2}$-Approximation (heißt, diese Lösung ist mindestens halb so gut wie die optimale Lösung).
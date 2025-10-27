## Definition
- Handlungsvorschrift zur Lösung eines Problems
- Allgemein formuliert - unabhängig von Programmiersprachen
- [[Relationen|Relation]] zwischen Eingabe und Ausgabe
- Es muss angegeben sein:
	- Ein- und Ausgabegrößen
	- Zulässige Anweisungen
	- Korrektheit

---

## Eigenschaften
### Korrektheit
- Ist das Problem eindeutig definiert?
- Löst der Algorithmus dieses Problem für jeden beliebigen Input?

### Effizienz
Die Effizienz eines Algorithmus kann im Hinblick auf verschiedene Kosten bzw. Messgrößen gemessen werden:
- Laufzeit
- Speicherverbrauch
- Bei Sortieralgorithmen: Anzahl der Vergleichsoperationen
- ...
$\rightarrow$ wesentlicher Untersuchungsgegenstand der Informatik.

### Lesbarkeit
Die Lesbarkeit ist ein wesentliches Qualitätsmerkmal von Algorithmen und Software.
- Kernidee wird einfach und verständlich präsentiert
- Je lesbarer das Programm, desto weniger anfällig ist es für Implementierungs- und Denkfehler

### -> Zielkonflikt
Meistens ist es nicht möglich, einen Algorithmus zu entwickeln, der sowohl:
- immer die bestmögliche Lösung findet, als auch
- effizient ist, als auch
- gut lesbar ist.

---

## Arten von Algorithmen
### Sortieralgorithmen
Formal ausgedrückt:
> Die Ausgabe eines Sortieralgorithmus ist eine aufsteigend sortierte Permutation der Eingabe.

#### Eigenschaften von Sortieralgorithmen
##### Stabilität
> Ein Sortieralgorithmus heißt **stabil**, wenn die relative Ordnung gleicher Elemente beim Sortieren erhalten bleibt.

[[Insertionsort]] und [[Mergesort]] sind stabil, [[Quicksort]] hingegen nicht. Man kann nur recht schwer Anpassungen an Quicksort vornehmen, um ihn stabil zu machen - meistens wird er dadurch langsamer.

##### Speicherplatz
> Ein Sortieralgorithmus arbeitet **in situ** (*in-place*), wenn er zusätzlich zum zu sortierenden Feld nur konstant viel Speicherplatz benötigt.

Zum Beispiel arbeitet [[Insertionsort]] in situ, [[Mergesort]] hingegen braucht zusätzlichen Speicher in der Größenordnung $\Theta(n)$, da das gesamte Feld parallel gespeichert werden muss.
Die Partitionierung von [[Quicksort]] arbeitet in situ, allerdings benötigt der Algorithmus zusätzlichen Speicherplatz für den Rekursionsstack. Dieser wächst im Normalfall logarithmisch mit $n$, wodurch Quicksort formell gesehen nicht in situ arbeitet.

##### Funktionsweise
###### Vergleichsbasiertheit
> Ein Sortieralgorithmus arbeitet *vergleichsbasiert*, wenn er nur durch die Vergleiche zweier Objekte aus der Eingabe Informationen über die Eingabe gewinnt.

Ein vergleichsbasierter Sortieralgorithmus, egal wie er funktioniert, benötigt im Worst Case 
$\Omega(n\log n)$[^1] Vergleiche. Damit liegt auch seine Laufzeit im Worst Case in $\Omega(n\log n)$.
Warum, steht [[Algo I - VL 5#Untere Schranke für vergleichsbasierte Algorithmen|hier]].

[^1]: Vgl. [[Größenordnungen]]

#### Verschiedene Sortieralgorithmen
##### Sortieren in quadratischer Zeit
- [[Insertionsort]]
- [[Selection Sort]]

##### Sortieren in logarithmischer Zeit
- [[Mergesort]]
- [[Quicksort]]
- [[Heaps#Heap Sort|Heapsort]]

##### Sortieren in Linearzeit
- [[Radixsort]]

---
### Graphenalgorithmen
#### Graphensuche
- [[Graphen#Breitensuche|Breitensuche]]
- [[Graphen#Tiefensuche|Tiefensuche]]
#### Kürzeste Wege
- [[Kürzeste Wege#Dijkstra-Algorithmus|Dijkstra-Algorithmus]] (SSSP)
- [[Kürzeste Wege#Floyd-Warshall-Algorithmus|Floyd-Warshall-Algorithmus]] (APSP)
#### Minimaler Spannbaum
- [[Minimaler Spannbaum#Algorithmus von Kruskal|Algorithmus von Kruskal]]

### Suchalgorithmen
#### Graphen
- [[Graphen#Breitensuche|Breitensuche]]
- [[Graphen#Tiefensuche|Tiefensuche]]

#### Labyrinthe
- [[Pledge-Algorithmus]]

#### Listen
- [[Binary Search]]

---

### Berechnungen
- Berechnung des größten gemeinsamen Teilers: [[Euklidischer Algorithmus]]
- Multiplikation von Matrizen: [[Strassen-Algorithmus]]

---

## Methoden zum Entwurf von Algorithmen
### Divide-and-Conquer
#### Allgemeiner Ansatz
- Man teilt eine Instanz eines Problems (z.B. eine zu sortierende Zahlenfolge) in k Teilinstanzen auf
- Man löst diese Teilinstanzen einzeln rekursiv
- Man kombiniert am Ende die gelösten Teilinstanzen wieder zur Gesamtlösung

### Greedy-Algorithmen
Ein Greedy-Algorithmus löst eine Probleminstanz schrittweise, indem er in jedem Schritt die jeweils für diesen Schritt optimale Entscheidung trifft, ohne dabei zukünftige Schritte zu berücksichtigen.

### Dynamische Programmierung
Zunächst gleicht das Prinzip der dynamischen Programmierung dem des 
[[Algorithmen#Methoden zum Entwurf von Algorithmen#Divide-and-Conquer#Allgemeiner Ansatz|Divide-and-Conquer]].

Der Unterschied ist, dass man bei der dynamischen Programmierung die Lösungen der Teilinstanzen zwischenspeichert.
Das ist dann hilfreich, wenn Teilinstanzen mehrfach vorkommen können - dann muss man diese kein zweites Mal lösen, sondern kann auf die vorherige Berechnung zurückgreifen.
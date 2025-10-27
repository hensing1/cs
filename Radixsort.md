Radixsort ist ein Algorithmus zum Sortieren von Ganzzahlen in Linearzeit.

# Funktionsweise & Laufzeit
## M-Sort
Damit der Radixsort funktioniert, braucht man einen Hilfsalgorithmus, hier genannt M-Sort. 

M-Sort funktioniert folgendermaßen:
- Man geht davon aus, dass die Werte im Eingabefeld nicht größer sind als eine Zahl $M$.
- Nun erstellt man sich für jede Zahl von 0 bis $M$ eine leere verkettete Liste.
- Nun geht man einmal die Liste durch:
	- Jedes Element $a$ aus dem Eingabefeld kommt ans Ende von der Liste an der Stelle $\text{wert}(a)$.
- Nun hängt man alle Listen aneinander, in der Reihenfolge $0,1,\ldots,M-1$.

Dieser Algorithmus sortiert das Eingabefeld bereits in Linearzeit, konkret in $O(n+M)$. Da $M$ aber beliebig groß sein kann (z.B. $2^{32}$ für einen `int`), ist er als Sortieralgorithmus ungeeignet.

Wichtigerweise ist M-Sort jedoch [[Algorithmen#Sortieralgorithmen#Stabilität|stabil]].

## Der Rest
Radixsort geht nun seine Zahlen Ziffernweise durch, und sortiert dabei nacheinander alle Zahlen bezüglich der $i$-ten Ziffer mithilfe von M-Sort. Da M-Sort stabil ist, bleibt die Reihenfolge bzgl. der vorher sortierten Ziffern erhalten, und am Ende ist das komplette Array sortiert.
Für eine Zahl in [[Kodierung von Binärzahlen#Ganzzahlen|M-adischer Darstellung]] braucht M-Sort dafür $O(n+M)$ (s.o.). Mit $l$ Ziffern benötigt Radixsort also eine Laufzeit in $O(l(n+M))$.
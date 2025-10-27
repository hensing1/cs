# Kapitel 3: Sortieren
Video: [Vorlesung - Woche 05](https://uni-bonn.sciebo.de/s/7Gfq3hL6DaUYioC#/files_mediaviewer/Vorlesung%20-%20Woche%2005.mp4)
Folien: [[Bachelor/Semester 1/algo_I/Skript & Folien/algo_I_03.pdf|Kapitel 3]]

![[Quicksort]]

# Eigenschaften von Sortieralgorithmen
![[Algorithmen#Sortieralgorithmen#Eigenschaften von Sortieralgorithmen]]

## Untere Schranke für vergleichsbasierte Algorithmen
Man kann allgemein sagen, dass für zwei Felder mit verschiedenen Ordnungstypen jeder vergleichsbasierte Algorithmus sich unterschiedlich verhalten muss.

Was ist ein Ordnungstyp?
![[Glossar#Ordnungstyp]]

Das Verhalten eines vergleichsbasierten Algorithmus kann man für ein festes $n$ abstrakt als Entscheidungsbaum darstellen, der die Bestimmung des Ordnungstypen der Eingabe darstellt:
![[Entscheidungsbaum_vergleichsbasierte_Algorithmen.png]]

Uns interessiert nun die Höhe dieses Entscheidungsbaums, da das die Anzahl der Vergleiche durch den Algorithmus im Worst Case ist.

Für ein Feld der Länge $n$ gibt es $n!$ Ordnungstypen, und die Anzahl der Blätter eines Binärbaums mit Höhe $h$ ist $2^h$. Das heißt, die Höhe des Baums muss so gewählt sein, dass gilt:
$2^{h} \geq n! \Rightarrow h\geq\log(n!)$.

Da $\log_2(n!)\in\Theta(n\log n)$, ist die Laufzeit von vergleichsbasierten Algorithmen in $\Omega(n\log n)$.

# Sortieren in Linearzeit
![[Radixsort]]

# Merge Sort
Konzept: #divide-and-conquer

## Funktionsweise
Merge Sort ist ein Sortieralgorithmus.
Man teilt seine Liste in zwei Hälften, sortiert diese unabhängig voneinander, und merget sie danach wieder zusammen.
Als Pseudocode:
- Sortiere linke Hälfte per merge sort
- Sortiere rechte Hälfte per merge sort
- Merge

## Laufzeit
Man definiert eine [[Rekursionsgleichungen|Rekursionsgleichung]]:
$$T(n)\le 2*T(n/2)+cn$$
wobei $T(n/2)$ die Laufzeit je eines rekursiven Aufrufs ist, und $cn$ die Zeit für den Aufruf von `Merge`, welche linear mit $n$ wächst (skaliert mit einer Konstante $c$).
Damit kann man entweder eine vollständige Induktion machen (siehe [[algo_I_02_1.pdf|Folien]] Seite 56), oder man pflanzt sich einen hübschen Rekursionsbaum:
![[Rekursionsbaum_Mergesort.png]]

In beiden Fällen kommt raus:
$$
\text{Laufzeit(Mergesort)} \in \Theta(n\log(n))
$$
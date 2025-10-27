Gehört zu #divide-and-conquer.

##### Funktionsweise
Man hat eine sortierte Liste und möchte ein bestimmtes Element $x$ darin finden.
Lösung:
Man sucht sich das Element in der Mitte raus und vergleicht es mit $x$; falls $x$ kleiner ist, sucht man im linken Teil der Liste weiter, falls es größer ist, im rechten - das ganze dann rekursiv.

##### Laufzeit
- Beweis für logarithmische Natur der Laufzeit:
	- man zählt quasi die Anzahl der Rekursiven Aufrufe (k)
	- Da sich das zu betrachtene Intervall mit jedem Schritt halbiert, kann es nicht mehr rekursive Aufrufe geben als $k=\log _{2}(n)$
	- Alles, was kein rekursiver Aufruf ist, ist in $\mathcal{O}(1)$
	- Daher ist die Laufzeit von Binary Search in $\mathcal{O}(\log(n))$
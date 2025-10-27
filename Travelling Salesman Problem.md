## Problem
Man hat einen Haufen Städte (bzw. einen Haufen Punkte, deren Distanz zueinander eindeutig bestimmt ist) und versucht, die kürzeste Rundreise zu finden, die all diese Punkte besucht

## Approximative Verfahren
### Minimum Spanning Tree
- Man baut sich einen Minimum Spanning Tree auf:
	- Man geht nacheinander alle Verbindungen durch, die am kürzesten sind
	- Man fügt die aktuelle Verbindung hinzu, falls mind. einer der beiden Punkte noch nicht hinzugefügt wurde
	- Man hört auf, sobald alle Punkte hinzugefügt wurde
- Nun geht man per Rechte-Hand-Regel den Baum entlang
- Sobald man den nächsten Punkt erreicht hat, fügt man ihn hinten an die Rundreise an - es sei denn, er wurde schon hinzugefügt

-> Durch den Minimum Spanning Tree erreicht man eine 2-Approximation
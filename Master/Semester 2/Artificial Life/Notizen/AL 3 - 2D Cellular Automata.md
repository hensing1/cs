[[ALSS25_03_CA_in_2D_Game_of_Life.pdf|Folien]]

***Arten von Nachbarschaften:***
- L4: "von Neumann"
- L8: "Moore"
Für $r=2$ haben wir keine fest definierten Bezeichnungen für die verschiedenen Möglichkeiten.

## Beispiele

#### Majority Voting
Mit $k \geq 2$ Zuständen: Folgezustand ist definiert durch Mehrheit der Zustände innerhalb der Nachbarschaft.
Falls keine Mehrheit vorhanden ist, behält die Zelle ihren Zustand bei.

### Nichtdeterministische CA

#### Forest Fire

Zustände: Feuer, Erde, Baum

Übergänge:
- Feuer -> Erde
- Erde -> Baum
	- spontan: mit W'keit $p$
	- falls Baum in von-Neumann-Nachbarschaft: mit W'keit $q$
- Baum -> Feuer
	- spontan: mit W'keit $f$
	- falls Feuer in von-Neumann-Nachbarschaft

### Conway's Game of Life

Nachbarschaft: $r=1$ Moore (L8)
Zustände: 0 oder 1

Regeln:
- Falls 1:
	- -> 1, falls $\sum$ Nachbarschaft = 2 oder 3 (ausgenommen Zelle selbst)
	- -> 0 sonst
- Falls 0:
	- -> 1, falls $\sum$ Nachbarschaft = 3
	- -> 0 sonst
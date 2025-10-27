[[ALSS25_02_Cellular_Automata.pdf]]
# Cellular Automata

Cellular Automata sind ein Ansatz für Informationsverarbeitung. Sie unterscheiden sich von der [[Von-Neumann-Architektur]], werden also **Non-von-Neumann**-Computer genannt.

Geprägt durch: Stanislav Ulam, Arthur Burks, John von Neumann, Stephen Wolfram

## Bestandteile

*Zellen auf einem Gitter* (cell lattice)

Das Gitter hat Dimension $d$ (üblicherweise $d=1$ oder $d=2$)

Eine Zelle hat einen Zustand $a$ aus einem Alphabet $A$, $|A|=k$.

Für alle Zellen wird definiert:
- eine Nachbarschaft $N$
	- Größer der Nachbarschaft im Fall $d=1$ angegeben mit Radius $r$, dh. $|N|=2r+1$
	- eine Zelle ist Teil ihrer eigenen Nachbarschaft
- eine *Regel* für den Folgezustand, abhängig von den Zuständen in der Nachbarschaft

Mögliche Startzustände für das Gitter:
- zufällig
- eine/endlich viele Zellen gesetzt (seed)
- Muster (unendlich)

*Anzahl Zustände einer Nachbarschaft:* $k^{|N|}$
*Anzahl möglicher Regeln:* $k^{k^{|N|}}$

Beispiel einer Regel für $k=2, d=1, r=1$:
![[Automaton_1d.png]]

Für diese Regeln gibt es die *Wolfram-Zahl*, im Fall oben: $(01011010)_{B}=90$

## Eigenschaften von Regeln

- **Silent:** 
	- ist gesamte Nachbarschaft im nicht-gesetzen Zustand, ist der Folgezustand auch nicht gesetzt
	- => leerer ("still") Bereich bleibt leer
- **Symmetrisch:**
	- alle Nachbarschaften, die Spiegelungen voneinander sind, haben denselben Folgezustand
- **Legal:**
	- Regel ist silent und symmetrisch
- **Peripher:**
	- Folgezustand einer Zelle hängt nicht von ihrem eigenen Zustand ab, sondern nur vom Zustand der angrenzenden Zellen
- **Totalistisch:**
	- Folgezustand hängt nur von *Anzahl* der gesetzten Zellen der Nachbarschaft ab

## Grenzen des Gitters

- virtuell unendlich
- zyklisch
- fixiert (Grenzzellen haben fixen, evtl. zufälligen Wert)
- adiabatisch (Zellen hinter der Grenze werden gespiegelt)
- absorbierende (offene) oder spiegelnde (geschlossene) Grenzen, hängen von der spezifischen Regel ab

## Verhaltensklassen

Nach Wolfram: Unabhängig vom Startzustand lässt sich das langfristige Verhalten unter einer bestimmten Regel meist in eine von vier Klassen einteilen

1. Homogen
	- alle Zellen verbleiben im silent state
2. Periodisch
	- Zustände oszillieren
3. Chaotisch
	- keine Periodizität und keine Muster zu erkennen
4. Komplex
	- Strukturen entstehen, verändern sich, interagieren miteinander, erstellen neue Strukturen
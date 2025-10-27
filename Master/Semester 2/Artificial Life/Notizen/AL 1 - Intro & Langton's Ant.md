[[ALSS25_01_Orga_A-Life_L-Ant.pdf]]
## Definitionen von Künstlichem Leben

> **Strong Artificial Life**
> "Tatsächliches" künstliches, dh. vom Menschen aus totem Material geschaffenes Leben, welches den gängigen Definitionen von *lebend* entspricht. 
> Heißt: es hat einen Metabolismus, wächst, kann sich fortpflanzen, reagiert auf Stimuli, etc.
> Operiert hauptsächlich auf *molekularem* Level.

^c380dd

> **Weak Artificial Life**
> Ziel: Eigenschaften, Prinzipien und Umstände für Leben identifizieren. 
> Verhalten von lebendigen Wesen wird *simuliert*.

^0ad659

## Langtons Ameise

Langtons Ameise operiert auf einem binären, rechteckigen Gitter. Sie hat eine $(x,y)$-Postion und eine Richtung $r \in \{ N,O,S,W \}$. Sie führt zyklisch die folgenden Schritte aus:
- **Scan**
	- Welche Farbe hat das aktuelle Feld?
- **Turn**
	- Falls Feld weiß: drehe 90° nach rechts
	- Falls Feld schwarz: drehe 90° nach links
- **Flip**
	- Ändere die Farbe des aktuellen Felds
- **Move**
	- Gehe einen Schritt in die aktuelle Richtung

### Verhalten
Bei komplett weißem Feld am Anfang:

Phase 1: Symmetrisches Wachstum (ca. bis Schritt 420)
Phase 2: Chaotisches Wachstum (ca. Schritte 400 bis 10000)
Phase 3: Periodisches Wachstum

![[Ameisenphasen.png|400]]

### Turing-Maschine

Man kann AND und NOT-Gates mit der Ameise implementieren (die Ameise läuft an einem Ende des Gates rein und am anderen wieder raus, und am Ende sind alle Felder gleich bis auf Input und Output).
Das bedeutet, jede boolesche Funktion kann implementiert werden, und Langton's Ameise ist eine [[Turingmaschine]].

### Erweiterungen

- Ein Feld könnte mehr als 2 Zustände haben
	- Zustände werden hochgezählt
	- Je nach Zustand dreht die Ameise entweder nach links oder nach rechts
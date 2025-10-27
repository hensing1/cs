Datum: 10.11.
[[TI_03_Boolesche_Algebra.pdf|Folien]] (Seiten 39 bis 58)

![[Binäre Entscheidungsdiagramme]]

# Logikgatter
![[logikgatter.png]]

# Schaltnetze
Man kann nun die Logikgatter zu Netzen zusammenbauen, um jede beliebige boolesche Funktion darzustellen.

Schaltnetze können nun je nach Anforderung sehr unterschiedlich umgesetzt werden.
- Normalform
	- Man bringt seine Funktion in die DNF
	- Man nimmt jede Eingangsvariable und deren Negation
	- Nun kann man sich mit AND-Gattern seine Minterme zusammenbauen
	- Das wird dann am Ende mit einem OR zusammengefasst
- Reduziertes Polynom
	- Man reduziert seine DNF auf möglichst wenig Minterme
	- Die Umsetzung ins Schaltnetz ist danach gleich, man braucht aber eben nur wesentlich weniger Gatter
- Reduzierung auf NAND
	- Man kann sein Polynom auch ausschließlich in NAND-Operationen umformen:
	  $x_1x_2+x_1x_3+x_2x_3=((x_1x_2)'(x_1x_3)'(x_2x_3)')'$ (nach den [[Aussagen#De Morgan'sche Gesetze|De-Morgan-Gesetzen]])
	- Das heißt, wenn man sein Polynom in ein Schaltnetz umgesetzt hat, kann man einfach jedes AND und OR mit einem NAND ersetzen
	- Praktisch, weil NAND-Gates weniger Transistoren brauchen

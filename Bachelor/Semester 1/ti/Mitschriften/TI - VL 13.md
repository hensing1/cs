Datum: 01.12.
[[TI_04_Schaltnetze.pdf|Folien]] (Ab S. 83)

# Subtraktion
$A-B$ wird folgendermaßen realisiert:
- Bilde Zweierkomplement von B
	- Invertiere alle Bits
	- Addiere eine 1
- Ignoriere das Carry-Out-Bit

# Carry-Save-Addierer
Ein Carry-Save-Addierer (CSA) macht aus drei Zahlen $a,b,c$ mit $a+b+c=s$ zwei Zahlen $e,f$ mit $e+f=s$.
$e+f$ kann man dann z.B. wieder mit einem normalen Addierer berechnen.

Das ganze funktioniert, indem pro Stelle alle drei Bits in einen Volladdierer gestöpselt werden. Die Summenbits dieser ganzen Volladdierer ergeben $e$, und die Übertragsbits ergeben (um eins nach rechts geshiftet) $f$.
Da die Volladdierer nicht voneinander abhängen, liegt die Laufzeit in $\mathcal{O}(1)$ (3 Gatterlaufzeiten).

Man kann beliebig viele CSAs hintereinander schalten, um beliebig viele Zahlen zu addieren.

# Multiplikation
Mit Logikgattern kann man leider nicht mal eben so zwei Zahlen miteinander multiplizieren.
Die Lösung: man multipliziert nach Schulmethode - das heißt, für zwei Zahlen der Länge $n$ braucht man $n$ Additionen.
![[Schulmethode.png|250]]

Jede Zeile kann man mit einem UND-Gatter für jedes Bit ein- und ausschalten.
Für $n$ Additionen kann man $n-2$ Carry-Save-Addierer nehmen (und am Ende einen normalen Addierer). Wenn man CSAs in einer Baumstruktur anordnet, hat man die geringste Durchlaufzeit ($\mathcal{O}(\log n)$):
![[Multiplizierer.png|400]]

# ALU
- Kombiniert eine Menge von funktionalen Einheiten (z.B. Shifter, Addierer, etc.) in einen einzelnen Chip, und am Ende hat man einen Multiplexer mit dem man eine bestimmte Funktion auswählen kann.
- Dafür gibt es einen Befehlsdekodierer, der neben den Inputs für den MUX auch noch Inputs für z.B. den Addierer liefert

# Komparator
**Überprüfen auf Gleichheit:**
Vergleicht zwei Binärzahlen auf Gleichheit, indem beide Bits derselben Stelle mit einem XOR verknüpft werden, und am Ende werden diese ganzen Teilergebnisse mit einem NOR kombiniert (sobald eine Stelle verschieden ist, geht das XOR auf 1 und das NOR dadurch auf 0).

**Größer-Kleiner-Vergleiche:**
Man subtrahiert eine Zahl von der anderen. Wenn alle Ausgangsbits 0 sind, sind beide Zahlen gleich, wenn das Negativ-Bit gesetzt ist, war die zweite Zahl größer, und wenn keins von beidem der Fall ist, war die erste Zahl größer.
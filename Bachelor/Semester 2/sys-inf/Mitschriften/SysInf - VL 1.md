Datum: 11.04
[[SysInf_Kap_1_Teil_1_230311_1117.pdf|Folien]]

# Einführung
## Betriebssysteme

> [!abstract] Definition
> Ein **Betriebssystem** ist eine Zusammenstellung von Programmen, welche die Systemressourcen eines Computers verwaltet und sie Anwendungsprogrammen zur Verfügung stellt.
> Es ist damit die *Schnittstelle* zwischen Hardwarekomponenten und Anwendungssoftware.

Die wichtigsten Aufgaben:
- Nutzerkommunikation
- Laden, Ausführen, Unterbrechen und Beenden von Programmen
- Zuteilung der Prozessorzeit
- Verwaltung des Hauptspeichers
- Betrieb der angeschlossenen Geräte
- Schutzfunktionen z.B. durch Zugriffsbeschränkungen

Um die angeschlossene Hardware verfügbar zu machen, braucht es Gerätetreiber. Diese bilden (gemessen am Speicherplatz) einen sehr großen Teil eines Betriebssystems.

Mittels Gerätetreibern unterscheidet man:
- Konkrete Betriebsmittel: z.B. Netzwerkkarte
- *Virtuelle Betriebsmittel*: standardisierte Schnittstelle des Kernels für alle Netzwerkkarten (technische Details werden gekapselt)

## Systemprogrammierung
> Als **Systemprogrammierung** bezeichnet man die Entwicklung von Programmen, die Teil des Betriebssystems sind bzw. direkt mit der Hardware kommunizieren müssen.

In der Systemprogrammierung muss man sich als Entwickler selbst um Synchronisation und Interprozesskommunikation kümmern. Programmierung auf Betriebssystemebene ist dadurch vergleichsweise umständlich.
Durch systemnahe Software schafft man eine Schnittstelle (bzw. Abstraktionsschicht) zwischen einer Applikation und dem Betriebssystem.

Die Systemprogrammierung steht im Gegensatz zu der *Anwendungsprogrammierung*. 
Fokus der Anwendungsentwicklung: Funktionalität,
Fokus der Systemprogrammierung: Effizienz und Robustheit.
Anwendungsentwicklung passiert daher meist mit Hochsprachen, welche die Funktionen der Systemprogrammierung kapseln.

Entsprechend wird Systemprogrammierung mit systemnahen Sprachen wie C, C++ oder Assembly umgesetzt.

# Computer-Hardware
## Von-Neumann-Architektur
Siehe: [[Von-Neumann-Architektur]]

In der Realität hängt die Peripherie (wie Laufwerke, Tastatur, Drucker, Netzwerkkarte, etc.) am selben Daten- und Adressbuss wie der RAM und ROM. Das heißt, dass für die CPU sich Hardwarezugriffe nicht von Speicherzugriffen unterscheiden. 

## BORIS
Boris ist ein Mikroprozessor. Boris:
- kann drei Befehle: LOAD, ADD, STORE
- kann den Hauptspeicher lesen und schreiben
- hat einen Akkumulator und eine ALU
- hat Register:
	- Current Instruction Register (CIR)
		- enthält den zuletzt aus dem Speicher geholten Befehl
	- Memory Data Register (MDR)
		- enthält Daten/Befehle, die aus dem Speicher kommen oder in den Speicher sollen
	- Memory Address Register (MAR)
		- enthält die Speicheradresse für den aktuellen Zugriff

### Befehle
Ein BORIS-Befehl passt in ein Byte: die ersten 4 Bits stellen den Operator dar, die 4 Bits danach den Operanden (hier: immer Speicheradressen)

Initialisierung: Setze den PC auf die erste Speicherzelle des auszuführenden Programms. Lade den Inhalt des PC dann in das MAR.

Laden eines Befehls: Gehe zu der Adresse, die im MAR steht, und lade den Inhalt in das MDR. Da es ein Befehl ist, wird er in das CIR kopiert. Inkrementiere danach den PC.

Dekodierung eines Befehls: die Control Unit schaut sich den Befehl im CIR an und schreibt den Operanden (die Adresse) in das MAR.

Ausführung des Befehls: 
- `LOAD A, [x]` (Befehlscode: `1001`)
	- Das MAR zeigt auf die Speicherstelle `x`. Der Inhalt davon kommt ins MDR.
	- Vom MDR kommt der Wert in den Akkumulator.
- `ADD A, [x]`
	- Das MAR zeigt auf die Speicherstelle `x`. Der Inhalt davon kommt ins MDR.
	- Der Inhalt des Akkumulators wird in die ALU kopiert.
	- Der Akkumulator wird mit dem Wert im MDR überschrieben.
	- Die ALU addiert Akkumulatorinhalt mit dem intern gespeicherten Wert.
	- Das Ergebnis wird in der ALU zwischengespeichert und kommt wieder in den Akkumulator.
	- -> es wurde also der Inhalt von `x` mit dem Akkumulatorinhalt addiert und wieder in den Akkumulator geschrieben.
- `STORE A, [x]`
	- Der Inhalt des Akkumulators wird in das MDR geladen.
	- Der Inhalt des MDR kommt an die Speicherstelle, die im MAR steht.

### Probleme
Wenn in der Speicherzelle des aktuellen Befehls gar kein gültiger Befehl drin ist, versucht BORIS trotzdem, ihn auszuführen.

## CISC und RISC
**Performance Equation:**
$$\frac{\text{time}}{\text{program}}=\frac{\text{instructions}}{\text{program}}\cdot \frac{\text{cycles}}{\text{instruction}}\cdot \frac{\text{time}}{\text{cycle}}$$
### CISC
Philosophie: so wenig instructions/program wie möglich (viele spezialisierte Befehle).

Es wird vorausgesetzt, dass der Compiler die "mächtigen" Operationen sinnvoll nutzt und nicht durch mehrere kleine Operationen nachbildet.

CISC-Befehle werden in der CPU durch Mikrocode in Teilschritte umgewandelt, die sehr ähnlich zu RISC-Befehlen aussehen.

CISC-Architektur: x86

### RISC
Philosophie: durch möglichst simple Befehle so wenige cycles/instruction (CPI) wie möglich

Es wird auf komplexe Adressierung verzichtet: Zugriffe auf den Hauptspeicher erfolgen lediglich mit Load und Store. Es wird daher sehr viel mit schnellen Registern gearbeitet. So werden auch langsame Hauptspeicherzugriffe so weit es geht verringert.
Man braucht für eine effiziente RISC-Maschine Compiler, die sehr Geschickt Gebrauch von den stark begrenzten Ressourcen machen.

RISC-Architektur: ARM (verbaut in Smartphones)

## Pipelining
### Befehlsphasen-Pipelining
(siehe TI)

geht dann besonders gut, wenn alle Befehlsphasen gleich lang sind.
Man muss vorhersagen, welcher Befehl wahrscheinlich als nächstes ausgeführt wird

### Super-Pipelining
Befehlsphasen werden weiter aufgeteilt und pipegeleint, z.B. Fetching der einzelnen Operanden.

### Superskalar-Technik
Befehlsfluss wird so zerlegt, dass mehrere Befehle echt gleichzeitig bearbeitet werden können.

### Multithreading
Jeder einzelne Prozessor/Prozessorkern arbeitet an einem Teil der Aufgabe (Thread), ohne sich nennenswert mit den anderen zu verständigen.
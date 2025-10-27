Datum: 19.01.
[[TI_07_Mikroprozessortechnik.pdf|Folien]] (Seiten 1 bis 15)

# Mikroprozessortechnik
## Von-Neumann-Architektur
![[Von-Neumann-Architektur#Grundlagen]]

### Arbeitsweise
Ein Programm besteht aus einer Folge von Maschinenbefehlen.
Diese stehen sequenziell im Hauptspeicher und werden standardmäßig auch sequenziell abgearbeitet.
Ausnahmen:
- Sprungbefehle (bedingte oder unbedingte Verzweigungen im Programmablauf)
- Unterprogrammaufrufe (Verzweigung in Unterprogramm, daraufhin Rückkehr an die ursprüngliche Stelle)
- Hardware Interrupts
- Exceptions

### Aufbau der CPU
![[CPU-Schema.png]]

#### Steuerwerk
- Liest den nächsten Befehl aus dem Speicher (die Adresse steht im Instruktionszähler)
- Dekodiert den gelesenen Befehl mit dem Instruktionsdekoder
- Setzt dahingehend die Steuersignale für das Rechenwerk (Datenpfad)

#### Registersatz
##### Universalregister
- Dienen zum Speichern von Zwischenergebnissen
- Je mehr Register, desto weniger Zugriffe zum Hauptspeicher werden benötigt
- In modernen CPUs gibt es 16, 32, oder mehr davon

##### Hilfsregister
Register mit speziellen Funktionen:
- **Instruktionszähler** (PC)
- **Statusregister**
	- Enthält Informationen über das Ergebnis der zuletzt ausgeführten arithmetischen Operation
	- Damit können bedingte Sprünge realisiert werden (z.B. BRZ: Branch if Zero)
- **Stackpointer** (zur einfachen Realisierung eines Stacks)
- **Instruktionsregister** (IR)
	- Zwischenspeicher für den auszuführenden *Befehl* (wird aus dem RAM dort reingeschrieben)
	- Wird vom Steuerwerk ausgelesen, um entsprechende Steuersignale zu erzeugen
- **Datenregister**
	- Zwischenspeicher für *Daten* (wird auch aus dem RAM dort reingeschrieben)
	- Wird vom Datenpfad ausgelesen

### Befehlsphasen
Die Abarbeitung eines Maschinenbefehls erfolgt (mindestens) über die folgenden vier Phasen:

#### Fetch
Man holt den Befehl aus dem Hauptspeicher.
- Inhalt des PC kommt auf den Adressbus
- Daten aus dem Hauptspeicher kommen ins Instruktionsregister
- PC wird inkrementiert

#### Decode
- Maschinenbefehl im IR wird dekodiert
- Operanden (falls vorhanden) werden gelesen

#### Execute
- Rechenwerk führt dekodierten Befehl aus
- Bei komplexeren Befehlen kann das auch aus mehreren Phasen bestehen

#### Write
Ergebnis aus dem Datenpfad wird abgespeichert: entweder in den Hauptspeicher, in ein Register oder bei einem Sprungbefehl in den PC
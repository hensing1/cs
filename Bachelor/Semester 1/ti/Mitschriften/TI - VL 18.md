Datum: 20.12.
[[TI_05_Schaltwerke.pdf|Folien]] (Seiten 96 bis Ende)

# Hauptspeicher
> Ein Hauptspeicher (RAM, Random Access Memory) dient dazu, eine große Anzahl von Datenworten zu speichern.

Jede Speicherstelle bekommt seine eigene Adresse. Damit benötigt man $\log_2(n)$ Datenleitungen für $n$ Adressen.

Es gibt zwei Arten von Hauptspeichern: statischen (SRAM) und dynamischen (DRAM)

## SRAM
> Statischer RAM

Man hat lauter Kippglieder (z.B. RS- oder D-Flip-Flops), die man mit einem Adressdekoder anwählen kann (immer ein Wort gleichzeitig).

Die Zugriffszeit ist hierdurch extrem kurz (nur wenige Nanosekunden), jedoch auch teuer in der Herstellung, da man 4 bis 6 Transistoren pro Speicherzelle benötigt. Daher werden SRAMs z.B. als schnelle, aber kleine Zwischenspeicher (Caches) verwendet.

### Aufbau
Zusätzlich zu den Adressleitungen hat man noch eine Leseleitung (deaktiviert bei 1 den Eingang und aktiviert den Ausgang), $n$ Input- und $n$ Outputleitungen. Wenn read = 0, werden die Inputs an die jeweiligen vom Adressdekoder ausgewählten Latches weitergeleitet.

Weitere oft verwendete Steuerleitungen:
- OE: Output Enable
	- Damit überhaupt was aus den Ausgängen rauskommt
	- "Tri-State"-Ausgang: Vermeidung von Kurzschlüssen, wenn mehrere Speicher zusammengeschaltet werden (Transistoren sind weder mit low noch mit high verbunden)
- CS: Chip Select
	- Aktiviert den gesamten Chip
- RD: Read
	- 1 schaltet Chip auf Lesemodus
- WE: Write Enable
	- Alternative zu RD - 1 schaltet Chip auf Schreibmodus

Wenn man mehr Speicher will, kann man entweder mehr Datenleitungen nehmen (# Datenleitungen linear mit Speicherkapazität) oder mehr Adressleitungen (# Adressleitungen logarithmisch mit Kapazität).
Beispiel: man kann 256 kBit speichern als 32k 8-Bit-Worte (15 Adress- und 8 Datenleitungen) oder 256k einzelne Bits (18 Adress- und eine Datenleitung).

Über den Tristate-Ausgang kann Ein- und Ausgang dieselbe Leitung sein.

Man kann in der Schaltung ordentlich was vereinfachen, indem man keine richtigen Latches nimmt, sondern eine CMOS-RAM-Zelle aus Transistoren zusammenbaut.

## DRAM
> Dynamischer RAM

In einem DRAM wird die Information nur in einem einzigen Kondensator abgelegt. Dadurch ist er zwar langsamer als ein SRAM, aber wesentlich günstiger. DRAMs werden als Hauptspeicher eingesetzt.

Die Ladung im Transistor bleibt nur für einen kurzen Zeitraum erhalten, daher muss eine Speicherzelle alle paar Millisekunden aufgefrischt werden.

### Aufbau
Man hat also einen Kondensator und einen MOSFET pro Speicherzelle:
![[DRAM-Zelle.png|250]]

Ist die Word Line auf 1, wird der Kondensator mit der Data Line Verbunden und kann dadurch entweder gesetzt werden, oder man kann den Rückfluss vom Kondensator an der Data Line messen und dadurch die Speicherzelle auslesen.
Aber auch wenn die Word Line aus ist (der Transistor also schließt), entlädt sich der Transistor von selbst.

Diese Speicherzellen sind auf dem Chip dann in einer Matrix angeordnet. Durch die Adressleitungen werden dann nacheinander die Zeilen (RAS, Row Address Strobe) und Spalten (CAS, Column Address Strobe) adressiert. Eine Zeile speichert genau eine *Seite* (page).
Eine Seite landet dann in einem internen Puffer, von wo aus sie ausgelesen werden kann.

### Zugriffsarten
- Normal Mode
	- es wird die vollständige Adresse (Row und Column) übertragen
- Page Mode
	- es werden mehrere Bits von derselben Seite ausgelesen (Row muss also nur einmal übertragen werden, die Column dann mehrfach)
	- schneller als Normal Mode, da nicht jedes Mal die vollständige Adresse übertragen werden muss
- Nibble Mode
	- Adresse wird einmal übertragen (Row und Column), danach werden nacheinander die darauf folgenden Bits ausgelesen
	- schneller als Page Mode, da die Übertragung der Columns gespart wird

### Speicherbänke
Ein Speicherzugriff ist nur einmal pro einer gewissen Zeiteinheit möglich.

Deshalb werden aufeinanderfolgende Seiten auf mehrere *Speicherbänke* verteilt, die jeweils eine eigene Speichermatrix und einen Adressdekoder besitzen. Dadurch muss man die Recovery-Zeit nicht abwarten und der Datendurchsatz wird deutlich erhöht.

### Refresh
Da der Kondensator einer Speicherzelle seine Ladung nur wenige Millisekunden festhalten kann, muss der ganze Chip regelmäßig refresht werden. Deshalb werden mit einer eigenen Refresh-Logik alle Seiten regelmäßig ausgelesen und zurückgeschrieben.

### Fehlererkennung und -korrektur
Da die Ladungsmengen, welche den Speicherinhalt definieren, äußerst klein sind, können gespeicherte Bits immer mal wieder kippen. Das nennt man *Soft-Error*, da die Speicherzelle danach korrekt weiterarbeiten kann.

Fehlererkennung kann mit einem *Paritäts-Bit* passieren, welches zusätzlich in den Speicher geschrieben wird. Wird beim Auslesen ein Fehler erkannt, wird ein Interrupt ausgelöst und das Betriebssystem stoppt ggf. das Programm.

Alternativ kann man ein Datenwort als *Hamming-Code* abspeichern (z.B. benötigt ein 32-Bit-Wort 6 weitere Prüfbits).
Der resultierende Code hat eine Hamming-Distanz von 3, sodass 1 Fehler korrigiert und 2 erkannt werden können. Diese Korrektur findet dann einmal pro Refresh statt.

# Read Only Memory (ROM)
Gibt es als:
- Einmal beschreibbar (ROM)
	- Speicherinhalt wird bei Herstellung festgelegt, Speicher ist also nicht-flüchtig
- Programmierbar (PROM)
	- ist einmal programmierbar via Durchbrennen von Sicherungen (ähnlich wie bei PLAs)
	- geeignet zum Prototyping von ROMs
- Löschbar und programmierbar (EPROM)
	- durch Bestrahlung mit UV-Licht (ca. 15 Minuten) kann Inhalt gelöscht werden
	- danach wieder programmierbar
- Elektronisch löschbar und programmierbar (EEPROM)
	- Inhalt kann elektrisch gelöscht werden
	- langsamer als EPROM
- Flash Memory (wird blockweise elektronisch gelöscht)
	- USB Sticks
	- SD-Karten
	- SSDs
- Weitere nicht-flüchtige Speicher
	- MRAM
		- teuer und unzuverlässig (hohe Ausfallrate), dafür aber etwa so schnell wie SRAM
	- P-RAM
		- wird in Macs zum Speichern von Systemeinstellungen verwendet
	- F-RAM
		- ähnlich aufgebaut wie DRAM, aber so schnell wie SRAM
		- Stand 2021 gibt es keine Chips mit mehr als 16Mb
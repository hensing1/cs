Datum: 09.05.
Folien: 
[[SysInf_Kap_1_Teil_3_230311_1928.pdf|Kapitel 1.5.4 bis 1.5.9]] (ab Seite 31)
[[SysInf_Kap_2_230505_1035.pdf|Kapitel 2.1]] (bis Seite 14)

*Kapitel 1.5*
# Mehr über die JVM
## Erzeugung von Threads
Der Haupt-Thread eines Java-Programm beginnt mit der Methode `main()` (oder im Browser im Falle eines Applets).
Weitere Threads können als Objekte der Klasse `java.lang.Thread` erzeugt werden. Dort heißt die Einstiegsmethode `run()`.

Durch das Scheduling durch das Betriebssystem ist es üblicherweise so, dass die Threads nicht genau gleichmäßig bzw. mit derselben Geschwindigkeit laufen.

## Die Struktur der JVM
![[JVM-Struktur.png|600]]
Execution engine $\leftrightarrow$ CPU
Runtime Data Areas $\leftrightarrow$ Speicher

Die Speicherbereiche:
- Method Area (Methodenorientiert)
	- beinhaltet:
		- Programmcode der Methoden & Konstruktoren
		- konstante Klassenvariablen
	- wird von allen Threads gemeinsam genutzt
- Heap (Objektorientiert)
	- beinhaltet Speicher für alle Klasseninstanzen & Arrays
	- wird vom Garbage Collector aufgeräumt
	- wird von allen Threads gemeinsam genutzt
- Java Stacks
	- Jeder Thread hat seinen eigenen Call Stack
		- ein Call Stack besteht aus gestapelten Stack Frames
		- jeder Stack Frame enthält:
			- die lokalen Variablen der Methode
			- einen Operandenstack
			- eine Referenz zum Constant Pool der zugehörigen Klasse
- PC Registers
	- Jeder Thread hat seinen eigenen program counter
- Native Method Stacks
	- Eine Methode in einer anderen Programmiersprache, die also nicht zu Java Byte Code kompiliert wird, heißt Native Methode. Entsprechend hat sie ihren eigenen Speicherbereich.

Wird weiterer Source Code benötigt, wird er durch den class loader nachgeladen (?)

## Datentypen
### Primitive Types
- Integer Types
	- `byte` - 8 Bit Zweierkomplement
	- `short` - 16 Bit Zweierkomplement
	- `[char]` - 16 Bit Unicode
	- `int` - 32 Bit Zweierkomplement
	- `long` - 64 Bit Zweierkomplement
- Floating-point Types
	- `float` - 32 Bit IEEE 754
	- `double` - 64 Bit
- Rücksprungadressen
	- Für methodeninterne "Mini-Unterprogramme"
- `boolean`

### Reference Types
Eine Referenz zeigt auf eine Instanz einer Klasse, eines Interfaces, oder eines Arrays.

## Befehlssatz des Java Byte Codes
- `iconst_<i>`
	- legt die Integer-Konstante `i` auf den Stack
	- jeder wert von `m1` bis `5` hat seinen eigenen Befehl (implizite Operanden), alle anderen Werte laufen über `bipush <i>`
- `iload_<n>`
	- legt die lokale Variable mit Index `n` auf den Stack
	- implizite Operanden: `iload_0`  bis `iload_3`, danach explizite Operanden
- `istore_<n>`
	- poppt Int aus dem Stack und legt es in lokale Variable mit Index `i`
	- implizite Operanden: `istore_0` bis `istore_3`
- `iinc <i> <c>`
	- Variable (int) mit Index `i` um konstanten Wert `c` erhöhen
- `imul`
	- poppt die oberen beiden Werte vom Stack, multipliziert sie und legt das Ergebnis wieder oben darauf ab

# Vom Programm zum lauffähigen Code
## Lader und Binder
Ein Lader nimmt ein Programm in *Maschinensprache* und bereitet es für die Ausführung vor. Dabei durchläuft er die vier wesentlichen Schritte:

- Allocation
	- Zuweisung von (Haupt-)Speicherplatz
- Relocation
	- Umrechnung aller Adressangaben entsprechend der zugewiesenen Speicherbereiche
- Linking
	- Herstellung der externen Referenzen zwischen den Programmteilen
- Loading
	- Speicherung von Programm und Daten

Es gibt dabei verschiedene Varianten, wie Compiler & Lader zusammenarbeiten bzw. die Arbeit untereinander aufteilen.
- **Übersetzen und Laden**
	- Compiler bzw. Assembler schreibt Objekt-Code direkt in den Hauptspeicher
	- Lader startet nur noch das Programm
	- Nachteile:
		- Compiler blockiert Hauptspeicher
		- Vor jedem Programmlauf muss kompiliert werden
		- Wenn man mehrere Compiler koordinieren muss, wird es ggf. unmöglich
- **Allgemeine Methode**
	- Trennung von Compiler und Lader
	- Sollen mehrere Programme aus verschiedenen Programmiersprachen miteinander kooperieren, muss die Behandlung externer Referenzen untereinander kompatibel sein
- **Absolutprogramm-Lader**
	- Compiler bestimmt die Hauptspeicheradresse, in die das Programm geladen werden soll
	- Vorteile:
		- einfach zu implementieren
		- kleiner Lader $\to$ mehr Hauptspeicher verfügbar
	- Nachteile:
		- Keine Flexibilität in der Speicherverwaltung (Speicher evtl. schon belegt)
		- Externe Referenzen müssen bereits vom Compiler aufgelöst werden
- **Verschiebende Lader**
	- Ablage des Objektprogramms wird zum Ladezeitpunkt (idR. durch Betriebssystem) bestimmt
	- Der Compiler generiert zunächst also nur relative Adressen
- **Bindende Lader**
	- Ein kompiliertes Programm landet zunächst in einem Hilfsspeicher als Bindemodul
	- anschließend wird es vom Lader in Maschinensprache in den Hauptspeicher gesetzt
	- Bindende Lader sind von allen Ladern am weitesten verbreitet.
	- Da die 4 o.g. Schritte für jeden Programmlauf neu ausgeführt werden müssen, werden für Programme mit vielen Bindemodulen Binde- und Ladevorgang getrennt

### Binder
Der Binder übernimmt die ersten drei Schritte vom Lader, also Allocation, Relocation und Linking.
Im Unterschied zum bindenden Lader schreibt er den Output nicht in den Arbeitsspeicher, sondern in eine Datei ("Lademodul").
Die Adressierung erfolgt entweder mit expliziter Adressangebe, oder mit einer Verschiebetabelle bzw. einem Basisregister.

Die derart erzeugten Module werden nur im Bedarfsfall in den Hauptspeicher geladen. Zum Nachladen wird das Programm unterbrochen.

Unter Windows heißen die Lademodule *Dynamic Link Library*. Sie haben die Dateiendung `.dll`, `.ocx`, `.vxd`, `.sys` oder `.drv`.
Unter Unix heißen sie "Shared Library". 

Wenn mehrere Programme dieselbe Library verwenden, muss sie nur einmal in den Hauptspeicher geladen werden.
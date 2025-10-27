Datum: 02.05.
Folien:
[[SysInf_Kap_1_Teil_2_230311_1928.pdf|Kapitel 1.3.6 und 1.4]] (Seiten 43 bis Ende)
[[SysInf_Kap_1_Teil_3_230311_1928.pdf|Kapitel 1.5.1, 1.5.2, 1.5.3]] (Seiten 1 bis 30)

Willkommen bei Sinf, dem neuen Senf

# Der Rest zur ISA
*Kapitel 1.3.6*
## Von Assembly zum Maschinencode
Ein Assembler macht im Wesentlichen folgendes:
- Übersetzung der Keywords in Binärcode
- Umsetzung symbolischer Adressen (Label) in Speicheradressen
- Umwandlung von Literalen in Binärdarstellung

Außerdem werden "Pseudo-Operationen" (wie z.B. Auflösung externer Referenzen) verarbeitet. Weiterhin können Makros definiert werden, welche mehrere Codezeilen unter einem eindeutigen Bezeichner zusammenfassen.
Der Bezeichner wird zur Compilezeit dann durch die entsprechenden Zeilen ersetzt. Platzhalter für Parameter (ähnlich wie bei Funktionen in höheren Programmiersprachen) sind ebenfalls möglich.

*Kapitel 1.4*
# Virtuelle Maschinen
ISA: gewissermaßen virtuelle CPU, da verschiedene CPUs durch dasselbe Instruction set angesteuert werden können.
Virtuelle Maschine: Ausführungsumgebung, in welcher alle Aspekte des Systems virtuell sind: CPU, Speicher, Ein-/Ausgabegeräte, etc.

Jedes Programm erhält dabei seine eigene Instanz einer virtuellen Maschine. Die VM kann beliebig vom Hostsystem abweichen.

Vorteile: Bessere Sicherheit durch Kapselung, Sandkasten-Environment für Entwicklungsarbeiten z.B. am Betriebssystem, mehrere (verschiedene) Systeme auf derselben Hardware

Nachteile: Interprozesskommunikation erschwert, mehr Overhead

*Kapitel 1.5*
# Java und die JVM
## Java Virtual Machine
Die JVM ist eine abstrakte Rechenmaschine mit einem eigenen Befehlssatz. Javaprogramme (`.java`-Datei) werden in diesen Befehlssatz kompiliert (in eine `.class`-Datei) und laufen dann in einer eigenen Instanz einer JVM.
Eine `.class`-Datei kann entweder interpretiert werden, oder zu einem anderen Prozessorbefehlssatz kompiliert oder direkt in Hardware umgesetzt werden.

## Laufzeitinstanz
Eine JVM-Instanz erhält nach der Erzeugung den Namen der zuerst aufzurufenden Klasse.

Während der Ausführung gibt es dann verschiedene Kontrollflüsse:
- Kontrollfluss (bzw. -flüsse) der Anwendung selbst
	- Am Anfang durch die `main()`-Methode eindeutig festgelegt
- Kontrollflüsse der JVM - *"daemon threads"*
	- z.B. für die Garbage Collection

Threads können zeitlich verzahnt oder auch echt parallel ausgeführt werden. Die Anwendung kann auch Threads als daemon threads markieren.

Eine JVM-Instanz wird beendet, wenn entweder alle *Anwendungsthreads* beendet sind (daemon threads sind irrelevant), oder die `exit()`-Methode durch die Anwendung aufgerufen wird (sofern sie das darf).

## Multitasking und Multithreading

> *Multitasking*
> Mehrere Anwendungsprogramme können parallel ausgeführt werden.

> *Multithreading*
> Mehrere Threads desselben Anwendungsprogramms können parallel ausgeführt werden.

Multitasking erfordert nicht die Kooperation des Anwendungsprogrammierers. Multithreading-Anwendungen müssen entsprechend als solche programmiert werden (und das Betriebssystem muss es natürlich auch unterstützen).

Bei Multithreading-Anwendungen muss der zeitliche Ablauf sowie die Synchronisation der Threads verwaltet werden.
Um zu verstehen, wie verschiedene Threads miteinander verwoben werden können, muss man sich klarmachen:
- Welche Aufgaben parallel laufen können
- Welche Aufgaben von welchen anderen Aufgaben abhängen

Wie verschiedene Threads ineinandergreifen, kann mittels eines *Präzedenzgraphen* veranschaulicht werden:
![[Präzedenzgraph.png|500]]

In diesem Beispiel hat man vier Methoden (Collect, Log, Stat und Report), welche parallelisiert werden.


Datum: 07.11.
[[Kapitel_2-Teil-1_Processes_WS2324.pdf|Folien]] bis Seite 23

# Kapitel 2: Fortgeschrittene Konzepte der Systemprogrammierung

## Prozesse

- Jeder Prozess hat seinen eigenen virtuellen Prozessor
- Alle Prozesse laufen i.A. unabhängig voneinander

### Prozesse im Hauptspeicher

Jedem Prozess ist ein begrenzter Speicherbereich zugeordnet. Dieser Bereich teilt sich in vier Sections:
- Stack (wächst nach unten)
	- Frames für unvollendete Subroutinen/Funktionen
		- Parameter
		- Lokale Variablen
		- Returnadresse
- Heap (wächst nach oben, dem Stack entgegen)
	- Speicherbereich für dynamisch erzeugte Daten
- Data
	- globale Variablen
- Text
	- Programmcode

### System Calls
Prozesse sind (in Linux und Windows) entweder im *user-mode* oder im *kernel-mode*.
Nutzerprozesse dürfen nur ihren eigenen Speicherbereich manipulieren. Alles andere (wie Dateien lesen/schreiben, Interprozesskommunikation, etc.) dürfen nur Kernel-mode Prozesse.

> System Calls sind das Interface zwischen Nutzerprozessen und dem Kernel.

Meistens nutzt man System Calls nicht direkt, sondern benutzt z.B. die GNU C Library.

### Process Control Block
Für jeden Prozess gibt es einen solchen Block im Speicher, in dem die relevanten Infos zu diesem Prozess stehen:
- Prozessstatus
- Program Counter
- CPU-Registerinhalt
- CPU-Schedulinginformation
- Speicherverwaltungsinformation
- Geöffnete Dateien

### Context Switch

Um von einem Prozess in den anderen zu wechseln, ist ein Context Switch nötig. Der aktuelle Prozesskontext muss gesichert werden, und der Kontext des Folgeprozesses muss geladen werden.

Der Kontext ist alles, was im PCB drinsteht. Kehrt die CPU zu einem Prozess zurück, muss all diese Information in der CPU wiederhergestellt werden.
Der Prozess selbst bekommt davon nichts mit.

Während des Context Switches kann keine produktive Arbeit verrichtet werden.

> **Interrupts:**
> Damit die CPU weiß, wann ein Context Switch passieren soll, gibt es den *PIT* (Programmable Interrupt Timer) - ein extra Hardware-Bauteil, das in regelmäßigen Abständen einen Interrupt-Systemcall macht, welcher dann den nächsten Context Switch initiiert.

### Prozessstatus

Ein Prozess kann sich in einem der folgenden Status befinden:
- `New`: Prozess wird erzeugt
- `Ready`: Der Prozess wartet darauf, einem Prozessor zugewiesen zu werden
- `Running`: Instruktionen des Prozesses werden ausgeführt
- `Waiting`: Der Prozess wartet auf ein Event (z.B. auf einen Kindprozess)
- `Terminated`: Der Prozess wurde beendet

![[Prozessstatus.png]]

### Scheduling

Situation: mehrere Prozesse im Status `ready`, aber nur ein Prozessor ist frei.

Für Scheduling-Strategien, siehe [[SysInf - VL 10|Synf]].

Verschiedene Scheduler-Modelle:
- Kooperativ: Prozesse geben durch Systemcall die Kontrolle freiwillig auf (yield)
- Preemptiv: Prozess kann durch System unterbrochen werden (z.B. durch Timer Interrupt)

### Process Creation in UNIX
- Normalerweise werden Prozesse dynamisch erzeugt (mit Ausnahme von manchen embedded systems mit statischen Prozessen)
- Jeder Prozess hat eine eigene pid (Process Identifier)

Genaugenommen wird (in UNIX/Linux) jeder Prozess von einem anderen Prozess gestartet -> man erhält einen Baum aller Prozesse. In Windows ist das nicht so.

Die Wurzel ist der Init-Prozess, der als erstes vom Betriebssystem gestartet wird. Den kann man irgendwo festlegen.

#### Prozesserstellung
Es gibt verschiedene Erstellungsparameter, die von einem Betriebssystem unterstützt werden können:

- **Teilen von Ressourcen**
	- Eltern- und Kindprozesse können sich Ressourcen teilen
	- Kindprozesse können Teile der Ressourcen des Elternprozesses teilen
	- Eltern-und Kindprozesse können sich keine Ressourcen teilen
- **Ausführung**
	- Gleichzeitig
	- Elternprozess kann auf Kindprozess warten
- **Adressraum**
	- Kindprozess ist Duplikat vom Elternprozess

#### Prozessbeendung

- **Durch Prozess**
	- `exit()` sagt dem Betreibssystem, dass dieser Prozess aufgeräumt werden soll
	- mit `wait()` kann man auf Output des Kindprozesses warten
		- wenn ein Kindprozess `exit()` aufruft, wird er so lange nicht aufgeräumt, bis der Elternprozess `wait()` aufgerufen hat
- **Durch Elternprozess**
	- Bei manchen Betriebssystemen werden die Kindprozesse abgeschossen, wenn der Elternprozess terminiert
		- Bei meinem WSL-Ubuntu ist das nicht so
	- ansonsten mit `kill(child_pid, SIGKILL)` 
- **Durch Betriebssystem**
	- Kein Speicher übrig
	- Programm versucht, illegale Instruktion auszuführen
	- Programm teilt durch null
- **Durch User-Request**
	- z.B. über task manager oder `kill`


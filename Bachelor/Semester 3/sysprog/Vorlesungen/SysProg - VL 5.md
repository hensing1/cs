Datum: 14.11.
[[Kapitel_2-Teil-1_Processes_WS2324.pdf|Folien]] von Seite 24 bis Ende

# Prozesse
*Kapitel 2.1*

## Prozesse in Linux

### Prozessverwaltung in C

- Eigene pid mit `pid_t getpid();`
- Parent-pid mit `pid_t getppid();`

- `system()` führt die übergebene Anweisung mit der Standard-Shell aus
	- der exit status wird an den aufrufenden Prozess zurückgegeben
- `fork()` dupliziert den aktuellen Prozess
	- Kindprozess startet genau an derselben Stelle im Programm
	- der gesamte Speicherblock wird für den Kindprozess kopiert
	- nicht perfekt im Hinblick auf Ressourcen, aber sehr einfach für das Betriebssystem
	- Ressourcenschonende Lösung: Copy-on-write
		- BS kopiert nicht den ganzen Speicherbereich, sondern nur die Sachen die *geändert* werden
		- erst wenn der Kind- oder Elternprozess irgendwas schreibt, werden die entsprechenden Speicherstellen kopiert
- `exec*()` ruft ein externes Programm auf
	- ersetzt den aktuellen Prozess
- `exit()` beendet Prozess (erfolgreich)
- `abort()` beendet Prozess (fehlerhaft)
- mit `wait()` wartet man, bis ein Kindprozess `exit()` aufruft
	- währden der Zeit wird der Prozess nicht vom BS geschedulet

*Varianten von exec*
- `execl` - Absolutpfad und Argumente
- `execlp` - Relativpfad und Argumente
- `execle` - Absolutpfad, Argumente und Systemvariablen
Das erste mit `exec` übergebene Argument ist der Name des auszuführenden Programms.


`fork` gibt im *Elternprozess* eine neue pid zurück und im *Kindprozess* eine 0, wodurch man im Programm unterscheiden kann, ob man im Eltern- oder im Kindprozess ist.

### Signals

Prozesse sollen irgendwie miteinander reden. Durch ein Signal können spezielle Nachrichten an einen Prozess gesandt werden.

Erhält ein Prozess ein Signal, dann
- hält er mit seiner aktuellen Ausführung an,
- bearbeitet das Signal, und
- kehrt zur Ausführung zurück.

Ein Prozess kann Signalhandler definieren, wo er dem Betriebssystem sagt, welche Funktion aufgerufen werden soll, wenn irgendein Signal kommt.
Wenn er fertig, springt er direkt zurück an die Stelle, wo er vorher war.

Signale:
- SIGKILL und SIGSTOP können nicht blockiert, abgefangen oder ignoriert werden
- SIGSEGV: Segmentverletzung (segfault)
- SIGUSR1: userdefiniert, oft benutzt für sowas wie "bitte aktualisiere deine Konfiguration"
- SIGCHLD: Kindprozess ist fertig
Für Entwickler am spannendsten:
- SIGINT: Keyboard interrupt (mit Ctrl+C)
	- kann abgefangen werden! (siehe vim)

mit `kill -USR1 [pid]` kann man z.B. seinem Prozess das Signal SIGUSR1 schicken

In C:
```c
#include <signal.h>
int kill(pid_t pid, int signo);
int raise(int signo); // äquivalent zu kill(getpid(), signo);
```


### Zombies

> Ein Zombie ist ein Kindprozess, der terminiert hat, dessen Elternprozess aber nicht `wait()` aufgerufen hat.

Der Elternprozess läuft also noch, aber der Kindprozess wird nicht aufgeräumt - weil man nicht weiß, ob der Elternprozess später noch irgendwann `wait()` aufruft.

`wait` blockiert den Elternprozess.
Will man non-blocking den Kindprozess aufräumen, kann man im Elternprozess einen Handler für `SIGCHLD` definieren, der den exit status vom Kind speichert und dann den Prozess aufräumt

## Prozesstools in Linux

- Laufende Prozesse anzeigen
	- `ps`: Process status
	- `pstree`
	- `top`
		- kann sortieren
- Signale an Prozesse senden
	- `kill` (nicht nur für SIGKILL)
- Prozessausführung beeinflussen
	- `nice` / `renice`
		- zum Beispiel:
			- Ein Prozess hat einen von 40 verschiedenen Prio-Werten, die bestimmen, mit welcher Priorität er gescheduled wird
			- diese Prios kann man mit `nice` setzen
	- `&`: an Aufruf anhängen, um den Prozess im Hintergrund auszuführen
	- `<ctrl+z>`: Prozess pausieren
	- `fg`: in den Vordergrund

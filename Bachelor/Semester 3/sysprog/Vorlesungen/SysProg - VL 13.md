Datum: 23.01.
[[Kapitel_3_Netzwerkprogrammierung_WS2324_v20240112-Teil2.pdf|Folien]] ab S. 30
# I/O-Multiplexing

Die Funktionen `recvfrom()` (UDP), `accept()` (TCP), `read()` (Dateien/Sockets, auch TCP) und `fgets()` (von stdin) blockieren typischerweise, wenn noch keine neue Eingabe vorliegt. D.h., man hat *blockierendes I/O*.

Wir möchten aber trotzdem in der Lage sein:
- neue Nachrichten zu senden, während wir auf Nachrichten warten
- mehrere Sockets gleichzeitig offen zu haben
- bei TCP gleichzeitig listening sockets (für Verbindungsaufbau) und connected sockets zu bedienen

Dafür benötigen wir I/O-Multiplexing.

## Nicht-Blockierendes I/O

Wir setzen den Socket (bzw. den file descriptor) in den *non-blocking mode*. 

Das geht so:
```c
#include <fcntl.h>

// sockfd sei file descriptor eines Sockets
int flags = fcntl(sockfd, F_GETFL, 0);
int err = fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);
```

Dann fragen wir periodisch an (z.B. mit `recvfrom()` bei UDP), ob ein neues Datagramm vorliegt.

Ist ein neues Datagramm da, wird es mit `recvfrom` vom Kernel in den User Space kopiert. Ansonsten wird `EWOULDBLOCK` bzw. `EAGAIN` returnt.

*Problem*
Wir realisieren **busy waiting**, verbrauchen also unnötig CPU-Zeit, wenn wir die ganze Zeit abfragen. Das ist bei blockierendem I/O nicht so, da der Prozess in dieser Zeit schläft.

## Signalgesteuertes I/O

- Man benötigt *Signalhandler* für das Signal `SIGIO`
	- wird mit `sigaction()` eingerichtet
- Sobald Datagramm anliegt, wird Signal `SIGIO` vom Kernel gesendet
- Entweder:
	- Signal Handler ruft `recvfrom()` und holt das Datagramm vom Socket
	- Signal Handler teilt der Hauptschleife mit, dass ein Datagramm vorliegt

*Vorteile:*
- für UDP sehr leicht umzusetzen, da `SIGIO` bedeutet, dass genau 1 Datagramm angekommen ist
- Prozess kann während des Wartens andere Dinge tun

*Nachteile:*
- für TCP sehr komplex, da `SIGIO` alles mögliche bedeuten kann
- wenn der Prozess sonst nichts zu tun hat, hat man wieder busy waiting

Realbeispiel: NTP-Server (Network Time Protocol), der viel zu tun hat, aber durch das Signal den exakten Zeitstempel der Ankunft eines Datagramms herausfindet
## I/O-Multiplexing mit `select()`

Mit `select()` kann man einen Haufen File Descriptors blockierend oder nicht-blockierend abfragen. Die fd's werden in einem `fd_set` gespeichert, welches Bitflags pro File Descriptor enthält.

```c
#include <sys/select.h>
#include <sys/time.h>

int select(int maxfdp1, fd_set* readfds, fd_set* writefds, fd_set* exceptfds,
		   struct timeval* timeout);
```

- Parameter:
	- `maxfdp1`: Nummer des höchsten file descriptors plus 1, dh. Anzahl der zu prüfenden file descriptors
	- `readfds`, `writefds`, `exceptfds`: je ein *file descriptor set* mit Deskriptoren, die zum Lesen, Schreiben bzw. auf "exceptional conditions" überprüft werden sollen
	- `timeout`: Zeitintervall, für das `select()` maximal blockieren soll
		- Struct `timeval` enthält `tv_sec` für Sekunden und `tv_usec` für Mikrosekunden
		- `select()` mit leeren fdsets und konkretem Timeout wartet wesentlich präziser als `sleep()`
		- Möglichkeiten:
			- `NULL`: unendlich warten (blockierender Aufruf), bis ein fd bereit wird
			- 0: sofort zurückkehren (nicht-blockierender Aufruf)
			- konrekter Wert: blockieren, bis entweder ein fd bereit wird oder der Timeout abläuft
		- kehrt der Aufruf vor dem Ablauf des Timeouts zurück, kann `select()` den Wert von `timeout` darauf anpassen, wieviel Zeit noch übrig war.
- Rückgabewert:
	- >0: Anzahl der Deskriptoren im Zustand "ready for I/O"
	- 0: Timeout (keine bereite Deskriptoren)
	- -1: Fehler

"Ready for I/O" bedeutet, dass eine Operation wie `read()` oder `write()` auf diesem file descriptor nicht blockieren wird. 

**Ablauf**
Die Fieldsets werden von dem Aufruf von `select()` *verändert*. Sie müssen also vor jedem Aufruf neu initialisiert werden.

1. Zurücksetzen der Fieldsets mit Makro `FD_ZERO(fd_set* set)`
2. Zu überprüfende Deskriptoren hinzufügen mit Makro `FD_SET(int fd, fd_set* set)`
3. `select()` aufrufen
4. Rückgabewert überprüfen
5. Falls >0: mit Makro `FD_ISSET(int fd, fd_set* set)` alle Deskriptoren überprüfen

Ein Socket ist *bereit zum Lesen* (enthalten in der Menge `readfds`), wenn:
- neues Datagramm bzw. neue bytes zu lesen sind
- der Leseteil bei TCP geschlossen wurde (`read()` wird 0 zurückgeben)
- der listening socket ist mit einem Verbindungsaufbau fertig (`appect()` wird erfolgreich sein)
- socket error liegt vor (`read()` wird -1 zurückgeben)

Ein Socket ist *bereit zum Schreiben* (enthalten in der Menge `writefds`), wenn:
- der Sende-Buffer genug Platz hat, um weitere Daten aufzunehmen
- der Schreibteil eines Sockets geschlossen wurde
- ein nicht-blockierender Aufruf von `connect()` fertig geworden ist (erfolgreich oder fehlerhaft)
- ein socket error liegt vor (`write()` wird -1 zurückgeben)

# Serverstrukturen

Zwei Ansätze
- *Iterativ:* Alle Client-Anfragen werden hintereinander bearbeitet
- *Nebenläufig:* mehrere Client-Anfragen können gleichzeitig bearbeitet werden

Beide Ansätze können verbindungslos (UDP) und verbindungsorientiert (TCP) implementiert werden.
Nebenläufige Bearbeitung wird hier nur mit TCP betrachtet.

*Verbindungslose Implementerung*
- Keine Begrenzung der Anzahl von Clients (man hat nur einen Socket)
- weniger Overhead

*Verbindungsorientierte Implementierung*
- Ein Socket pro aktive Verbindung $\to$ Begrenzung durch Backlog und Betriebssystem-Ressourcen
- einfach zu implementieren

>[!info] Stateless vs. Stateful
>- Stateless: Server merkt sich keine Informationen zum Client
>	- typisch bei iterativ + verbindungslos
>- Stateful: Server merkt sich den Zustand nach jeder Interaktion mit Client
>	- einfach realisierbar bei verbindungsorientierten Servern für die Dauer einer Verbindung

Folie 128: Pfeil nach oben für While-Schleife fehlt


Iterativer TCP-Server:
- Anzahl der aktiven Verbindungen begrenzt auf 1
- Anzahl der wartenden Verbindungen begrenzt durch Backlog

## Nebenläufiger TCP-Server mit `fork()`

bis 132
Datum: 19.12.
[[Kapitel_2-Teil-3_IPC_WS2324.pdf|Folien]] - Seite 50 bis Ende

# Mehr Interprozesskommunikation

## FIFOs

> Ein Fifo ist eine *Named [[SysProg - VL 9#Pipes|Pipe]]*, welche im Dateisystem wohnt.

- Ein Fifo kann mit dem `mkfifo` command oder `mkfifo()` aus `<sys/stat.h>` erstellt werden
- Ein Prozess kann einen Fifo mit [[SysProg - VL 9#^fc8616|open]] öffnen:
	- Dateipfad des Fifos übergeben
	- Flags: `O_RDONLY` oder `O_WRONLY`
- Der eigentliche Datenaustausch funktioniert genau wie bei Pipes:
	- Half-Duplex
	- Beide Prozesse (Sender & Empfänger) müssen gleichzeitig laufen
	- Prozesspersistenz: Daten gehen verloren, sobald kein Prozess mehr den Fifo offen hat
- `open` blockiert, bis beide Enden der Pipe geöffnet sind
- Entfernen der Pipe mit [[SysProg - VL 9#^5a0a5b|unlink]]

Man kann mit `fcntl()` das Flag `O_NONBLOCK` für ein Fifo setzen:
![[Non-Blocking_FIFOs.png|450]]

## Message Queues (POSIX)

> Eine Message Queue ist wie ein FIFO (named pipe), nur mit Kernelpersistenz. Die lesenden und schreibenden Prozesse müssen nicht gleichzeitig laufen.
> Die Posix Message Queue hat eine eigene API und funktioniert nicht mit der files API.

- Es gibt einen Message Queue Descriptor anstelle eines file descriptors
- Der Message Queue Descriptor ist ein [[SysProg - VL 9#Posix IPC Names|POSIX IPC Name]]
- Damit der Name im Dateisystem auftaucht, muss man unter Linux extra mounten
- Man muss die real-time library linken (Linker: `-lrt` flag setzen)

**Öffnen**
```c
#include <mqueue.h>
mqd_t mq_open(const char* name, int oflag); // existierende mq öffnen
mqd_t mq_open(const char* name, int oflag, mode_t mode,
			  struct mq_attr* attr); // neue mq erstellen
```

Return den Message Queue Descriptor.
Die Funktion `Mq_open()` ist ein Wrapper für `mq_open()` aber mit Errorchecks. #bruh 

**Senden**
```c
#include <mqueue.h>
int mq_send(mqd_t mqdes, const char* msg_ptr, size_t msg_len, unsigned int msg_prio);
```

- Returnt 0 wenn ok, -1 wenn nicht
- Nachricht wird entweder komplett geschrieben oder gar nicht
- Nachricht wird nach Nachrichten mit gleicher Prio und vor Nachrichten mit niedriger Prio eingefügt
- Maximale Nachrichtenlänge wird beim Erstellen in `mq_attr` festgelegt

**Empfangen**
```c
#include <mqueue.h>
ssize_t mq_receive(mqd_t mqdes, char* msg_ptr, size_t msg_len, unsigned int* msg_prio);
```

- Liest die älteste Nachricht mit der höchsten Priorität
- Returnt mit error wenn `msg_len` kleiner als festgelegte Maximallänge, unabhängig von der tatsächlichen Nachrichtenlänge
	- Maximallänge kann mit `Mq_getattr()` herausgefunden werden
- Wenn gelesen wird, verschwindet die Nachricht aus der Queue und andere Leser können sie nicht mehr lesen

**Schließen und Löschen**
```c
#include <mqueue.h>
int mq_close(mqd_t mqdes);
int mq_unlink(const char* name);
```

Siehe [[SysProg - VL 9#^5a0a5b|Files API]].

**Nachrichten**
```c
#include <mqueue.h>
int mq_notify(mqd_t mqdes, const struct sigevent* notification);
```

Mit dieser Funktion kann sich ein Prozess dafür *registrieren*, ein Signal zu erhalten, wenn die leere Message Queue eine neue Message erhält.

Verhalten abhängig von `notification->sigev_notify`:
- `SIGEV_NONE`: Prozess wird registriert, aber kein Signal
- `SIGEV_SIGNAL`: Prozess erhält Signal `sigev_signo`
- `SIGEV_THREAD`: Bei neuer Message wird neuer Thread mit der Funktion unter `notification->sigev_notify_function` erstellt

Der Prozess muss sich nach jedem Signal neu registrieren. Es kann nur ein Prozess gleichzeitig registriert sein.
## Sockets

*Unix Domain Sockets* können für IPC verwendet werden. Die API sieht genauso aus wie bei < Netzwerksockets >.

- Full-Duplex
- Prozesspersistenz

```c
#include <sys/socket.h>
#include <sys/un.h>

struct sockaddr_un un;
un.sun_family = AF_UNIX;
strcpy(un.sun_path, "foo.socket");
int fd = socket(AF_UNIX, SOCK_STREAM, 0);
bind(fd, (struct sockaddr*) &un, size);
```

Bei socket:
- `SOCK_STREAM` für streamorientierten Socket (vgl. TCP)
- `SOCK_DGRAM` für Datagramm-orientierten Socket (vgl. UDP)

Unix Socket (Socket Stream?) praktisch für lokale Datenbanken, damit man nicht über Localhost den ganzen Netzwerkkram drumherum hat

## Posix Shared Memory

- Identisch zu shared memory bei [[SysProg - VL 6#POSIX Threads|Threads]]
- Effizienter als Pipes oder Message Queues, da Nachrichten nicht durch den Kernel müssen
- Synchronisation genauso schwer wie bei Threads (z.B. mit Posix Semaphoren, s.u.)
- Mehrere Möglichkeiten
	- Posix shared memory
	- "Memory-mapped file"
	- `/dev/zero` für "anonymous memory-mapping"
- Kernelpersistenz

### Posix Semaphores

- Konzeptionell gleich [[SysProg - VL 8#Semaphoren|Semaphoren bei Threads]]
- Zwei Geschmacksrichtungen:
	- Shared-memory-basiert (siehe Threading-Kapitel)
	- mit Name
		- selbe Namensregeln wie bei [[SysProg - VL 10#Message Queues (POSIX)|Posix Message Queues]]
		- `sem_open()` statt `sem_init()`
		- `sem_close()` und `sem_unlink()` statt `sem_destroy()`

## Signale

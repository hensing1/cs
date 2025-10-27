Datum: 12.12.
[[Kapitel_2-Teil-3_IPC_WS2324.pdf|Folien]] - Anfang bis 49

# Interprozesskommunikation (IPC)
*Kapitel 2.3*

Die Unix-IPC stellt Mechanismen für
- Kommunikation
- Synchronisation
- Event Notification
zwischen Prozessen zur Verfügung. 
Das wird benötigt, da Prozesse im Standardfall keine Ressourcen miteinander teilen (im Gegensatz zu Threads, welche im Standardfall alle Ressoucen miteinander teilen).

## Die Bäsics

Es gibt: 
- System V IPC
	- UNIX-System von AT&T von 1983
- POSIX IPC *$\leftarrow$ Sysprog*
	- POSIX ist eine Familie von IEEE-Standards für UNIX APIs
	- Wurde 1988 als Verbesserung über SysV IPC eingeführt mit etwas anderen APIs, aber ähnlichem Funktionsumfang
- D-Bus
	- High-Level-Kommunikation zwischen Desktopanwendungen

*Wie finde ich den Kommunikationspartner?*
1. Eltern/Kind-Beziehung zwischen Prozessen (ähnlich wie bei Threads)
2. Bezeichner für Kommunikationskanal
	- Netzwerkkommunikation: Host + Port
	- Dateisystem:
		- Dateipfad für Dateien
		- Dateien als Pointer (z.B. .pid files, die Process ID eines Prozesses enthalten)
	- POSIX IPC names (s.u.)
	- D-Bus namespaces

### Posix IPC Names
Der Posix-Standard definiert einen Dateipfad-Ähnlichen String als Bezeichner für einen IPC-Kommunikationskanal. Wenn dieser String mit '/' anfängt, ist er ein globaler Bezeichner.

Ob mehrere '/' erlaubt sind, was passiert wenn der Bezeichner nicht mit '/' anfängt, oder ob man ihn im Dateisystem finden kann, ist in diesem Standard nicht definiert.

In Linux wohnen diese Namen in einem virtuellen Dateisystem, das explizit gemountet werden kann.

### Persistenz

> Die Persistenz eines IPCs beschreibt, wie lange ein Objekt dieses Typs existiert.

Es gibt drei Arten von Persistenz:
1. Prozesspersistenz
	- IPC-Objekt besteht, solange es noch aktive Prozesse gibt, die darauf zugreifen
2. Kernelpersistenz
	- IPC-Objekt besteht, bis der Kernel neustartet, oder es explizit gelöscht wird
3. Dateisystempersistenz
	- IPC-Objekt besteht, bis es explizit aus dem Dateisystem gelöscht wird

| IPC | Persistenz |
| ---- | ---- |
| Pipe, Fifo | Prozess |
| Mutex, Condition Variable, Memory Semaphore, R/W Lock | Prozess |
| Message Queue, Named Semaphore, Shared Memory (Posix + System V) | Kernel |
| TPC / UDP Socket, Unix Domain Socket | Prozess |
Kommunikation über Dateien wird normalerweise nicht für IPCs verwendet, weil die Prozesse ohnehin keinen Neustart überleben.

Wenn Posix message queues, semaphoren und shared memory mit mapped files implementiert sind, dann haben sie Dateisystempersistenz.

## Kommunikation über Dateien

Unix: "Everything is a file", darunter auch Standard-Input/Output, Netzwerksockets, usw.
Die Kommunikation läuft über die *Files API*. Die Files API arbeitet mit *file descriptors*, einem Integerwert, der einer Datei zugeordnet ist.

**Öffnen**
```c
#include <fcntl.h>
int open(const char* pathname, int oflag, ... /* mode_t mode */);
```

^fc8616

`open` returnt den file descriptor, oder -1 falls etwas schiefgelaufen ist.

Folgende Flags können für `oflag` zusammenge`OR`t werden:
- `O_RDONLY`, `O_WRONLY`, `O_RDWR` (genau eine von diesen)
- `O_APPEND`: write-operationen fügen Dinge an die Datei hintenan
- `O_TRUNC`: Datei wird komplett überschrieben
- `O_CREAT`: erstelle Datei, falls sie noch nicht existiert
- `O_EXCL`: Fehler, falls `O_CREAT` übergeben wurde und Datei schon existiert

`mode`: falls `O_CREAT` übergeben wurde und Datei noch nicht existiert, werden hier die Flags für Lese/Schreibrechte der Datei gesetzt.

**Lesen**
```c
#include <unistd.h>
ssize_t read(int filedes, void* buf, size_t nbytes);
```

Liest maximal `nbytes` in den Buffer `buf` und returnt die Anzahl der Bytes, die tatsächlich gelesen wurden.
Returnt -1 wenn Fehler.

**Schreiben**
```c
#include <unistd.h>
ssizte_t write(int filedes, const void* buf, size_t nbytes);
```

Schreibt maximal `nbytes` aus `buf` ans Ende der Datei.
Returnt -1 bei Fehler oder Anzahl der tatsächlich geschriebenen Bytes.

**Schließen und Löschen**
```c
#include <unistd.h>
int close(int filedes);
int unlink(const char* path);
```

^5a0a5b

`close()` wird automatisch aufgerufen, wenn Prozess beendet.

Nach `unlink()` sind keine `open()`s mehr möglich, die Prozesse können aber noch auf die Datei zugreifen, wenn sie sie bereits geöffnet haben.
Beendet der letzte zugreifende Prozess, wird die Datei gelöscht.

**lseek**
```c
#include <unistd.h>
off_t lseek(int filedes, off_t offset, int whence);
```

Verschiebt den file pointer um `offset` (positiv oder negativ) für die nächste Lese/Schreib-Operation.
`whence`: Flag, wozu `offset` relativ ist:
- `SEEK_SET`: Anfang der Datei
- `SEEK_CUR`: aktuelle Position
- `SEEK_END`: Ende der Datei

Returnt die resultierende Position oder -1.
`lseek(filedes, 0, SEEK_CUR)` kann verwendet werden, um aktuelle Position herauszufinden.

### Mit Buffered Streams
In `<stdio.h>` finden sich mit `fopen`, `fread`, `fwrite` und `fseek` gebufferte Varianten, welche `open` etc. intern verwenden. In den meisten Fällen sollte man diese verwenden.


### File Management

Im Kernel werden die ganzen file descriptors verwaltet. Hierfür gibt es drei Arten von Tabellen:
1. File Descriptor Table
	- eine pro Prozess
	- enthält file descriptor flags, Pointer zu Eintrag in File Table
2. File Table
	- geteilt von allen Prozessen
	- enthält status flags und offsets pro Datei, Pointer zu Eintrag in V-Node Table
3. V-Node table
	- geteilt von allen Prozessen
	- enthält Berechtigungen, Dateigröße etc. pro Datei

Nach `fork()`: jeder Prozess hat eigene Descriptor Table, teilen aber den File offset. Wenn also beide schreiben (z.B. in stdout), verschachtelt sich das geschriebene, aber nichts wird überschrieben.

## Nachrichtenaustausch

Nomenklatur:
- Simplex: Datenaustausch nur in eine Richtung
- Half-Duplex: Datenaustausch in beide Richtungen möglich, aber nur eine gleichzeitig
- Full-Duplex: Datenaustausch in beide Richtungen gleichzeitig möglich

### Pipes

Pipes sind eine Half-Duplex-Methode, um Informationen von einem Prozess zu einem anderen zu schicken (in eine Richtung). Sie laufen (mit Ausnahmen) über die files API.

- Kein `lseek` möglich
- keine Synchronisation erforderlich
- Mehrere Sender/Empfänger möglich (siehe Regeln für file descriptors), aber `read` entfernt Daten aus der Pipe $\to$ ein bestimmtes Paket kann nur ein Prozess bekommen

Erstellung:
```c
#include <unistd.h>
int pipe(int fd[2]);
```

- `fd`: existierendes Array von file descriptors
- Nach Aufruf:
	- `fd[0]` für lesen
	- `fd[1]` für schreiben
- Returnt 0 bei OK, -1 bei Error

Danach kann mit `read()` und `write()` (s.o.) in die Pipe geschrieben oder daraus gelesen werden.
`read()` blockiert, wenn noch nichts am anderen Ende der Pipe geschrieben wurde.

Der Sender muss den lese-fd und der Empfänger den schreib-fd schließen.

Wenn alle Sender die Pipe geschlossen haben: `read` returnt 0 (=EOF).
Wenn alle Empfänger die Pipe geschlossen haben: `write` verursacht Signal `SIGPIPE`.

Der Kernel hat einen Pipe Buffer, dessen Größe in `PIPE_BUF` steht, was wiederum in pathconf zu finden ist.

### Umleiten: `dup` und `dup2`
```c
#include <unistd.h>
int dup(int filedes);
int dup2(int filedes, int filedes2);
```

- `dup()` gibt einen neuen file descriptor zurück, der auf dieselbe Datei zeigt wie `filedes`.
- `dup2()` schließt `filedes2`, lässt `filedes2` auf dieselbe Datei zeigen wie `filedes`, und gibt `filedes2` zurück.

### `popen` und `pclose`

```c
#include <stdio.h>
FILE* popen(const char* cmdstring, const char* type);
int pclose(FILE* fp);
```

- `popen()`:
	- `cmdstring` wird in einem neuen Prozess in einer Shell ausgeführt (`/bin/sh`), und dann wird eine Pipe dahin geöffnet.
	- `type` ist entweder `'r'` oder `'w'`. 
		- Bei `'r'` wird stdout vom Kindprozess umgelenkt, bei `'w'` wird stdin umgelenkt

Die Datei kann dann z.B. mit `fgets()` ausgelesen werden.

`pclose()` schließt die Pipe wieder.
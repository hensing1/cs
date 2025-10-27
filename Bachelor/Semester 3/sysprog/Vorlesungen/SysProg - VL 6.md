Datum: 21.11.
[[Kapitel_2-Teil-2_Threads_WS2324.pdf|Folien]] bis S. 45

# Threads
*Kapitel 2.2*

## Grundlagen

*Die Nachteile von Prozessen*
- [[SysProg - VL 9|Interprozesskommunikation]] ist vergleichsweise komplex
- Ein [[SysProg - VL 4#Context Switch|Context Switch]] dauert relativ lange

*Die Idee von Threads:* Parallelismus innerhalb eines Prozesses ermöglichen

- Beispielszenario für eine Applikation
	- ein Thread für User Interface
	- ein Thread für Berechnungen

### Grundundlagen

Threads desselben Prozesses:
- teilen sich ihren Adressraum
- haben Zugriff auf dieselben Variablen
- haben keinen eingebauten Zugriffsschutz:
	- können gegenseitig auf Ihren Stack zugreifen / ihn manipulieren
	- können gegenseitig Ihre Ausführung beeinflussen

Jeder Thread hat:
- eigene Register
- eigenen Program Counter
- eigenen Stack
- eigenen Status (executing, blocked, etc.)

teilt jedoch:
- Code
- Globale Variablen
- Geöffnete Dateien
- Kindprozesse
- Alarme und Signale
mit den anderen Threads desselben Prozesses.

**Vorteile**
- Threadwechsel ist günstiger als Prozesswechsel
- Threads können auch günstiger miteinander kommunizieren
- Können (echt) parallel auf Mehrkernprozessoren laufen
- Blockieren sich nicht gegenseitig $\to$ Anwendung wird nicht blockiert, wenn sie im Hintergrund Berechnungen durchführt
- Können sich leicht Ressourcen teilen

**Nachteile**
- Gemeinsamer Zustand - Threads können einander in die Quere kommen
- Fehler in einem Thread können alle anderen beeinflussen
	- z.B.: ein Segfault in einem Thread lässt Prozess und damit sämtliche Threads abstürzen
- Schwieriger zu synchronisieren

### User- und Kernel Threads

**User Threads** werden von einer Bibliothek auf User-Level verwaltet. Der Kernel bekommt davon nichts mit und behandelt den Prozess als single threaded.

*Vorteile:*
- einfach & schnell zu erstellen und verwalten

*Nachteile:*
- nur ein Prozessorkern für alle Threads
- Wird der Prozess blockiert (z.B. durch Syscall), werden alle Threads blockiert

**Kernel Threads** erzeugt man mittels eines Syscalls an den Kernel.

Die Vor- und Nachteile sind entgegengesetzt zu den Kernel Threads.

### Multithreading-Modelle

- *One-to-Many:*
	- Auf einem Kernel-Thread laufen mehrere User-Threads
	- Alle Vor- und Nachteile von User-Threads
	- Beispiel: GNU Portable Threads
- *One-to-One:*
	- Jeder User-Level Thread hat einen eigenen Kernel-Thread
	- Alle Vor- und Nachteile von Kernel-Threads
	- Beispiel: Linux, Windows
- *Many-to-Many:*
	- Gewisse Anzahl an Kernel-Threads
		- z.B. 16 Threads für 8-Core-Prozessor
	- User-Level-Threads werden auf Kernel-Threads gemappt
	- Früher öfter verwendet (Solaris), neuere Beispiele: Go

## Threadimplementierung in Linux

Linux unterscheidet nicht so wirklich zwischen Threads und Prozessen (abgesehen von den konzeptionellen Unterschieden).

Erstellung durch System Call mit `clone()`, was sich verhält wie `fork()` bei [[SysProg - VL 5|Prozessen]]. Dabei wird auch tatsächlich ein Kindprozess erstellt, der sich aber (je nach übergebenen Flags) Ressourcen mit dem Vaterprozess teilt.

Neu in C11: `<threads.h>` mit Support für Mutual Exclusion und so Zeug.

### POSIX Threads
- POSIX: Portable Operating System Interface für uniX
	- Familie von Betriebssystem-Standards
	- Administriert von IEEE
- POSIX Threads:
	- Standard-API für Threads:
		- erstellen
		- manipulieren
		- zerstören

Posix Threads sind in C in der Library `libpthread` mit dem Header `<pthread.h>` zu finden. Dem Linker muss man den Parameter `-lpthread` mitgeben.

#### Erstellen

```c
int pthread_create(pthread_t* thread, const pthread_attr_t* attr,
				   void* (*start_routine)(void*), void* arg);
```

- Parameter
	- `thread`: Thread Identifier
	- `attr`: Attribute des neuen Threads
	- `start_routine`: Funktion, die der neue Thread ausführen soll
	- `arg`: Parameter für `start_routine`
- Returnt: 0 wenn ok, error code sonst
- Führt intern `clone()` aus

#### Attribute

Wenn man keine Attribute möchte, kann man `pthread_create` auch `NULL` übergeben.

Ansonsten:
```c
int pthread_attr_init(pthread_attr_t* attr); // Attribut-Datenstrukturen mit
											// default-Werten füllen
int pthread_attr_destroy(pthread_attr_t* attr);
```

Attribute können gesetzt werden mit `int pthread_attr_setXY(pthread_attr_t* attr, AttrType t);` und überprüft werden mit `...getXY`, wobei `XY` durch eins der folgenden Attribute ersetzt wird:
- Detach State (s.u.)
	- `detachstate`
		- `t` ist entweder `PTHREAD_CREATE_DETACHED` oder `PTHREAD_CREATE_JOINABLE`
- Für Scheduling:
	- `schedpolicy`
	- `scope`
	- `inheritsched`
- Stackgröße und -adresse:
	- `stacksize`
	- `stackaddr`

#### Übergabe von Parametern

Über `void* arg` kann nur ein Parameter an die Funktion `start_routine` übergeben werden.

Lösung: erstelle Struct, welches sämtliche Parameter enthält. 
Achtung: es wird ein Pointer auf dieses Struct übergeben. Man muss also auf die Lebenszeit dieser Datenstruktur achten. Da sich Eltern- und Kindthread die Ressource teilen, sollte nur einer gleichzeitig auf der Ressource arbeiten / diese verändern.


#### Beenden eines Threads

1. Implizit:
	- Returnen aus der Threadfunktion
	- -> Returnwert der Threadfunktion wird zu Returnwert von diesem Thread
2. Explizit:
	- `void pthread_exit(void* value_ptr);`
		- `value_ptr` wird zum Retunwert dieses Threads
3. Durch anderen Thread im selben Prozess:
	- `pthread_cancel(pthread_t thread);`
		- wenn alle Threads für das Programmende beendet werden müssen
		- wenn das Resultat nicht mehr benötigt wird

#### Joinable/Detached

Standardmäßig ist ein Kindthread im Zustand **joinable**, das heißt man kann mit `pthread_join(pthread_t thread, void** value_ptr);` im Elternthread darauf warten und sein Ergebnis einsammeln. 
> Man sollte keinen Wert zurückgeben, der zum Stack des Kindthreads gehört. Dieser Speicher wird freigegeben, wenn der Thread fertig ist.

Ein joinable Thread *wartet*, bis der Elternthread `pthread_join` aufruft. 

Ein **detached** Thread macht das nicht. Man kann einen Thread mit `pthread_detach` detachen. Ein detachter Thread kann nicht wieder attached werden und auch nicht wieder ge`join`t werden, d.h. der Returnwert kann auch nicht ausgelesen werden.

Ein detached Thread ist also nur sinnvoll wenn:
- der Thread komplett unabhängig läuft, oder
- sein Ergebniss dem Elternprozess irgendwie anders mitgeteilt wird, z.B. über einen shared state.

#### Canceln

Ein Thread kann vom Elternthread mit `pthread_cancel` gecancelt werden.

Mit `phtread_setcancelstate` kann ein Thread sich selbst un-cancelbar machen.

Mit `pthread_setcanceltype` kann einer von zwei Cancel-Herangehensweisen ausgewählt werden:
- synchron (`PTHREAD_CANCEL_DEFERRED`, default)
	- Thread kann nur an bestimmten Punkten gecancelt werden, die mit `pthread_testcancel` festgelegt werden
- asynchron (`PTHREAD_CANCEL_ASYNCHRONOUS`)
	- Thread kann irgendwo in der Mitte angehalten werden
	- Daten, auf die zugegriffen wird, können evtl. noch in einem inkonsistenten Zustand sein

So oder so muss der Thread danach noch mit `pthread_join` eingesammelt werden.
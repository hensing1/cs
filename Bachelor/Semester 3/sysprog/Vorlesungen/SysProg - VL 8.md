Datum: 05.12.
[[Kapitel_2-Teil-2_Threads_WS2324.pdf|Folien]] von 75 bis Ende

# Threadsynchronisation
*Kapitel 2.2.3 ff.*

## Semaphoren

> Ein Semaphor ist ein *shared counter*, welcher überwacht, wieviele Threads auf eine Ressource zugreifen. 
> Er erlaubt Zugriff, wenn der counter größer als 0 ist.

Mit einem Semaphor kann man Ressourcen mit einem Erzeuger-/Verbraucherprinzip verwalten.
Ein Mutex kann mit einem binären Semaphor umgesetzt werden.

Es gibt zwei Operationen:
*Wait-Operation:*
- Wenn Counter auf 0 steht, blockiere den Caller-Thread
- Sobald der Semaphorenwert $>0$ ist, kann Thread weitermachen und Semaphor wird um 1 dekrementiert

*Post-Operation:*
- Inkrementiert den Semaphorenwert um 1

### PThread-Semaphoren

Datenstruktur: `sem_t`
Initialisierung: `int sem_init(sem_t* sem, int pshared, unsigned int value);`
- `pshared`: zeigt an, ob die Semaphore von mehreren Prozessen verwendet wird
- `value`: Initialwert der Semaphore

Zerstörung: `int sem_destroy(sem_t* sem);`

Auf Semaphore warten:
- `int sem_wait(sem_t* sem);`
	- Blockiert, wenn Semaphorenwert gleich 0
- `int sem_trywait(sem_t* sem);`
	- Blockiert nie
	- returnt 0, wenn Lock erfolgreich (Wert war größer 0)
	- returnt `EAGAIN`, wenn Lock nicht erfolgreich (Wert war gleich 0)

Semaphoren-Lock freigeben: `int sem_post(sem_t* sem);`

## Barrier

> Eine Barrier ist wie ein Semaphor ein *shared counter* zwischen Threads.
> Sie blockiert, solange ein bestimmter Schwellwert nicht erreicht ist.

Anwendungsbeispiel: mehrere Threads möchten gleichzeitig weitermachen, wenn alle Threads mit ihrer jeweiligen Aufgabe fertig sind.

Nur eine Operation: `wait()`, welche den Counter um 1 inkrementiert und blockiert, falls der Schwellwert noch nicht erreicht ist.
Falls der Schwellwert erreicht wurde, werden alle wartenden Threads freigegeben und der Counter wird wieder auf 0 gesetzt.

### PThread-Barrier

Datenstrukturen:
- `pthread_barrier_t`
- `pthread_barrierattr_t`

Initialisierung: `int pthread_barrier_init(pthread_barrier_t* restrict barrier, const pthread_barrierattr_t* restrict attr, unsigned int count);`
- `count`: Schwellwert für die Barrier

Zerstörung: `int pthread_barrier_destroy(pthread_barrier_t* barrier);`

## Read-Write Locks

> Ein Read-Write Lock ist ein Threadsynchonisierungstool zum Schutz einer geteilten Ressource.
> Es sind entweder beliebig viele Lesezugriffe oder nur ein Schreibzugriff gleichzeitig erlaubt.

Drei Operationen: `readlock`, `writelock` und `unlock`.

### PThread-Read/Write Locks

Datenstrukturen:
- `pthread_rwlock_t`
- `pthread_rwlockattr_t`

Initialisierung:
- Dynamisch: `int pthread_rwlock_init(pthread_rwlock_t* rwlock, const pthread_rwlockattr_t* attr);`
- Statisch (zur Deklarationszeit): `pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER;`

Zerstörung: `int pthread_rwlock_destroy(pthread_rwlock_t* rwlock);`

Operationen (jeweils mit `pthread_rwlock_t* lock` als einzigen Parameter):
- Erhalten eines Read Locks: `pthread_rwlock_rdlock` bzw. `tryrdlock`
- Erhalten eines Write Locks: `pthread_rwlock_wrlock` bzw. `trywrlock`
- Freigeben (unabhängig davon, ob es read oder write ist): `pthread_rwlock_unlock`

# Deadlocks

Beim Verwenden dieser ganzen Threadsynchonisierungstools muss sich vor [[SysInf - VL 9#Deadlocks|Deadlocks]] in Acht nehmen.

Es gibt Tools zur automatischen Erkennung von Deadlocks, die sind aber teuer in sachen Rechenaufwand. Es gelten die in SysInf besprochenen Kriterien für Deadlocks, die es als Programmierer zu vermeiden gilt.

# Multithreading-Ansätze

## Worker Threads

Ansatz: man hat *einen* Dispatcher-Thread, welcher bei eingehenden Aufträgen Worker-Threads erstellt und deren Ergebnisse einsammelt.
Die Worker Threads arbeiten auf geteilten Daten. 
Falls es eine große Menge an Aufgaben gibt, wird dieser Ansatz schnell teuer & komplex, er ist aber einfach zu implementieren.

## Thread Pools

Hat man mehrere, unabhängige Aufgaben, die kurzlebig sind und in großer Häufigkeit auftreten, sind Worker Threads keine gute Idee.
Anstatt dessen ist es sinnvoll, eine Handvoll im Vorhinein erstellte Threads bereit zu haben, welchen bei Bedarf diese Aufgaben zugewiesen werden.

Die eingehenden Aufträge, die gerade warten, können in einer [[Heaps#Prioritätswarteschlange|Priority Queue]] verwaltet werden.

Die Anzahl der Threads im Thread Pool kann dynamisch an die work load angepasst werden.

# Thread Safety

Code oder Codebibliotheken heißen *thread safe*, wenn sie von mehreren Threads gleichzeitig genutzt werden können, ohne dass Probleme auftauchen. 

Nicht alle Bibliotheken sind thread safe, da dies für Programmier- oder Performance-Overhead sorgen kann und oft auch nicht relevant ist. Im Zweifel in der Dokumentation nachlesen.
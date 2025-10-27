Datum: 28.11.
[[Kapitel_2-Teil-2_Threads_WS2324.pdf|Folien]] von Seite 46 bis 74

# Threadsynchronisation
*Kapitel 2.2.3*

Das Problem: Threads laufen unabhängig voneinander in keiner vorgegebenen Reihenfolge, greifen aber auf dieselben Ressourcen zu und sind ggf. von den Berechnungen anderer Threads abhängig.

> **Race Conditions**
> Das Ergebnis einer Multithreading-Anwendung kann davon abhängen, welcher Thread den Zugriff auf eine geteilte Ressource zuerst erreicht, bzw. ob zwei Threads dieselbe Ressource gleichzeitig erreichen. 
> In einem solchen Fall spricht man von einer Race Condition.

> **Kritischer Abschnitt**
> Alle Codeteile, welche auf eine bestimmte Ressource zugreifen und welche nicht parallel von mehreren Threads ausgeführt werden dürfen, bilden einen Kritischen Abschnitt.

Tannenbaums vier Anforderungen für eine gute Lösung kritischer Abschnitte:
1. Keine zwei Threads gleichzeitig in einem kritischen Abschnitt
2. Keine Annahmen über Timing (Geschwindigkeit eines Threads)
3. Kein Thread außerhalb eines kritischen Abschnittes sollte andere Threads blockieren
4. Kein Thread sollte endlos auf Zugriff auf kritischen Abschnitt warten

## Mutual Exclusion

> **Mutex-Variable**
> Eine Mutex-Variable ist eine globale Variable, welche einem *kritischen Abschnitt* zugeordnet ist.
> Ein Thread kann einen kritischen Abschnitt blockieren, indem er mit `lock()` die Mutex-Variable setzt und sie mit `free()` wieder freigibt. 
> Ist beim Aufruf von `lock()` die Variable bereits blockiert, muss der Thread warten.

`lock` und `unlock` rahmen den kritischen Abschnitt ein.

Warten mehrere Threads, nimmt das Betriebssystem irgendeinen Thread raus. Es ist also keine FIFO-Reihenfolge garantiert.

- `lock` lässt den Thread solange warten, bis die Mutex-Variable frei ist.
- `trylock` blockiert den Thread nicht. Sein Rückgabewert sagt, ob der Lock erfolgreich war oder nicht.

### PThread-Mutex

Ein *POSIX Thread* (pthread) ist ein Sprachunabhängiges Modell für parallele Ausführung von Code.
In C können pthreads mit dem `pthread.h`-Header implementiert werden.

#### Mutex-Variable

*Datenstrukturen:*
- `pthread_mutex_t` - Datentyp für Mutex-Variable
- `pthread_mutexattr_t` - Datentyp für Mutex-Attribute

*Initialisierung:*
- dynamisch: `int pthread_mutex_init (pthread_mutex_t *mutex, pthread_mutexattr_t *attr);`
- statisch: `pthread_mutex_t mutex_var = PTHREAD_MUTEX_INITIALIZER;`

*Zerstörung:*
- `int pthread_mutex_destroy (ptherad_mutex_t *mutex);`

#### Mutex-Attribut

*Initialisierung:*
- `int pthread_mutexattr_init(pthread_mutexattr_t *attr);`

*Zerstörung:*
- `int pthread_mutexattr_destroy(pthread_mutexattr_t *attr);`

PThread-Mutex-Typen
- *Normal:* zweifacher lock vom selben Thread resultiert in Deadlock (Thread wartet auf sich selbst)
- *Errorcheck:* zweifacher Lock vom selben Thread resultiert in Fehler
- *Rekursiv:* mehrfacher Lock vom selben Thread möglich, muss aber genauso oft wieder freigegeben werden
- *Default:* Betriebssystemstandard übernehmen

### Condition Variables

*Situation:* ein Thread wartet darauf, dass irgendeine bestimmte Bedingung eintritt. In dieser Zeit soll er schlafen gehen und keine Ressourcen verbrauchen. Er soll aufwachen, sobald die Bedingung erfüllt ist.

*Lösung:* Condition Variable.

- Eine Condition Variable `Y` ist *immer* an einen Mutex `X` gebunden.
	- Das liegt daran, dass die Condition Variable auf irgendeine Weise von geteilten Ressourcen abhängt. Auf geteilte Ressourcen sollte nur mit Mutexen zugegriffen werden.
- Der Mutex muss vorher mit `lock(X)` gesichert werden.
- Mit `wait(Y, X)` wird auf die CV `Y` gewartet. Der Lock auf `X` wird mit dieser Operation implizit *freigegeben*.
- Mit `signal(Y)` kann ein anderer Thread signalisieren, dass die Bedingung für `Y` erfüllt ist. Dieser Thread muss vorher einen Lock auf `X` ausgeführt haben. Dieser Lock wird durch `signal` *nicht freigegeben*.

#### PThread

- Datenstruktur für CV: `pthread_cond_t`
- Initialisierung:
	- dynamisch: `int pthread_condi_init(pthread_cond_t* cond, const pthread_condattr_t* attr);`
	- statisch: `pthread_cond_t condVar= PTHREAD_COND_INITIALIZER;`
- Zerstörung:
	- `int pthread_cond_destroy(pthread_cond_t* cond)`

##### Warten
```c
pthread_mutex_lock(&mutex);
pthread_cond_wait(&cond, &mutex);
// Signal has been received
// Do actual work here...
pthread_mutex_unlock(&mutex);
// ... or here
```

##### Warten (mit timeout)
```c
pthread_cond_timedwait(pthread_cond_t* cond, thread_mutex_t* mutex, const struct timespec* abstime);
```

- gibt `ETIMEDOUT` zurück, falls `*abstime` überschritten wird
- `*abstime` ist ein *absoluter Zeitstempel*, keine relative Zeitangabe

Beispiel: max. 5 Sekunden warten
```c
int result;
struct timespec tspec;
struct timeval tval;

pthread_mutex_lock(&mutex);
result = gettimeofday(&tval, NULL);
tspec.tv_sec = tval.tv_sec;
tspec.tv_nsec = tval.tv_usec * 1000;
tspec.tv_sec += 5;
result = pthread_cond_timedwait(&cond, &mutex, &tspec);

if (result == ETIMEDOUT) {
	printf(“Timeout!\n”);
} else {
	printf(“Signal received!\n”);
}

pthread_mutex_unlock(&mutex);
```

##### Spurious Wakeups

Es kann irgendwie vorkommen, dass Threads fehlerhaft aufwachen (spurious wakeups). Lösung:
```c
pthread_mutex_lock(&threadFlagMutex);
while(!threadFlag) {
	pthread_cond_wait(&threadFlagCondition, &threadFlagMutex);
}
pthread_mutex_unlock(&threadFlagMutex);
// Condition fulfilled – Do work!
```

Mit `timedwait` funktioniert das genauso. An dieser Stelle ist es tatsächlich sinnvoll, dass ein absoluter Zeitstempel mitgegeben wird.

##### Senden
- `int pthread_cond_signal(pthread_cond_t* cond);`
	- Weckt *mindestens einen* Thread auf, falls welche warten
- `int pthread_cond_broadcast(pthread_cond_t* cond);`
	- Weckt *alle* wartenden Threads auf


Datum: 13.06.
[[SysInf_Kap_3_230526_1204.pdf|Folien]] (Seiten 10 bis 30)

*Kapitel 3*
# Prozesse und Prozessverwaltung
## Prozesse aus Sicht des Betriebssystems

Vom Betriebssystem müssen *pro Prozess* die folgenden Parameter verwaltet werden:
- Zustand des Prozesses:[^1]
	- ready: bereit zur Ausführung, wartet auf Prozessor
	- running
	- inactive: muss auf Ereignis warten
- Program counter
- CPU-Register
- Scheduling Information (wie Priorität, Position in der Warteschlange, ...)
- Speicherverwaltung
- I/O-Status (reservierte Geräte, angeforderte Geräte, offene Files, ...)

[^1]: Sowohl Unix/Linux als auch Windows haben noch weitere Prozesszustände, diese unterscheiden sich jedoch stark voneinander

An dieser Stelle unterscheidet man auch zwischen *User space* (laufende [[Glossar#Nutzerprozess|User-Prozesse]]) und *Operating System space* ([[Glossar#Betriebssystemprozess|Prozesse vom Betriebssystem]]):

![[User_vs_OS_space.png|400]]

Prozesswechsel können durch Spezialhardware deutlich beschleunigt werden.

### Was denn Threads
Wenn Prozesse gemeinsame Betriebsmittel nutzen (Speicherplatz, Programmcode, Dateien), können Prozesswechsel beschleunigt werden. Es können also mehrere Threads (leichtgewichtige Prozesse) unter einem Nutzerprozess zusammengefasst werden. 

## Interprozesskommunikation und Synchronisation

### Mutual Exclusion
Wir haben mehrere Prozesse, die gerne auf denselben Speicher zugreifen möchten (lesender- und schreibenderweise), um zu kommunizieren.

Wird auf eine Variable im gemeinsamen Speicher zugegriffen, gibt es ggf. kritische Abschnitte, in denen nur ein Prozess Zugriff auf diesen Speicherbereich haben sollte. In diesem Abschnitt müssen andere Prozesse, die auch auf diesen Speicherbereich zugreifen möchten, warten.
Das Stichwort hierzu heißt *mutual exclusion* (wechselseitiger Ausschluss).

> [!info] Mutual Exclusion in C++ und Java
> In C/C++ wird mutual exclusion mit *mutex*en geregelt, in Java gibt es den *Monitor*: ein Softwaremodul, welches Daten (und Operationen darauf) kapselt, sodass man nur über den Monitor mit den Daten interagieren kann.
> 
> Konkret gibt es in Java das Keyword `synchronized` für Methoden. Pro Objekt (bzw. pro Klasse bei statischen Methoden) darf nur eine synchronized-Methode gleichzeitig ausgeführt werden.
> Um die Objektsperrung innerhalb einer synchronized-Methode zu umgehen, gibt es die Methode `wait()`, die alle Sperren solange aufhebt, bis der Thread durch die Objektmethode `notify()` (zufällig ausgewählter Thread) bzw. `notifyAll()` (alle Threads) wieder aufgeweckt wird.
> 
> > [!example]- Codebeispiel Java
> > ```java
> > class Monitor {
> > 	private int avail; // Anzahl verfügbarer Ressourcen
> > 	Monitor (int a) { avail = a; }
> > 	synchronized void getElem (int n, int who) { // Monitor gibt n Elemente ab
> > 		System.out.println("Client"+who+" needs "+n+", available "+avail);
> > 		while (avail < n) {
> > 			try { wait(); } catch (InterruptedException e) {}
> > 		} // try ... catch nötig wegen wait()
> > 		avail -= n;
> > 		System.out.println("Client"+who+" got "+n+", available "+avail);
> > 	}
> > 	synchronized void putElem (int n, int who) { // Monitor nimmt n Elemente zurück
> > 		avail += n;
> > 		System.out.println("Client"+who+" put "+n+", available "+avail);
> > 		notifyAll(); // Alle Wartenden können Bedingung erneut prüfen
> > 	}
> > }
> > ```

### Deadlocks
Damit ein Deadlock passieren kann, müssen die folgenden vier Bedingungen eintreten:
1. Mutual exclusion (s.o.)
2. Hold and wait: Prozesse halten ein Betriebsmittel fest, warten aber auf (mind.) ein weiteres
3. No preemption: Betriebsmittel können erst nach der Nutzung wieder freigegeben bzw. entzogen werden
4. Circular wait condition: es gibt einen geschlossenen Kreis, in dem jeder Prozess ein Betriebsmittel festhält, das der Vorgänger benötigt.

Dies sind notwendige, aber keine hinreichenden Bedingungen: derselbe Code kann, wenn die Prozesse in einer ungünstigen Reihenfolge vom Betriebssystem vergeben werden, in einen Deadlock geraten, oder eben nicht.


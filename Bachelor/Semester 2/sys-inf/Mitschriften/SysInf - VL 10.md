Datum: 20.06.
[[SysInf_Kap_3_230526_1204.pdf|Folien]]: Seite 31 bis Ende

*Kapitel 3: Prozesse und Prozessverwaltung*
# Scheduling-Strategien

Sind mehrere Prozesse im < Zustand "ready">, dann muss das Betriebssystem entscheiden, welcher Prozess zuerst laufen darf. Diese Aufgabe übernimmt ein *Scheduler*.

*Kriterien zur Beurteilung von Scheduling-Strategien:*
- Faire Aufteilung von Ressourcen
- Effizienz
	- Hohe Auslastung der Betriebsmittel
	- Wenig CPU-Zeit durch Scheduler verbraucht
- Akzeptable Antwortzeit für Benutzer
- Verweilzeit
	- Laufzeit von Hintergrundprozessen
- Durchsatz
	- Hinreichend viele Aufträge pro Zeiteinheit

Jede Scheduling-Strategie trifft einen Kompromiss aus diesen Kriterien.

## Allgemeines Prioritätenverfahren

Fast alle Scheduling-Algorithmen sind Sonderfälle des allgemeinen Prioritätenverfahrens:
- Man hat eine Menge von *Prioritätsklassen*
	- jeder Prozess wird einer solchen Klasse zugeordnet
- Betriebsmittel werden anhand der Prioritätsklassen zugeteilt.

Laufende Prozesse können im Allgemeinen auf drei Arten unterbrochen werden:
- sie sind fertig,
- sie werden durch das Betriebssystem unterbrochen (kommen zurück in den Zustand "ready"),
- sie warten auf ein Ereignis und kommen in den Zustand "inactive".

### FIFO-Strategie
Es gibt nur eine Prioritätsklasse, und Prozesse werden solange ausgeführt, bis sie entweder fertig sind oder auf ein Ereignis warten (also ohne vorzeitigen Entzug durch das Betriebssystem).

Langläufer blockieren damit das gesamte System.

### Round-Robin-Scheduling
Haupt-Eigenschaft ist *preemtive scheduling*: es gibt eine zeitliche Beschränkung bei der Ausführung. Prozesse, die nach Ablauf der Zeit nicht fertig sind, kommen zurück in die Warteschlange.

Variationen:
- Anzahl der Prioritätsklassen
	- Bevorzugung von Prozessen mit kurzer Nutzungszeit
- unterschiedlich große Zeitbeschränkungen je nach Prioritätsklasse.

### I/O-orientiert
Häufig ergibt sich eine besonders gute Auslastung des GHesamtsystems, wenn beim CPU-Scheduling die Prozesse bevorzugt werden, die ein *langsames* I/O-Gerät benötigen.

### SPT
*Shortest Processing Time First*: um die kürzeste mittlere Bearbeitungszeit zu erzielen, werden (innerhalb derselben Prioritätsklasse) diejenigen Prozesse zuerst abgearbeitet, die (voraussichtlich) die kürzeste Laufzeit haben.

### SRPT
Shortest *Remaining* Processing Time First: SPT, bei dem Prozesse unterbrochen werden können, um später laufbereit werdende Prozesse mit kürzeren Laufzeiten vorzuziehen.

> SRPT ist eine Optimalstrategie bezogen auf die kürzesten mittleren Bearbeitungszeiten.

> [!info] *Heuristik zur Schätzung der Prozesslaufzeit*
> Die Prozesslaufzeitabschätzung basiert auf historischen Daten. 
> 
> Ist $T_{i}$ der aktuelle Schätzwert und $x$ der aktuelle Messwert (CPU-Zeit im letzten Inactive-Inactive-Zyklus), dann ist $$T_{i+1}=a \cdot T_{i}+(1-a) \cdot x.$$
> Hierbei kann $a \in [0,1]$ variiert werden, um zu steuern, welches Gewicht den historischen Daten gebeben wird.

## Echtzeitscheduling

Im Echtzeitbetrieb müssen beim Scheduling auch Deadlines für Prozesse berücksichtigt werden.

Wesentliche, zu betrachtende Werte:
- Laufzeit des Prozesses
- Frühester Startzeitpunkt (wann wird er lauffähig)
- Tatsächlicher Startzeitpunkt
- Deadline

Die Restantwortzeit ist die Spanne vom jetzigen Zeitpunkt bis zur Deadline. Der Spielraum ist die Spanne zwischen voraussichtlichem Endzeitpunkt des Prozesses und der Deadline.

Visualisierung mit Gantt-Diagrammen:
![[Gantt-Diagramm.png|300]]

*Periodische Prozesse*
- werden in festen Zeitabständen neu eingeplant
- haben eine a priori bekannte Bearbeitungszeit
- haben eine Deadline, bevor sie erneut eingeplant werden.

### Einplanung nach statischen Vorab-Prioritäten
*Rate-monotonic scheduling:* Je niedriger die Periodendauer, desto höher ist die Priorität.

Kommt ein neuer Job mit kürzerer Periodendauer dazu, wird der aktuell laufende Prozess unterbrochen.

> Gibt es einen gültigen Schedule mit statischen Vorab-Prioritäten, dann liefert rate-monotonic scheduling einen solchen.

Das klappt jedoch meistens nur, wenn die Gesamt-CPU-Auslastung recht gering ist: für 10 wiederkehrende Prozesse liegt die untere Schranke, bis zu der garantiert noch ein gültiger Schedule möglich ist, bei einer Auslastung von knapp über 70%.

### Einplanung nach Antwortzeit
*Earliest deadline first:* Es gibt keine statischen Prioritäten, sondern es wird dynamisch der Job eingeplant, dessen Deadline am nächsten liegt.

> Theorie: EDF ist eine Optimalstrategie (für Einprozessorsysteme), der die Einhaltung aller Deadlines bis zu 100% Auslastung garantiert.
> Praxis: durch den Overhead beim Wechsel ist dieses Optimum nicht erreichbar.

### Einplanung nach Spielraum
Sind Deadline und (Rest-)Laufzeit bekannt, können Jobs anhand der geringsten Differenz zwischen Deadline und Laufzeitende eingeplant werden.

> Genau wie EDF ist dies eine Optimalstrategie für Einprozessorsysteme.

Unterschied: mit dieser Strategie kann vorzeitig erkannt werden, ob ein Job nicht rechtzeitig fertig wird.
Außerdem funktioniert diese Strategie bei Mehrprozessorsystemen besser als EDF, liefert aber i.A. keinen Optimalschedule mehr.

--- 

> [!info] Anomalien bei schnelleren Prozessoren
> Gibt es einen gültigen Schedule für ein System, bleibt dieser nicht zwangsläufig erhalten, wenn sich die Prozessorgeschwindigkeit erhöht:[^1] [^2]
> ![[Scheduling-Anomalie_1.png|450]]
> ![[Scheduling-Anomalie_2.png|450]]

[^1]: Kritischer Abschnitt ist hier wieder ein Abschnitt, in dem ein Prozess unter Ausschluss auf einer geteilten Ressource arbeitet.
[^2]: Mehr dazu: [computer.org](https://www.computer.org/csdl/magazine/co/2006/05/r5054/13rRUxBJhpT) (Zugriff über Uni-Netzwerk)


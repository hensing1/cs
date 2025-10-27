Datum: 06.12.
[[TI_05_Schaltwerke.pdf|Folien]] (Seiten 1 bis 24)

# Schaltwerke
Schalt**netze**: Ausgabe ist ausschließlich abhängig von der Eingabe
Schalt**werke**: Ausgabe ist abhängig von Eingabe *und* gespeichertem Zustand

Diese Zustände werden durch **Speicherglieder** gespeichert. 
Ein Speicherglied heißt auch *bistabiles Kippglied*, und in speziellen Fällen *Latch* oder *Flip-Flop*.

## RS-Kippglied
Auch bekannt als **RS-Latch**.
Man hat zwei Eingänge: Set und Reset (S und R).
Mit S setzt man den Ausgang Q auf 1. Dann kann man S wieder auf 0 setzen, aber Q bleibt auf 1.
Um Q wieder auf 0 zu setzen, setzt man R auf 1.

R=S=0 heißt *Speicherzustand*.
R=S=1 ist verboten, besonders weil der Übergang von 11 nach 00 nicht definiert ist - es entsteht ein hochfrequentes Störsignal -  solange, bis sich die Impulsfolgen sich genug verschoben haben, dass das Latch in einen stabilen Zustand übergeht (der ist dann aber eben zufällig).

Wahrheitstabelle:

| R   | S   | Q   |                 |
| --- | --- | --- | --------------- |
| 0   | 0   | Q   | Speicherzustand |
| 0   | 1   | 1   | **s**etzen      |
| 1   | 0   | 0   | **r**ücksetzen  |
| 1   | 1   | (0) | verboten        |

Umsetzung mit NOR-Gattern:
![[RS-Latch.png|300]]

Das ganze gibt es auch mit NAND-Gattern, dann muss man die Eingänge nur invertieren.

Schaltzeichen:
![[RS-Latch-Schaltzeichen.png]]

## Taktabhängige Kippglieder
Problem: Latch kann auch durch ein kurzes Störsignal (Hazard) gesetzt oder rückgesetzt werden
Lösung: man sorgt dafür, dass Signale nur dann am Latch ankommen, wenn ein Taktsignal gerade auf 1 ist - das macht man, indem man das Taktsignal mit jeweils einem UND-Gatter mit den Eingängen verknüpft.

Schaltzeichen:
![[RS-Latch-Taktgesteuert-Schaltzeichen.png]]
Die 1 gibt an, dass S und R von C gesteuert werden.

## Taktsignale
Ein Taktsignal wird verwendet zur Synchronisation von Verarbeitungsschritten.

**Taktimpulsdauer:** $\tau$
**Periodendauer:** $T$
**Taktfrequenz:** $1/T$
**Tastverhältnis:** $\tau/T$

**Taktflanke:** Übergang zw. 0 und 1 (positive Taktflanke) bzw. 1 und 0 (negative Taktflanke).
**Taktphase:** Zeitraum, in dem das Taktsignal 1 (positive Taktphase) bzw. 0 (negative Taktphase) ist.

## D-Latch
Man hat nur noch einen Eingang D. Der Zustand von D, der zum Zeitpunkt der negativen Taktflanke besteht, wird für die nächste negative Taktphase gespeichert.

Wenn das Taktsignal C=1 ist, wird der Eingang D (inklusive Hazards) an Ausgang Q weitergeleitet.

![[D-Latch.png|400]]

## RS-Master-Slave-Kippglied
Auch **RS-Flip-Flop**.

Zwei hintereinander geschaltete Latches, bei dem beim zweiten das Taktsignal invertiert ist.
Das verhindert das "Durchrutschen" von Hazards: 
Sobald das erste Kippglied abgeschaltet wird (C = 0), ist dessen Ausgabe stabil. Und genau in diesem Moment macht das zweite Kippglied auf. 
Das heißt, der Ausgang ist um eine Taktphase verzögert. Deshalb erhält der Ausgang das Symbol $\lnot$ im Schaltzeichen (man sagt auch, der Ausgang ist *retardiert*):

![[RS-Flip-Flop.png]]

Die Eingabe R=S=1 ist immer noch verboten.

### Hazards
Wenn ein Störimpuls während der negativen Taktflanke kommt, kann für die folgende Taktphase ein Fehler am Ausgang vorliegen. Außerdem können, wenn der Flip-Flop im Speicherzustand ist (R=S=0), Hazards während der positiven Taktphase immer noch den Zustand beeinflussen.

## JK-Master-Slave-Kippglied
Auch **JK-Flip-Flop**.

Modifikation vom RS-Flip-Flop: Eingang S (heißt jetzt J) ist nur dann aktiv, wenn der Ausgang gerade 0 ist. Eingang R (heißt jetzt K) ist nur dann aktiv, wenn der Ausgang gerade 1 ist.

Das hat den Vorteil, dass J=K=1 jetzt kein illegaler Input mehr ist: wenn man (während der postiven Taktphase) beides auf 1 setzt, kippt der Flip-Flop in den jeweils anderen Zustand. 

Wenn man beide konstant auf 1 lässt, kippt der Flip-Flop einmal pro negativer Taktflanke.

Wahrheitstabelle:

| **J** | **K** | **$Q_{n+1}$** |            |
| ----- | ----- | ------------- | ---------- |
| 0     | 0     | $Q_{n}$       | Speichern  |
| 0     | 1     | 0             | Rücksetzen |
| 1     | 0     | 1             | Setzen     |
| 1     | 1     | $Q_{n}'$      | Kippen     |

Wahrheitstabelle in Abhängigkeit vom gewünschten Ausgangsverhalten:

| **$Q_{n}$** | **$Q_{n+1}$** | **J**   | **K**   |
| ------- | --------- | --- | --- |
| 0       | 0         | 0   | -   |
| 0       | 1         | 1   | -   |
| 1       | 0         | -   | 1   |
| 1       | 1         | -   | 0   |

## T-Master-Slave-Kippglied
Man nimmt sich ein JK-Master-Slave-Kippglied, und stöpselt J und K zu einem Eingang T aneinander. 
Das heißt, man kann entweder kippen oder nicht kippen (wenn T=1 während der positiven Taktphase, dann kippt es zur nächsten negativen Taktflanke).

Man kann auch den Input direkt weglassen und einfach das Taktsignal als Input nehmen. Dann togglet das Ding immer mit jedem Takt.
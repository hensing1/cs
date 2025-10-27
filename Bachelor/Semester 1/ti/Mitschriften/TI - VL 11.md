Datum: 24.11.
[[TI_04_Schaltnetze.pdf|Folien]] (Seiten 28 bis 55)

# PLAs
> Ein **PLA** (Programmable Logic Array) ist ein vorgefertigter Schaltkreis, welcher einmalig auf eine beliebige Schaltfunktion programmiert werden kann.

Das ganze sieht folgendermaßen aus:
![[PLA.png|550]]

Man hat also eine Reihe von UND-Gattern, die jedes auf ein beliebiges Monom aus den Eingangsvariablen programmiert werden können.
Diese Monome können dann an den Ausgangsvariablen beliebig verknüpft werden - man kann also ein beliebiges Polynom bzw. eine DNF < bitte Link > darstellen.

Das wird programmiert, indem hohe Programmierspannungen gezielt so angelegt werden, dass an den gewünschten Stellen die Sicherungen durchbrennen und dort eine Verbindung entsteht.

# Laufzeiteffekte / Hazards
Gatter sind nicht unendlich schnell - daher kann es vorkommen, dass nicht alle Signaländerungen synchron an Folgegattern ankommen. Dadurch entstehen **Hazards**.

- *Statische Hazards*: Fluktuation von Signalen, die eigentlich statisch sein sollen
- *Dynamische Hazards*: Fluktuation von Signalen, die sich gerade verändern

Hat man ein *Taktsignal*, treten Hazards immer für einen gewissen Zeitraum nach jedem Puls auf. Wie lange dieser Zeitraum dauert, hängt von der Anzahl der Gatter ab, die hintereinander hängen.

## Visualisierung
Man kann Timing-Diagramme malen, auf dem man den Zustand jedes Ausgangs aufträgt. Man geht hierbei davon aus, dass alle Gatter dieselbe konstante Laufzeit benötigen.

## Vermeidung
Man kann Hazards umgehen, indem man das Äquivalent zu zusätzlichen Rechtecken im KV-Diagramm in seine Schaltung einbaut (hat aber in der Praxis keine große Bedeutung).

Letztendlich benutzt man hauptsächlich *synchrone Schaltungen*, welche Signale nur zu bestimmten Zeitpunkten auswerten - wenn die Hazards bereits abgeklungen sind.

# Steuersignale
Häufig hat man in Schaltungen Steuersignale, um andere Signale ein- oder auszuschalten. Ein Signal $A$ kann mit einem Steuersignal $S$ folgendermaßen steuern:
- $A$ UND $S$: $A$ wird weitergeleitet, falls $S=1$, sonst 0.
- $A$ ODER $S$: $A$ wird weitergeleitet, falls $S=0$, sonst 1.
- $A$ XOR $S$: $A$ wird weitergeleitet, falls $S=0$, sonst $A'$.

# Code-Umsetzer
> Bauteile, welche einen Code in einen anderen umwandeln

z.B. 7-Segment-Anzeigen: Umsetzung einer Binärzahl in einen 7-Bit-Code, um eine Anzeige anzusteuern.

# Multiplexer
Ein $n$:1-Multiplexer leitet genau eins von $n$ Eingangssignalen an seinen Ausgang weiter.
$n$ ist heirbei im Normalfall eine Zweierpotenz.
Um auszuwählen, welches Signal weitergeleitet werden soll, gibt es $\log_{2}n$ Steuerleitungen.

Multiplexer sind z.B. praktisch, wenn man irgendein Signal auslesen will (z.B. von einem Register).

## Beispiel: 2:1 MUX
Man hat ein Steuersignal $S$ und zwei Eingangssignale $D_{0}$ und $D_{1}$, sowie ein Ausgangssignal $Y$.
Wertetabelle:

| $S$ | $Y$   |
| --- | ----- |
| 0   | $D_0$ |
| 1   | $D_1$ |

### Schaltbilder
![[Schaltbilder_2_1_MUX.png|450]]

### Entwicklungssatz von Shannon
Mit einen 2:1-Multiplexer kann man den [[Boolesche Algebra#Entwicklungssatz von Shannon|Entwicklungssatz von Shannon]] (Fallunterscheidung) umsetzen:

$Y=SD_{1}+S'D_{0} \iff f(x_1,\ldots,x_{i},\ldots,x_{n})=x_{i}f_{x_{i}=1}+x_{i}'f_{x_{i}=0}$

Der Ausgang ist dann quasi die Komplette Funktion $f$, die Eingänge sind die *Kofaktoren*, und das Steuersignal ist die Variable, nach der man entwickelt (also ist das ganze irgendwie rückwärts).

## Multiplexer kaskadieren
Man kann auch z.B. einen 8:1 Multiplexer aus zwei 4:1 und einem 2:1 MUX, bzw. sieben 2:1 MUX zusammenbauen (die Durchlaufzeit ist dann halt nur länger).

## Realisierung beliebiger Schaltfunktionen
Mit einem 8:1 MUX kann man jede beliebige 3-Bit-Schaltfunktion realisieren: 3 Eingangsbits können insgesamt 8 verschiedene Zustände kodieren, und für jeden dieser Zustände kann man eine 1 oder 0 an den MUX legen. Man klebt quasi die rechte Spalte der Wertetabelle an die Eingäge des MUX. Die Funktionsparameter werden zu den MUX-Steuersignalen.

ABER NANU
Genau dasselbe geht auch mit einem 4:1-Multiplexer:
- 2 Parameter (sagen wir mal $s_2$ und $s_{1}$) kommen an die Steuerleitungen wie gehabt
- Hiermit kann man nun zwei Zeilen der Wertetabelle repräsentieren
- Diese zwei Zeilen können insgesamt vier Zustände haben, müssen nun aber durch nur einen Eingang repräsentiert werden:

| Zeile 1 | Zeile 2 | Wert am Eingang |
| ------- | ------- | --------------- |
| 0       | 0       | 0               |
| 0       | 1       | $S_{0}$         |
| 1       | 0       | $S_{0}'$        |
| 1       | 1       | 1               |

Also können alle Möglichkeiten abgedeckt werden.
Datum: 15.12.
[[TI_05_Schaltwerke.pdf|Folien]] (Seiten 76 bis 95)

# Mehr über Schaltwerke

> **Autonomes Schaltwerk**
> Funktioniert wie ein *Schaltwerk*, aber ohne Eingänge - produziert also eine festgelegte Reihenfolge von Ausgangssignalen

*Beispiele:*
- Binärzähler
- verkehrsunabhängige Ampelsteuerung

## Realisierung von beliebigen Schaltwerken
Man kann ein Schaltwerk aus einem PLA und einem Register zusammenbauen:
![[PLA-Schaltwerk.png|450]]

## Enable-Signal
Oft möchte man Bauteile (z.B. Register) ein- und ausschalten können. Dafür stellen diese Bauteile oft einen Enable-Eingang zur Verfügung.

### Umsetzung
Damit man nicht jedes Bit einzeln abschalten muss, möchte man im Endeffekt das Taktsignal abschalten. 
Man könnte natürlich einfach das Enable-Signal mit dem Taktsignal verUNDen, dadurch könnten aber Hazards entstehen, wenn das sich das Enable-Signal während der positiven Taktphase ändert.

> Niemals Schaltnetze in den Pfad des Taktsignals legen! (wegen Hazards)

Lösung: 
Wenn man ein (negativ getriggertes) D-Latch vorschaltet, kann das Enable-Signal erst mit der negativen Taktflanke durchrutschen - also dann, wenn es unkritisch ist. Dieses synchronisierte Enable-Signal kann man dann reinen Gewissens mit dem Taktsignal verUNDen.
![[Enable-Signal.png|300]]

## Standard-Schaltwerke
### Universalregister
Kombiniert ein Auffangregister (das speichern kann) und ein Schieberegister (das schieben kann).

Das heißt, man $n$ Ausgangsbits (die das ausgeben was gerade im Register gespeichert ist) und $n+2$ Eingangsbits ($n$, damit man parallel ins Register schreiben kann, und je ein serielles Bit um entweder von links oder rechts Daten ins Regester zu schieben).

Damit kann man folgende Dinge umsetzen:
- Datenwort der Länge $n$ speichern (Daten werden parallel geschrieben und ausgelesen)
- Durch Schieben mit 2 multiplizieren bzw. durch 2 dividieren
- Seriell-parallel-Wandlung (Daten werden bitweise in das Register geschoben)
- Parallel-Seriell-Wandlung (Daten werden parallel geladen und seriell durch Schieben ausgelesen)

Da es 4 Modi gibt (laden, rechts schieben, links schieben, speichern), braucht man 4 Steuerbits.

### Akkumulator
Kombination eines Registers und eines Addierers: Addiert den Input mit dem Wert aus dem Register. Der Output kann wieder im Register gespeichert werden.

Vor dem Register hat man noch einen MUX, mit dem man entscheiden kann, ob vom Input oder vom Addierer ins Register geladen werden soll.

### Synchrone Zähler
Beim Asynchronen Zähler ist die Verzögerungszeit $\mathcal{O}(n)$. Bei synchronen Zählern ist die Verzögerung $\mathcal{O}(1)$, da alles irgendwie parallel geschaltet ist.

### Instruktionszähler
*Instruction counter

Ein Akkumulator, bei dem ich alternativ zum Input eine 1 addieren bzw. in den Register schreiben kann.
Das ist toll, denn Befehle und Daten sind praktisch immer sequenziell im Hauptspeicher abgelegt. Die kann man mit dem Instruktuionszähler jetzt nacheinander adressieren.

Dadurch, dass man aber auch einen beliebigen Wert von außen draufaddieren kann, kann man einen **relativen Sprung** durchführen. Das ist zum Beispiel praktisch wenn man eine Schleife hat und wieder hoch an den Schleifenanfang bzw. das Schleifenende springen möchte.

Man kann den Input auch direkt in den Register lenken, dann macht man einen **absoluten Sprung** (Sprung zu einer festen Adresse im Hauptspeicher).
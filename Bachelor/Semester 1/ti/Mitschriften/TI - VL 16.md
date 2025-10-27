Datum: 13.12.
[[TI_05_Schaltwerke.pdf|Folien]] (Seiten 55 bis 75)

# Register
> Zusammenfassung von mehreren Speicherelementen (z.B. Flip-Flops), meist mit gemeinsamen Steuerleitungen. Damit kann man dann mehrere Bits (Datenworte) parallel ab- bzw. zwischenspeichern (und auch manipulieren).

## Schieberegister
Hintereinanderschaltung von ganz vielen D-Flip-Flops (taktflankengesteuert). Das heißt, bei jedem Takt wird das Eingabesignal einen Flip-Flop nach hinten geschoben.

Man hat einen Eingang, also kommen die Bits in Serie an. Hat man $n$ Flip-Flops, stehen nach $n$ Takten die $n$ letzten Bits parallel zur Verfügung (man hat einen **Seriell-parallel-Wandler**).

Das ganze gibt es auch in *bidirektionaler* Variante, die kann dann in beide Richtungen schieben.

## Frequenzteiler / Binärzähler
Wenn man das (negierte) Ausgangssignal eines D-Flip-Flops an seinen Eingang stöpselt, hat man am Ausgang das halbierte Taktsignal vorliegen.

Mit $n-1$ D-Flip-Flops (oder auch mit T-Flip-Flops) kann man damit einen $n$-Bit-**Binärzähler** machen. Dieser ist dann allerdings *asynchron*, d.h. er hat eine Durchlaufzeit von $\mathcal{O}(n)$, da alles hintereinandergeschaltet ist.
Je größer dieses $n$, desto langsamer wird die maximale Taktfrequenz, mit der ein solcher Binärzähler noch funktioniert.

## Auffangregister
(steht als "Auffangregister" im Lehrbuch, der Name ist aber nicht besonders gebräuchlich)

Bestehend aus einer Parallelschaltung von taktflankengesteuerten RS-Flip-Flops und einem Enable-Eingang. Man kann mit $n$ Flip-Flops also ein $n$-Bit-Wort in einem solchen Register abspeichern.
Bei positiver Taktflanke und positiven Enable-Signal wird der Input übernommen.

Dieses Bauteil ist eine wesentliche Komponente eines jeden Prozessors.

# Schaltwerk
> Technische Realisierung von [[Endliche Automaten|endlichen Automaten]].

Zusammensetzung:
- Speicherglieder
	- Speichert den aktuellen Zustand
- Schaltnetz
	- Bekommt ein Eingangssignal - eine Eingabe pro Takt
	- Berechnet den nächsten Zustand und das Ausgangssignal

## Mealy-Automat
> Allgemeines Schema der Realisierung eines endlichen Automaten

- Drei Bitvektoren:
	- $X$: Eingabe des Automaten
	- $Y$: Ausgabe des Automaten
	- $Z$: Zustand des Automaten
- Für Zeitpunkt $t$ ist $Z(t_n)=Z$ und $Z(t_{n+1})=Z^{+}$.
- Im Schaltnetz hat man eine Übergangsfunktion $g(X,Z)=Z^{+}$ und eine Ausgabefunktion $f(X,Z)=Y$
- Man braucht einen Startzustand $Z(t_0)$

Zum Zeitpunkt $t_n$ wird nun von außen die Eingabe $X$ und von den Speichergliedern $Z(t_n)$ als Inputs in die beiden Schaltnetze ($g$ und $f$) eingegeben. Dadurch wird durch $g$ der Zustand $Z(t_{n+1})$ berechnet, welcher im nächsten Takt in die Speicherglieder übernommen wird.

Wie schnell darf ich das Ding takten?
Die Taktperiode muss länger sein als die Summe aus:
- Zeit von Taktflanke bis zur stabilen Ausgabe der Speicherglieder
- Signallaufzeit durch Schaltnetz $g$
- [[TI - VL 15#D-Flip-Flop|Setup-Zeit]] der Speicherglieder
- plus Toleranz, da alles so ein bisschen schwankt

## Moore-Automat
> Sonderfall des *Mealy-Automaten*, bei welchem die Ausgabe lediglich vom inneren Zustand abhängt.

Man hat also $f(Z)$ statt $f(X,Z)$).
Vorteil: Hazards am Eingangssignal werden nicht an den Ausgang weitergeleitet. Wenn man viele Schaltwerke hintereinander schaltet, entstehen mit jedem neuen Glied immer längere Verzögerungen. Mit Moore-Automaten passiert das nicht.

*"Wir wollen das benutzen, um einen Computer zu steuern"*

## Visualisierung
### Zustandsfolgetabelle
Man hat links die Spalten für Zustand und Input, und rechts eine Spalte für Folgezustand (Schaltfunktion $g$) und Ausgabe (Schaltfunktion $f$).
Das kann man nun wie gewohnt mit KV-Diagramm, Quine-McCluskey usw. optimieren.

### Zustandsdiagramm
Visualisierung des endlichen Automaten durch gerichteten Graphen nach [[Endliche Automaten#Endliche Deterministische Automaten#Anschauliche Darstellung|diesem Schema]], nur eben ein bisschen anders.

- Ein Knoten repräsentiert einen Zustand
	- für die Markierung des Startzustands setzt man gerne auch einen dicken schwarzen Punkt
	- Endzustände gibt es letztendlich nicht
- An jedem Pfeil steht der entsprechende Input ($x_1x_2\ldots$), mit dem man in den Folgezustand $Z^{+}$ kommt
	- Mealy-Automat: die dabei entstehenden Ausgangsbits kommen mit an den Pfeil
	- Moore-Automat: da die Ausgangsbits nur vom Zustand abhängen, schreibt man sie in den entsprechenden Knoten rein

### Beispiel
Moore-Automat, der die *Paritätsfunktion* für einen beliebig langen Bitstring umsetzt

- Ein Eingangsbit $x$ (sequenzielle Eingabe des Bitstrings)
- Ein Zustandsbit $z$ (bisherige Eingabe hat gerade oder ungerade Anzahl von Einsen)
- Ein Ausgangsbit $y$ (siehe Zustandsbit)

**Diagramm:**
![[Paritätsautomat.png|400]]

**Zustandsübergangstabelle:**

| **$z$** | **$x$** |\|| **$z^+$** | **$y$** |
| --- | --- |-| ----- | --- |
| 0   | 0   |\|| 0     | 0   |
| 0   | 1   |\|| 1     | 0   |
| 1   | 0   |\|| 1     | 1   |
| 1   | 1   |\|| 0     | 1   |

Die Zustandsübergangsfunktion ist einfach ein XOR: $z^{+} = g(z,x) = z \oplus x$
Die Ausgabe ist identisch zum Zustand: $y = f(z) = z$

**Schaltwerk:**
![[Paritätsautomat_Umsetzung.png|400]]


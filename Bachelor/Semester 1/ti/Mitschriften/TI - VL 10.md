Datum: 22.11.
[[TI_04_Schaltnetze.pdf|Folien]] (Seiten 11 bis 27)

# MOSFETs
## Allgemeines
Ein MOSFET ist ein Transistor, also ein elektrischer Schalter. Als solcher besitzt er drei Anschlüsse: Source, Drain und Gate. Besteht zwischen Source und Gate ein ausreichendes elektrisches Potential (Threshold-Spannung, $U_{th}$), stellt der Transistor eine leitende Verbindung zwischen Source und Drain her.

Es gibt n-Kanal- und p-Kanal-MOSFETs (NMOS und PMOS). Beim NMOS ist $U_{th}$ positiv, beim PMOS negativ.

## Aufbau
![[n-Kanal-Mosfet.png|500]]
$\text{SiO}_{2}$ ist ein Isolator. Das Substrat ist (schwach) p-dotiert, die Bereiche an den Elektroden für Source und Drain sind (stark) n-dotiert.
Der PMOS sieht genauso aus, nur dass das Substrat n-dotiert ist und die anderen Bereiche p-dotiert. Bulk ist ebenfalls mit Source verbunden.

## Funktionsweise
Ein MOSFET funktioniert über Feldeffekte. Ist beim NMOS eine positive Spannung zwischen Gate und Source (bzw. Gate und Bulk), wandern durch das entstehende elektrische Feld die Elektronen nach oben und "verdrängen" dadurch die Löcher (bzw. sie rekombinieren mit den Löchern). Dadurch entsteht unter dem Isolator ein leitfähiger n-Kanal, der Source und Drain miteinander verbindet.
Die beweglichen Ladungsträger zwischen Source und Drain sind hierbei Elektronen. 
$U_{DS}$ ist hierbei positiv.[^1]

Ein PMOS funktioniert andersherum: hier ist $U_{GS}$ negativ, wodurch Löcher im n-Substrat nach oben wandern und dort einen p-Kanal bilden. Im p-Kanal sind Löcher die beweglichen Ladungsträger.

[^1]: Es gilt: $U_{GS}\geq U_{th}$ und $U_{DS} < U_{GS}-U_{th}$, damit Strom fließt.

## Schaltsymbole
### NMOS
![[NMOS-Schaltsymbol.png|250]]

### PMOS
![[PMOS-Schaltsymbol.png|250]]

# Umsetzung von Gattern
## Standardisierung
Um Transistoren zu Gattern und Gatter zu Schaltnetzen zusammenzubauen, müssen die Schaltpegel (Spannungswerte für `true` und `false`) sowie die Signallaufzeiten aller Bauteile gleich bzw. ähnlich sein.
Damit sich das ganze also berechenbar verhält, müssen alle Bauteile standardisiert sein.
Dafür gibt es Schaltkreisfamilien: z.B. TTL (Transistor-Transistor-Logic), NMOS (n-Kanal-Mosfets), PMOS (p-Kanal-Mosfets), CMOS (Complementary Mosfets - Mischung aus NMOS und PMOS).

## Signalpegel
Auf dem Weg von einem Gatter zum nächsten kann durch äußere Einflüsse (Fertigungsschwankungen, Betriebsspannungsschwankungen, Störungen von anderen Leitungen etc.) unterwegs Spannung verloren gehen.
Daher bestimmt man nicht einen bestimmten Spannungswert für 0 oder 1, sondern einen Spannungsbereich:
![[Spannungspegel.png]]

Normalerweise steht die hohe Spannung für 1 (*active high*).

Um Störspannungen zu verkraften, sind die Pegel am Eingang eines Gatters breiter als am Ausgang (die Signale werden also an jedem Gatter "aufgefrischt", und am Eingang ist der Toleranzbereich für eingehende Spannungen größer).

## CMOS-Schaltnetze
### NOT-Gatter
![[CMOS-NOT.png|350]]
Haben $x$ und 1 den gleichen Pegel, schließt der PMOS oben und der NMOS öffnet. Andersrum ist es andersrum.

### NAND-Gatter
![[CMOS-NAND.png|350]]
Zur Erinnerung: 

| a   | b   | a NAND b |
| --- | --- | -------- |
| 0   | 0   | 1        |
| 0   | 1   | 1        |
| 1   | 0   | 1        |
| 1   | 1   | 0         |

Man kann sich die Schaltung so vorstellen: oben ist durch die Parallelschaltung $\lnot a \lor \lnot b$ umgesetzt, und unten $a \land b$, aber eben negiert, da unten die 0 angeschlossen ist.

Überhaupt funktioniert diese Art von Mischgatter mit allen booleschen Funktionen, die genau eine Negation am Ausgang haben. Wenn man dann die de-Morgan-Regel anwendet, kommt man mehr oder weniger direkt auf die Konfiguration der PMOS-Gatter zwischen 1 und dem Ausgang.

## Ein- und Ausgangslastfaktor
Jedes Gatter hat einen vom Hersteller angegebenen Ausgangslastfaktor, welcher bestimmt, an wieviele Standardeingänge der Ausgang des Gatters angeschlossen werden kann. Dieser Faktor wird **Fan-out** genannt.
Für ein CMOS-Bauteil ist der Fan-out = 50.

Der Eingangslastfaktor wird als **Fan-in** bezeichnet. Ein Standard-Gattereingang hat einen Fan-in von 1. Manche Schaltungen haben für bestimmte Eingänge höhere Fan-ins, wenn der Eingang eine höhere Belastung für den vorhergehenden Ausgang darstellt. Das passiert zum Beispiel dann, wenn dieser Eingang chipintern auf mehrere Gatter verteilt wird.

Die Summe aller Fan-ins, die von einem Bauteil getrieben werden, darf den Fan-out dieses Bauteils nicht überschreiten.
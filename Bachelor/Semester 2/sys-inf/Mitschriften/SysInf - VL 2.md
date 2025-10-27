Datum: 18.04.
[[SysInf_Kap_1_Teil_2_230311_1928.pdf|Folien]]

*Kapitel 1.3*
# ISAs und Assembler
## Instruktionsarchitektur

Bei der Instruktionsarchitektur (Instruction Set Architecture, ISA) geht es darum, einen einheitlichen Maschinenbefehlssatz für verschiedene Mikroarchitekturen zu definieren. 
Ein Programm in einer Hochsprache wird dann zunächst in die ISA-Ebene kompiliert und ist dann auf jeder Hardware lauffähig, die diese ISA unterstützt. Das ISA-Programm selbst wird dann direkt in der Hardware oder durch ein Mikroprogramm ausgeführt.

*In Hardware umgesetzte ISAs:*
- ARM
- x86
	- IA-32
	- x86-64 (64-Bit Obermenge von IA-32)
- PDP-11
- ...

*(Hauptsächlich) in Software implementierte ISAs:*
- p-Code
- Java virtual machine

## Aufbau eines Maschinenbefehls
Ein Maschinenbefehl ist in [[Glossar#Bits, Bytes, Worte|Worten]] gespeichert; manchmal auch in Halb- Doppel- oder Mehrfachworten.

Er besteht im Wesentlichen aus den folgenden, aufeinanderfolgenden Komponenten:
- *Format*
	- Angabe der Länge und Positionen der einzelnen Felder
	- kann entfallen, falls Op-Code eindeutig
- *Op-Code*
- *Daten*
	- immediate: Konstanter Wert
	- implizit: durch Op-Code eindeutige Speicheradresse (z.B. Stack oder Akkumulator)
	- direkte Adressierung: Adresse des Operanden im Befehlswort
	- indirekte Adressierung: Adresse der Speicherzelle, in der sich die Adresse des Operanden befindet
- *Ziel*
	- ggf. Überdeckung: das Ergebnis soll in der Datenquelle gespeichert werden
	- ggf. Implizierung: das Ergebnis kommt in den Stack/Akkumulator
- *Folge*
	- ggf. Adresse des nächsten Befehls, falls Sprungbefehl

## Assembler

Eine Assembly-Sprache ist eine maschinenorientierte Programmiersprache, welche die binären Maschinenbefehle durch menschenlesbare Symbole darstellt.
Zusätzlich werden noch Labels für Sprungbefehle unterstützt, sowie "Pseudobefehle" (z.B. für Reservierung von Speicherplatz).

### $\alpha$-Notation
Damit wir uns von spezifischen Assembly-Sprachen abhängig machen, arbeiten wir in dieser Vorlesung mit der $\alpha$-Notation:

| Symbol        | Bedeutung                                |
| ------------- | ---------------------------------------- |
| $\alpha$      | Akkumulator bzw. dessen Inhalt           |
| $\rho(i)$     | Inhalt der Speicherzelle mit Adresse $i$ |
| $+,-,\cdot,/$ | Erlaubte Operatoren                      |

Zusätzlich erlaubt sind Labels für Zellen des Datenspreichers oder des Programmspeichers.

*Wertzuweisung:*
$\rho(i) := \rho(j)$, oder
$\rho(i) := \rho(j) \text{ op } \rho(k)$
$\text{op}$ ist hierbei einer der vier erlaubten Operanden. 

*Bedingter Sprungbefehl:*
$\text{if } \alpha=0 \text{ then goto }j;$

*Unbedingter Sprungbefehl:*
$\text{goto } j;$

Statt $j$ kann in beiden Fällen auch ein Label verwendet werden.

Zusätzlich hat man einen *Stack* $\sigma$ mit einem *Stackpointer* $\tau$.

- $\text{push}$: der Aktuelle Inhalt des Akkumulators wird auf den Stack gelegt. $\tau$ wird um 1 erhöht.
- $\text{pop}$: das oberste Stack-Element wird auf den Akkumulator gelegt. $\tau$ wird um 1 erniedrigt.
- $\text{stack op}$: die beiden obersten Stack-Elemente gepoppt, durch $\text{op}$ verknüpft und wieder auf den Stack gelegt. $\tau$ wird insgesamt um 1 erniedrigt.

## Adressierung
Ein Maschinenbefehl kann prinzipiell beliebig viele Adressen enthalten. In der Praxis werden aber nur Befehle mit wenigen Adressen verwendet weil:
- je größer der adressierbare Speicherbereich, desto länger die Adresse, und
- je mehr Operanden, desto langsamer die Bearbeitung.

*3-Adress-Format:* Zwei Quell- und eine Zieladresse
*2-Adress-Format:* Zwei Quelladressen, die Zweite wird überschrieben
*1-Adress-Format:* Eine Quelladresse, welche überschrieben wird

Je weniger Adressen man auf einmal verwenden kann, desto länger wird ggf. das Programm. Bei Maschinen, die nur wenige Adressen zulassen, muss man mehr im Akkumulator zwischenspeichern bzw. den Stack verwenden.
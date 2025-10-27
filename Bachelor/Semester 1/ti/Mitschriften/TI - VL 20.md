Datum: 17.01.
[[TI_06_Register_Transfer_Entwurf.pdf|Folien]] (Seiten 20 bis Ende)

# Mikroprogrammierung
Ein Steuerwerk lässt sich auf verschiedene Arten umsetzen. Eine Möglichkeit ist ein "fest verdrahtetes" Steuerwerk. Dieses ist dann sinnvoll, wenn man ein Bauteil mit einer sehr spezialisierten Funktion haben möchte, welches für seine komplette Lebensdauer nur einen Ablauf haben soll.

## Mikroprogrammiertes Steuerwerk

Ein **mikroprogrammiertes Steuerwerk** ist eine flexiblere Alternative zum fest verdrahteten Steuerwerk.
Es besteht aus einem *ROM* und einem *Adressregister*.

Das Adressregister enthält den Zustand des Steuerwerks (äquivalent zum Zustand eines Mealy-Automaten).

Die Adressierung des ROMs erfolgt über das Adressregister, plus weitere eventuelle Statusvariablen, die als Input von außen kommen.
An jeder Adresse des ROMs steht dann:
- Der Folgezustand für das Adressregister
- Die Steuervariablen (der Output des Steuerwerks)

Alles in allem ist im ROM also ein *Mikroprogramm* gespeichert, welches an jeder Adresse eine *Mikroinstruktion* enthält, die wiederum die Steuersignale und den Folgezustand speichert.

### Problem
Die Größe des ROMs wächst exponentiell mit der Anzahl Input-Bits. Wenn also ein weiteres Status-Bit als Input dazu kommt, verdoppelt dies die Anzahl der benötigten Speicherstellen im ROM - selbst dann, wenn dieses Status-Bit für die meisten Zustände einen Don't-Care-Term darstellt.

### Kodierung der Ein- und Ausgänge
Durch einen Encoder können, wenn bestimmte Kombinationen der Eingangsbits nicht vorkommen können, die Statusvariablen auf eine minimale Anzahl an Adressierungsbits reduziert werden. Jedes eingesparte Bit reduziert die Größe des benötigten ROMs um die Hälfte.

Wenn nicht alle möglichen Belegungen der Ausgangsvariablen benötigt werden, können mit einem Decoder analog zu den Eingangsvariablen Ausgangsbits eingespart werden.

Problem mit dieser Lösung: man verliert wieder an Flexibilität, da wieder ein Schaltnetz für Encoder und Decoder benötigt wird.

## Adressmodifizierendes Steuerwerk
Grundidee:
- Die Adressierung des ROMs erfolgt nur noch über den Zustand des Automaten, nicht mehr direkt über Statusvariablen
- Aufeinanderfolgende Zustände liegen sequenziell, d.h. direkt hintereinander im ROM
- Absolute Sprünge (zu einer bestimmten Adresse) werden ausgeführt, wenn bestimmte Bedingungen erfüllt sind - ansonsten wird die Adresse einfach um eins hochgezählt

Der Speicherinhalt an einer Adresse im ROM teilt sich in drei Bereiche:
- Die Adresse des Folgezustands (für einen absoluten Sprung)
- Kontrollflussvariablen, welche steuern, ob abhängig von den Statusvariablen ein absoluter Sprung durchgeführt werden soll
- Steuervariablen, welche den Output des Steuerwerks bilden

Die Kontrollflussvaraiblen bilden den Input für einen Multiplexer, an dessen Eingängen die Statusvariablen hängen. Der Output von diesem Multiplexer geht zu einem weiteren Multiplexer, der entweder die Adresse aus dem ROM oder die um eins inkrementierte aktuelle Adresse an das Adressregister weiterleitet.

Die Daten in einer Adresse lassen sich mit einer Mikroinstruktion beschreiben.

Beispiel:
![[Adressmodifizierendes Steuerwerk.png]]

Wichtige Einschränkung: 
Es kann nicht jeder beliebige Mealy-Automat in ein adressmodifizierendes Steuerwerk umgewandelt werden, da nur maximal zwei Zuständsübergänge pro Zustand realisiert werden können (einmal der absolute Sprung und einmal der Inkrement).
Außerdem kann nur eine Sprungbedingung gleichzeitig ausgewertet werden (sowas wie `L0 && B1` müsste vorher (außerhalb vom Automaten) zu einer Variable zusammengefasst werden, damit es im Multiplexer angewählt werden kann).

## Umsetzung
Von der Spezifikation bis zur Implementierung eines Steuerwerks können verschiedene Möglichkeiten gewählt werden:
- Spezifikation: Zustandsdiagramm oder Mikroprogramm
- Sequenzkontrolle: Festverdrahtete Zustandsübergangsfunktion oder Mikroprogramm-Adresszähler
- Logische Repräsentation: Boolsche Gleichungen oder Wahrheitstabellen
- Implementierungstechnik: per PLA oder mit ROM
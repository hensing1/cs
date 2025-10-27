Datum: 27.06.
[[SysInf_Kap_4_230311_1948.pdf|Folien]] bis Seite 32

*Kapitel 4*
# Speicherverwaltung und Dateisystem

## Speicherverwaltung

> *Schutz vor Zugriff auf fremde Speicherbereiche*
> Um zu gewährleisten, dass ein Prozess nur auf den ihm zugewiesenen Speicherbereich zugreift, muss
> - das Basisregister vor Modifikation geschützt sein, und
> - das Displacement in zulässigem Bereich sein (größer/gleich 0, kleiner/gleich Größe des Speicherbereichs).

### Partitionierung des Hauptspeichers
Jeder Prozess braucht seinen eigenen Speicherbereich; hierfür muss der Hauptspeicher partitioniert werden.

Varianten hierfür:
- Statische Partitionierung: Prozessen werden geeignete, vorher festgelegte Partitionen zugeordnet
	- geringer Verwaltungsaufwand
	- schlechte Speicherplatzausnutzung
	- Warteschlangen für Prozesse: entweder getrennt (pro Partition) oder eine gemeinsame
- Variable Partitionierung
	- Hoher Verwaltungsaufwand
	- bessere Speicherplatzausnutzung
	- Bei häufigem Prozesswechsel kann Hauptspeicher zerstückelt werden (fragmentation)
		- Prozesse können in diesem Fall unterbrochen und verschoben werden
	- Verwaltung, welche Speicherbereiche frei bzw. belegt sind
		- Via Bitmap: Einteilung des Speichers in Bereiche gleicher Länge - jeder Bereich erhält einen Flag in der Bitmap
		- Via verketteter Liste: zusammenhängede Speicherbereiche (welche komplett frei bzw. belegt sind) erhalten einen Eintrag in der verketteten Liste

Algorithmen zur Vergabe von Speicherplatz:
- First fit
	- Beginne die Suche bei Adresse 0 und wähle den ersten Bereich, der groß genug ist
- Next fit
	- Beginne Suche bei der aktuellen Position und wähle den ersten Bereich, der groß genug ist
- Best fit
	- Suche den kleinstmöglchen Bereich heraus, in den der Prozess hineinpasst
	- Nachteil: lange Suchzeit und schlechte Speichernutzung wegen kleiner, nutzloser Lücken
- Worst fit
	- Suche größten freien Bereich heraus
	- Vorteil: keine kleinen freigelassene, nutzlose Bereiche (??)
	- Nachteil: Vernichtung großer Bereiche -> schlecht für Prozesse mit hohem Platzbedarf

### Swapping

> [!abstract] *Swapping*
> Beim Swapping werden Prozesse komplett in den Hintergrundspeicher verlagert, um bei Bedarf wieder in den Hauptspeicher zurückgeholt werden zu können.

Swapping ist nützlich, wenn:
- der Hauptspeicher zu klein ist, oder
- Prozesse unterbrochen werden, oder
- längere Zeit auf I/O-Geräte gewartet wird und der Hauptspeicher währenddessen für etwas anderes genutzt werden soll.

### Virtueller Speicher

Problem: das Programm passt nicht komplett in den Hauptspeicher.
Lösung: **Speicherhierarchie**. Man teilt den Speicher in *Seiten* ein. Speicherinhalte zwischen Hierarchien werden dann seitenweise ausgetauscht.

Wegen dieser Einteilung in Seiten spricht man von **Paging**. Durch Paging kann ein *virtueller Speicher* realisiert werden, welcher aus Sicht des Programms wesentlich größer ist als der Hauptspeicher.

Die Speicherhierarchie teilt sich grob ein in:
- CPU-Register und [[TI - VL 23#Caches|Caches]] (sehr klein, extrem schnell)
- Hauptspeicher (klein, schnell)
- Hintergrundspeicher (groß, langsam)

Eine Datenstruktur, die sich dieses Paging zunutze macht, ist der [[Algo I - VL 8#B-Bäume|B-Baum]].

#### Seitentabelle
Seiten werden in einer Seitentabelle verwaltet, wo pro Seite drinsteht, wo die Seite gerade ist, ob sie verändert wurde, wer drauf zugreifen darf, usw.
Ein Eintrag in einer Seitentabelle sieht typischerweise so aus:
- Valid/Invalid-Bit:
	- ist dies eine gültige Seitennummer des aktuellen Prozesses?
- Referenced-Bit:
	- Wurde seit dem Rücksetzen dieses Bits auf die Seite zugegriffen?
- Modified-Bit:
	- Wurde die Seite im Hauptspeicher verändert? Falls ja: Seite muss im Hintergrundspeicher gesichert werden.
- Protection:
	- Flags für Zugriffsberechtigungen (z.B. Lesen/Schreiben/Ausführen)
- Present/Absent-Bit:
	- Ist die Seite gerade im Hauptspeicher?
- Page frame number (z.B. 32 Bit):
	- Nummer des Seitenrahmens

#### Paging
Für Paging muss:
- die logische (virtuelle) Adresse des Seitenrahmens, der die Seite enthält, in eine physische übersetzt werden, und
- ggf. die Seite in den Hauptspeicher nachgeladen werden.

Sei $N$ die Menge der adressierbaren Seiten im logischen Adressraum und $M$ die Menge der physischen Seitenrahmen. Dann beschreibt die Funktion $f_{t}: N \to M \cup \set{\bot}$ mit $$f(i)=\left\{\begin{align*}j&\text{, falls Seite }i \text{ zum Zeitpunkt }t \text{ im Seitenrahmen }j \text{ ist}\\\bot&\text{ sonst}\end{align*}\right.$$
formell die Adresszuordnung, wobei die logische Adresse $(i,w)$ auf die Adresse $(f_{t}(i),w)$ abgebildet wird. $w$ ist die Speicheradresse innerhalb der Seite (Offset).

Eine Seite ist einem Prozess entweder vollständig oder gar nicht zugeordnet.

Meistens gibt es *pro Prozess eine Seitentabelle* mit ggf. Millionen von Einträgen. 

> *Translation Look-aside Buffer (TLB)*
> Der TLB ist ein Spezialspeicher, welcher einen Teil der Seitentabelle enthält. Er arbeitet ca. 10-mal so schnell wie der Hauptspeicher.
> Bei einem Seitenzugriff wird die Seitenzahl zunächst im TLB gesucht (nicht durch Adressierung, sondern durch parallelen Vergleich der Seitenzahl mit dem Inhalt der Speicherzellen). Bei einem TLB miss wird im Rest der Seitentabelle im Hauptspeicher gesucht.

Eine Seitentabelle kann sehr groß werden. Dann muss ggf. die Seitentabelle selbst gepaged werden.
Dann hat man eine zwei- oder auch dreistufige Hierarchie. Die logische Adresse unterteilt sich dann in mehrere Bereiche, die jeweils einen Offset in der darunterliegenden Seitentabelle darstellen:
![[paging_paging.png|400]]

Die Seitentabelle kann mit einer [[Hashing#Verkettete Liste|Hashtabelle (mit verketteter Liste)]] realisiert werden.

### Segmentierung
Segmente aus Programmierersicht (wie Stack, Methoden, etc.) werden auch in der eigentlichen Speicherorganisation umgesetzt, um unerlaubte Speicherzugriffe zu verhindern: es gibt eine **Segement-Tabelle**, welche Anfangsadresse (Base) und Größe (Limit) jedes Segments speichert. 

Die logische Adresse enthält also einen Selector für das zugehörige Segment, und einen Offset innerhalb dieses Segments. Bevor die Umrechnung in die logische Adresse erfolgt, wird erst die logische Adresse über die Segmenttabelle in eine *lineare Adresse* umgerechnet. Dabei wird auch geprüft, ob der Zugriff die Grenze des Segments nicht überschreitet. 
Schließlich wird die lineare Adresse über die Seitentabelle in die physische Adresse umgerechnet (s.o.).
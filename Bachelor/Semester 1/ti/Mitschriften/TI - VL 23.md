Datum: 26.01.
[[TI_08_Rechnerstrukturen.pdf|Folien]]

# Rechnerstrukturen
> Apple kommt ihm nicht ins Haus

![[Glossar#Rechnerklassifikation nach Flynn]]

## Einteilung von Instruction Sets
Viele und komplexe Befehle: CISC (Complex Instruction Set Computer)
Wenige und einfache (elementare) Befehle: RISC (Reduced Instruction Set Computer)

Auf einem CISC können Befehle gerne mal mehrere Takte dauern, da Maschinenbefehle in mehrere Mikroinstruktionen werden müssen.

In einem RISC werden Instruktionen effizienter ausgeführt, und man kann eine Pipeline nutzen. Dadurch sind RISCs insgesamt schneller als CISCs (heutzutage werden so ziemlich überall RISCs verwendet).

## Caches
> **Grundkonzept**
> Ein DRAM-Hauptspeicher ist um einiges langsames als die Arbeitsgeschwindigkeit einer modernen CPU. 
> Ein Cache dient als Zwischenspeicher, welcher Daten in räumlicher Nähe zur CPU mit schnellen SRAM-Speicherzellen speichert, wodurch die Zugriffszeiten wesentlich verkürzt werden.

Es entsteht also eine Speicherhierarchie - vom L1-Cache (höchste Geschwindigkeit, kleinstes Speichervolumen) über L2-Cache, über Hauptspeicher, zum Permanentspeicher (niedrigste Geschwindigkeit, höchstes Speichervolumen).

Zwischen zwei dieser Ebenen werden Daten in Böcken ausgetauscht. Ein Block ist die kleinste Datenmenge, die in einer Ebene vorhanden oder nicht vorhanden sein kann.
Ist ein gesuchter Block im angeforderten Speicher vorhanden, spricht man von einem *hit*. Falls nicht, hat man einen *miss*, und man muss im Speicher in der Ebene darunter danach suchen.

Man macht sich also *zeitliche Lokalität* zunutze (dass man ein kürzlich genutztes Datum bald möglicherweise noch einmal braucht), sowie *räumliche Lokalität* (verwandte Daten, die gemeinsam benötigt werden, liegen im Speicher nah beieinander - sei es sequenziell angeordneter Programmcode, oder Speicherstrukturen wie Arrays oder Objekte).

Da der Cache kleiner ist als der Hauptspeicher, muss man sich überlegen, wie man die Speicheradressen einander zuordnet.

### Direct Mapped Cache
Jede Speicheradresse aus dem Hauptspeicher wird genau einer Speicherstelle im Cache zugeordnet, z.B. anhand der unteren $n$ Adressbits. Hat der Cache also $2^n$ Speicherstellen, bekommt eine Adresse $a$ die Cache-Stelle $a \!\!\mod 2^n$ zugeordnet.
Die restlichen Bits der Adresse werden im Cache zusammen mit den Daten als *tag* abgelegt. Dieser tag wird beim Lesen mit dem oberen Teil der Adresse verglichen, um festzustellen, ob man einen hit hat.
Zusätzlich gibt es ein Valid-Bit, welches anzeigt, ob die Speicherstelle überhaupt gültige Daten enthält. Dieses wird im kompletten Cache beim Einschalten auf 0 gesetzt.

Beim Lesen werden bei einem Miss die Daten in der entsprechenden Cache-Zeile abgelegt, damit sie später zur Verfügung stehen.
Beim Schreiben werden die Daten zuerst in den Cache geschrieben. Um die Daten dann mit dem Hauptspeicher konsistent zu halten, gibt es verschiedene Strategien:

*Write-Through*
Die Daten werden direkt in den Hauptspeicher zurückgeschrieben

*Write-Back*
- Die Daten werden erst dann zurückgeschrieben, wenn der Platz im Cache für etwas anderes gebraucht wird
- Anhand eines Dirty-Bits wird beim Überschreiben festgestellt, ob der überschriebene Inhalt in den Hauptspeicher zurückkopiert werden muss
- Write-Back ist das effizientere Verfahren, jedoch insbesondere bei Mehrprozessorsystemen aufwändiger, bei welchen jeder Prozessor seinen eigenen Cache hat

**Blockgröße**
Um die räumliche Lokalität hauszunutzen, umfasst ein Block mehrere Worte (z.B. vier). Es werden also immer vier Worte gemeinsam zwischen Hauptspeicher und Cache hin- und hergeschoben.
Ein Wort besteht wiederum aus mehreren Bytes.

Eine Byte-Adresse teilt sich also (im realen Beispiel des MIPS-Prozessors) auf in:
- Tag (16 Bit)
- Index (12 Bit)
	- Zeile im Cache (hat $2^{12}=4096$ Zeilen)
- Word Offset (2 Bit)
- Byte Offset (2 Bit)

### Mehrweg-Cache
Ein Mehrweg-Cache besteht quasi aus mehreren parallel geschalteten Direct Mapped Caches. 
Hat man also einen 4-Wege-Cache, kann ein gesuchtes Wort in einem von vier Cache-Blöcken stehen. Ist es dort nicht vorhanden, muss einer dieser vier Blöcke verdrängt werden. Welchen man verdrängt, kann durch verschiedene Strategien entschieden werden.

Es kann natürlich trotzdem vorkommen, dass sich Datenwörter aus dem Hauptspeicher die ganze Zeit gegenseitig verdrängen. Dagegen gibt es Assosiative Caching, das ist aber teuer & aufwändig.

## Pipelining
Man teilt die Befehlsphasen eines Prozessors auf eigene Einheiten auf. Dadurch kann für den nächsten Befehl schon gefetcht werden, während der aktuelle noch decodet wird.
Die Latenz bleibt gleich, aber der Durchsatz wird um den Faktor der Pipeline-Stufen erhöht.

![[Pipelining.png|600]]

Es kann sein, dass sich durch Pipelining die Latenz erhöht, da mehr in Registern zwischengespeichert werden muss.

### Pipeline Hazards
Wenn man einen Branch-Befehl hat, weiß man in der Pipeline nicht vor dem Befehl, was man reinstopfen soll.

Zwei Lösungen:
- NOP-Befehle, bis der Branch-Befehl fertig ist
	- Entweder durch Hardware nach jedem Sprungbefehl, oder durch Software (den Compiler)
- Man lädt spekulativ die (erwarteten) nächsten Zeilen in die Pipeline
	- wenn man falsch liegt, muss man die Pipeline flushen


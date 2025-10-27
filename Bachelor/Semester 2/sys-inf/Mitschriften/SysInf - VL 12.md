Datum: 04.07.
[[SysInf_Kap_4_230311_1948.pdf|Folien]] - Seiten 33 bis Ende

*Kapitel 4: Speicherverwaltung und Dateisystem*
# Virtueller Speicher
## Behandlung von Seitenfehlern

> **Seitenfehler**
> Versuchter Zugriff auf eine Seite, die sich gerade nicht im physischen Speicher befindet.

Um auf den Inhalt einer Seite zuzugreifen, muss diese gerade im Hauptspeicher sein. Hat man also einen Seitenfehler, muss man sich entscheiden, welche Seite verdrängt werden soll, damit die Seite mit dem angeforderten Inhalt Platz hat.

Prozedur beim Nachladen:
1. Lege den zugehörigen Prozess still.
2. Finde die gesuchte Seite im Hintergrundspeicher.
3. Suche nach einem freien Seitenrahmen im Hauptspeicher.
	- gibt es keinen, dann muss eine Seite rausgeworfen werden. Diese wird in den Hintergrundspeicher verschoben, und die Seitentabelle wird aktualisiert.
4. Lade Kopie der fehlenden Seite in den Hauptspeicher und aktualisiere die Seitentabelle.
5. Starte den Prozess wieder.

Wurde die auszulagernde Seite nicht verändert (dirty bit nicht gesetzt), dann kann sie einfach überschrieben werden.

> *Mittlere effektive Zugriffszeit*
> $$\text{MeZ}=(1-p)\cdot t_{\text{Speicherzugriff}} + p \cdot t_{\text{Seitenfehler}}$$
> wobei $p\in [0,1]$ die Wahrscheinlichkeit für das Auftreten eines Seitenfehlers ist.

$t_{\text{Speicherzugriff}}$ liegt bei Hauptspeichern im Bereich von 10 bis 200 Nanosekunden (also $10^{-8}$ Sek).
Hat man eine Festplatte, dann ist $t_{\text{Seitenfehler}}$ meist im Millisekundenbereich (also $10^{-3}$ Sek).

Mit $p=0.001$ ist $\text{MeZ}=0.999 \cdot 200 \text{ns} + 0.001 \cdot 8000000 \text{ns} \approx 8200 \text{ns}\Rightarrow$ Verlangsamung um etwa Faktor 40.

### Algorithmen zur Seitenersetzung
*Demand Paging:* Verdränge erst dann Seiten, wenn alle Seitenrahmen belegt sind. Verdränge nie mehr Seiten, als neu dazukommen.

FIFO wäre zum Beispiel ein Demand Paging-Algorithmus. 
Bei FIFO *kann* es vorkommen, dass mit denselben Lookups bei einer größeren Queue *mehr* page misses passieren als mit einer kleineren. Das heißt *Belady-Anomalie*.

Das kann mit einem Stack-Algorithmus nicht passieren:
> Ein Demand Paging-Algorithmus heißt Stack-Algorithmus, wenn zu jedem Zeitpunkt (und jede mögliche Folge von Zugriffen) der Hauptspeicher alles enthält, was ein kleinerer Hauptspeicher ebenfalls enthalten hätte.

"Least Recently Used", bei dem immer die Seite verdrängt wird, auf die auf die am längsten nicht mehr zugegriffen wurde, ist ein Stack-Algorithmus.

## Speicherverwaltung bei Multiprogramming
Multiprogramming: "Mehrere Prozesse laufen gleichzeitig"

Laufen zu viele Prozesse gleichzeitig, kann es zu *thrashing* kommen: es müssen andauernd Seiten ausgetauscht werden, was so viel Zeit in Anspruch nimmt, dass die CPU die eigentliche Arbeit nicht mehr ausführen kann.

Eine Möglichkeit der Speicherverwaltung ist das **Working-Set-Konzept**:
- Das Working Set eines Prozesses ist die Menge der Seiten, auf die der Prozess "in letzter Zeit", also während der letzten $x$ Zugriffe, zugegriffen hat.
- Ein Prozess kann nur dann aktiv werden, wenn im Hauptspeicher genug Platz für sein Working Set ist.
- Bei Seitenfehlern werden die Seiten ausgetauscht, die momentan zu keinem Working Set gehören.
- Ist kein Tauschkandidat verfügbar, dann wird der Prozess mit dem aktuellen Seitenfehler stillgelegt.

Das Working-Set-Konzept macht sich das < Lokalitätsprinzip> zunutze, also dass Programme (wegen Schleifen, Methoden, Arrays, etc.) phasenweise nur auf bestimmte, räumlich begrenzte Speicherbereiche zugreifen.

## Übrigens
Der Hintergrundspeicher kann übrigens auch im Netzwerk liegen (LAN/WAN). Ein Netzwerk, das für hohen Datenaustausch optimiert ist, heißt Storage Area Network (SAN).

Außerdem gibt es Dateien auf dem Permanentspeicher. Das Betriebssystem speichert Metadaten zu diesen Dateien. Dateien sind in einer Baumstruktur ("Ordner") organisiert. Beim Zugriff auf Dateien bzw. Verzeichnisse sind "Sicherheitsbelange massiv berührt".
bahnbrechend
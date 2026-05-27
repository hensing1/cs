Audiosignal (idealisiert): Funktion $f: \mathbb{R} \to \mathbb{R}$ (Luftdruck über die Zeit)
In Digitalform: $x: \mathbb{Z} \to \mathbb{Z}$

*Pattern Matching:* bekannte Muster in großen, verrauschten Datenmengen finden
*Machine Learning:* iterativ Performanz bzgl. einer Aufgabe verbessern, ohne es explizit zu programmieren

## Aufgaben

**Audio Detection**
Liste von Segmenten des Eingangssignals zurückgeben, die das gesuchte Signal enthalten (z.B. Sprache)

**Audio Classification**
Gegeben: Audiosignal, $N$ verschiedene Klassen

- Closed-set classification: Klassifizierung jedes Datums in $N$ bekannte Klassen
- Open-set classification: Klassifizierung jedes Datums in $N$ bekannte Klassen *oder* "unbekannt"

Zweistufiger Klassifizierer: erst z.B. "Sprache" erkennen (aus möglichen Klassen "Rauschen", "Sprache", "Musik", etc.), danach konkrete Person erkennen

"Robustheit" eines Klassifizierers kann im Hinblick auf Rauschen sein, oder im Hinblick auf semantische Veränderungen.

**Audio Segmentation**
Partitionierung eines Signals

**Source Separation**
Gegeben: $N$ verschiedene Signale, die sich jeweils aus $M$ verschiedenen Quellen zusammensetzen -> die einzelnen Quellen wiederherstellen

**Noise Reduction**
Rauschen reduzieren, Signal wiederherstellen, Deutlichkeit / Verständlichkeit von Signal verbessern

**Audio Compression**
Verlustfrei oder verlustbehaftet die Speichergröße eines Audiosignals verringern

**Audio Identification**
z.B. Musikstück anhand von kurzem Segment erkennen
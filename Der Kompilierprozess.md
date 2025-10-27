# Der Kompilierprozess

## Analyse

### Lexikalische Analyse
Die lexikalische Analyse ist der erste Schritt im Kompilierprozess. Sie umfasst:

- Erkennung der Token (Grundsymbole),
- Ausblenden bedeutungsloser Zeichen (wie Kommentaren und Whitespace),
- Codierung der Token für die weitere Verarbietung.

Ein Programm für die lexikalische Analyse heißt **Scanner**.

In Java beispielsweise gibt es folgende Arten von Token:
- Ein Identifier für eine Variable,
- ein reserviertes Keyword,
- ein Literal, z.B. eine Zahl oder auch `null`,
- ein Separator `( ) { } [ ] ; , .`, oder
- ein Operator wie `= < > ! +=` usw.

Die Syntax-Grammatik einer Programmiersprache ist [[Formale Sprachen und Grammatiken#Chomsky-Hierarchien#Definition|regulär]], also kann die lexikalische Analyse mit einem [[Endliche Automaten|DFA]] erfolgen.

### Syntaktische Analyse
Die syntaktische Analyse erstellt einen *Ableitungsbaum* aus den in der lexikalischen Analyse bestimmten Token.
Ein Programm, das die syntaktische Struktur eines Quellprogramms bestimmt, heißt **Parser**.

lexikalische Analyse: Bestimmung der "Worte"
syntaktische Analyse: Bestimmung des "Satzbaus"

Für die syntaktische Analyse reicht eine reguläre Grammatik nicht aus: man braucht einen [[Kellerautomat|Kellerautomaten]] (pushdown automaton), der eine [[Formale Sprachen und Grammatiken#Kontextfreie Grammatiken|kontextfreie Grammatik]] entscheiden kann.
Ein Beispiel für eine kontextfreie Grammatik in diesem Zusammenhang ist ein arithmetischer Ausdruck.

### Semantische Analyse
In der semantischen Analyse werden kontextsensitive Prüfungen vorgenommen, welche durch eine kontextfreie Grammatik - und damit in der syntaktischen Analyse - nicht erfasst werden können, z.B.: 
- Prüfung, ob eine verwendete Variable deklariert wurde
- Typisierung von Ausdrücken
- Verwendung von Bezeichnern im korrekten Kontext (z.B. keine `break`-Statements außerhalb von Loops)

Eine mit derartigen Attributen versehene, kontextfreie Grammatik heißt [Attributgrammatik](https://de.wikipedia.org/wiki/Attributgrammatik).

## Synthese
In der Synthese wird der in der Analysephase erzeugte Zwischencode in die Maschinensprache der Zielmaschine übersetzt. Der zentrale Teil der Syntese ist also die **Code-Erzeugung**.

### Registerzuteilung
Lokale Variablen eines Programms müssen in Registern abgelegt werden. Jedoch gibt es evtl. nicht ausreichend Register, um alle Variablen abzuspeichern - dann müssen manche Variablen in den Hauptspeicher ausgelagert werden.

Nun muss man sich Gedanken machen, welche Variablen wo abgelegt werden und welche Register zu welchen Zeitpunkten sinnvollerweise wieder freigegeben werden.

Hierfür gibt es verschiedene Strategien:

*On-the-fly:*
Gibt es mehr Variablen als reale Register, wird mit symoblischen Registern gearbeitet. Jedem belegten symbolischen Register wird dabei ein reales Register oder eine Speicherzelle zugeordnet.

FIFO-Prinzip: wenn ein Register freigegeben werden muss, wird dasjenige ausgewählt, in welches als erstes geschrieben wurde.

LRU (least recently used): es wird das Register gewählt, auf dessen Inhalt am längsten nicht mehr zugegriffen wurde.

*Mehrere Durchgänge:*
Dieses Verfahren arbeitet zukunftsorientiert; d.h. es wird das Register zur Freigabe gewählt, welches in Zukunft am spätesten (oder gar nicht mehr) verwendet wird.

In einem Durchgang (on-the-fly) ist dies aber nicht möglich. Man braucht zwei: einen zur Feststellung, wann welche Werte verwendet werden, und einen zweiten zur eigentlichen Registerzuteilung.
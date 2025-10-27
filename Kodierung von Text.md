# ASCII
## Definition
- 7-Bit-Code (127 Zeichen), reicht aus für:
	- Groß-/Kleinbuchstaben (ohne Umlaute, da amerikanisch)
	- Sonderzeichen
	- Nicht-Druckbare Steuerzeichen (sowas wie tab, carriage return, etc.)
- Das 8. Bit bleibt entweder 0 oder wird als [[Korrektur von Übertragungsfehlern#Paritäts-Bit|Paritätsbit]] verwendet
- Die unteren 4 Bit der Zahlen sind die Binärdarstellung der entsprechenden Zahl
- Groß- und Kleinbuchstaben unterscheiden sich nur durch ein Bit

## Tabelle
![[ASCII_Tabelle.png]]

-> "A" codiert als `x41`

## Problem
Länderspezifische Zeichen sind nicht in ASCII enthalten
1. Lösung: Zeichen ersetzen (z.B. { wird zu ä)
2. Lösung: Auf Paritätsbit verzichten, um Anzahl der Zeichen zu verdoppeln

# ISO 8859
Der Standard 8859 der **I**nternational **O**rganization for **S**tandardization (hä?) legt 15 Teilnormen fest, welche jeweils 8-Bit-Kodierungen für einen länderspezifischen Zeichensatz festlegen. 
ISO 8859-1 ("Latin-1") ist die am zweithäufigsten im Internet genutzte Codierung (etwas über 1% aller Websites). Die ersten 7 Bits stimmen hierbei mit ASCII überein.

# Unicode
Mit Unicode bekommt jedes erdenkliche Zeichen seinen eigenen Code, und zwar mit genau 21 Bits:
- Die ersten 5 Bits teilen den Standard in 17 "Planes" ein:
	- Die Plane 0 heißt Basic Multilingual Plane (BMP) und enthält eigentlich alle wichtigen Zeichen.
		- Die untersten $2^7$ Zeichen der BMP entsprechen wieder dem ASCII.
	- Die Planes 1 bis 17 enthalten irgendeinen komischen Kram (wie seltene chinesische Schriftzeichen, historische Skripte, Emojis und Dominosteine) und sind größtenteils noch unbenutzt.
- Jede Plane hat 16 Bits zur Verfügung

## UTF
> Unicode Transformation Format

Ist eine Methode, um 21-Bit-Unicode-Zeichen in einem Byte (UTF-8), zwei Bytes (UTF-16) oder vier Bytes (UTF-32) abzuspeichern. Das funktioniert wie folgt:
![[UTF.png]]

Wie man sieht, kann UTF-8 ein Zeichen nur dann in einem Byte abspeichern, wenn bei diesem Zeichen nur die unteren 7 Bits nicht-null sind (das entspricht dem ASCII-Teil der BMP).
Eine ASCII-Datei ist also eine gültige UTF-8-Datei!

Damit die UTF-16-Kodierung funktioniert, dürfen in der BMP die Zeichen 110110\* und 110111\* nicht vorkommen (das nennt man dann low & high surrogates).

UTF-8 wird bei weitem am häufigsten verwendet (nicht nur von allen UTFs, sondern von allen Zeichenkodierungen insgesamt).

### Byte Order Mark
Damit in UTF-16 und UTF-32 zwischen [[Glossar#Little-Endian, Big-Endian|Big-Endian und Little-Endian]] unterschieden werden kann, wird manchmal ein Byte Order Mark (BOM) in Form des Null Breiten Nichtverbinders™ an den Anfang der Datei gesetzt (Zeichen FEFF).
In [[Kodierung von Text#ISO 8859|Latin-1]] wäre das "ï»¿" - eine sehr unwahrscheinliche Zeichenfolge, wodurch also diese Dateikodierungen voneinander unterschieden werden können.
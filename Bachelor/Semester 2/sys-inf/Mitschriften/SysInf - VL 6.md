Datum: 16.05.
[[SysInf_Kap_2_230505_1035.pdf|Folien]]: Seiten 15 bis 38

Kapitel 2.2

# Übersetzungsprozess
Betrachtet man die automatische Übersetzung einer Quellsprache $A$ in eine Zielsprache $B$, wobei $A$ mächtiger ist als $B$, spricht man von einem **Compiler**.

Für den Bau eines Compilers müssen für beide Sprachen sowohl die *Syntax* (welche Zeichenketten sind korrekt formulierte Programme der Sprache) als auch die *Semantik* (welche Bedeutung hat ein korrekt formuliertes Programm) formal korrekt definiert sein.

## Struktur
Der Übersetzungsprozess lässt sich sinnvollerweise einteilen in:
- Analyse
	- lexikalische Analyse
		- Erkennung der Grundsymbole durch *Scanner*
	- syntaktische Analyse
		- Erkennung der Programmstruktur
		- Bestimmung des Ableitungsbaums anhand der Syntax
	- semantische Analyse
		- Ergänzung des abstrakten Programmbaumes um Attribute
- Synthese
	- Erzeugung der Zielsprache aus dem Zwischencode aus der Analyse

## Exkurs: Kontextfreie Grammatiken

Man kann die Syntax einer Programmiersprache mit einer [[Formale Sprachen und Grammatiken#Kontextfreie Grammatiken|kontextfreien Grammatik]] beschreiben.

Dafür lernen wir die Backus-Naur-Form kennen: 

![[Formale Sprachen und Grammatiken#Backus-Naur-Form]]

![[Formale Sprachen und Grammatiken#Syntaxdiagramm]]

## Analyse

Schritt 1:
![[Der Kompilierprozess#Lexikalische Analyse]]
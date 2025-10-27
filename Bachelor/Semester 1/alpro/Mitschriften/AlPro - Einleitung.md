[[01_Einleitung_01.pdf|Einleitung Teil 1]]
[[01_Einleitung_02.pdf|Einleitung Teil 2]]
# Was ist ein Algorithmus?
![[Algorithmen#Definition]]

> [!info] By the way
> Abstraktion ist wichtig und überall in der Informatik. Es ist das Entfernen von unwesentlichen Bestandteilen.
> Es werden sowohl Verfahren (wie z.B. im Falle von Algorithmen) abstrahiert & verallgemeinert, als auch z.B. Computermodelle (z.B. bis hin zur [[Registermaschinen|Registermaschine]])

# Programmierung
## Abstraktes Computermodell zum Zweck dieser Vorlesung
- Es gibt eine (oder mehrere) CPU(s), mit denen Daten verarbeitet werden
- Es gibt eine Menge von Speicheradressen, um Daten abzulegen
- Es gibt die Möglichkeit, auf andere Ressourcen/Peripherien des Computers zuzugreifen
Das war's.

## Begriffserklärungen
![[Glossar#Programme & Prozesse]]

## Programmiersprachen
- Programmiersprachen sind Sprachen, in denen man programmiert (ach so)
- Verschiedene Programmiersprachen haben verschiedene Datentypen
	- C++ hat ints von int8 bis int64 (jeweils signed und unsigned)
		- Ein char hat 8 bit, ein wchar hat 16 oder 32 bit
	- Python hat Datentyp "complex" für komplexe Gleitkommazahlen
		- list ist auch ein primitiver Datentyp
- Es gibt etwas das nennt sich "Hello World"-Programm

## Entwicklung
Man nehme:
- Einen Texteditor (am besten mit Syntax Highlighting und Autovervollständigung)
- Einen Compiler (für C++ gibt es clang++, g++, MSVC)
	- Um eine c++-Datei zu kompilieren:
	  `> clang++ -std=c++17 -o NAME_AUSGABE_DATEI NAME_EINGABE_DATEI.cpp`
	  `> ./NAME_AUSGABE_DATEI`
- Das Tastaturlayout "US international without dead keys" macht es einfacher, häufig benutzte Sonderzeichen wie `[ ] { } ^ ' /` zu verwenden

## C++
Es gibt verschiedene Arten von Statements in C++:
- Declaration Statements
	- sowas wie `int alter;`
- Expression Statements
	- Berechnungen
		- `42 * 3;`
	- Zuweisungen
		- `alter = 5;`
	- Methodenaufrufe
- Selection Statements
	- `if / else`
	- `switch`
- Iteration Statements
	- `while`
	- `for`

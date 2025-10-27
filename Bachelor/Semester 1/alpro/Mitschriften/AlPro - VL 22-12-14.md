Datum: 14.12.
Folien: [[05_Objektorientierte_Programmierung_mit_C++_01.pdf|Objektorientierte Programmierung mit C++ - 01]]

# Objektorientierte Modellierung
Wir möchten unser Projekt in mehrere, miteinander interagierende Objekte unterteilen.

Es gibt zwei wesentliche Sichtweisen:
- **Zusammensetzung:** aus welchen Objekten besteht X?
- **Subtypenbildung:** welche Objekte verhalten sich allgemeiner / spezieler als X?

Um das zu demonstrieren, machen wir ein Beispielprojekt mit Graphen (Klasse für Knoten, Klasse für Kanten, Klasse für Graph). Siehe Übungsaufgaben.

Bemerkung zu den wichtigsten Aufgaben von **Buildsystemen:**
- Prüfung ob die nötigen Voraussetzungen erfüllt sind (sind notwendige Compiler, Bi-  
bliotheken und Hilfsprogramme verfügbar?)  
- Systembezogene Konfiguration aus allgemein gegebener Definition ableiten  
- Softwareprojekt entsprechend der allgemeinen Konfiguration bauen  
- Korrekte Funktionsweise des gebauten Softwareprojekt testen

Befehle für CMake:
```
> mkdir -p build
> cd build
> cmake ..
> make
> ./programmname
```


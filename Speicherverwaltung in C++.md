# Speicherverwaltung in C++

## Einteilung des Virtuellen Adressraums
Jeder Nutzerprozess (also jede Instanz eines C++-Programms) verfügt über einen virtuellen Adressraum, in welchem - zusammen mit den CPU-Registern - alle Programmbefehle und Programmdaten abgespeichert sind.
Der virtuelle Adressraum ist unterteilt in den **Programmspeicher**, **Stackspeicher** und **Heapspeicher**.

### Stackpeicher
Der Stackspeicher ist funktionsorientiert. Er enthält alle Daten, welche zu einem Funktionsaufruf gehören.

Bei einem Funktionsaufruf wird ein neuer **Stackframe** im Stackspeicher abgelegt. Der Stackframe enthält alle Variablen, die in der Funktion definiert werden und hat eine *statische Größe*, welche bereits zu Compilezeit feststeht. 
Wenn die Funktion durchlaufen wurde, wird der aktuelle Stackframe wieder entfernt. Etwaige Rückgabewerte werden in den Stackframe der aufrufenden Funktion geschrieben.

### Heapspeicher
Dinge, deren Größe man erst zur Laufzeit weiß (wie zum Beispiel [[AlPro - VL 22-10-26#C++-Arrays (dynamisch)|Dynamische Arrays]]), landen nicht auf dem Stack, da der Stackframe einer Funktion immer gleich groß ist. Stattdessen kommen sie auf den Heapspeicher.
Im Stackframe verweist dann eine Referenz auf die entsprechende Speicherstelle im Heap.

Der Heapspeicher hat nicht besonders viel mit der Datenstruktur *Heap* gemeinsam - eine passendere Bezeichnung wäre sowas wie "Memory Pool für dynamische Speicherstrukturen".
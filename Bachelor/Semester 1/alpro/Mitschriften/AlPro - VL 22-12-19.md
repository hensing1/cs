Datum: 19.12.
Folien: [[05_Objektorientierte_Programmierung_mit_C++_02.pdf|Objektorientierte Programmierung mit C++ - 02]]

# UML
Es geht um die **Unified Modeling Language** zur visuellen Darstellung von Ideen und Konzepten in objektorientierter Programmierung.

Es gibt zwei hauptsächliche *Dialekte*:
- *UML-Sketching:* Darstellung von konzeptionellen Ideen, unabhängig von der konkreten Programmiersprache
- *UML-Blueprinting:* Darstellung der konkreten Implementierung in einer Programmiersprache

Es gibt verschiedene *Diagrammarten:*
- *Aktivitätsdiagramme* und *Prozessdiagramme:* Entwurf von prozedualen Vorgängen
- *Klassendiagramme:* Aggregationen und Vererbungen von Objekten

## Klassendiagramme
Im Sketchingdialekt werden Attribute (ohne konkreten Datentyp) und wichtige Memberfunktionen (also Interaktionsschnittstellen) (ohne Konstruktor, getter/setter, oder Operatoren) mit Attributnamen und dem (abstrakten) Rückgabetyp angegeben. 

Das alles wird im Blueprintdialekt für die entsprechende Programmiersprache konkretisiert (mit Datentypen, sämtlichen Methoden, etc.). Im Blueprinting wird z.B. auch beschrieben, ob Variablen read-only sind (mit dem Zusatz `{read-only}`.
Methodenparameter werden hier auch mit `in`, `inout` oder `out` versehen.
Durch die Angabe des Keywords `{query}` hinter dem Rückgabetyp wird angegeben, dass die Operation den Objektzustand nicht ändert.

Man modelliert (in beiden Dialekten), ob man von außen Zugriff auf die Attribute / Methoden hat. Das nennt man *Kapselung* bzw. *Information Hiding*.

> [!info] Ach was
> Objekte desselben Typs können gegenseitig auf *all* ihre Attribute zugreifen. 
> Man soll ja beim Implementieren der Memberfunktion sowieso darauf achten, dass die erreichten Zustände immer zulässig sind.

Ein Objekt, dessen Attribute alle zugreifbar sind und das (im Sinne des Sketchings) über  
keine wesentlichen Memberfunktionen verfügt, nennt man *Data Transfer Object*. Diese werden in C++ mit `struct`s implementiert.

Private Memberfunktionen (das sind ja meistens Hilfsfunktionen) werden beim UML-Sketching oft nicht genannt.
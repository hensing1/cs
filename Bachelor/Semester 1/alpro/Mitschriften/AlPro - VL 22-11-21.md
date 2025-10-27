Folien: [[04_Algorithmen_Teil_2_03.pdf|Algorithmen Teil 2 - 03]]

# Abstrakte Datentypen und Datenstrukturen

> [!abstract] Definition
> Ein **abstrakter Datentyp** ist ein Modell für eine Kollektion von Objekten derselben Art. Hierbei ist eine Menge von Operationen definiert, die für diese Kollektion verfügbar ist.
> Man kann für jede dieser Operationen den Speicherverbrauch und die Laufzeit in Abhängigkeit von der Anzahl der gespeicherten Objekte angeben.
> 
> Eine **Datenstruktur** ist eine *Realisierung* eines abstrakten Datentyps, welche die vom Datentyp vorgegebenen Operationen und die dazugehörigen Laufzeiten und Speicheransprüche erfüllen.

## Sequenzielle Container
Ein Sequenzieller Container erfüllt die folgenden Bedingungen:
- Alle Objekte haben denselben Typ T
- Rückgabe der *Anzahl* der gespeicherten Objekte in $\mathcal{O}(1)$
- Für die enthaltenen Objekte ist eine *Reihenfolge* definiert
- Die einfügenden und entfernenden Operationen erhalten die Reihenfolge und haben Laufzeit $\mathcal{O}(n)$
- Ist der Speicherverbrauch von T beschränkt, liegt der Speicherverbrauch in $\mathcal{O}(n)$

Es gibt auch sequenzielle Container mit Laufzeit $\mathcal{O}(\log n)$ oder $\mathcal{O}(1)$.

### Dynamisches Array
#### Definition
Ein dynamisches Array ist ein sequenzieller Container, welcher die folgenden Eigenschaften erfüllt:
- Die Reihenfolge der Objekte ist gegeben durch Indizes $0,1,2,\ldots$ und der Objektzugriff ist über diese Indizes möglich
- Objekte können an beliebigen Stellen eingefügt und entfernt werden
- Die amortisierte Laufzeit von Einfügen und Entfernen am *Ende* ist $\mathcal{O}(1)$

#### Umsetzung durch Datenstruktur
Die Objekte vom Typ T als dynamisches Array zu speichern, reserviert man sich zunächst ein zusammenhängendes Stück Speicher für Objekte desselben Typs.
Ein Objekt mit Index $i$ wird dann gespeichert an der Speicherstelle $p+i \cdot s$, wobei $p$ die Adresse des ersten Objekts ist und $s$ die Größe des Typs T.

Falls man ein Objekt hinten anfügen will und kein Platz mehr ist, verdoppelt man (z.B.) den reservierten Speicher.

Um was in der Mitte einzufügen, muss man alles dahinter nach hinten schieben. Durchschnittliche Laufzeit: $\mathcal{O}(n)$.

Entfernen verhält sich analog.

### Verkettete Liste
Eine einfach verkettete Liste ist ein sequenzieller Container, welcher die folgenden Eigenschaften erfüllt:
- Man kann das erste Objekt zurückgeben
- Falls es einen Nachfolger eines Objekts gibt, kann dieser zurückgegeben werden
- Objekte können an beliebigen Positionen eingefügt oder entfernt werden (man muss ggf. den Vorgänger angeben)
- Alle dieser Operationen haben Laufzeit $\mathcal{O}(1)$

Bei einer doppelt verketteten Liste muss man auch den Vorgänger zurückgeben können, und beim Löschen muss man keinen Vorgänger angeben (man hat ja die Vorgänger- und Nachfolgerpointer zur Verfügung)

### Queue
Ein sequenzieller Container ist eine Queue, falls:
- Man Objekte am Anfang entfernen und am Ende einfügen kann
- Beides in $\mathcal{O}(1)$ passiert

### Stack
Ein sequenzieller Container ist ein Stack, falls:
- Man Objekte am Anfang entfernen und einfügen kann
- Beides in $\mathcal{O}(1)$ passiert

# Dynamische Speicherverwaltung
## Virtuelle Adressräume
Jedem Nutzerprozess steht ein eigener, virtueller Adressraum zur Verfügung.
Der virtuelle Adressraum besteht aus **Programmspeicher**, **Stackspeicher** und **Heapspeicher**.

Für Stack- und Heapspeicher, siehe: [[Speicherverwaltung in C++#Einteilung des Virtuellen Adressraums]].

## Verwaltung des Heapspeicher
Man hat also Gedöns im Heapspeicher, das evtl. unabhängig ist von spezifischen Funktionsaufrufen (liegt halt nicht im Stack).

Zunächst einmal hat man **Pointer**. Ein Pointer ist eine Adressvariable, welche eine *virtuelle Adresse* eines *bestimmten Typs* abspeichert.
Wenn man nun also ein Objekt anlegt, landet es auf dem Heap. Dann wird ein Zeiger mit dem Typ des Objekts zurückgegeben, der auf die entsprechende Speicheradresse im Heap zeigt.

Wenn man dieses Objekt irgendwann nicht mehr braucht, gibt es verschiedene Wege, den Speicherplatz wieder freizugeben:
- *Explizites Aufräumen:* der Programmierer muss sich selber darum kümmern, dass der Speicherplatz wieder freigegeben wird. Das ist zum Beispiel in **C** der Fall. Vergisst man das Aufräumen, lebt das Objekt bis zum Programmende im Heap weiter.
- *Implizites Aufräumen*: Die Programmiersprache erkennt, falls gar kein Zeiger mehr auf den verwendeten Heapspeicher zeigt. Das ist nicht ganz so effizient wie explizites Aufräumen (aber immer noch ziemlich gut), aber es nimmt dem Programmierer einiges an Arbeit ab. Falls aber auf dem Heap ein Kreis von aufeinander zeigenden Pointern existiert, wird dieser Teil des Heaps nicht aufgeräumt. **C++** verwendet tatsächlich implizites Aufräumen.
- *Vollautomatisches Aufräumen* (Garbage collection): Alle Stackvariablen sind Pointer, und alle Objekte liegen auf dem Heap. Regelmäßig kommt der Garbage Collector angefahren und räumt den Heap auf - dabei wird alles entfernt, was nicht mehr vom Stack aus erreichbar ist. Das ist nicht so effizient wie implizites Aufräumen, aber der Heap wird garantiert aufgeräumt.
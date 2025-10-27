Um ein Element $e$ aus einer doppelt verketteten Liste zu entfernen, werden zunächst - falls vorhanden - die sich unmittelbar davor und dahinter befindlichen Elemente $d$ und $f$ benötigt. 

Nun muss der Nachfolger-Zeiger in $d$, der vorher auf $e$ gezeigt hat, mit einem Zeiger auf $f$ überschrieben werden. Ebenso muss der Vorgänger-Zeiger von $f$, der vorher auf $e$ gezeigt hat, mit einem Zeiger auf $d$ überschrieben werden. Nun kann $e$ aus dem Speicher gelöscht werden.

![[Drawing 2022-11-27 15.32.36.excalidraw]]

Falls $e$ das erste Element in der Liste war, muss der Vorgänger-Zeiger von $f$ auf den Nullzeiger gesetzt werden, da $f$ nun das erste Element ist.
Falls $e$ das letzte Element war, muss der Nachfolger-Zeiger von $d$ auf den Nullzeiger gesetzt werden.
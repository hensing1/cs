Folien: [[04_Algorithmen_Teil_2_02.pdf|Algorithmen Teil 2 - 02]]

Heute machen wir Pathfinding.
Dafür haben wir ein 2d-Grid mit einem Startpunkt und einem Zielpunkt, und wir wollen einen möglichst kurzen Pfad finden, der die beiden Punkte verbindet.

# Pathfinding ohne Heuristik
Wir wissen, dass das Ziel irgendwo in der Nähe ist, aber wir wissen nicht wo und wir können die Distanz zum Ziel nicht abschätzen.

Also gucken wir uns per [[Algorithmen#Methoden zum Entwurf von Algorithmen#Greedy-Algorithmen|Greedy-Verfahren]] nacheinander alle Felder an, welche dem Startpunkt am nächsten sind.

Dadurch guckt man sich quasi in einer Spirale alle Felder um den Startpunkt herum an. Da die Distanz zum Ziel endlich ist und man mit jedem Schritt das Suchfeld verkleinert, ist es garantiert, dass man irgendwann das Ziel findet (oder man ist irgendwie eingemauert, in welchem Fall man aufhört, sobald man keine neuen Felder mehr finden kann).

Wenn man sich jetzt noch bei jedem neuen Feld den jeweiligen Vorgänger merkt, also das Feld, von dem aus man das neue Feld entdeckt hat, kann man damit schrittweise den Pfad zurück konstruieren, sobald man das Ziel gefunden hat.

Problem: die Laufzeit ist natürlich riesig groß, da wir den Suchbereich nicht vernünftig einschränken können.

# Pathfinding mit Heuristik
## Distanz zum Ziel
Unterschied: man schaut sich nicht mehr als erstes die Felder an, die dem Startpunkt am nächsten sind, sondern die (gerade erreichbaren) Felder, die laut einer Heuristikfunktion dem *Ziel* am nächsten sind.
So eine Heuristikfunktion könnte zum Beispiel einfach die euklidische Distanz (Luftlinie) vom jeweiligen Feld zum Ziel angeben.

Vorteil: im besten Fall sinkt die Laufzeit dadurch erheblich, weil man nicht mehr in die falsche Richtung läuft.

Nachteil: wenn man Pech hat, findet man hiermit einen Weg, der wesentlich schlechter ist als der kürzeste Pfad. Es ist halt immer noch ein Greedy-Verfahren, und damit schaut man sich nur das lokale Optimum an, welches sich aber vom globalen Optimum unterscheiden kann.

## Pfadlänge + Distanz zum Ziel
Neue Heuristik: Addition des bislang zurückgelegtem Pfad addiert mit der Luftlinie zum Ziel.

Wenn man nun bei jedem Schritt das Feld auswählt, das laut dieser Heuristik den geringsten Wert hat, findet man tatsächlich immer den kürzesten Pfad, noch dazu in wesentlich besserer Laufzeit als bei der Suche ohne Heuristik.

Problem: wenn es mehrere kürzeste Pfade gibt (z.B. auf offener Ebene), kann es immer noch zu langen Laufzeiten kommen.

# A*-Algorithmus
Der A*-Algorithmus ist eine Verallgemeinerung des oben beschriebenen Verfahrens. Er funktioniert für gewichtete [[Graphen]] statt 2d-Landschaften.

Zudem kann man mit einem Parameter $\omega$ bestimmen, wie man das Auswahlverfahren bestimmen möchte:
$\text{Auswahl}=\text{argmin}_{v\in \text{offen}} \space \omega \cdot \text{ZurückgelegterWeg}(v)+(1-\omega)\cdot\text{Heuristik}(v)$

Für $\omega = \frac{1}{2}$ erhält man das Verhalten des oben beschriebenen Algorithmus, sofern die Heuristik die Länge zum Ziel nicht überschätzt.

Für $\omega < \frac{1}{2}$ erhält man einen approximativen Algorithmus.
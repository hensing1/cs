Kapitel 4: _Dynamische Mengen_
[Vorlesung](https://uni-bonn.sciebo.de/s/7Gfq3hL6DaUYioC#/files_mediaviewer/Vorlesung%20-%20Kapitel%204-2-2.mp4)

# Verallgemeinerte Suchbäume
> [!abstract] Verallgemeinerter Suchbaum
> Ein Knoten in einem verallgemeinerten Suchbaum darf **beliebig viele** (aber mindestens einen) Schlüssel haben. Hat ein innerer Knoten *$l$ Schlüssel*, besitzt er *$l+1$ Kinder*.
> 
> Für beliebige Schlüssel $k_1,\ldots,k_{l+1}$ der Kinder $u_1,\ldots,u_{l+1}$ eines Knoten $v$ gilt:
>$$k_{1}\leq v.\text{key}(1) \leq k_{2} \leq v.\text{key}(2) \leq\ldots\leq v.\text{key}(l) \leq k_{l+1}.$$

# B-Bäume
## Motivation
B-Bäume sind eine Datenstruktur, welche im Gegensatz zu den bisher behandelten Lösungen auch auf die Speicherhierarchie moderner Rechner Rücksicht nimmt. 
Bei großen Datenmengen passt evtl. nicht mehr die gesamte Datenstruktur in den Hauptspeicher. Das heißt, es kann unter Umständen vorkommen, dass z.B. bei einem AVL-Baum $\Theta(\log n)$ Zugriffe auf die Festplatte passieren. Auch bei SSDs ist das ganze um einige Größenordnungen langsamer als ein Zugriff auf den Hauptspeicher.

Bei B-Bäumen macht man es sich nun zunutze, dass Daten seitenweise in den Arbeitsspeicher geladen werden (z.B. bei x86-Architekturen sind das Blöcke der Größe 4kB). Das verschieben eines Blocks dauert kaum länger als das Lesen eines bestimmten Werts.

## Definition

> [!abstract] B-Baum
> Ein verallgemeinerter Suchbaum heißt *B-Baum der Ordnung $t$* (mit $t\in\mathbb{N},t\geq 2$), wenn folgende Eigenschaften erfüllt sind:
> - Alle Blätter sind auf derselben Ebene.
> - Jeder Knoten enthält höchstens $2t-1$ Daten und (mit Ausnahme der Wurzel) mindestens $t-1$ Daten.
> - Ist der Baum nicht leer, enthält die Wurzel mindestens ein Datum.

Beachte: ein innerer Knoten in einem B-Baum der Ordnung $t$ hat mindestens $t$ und höchstens $2t$ Kinder. Die Wurzel darf auch $2$ bis $2t$ Knoten haben.

## Worst-Case-Wachstum
Die Höhe eines B-Baums ist nach oben beschränkt durch $\log_{t}(\frac{n+1}{2})$.
Begründung: die Worst-Case-Knotenanzahl ist $2t^{i-1}$ pro Ebene und damit $2t^{h}-1$ insgesamt. Dieser Term umgestellt ergibt $h \leq \log_{t}(\frac{n+1}{2})$.

Die Anzahl der Speicherzugriffe für Search, Insert und Delete steigt ja bekanntlich linear mit der Höhe eines Suchbaums.
Da die Höhe des B-Baums $\log_{t}(\frac{n+1}{2})=\frac{\log_{2}(n+1)-1}{\log_{2}t}$ und die vom AVL-Baum $\log_{2}(n+1)$, sinkt die Anzahl der Speicherzugriffe um den Faktor $log_{2}t$. Da das eine Konstante ist, geht das in der O-Notation unter, aber für z.B. $t=1024$ ist das schon einigermaßen signifikant, u.a. da das $t$ so gewählt wird, dass ein einzelner Knoten als Ganzes in einer einzelnen Seite in den Speicher geladen werden kann.

## Operationen

> [!example] Komplexität
> Für alle drei Operationen `Search`, `Insert` und `Delete` gilt:
> Laufzeit ($\mathcal{O}(t)$ pro Knoten): $\mathcal{O}(th)=\mathcal{O}(t\log_{t}n)$
> Seitenzugriffe (einen pro Knoten): $\mathcal{O}(\log_{t}n)$

### Search
Man durchsucht den Wurzelknoten nach dem gesuchten Wert. Falls man ihn nicht findet, sucht man zwischen den beiden Werten im Knoten, zwischen denen sich der gesuchte Wert befindet, im entsprechenden Kind weiter.

### Insert
Man sucht zunächst den Knoten raus, in den der Wert reingehört.
Falls noch Platz ist, fügt man den Wert ein.
Falls nicht, zieht man den mittleren Wert in den Knoten darüber, und teilt die Werte links und rechts von der Mitte in eigene Knoten auf. Dann fügt man den Wert ein.

Beachte: wenn der mittlere Wert nicht in den Vaterknoten passt, wird das Prozedere dort wiederholt. Der B-Baum wächst also quasi in Richtung Wurzel. 
Wenn man sich das mal genauer anguckt, ist das ist auch der Grund warum die Wurzel auch zwei Kinder haben darf. Dass der Baum nach oben (und in die Breite) wächst, sorgt auch wiederum dafür, dass alle Blätter auf derselben Ebene bleiben.

### Delete
1. Falls das zu löschende Element $e$ nicht in einem Blatt ist, tausche es mit dem größten Element, das kleiner als $e$ ist, und lösche es dann.
2. Falls der Knoten nun $t-2$ Schlüssel enthält (nicht erlaubt), müssen entweder:
	1. Daten rotiert werden, wenn in einem Nachbarknoten noch mindestens $t$ Daten drin sind. Dann wandert die Wurzel zwischen dem zu leeren Knoten und dem Nachbarknoten nach unten in den zu leeren Knoten, und das kleinste (bzw. größte) Element aus dem Nachbarknoten nach oben an die Stelle des vorherigen Schlüssels.
	   Oder:
	2. es muss der Knoten mit einem Nachbarn zusammengefasst werden, der $t-1$ Schlüssel enthält. Dann rutscht deren gemeinsames Vaterelement runter in die Mitte, links davon die Werte vom einen Knoten, rechts davon die Werte vom anderen, alles in einem Knoten.
	   (Falls nun im Vaterknoten auch nicht mehr genug Daten da sind, wird dort analog verfahren).
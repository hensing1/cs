[[06snakes_WS2425_slides.pdf]]

# Snakes

Gegeben: ein grober Umriss in der Nähe von einem Objekt
Gesucht: der genaue Umriss von diesem Objekt

Idee: wir definieren eine *Energie* des Umriss (geschlossene Kurve / Schlange definiert durch Punkte (Vertices)), die wir *minimieren* wollen.
Wir verschieben iterativ jeden Punkt entlang der Schlange entgegen dem Energiegradienten.
$$
E_{gesamt}=E_{intern}+E_{extern}
$$
Interne Energie: Prior (ermutigt Glattheit, Elastizität, bekannter Umriss, ...)
Externe Energie: Basierend auf Bildinformationen (Schlange soll Strukturen im Bild folgen, z.B. Kanten).

*Beispiel Externe Energie*
Mit Gradientenbildern $G_{x}(x,y), G_{y}(x,y)$ und einen Punkt $v$:
$$
E_{extern}(v)=-(|G_{x}(v)|^2+|G_{y}(v)|^2)
$$

*Beispiel Interne Energie*
Für eine Schlange $v(s)$ ist die erste Ableitung die Länge, die zweite Ableitung die Krümmung. 
Länge minimieren heißt, dass die Schlange elastisch ist, Ableitung minimieren heißt, dass die Schlange starr ist.
$$
E_{intern}(v(s))=\alpha \left| \frac{\partial v}{\partial s} \right|^2 + \beta \left| \frac{\partial^2 v}{\partial^2 s} \right|^2
$$
Im diskreten Fall:
$$
E_{intern}=\sum_{i=0}^{n-1} \alpha \left\|v_{i+1}-v_{i}\right\|^2 + \beta \|v_{i+1}-2v_{i}+v_{i-1}\|^2
$$
Alternativ, damit durch die Elastizität die Schlange nicht zu einem Punkt kollabiert, können wir den Abstand zwischen den Punkten gleichmäßig halten (Standardabweichung der Abstände minimieren).

## Dynamische Programmierung

Wir optimieren alle Punkte gleichzeitig - funktioniert mit dem *Viterbi-Algorithmus* unter der Annahme, dass die Schlange kein Kreis ist (hat ein Anfang und ein Ende).

Annahmen:
- pro Punkt gibt es $k$ Optionen, wie er verschoben werden kann (z.B. 9, wenn wir eine 3x3 Nachbarschaft untersuchen)
- Wir haben eine *unary cost* (externe Energie eines einzelnen Punkts)
- Wir haben eine *binary cost* (interne Energie zwischen zwei benachbarten Punkten)

Wir bauen einen Graphen:
- jeder Punkt erhält $k$ Vertices im Graphen
	- das Knotengewicht ist die unary cost dieser Option
- jeder Vertex vom Punkt $v_{i}$ hat eine Kante zu allen $k$ Vertices vom Punkt $v_{i+1}$
	- das Kantengewicht ist die binary cost der beiden Optionen

Wir finden den minimalen Pfad durch diesen Graphen:
- Pro Punkt:
	- Für jeden der $k$ Knoten:
		- Schaue die $k$ eingehenden Kanten an
		- Pfadgewicht für diesen Knoten ist min{Pfadgewicht adjazenter Knoten + Kantengewicht} + unary cost
		- Behalte nur die Kante, die mit dem gerinsten Pfadgewicht assoziiert ist
- Am Ende:
	- finde Knoten vom letzten Punkt mit minimalen Pfadkosten
	- Verfolge Kanten zurück
	- Pfadknoten entsprechen den Zuständen, zu denen alle Punkte gleichzeitig bewegt werden, um die Gesamtkosten in diesem Schritt zu minimieren

Man kann auch die Unaries in die Binaries zusammenfassen. 

Mit $k$ Optionen und $n$ Knoten hat dieser Graph $\mathcal{O}(nk^2)$ Kanten.

Workaround, damit es doch für geschlossene Kantenzüge funktioniert:
- fixiere $v_{1}$, Löse für den Rest
- fixiere anderen Punkt an der neuen Position, löse nochmal für den Rest

## Kontinuierliche Snakes

$C(s)$ beschreibt die Snake (reeller Parameter $s$), $C_{s}(s)$ die erste und $C_{ss}(s)$ die zweite Ableitung. 

Energiefunktion:
$$
E(C) = - \int _{0}^{1} |\nabla I(C(s))|^2 + \alpha |C_{s}(s)|^2+\beta |C_{ss}(s)|^2\,ds
$$

Mit $\nabla I$ dem Bildgradienten (erster Term ist externe Energie), und $\alpha,\beta$ Parameter für die Ableitungen (interne Energie).
Wir suchen den *Gradienten* dieser Energiefunktion.

Eine Funktion $E(C)= \int \mathcal{L}(C,C_{s},C_{ss})\,ds$ hat den Gradienten gegeben durch die *Euler-Lagrange-Gleichung*, und es kommt raus:
$$
\frac{\partial E}{\partial C}=-\nabla |\nabla I(C)|^2 - \alpha C_{ss} + \beta C_{ssss} \to \text{min}
$$

Die kann man jetzt diskretisieren, und dann hat man eine analytische Methode (über gradient descent), um die Snake zu optimieren.

## Oh nein

Wir können in die Situation kommen, dass die Länge der Snake nicht ausreicht - wir haben nicht genug Kontrollpunkte, um die komplette Objektkontur zu erfassen, z.B. weil der Umriss wesentlich länger ist als der umschließende Kreis.

Alternativ können wir aus Versehen mehrere Objekte mit derselben Snake umschließen, und haben dazwischen dann eine Verbindung, die wir nicht haben wollen (wir können die Topologie nicht verändern, dh. keine Löcher hinzufügen oder Segemente trennen).

### Level-Set-Repräsentierung

Wir repräsentieren unsere Snake als level set in einer Funktion: alle Werte innerhalb der Kontur sind negativ, alle außerhalb positiv, und der Umriss ist die Menge der Punkte, für die die Funktion 0 ist.
Genauer haben wir durch die Funktion ein *signed distance field*, also jeder Punkt gibt den Abstand zur Snake.

Wir machen uns damit unabhängig von der Anzahl der Kontrollpunkte.

Wir optimieren jetzt nicht die Kontur, sondern die Level-Set-Funktion.

Der Gradient dieser Funktion hängt vom Bildgradienten ab und wird pixelweise parallel berechnet (auf der GPU).
[[04edges_WS2425_slides.pdf]]

# Kanten

Eine Kante ist eine Diskontinuität in der Intensitätsfunktion, die wir durch Glättung und Ableitung finden können.

Wir können mit einem Gaußfilter glätten und dann ableiten, oder wir können den Gaußfilter ableiten und damit glätten (Ableitung ist linear und shiftinvariant, also eine Konvolution, und Konvolutionen sind assoziativ).

- *Glättungsfilter*
	- Glättung := gewichtete Summe benachbarter Werte, alle Werte $\geq 0$
	- Gesamthelligkeit des Bildes soll erhalten bleiben -> Summe aller Werte ist 1
- *Ableitungsfilter*
	- Berechnung des Gradienten
	- Keine Filterantwort in konstanten Regionen -> Summe aller Werte ist 0

![[ISS - VL 6#Canny Edge Operator]]

## Shape Fitting mit Chamfer Distance

Wir möchten ein Objektmodell (z.B. ein Kreis) mit beobachteten Features (hier: Kantenzügen) übereinbringen.

> [!abstract] Definition **Chamfer-Distanz**
> Die Chamferdistanz ist ein Maß für den Abstand zwischen zwei Puntkemengen (hier: Template $T$ und registrierte Bildpunkte $I$):
> $$D_{\text{chamfer}}(T,I) \equiv \frac{1}{|T|}\sum_{t \in T}d_{I}(t)$$mit $d_{I}(t)$ der Minimale Abstand des Punkts $t$ zu irgendeinem Punkt in $I$.

Berechnung von $d_{I}(t)$: **Distanztransformation**

Enthält für jeden Pixel den Abstand zum nächsten Kantenpixel.

Algorithmus für L1-Distanz:
- *Initialisierung:* setze Kantenpixel auf 0, alle anderen auf $\infty$
- *Forward Pass:* berechne nächste Punkte nach oben und links
	- Iteriere links nach rechts, oben nach unten
	- Pro Pixel:
		- zentriere Maske $\begin{bmatrix}\infty & 1 & \infty \\ 1 & 0 & \infty \\ \infty & \infty & \infty \end{bmatrix}$ auf Pixel
		- addiere die jeweiligen Maskenwerte auf Pixelwerte
		- neuer Pixelwert: Minimum
- *Backward Pass:* berechne nächte Kantenpuntke nach unten und rechts
	- Iteriere rechts nach links, unten nach oben
	- Pro Pixel: dasselbe, nur mit Maske $\begin{bmatrix}\infty & \infty & \infty \\ \infty & 0 & 1 \\ \infty & 1 & \infty \end{bmatrix}$

Maske für Schachbrett-Distanz: $\begin{bmatrix}1 & 1 & 1 \\ 1 & 0 & \infty\end{bmatrix}$
Approximierungen für Euclidische Distanz:
- Chamfer 3-4: $\begin{bmatrix}4 & 3 & 4 \\ 3 & 0 & \infty\end{bmatrix}$
- Chamfer 5-7-11: $\begin{bmatrix}\infty & 11 & \infty & 11 & \infty \\ 11 & 7 & 5 & 7 & 11  \\ \infty & 5 & 0 & \infty & \infty\end{bmatrix}$

> Mit einer Distanztransformation lässt sich die Chamfer-Distanz nun einfach als Korrelation mit dem Tempate berechnen.

^64866f

## Hough Transform

- Für Linien mit $y=mx+b$: Jeder Bildpunkt entspricht einer Linie im Hough-Raum -> Schnittpunkt von Hough-Linien entspricht Linie im Bild
- Für Linien mit $d=x \cos \theta + y \sin \theta$: Jeder Bildpunkt entspricht Sinusoid im Hough-Raum

- Für Kreis:
	- $r^2=(x-a)^2+(y-b)^2$
	- Wenn Radius bekannt:
		- Hough-Raum hat Achsen $a,b$
		- Bildpunkt ist Kreis im Hough-Raum
	- Wenn Radius unbekannt:
		- Hough-Raum hat Achsen $a,b,r$
		- Bildpunkt ist Kegel im Hough-Raum
	- Wenn Radius unbekannt, aber Gradientenrichtung bekannt
		- Hough-Raum immernoch $a,b,r$
		- Bildpunkt ist Linie, weil Kreiszentrum nur in eine bestimmte Richtung liegen kann

Falls Rauschen: Hough-Raum diskretisieren 

In der Praxis nicht mehr als 5 Dimensionen im Hough-Raum
Man kann den Hough-Raum auch glätten mit Gauß.

### Mean Shift

Man hat einen sehr hochauflösenden Hough-Raum, und statt einem großen Peak hat man viele kleine auf einem Haufen. Mit Mean Shift findet man das Zentrum von diesem Haufen.

- Definiere eine Region um den Startpunkt
- Berechne Schwerpunkt der Punkte innerhalb dieser Region
- Schwerpunkt - Mittelpunkt der Region = "Mean Shift Vector" -> Vektor, um den der Kreis verschoben wird.

Für die Schwerpunktberechnung kann man die Punkte unterschiedlich gewichten:
- $\text{max}(0, 1-\|x\|^2)$ (Epanechnikov-Kernel, umgedrehte Parabel)
- Konstanter Kernel
- Normalverteilung: $\exp\left( - \frac{1}{2}\|x\|^2 \right)$

Jetzt berechnen wir den Gradienten von diesem Kernel am aktuellen Punkt und erhalten dadurch den Mean Shift Vector.

### Generalisierte Hough-Transformation

Hough mit beliebigen Formen.

- Wir schnappen uns unsere Form und einen Referenzpunkt innerhalb der Form.
- Für jeden Punkt entlang der Form:
	- Berechne Gradienten der Kante (Kantenrichtung)
	- Berechne Vektor zum Referenzpunkt
- Erstelle Lookup-Tabelle:
	- Für eine bestimmte Gradientenrichtung: welche Referenzvektoren kommen vor?

Im Bild:
- Für einen Kantenpixel $x$:
	- Bestimme Gradientenrichtung $\theta$
	- Schaue für $\theta$ alle Referenzvektoren $r_{i}$ in der Lookup-Tabelle nach
	- Votiere für alle Punkte $x+r_{i}$.
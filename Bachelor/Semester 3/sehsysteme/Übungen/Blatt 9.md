# Blatt 9

- Henning Lehmann

## Aufgabe 1
![[Pasted image 20231217021532.png]]

Wenn die Maximaextraktion nur Felder mit Wert 8 berücksichtigt, werden nur "perfekte Kreise" im Sinne der genannten Formel gefunden.

## Aufgabe 3

*Nr. 1*
Die Geradengleichung $y = a + mx$ ist aus verschiedenen Gründen ungeeignet für die Hough-Transformation:
- Eine vertikale Gerade kann wegen $m = \pm \infty$ nicht dargestellt werden.
- Um einen konstanten Winkel zwischen den betrachteten Geraden zu erhalten, müsste sich $m$ auf nichtlineare Weise ändern, wodurch die Komplexität der Berechnung steigt und numerische Ungenauigkeiten entstehen können.
- Für steile Geraden kann $a$ betragsmäßig sehr groß werden, wodurch $a$ nur ungenau oder überhaupt nicht dargestellt werden könnte.

*Nr. 2*
Ein betrachteter Pixel $(x, y)$ votiert für alle Punkte $(x_{i},y_{i})$, welche die Gleichung $$\frac{(x-x_{i})^{2}}{a^{2}}+ \frac{(y - y_{i})^{2}}{b^{2}}=1$$ erfüllen, mit Länge der horizontalen Halbachse $a$ und Länge der vertikalen Halbachse $b$.

Der Hough-Raum hat also vier Dimensionen.

*Nr. 3*
Vier Parameter:
- x-Koordinate $x_k$ des Bildausschnittes
- y-Koordinate $y_k$ des Bildausschnittes
- Länge der horizontalen Achse (Breite des Templates)
- Länge der vertikalen Achse (Höhe des Templates)


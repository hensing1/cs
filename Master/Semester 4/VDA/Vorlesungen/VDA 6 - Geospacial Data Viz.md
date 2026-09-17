[[vda-06-Geospatial-Visualization.pdf]]

Darstellung von Daten auf Karten

Parametrisierung von Weltkarte: Längengrad $\phi$ (-90° bis 90°) und Breitengrad $\lambda$ (-180° bis 180°) - ein Grad weiter eingeteilt in 60 Minuten und dann 60 Sekunden

## Weltkartenprojektionen

*Conformity:* erhält lokal Winkel und Umrisse

Konformität und Erhalt von Flächen kann mit **Tissot's Indicatrix** illusitriert werden, die Kreise über dem Erdball verteilt und dann zeigt, was mit diesen Kreisen bei einer bestimmten Projektion passiert

- Equirectangular
	- $x := \lambda$, $y := \phi$
	- weder konform noch Flächenerhaltend
- Mercator
	- $x:= \lambda$, $y := \ln\left( \tan\left( \frac{\pi}{4}+\frac{\phi}{2} \right) \right)$
	- konform
	- Flächen werden zu den Polen hin (unendlich) stark aufgeblasen
- Lambert
	- $x := \lambda$, $y := \sin \phi$
	- Flächenerhaltend
	- konform am Äquator
- Gall-Peters
	- $x := \lambda$, $y:= 2 \sin \phi$
	- Flächenerhaltend
	- konform bei $\phi = \pm 45°$ ($+45°$ ist Europa)
- Sinusoid
	- $x := \lambda \cos \phi$, $y := \phi$
	- parallele Linien bleiben (lokal) parallel
	- Äquator und Nullmeridian bleiben gerade
	- Pole sind spitze Ecken
- Mollweide
	- flächenerhaltend

## Punkt- und linienbasierte Vis

Wir haben punktweise Daten auf einer Karte (Events).

*Proportional Symbol Map:* Punkte werden mit einem numerischen Wert, der zu dem Event gehört, skaliert
Problem: Events mit Wert 0 können nicht dargestellt werden

Da Menschen schlecht im abschätzen von Flächen sind: Kreise etwas schneller mit dem Wert wachsen lassen, als es für die Fläche passen würde: $$r=r_{0}\left( \frac{v}{v_{0}} \right)^{0.5716}$$
für einen Referenzwert $r_{0}$ mit Radius $v_{0}$. "Korrekt" für die Fläche wäre ein Exponent von $0.5$.

*Graduated Symbol Map:* Die Mengen werden erst in Klassen diskretisiert (gibt dann eine Symbolgröße pro Klasse)

Zusätzlichen Infos können auch noch hinzugefügt werden, z.B. als Farbe, oder die Kreise können zusätzlich Tortendiagramme sein, etc.

*Dot Density Map:* Jeder Punkt repräsentiert eine gewisse Anzahl, kein konkretes Event (exakte Platzierung ist nicht genau spezifiziert) - Anzahl, für die ein Event steht, muss so gewählt werden, dass Overdraw vermieden wird

*Flow Map:* zeigt Pfeile auf der Karte, deren Breite mit der entsprechend bewegten Menge korreliert

## Flächenbasierte Vis
*Choropleth Maps:* jede Fläche (z.B. Stadtteile) werden eingefärbt - Normalisierung der Werte wichtig, da Wert sonst stark mit Fläche korreliert
Binning, und welche Flächen aggregiert werden, kann das Aussehen stark beeinflussen

*Dasymetric Maps:* zeigen Dichte nur in den Arealen, wo die Werte tatsächlich 

*Isarithmic Maps:* zeigen Isolinien

*Cartograms:* verzerren die Fläche, damit sie dem zugrundeliegenden Wert entspricht
- noncontinuous: einzelne Flächen werden, ohne ihre Form zu verändern, geschrumpft
- noncontiguous: Topologie (Nachbarschaft) nicht erzwungen
- diagrammatic: Flächen werden abstrahiert und auf einen einfache Fläche (z.B. Quadrat oder Kreis) reduziert
- continuous: Flächen werden mit dem Nintendo DSi Aufblähtool aufgeblasen oder verkleinert

## Scattered Data Interpoation
Z.B. Wetter-Messdaten interpolieren

### Inverse Distance Weighting
Gewichteter Durchschnitt der umliegenden Punkte: $$\hat{f}(x)=\frac{\sum_{i}w(x-x_{i})y_{i}}{\sum_{i}w(x-x_{i})}$$
mit $f(x_{i}) := y_{i}$ und Gewichtungsfunktion $w(x-x_{i})=\|x-x_{i}\|^{-p},\ p>0$.
Mit Parameter $p$ kann man die Smoothness steuern.

Problem mit IDW: Gewichtungen werden problematisch, wenn Punkte ungleichmäßig verteilt sind (z.B. mehrere Wetterstationen nah beieinander)

### Kriging
Auch gewichteter Durchschnitt: $$\hat{f}(x)=\sum_{i}\lambda_{i}y_{i}$$
aber $\lambda_{i}$ wird optimiert, sodass $$E\left[ \left( \sum_{i}\lambda_{i}y_{i}-f(x) \right)^{2} \right]-2m\left( \sum_{i}\lambda_{i}-1 \right)$$
minimiert wird. Der Term links ist der erwartete Vorhersagefehler (durch ein geschätztes $f(x)$), und der rechte Term sorgt dafür, dass sich die $\lambda_{i}$s möglichst auf 1 summieren (unbiased).

Die Schwierigkeit liegt nun darin, $f(x)$ zu schätzen.
Annahme: wenn zwei Punkte $x_{i},\ x_{j}$ nah beieinander sind, ist die erwartete Varianz gering.
Die Varianz wird geschätzt als $\text{Var}(f(x_{i})-f(x_{j}))=2\gamma(x_{i}-x_{j})$. 
- $\gamma(\varepsilon>0)$ nennen wir *Nugget*, also erwarteter Messfehler oder Diskontinuitäten
- $\gamma$ steigt an mit steigendem Argument - der Bereich, in dem das passiert, ist die *Range*, also die Distanz ab dem zwei Werte unkorreliert werden
- Dann kommt der *Sill*, wo $\gamma$ nicht mehr Ansteigt und die Varianz des gesamten Prozesses erreicht wird

Wir sagen, dass es von der konkreten Richtung von $x_{i}$ nach $x_{j}$ nicht abhängt, es ist also *isotropisch*.
$\gamma$ wird meist empirisch gesetzt.


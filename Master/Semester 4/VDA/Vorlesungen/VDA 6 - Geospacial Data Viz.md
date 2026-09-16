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
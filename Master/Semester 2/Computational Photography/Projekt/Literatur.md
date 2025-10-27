# Ziel des Projekts

- **Photometric Normal Map** und **Albedo Map** vom eigenen Gesicht erstellen

Worum geht's: "Photometric Stereo with Spherical Gradient Illumination"

**Normal Map:**
- Objektnormalen bestimmen
- Rekonstruktion und re-illumination der 3D-Szene mit 2D-Aufnahmen

**Albedo Map:**
- Textur, die die Farbe des Objekts unter neutraler Belichtung (ohne Schatten oder sonst was) beschreibt

**Photometric Stereo:**
- Mehrere Bilder einer Szene (vom selben Blickpunkt)
- Beleuchtung aus verschiedenen Richtungen
- Bestimmung der Normalen für jeden Pixel

# Literatur

## Photometric Method for Determining Surface Orientation from Multiple Images (Woodham)
*Classic photometric stereo*



## Image-Based Lighting (Paul Debevec)
[video](https://dl.acm.org/doi/10.1145/1185657.1185686)
Stand: 2006

- Echte Umgebungsszene
- Computergeneriertes Objekt eingefügt mit realistischer Beleuchtung

- Backdrop für die Szene mit HDR-Bild
- Raytracing
	- Fall 1: Strahl trifft den Backdrop direkt (einfach)
	- Fall 2: Strahl trifft auf spekulares Objekt (Glas): Teil wird direkt reflektiert und trifft Backdrop, anderer Teil wird gebrochen (in Objekt hinein) und weiterverfolgt
	- Fall 3: Strahl trifft auf diffuses Objekt
		- kompliziert, denn dieser Punkt erhält Licht aus allen Richtungen
		- wir machen Sampling in alle Richtungen
			- problematisch, wenn man nur eine sehr kleine Lichtquelle hat - wird evtl. nicht vom Sampling getroffen
			- wird sie durch Zufall doch getroffen, ist sie überrepräsentiert (nicht die gesamte Umgebung ist so hell wie die Lichtquelle)
			- -> Pixel sind entweder zu dunkel oder viel zu hell

Eine Lösung für zu helle Punktlichtquelle im Backdrop (bspw. Sonne):
- Lichtquelle maskieren, den Rest als normalen Backdrop verwenden
- Die Lichtquelle selbst als traditionelle Punktlichtquelle modellieren
	- Farbe: Durchschnittsfarbe der maskierten Pixel
- Zwei Renderings: einmal ohne Sonne (Raytracing), einmal mit, dann zusammenaddieren

Was auch geht: die ganze Umgebungsszene downsamplen und jedes Pixel mit einer Lichtquelle ersetzen, dann die Szene mit "traditionellen" Rendering-Methoden beleuchten. Auch ohne *global illumination system* (sorgt für indirekte Beleuchtung durch Szenen-reflektierte Strahlen) und ohne HDR-Umgebungsbild sieht das dadurch noch recht überzeugend aus. 

Besser als Downsampling: Lichtquellen tendenziell dort verteilen, wo sich das Licht in der Szene befindet. Geht mit *Median cut algorithm*:
- Bild abwechselnd horizontal und vertikal in zwei gleich leuchtkräftige Teile teilen
	- Geht effizient irgendwie mit summed area tables
- Am Ende eine Lichtquelle pro Region, mit der Durchschnittsfarbe dieser Region

*Importance Sampling*
- Beleuchtung nicht uniform samplen, sondern helleren Pixeln größere Wahrscheinlichkeit zuordnen
	- -> approximiert reale Beleuchtung korrekt
	- pdf (probability distribution function) nehmen
	- cdf (cumulative distribution function) daraus berechnen
	- uniform Werte für y-Achse generieren und passenden x-Wert der cdf finden -> W'keit-Sampling gemäß pdf
- Helligkeitswerte der Pixel sind Werte für die pdf
- Für 2D: Helligkeiten aller Spalten aufsummieren -> pdf für Spalten -> samplen und dadurch Spalte wählen -> danach Spalte samplen

*Ambient Occlusion*
- Szene einmal mit image based lighting ausleuchten, als wäre komplette Umgebung eine weiße Kugel
	- geht mit sehr wenigen Strahlen, da keine Varianz in der Umgebung
	- produziert weiche Schatten und dunkelt verdeckte Stellen ab
- Szene ein zweites Mal diffus ausleuchten:
	- Normalenvektor der Szene nehmen
	- damit einen Punkt in der geblurten Umgebungs-Map indizieren
	- keine Schatten
- diese beiden Bilder miteinander multiplizieren

*Sphere Blockers*
- Szene für Schattenwurf mit vielen kleinen (überlappenden) Kugeln approximieren
- Raytracing geht dadurch schneller
- Schatten sind immer noch gute Approximierung


Sampling anhand BRDF

**Re-Lighting mit diesen Technicken**
- Dasselbe Subjekt aus derselben Perspektive mit Beleuchtung aus verschiedenen Richtungen nehmen
- Umgebungs-Map der Zielumgebung nehmen
- Diese Re-Samplen anhand der Beleuchtungsrichtungen, die man aufgenommen hat
- Beleuchtungsbilder des Subjekts anhand Farbe und Helligkeit der re-gesampelten Umgebungsmap skalieren
- wieder aufaddieren


## Rapid Acquisition of Specular and Diffuse Normal Maps from Polarized Spherical Gradient Illumination


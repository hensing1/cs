Datum: 16.04.
[[pho1-02-camera.pdf|Folien]]

# Kameras

> Die Pixel auf einem Kamerasensor sind Photonenzähler.

- Monochromkamera:
	- mehr Licht pro Pixel, da nichts gefiltert wird -> kürzere Belichtungszeiten
- Farbkamera:
	- Man kann das einfallende Licht mit einem Strahlenteiler aufteilen und dann drei Chips (mit Rot-, Grün- bzw. Blaufilter) verwenden
	- Nimmt man nur einen Chip, müssen sich Rot-, Grün- und Blaupixel denselben Sensor teilen und auf irgendeine Weise angeordnet werden:
		- Bayer-Filter: 
			- wird in den meisten Kameras verwendet

![[Sensorpatterns.png|500]]

## Demosaicing
Jeder Farbpixel im Bayer-Filter wird zu einem RGB-Pixel im Bild. Also müssen die beiden fehlenden Farben von den Nachbarpixeln interpoliert werden.
Je nachdem, wie interpoliert wird, können damit farbliche Artefakte auftreten

## Rolling Shutter, Global Shutter

Rolling Shutter: Chip wird zeilenweise ausgelesen -> Scherung bei Bewegung
Global Shutter: alle Pixel messen zur selben Zeit und können sich diese Information merken, bis sie ausgelesen werden

## Kameras und geomietrische Optik
![[Optik#Strahlenmodell (Geometrische Optik)]]


**Pinhole-Kamera:** ^6603db
- alles ist scharf (nah und fern)
- Bild wird falsch herum auf die Rückwand der Kamera geworfen
**Kamera mit Linse:**
- Schärfe hängt von der Entfernung des Objekts ab (bzw. von der Entfernung zum Chip)
- Linse ist Approximation des Pinhole Models. Das funktioniert nicht mehr bei Weitwinkellinsen.
- Dünne Linse: modellierbar mit Pinhole Model, unter Annahme von flachem Chip
- Je größer die Blende werden kann, desto besser (teurer) muss die Linse sein
- f/22: kleine Blende, f/1.8: große Blende

In der Photogrammetrie möchten wir gerne alles scharf haben, also mögen wir kleine Blenden.
Wir mögen auch Telefoto-Linsen, da die perspektivische Verzerrung minimiert wird.

Wenn wir eine Kamera (z.B. mit dünner Linse) mit dem Pinhole-Kameramodell beschreiben, treffen wir folgende Annahmen:
	1. Alle Strahlen eines Objektpunktes schneiden sich im selben Punkt
	2. Alle Bildpunkte liegen auf einer Ebene (Sensor ist flach)
	3. Alle Strahlen von Objekt- zu Bildpunkten verlaufen geradlinig

### Aberrationen

> Eine Aberation ist eine Abweichung vom idealisierten Strahlenverlauf unter dem Pinhole-Kameramodell.

*Verzerrung:* gerade Linien von Objekten werden im Bild gekrümmt

*Sphärische Aberration:* Strahlen, die die Linse weiter außen treffen, werden stärker gebrochen

*Chromatische Aberration:* Verschiedene Wellenlängen werden verschieden gebrochen

*Astigmatismus:* Fokuspunkt in der vertikalen Ebene ist verschieden vom Fokuspunkt der horizontalen Ebene

*Coma:* Kombination aus sphärischer Aberration und Astigmatismus, wenn das einfallende Licht von der Seite kommt

*Vignette:* Helligkeit fällt zum Bildrand hin ab

## Wellenoptik

![[Optik#Wellenmodell (Physikalische Optik)]]

Chlorophyll ist sehr reflektiv für Infrarotlicht.
Es gibt Hyperspektralkameras, die Bilder mit allen möglichen Wellenlängen gleichzeitig aufnehmen können $\to$ Bilder werden zu Datacubes, mit der Wellenlänge als dritte Dimension

### Quantenoptik
![[Optik#Teilchenmodell (Quantenoptik)]]


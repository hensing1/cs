Datum: 19.10.
[[Robotik_02_Sensoren.pdf]]

Übung: [[Uebung_01.pdf]]

# Sensoren

## Abstandssensoren
Dieselbe Messung wird oft von verschiedenen Messgeräten durchgeführt, für Redundanz / höhere Genauigkeit.
Abstandsmessung z.B. zum Erkennen von Hindernissen oder an Fingerspitzen.

### Ultraschall-Abstandssensoren
- Wenn man weiß, wie schnell sich der Schall durch das entsprechende Medium bewegt, kann man mit akustischen Pings (> 20 kHz) nach Reflektionen horchen und damit Abstände bestimmen
- Schallgeschwindigkeit:
	- 0°C: 330 m/s
	- 20°C: 343 m/s
	- 40°C: 355 m/s
- Anwendungen:
	- Abstandsmessung
	- Hindernisvermeidung (kurze Reichweite)
	- Kartierung der Umgebung (lange Reichweite)
- Nicht jedes Objekt reflektiert Schallwellen gleich: durch manche propagiert der Schall weiter, manchmal wird der Schall vom Sender wegreflektiert
- Minimale / Maximale Messdistanz muss bedacht werden (hängt von Lautstärke & Frequenz ab)

Bei Ultraschall-Detektoren muss man den Detektionswinkel beachten (Dinge $\pm 15°$ werden noch erfasst).
Parksensoren funktionieren übrigens mit Ultraschall.

#### Ultraschall-Eigenschaften
Das Echo ist umso besser, je größer die dem Sensor zugewandte Oberfläche ist.
Große, raue Objekte können besser erkannt werden: man möchte keinen akustischen Spiegel haben, sondern eine Art diffusen Reflektor.
*Je kleiner die Wellenlänge, desto besser können glatte Oberflächen erkannt werden.*

Je breiter der Schallkegel ist, desto größer ist der Messfehler, falls man eine schräge Oberfläche detektiert:
![[Schalldetektor_ist_kurzsichtig.png|350]]

Hindernisse werden unter Umständen inkorrekt oder gar nicht erkannt: 
![[Halluziniertes_Hindernis.png|350]]

![[Totalreflektion.png|500]]

Es können Mehrfachreflektionen auftreten:
![[Mehrfachreflektion.png|250]]

### Infrarot-Abstandssensoren
IR-Lichstrahl wird reflektiert, die Entfernung wird per Triangulation bestimmt:
![[IR-Triangulation.png|450]]

Je nachdem, wo die Reflektion auf dem ccd-Dings auftrifft, ist die gemessene Spannung dort höher oder niedriger. Zwischen Spannung und Abstand besteht aber kein linearer Zusammenhang, sodass die Kalibrierung schwieriger und die Genauigkeit nicht allzu hoch ist.
Nur für kleine Messdistanzen geeignet.

### Laser-Scanner (LIDAR)
Stark fokussierter Laserstrahl wird gesendet, und es wird die Zeit gemessen, bis er zurückkommt. 
Das Ding rotiert, also kann man einen großen Sichtbereich erfassen.
- 270° Sichtbereich
- 0,5° Winkelauflösung
- 30m Messbereich, 5cm Genauigkeit

Messung nur in einer Ebene (Laserstrahl ist nicht nur horizontal, sondern auch vertikal stark fokussiert).
Es gibt auch teure Messgeräte, die so rotieren, dass sie das gesamte Umfeld erfassen.
Man kann auch einen billigeren 2D-Scanner um eine zweite Achse rotieren.

### Time-of-Flight-Kameras
Mit einer solchen Kamera kann man flächenmäßig Tiefenmessungen machen (gleichzeitig, ohne das Gerät irgendwo entlang rotieren zu müssen).
Das funktioniert, indem man die Phasenverschiebung von moduliertem Licht misst.
- Genauigkeit: 0,3 bis 5,0m, $\pm$ 1cm Genauigkeit
- bis zu 54 FPS
- evtl. Artefakte an Objektkanten
- Für geringe Abstände sind diese Kameras sogar einigermaßen günstig.

Microsoft Kinect: liefert Farb-, Tiefen- und Infrarotbild

*Problem bei Phasenverschiebung*
Man weiß unter Umständen nicht, ob zwei Wellen um z.B. 0.5, 1.5, 2.5 etc. Wellenlängen verschoben sind. 
Man kann aber zumindest Annahmen über die Kontinuität von Oberflächen messen (kein Phasensprung -> wahrscheinlich noch dasselbe Objekt).
Man kann auch Mehrfachmessungen mit verschiedenen Frequenzen machen, um die Mehrdeutigkeiten zu vermeiden.

### Radar
- Beleuchten Szene mit Radiosignal (77 - 81 GHz) und messen die Rücklaufzeit
- Geschwindigkeitsmessung durch Doppler-Effekt
	- praktisch z.B. für Autos, um Geschwindigkeit des Vorausfahrenden zu erkennen
- Funktionieren auch bei Rauch und Nebel
- Hohe Reichweite (150m), mittlere Genauigkeit

## Kameras

### Stereo-Kameras
Disparität zwischen zwei Bildaufnahmen aus verschiedenen Blickwinkeln lässt auf Tiefe schließen, wenn man vorher Korrespondenzen gefunden hat.
Problem: die Korrespondenzen zu finden, ist nicht trivial.
Mögliche Lösung: man kann die Szene mit einem pseudo-zufälligen IR-Muster beleuchten, damit man herausbekommt, welche Bildteile zueinander gehören.

Außer durch Disparität kann man auch noch durch Objektgröße, Shading u.a. auf Tiefe schließen.

### Lichtkameras
Der Lichtsensor besteht aus 50% grünen, 25% blauen und 25% roten Farbzellen (im Bayer-Muster).
Daher ist z.B. bei schwarz-weiß-Übergängen im Bild eine Farbinterpolation erforderlich.

In der High-Level Vision kann man Objekte visuell voneinander unterscheiden (vgl. [[INF 131 - Intelligente Sehsysteme]]).

### Thermalkameras
Gut, um Menschen / Tiere zu erkennen, oder zur Detektierung von Brandherden.

## Encoder

Man hat einen Schwarz-Weiß-Code an Drehgelenken, um die Drehrichtung und -geschwindigkeit festzustellen. 
Siehe auch [[Korrektur von Übertragungsfehlern#Gray-Code|Gray-Code]].

Das ganze geht auch mit einem Drehwiderstand (Potentiometer) oder einem Magnet-Encoder, der über den Hall-Effekt misst, wie ein Magnet ausgerichtet ist oder bewegt wird.

## Intertialsensoren (IMUs)
### Orientierungssensor
Besteht aus:
- Beschleunigungssensor
	- Messung der Erdbeschleunigung
- Drehratensensor
- Kompass

## Sonstige
- Oberflächensensoren
	- Es gibt künstliche Häute, die Postion und Druckkraft auf ihrer Oberfläche erkennen können.
- Mikrofone
- Hall-Sensoren
	- Können Vibrationen beim Streichen von Oberflächen erkennen, um zwischen rauen und glatten Oberflächen zu unterscheiden
- Künstliche Nase

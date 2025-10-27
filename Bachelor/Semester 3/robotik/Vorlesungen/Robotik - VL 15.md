Datum: 01.02.
[[Robotik_15_Pfadplanung__Wahrnehmung.pdf|Folien]]

# Robotis

## Flugroboti

*Sensoren:*
- Rotierender 2D-Laserscanner
- Weitwinkelkameras
- Ultraschallsensoren
	- für sowas wie Fenster

Egozentrische Planung ist nahe am Roboter genauer, verfeinert die allozentrische Planung

Allozentrische Planung:
3D-Pfad mit A* durch Voxel-Gitter

Lokale Multiresolution:
- Neuplanung mit hoher Rate


## Dynamische Trajektorienplanung

Wir planen nicht nur die Trajektorie bezüglich Position, sondern auch Geschwindigkeit

## Planung mit Sichtbarkeitsbeschränkung

Wir versehen unentdeckte Gebiete mit mittleren Kosten
Manchmal kann ich nicht in die Richtung messen, in die ich fliegen möchte (z.B. nach oben). 
Planung vom Pfad so, dass ich auch messen kann, wohin ich fliege (resultiert im Beispiel in Spirale)

Kostenoptimale Bestimmung von Beobachtungsposen, wenn eine bestimmte Pose eingenommen werden soll, aber wegen Hindernissen nicht eingenommen werden kann


## SMPA-Architektur

Sense -> Model -> Plan -> Act


...

Man kann Bilder aus einer Fisheye-Linse entzerren, das ist aber teuer und es ist besser, das erst mit den extrahierten Features zu machen

... 
Partikel Filter:
- Jede Hypothese ist durch Partikel repräsentiert
- Hypothesen können fortgeschrieben werden ("was passiert, wenn ich nach vorne laufe")
- Wahrscheinliche Hypothesen werden verstärkt und vervielfältigt
- Man vergleicht die Messung, die man *macht*, mit den Messungen, die man gemäß der Hypothesen machen *müsste*
- Wenn man ungefähr weiß wo man ist, propagiert man die Hypothesen mit einem Gewissen rauschen
- Propagieren: erhöht Unsicherheit und Anzahl von Hypothesen
- Messung: verringert Unsicherheit und Anzahl von Hypothesen


## Neuronale Netze

Gedöns

### Deep Lernmimg

Objekte bestehen aus Teilen, und so weiter
Wir erkennen erst die Teile und dann die Zusammensetzung von Teilen und dann die Zusammensetzung von Zusammensetzungen und am Ende den Elefant

## Computah Vishn

Schlecht gestelltes Problem und sowas

Luminanzkram: man versucht zu schätzen, wie stark irgendeine Fläche beleutet wird / reflektiert
Dann versucht man zu unterscheiden zwischen Beleuchtungskanten (gleiche Farbe, verschiedene Beleuchtung) und Reflektions(?)kanten (verschiedene Farben, gleiche Beleuchtung)

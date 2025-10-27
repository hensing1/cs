Datum: 26.10.
[[Robotik_03_Aktuatoren_Gelenke.pdf]]

Übung: [[Uebung_02.pdf]]

## Aktuatoren

*Energiequellen*
- Elektrik
- Pneumatik
	- Komprimierte Luft - hohe Energieverluste
- Hydraulik
- Chemisch
	- hohe Energiedichte

Steuerung über Motoren oder Ventile, benötigen häufig Feedback über Sensoren.

### Elektromagnetische Aktuatoren

#### Gleichstrommotoren
- Drehzahl hängt von Spannung ab
- Durch Schleifkontakte werden immer andere Spulen angesteuert, damit sich der Motor weiterdreht
- kann kurzfristig überlastet werden
- Graphitstäbchen/Metallbürsten nutzen sich ab
- Motor funktioniert wie Generator, erzeugt also Gegenspannung -> konstante Leerlaufgeschwindigkeit wird erreicht

Viel Strom -> viel Drehmoment (ungefähr linear Abhängig)

##### Ansteuerung
H-Brücke: Controllerdings, kann an- und ausschalten für PWM. Man steuert die Drehzahl über PWM statt über die Anpassung der Spannung.

Modi:
- Vorwärts (1 und 2)
- Rückwärts (3 und 4)
- Bremsen (2 und 4 bzw. 1 und 3, schließt den Motor kurz)
![[H-Brücke.png|250]]

##### Bürstenlose DC-Motoren
- Keine Bürsten -> keine Abnutzung, hohe Drehzahlen
- Viel Leistung pro Gewichtseinheit
- Ansteuerung komplizierter als bei Bürstenmotoren
	- wenn er sich langsam dreht, braucht man zusätzliche Sensoren, um zu messen wie der Motor steht -> zusätzliche Elektronik erforderlich

#### Schrittmotoren
Drehen sich schrittweise, brauchen teilw. keine Steuerungselektronik
![[Schrittmotor.png|350]]

#### Linearmotoren
Können sich mit hoher Präzision & Geschwindigkeit, aber geringer Kraft an einer Magnetstange entlangbewegen

## Getriebe
Getriebe sind wichtig, da Elektromotoren nur bei schneller Rotation effizient sind.

- Stirnrad
	- zwei Zahnräder
- Schneckenrad
	- Ein Zahnrad, eine sich drehende Schnecke
	- nicht gut rücktreibbar
		- schlecht, wenn man z.B. beim Aufkommen den Motor rückwärts drehen und dadurch Energie rückgewinnen möchte
- [Planetengetriebe](https://de.wikipedia.org/wiki/Umlaufr%C3%A4dergetriebe)
	- Bestandteile:
		- ein kleines Zahnrad innen (Sonnenrad)
		- ein großes Hohlrad außen
		- mehrere Umlaufräder dazwischen
		- Steg, der die Umlaufräder relativ zueinander festhält
	- Betriebsmodi:
		- Steg fest: Umlaufrad läuft langsam entgegen dem Sonnenrad
		- Hohlrad fest: Steg läuft langsam mit dem Sonnenrad
		- Sonnenrad fest: Steg läuft langsam mit dem Hohlrad
	- Übersetzungen von 1:3 bis 1:9

Bei hohen Übersetzungen sind Getriebe so gut wie nicht rücktreibbar.

- Wellengetriebe:
	- Man hat ein elliptisches Ding in der Mitte (Antrieb), das einen flexiblen Zahnradring (Abtrieb) in einem Hohlrad dreht
	- Bei einer Umdrehung der Ellipse dreht sich der Ring zwei Zähne weiter
	- Am besten erklärt mit [gif](https://de.wikipedia.org/wiki/Harmonic_Drive)
	- sind spielfrei (wackelt nicht)
	- Hohe Untersetzung
	- Teuer

- Zykloidgetriebe
	- alles eiert irgendwie rum

- Gewindestange
	- schnelle Drehbewegung -> langsame, kräftige Linearbewegung

- Zahnriemen und Ketten
	- wie beim Fahrrad
	- Kette/Riemen muss gespannt werden

- Flaschenzug
	- Übersetzung: 1-zu-AnzahlUmleitungen

## Aktuatoren mit Getrieben

### Servos
Modellbauservos sind ne gute Sache.
Bestehen aus:
- Elektromotor
- Getriebe
- Sensor
- Regelelektronik

Pulsweite des Steuerungssignals: gewünschte Zielposition

#### Dynamixel-Servo
Kommerziell erhältlicher Servo.

Man kann ihm Zielposition, Drehgeschwindigkeit, Drehmoment und Nachgiebigkeit als Parameter übergeben.
Messen kann er Position, Geschwindigkeit, Belastung und Temparatur.
Man kann ihn fragen, wie es ihm geht

### Quasi-Direct-Drive
Man hat einen bürstenlosen DC-Motor mit integriertem Planetengetriebe. Dadurch hat man ein hohes Drehmoment, außerdem ist das Ding rücktreibbar.
Man hat aber etwas Spiel im Getriebe.

Wenn man mehr Drehmoment haben möchte, gibt es die auch mit einem zweistufigen Planetengetriebe.

### Seriell-elastische Aktuatoren
Man hat zwischen Antrieb und Getriebe eine Feder. Dadurch kann man nachgiebige Gelenke basteln - man kann zudem den Antrieb so programmieren, dass er sich wie eine Feder verhält.

### Pneumatische Aktuatoren
- Bewegen sich durch Luftdruck
- Können nicht drücken, sondern nur ziehen -> man braucht antagonistische Antriebe (also zwei gegenläufige Aktuatoren)
- Kontinuierliche Drehung geht auch
- So eine Art Muskel geht auch

### Hydraulische Aktuatoren
Druck wird durch Flüssigkeit übertragen. Wenn die hydraulische Flüssigkeit austritt, kann das gefährlich werden.
Hydraulik-Motoren, die sich kontinuierlich drehen, gibt es auch.

Man kann damit sehr hohe Kräfte erzeugen (Beispiel Wagenheber).

### Piezo-Aktuator
Man hat Kristalle, die sich bei Anlegen einer elektrischen Spannung ausdehnen. Die Kräfte sind so mittelgroß und die Distanzen klein, aber man kann es sehr präzise steuern.
Ultraschall-Piezomotoren können sich sehr schnell drehen, haben aber eine geringe Kraft. Sie sind selbsthaltend, wenn der Strom ausfällt.

### Verdrillungsantrieb
Man hat zwei parallele Gummibänder an einem Motor hängen. Dreht sich der Motor, verdrillen sich die Bänder und es enteht eine Zugbewegung.

## Gelenke
Man hat insgesamt 6 Freiheitsgrade zwischen 2 Starrkörpern (3 Verschiebungen, 3 Drehungen)

Ein Gelenk schränkt die Freiheitsgrade zwischen zwei Starrkörpern gezielt ein.

Die Bewegung kann man mathematisch modellieren, siehe [[Robotik - VL 4|nächste Vorlesung]].
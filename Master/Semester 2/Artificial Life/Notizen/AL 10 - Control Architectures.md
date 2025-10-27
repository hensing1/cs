[[ALSS25_10_Complex_Behavior_Braitenberg_Vehicles.pdf]]

Wir diskutieren Architekturen zur Steuerung von autonomen Agenten.
Agenten haben:
- Sensorik, um die Umwelt wahrzunehmen
- Logik, um die Sensordaten zu verarbeiten
- Aktorik / Motorik, um Aktionen in der Welt vorzunehmen

**Reaktive Steuerung**
Die Sensordaten werden direkt auf Motordaten abgebildet.

**Proaktive Steuerung**
Der Controller hat ein *internes Modell* von der Welt, welches durch Sensordaten aktualisiert wird, und welches zur Planung und Vorhersage verwendet werden kann.

## SMPA-Architektur

- Sense
- Model
- Plan
- Act

Diese vier Schritte werden ggf. nicht nur nacheinander durchlaufen, sondern haben auch Rückkopplungen.

## Systemtheorie

- Wir haben Input $x$, Output $y$ und eine Transferfunktion $g$
- Die Eigenschaften von $g$ können mit Differenzialgleichungen oder Konvolutionen beschrieben werden
- Wir nehmen manchmal die Fourier/Laplacetransformation von alldem, da man im Frequenraum bestimmte Dinge leichter rechnen kann (Konvolutionen, Integrale, Ableitungen)

Wir nennen:
- Das zu kontrollierende System **P** (Plant)
- Den Controller **C**
- Den Aktuator **A**
- Den Sensor S, welcher Feedback **F** gibt.

Zusätzlich haben wir Rauschen **N**.

### Open Loop Control

Wir *steuern* das System. Der Input $X$ muss nicht unbedingt eine Messung sein.
![[Open Loop Control.png]]

### Closed Loop Control
Wir *regeln* das System. Der Controller erhält die *Differenz* zwischen Zielwert $X$ und gemessenem Wert $Y$.
![[Closed Loop Control.png]]

## Braitenberg-Vehikel

### Typ 1

Ein Sensor, ein Motor. Je mehr der Sensor wahrnimmt (z.B. Licht, Wärme, etc.), desto schneller dreht sich der Motor.

### Typ 2

Zwei Typ-1-Vehikel aneinander geklebt. 
Unterschieden wird die Verkabelung von Sensoren zu Motoren:
- 2a: linker Sensor zu linkem Motor, rechter Sensor zu rechtem Motor
	- -> Vehikel *wendet sich ab* von dem, was die Sensoren messen
	- Je weiter weg, desto langsamer
- 2b: Verkabelung über kreuz
	- -> Vehikel *steuert zu* auf das, was die Sensoren messen
- 2c: Beide Sensoren zu beiden Motoren
	- -> selbes Verhalten wie Typ 1

### Typ 3

Verbindungen sind nicht mehr positiv wie in Typ 1 und 2, sondern *hemmend*. Je mehr ein Sensor wahrnimmt, desto langsamer dreht sich der entsprechende Motor.

- 3a: Verbindungen wieder auf derselben Seite
	- -> Steuert auf Quelle zu, wird aber immer langsamer
- 3b: Verbindungen wieder über kreuz
	- -> Wendet sich langsam von Quelle ab

Für 3c Vehikel werden vier Sensorpaare verwendet, die alle etwas unterschiedliches messen. Es werden Typen 2a, 2b, 3a und 3b kombiniert (ein Sensor positiv nicht-kreuzend, einer positiv kreuzend usw.). Die Signale zu den Motoren werden zusammengerechnet.

3b-Vehikel sind am populärsten, da sie gut darin sind, Hindernisse zu vermeiden (wenn die Sensoren Abstandssensoren sind).
Sie können allerdings in Ecken stecken bleiben.

### Typ 4
Während die Typen 1-3 lineare (bzw. affine) Verbindungen zwischen Sensorwert und Motorwert haben, wird diese Beschränkung bei Typ 4-Vehikeln aufgehoben.

Ein 4a-Vehikel kann beliebige kontinuierliche Funktionen haben, bei 4b-Vehikeln sind Diskontinuitäten erlaubt.
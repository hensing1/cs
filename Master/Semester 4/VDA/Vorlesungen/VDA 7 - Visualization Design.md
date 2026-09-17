[[vda-07-Visualization-Design.pdf]]
## Marks and Channels

**Marks** sind geometrische Primitives, we Punkte, Linien und Flächen.
**Channels** sind die verschiedenen visuellen Attribute, die man einem Mark zuweisen kann (Position, Farbe, Form, etc.)

Verschiedene Kanäle haben verschiedene "Effektivität" (von mehr nach weniger): Position, Größe, Ausrichtung, Farbe, Lumineszens, Sättigung, Krümmung

Höhere Effektivität: kleinere Differenzen können mit bloßem Auge auseinandergehalten werden

Von den Kanälen ist *Länge* der einzige, der linear wahrgenommen wird. Andere Kanäle, wie Fläche, Helligkeit oder Sättigung, werden proportional zu einem bestimmten Power Law wahrgenommen

**Pre-Attentiveness:** Attribute heißen pre-attentive, wenn sie direkt (innerhalb ~250ms) wahrgenommen werden können, ohne dass man danach suchen muss

Farbe und Form sind einzeln pre-attentive. Innerhalb einer Farbe ist eine Form nicht mehr pre-attentive, wenn dieselbe Form auch in anderen Farben vorhanden ist

- schiefe Linie unter geraden ist pre-attentive, gerade Linie unter schiefen nicht
- Text ist nicht pre-attentive

 -> effektivere Kanäle, am besten welche die pre-attentive sind, für wichtige Attribute behalten

## Designprozess für Visualisierungen

### 1. Precondition
*Lernen* (über eigenes Projet, Visualisierungsmethoden und menschliche Wahrnehmung Bescheid wissen) -> *Durchstöbern* (mit Leuten reden um (die richtigen) Daten zufinden) -> *Rollen besetzen* (Mensch der das Tool benutzen und damit Daten analysieren will, und häufig auch die Daten selbst erstellt; Mensch der die Daten gatekeept; Leute die das Tool mitbauen)

### 2. Core
*Entdecken* (Forschungsfragen und Analyseprobleme der User verstehen; 5 W-Fragen stellen (was warum wer wo wann)) -> *Designen* -> *Implementieren* (Mock-ups zuerst, existierende Infrastrukturen verwenden) -> *Deployen* 

> Verschachteltes Vis-Modell:
> (Domäne (Aufgabe (Art der Visualisierung (Algorithmus))))
> 
> => gelöste Aufgaben im inneren sind nutzlos, wenn auf höherem Level falsche Entscheidungen getroffen wurden

### 3. Analyse

*Reflektieren* (was kann nächstes Mal besser laufen) -> *Schreiben* (Paper rausbringen wie / wie gut es funktioniert hat)

## Algebraische Perspektive

Das hier:
![[VisDesign als Algebra.png|342]]

heißt: wenn sich Daten ändern, sollen diese Änderungen aus der Visualisierung angemessen ersichtlich sein.

- $\omega$ soll Sinn ergeben, gegeben $\alpha$ (Visual-Data Correspondence)
- für alle wichtigen $\alpha$ soll $\omega$ ersichtlich sein (Unambiguous Data Depiction)
- auffallende $\omega$ sollten ohne Datenänderung $(\alpha=1)$ nicht passieren (Representative Invariance)
	- Rendering-Entscheidungen, die unabhängig von den Daten getroffen werden, sollten nicht die Interpretation des Plots verändern
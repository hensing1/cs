Datum: 11.04.
[[AI02_SS24_Agents_240411_240410.pdf|Folien]]
[[GdKI-SS24-Aufgabenblatt-01.pdf|Übung]]
[[GdKI-Blatt01-Laffargue-Lehmann-Meyer|Lösung]]

# Rationale Agenten

> [!abstract] Definition *Agent*
> Ein Agent ist etwas, das:
> - die Umgebung durch *[[Sensoren]]* wahrnehmen kann (Perzepte), und
> - die Umgebung mit *[[Aktuatoren]]* manipulieren kann (Aktionen).
> 
> Der Agent befindet sich also mit seiner Umwelt in einer Rückkopplungsschleife.

> ***Rationaler Agent***
> Ein rationaler Agent wählt immer die optimale Aktion gemäß einer Zielerreichungsmetrik.

Voraussetzung: Leistungskriterium ist definiert.

*PEAS-Spezifikation* zur Einteilung von Typen von rationalen Agenten:
- Performance (Leistungskriterium)
- Environment
- Actuators
- Sensors.

Davon ist die Umgebung i.A. am wenigsten (im Vorfeld) zu beeinflussen.

> [!note] Spezifizierung der Umgebung 
> - *Vollständig oder unvollständig beobachtbar?*
> - *Deterministisch, stochastisch oder strategisch?*
> 	- Deterministisch: nächster Zustand hängt allein vom aktuellen Zustand und der ausgeführten Aktion ab
> 	- Strategisch: deterministisch bis auf Aktionen anderer Agenten
> 	- Ansonsten: stochastisch.
> - *Episodisch oder sequentiell?*
> 	- Episodisch: Qualität einer Aktion kann innerhalb einer Episode (Perzept + Aktion) bewertet werden
> 	- Sequentiell: Für die Qualitätsbewertung müssen vorherige und/oder zukünftige Entwicklung berücksichtigt werden
> - *Statisch, dynamisch oder semidynamisch?*
> 	- Statisch: die Welt ändert sich nicht, während der Agent reflektiert
> 	- Semidynamisch: die Welt ist statisch, aber ihre Bewertung ist dynamisch
> - *Diskret oder kontinuierlich?*
> 	- Diskret: z.B. Schachspiel
> 	- Kontinuierlich: z.B. reale Umgebung
> - *Einzelagenten oder Multiagenten?*
> 	- Müssen andere Entitäten der Umgebung als Agenten betrachtet werden?
> 	- Andere Agenten können kooperativ oder kompetetiv sein

Beispiel Schachspiel (mit Uhr): vollständig beobachtbar, strategisch, sequentiell (da zukünftige Züge berücksichtigt werden müssen), semidynamisch (da die Zeit während der Bewertung herunterläuft), diskret, Multiagenten.

Wählt ein Agent für alle möglichen Wahrnehmungssequenzen bei gegebenem Weltwissen immer die Aktion, welche die erwartete Leistung maximiert, ist er ein *idealer rationaler Agent.*

## Design von Agentenprogrammen

Zu dem Design eines Agenten gehört die *Architektur* (Sensoren/Effektoren) und der *Programmcode*.

Der Programmcode realisiert im Wesentlichen die Funktion $\text{Agent} : \text{Perzept} \to \text{Aktion}$.

### (Tabellengesteuerte Agenten)

Für jede mögliche Eingabe*sequenz* steht die dazugehörige Aktion in einem Tabelleneintrag.

-> Auswendiglernen, keine Generalisierung

Ist $P$ die Menge der möglichen Perzepte und $T$ die Lebensdauer des Agenten, hat die Tabelle $\sum_{t=1}^{T}|P|^{t}$ Einträge.

### Einfache reflexive Agenten

Keine Perzepthistorie - aktion wird aus aktuellem Perzept bestimmt

-> geeignet für eine vollständig beobachtbare Welt und Lösung einfacher Aufgaben
-> geeignet für Auslösen von Reflexen

### Reflexive Agenten mit Weltmodell

Der Agent hat ein internes Weltmodell. 

In jeder Iteration:
- Aktualisierte das Weltmodell anhand der zuletzt ausgeführten Aktion und dem aktuellen Perzept
- Bestimme die Aktion reflexiv anhand dieses Weltmodells

### Zielorientierte Agenten

Situation: man hat einen reflexiven Agente mit Weltmodell, aber es gibt *mehrere Aktionen*, die in einer bestimmten Situation auszuführen sind.

Soll der Agent ein Ziel verfolgen, muss dieses entsprechend formalisiert sein. Dann muss der Agent bestimmen, welche der verfügbaren Aktionen zum Ziel führt. Diese Aktion wird dann ausgewählt.

### Nutzenorientierte Agenten

Situation: man hat einen zielorientierten Agenten, aber mehrere Aktionen führen ans Ziel.

Die Aktionen müssen also durch eine *Nutzenfunktion* (utility function) mit einem Nutzwert versehen werden.

Potentiell gibt es *mehrere* Nutzenfunktionen für Teilziele, die miteinander im Konflikt stehen (z.B. schnell fahren vs. sicher fahren im Beispiel eines Autos).
Man kann mehrere Teilziele miteinander verrechnen, indem man ihre Wichtigkeit und ihre Erzielbarkeit in Betracht zieht.

### Lernende Agenten

Ein lernender Agent kann sich selbst evaluieren. Er besteht aus vier Komponenten:

- *Performanzkomponente:* eines der obenstehenden Agentenmodelle
- *Bewertung* der bisherigen Performanz
- *Lernkomponente* zur Generierung von Änderungsvorschlägen auf Grundlage der Bewertung
- *Problemgenerator* zur Auswahl von ungelernten Aktionen (Exploration)

![[Lernender Agent.png]]
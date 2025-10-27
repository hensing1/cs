Datum: 15.04.
[[AI03_SS24_Search_240415_240412.pdf|Folien]]

# Suche

Annahme: Wir haben einen Agenten in einer vollständig beobachtbaren Umwelt, deren Zustände statisch und diskret sind. Die Aktionen des Agenten sind deterministisch.

Kennt der Agent nun seinen aktuellen Zustand sowie eine Menge von Zielzuständen, kann er die benötigte Aktionsfolge mit einem *Suchalgorithmus* bestimmen.

Agentenentwurfsschema:
1. Formulierung von Problem und Ziel,
2. Suche nach Lösung,
3. Ausführung der Lösungsschritte.

> [!note] *Problemformulierung*
> Eine vollständige Problemformulierung enthält:
> - Zustandsraum
> - Menge von möglichen Startzuständen aus diesem Zustandsraum
> - Pro Zustand eine Menge von gültigen Aktionen
> - Ein Zieltest, um zu bestimmen, ob ein Zustand ein Zielzustand ist
> - Definition von Aktionskosten

> ***Kosten***
> - Pfad: Folge von Aktionen
> - Lösung: Pfad vom Startzustand zu einem Zielzustand
> - Pfadkosten: Summe der Aktionskosten *(Online-Kosten)*
> - Suchkosten: Zeit- und Speicherbedarf für das Finden einer Lösung *(Offline-Kosten)*

## Allgemeine Suchprozedur

> **General Search**: $(\text{problem, strategy}) \mapsto \text{solution or failure}$
> Initialisiere Suchbaum mit Startzustand von $\text{problem}$
> `while True:`
> > `if` keine Knoten, die expandiert werden können `then return` $\text{failure}$
> > Wähle Blattknoten nach Vorgabe von $\text{strategy}$
> > `if` Knoten besteht Zieltest `then return` Pfad von Wurzel zu diesem Knoten
> > `else` expandiere Knoten und füge resultierende Knoten dem Suchbaum hinzu

Pro Knoten speichern wir:
- Korrespondierender *Zustand* im Zustandsraum
- *Vorgängerknoten* im Suchbaum
- *Operator/Aktion*, die den Knoten erzeugt hat
- *Tiefe* im Suchbaum
- *Pfadkosten* bis zu diesem Knoten

Alle Blattknoten müssen in einer **Warteschlange** gespeichert werden, die gemäß $\text{strategy}$ die Knoten einsortiert.

> [!abstract] Bewertung von Suchstrategien
> - Vollständigkeit (wird immer eine Lösung gefunden, falls wellche existieren?)
> - Optimalität
> - Zeitkomplexität
> - Speicherkomplexität

## Uninformierte Suchverfahren

Sei $b$ der maximale Verzweigungsgrad und $d$ Tiefe der Lösung.


- [[Graphen#Breitensuche|Breitensuche]]: FIFO-Warteschlange
	- Findet immer die Lösung mit geringster Tiefe $\to$ *vollständig* bei endlicher Lösungstiefe
	- *Optimal*, sofern Pfadkostenfunktion eine nichtfallende Funktion der Kostentiefe ist
	- Zeit- und va. Speicherkomplexität steigt exponentiell mit der Suchtiefe
- [[Graphen#Tiefensuche|Tiefensuche]]: LIFO-Warteschlange
	- *Unvollständig*, wenn Baum unendlich tief werden kann
	- *Nicht optimal*
	- Zeitkomplexität steigt exponentiell mit Suchtiefe
	- Speicherkomplexität steigt nur linear mit Suchtiefe
- Iterative Tiefensuche: tiefenbeschränkte Tiefensuche wird iterativ mit wachsender Suchtiefe aufgerufen
	- *Vollständig* und *optimal* wie Breitensuche
	- Lineare Speicherkomplexität wie Tiefensuche ($\mathcal{O}(b \cdot d$))
- Bidirektionale Suche: sucht von Start- und von Zielzuständen gleichzeitig, bis gemeinsamer Zustand getroffen wurde
	- Zeitkomplexität $\mathcal{O}(b^{d/2})$
	- Zu beachten:
		- Operatoren sind nicht immer umkehrbar
		- Zielzustände ggf. nicht vollständig beschrieben (z.B. beim Schach)
		- Effizientes Verfahren benötigt, um zu testen, ob Verfahren einen gemeinsamen Zustand gefunden haben


## Problemklassen

**Einzustandsproblem:**
Die Welt ist vollständig beobachtbar und Aktionen sind deterministisch.
Diese Probleme sind durch obige Suchverfahren lösbar.

**Mehrzustandsproblem:**
Aktionen sind deterministisch, aber die Welt ist unbeobachtbar. 
Der Agent befindet sich also in *Glaubenszuständen* (belief states). Ein Glaubenszustand beinhaltet alle physischen Zustände, die derzeit möglich sind. 
Die Menge aller Glaubenszustände ist also schlimmstenfalls die [[Mengen#Potenzmenge|Potenzmenge]] aller Weltzustände.

Eine Lösung ist jeder Pfad zu einem Glaubenszustand, der vollständig aus Zielzuständen besteht.

Das Suchverfahren muss also auf den Raum der Glaubenszustände angewandt werden. 

**Kontingenzproblem:**
Aktionen sind nicht deterministisch, aber der Agent kann die Umwelt nach einer Aktion erneut erfassen.

Nicht lösbar durch "Formulieren - Suchen - Ausführen", da das Suchverfahren ggf. nach einer Aktion neu angewandt werden muss.
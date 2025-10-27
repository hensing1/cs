# GdKI - Blatt 1

- Hana Laffargue
- Henning Lehmann, 50045776
- Marie Meyer, 50077724

## Aufgabe 2

### a)
FALSCH.
Die Agentenfunktion hat die Form $f: \text{Wahrnehmungssequenz} \times \text{Weltwissen} \to \text{Aktion}$, vgl. Folie 12.
Das Agentenprogramm realisiert die Funktion $g: \text{Perzept} \to \text{Aktion}$, vgl. Folie 20, 25.
Die Eingabe für das Programm ist also lediglich das aktuelle Perzept, und nicht die komplette Perzeptsequenz und das Weltwissen. 

### b)
FALSCH.
Gegenbeispiel: eine Agentenfunktion für einen rationalen Skatspiel-Agenten kann nicht durch ein einfaches, reflexives Agentenprogramm realisiert werden, da sich ein solches Programm nicht merken kann, welche Karten bereits gespielt wurden.

## Aufgabe 3
### a)

| Agent Type                           | Performance Measure             | Environment                                            | Actuators                       | Sensors         |
| ------------------------------------ | ------------------------------- | ------------------------------------------------------ | ------------------------------- | --------------- |
| Fußballspielender Roboter            | Erzielte Tore des Teams         | Teakameraden, Gegenspieler, Fußballfeld, Tore, Fußball | Beine, Arme                     | Kamera          |
| Internetagent zum Kaufen von Büchern | Die korrekten Bücher raussuchen | Buchhandlungs-Websites                                 | mögliche Kaufoptionen auflisten | Tastatureingabe |

### b)

| Task                                 | Observability | Next State    | Evaluation of Actions | Environment | State space | # Agents |
| ------------------------------------ | ------------- | ------------- | --------------------- | ----------- | ----------- | -------- |
| Fußball-spielender Roboter           | fully         | strategic     | sequential            | dynamic     | continous   | multi    |
| Internetagent zum Kaufen von Büchern | fully         | deterministic | episodic              | static      | discrete    | single   |

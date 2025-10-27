[[ALSS25_06_Evolutionary_Algorithms_1.pdf]]
[[ALSS25_07_Evolutionary_Algorithms_2.pdf]]
[[ALSS25_08_Evolutionary_Algorithms_3.pdf]]

## Evolutionary Algorithms

Wir möchten eine **Kostenfunktion** $f: S \to \mathbb{R}$ auf einem Suchraum $S$ minimieren (bzw. Fitnessfunktion maximieren).

*Stochastische Optimierung:* Zufällige Komponente in den Daten / der Zielfunktion / einer anderen Komponente.

Verschiedene Optimierungsmethoden können anhand von analytisch definierten Kostenfunktionen - z.B. einfachen Polynomen, der [Rosenbrock-Funktion](https://infinity77.net/global_optimization/test_functions_nd_R.html#go_benchmark.Rosenbrock), uvm - getestet werden.

> *Evolutionary Computation*
> Oberbegriff für alle möglichen Algorithmen, die von biologischer Evolution inspiriert sind, theoretische Grundlagen dahinter, sowie abstraktere Konzepte wie Schwarmintelligenz.

Evolutionäre Algorithmen verfolgen mehrere Hypothesen zur Zielfunktions-optimierung gleichzeitig. Die einzelnen Manifestierungen der jeweiligen Hypothesen sind *Individuen*.
Alle Individuen bilden gemeinsam die *Population* des evolutionären Algorithmus.

Jedes Individuum $p$ ist definiert durch sein **Genom** $s_p \in S$. ("Genom" ist die gesamte Erbsubstanz eines Individuums, ein "Gen" ist ein spezifisches Segment des Genoms). Im Verlaufe des Algorithmus werden Individuen $q$ mit den schlechtesten Werten für $f(s_q)$ aussortiert (survival of the fittest).

### Schritte eines EA

![[EA_cycle.png|400]]

#### Initialisierung

A-Priori-Wissen sollte bei initialer Genauswahl nach Möglichkeit genutzt werden.
Vom Suchraum $S$ sollte möglichst viel abgedeckt sein (hohe Diversität).

#### Auswahl der Eltern

Es werden $\mu$ Individuen ausgewählt, aus deren Genomen $\lambda$ neue Individuen (Nachkommen) erzeugt werden.

Hierfür gibt es verschiedene Möglichkeiten:

- Zufällige Auswahl
- Elitär (fitnessbasiert):
	-  Obere $x\%$ der nach Performance sortierten Individuen
	- Alle Individuen $p$ mit Performance $f(s_p) > t$ für Threshold $t$
- Stochastisch (fitnessbasiert):
	- Wahrscheinlichkeit proportional zur Fitness (Wheel of fortune)
	- Wahrscheinlichkeit proportional zu [[Neuronale Netze#^04fda6|Softmax]] der Fitness
	- Wahrscheinlichkeit invers proportional zum Rang
	- Turnier: wähle zufällig Individuen aus, vergleiche Fitness von jeweils zweien, die Gewinner kommen in die nächste Runde - höre auf, wenn genug ausgedünnt

Entweder die Elternauswahl passiert nach der externen Selektion, oder parallel dazu (Eltern werden aus kompletter Population gewählt, um Diversität höher zu halten).

#### Vererbung

Je nach Erbungsprozess sind $k$ Eltern an der Erstellung eines Nachkommens beteiligt:

- $k=0$: neues Genom wird vollkommen zufällig generiert (starker Fokus auf *Exploration*)
- $k=1$: komplettes Genom des einen Elternteils wird kopiert (starker Fokus auf *Exploitation*)
- $k=2$: Rekombination der beiden Eltern-Genome (s.u.)
- $k \geq 3$: abnehmender Nutzen im Hinblick auf Vererbung der besten Gene

##### Rekombination

Cross-over: es werden zufällig $N \geq 1$ Crossover-Punkte gewählt, auf deren Seiten die Gene eines einzelnen Elternteils gewählt wird:

![[EA_crossover.png|400]]

Weitere Möglichkeiten:

- Mittelwert (bei reellen Genwerten)
  - verringert den Suchraum -> alle Genwerte konvergieren
- Minimale/Maximale Werte, Summe, Differenzen
- Ist Genum eine Menge von Werten: Vereinigung, Schnitt
- Ist Genum ein String: Konkatenation

#### Mutation

Ziel: die Diversität der Genome innerhalb der Population erhöhen (Exploration).

Möglichkeiten:

- Bei binärem Gen: Bit-flip
	- ein Bit zufällig heraussuchen und flippen (-> Hamming-Distanz garantiert 1)
	- jedes Bit mit Wahrscheinlichkeit $\omega$ flippen (-> Hamming-Distanz gegeben durch W'keitverteilung)
- Bei Vektor von Parametern: einzelnen Wert ändern
- Bei Sequenz: Reihenfolge verändern
- ...

Nach Möglichkeit sollte darauf geachtet werden, dass durch Mutation kein ungültiges Genom entsteht.
Dem sollte je nach Anwendung durch Gestaltung des Genoms / der Vererbung / der Mutation Rechnung getragen werden.

#### Evaluation

I.A. müssen nur die neuen Individuen einer Generation neu evaluiert werden.
Haben viele Individuen eine sehr ähnliche Fitness, kann dies ein Indiz für ein lokales Optimum sein.

#### Externe Selektion

Übliches Vorgehen:

- $\lambda$ Individuen (mit schlechtester Performance) verwerfen
- $\mu = |P|-\lambda$ Individuen als Pool für mögliche Eltern behalten
- Mit diesen Elternteilen $\lambda$ neue Individuen erzeugen (Populationsgröße $|P|$ bleibt konstant)

Für die Auswahl der Aussortierten gibt es dieselben Möglichkeiten wie bei [[#Auswahl der Eltern]].

**Notation** für Selektion und Elternauswahl:

- $(\mu + \lambda)$: Eltern überleben, nächste Generation besteht aus $\mu$ Eltern und $\lambda$ Nachkommen
- $(\mu, \lambda)$: Eltern überleben nicht, nächste Generation besteht nur aus $\lambda$ nachkommen

Beispiele:
- $(1+1)$: ein Elternteil erzeugt ein Nachkommen und überlebt (Vererbung durch Kopieren der Gene)
- $(1 + \lambda)$: ein Elternteil erzeugt $\lambda$ Nachkommen und überlebt
- $(\mu + \lambda)$: $\mu$ Eltern erzeugen $\lambda$ Nachkommen durch Rekombination, überleben
- $(\mu, \lambda)$: $\mu$ Eltern erzeugen $\lambda$ Nachkommen durch Rekombination, überleben nicht

Die externe Selektion kann genauso realisiert werden wie die Elternauswahl (zufällig, Rang-basiert, Performance-basiert, ...)
#### Abbruch des EA

Nach verschiedenen Kriterien: 

- Bestes Individuum ist gut genug
- Teilmenge der Population ist gut genug
- Evaluation der Population stagniert
- nach Zeitdauer / Anzahl Iterationen

### Visualisierung

Mit Performance-Graph (Zeit $t$ vs. beste Performance $f*(t)$).
Zusätzliche Info: durchschnittliche Performance, Standardabweichung innerhalb der Population zum Zeitpunkt $t$

### Super-Individuum

Individuum mit wesentlich höherer Fitness als der Rest der Population.
Schlecht, weil sich dieses Individuum überproportional stark vermehrt und die anderen Individuen verdrängt, wodurch die Diversität sinkt und die Wahrscheinlichkeit verringert wird, Lösungen mit Qualität über das Super-Individuum hinaus zu finden.
-> Super-Individuen sollten vermieden werden.


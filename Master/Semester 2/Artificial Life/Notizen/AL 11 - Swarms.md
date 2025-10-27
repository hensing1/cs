[[ALSS25_11_Swarm_Behavior_Boids_PSO.pdf]]

Statt großem kompliziertem Roboti haben wir viele kleine simple Robotis.

## Didabots

Wir haben einen Roboter mit [[AL 10 - Control Architectures#Typ 3|Braitenberg-3b-Verhalten]], also Hindernisvermeidung.

Man hat mehrere von diesen Robotern in eine Arena mit einigen Boxen gelassen, aber nach und nach haben die Robtoer die Boxen in kleine Cluster zusammengescharrt.
Warum?

- Die Boxen waren klein genug, um zwischen den beiden Sensoren zu landen und für den Roboter "unsichtbar" zu sein
- Die Box wurde durch die Gegend gefahren, bis entweder:
	- die Box *spontan* freigelassen wurde (durch Vibrationen)
	- der Roboter wegen einer anderen Box (oder Hindernis) sich gedreht hat (*induziertes* Freilassen).

Das entstehende (emergente) Verhalten ist also, dass die Roboter "aufräumen".

## Boids

**B**ird Andr**oids**

Ein einzelnes Individuum verfolgt drei Ziele:
1. Separation: weiche anderen Boids aus
2. Alginment: steuere in die durchschnittliche Richtung der nahgelegenen Boids
3. Cohesion: steuere in Richtung der durchschnittlichen Position der nahegelegenen Boids

## Particle Swarm Optimization

PSO ist ein iterativer Optimierungsalgorithmus, der in einem Suchraum $S$ eine Zielfunktion $f: S \to \mathbb{R}$ optimiert, indem eine Population $P$ von Partikeln $S$ durchsucht.

Ein Partikel $j \in P$ hat hierbei:
- eine Position $X_{j} \in S$
- Geschwindigkeit $V_{j}$
- das bisherige Optimum $X_{j,\mathrm{pb}}$
- ggf. das Optimum $X_{j,\mathrm{grb}}$ einer Gruppe, der das Partikel zugeordnet ist

Die Geschwindigkeit wird in jedem Iterationsschritt aktualisiert wie folgt:
$$V_{j} \leftarrow \omega V_{j} + \alpha R (X_{j,\mathrm{pb}} - X_{j})+\beta R (X_{gb} - X_{j}) + \gamma R (X_{j,\mathrm{grb}}-X_{j})$$
mit Parametern:
- Momentum $\omega \in [0,1]$
- $\alpha$ : Gewichtung für Steuerung in Richtung des eigenen Optimum
- $\beta$ : Gewichtung für Steuerung in Richtung des globalen Optimum
- $\gamma$ : Gewichtung für Steuerung in Richtung des Gruppen-Optimum
- $\alpha,\beta,\gamma \in [0,4]$
- $\mathcal{R} \in [0,1]$ Steuerung von Exploration ($\mathcal{R}=0$) und Exploitation ($\mathcal{R}=1$)

Die Position wird danach aktualisiert mit $X_{j} \leftarrow X_{j} + V_{j}$.

Typische Besetzung der Parameter: $\omega =1,\,\alpha=2,\,\beta=2,\,\gamma=1$

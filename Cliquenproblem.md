# Cliquenproblem

## Problembeschreibung
Bei dem Cliquenproblem geht es darum, in einem gegebenen Graphen eine größtmögliche [[Graphen#^961695|Clique]] zu finden. 

**Optimierungsvariante**
*Eingabe:* Graph $G=(V,E)$
*Aufgabe:* Berechne eine Clique mit maximaler Kardinalität.

**Wertvariante**
*Eingabe:* Graph $G=(V,E)$
*Aufgabe:* Berechne das größte $k^{\star}\in \mathbb{N}$, für das es eine $k^{\star}$-Clique in $G$ gibt.

**Entscheidungsvariante**
*Eingabe:* Graph $G=(V,E)$ und ein Wert $k \in \mathbb{N}$
*Aufgabe:* Entscheide, ob es in $G$ eine Clique der Größe mindestens $k$ gibt.

## Komplexität
Das Cliquenproblem ist #NP-schwer. Per [[Beweistechniken#^c978bf|Turing-Reduktion]] kann man zeigen: wenn es eine polynomielle Lösung für eine der drei oben beschriebenen Varianten gibt, dann sind die anderen beiden ebenfalls in polynomieller Zeit lösbar.

### Lösung mit nichtdeterministischer Turingmaschine
Um zu zeigen, dass die Entscheidungsvariante des Cliquenproblems zur [[Komplexitätstheorie#NP|Klasse NP]] gehört, kann eine [[Turingmaschine#Nichtdeterministische Turingmaschine|nichtdeterministische Turingmaschine]] mit dem folgenden Verhalten konstruiert werden:
- Schreibe $n$ Rauten hintereinander auf eine freie Stelle des Bandes. Setze den Kopf auf die erste Raute.
- Solange du eine Raute siehst: ersetze die Raute nichtdeterministisch mit einer 0 oder einer 1. Die auf diese Weise geschriebene Zufallszahl wird als Auswahl $V'$ der Knotenmenge $V$ interpretiert.
- Falls die so ausgewählten Knoten eine $k$-Cique bilden, akzeptiere.

Da jeder Teilschritt nur polynomielle Laufzeit benötigt, ist auch die Gesamtlaufzeit in jedem Fall polynomiell.
Da zusätzlich eine NTM eine Eingabe genau dann akzeptiert, wenn es mindestens einen akzeptierenden Rechenpfad gibt, entscheidet die oben beschriebene NTM das Cliquenproblem. Damit gehört es zu der Klasse NP.

### Reduktion auf Vertex-Cover-Problem
[[Reduktionen#^94ab81|Polynomielle Reduktion]] des Cliquenproblems auf das Vertex-Cover-Problem.[^1] 

Schritt 1: Kehre den Graphen bezüglich auf die Kanten um, d.h. definiere die neue Kantenmenge $$E'=\set{\set{x,y} \mid x,y \in V, x \neq y, \set{x,y} \not\in E}$$als die Menge der Kanten, welche nicht in dem Graphen enthalten sind, in dem wir eine $k$-Clique finden wollen.

Schritt 2: Prüfe, ob der Graph $(V,E')$ einen Vertex Cover der Größe $k'=|V|-k$ enthält. Ist nämlich $C \subseteq V$ eine Clique in $(V,E)$, dann ist auch $G=V \setminus C$ ein Vertex Cover in $(V, E')$ (und umgekehrt).

![[Clique_Vertex_Cover.png|500]]

[^1]: Vertex-Cover-Problem: Finde eine (möglichst kleine) Teilmenge von Knoten in einem Graphen, sodass alle Kanten in diesem Graphen zu diesem Knoten inzident sind.
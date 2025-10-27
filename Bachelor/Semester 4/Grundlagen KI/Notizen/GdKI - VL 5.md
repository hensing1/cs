Datum: 22.04.
[[AI05_SS24_Games_240422_240419.pdf|Folien]]

# Spiele

Spiele = "Multiagenten-Umgebungen" mit wohldefinierten Regeln, i.A. deterministische und diskrete Aktionen, etc.

*Zweipersonen-Brettspiele*
Wir haben eine Nutzenfunktion, die den Spielausgang bewertet: z.B. +1 für Sieg, -1 für Niederlage, 0 für Unentschieden.
Ein Spieler (MAX) möchte die Nutzenfunktion maximieren, der andere (MIN) möchte sie minimieren.

## Minimax-Algorithmus

1.  Erzeuge *vollständigen* Spielbaum mittels Tiefensuche
2. Wende die Nutzenfunktion auf jeden Terminalzustand an
3. Propagiere die Nutzenfunktion zurück durch den Baum

Minimax geht von perfektem Spiel vom Gegner aus.

> **Minimax:** $\text{state} \mapsto \text{action}$
> `v := MaxValue(state)`
> `return action in successors(state) with value v`
> 
> **MaxValue:** $\text{state} \mapsto \text{utility value}$
> `if terminal(state): return utility(value)`
> `v := -Infinity`
> `for action in successors(state):`
> > `v := max(v, MinValue(next_state(state, action)))`
> `return v`
> 
> **MinValue:** $\text{state} \mapsto \text{utility value}$
> `if terminal(state): return utility(value)`
> `v := Infinity`
> `for action in successors(state):`
> > `v := min(v, MaxValue(next_state(state, action)))`
> `return v`

$\to$ Minimax ist eine [[Graphen#Tiefensuche|Tiefensuche]].

Problem: vollständiger Spielbaum ist meistens zu groß.
Abhilfe: Betrachte `state`s ab einer bestimmten Suchtiefe als Terminalzustände. Dann benötigt man eine Evaluierungsfunktion, die einen Nichtterminalzustand mit einer Heuristik bewertet.

### Beendung der Suche

- Wenn man iterative Tiefensuche verwendet, kann die Suche durch ein Zeitlimit abgebrochen werden
- Horizonteffekt: ein letztlich unvermeidlicher, schädigender Gegenzug wird aus dem Suchbaum herausgeschoben, indem herauszögernde Züge gewählt werden. Die Heuristik kann die entstehenden Positionen nicht korrekt bewerten.
	- Lösung durch größere Suchtiefe oder bevorzugter Betrachtung "forcierenderer" Züge

### Alpha-Beta-Kürzung

Durch Alpha-Beta-Kürzung werden genau dieselben Ergebnisse erzielt wie durch Minimax, aber es werden Teilbäume, die es sich nicht zu betrachten lohnt, abgeschnitten.

> **AlphaBetaSearch:** $\text{state} \mapsto \text{action}$
> `v := MaxValue(state, -Infinity, +Infinity)`
> `return action in successors(state) with value v`
> 
> **MaxValue:** $\text{state},\, \alpha,\,\beta \mapsto \text{utility value}$
> `if terminal(state): return utility(value)`
> `v := -Infinity`
> `for action in successors(state):`
> > `v := max(v, MinValue(next_state(state, action), alpha, beta))`
> > `if v >= beta: return v`  *// pruning*
> > `alpha := max(alpha, v)`
> `return v`
> 
> **MinValue:** $\text{state},\, \alpha,\,\beta \mapsto \text{utility value}$
> `if terminal(state): return utility(value)`
> `v := +Infinity`
> `for action in successors(state):`
> > `v := min(v, MaxValue(next_state(state, action), alpha, beta))`
> > `if v <= alpha: return v`  *// pruning*
> > `beta := min(beta, v)`
> `return v`

- $\alpha$ ist der beste Wert, den Min in einem benachbarten Teilbaum erzielen kann. Findet Min also im seinem aktuellen Teilbaum einen kleineren Wert als $\alpha$, weiß Min, dass Max den anderen Teilbaum wählen wird, und muss nicht mehr weitersuchen.
- $\alpha$ und $\beta$ werden nur nach unten, aber nicht nach oben weitergegeben.
- Funktioniert am besten, wenn die besten Züge zuerst ausgewertet werden.
	- -> $\mathcal{O}(b^{m/2})$ statt $\mathcal{O}(b^{m})$, d.h. man kann doppelt so weit in derselben Zeit suchen
	- Bei durchschnittlich verteilten Zügen $\mathcal{O}(b^{3m/4})$

### Expectimax

Wir haben zwischendurch Züge, die durch keinen Spieler, sondern durch Zufall entschieden werden.

![[Expectimax.png]]


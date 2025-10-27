Datum: 18.04.
[[AI04_SS24_Informed_Search_240418_240417.pdf|Folien]]

# Informierte Suche

**Best-First Search:** erweitert [[GdKI - VL 3#Allgemeine Suchprozedur|General Search]] mit einer *Evaluierungsfunktion* $f(n)$. Die Knoten werden dann gemäß ihrer Evauierung in die Queue einsortiert, sodass als nächstes der Knoten mit der besten Evaluierung betrachtet wird.

Einigung für diese VL: neue Knoten werden *vor* den Knoten mit derselben Evaluierung in der Queue eingeordnet.

*Greedy Search mit Heuristik*

- Pfadkosten von Start zu aktuellem Knoten sind bekannt
- Pfadkosten vom aktuellen Knoten zum Ziel werden *geschätzt* durch Schätzfunktion $h(n)$

Die Bestensuche mit $f(n) = h(n)$ heißt gierige Suche.

Beispiel für Heuristik: Luftliniendistanz bei Navigation

## A*

$g(n)$: bisherige Pfadkosten
$h(n)$: *zulässige* Heuristikfunktion
$f(n) = g(n) + h(n)$

A* ist eine Bestensuche mit $f(n) = g(n) + h(n)$. Die *erste* von A* gefundene Lösung ist eine mit minimalen Pfadkosten.

> [!abstract] Definition *Zulässigkeit*
> Eine Heuristikfunktion ist zulässig, wenn die verbeibende Distanz zum Ziel *nicht überschätzt* wird.

- A* ist *vollständig* (d.h. wenn eine Lösung existiert, wird diese auch gefunden), sofern jeder Knoten nur endlich viele Nachfolgerknoten hat und alle Kantengewichte (Operatorkosten) mindestens so groß wie eine positive Konstante $d$ sind.
- A* benötigt *polynomiell* viel Zeit, falls der Fehler der Heuristik maximal logarithmisch mit den tatsächlichen Pfadkosten $h ^{\ast}(n)$ wächst, d.h. $|h ^{\ast}(n)-h(n)|\in \mathcal{O}(\log h ^{\ast}(n))$.

> [!abstract] Definition *Monotonie*
> Sei $n'$ der Nachfolgeknoten von $n$. Wenn für alle $n$ und $n'$ und $f(n) = g(n) + h(n)$ gilt, dass $f(n') \geq f(n)$, dann heißt $h(n)$ *monoton*.

**Erkennung von Wiederholungen**
Graph-Search ist eine Erweiterung von General-Search, die eine Liste `closed` hinzufügt.
In `closed` kommen alle Knoten, die man schon expandiert hat.

A* als Graph-Search ist dann optimal, wenn $h(n)$ *monoton* ist.

Gewährleistung von Monotonie in A*: *Path-Max-Gleichung* $f(n') = \max(f(n), g(n') + h(n'))$

Vergleich von Heuristiken: je höher geschätzt wird, ohne $h ^{\ast}$ zu überschreiten, desto besser.

# Lokale Suche

Situation: die Offline-Kosten sind kein hartes Kriterium, wir sind nur am Zielzustand selbst interessiert.

Idee: beginne mit zufällig gewählter Konfiguration und verbessere sie schrittweise.

> **Hill-Climb:** $\text{problem} \mapsto \text{solution state}$
> `current := make_node(initial_state(problem))`
> 
> `while True:`
> > `next := max(successors(current))`
> > `if value(next) < value(current): return state(current)`
> > `current := next`

Probleme:
- kann nur das lokale Optimum zurück geben
- kann auf Plateaus bzw. Graten und Sattelpunkten nur zufällig herumwandern

Lösungen:
- mit anderer zufälliger Konfiguration neu starten
- Rauschen hinzufügen (simulated annealing)
- Tabu-states: die letzten $n$ angewandten Operatoren nicht erneut anwenden

Welche dieser Lösungen die richtige ist, ist problemspezifisch und kann meist nur empirisch bestimmt werden.

Simulated annealing: füge mit der Zeit abnehmendes Rauschen in Hill-Climb ein.

> **Simulated Annealing:** $\text{problem, schedule} \mapsto \text{solution state}$
> `current := make_node(initial_state(problem))`
> 
> `for t from 1 to Infinity:`
> > `T := schedule[t]`
> > `if T=0: return current`
> > `next := pick_random(successors(current))`
> > `delta_e := value(next) - value(current)`
> > `if (delta_e > 0) or (rand(0,1) <` $e^{\Delta E/T}$`): current := next


Datum: 16.04.
[[0.2-GraphDefinitionen-v2.pdf|Folien]]

# Definitionen und Graphrepräsentationen

## Definitionen

- [[Graphen#Begriffsdefinitionen#Gerichteter Graph|Gerichtete]] und [[Graphen#Begriffsdefinitionen#Ungerichteter Graph|ungerichtete Graphen]]
- [[Graphen#^9076aa|Pfade und Wege]] und [[Graphen#^df5d2f|Kreise]]
- [[Graphen#^f27dcc|Induzierte Teilgraphen]]
- [[Graphen#^9c3af1|Zusammenhangskomponenten]]
- [[Graphen#^c50cc7|Bipartite Graphen]]
- [[Graphen#^a00f13|Dünne und dichte Graphen]]

## Repräsentationen

Betrachtete Operationen:
- Iteration über alle Nachbarn eines Knoten $v$
- Abfrage, ob eine Kante $(v,w)$ vorhanden ist
- Addieren einer Kante
- Entfernen einer Kante

### Listenbasiert

- Unsortierte, einfach verkettete Liste aller Kanten
	- Operationen: alles $\mathcal{O}(m)$, außer addieren einer Kante ($\mathcal{O}(1)$)
	- Speicherplatz: $\mathcal{O}(m)$
- Für *jeden Knoten* unsortierte, einfach verkettete Liste aller Nachbarknoten
	- Operationen: alles $\mathcal{O}(\delta^{+}(v))$, außer addieren einer Kante ($\mathcal{O}(1)$)
	- Speicherplatz: $\mathcal{O}(m+n)$

### Arraybasiert

- Für jeden Knoten unsortiertes dynamisches Array
	- Operationen: alles $\mathcal{O}(\delta^{+}(v))$
	- Speicherplatz: $\mathcal{O}(m+n)$, oder $\mathcal{O}(n^{2})$ wenn man einen dynamischen Graphen hat und den Speicherplatz im Vorfeld allokiert

![[Graphen#Adjazenzarray]]

![[Graphen#Adjazenzmatrix]]


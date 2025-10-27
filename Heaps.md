# Heaps
## Definition

> [!abstract] Max-Heap
> Ein **Heap** (hier: *Max-Heap*) ist ein *binärer Baum*, für den folgende Bedingungen gelten:
> - Für jeden Knoten $v$ mit Inhalt $x$ gilt, dass die Schlüssel aller Daten *im linken oder rechten Teilbaum* von $v$ *höchstens so groß* sind wie der Schlüssel von $x$.
> - Der Binärbaum ist bis auf evtl. die letzte Ebene vollständig.
> - Die letzte Ebene ist von links nach rechts gefüllt.

## Speichern als Feld
Ein Heap kann sehr einfach in einem Feld gespeichert werden. Hierbei wird jede Ebene nacheinander von links nach rechts im Feld abgelegt. 
Die Kinder eines Knotens an der Stelle $i$ sind dadurch an den Stellen $2i$ und $2i+1$.[^1]
Der Elternknoten an der Stelle $i > 1$ ist an der Stelle $\lfloor i / 2 \rfloor$.

Ein Feld ist damit genau dann ein Heap, wenn für alle $i$ gilt:
`a[i].key >= a[2i].key` und `a[i].key >= a[2i+1].key`.

[^1]: Angenommen, der Index beginnt bei 1.

## Erzeugen eines Max-Heaps

Hierfür gibt es zunächst die Methode `Max-Heapify`. Hierbei gehen wir davon aus, dass die Teilbäume unterhalb von `i` bereits die Heap-Eigenschaft erfüllen, der Knoten `i` selbst aber möglicherweise nicht.

```
def Max-Heapify(a,i):
	largest = Index des Maximum aus a[i].key, a[2i].key und a[2i+1].key
	if (i != largest):
		vertausche a[i] und a[largest]
		Max-Heapify(largest)
```

Nun gilt: wenn vorher die Heap-Eigenschaft für alle Indizes `j > i` galten, gilt sie nach `Max-Heapify(i)` für alle `j >= i`.

Damit kann man mit dem einfachen folgenden Algorithmus aus einer Liste einen Heap machen:

```
def Build-Heap(a):
	for (i = a.length/2; i >= 1; i--):
		Max-Heapify(a,i)
```

Man muss erst bei $\lfloor \text{a.length} / 2\rfloor$ anfangen, da für Blätter die Heap-Eigenschaft trivialerweise immer erfüllt ist.

## Heap Sort
Mit den Funktionen `Max-Heapify` und `Build-Heap` lässt sich nun ein Sortieralgorithmus definieren:

```
def Heapsort(a)
	Build-Heap(a)
	heapsize = n
	while heapsize > 0:
		vertausche a[1] und a[heapsize]
		heapsize--
		Max-Heapify(1)
```

### Laufzeit
Die Laufzeit von `Heapsort` liegt in $\mathcal{O}(n\log n)$. 
Das liegt daran, dass die Laufzeit von `Max-Heapify` in $\mathcal{O}(\log n)$ liegt (der Baum hat die Höhe $\log_{2}n$), und es wird $2n$-mal aufgerufen: $n$-mal in `Build-Heap`[^2] und $n$ mal durch die while-Schleife.

[^2]: Genaugenommen kann man `Build-Heap` sogar mit $\mathcal{O}(n)$ abschätzen

## Prioritätswarteschlange

> [!abstract] Definition
> Eine **Prioritätswarteschlange** speichert *Element/Schlüssel-Paare* und unterstützt die folgenden Operationen:
> - `Insert(x,k)`: fügt ein neues Element $x$ mit Schlüssel $k$ ein
> - `Find-Max()`: gibt ein Element mit dem größten Schlüssel zurück.
> - `Extract-Max()`: entfernt ein Element mit dem größten Schlüssel und gibt es zurück.
> - `Increase-Key(i,k)`: erhöht den Schlüssel des an Stelle $i$ gespeicherten Objekts auf $k$.

`Increase-Key` lässt das Element x solange im Baum aufsteigen, bis ein Vaterknoten mit einem höheren Schlüsselwert als `k` gefunden wird. 
`Insert` hängt zunächst das neue Element hinten dran und benutzt dann `Increase-Key`, um es einzusortieren.

`Extract-Max()` gibt die Wurzel zurück, dann wird das letzte Element in die Wurzel gesetzt. Dann wird `Max-Heapify` aufgerufen, um die Heap-Eigenschaft wieder herzustellen.

`Find-Max` benötigt konstante Laufzeit, da das größte Element immer ganz vorne ist. Alle anderen Operationen benötigen $\mathcal{O}(\log n)$.
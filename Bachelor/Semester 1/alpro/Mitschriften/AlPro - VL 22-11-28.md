Datum: 28.11.
Folien: [[04_Algorithmen_Teil_2_05.pdf|Algorithmen Teil 2 - 05]]

# Priority-Queue
![[Heaps#Prioritätswarteschlange]]

# Baum
Definition für Alpro:
> Ein [[Graphen#Ungerichteter Graph|ungerichteter Graph]] ist ein **Baum**, wenn je zwei Knoten durch *genau einen Weg* miteinander verbunden werden können.

> [!abstract] Äquivalente Baumdefinitionen
> Sei $G = (V, E)$ ein ungerichteter Graph mit $n$ Knoten. Dann sind folgende Aussagen äquivalent:  
> - $G$ ist ein Baum.  
> - $G$ ist zusammenhängend und kreisfrei.  
> - $G$ ist zusammenhängend und das Entfernen einer beliebigen Kante zer-  
stört diese Eigenschaft.  
> - $G$ ist kreisfrei und das Hinzufügen einer beliebigen Kante zerstört diese  
Eigenschaft.  
> - $G$ ist zusammenhängend und hat genau $n − 1$ Kanten.  
> - $G$ ist kreisfrei und hat genau $n − 1$ Kanten.

Wenn man explizit einen Wurzelknoten wählt, hat man einen **Baum mit ausgezeichneter Wurzel**.

Wir definieren nun Tiefe, Eltern- und Kindknoten, Blätter, pi pa po.

## Durchlaufreihenfolgen
### Pre-Order
- Erst der Wurzelknoten
- dann der linke Teilbaum
- dann der rechte Teilbaum

### In-Order
- Erst der linke Teilbaum
- dann die Wurzel
- dann der rechte Teilbaum

### Post-Order
- Erst der linke Teilbaum
- dan der rechte Teilbaum
- dann die Wurzel

### Level-Order
Erst die Wurzel, dann das erste Level v.l.n.r., dann das zweite, usw.

## Heap
![[Heaps#Definition]]
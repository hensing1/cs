# AVL-Bäume
Problem: man kann die Höhe von Suchbäumen nicht vernünftig beschränken (siehe [[Algo I - VL 6#Suchbaum als dynamische Datenstruktur|letzte Vorlesung]]). Es wäre natürlich schön, nach jedem Einfügen und Löschen von Elementen den Baum bis auf die letzte Ebene vollständig zu halten, das ist aber nicht effizient möglich. Ein AVL-Baum ist ein Kompromiss.

## Definition

> Ein AVL-Baum[^1] ist ein binärer Suchbaum, bei welchem sich an *jedem Knoten* die Höhe des linken Teilbaums um maximal 1 von der Höhe der rechten Teilbaums unterscheidet.
> Man definiert für einen Knoten $v$ mit Teilbaumhöhen $h(T_L)$ und $h(T_R)$ die Funktion $bal(v)=h(T_L)-h(T_R)$ als *Balance* des Knotens. In einem AVL-Baum gilt $bal(v)\in\set{-1,0,1}$ für jeden Knoten $v$.

[^1]: Benannt nach den Mathematikern **A**delson-**V**elski und **L**andis, zwei sowjetischen Mathematikern, die die Datenstruktur 1962 erstmals vorstellten.

## Worst-Case-Wachstum
- Ein AVL-Baum der Höhe $h$ hat eine Mindest-Knotenanzahl ($A(h)$) von $A(h)=1+A(h-1)+A(h-2)=f_{h+3}-1$ Knoten, mit $A(0)=1$, $A(1)=2$,$h \geq 2$ und $f_{n}=\text{n-te Fibonacci-Zahl}$.
- Da die Fibonacci-Zahlen exponentiell wachsen, hat ein AVL-Baum der Höhe $h$ auch exponentiell viele Knoten (anders als ein normaler Suchbaum, der im schlimmsten Fall $h+1$ Knoten hat).
- Das heißt, die Höhe eines AVL-Baums wächst auch im schlimmsten Fall nur logarithmisch mit der Knotenanzahl - konkret ist $h < 1,4405\cdot \log_{2}(n+1)$.
	- Diese Formel ergibt sich irgendwie aus der geschlossenen Form der Fibonacci-Folge. Da hat man dann $n+1=(\text{irgendein Kram})^h$, und wenn man das nach $h$ umstellt, ergibt sich obiger Term.

## Operationen
### Insert
#### Technisches Vorgehen
Prinzipiell geht man folgendermaßen vor:
- Man setzt den neuen Knoten an die richtige Stelle.
- Man muss nun die Balancen entlang des Pfades von der Wurzel bis zum neuen Blatt korrigieren. Anderswo können sich die Balancen nicht verändert haben und die AVL-Eigenschaft kann dort auch nicht verletzt sein.
- Man geht diesen Pfad von unten nach oben ab. Gesetzt den Fall, man erreicht hierbei einen Knoten $v$ von seinem rechten Kind, setzt man $bal(v)$ auf $bal(v)-1$ und muss folgende Fallunterscheidungen machen:
	1. $bal(v)=1$: wir haben gerade den rechten Teilbaum vergrößert, d.h. wir setzen $bal(v)=0$. Die beiden Teilbäume von $v$ sind nun gleich hoch, und die Gesamthöhe des Teilbaums mit der Wurzel $v$ kann sich nicht verändert haben. Das wiederum heißt, weiter oben ändern sich keine Balance verändert haben, und wir hören mit der Rebalancierung auf.
	2. $bal(v)=0$: wir setzen $bal(v)=-1$ und führen den Rebalancierungsprozess am nächst-höheren Knoten fort, sofern es einen gibt.
	3. $bal(v)=-1$: man muss den Baum jetzt umbauen, da sonst mit $bal(v)=-2$ die AVL-Eigenschaft nicht mehr erfüllt wäre. Wie man den Baum umbau(m)t, hängt von dem spezifischen Fall ab - entweder ist es eine Linksrotation, oder eine Rechtsrotation gefolgt von einer Linksrotation. Bei einer Rotation tauscht man quasi die Wurzel des Baums um, sodass sich die höhen der jeweiligen Teilbäume angleichen. Das ganze mit Worten zu beschreiben ist etwas umständlich, daher sind untenstehend die Diagramme der jeweiligen Fälle, die eintreten können. Der Teilbaum, bei dem der neue Knoten hinzugekommen ist, ist jeweils mit einem Punkt markiert. Für alle Umformungen gilt: danach ist die Umformung des kompletten Baums abgeschlossen.
		1. Fall: ![[AVL-Linksrotation.png]]
		2. Fall: ![[AVL-Rechts-Links-Rotation.png]]
		3. Fall: ![[AVL-Rechts-Links-Rotation-2.png]]
		4. Fall: im obigen Diagramm ist $w$ der neue Knoten (d.h. Teilbäume A,B,C,D sind leer). Auch in diesem Fall genügt eine RL-Rotation.
- Kommt man vom linken Kind des Teilbaums $v$, funktioniert das ganze genauso, nur eben umgekehrt. Damit sind alle Fälle des Einfügens abgedeckt.

#### Laufzeit
Die Rotationen benötigen jeweils nur konstante Laufzeit und müssen maximal einmal angewendet werden. Damit hängt die Dauer vom Rebalancieren lediglich linear von der Höhe des Baumes ab (man muss ja nur einen Pfad ablaufen). Die Höhe wächst wiederum logarithmisch mit $n$. Also ergibt sich für die Laufzeit: $$\mathcal{O}(\log n).$$


### Delete
Das Löschen aus einem AVL-Baum verläuft im ersten Schritt genau wie bei einem gewöhnlichen binären Suchbaum.
Danach können aber, wie beim Einfügen, entlang des Pfades von der Wurzel bis zur Stelle des ehemaligen Knotens wieder die Balancen verändert worden sein. 
Das heißt, man geht wieder diesen Pfad von unten nach oben entlang und muss evtl. bestimmte Rotationen durchführen. Der Unterschied zum Einfügen ist, dass man nach einer Rotation noch nicht unbedingt fertig ist, da die Höhe des Teilbaums nach dem Rotieren geschrumpft sein kann. Man muss dann also am nächst-höheren Knoten weitermachen.
Trotzdem benötigt die Abarbeitung von jedem Knoten nur konstante Zeit, da eine Rotation nur konstante Zeit benötigt. Das wiederum bedeutet, dass sich die Gesamtlaufzeit von `Delete(k)` wieder mit $\mathcal{O}(\log n)$ abschätzen lässt.

### Search
Da die Höhe eines AVL-Baums in jedem Fall logarithmisch zu $n$ ist, liegt auch die Suchlaufzeit in $\mathcal{O}(\log n)$.
# Aufgabe 2
## a)
Zu zeigen ist, dass die Laufzeit von `Build-Heap` für eine Liste mit $n$ Einträgen in $\mathcal{O}(n)$ liegt.

Hierzu soll zunächst gezeigt werden, dass die Laufzeit von `Max-Heapify(i)` in $\mathcal{O}(l)$ liegt, wobei $l$ die Anzahl der Ebenen im Heap beschreibt, welche unterhalb des Knotens $i$ liegen. 

Zu beobachten ist, dass jeder Aufruf von `Max-Heapify(i)` höchstens einen weiteren rekursiven Aufruf tätigt, welcher mit genau einem Kindknoten von $i$ parametrisiert ist. Dieser Kindknoten liegt im Binärbaum per Definition eine Ebene unter $i$. Da der ursprüngliche Aufruf von `Max-Heapify` auf Ebene $e_{i}$ passiert, können alle Ebenen oberhalb von $e_{i}$ ignoriert werden - daraus folgt, dass höchstens $l = h - e_{i}$ rekursive Aufrufe getätigt werden. Da die restlichen Operationen von `Max-Heapify` konstante Laufzeit benötigen, liegt die Gesamtlaufzeit in $\mathcal{O}(l)$.

Sei o.B.d.A. die Höhe des Baums $h=2^{n}$.

Wie in der letzten Übung gezeigt wurde, liegen in einem vollständigen Binärbaum $2^{j}$ Knoten in jeder Ebene $j$. 
Von unten nach oben betrachtet, halbiert sich damit die Anzahl der Knoten auf jeder Ebene, und pro Knoten (welcher kein Blatt ist, also ab der zweiten Ebene von unten) wird einmal `Max-Heapify` aufgerufen, welcher im schlimmsten Fall pro Ebene unterhalb des Knotens einen rekursiven Aufruf tätigt.

Damit ergibt sich eine Laufzeit $L$ von
$$
\begin{aligned}
L\leq&\sum\limits_{i=1}^{h-1} 2^{h}\cdot i \cdot 0,5^{i}\\
=&\space 2^{h}\sum\limits_{i=1}^{h-1}i \cdot 0,5^{i}\\
<&\space 2^{h} \cdot 0,5/(1-0,5)^2\\
=&\space 2^{h} \cdot2\\
=&\space 2^{\log_{2}n} \cdot2\\
=&\space 2n \in \mathcal{O}(n)
\end{aligned}
$$

<div style="page-break-after: always;"></div>

## b)
*Lemma:*
> Um ein Element in eine Priority-Queue der Länge $n$ einzufügen, benötigt man im schlimmsten Fall $\lceil \log_{2}n \rceil$ Schritte.

*Beweis:*
Eine Priority-Queue ist ein Binärbaum, und ein Binärbaum hat Höhe $h=\lceil \log_{2}n \rceil$. Die Operation `Insert` fügt das neue Element an das Ende der Queue, d.h. in die unterste Ebene des Baums, und ruft dann `Increase-Key` auf. Bei `Increase-Key` wird der Knoten in jedem Schritt eine Ebene nach oben geschoben, welches höchstens $h$-mal passieren kann. Dadurch werden im Worst-Case mindestens $\lceil \log_{2}n \rceil$ benötigt.

*Zu zeigen:*
> Einen Heap mit der `Insert`-Operation einer Priority-Queue aufzubauen, benötig im schlimmsten Fall eine Laufzeit von $\mathcal{\Omega}(n \log n)$.

Aus o.g. Lemma ergibt sich für eine Folge von $n$ `Insert`-Operationen auf einen leeren Heap im Worst Case folgende Laufzeit $L$:
$$
\begin{align}
L \geq & \sum\limits_{i=1}^{n} \lceil \log_{2}i \rceil\\
> & \space \log_{2}\left(\prod_{i=1}^{n}i\right)\\
= & \space \log_{2}(n!)= \Theta(n \log n)\\
&\Rightarrow L \in \Omega(n \log n)
\end{align}
$$
$\square$

Nächstes mal:
Konkrete Sequenz angeben, für das tatsächlich Laufzeit $n \log n$ erreicht wird.

Musterlösung:
Betrachte Sequenz $1 \ldots n$
Sei $i$ die größte Zahl mit $2^{i} -1 \leq n$
Betrachte Einfügen von $2^{i-1},\ldots,2^{i}-1$
Für jedes Element gilt: Es ist Maximum zum Zeitpunkt des Einfügens. Für jeden Knoten haben wir Kosten von $\Omega(i)$
Für diese Knoten: Kosten $\Omega(2^{i-1}i)$
Weiterhin gilt: $n \leq 2^{i+1}$ (per Definition)
$\iff \frac{n}{2}\leq 2^{i} \iff \log(\frac{n}{2})\leq i$
$\iff \frac{n}{4} \leq 2^{i-1}$

Einsetzen: Laufzeit $\Omega(\frac{n}{4} \log(\frac{n}{2}))=\Omega(n \log n)$
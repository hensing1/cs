# Aufgabe 7.4
*Direkter Beweis*

Sei $U$ ein beliebiges Universum der Größe $|U|\geq(n-1)m+1$.
Ziel ist es, eine Menge $S \subseteq U$ zu generieren, sodass gilt: $\forall k,k' \in S : h(k)=h(k')$.

Hierzu definieren wir zunächst $m$ Hilfsmengen $S_1,S_2,\ldots,S_m$. Diese sollen im Folgenden schrittweise erweitert werden.

Zunächst befüllen wir jede Menge $S_{i}$ mit genau einem Element aus $U$, sodass für alle $i,j \in \set{1,2,...,m}$ mit $i \not = j$ gilt: $S_{i}\cap S_{j} = \emptyset$. Damit haben wir genau $m$ Elemente aus $U$ benutzt, womit mindestens $(n-2)m+1$ Elemente aus $U$ noch nicht auf die Hilfsmengen verteilt sind.

Im schlechtesten Fall bildet $h$ nun jedes Element aus $\bigcup\limits_{i=1}^{k}S_{i}$ auf ein anderes $h(k)$ ab. Wäre dies nicht der Fall, gelte also z.B. für $k_{i}\in S_{i}$ und $k_{j}\in S_{j}$, dass $h(k_i)=h(k_j)$, dann könnten wir eine neue Menge $S'=S_{i}\cup S_{j}$ bilden, welche zwei Elemente enthielte die bereits auf denselben Wert abgebildet werden. Damit wären wir unserem Ziel bereits einen Schritt näher.

Zu beobachten ist nun, dass bereits auf alle Werte aus $\set{0,\ldots,m-1}$ abgebildet wurde. Dies folgt direkt daraus, dass wir $m$ verschiedene Elemente verwendet haben und jedes einzelne Element auf einen anderen Wert abgebildet wurde.

Nun wählen wir erneut $m$ verschiedene Elementen $k_1,k_2,\ldots,k_m$ aus $U \setminus \bigcup\limits_{i=1}^{k}S_{i}$. Wieder gehen wir davon aus, dass jedes $k_{i}$ auf einen anderen Wert abgebildet wird. Erneut ergibt sich die Situation, dass $\bigcup\limits_{i=1}^{m}\set{h(k_{i})}=\set{0,\ldots,m-1}$. 

Nun erweitern wir unsere Hilfsmengen derart, dass wir jedes neue Element $k_{i}$ genau der Hilfsmenge $S_{j}$ hinzufügen, für deren einziges Element $k^{S_{j}}$ gilt: $h(k_{i})=h(k^{S_{j}})$. Dies können wir für jedes Element $k_{i}$ tun.
Es folgt, dass wir nun $m$ Mengen mit jeweils zwei Elementen haben, die beide durch $h$ auf denselben Wert abgebildet werden.

Diese Schritte (Auswählen von $m$ neuen Elementen, Verteilen auf die Hilfsmengen) wiederholen wir nun insgesamt $(n-1)$-mal. Damit haben wir $(n-1)\cdot m$ verschiedene Elemente aus $U$ verwendet und diese, da wir in jedem Schritt von dem Worst Case ausgehen, auf $m$ Hilfsmengen verteilt, sodass jede Hilfsmenge genau $n-1$ Elemente enthält, welche alle auf denselben Wert abgebildet werden. 
Da $U$ mindestens $(n-1)m+1$ Elemente enthält, haben wir mindestens ein Element $k^*$ noch nicht verwendet. Egal, welchen Wert $h(k^{*})$ nun annimmt: es ist garantiert, dass wir bereits eine Hilfsmenge $S_{i}^{*}$ haben, für die alle $n-1$ Elemente $k_{S_{i}^{*}}$ auf $h(k^{*})$ abbilden. Erweitern wir nun diese Menge um $k^{*}$, dann haben wir mit $S_{i}^{*}$ eine Menge mit $n$ Elementen, welche alle auf denselben Eintrag der Hashtabelle abgebildet werden, was zu zeigen war.
$\square$
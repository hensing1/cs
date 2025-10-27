# Quicksort
Sortieralgorithmus nach dem Prinzip #divide-and-conquer.
## Funktionsweise
- Man partitioniert zuerst seine Liste im Verhältnis zu einem Pivot-Element an der Stelle $q$. Danach gilt:
	- Alle Werte, die kleiner sind als das Pivot-Element, sind nun an den Stellen $0$ bis $q-1$.
	- Alle Werte, die größer sind als das Pivot-Element, sind nun an den Stellen $q+1$ bis $n-1$.
- Dann wird zweimal ein rekursiver Aufruf gemacht: einmal für den Bereich von $0$ bis $q-1$, und einmal für den Bereich von $q+1$ bis $n-1$. 
## Partitionierung
### Festes Pivot-Element
Man könnte natürlich zum partitionieren der Liste sich zwei halb so große Listen anlegen, und dort die Elemente abhängig von einem Pivot-Element reinsortieren. Das ist aber speicherplatztechnisch ungünstig, da man sich eben immer zwei Listen anlegen muss, deren Länge abhängig von der gesamtlänge der Liste ist.

Schlauer ist folgender Ansatz:
- Das Pivot-Element ist das letzte Element der Liste.
- Man merkt sich, wie groß die Bereiche für alle kleineren und alle größeren Elemente (im Verhältnis zum Pivot-Element) sind. Am Anfang ist die Größe beider Bereiche = 0.
- Man geht genau einmal die Liste durch:
	- Ist das aktuelle Element größer als das Pivot-Element, bleibt es an Ort und Stelle. Der Bereich der größeren Elemente wächst um 1.
	- Ist das aktuelle Element kleiner(-gleich) dem Pivot-Element, wird es mit dem vordersten Element aus dem Bereich der größeren Elemente getauscht. Der Bereich der kleineren Elemente wächst um 1, und der Bereich der größeren Elemente rutscht um 1 nach rechts.
- Am Ende tauscht man das Pivot-Element mit dem ersten Element aus dem Bereich mit den größeren Elementen. Das Pivot-Element liegt damit zwischen den beiden Bereichen.

### Zufälliges Pivot-Element (RandomQuicksort)
Um die Laufzeit (s.u.) einheitlicher zu gestalten, kann ein zufälliges Pivot-Element gewählt werden. Das lässt list simplerweise dadurch erreichen, dass ein zufälliges Element ans Ende der Liste getauscht wird und dann so fortgefahren wird wie oben beschrieben.

## Laufzeit
### Worst Case
Der Worst Case tritt ein, wenn das Pivot-Element stets das größte Element der Liste (bzw. des aktuellen Listbereichs) ist. Dann ist nämlich $q$ gleich dem höchsten Index des Listbereichs.

Der [[Rekursionsgleichungen#Rekursionsbäume|Rekursionsbaum]] sieht in diesem Fall also folgendermaßen aus:
![[quicksort_worst_case.png|250]]

Als [[Rekursionsgleichungen|Rekursionsgleichung]] ergibt sich:
$$
T(n)=\begin{cases*}
\Theta (1) & falls n=0,\\
\Theta (n-1)+cn & falls n>0.
\end{cases*}
$$
Dadurch ergibt sich: $T(n)=\Theta(n^2)$.

### Best Case
Wenn das Pivot-Element der Median ist, wird der Best Case erreicht, da sich die Größe des Teilproblems bei jedem Rekursionsaufruf halbiert. 
Mit $T(n)=2\cdot T(n/2)+cn$ ergibt sich laut [[Rekursionsgleichungen#Master-Theorem|Master-Theorem]]: $T(n)=\Theta(n\log n)$.

### RandomQuicksort
Dadurch, dass immer ein zufälliges Element als Pivot-Element gewählt wird, liegt die *erwartete Laufzeit* von RandomQuicksort für einen *beliebigen Input* in $\Theta(n\log n)$.

#### Warum?
Für die Laufzeitanalyse von RandomQuicksort reicht es, sich anzuschauen, wie oft erwartungsgemäß ein *wesentlicher Vergleich* stattfindet. Ein wesentlicher Vergleich ist der Vergleich zwischen zwei Elementen. 

Ein Vergleich zwischen zwei beliebigen Elementen $i$ und $j$ kann im gesamten Verlauf von Quicksort nicht mehr als einmal auftreten. Das liegt daran, dass zwei Elemente nur dann miteinander verglichen werden, wenn eins davon das Pivot-Element ist.
Da nun aber das Pivot-Element nach dem Durchlauf der Partitionierung schon an der richtigen Stelle steht und nicht Teil der weiteren Teilprobleme ist, kann es danach auch mit nichts mehr verglichen werden.

Das heißt, der Erwartungswert der Anzahl der wesentlichen Vergleiche ist:
$$
E[X]=E\left[\sum\limits_{i=1}^{n-1}\sum\limits_{j=i+1}^{n}X_{ij}\right]
$$
Mit $X_{ij}$ gleich der Wahrscheinlichkeit, dass $i$ und $j$ miteinander verglichen werden. 

Aufgrund der [[Wahrscheinlichkeitsrechnung#Grundlagen|linearität des Erwartungswerts]] ist das dasselbe wie:

$$
E[X]=\sum\limits_{i=1}^{n-1}\sum\limits_{j=i+1}^{n}E[X_{ij}]
$$
und da $X$ eine Binärvariable ist:
$$
E[X]=\sum\limits_{i=1}^{n-1}\sum\limits_{j=i+1}^{n}Pr[X_{ij}=1]
$$

Es gilt: $Pr[X_{ij}=1]=Pr[x=y_{i}\lor x=y_{j}]$, wobei $x$ das Pivot-Element ist. Die Wahrscheinlichkeit, dass in einer Folge von $y_i$ bis $y_{j}$ eins von beiden das Pivot-Element ist, ist $\frac{2}{j-i+1}$.

Wenn man das jetzt oben in diese Doppelsumme einsetzt und ein bisschen rumrechnet, kommt man auf:
$$E[X]=(2n+2)(H_{n}-1)-2(n-1)$$
wobei $H_{n}=\sum_{i=1}^{n}1/i$ ist (die $n$-te harmonische Zahl).

Diese Harmonische Zahl wächst logarithmisch, und der zweite dominierende Faktor ist $2n+2$. Zusammengenommen liegt dieser Term also in $O(n\log n)$.
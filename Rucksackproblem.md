Alias: **Knapsack Problem**, **KP**
Tags: #NP, #NP-schwer, #NP-vollständig, #DynamischeProgrammierung

# Rucksackproblem
## Definition
Man hat einen Rucksack mit einer gewissen Kapazität, und man hat Elemente mit jeweils einem bestimmten Nutzen und einem bestimmten Gewicht.[^1]
Man möchte den Rucksack so füllen, dass der Nutzen der in ihm enthaltenen Elemente maximal wird, ohne dass die Kapazität überschritten wird.

[^1]: Die Größen für Kapazität und Gewicht sind üblicherweise diskreter Natur.

## Abwandlung: Fraktionales Rucksackproblem

Bei dem fraktionalen Rucksackproblem wird erlaubt, dass man die Elemente beliebig zerstückeln kann. Dies hat zur Konsequenz, dass man die Kapazität des Rucksacks immer vollständig ausnutzen kann.

Dieses Problem ist sehr einfach zu lösen: man sortiert die Elemente nach ihrer Effizienz ($=\frac{\text{Nutzen}}{\text{Gewicht}}$), und packt dann nacheinander die Elemente mit der höchsten Effizienz in den Rucksack. Passt irgendwann ein Element nicht mehr rein, packt man es zerstückelt rein, sodass der Rucksack komplett voll ist. Diese Greedy-Lösung ist optimal, da jede Kapazitätseinheit des Rucksacks optimal ausgenutzt wird.

## Lösungen und Approximationen

### $\frac{1}{2}$-Approximation per Greedy-Verfahren

> 1. Sortiere Objekte nach ihrer *Effizienz*: $$\frac{p_{1}}{w_{1}}\geq \frac{p_{2}}{w_{2}} \geq \ldots \geq \frac{p_{n}}{w_{n}}$$
> 2. `for i from 1 to n`:
> 	1. falls $p_{i}$ in den Rucksack passt, füge es hinzu
> 3. Sei $i ^{\ast}$ ein Objekt mit größtem Nutzen $p_{i ^{\ast}}$
> 4. Falls $p(\text{Rucksack})<p_{i ^{\ast}}$: packe nur $i ^{\ast}$ in den Rucksack.

Ohne Schritt 4 ist dies kein Approximationalgorithmus, da die Lösung beliebig schlecht werden kann (s.u. für beliebig große $M >2$):

Kapazität = $M$

| Objekt $i$ | Nutzen $p_{i}$ | Gewicht $w_{i}$ |
| ---------- | -------------- | --------------- |
| 1          | 2              | 1               |
| 2          | $M$            | $M$             | 

Allgemein gilt: $$OPT \leq p(B) + p_{i+1},$$wobei $B = \set{1,\ldots,i}$ mit $i<n$ die in Schritt 2 berechnete Menge ist. 
Also: $$\begin{align*}
&\max \set{p(B), p_{i ^{\ast}}}\\
\geq& \max \set{p(B), p_{i +1}}\\
\geq& \frac{1}{2} (p(B) + p_{i+1})\\
\geq& \frac{1}{2} \space OPT.
\end{align*}$$

Der vollständige Beweis ist in [[Skript - Approximationsalgorithmen.pdf|diesem Skript]] auf S. 15f.

### Approximationsschema

FPTAS mittels [[Algorithmen#Dynamische Programmierung|dynamischer Programmierung]].
Zentrale Frage: Was ist das *geringste Gewicht*, um einen gewissen *Mindestnutzen* zu erreichen?

#### Dynamisches Programm

Es sei $W(i,p)=\min\set{w_{1}x_{1}+\ldots+_{i}x_{i}\mid p_{1}x_{1}+\ldots+p_{i}x_{i}\geq p}$ das minimale Gewicht, das erreicht wird, um einen Nutzen von mindestens $p \in \set{1,\ldots,nP}$ zu erzielen, wenn man nur die ersten $i$ Objekte zur Verfügung hat.

Es ist $W(0,p)=0$ für $p\leq 0$ bzw. $W(0,p)=\infty$ für $p>0$, und $$W(1,p)=\left\{\begin{align*}
0&\text{ falls } p \leq 0\\
w_{1}&\text{ falls }0 < p\leq p_{1}\\
\infty &\text{ falls } p>p_{1}.
\end{align*}\right.$$

Rekursive Berechnung: $W(i+1,p)=\min\set{W(i,p),W(i,p-p_{i+1})+w_{i+1}}$.

Im ersten Fall ist das $(i+1)$te Objekt im Rucksack enthalten, im zweiten eben schon.

Zum Schluss wird das maximale $p \in \set{1,\ldots,nP}$ ausgegeben, sodass $W(n,p)\leq t$.

#### FPTAS
$1-\epsilon$ - Approximation:

Sei $P$ wieder der maximale Nutzen eines Objekts.
Dann wird der Skalierungsfaktor gesetzt auf $K := \epsilon \frac{P}{n}$.

Runde nun jedes Gewicht auf Vielfache von $K$: $p_{i}'=\lfloor p_{i}/K\rfloor$.

Rufe schließlich obiges dynamische Programm mit $p_{1}',\ldots,p_{n}', w_{1},\ldots,w_{n},t$ auf.

Beispiel:
$n=4$, $P=50$ und $\epsilon=\frac{4}{5}$. Dann ist $K=\epsilon \frac{P}{n}=10$.

| Nutzen     | Skalierter Nutzen |
| ---------- | ----------------- |
| $p_{1}=33$ | $p_{1}'=3$        |
| $p_{2}=25$ | $p_{2}'=2$        |
| $p_{3}=50$ | $p_{3}'=5$        |
| $p_{4}=27$ | $p_{4}'=2$        |

Wie man sieht, verliert man etwas an Genauigkeit, jedoch hält man seine $p$-Werte schön klein, was sich positiv auf die Laufzeit auswirkt:

$P'=\max\limits_{i\in \set{1,\ldots,n}}p_{i}'=\left\lfloor\frac{P}{K}\right\rfloor=\left\lfloor\frac{P}{\epsilon \frac{P}{n}}\right\rfloor=\left\lfloor\frac{n}{\epsilon}\right\rfloor \leq \frac{n}{\epsilon}$ $\to$ *Laufzeit von $\Theta(n^{2}P')=\mathcal{O}(\frac{n^{3}}{\epsilon})$* $\to$ ***FPTAS***

### Genaue Berechnung mit dynamischer Programmierung

```cpp
std::vector<std::vector<int>> dyn_kp(
		int capacity,
		std::vector<int>& utility,
		std::vector<int>& weights)
{
    int n = utility.size();
    std::vector<std::vector<int>> P(n);
    for (int i = 0; i < n; i++)
        P[i] = std::vector<int>(capacity + 1);
  
    for (int w = 0; w < weights[0]; w++)
        P[0][w] = 0;
    for (int w = weights[0]; w <= capacity; w++)
        P[0][w] = utility[0];

    for (int i = 1; i < n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (weights[i] > w) {
                P[i][w] = P[i - 1][w];
                continue;
            }
            P[i][w] = std::max(utility[i] + P[i - 1][w - weights[i]], P[i - 1][w]);
        }
    }
  
    return P;
}
```

#### Zerlegung in Teilprobleme
Voraussetzung: man hat seine $n$ Objekte in irgendeiner festgelegten Ordnung (heißt jedes Objekt hat einen Index $i$ mit $0\leq i<n$).
Man definiert sich nun seine Teilprobleme in folgender Form:
> Was wäre, wenn ich nur die ersten $i$ Objekte zur Verfügung hätte, und einen Rucksack mit Kapazität $w$ mit $0\leq w\leq nW$?[^1]

Man baut sich also eine Tabelle auf, in der die Optimallösung (heißt: der maximale Nutzen $P(i,w)$) für alle möglichen $i$ und $w$ enthalten sind. Man hat dann für jedes $i$ eine Zeile und für jedes $w$ eine Spalte.
Nun füllt man die Tabelle zeilenweise (ein $i$ nach dem nächsten). Bei jeder Zelle fragt man sich folgendes: 
> Wenn ich das Objekt reinpacke, und dann die Optimallösung für den Rest der Kapazität (mit den ersten $i-1$ Objekten) obendrauf packe, ist die Lösung dann besser als wenn ich direkt die Optimallösung $P(i-1,w)$ nehme?

Formal gesprochen: $$P(i,w)=\max\set{p_{i}+P(i-1,w-w_{i}),\space P(i-1,w)}$$
Wenn man bei $P(n,t)$ angekommen ist, kann man aufhören.

Man kann sich in der Tabelle zusätzlich merken, ob man in einem Feld $(i,w)$ das entsprechende Objekt eingepackt hat oder nicht. Damit kann man dann am Ende rekonstruieren, mit welchen Objekten man den optimalen Nutzen erreicht.

#### Laufzeit
Da die Tabelle $n\cdot W$ Spalten hat, hängt die Laufzeit nicht nur von der Anzahl der Elemente, sondern auch vom Gewicht des schwersten Elements ab, und die Laufzeit ist in $\Theta(n^{2}W)$.

[^1]:  $W$ ist hierbei das Gewicht des schwersten Elements, d.h. $nW$ dient als Obergrenze. Das macht man deshalb, damit man am Ende eine vollständige Tabelle hat und für eine beliebige Rucksackkapazität $t$ direkt eine optimale Lösung geben kann. Will man die Lösung nur für ein einziges $t$ berechnen, kann man natürlich auch $t$ statt $nW$ als Obergrenze nehmen und spart dadurch Zeit. 

### Reduktion auf Kürzeste-Wege-Problem

Sei $P=\max_{i}p_{i}$ der Nutzen des nützlichsten Objektes, sowie $\tilde{p}_{i}=P-p_{i}$. 
Konstruiere daraus in polynomieller Zeit den folgenden Graphen als Eingabe für das [[Kürzeste Wege#Beschränktes Kürzeste-Wege-Problem|beschränkte Kürzeste-Wege-Problem]]:
![[Rucksackproblem_BKWP.png]]

Die Gewichtsschranke sei hierbei die Kapazität des Rucksacks ($W=t$) und die Kostenschranke $C=nP-z$, wobei $z$ die Nutzenschranke für die Entscheidungsvariante des KP ist.

Wird nun ein Objekt $i$ in den Rucksack gepacht, ist das äquivalent dazu, dass der optimale Pfad die obere Kante mit den Attributen $(w_i,\tilde{p}_i)$ wählt.
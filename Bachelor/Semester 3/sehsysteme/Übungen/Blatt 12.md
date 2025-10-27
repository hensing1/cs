# Übungsblatt 12

- Henning Lehmann

## Aufgabe 1

Referenz: $(0;2;0)$

| Punkt | $\alpha$ | $\beta$ |
| ---- | ---- | ---- |
| $(-1;0;0)$ | $1$ | $-2$ |
| $(-1;1;0)$ | $1$ | $-1$ |
| $(-1;2;0)$ | $1$ | $0$ |
| $(0;2;0)$ | $0$ | $0$ |
| $(1;2;0)$ | $1$ | $0$ |
| $(1;1;0)$ | $1$ | $-1$ |
| $(1;0;0)$ | $1$ | $-2$ |

Spin Image:

| $\uparrow \beta; \rightarrow \alpha$ | 0 | 1 | 2 |
| ---- | ---- | ---- | ---- |
| 2 |  |  |  |
| 1 |  |  |  |
| 0 | 1 | 2 |  |
| -1 |  | 2 |  |
| -2 |  | 2 |  |
Merkmalsvektor: $$\begin{pmatrix}0 & 0 & 0 & 0 & 0 & 0 & 1 & 2 & 0 & 0 & 2 & 0 & 0 & 2 & 0\end{pmatrix}$$

## Aufgabe 2

### 1.
![[KD-Baum.png]]

### 2.

Query Point: $q = (2;0.5)$
Distanz: $d = \infty$

*Baumabstieg:*
- $2 \leq 3.5$ $\to$ Linker Teilbaum
- $0.5 \leq 2$ $\to$ Linker Teilbaum
- $2 > 1.5$ $\to$ Rechter Teilbaum

Blattknoten: $c = (2;2)$
$\text{dist}(q, c) = 1.5 < \infty$
$\to d = 1.5$
$\to$ Aktueller nächster Nachbar: $b = (2;2)$

*Baumaufstieg:*
- Distanz zu Hyperebene: $d' = \text{dist}(q, (x=1.5)) = 0.5 < 1.5$
	- $\to$ Baumabstieg:
		- Blattknoten: $c = (1;1)$
		- $d'=\text{dist}(q,c) = \sqrt{1^{2}+0.5^{2}}=\frac{\sqrt{5}}{2}\approx1.12 < 1.5$
		- $\to d = 1.12$
		- $\to b = (1;1)$
- Distanz zu Hyperebene: $d' = \text{dist}(q, (y=2))=1.5 > 1.12$
	- $\to$ kein Baumabstieg
- Distanz zu Hyperebene: $d' = \text{dist}(q, (x=3.5))=1.5 > 1.12$
	- $\to$ kein Baumabstieg

Gefundener nächster Nachbar: $b = (1;1)$.

![[KD-Suche.png]]


## Aufgabe 3

### 1.

- $d=1$:
	- Maximal: $0.5^{1}=50\%$
	- Minimal ($q$ befindet sich am Rand): $(0.5/2)^{1}=25\%$
- $d=2$:
	- Maximal: $0.5^{2}=25\%$
	- Minimal ($q$ befindet sich in einer Ecke): $(0.5/2)^{2}=6.25\%$
- $d=3$:
	- Maximal: $0.5^{3}=12.5\%$
	- Minimal: $0.25^{3}=1,5625\%$
- $d=10$:
	- Maximal: $0.5^{10}=\frac{1}{1024}\approx 0.098\%$
	- Minimal: $0.25^{10}=(\frac{1}{1024})^{2}\approx 9.54 \cdot 10^{-5}\%$

### 2.
Bei einer Bereichsanfrage in einem $k$-d-Baum ist darauf zu achten, dass der Anfragepunkt nicht zu weit am Rand jeder Dimension liegt. 
Liegt der Anfragepunkt in einer Ecke, so werden im Vergleich zu einem mittigen Punkt ein Anteil von $0.5^{d}$ der Punkte ausgeschlossen.

Außerdem muss bei höherer Dimensionalität die Bereichsgröße größer gewählt werden, da ansonsten der Anteil der erfassten Punkte exponentiell abfällt.

## Aufgabe 4

### 1.
Bei Punkten in allgemeiner Lage wird in beiden Fällen die Anzahl der Punkte pro Knoten mit jeder hinzugefügten Hyperebene halbiert. Also haben beide Bäume die Höhe $h=\lceil \log_{2}(N) \rceil$, wobei $N$ die Anzahl der Punkte ist.

### 2.
Erneut ist die Höhe beider Bäume gleich. Die Argumentation ist dieselbe wie bei 1.
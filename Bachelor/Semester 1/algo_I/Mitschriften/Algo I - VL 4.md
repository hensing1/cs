[[algo_I_02_3.pdf|Folien]]
Überkapitel: *Methoden zum Entwurf von Algorithmen*
# Dynamische Programmierung

## Definition
![[Algorithmen#Methoden zum Entwurf von Algorithmen#Dynamische Programmierung]]

## Beispiele
### Fibonacci-Zahlen
Die Fibonacci-Zahlen können rekursiv berechnet werden:
```py
def fib(n):
	if n==0:
		return 0
	if n==1:
		return 1
	return fib(n-1)+fib(n-2)
```

Die Laufzeit dieser Implementierung ist in $\Theta(2^{n})$ - jeder Aufruf führt im schlimmsten Fall zu zwei weiteren rekursiven Aufrufen.
Werden dagegen die Zwischenergebnisse abgespeichert (oder wird das Problem iterativ statt rekursiv gelöst), muss jede Fibonacci-Zahl nur einmal berechnet werden und die Laufzeit liegt in $\Theta(n)$.

### Zuschnittproblem
Man angenommen man hat ein Brett der Länge $n\in\mathbb{N}$, und man kann dieses Brett beliebig in Teilstücke der Länge $i\in\mathbb{N},1\leq i\leq n$ zersägen. Für jede mögliche Brettlänge $i$ kann ein bestimmter Preis $p_{i}$ erzielt werden.
Nun möchte man das Brett so zersägen, dass man den größtmöglichen Gesamtpreis erzielen kann.

#### Beispiel für $n=5$
![[Zuschnittproblem.png]]

#### Berechnung
Die Berechnung erfolgt ähnlich wie die der Fibonacci-Zahlen:
- Für eine beliebige Brettlänge $i$ ist ist der Bestpreis $R_{i}=\max\{p_{j}+R_{i-j}|j\in\set{1,...,i}\}$.
- Wenn man es rekursiv berechnet, wird bei jedem Aufruf der Bestpreis für alle kleineren Längen bestimmt.
- Wenn man hierbei die Ergebnisse nicht zwischenspeichert, wächst die Laufzeit wieder exponentiell mit $n$.
- Auch dieses Problem löst man einfacher iterativ als rekursiv (mit Laufzeit $\Theta(n^2)$):
	- Definiere Erlös für Länge $\leq 0$ als $0$
	- $R_{1}=p_{1}$
	- $R_2$ ist das Maximum aus $p_{1}+R_1$ und $p_{2}$
	- $R_3$ ist das Maximum aus $p_1+R_2$ , $p_2+R_1$ , und $p_3$
	- ...

### Rucksackproblem (nochmal)
Zur Erinnerung: [[Rucksackproblem]]

Durch dynamische Programmierung kann das richtige Rucksackproblem (mit nicht-teilbaren Objekten) optimal gelöst werden.

![[Rucksackproblem#Zerlegung in Teilprobleme]]

![[Rucksackproblem#Laufzeit]]
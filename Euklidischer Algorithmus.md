# Euklidischer Algorithmus

> Der euklidische Algorithmus berechnet den *[[Glossar#Größter gemeinsamer Teiler|größten gemeinsamen Teiler]]* zwischen zwei ganzen Zahlen.

## Beschreibung
```
def ggT(a,b):
	x[0] = max(a,b)
	x[1] = min(a,b)
	i = 1
	while (x[i] != 0):
		x[i+1] = x[i-1] mod x[i]
		i++
	return x[i-1]
```

## Funktionsweise
Die Korrektheit von `ggT` folgt aus der formalen Definition des größten gemeinsamen Teilers:
![[Glossar#Größter gemeinsamer Teiler]]

Der Algorithmus produziert eine Zahlenfolge $(x_0,x_1,\ldots,x_{n-1},x_{n})$ mit $x_{n-1}=\text{ggT}(x_{0},x_{1})$ und $x_{n}=0$.
Außerdem lässt sich jedes $x_i$ schreiben als $x_{i}=q \cdot x_{i+1} + x_{i+2}$.
**Erstens: $x_{n-1}$ teilt $x_0$ und $x_1$**
Da $x_n=0$, gilt $x_{n-2}=q_{n-1} \cdot x_{n-1} + x_{n} = q_{n-1} \cdot x_{n-1} \Rightarrow x_{n-1} \mid x_{n-2}$.
Weiterhin: $(x_{n-3}=q_{n-2} \cdot x_{n-2}+x_{n-1}) \land (x_{n-1} \mid x_{n-2}) \Rightarrow x_{n-1} \mid x_{n-3}$.
Das kann man jetzt immer so weiterführen, bis man bei $x_{1}$ und $x_{0}$ ankommt.

**Zweitens: alle weiteren Teiler von $x_{0}$ und $x_{1}$ teilen $x_{n-1}$**
Sei $d'$ ein Teiler von $x_0$ und $x_1$.
Schreibt man $x_{2}=x_{0}-q_{1}\cdot x_{1}$, wird ersichtlich, dass $d'$ auch $x_{2}$ teilt. 
Da $x_{3}=x_{1}-q_{2}\cdot x_{2}$, teilt $d'$ auch $x_{3}$, usw. Daher teilt $d'$ auch $x_{n-1}$.


## Laufzeit
Die Anzahl der While-Durchläufe beträgt maximal $2 \cdot \log_{2}(x_0)$.

Das liegt daran, dass sich das $x_{i}$ mindestens alle zwei Schleifendurchläufe halbiert:
$$
x_{i}=q_{i+1} \cdot x_{i+1} + x_{i+2} \geq x_{i+1}+x_{i+2} > 2x_{i+2}
$$

# Erweiterter euklidischer Algorithmus
Bei dem erweiterten euklidischen Algorithmus verwendet man die Teilergebnisse aus dem einfachen euklidischen Algorithmus, um eine Linearkombination $g=ax+by$ mit $\text{ggT}(x,y)=g$ zu berechnen.


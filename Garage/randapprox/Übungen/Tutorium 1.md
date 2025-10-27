Datum: 19.10.

# Aufgabe 1.1

*Gegeben:* gerichteter Graph $G=(V,E)$ (ohne Schleifen)
*Mögliche Lösungen:* $S \subseteq E: (V,S)$ enthält keine Kreise.
*Zielfunktion:* maximiere $|S|$

Algorithmus:
1. $V=\set{v_{1},\ldots,v_{n}}$
2. $S_{1} = \set{(v_{i},v_{j}) \in E, i<j}$
   $S_{2} = \set{(v_{i},v_{j}) \in E, i > j}$
3. Gib $S_{1}$ aus, falls $|S_{1}|\geq |S_{2}|$, sonst gib $S_{2}$ aus.

#### Korrektheit
Angenommen, es gäbe Kreis in $S_{1}$. Seien $v_{i}$ und $v_{j}$ Knoten in diesem Kreis, dann muss es Pfad von $v_{i}$ nach $v_{j}$ sowie von $v_{j}$ nach $v_{i}$ geben. Sei oBdA $i<j$, dann muss es mindestens eine Kante $\set{u,v}$ in dem Pfad $v_{j}\to v_{i}$ geben, sodass $u>v$. Diese Kante kann jedoch nicht in $S_{1}$ vorhanden sein.

Argumentation für $S_{2}$ analog.

#### $\frac{1}{2}$-Approximation
Es ist $|S_{1}|+|S_{2}|=|V|$, also ist $\max \set{|S_{1}|, |S_{2}|}\geq \frac{|V|}{2}$. 

Außerdem ist $OPT\leq|V|$. 

Also ist $r= \frac{|V|/2}{|V|}=\frac{1}{2}$.

#### Approximation ist nicht besser als $\frac{1}{2}$
![[Kreisfreier Graph|250]]

$OPT=2$, jedoch $\max \set{|S_{1}|,|S_{2}|}=1$.

# Aufgabe 1.2
[[Bin Packing]]:
Geben Sie einen Greedy-Algorithmus mit Laufzeit $\mathcal{O}(n)$ und Approximationsfaktor 2 an.

> **Greedy Bin Cover**
> 1. $i := 1$
> 2. For $s_{k}$ in $M$:
> 	1. if $b_{i} + s_{k} \geq 1$: $i$++
> 	2. $b_{i}$ += $s_{k}$
> 3. return $\set{b_{1},\ldots,b_{i}}$

$\frac{1}{2}$-Approximation: 
- $OPT \geq \left\lceil \sum\limits_{k=1}^{n} s_{k} \right\rceil$ 
- Bins am Ende des Algorithmus durchschnittlich mindestens halbvoll:
	- Falls ein Objekt nicht mehr in Bin $i$ reinpasst, dann haben die Bins $i$ und $i+1$ zusammen mindestens Füllstand 1, also durchschnittlich 1/2.

# Aufgabe 1.3
Es gibt in einem Baum immer ein optimales [[Vertex Cover]], das keine Blätter enthält:

Sei $S$ ein optimales Vertex Cover. Falls $\exists$ Blatt $v \in S$: entferne $v$ aus $S$ und füge Elternknoten hinzu.
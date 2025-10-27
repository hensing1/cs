# Grundlagen

## Zufallsvariablen
Eine Zufallsvariable kann genau einen Wert aus einer beliebigen, gegebenen Menge annehmen.
Jedem dieser Werte ist eine Wahrscheinlichkeit zugeordnet. Die Wahrscheinlichkeiten müssen sich zu 1 aufsummieren.

## Wahrscheinlichkeit und Erwartungswert

Für ein Zufallsereignis $A$ ist $Pr[A]$ die *Wahrscheinlichkeit*, dass es eintritt. $Pr[A]$ ist auch die *relative Häufigkeit* von $A$, wenn das Experiment sehr oft wiederholt wird.

Wenn das Experiment unendlich oft wiederholt wird, ist der *Erwartungswert* $E[X]$ der Durchschnittswert der Zufallsvariable $X$.
$E[X]$ wird berechnet, indem man die Summe aus allen möglichen Werten von $X$ berechnet und dabei jeden Wert mit der Wahrscheinlichkeit gewichtet, mit der er auftritt.

Formeln für $E[X]$:
Falls $X$ nur Werte aus $\mathbb{Z}$ annehmen kann:
$$
E[X]=\sum\limits_{i=-\infty}^{i=\infty}i\cdot Pr[X=i]
$$
Alternative Formel, falls $X$ nur Werte aus $\mathbb{N}_{0}$ annehmen kann:
$$
E[X]=\sum\limits_{i=1}^{i=\infty}Pr[X\geq i]
$$

> [!info] Binäre Zufallsvariable
> Für eine Zufallsvariable $X$, die nur die Werte 0 oder 1 annehmen kann, ist $E[X]=Pr[1]$.

> [!info] Linearität des Erwartungswertes
> Für zwei beliebige Zufallsvariablen $X$ und $Y$ gilt: $$E[X+Y]=E[X]+E[Y].$$ Das gilt auch dann, wenn $X$ und $Y$ voneinander abhängen.

## Etwas formeller
Aus der Vorlesung [[INF 153 - Einführung in Deep Learning für Visual Computing]]:

![[DLVC - VL 2#Grundlagen]]

![[DLVC - VL 2#Multivariate Wahrscheinlichkeit]] ^70b256

![[DLVC - VL 2#Erwartungswert und Varianz]]

![[DLVC - VL 2#Shannon-Entropie]]

![[DLVC - VL 2#Kreuzentropie]]

## Theoreme
$P(A) = 1 - P(\lnot A)$
$P(A \lor B) = P(A) + P(B) - P(A \land B)$

$P(A,B) = P(A \land B) = P(A|B)\cdot P(B)$
$P(A,B|C) = P(A|B,C)\cdot P(B|C)$

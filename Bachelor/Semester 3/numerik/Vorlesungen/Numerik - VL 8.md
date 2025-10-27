Datum: 01.12.
[[Skript_2023_01_26.pdf|Skript]] bis S. 94

# Eigenwertprobleme
*Kapitel 7*

Es geht (in dieser Vorlesung) um symmetrische, rellwertige, quadratische Matrizen.

## Schur-Faktorisierung

Zerlegung in der Form $$A = QTQ ^{\ast},$$
wobei:
- $Q$ unitär
- $T$ obere Dreiecksmatrix
	- Für $T$ und $A$ gilt:
		- gleiches charakteristisches Polynom
		- gleiche Eigenwerte
		- gleiche algebraische und geometrische Vielfachheiten

Eine Schur-Faktorisierung gibt es für *jede quadratische Matrix* $A \in C^{m \times m}$.

### Frobenius-Begleitmatrix

monisches Polynom: hat nur eine Variable

- für jedes monische Polynom $p$ gibt es eine Matrix, die $p$ als charakteristisches Polynom hat.
- diese Matrix kann man konstruieren

$\Rightarrow$ es gibt ein Limit für die analytische Bestimmung von Eigenwertproblemen

Wir möchten also Eigenwerte schätzen, um die Eigenwerte iterativ (konvergieren) zu bestimmen

Wir nehmen einen beliebigen Vektor $x \in \mathbb{R}^{m}\setminus \set{0}$

Wie nah ist dieser Vektor daran, ein Eigenvektor zu sein?

$\Rightarrow$ Lösung für $\|Ax - \alpha x\|_{2}\stackrel{\alpha}{\to}\min$ bestimmen

Lösung mit Normalengleichung: $x^{T}x \alpha = x^{T}Ax \iff \alpha= \frac{x^{T}Ax}{x^{T}x}$

$\to$ $\alpha$ heißt Rayleigh-Koeffizient
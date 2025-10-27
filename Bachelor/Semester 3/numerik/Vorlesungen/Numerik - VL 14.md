Datum: 26.01.

# Mehr Analysis

## Schmiegequadrik

Von der Taylor-Approximation kommt man direkt zur Schmiegequadrik.

Die Formel ist analog zur Tangentielebene, nur dass man noch die zweite Ableitung dazunimmt (Taylorformel zweiter Iteration):
$$x_{n+1}=T_{2}f(x;a)=f(a) + f'(a)(x-a) + \frac{1}{2}(x-a)^{t}f''(a)(x-a)$$

- $f''$ ist Hessematrix (symmetrisch und deshalb diagonalisierbar)

- Schmiegequadrik hat dieselbe Krümmung wie der Graph im Punkt $a$
- Krümmung invers zum Radius der Kugel, mit der man den Graph approximieren kann
- Die Schmiegequadrik selbst ist entweder
	- elliptischer Paraboloid (definit)
	- hyperbolischer Paraboloid (semidefinit)
		- eine Parabel nach oben (positiver Eigenwert)
		- eine Parabel nach unten (negativer Eigenwert)
		- $\to$ Sattelfläche
	- zylindrischer Paraboloid (singulär)

## Lokale Extrema

**Notwendiges Kriterium**
Alle Richtungsableitungen sind Null $\to$ man hat *stationäre Stelle*.
Ein Sattelpunkt ist zum Beispiel eine stationäre Stelle.

**Hinreichendes Kriterium**
- Alle Richtungsableitungen Null
- Alle EW größer 0 oder alle EW kleiner 0

# Kapitel 9

Bislang haben wir $\mathbb{R}^{n}\to \mathbb{R}$ betrachtet. Jetzt kommt $\mathbb{R}^{n}\to \mathbb{R}^{m}$.

$$F(x_{1},\ldots,x_{n}) \mapsto \begin{pmatrix}f_{1}(x_{1},\ldots,x_{n}) \\ \vdots \\ f_{m}(x_{1},\ldots,x_{n})\end{pmatrix}$$

Differenzierbarkeit ist analog definiert: $f(a+h)=f(a)+L(h)+R(h)$

- $L(h)$ ist Matrix $L$ (Defferential, Linearisierung) angewendet auf Vektor $h$
- $R(h)$ ist Vektor
- $\lim_{h \to 0}\frac{R(h)}{\| h \|}=0$

Lemma?
Funktionalmatrix?


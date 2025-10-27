Datum: 09.11.
[[Robotik_05_Orientierungsrepraesentationen_DH-Parameter.pdf|Folien]]

Übung: [[Uebung_04.pdf]]
# Darstellung von Rotationen
Keine der Rotationsdarstellungen, die mit drei Parametern arbeitet, ist vollständig zufriedenstellend.

Man kann festlegen:
- Reihenfolge der Rotationen
- Ob sich die Achsen mitdrehen oder nicht

*Rotationsmatrizen*
$$\begin{align*}
R_{X}(\alpha)&=\begin{pmatrix}1 & 0 & 0 \\
0 & \cos \alpha & -\sin \alpha\\
0 & \sin \alpha & \cos \alpha\end{pmatrix}\\
R_{Y}(\beta)&=\begin{pmatrix}\cos \beta & 0 & \sin \beta\\
0 & 1 & 0\\
-\sin \beta & 0 & \cos \beta\end{pmatrix}\\
R_{Z}(\gamma)&=\begin{pmatrix}\cos \gamma & -\sin \gamma & 0\\
\sin \gamma & \cos \gamma & 0\\
0 & 0 & 1\end{pmatrix}
\end{align*}$$

^487b39

Durch Mulitplikation dieser Matrizen kann man eine beliebige Rotation im $\mathbb{R}^{3}$ beschreiben, siehe [[Robotik - VL 4#Berechnung|letzte Vorlesung]].

## Rotation um Vektor
Man kann immer einen Einheitsvektor $K$ finden, um den man mit $\theta$ rotieren kann, um eine Gesamtrotation zu beschreiben.

## Rückbestimmung: Rotationsmatrix $\to$ Winkel

Gegeben sei eine Rotationsmatrix $^A_BR=(r_{i,j})^{3 \times 3}$ und eine Rotationsdarstellung in Abhängigkeit von drei Winkeln, beispielsweise Z-Y-Z-Eulerwinkel.

Wir wollen diese Winkel anhand von $^A_{B}R$ bestimmen.

Ansatz: 
- bestimme allgemeine Rotationsmatrix für Z-Y-Z-Eulerwinkel: $$R_{ZY'Z''}(\alpha, \beta, \gamma)=R_{Z}(\alpha)\cdot R_{Y}(\beta) \cdot R_{Z}(\gamma)=\begin{pmatrix}\text{kompliziert} & \text{kompliziert} & \cos \alpha\sin \beta \\ \text{kompliziert} & \text{kompliziert} & \sin \alpha \sin \beta \\ -\sin \beta \cos \gamma & \sin \beta \sin \gamma & \cos \beta\end{pmatrix}$$
- Löse Winkel mit einfachstem Eintrag, in diesem Fall $\beta = \arccos(r_{3,3})$ 
- Nutze Ergebnis zur Bestimmung der anderen Winkel, in diesem Fall $\alpha = \arccos(r_{1,3}/\sin\beta)$ und $\gamma=\arcsin(r_{3,2}/\sin\beta)$

Das Problem: ist $\beta=0$ und und damit $\sin(\beta) = 0$, ist dies nicht mehr lösbar. In diesem Fall hat man eine Singularität.

> **Singularität**
> Eine Rotationsmatrix ist in einer *singulären Konfiguration* bzgl. einer Rotationsdarstellung, wenn es keine eindeutige Möglichkeit gibt, mit dieser Darstellung die Rotation zu beschreiben.

Im Falle von Eulerwinkeln hat man dann eine Singularität, wenn zwei der Rotationsachsen identisch (bzw. die Rotationsvektoren linear abhängig) sind.

Im obigen Beispiel bedeutet $\beta=0$, dass die Achsen $Z$ und $Z''$ identisch sind. Man kann also $\alpha$ beliebig wählen, und dennoch über die geeignete Wahl von $\gamma$ die Rotation erreichen.

Im Falle der Vektorrotation liegt eine Singularität vor, wenn $\sin \theta=0$, also wenn um 0° oder 180° gedreht wurde. Dann gibt es unendlich viele Vektoren, mir der diese Drehung entstanden sein könnte.

## Quaternionen
*Jede* Rotationsrepräsentation mit drei Parametern hat eine Singularität. Die Quarternionen sind eine Möglichkeit, eine Rotation *eindeutig* über vier Parameter $\epsilon_{1},\ldots,\epsilon_{4}$ darzustellen.

Gegeben sei eine Rotation um einen Vektor $W=\begin{pmatrix}w_{1} \\ w_{2} \\ w_{3}\end{pmatrix}$ um einen Winkel $\theta$.

Die Eulerparameter berechnen sich dann wie folgt:
$$\begin{align*}
\epsilon_{1}&=w_{1}\sin \frac{\theta}{2}\\
\epsilon_{2}&=w_{2}\sin \frac{\theta}{2}\\
\epsilon_{3}&=w_{3}\sin \frac{\theta}{2}\\
\epsilon_{4}&=\cos \frac{\theta}{2}.
\end{align*}$$
Wir nehmen $\frac{\theta}{2}$, damit der Sinus eindeutig ist.
Mit $\|W\|=1$ ist $\epsilon_{1}^{2}+\epsilon_{2}^{2}+\epsilon_{3}^{2}+\epsilon_{4}^{2}=1$.

Die Rotationsmatrix errechnet sich wie folgt:
![[Drehmatrix_Eulerparameter.png|500]]

Und umgekehrt: $$\begin{align*}
\epsilon_{4}&=\frac{1}{2}\sqrt{1+r_{11}+r_{22}+r_{33}}\\
\epsilon_{1}&= \frac{r_{32}-r_{23}}{4\epsilon_{4}}\\
\epsilon_{2}&= \frac{r_{13}-r_{31}}{4\epsilon_{4}}\\
\epsilon_{3}&= \frac{r_{21}-r_{12}}{4\epsilon_{4}}
\end{align*}$$
Ist $\epsilon_4=0$, berechnet man stattdessen ein anderes $\epsilon$ zuerst, und dann die übrigen Parameter in Abhängigkeit davon.


# Denavit-Hartenberg-Parameter

> Denavit-Hartenberg-Parameter beschreiben eine kinematische Kette auf kanonische Weise. 

Es gibt Glieder (starr) und Verbindungen zwischen Gliedern (beweglich). Verbindungen sind entweder Verdrehungen an einer Achse oder Verschiebungen entlang einer Achse.

Ein Glied $i$ verbindet zwei Achsen $i$ und $i+1$.
- Gliedparameter:
	- Achsenabstand $a_i$ (Länge der Verbindungslinie, die zu beiden Achsen rechtwinklig ist)
	- Winkel $\alpha_i$ zwischen Achsen $i$ und $i+1$
- Verbindungsparameter:
	- Linear-Offset $d_i$
		- Abstand zwischen $a_{i-1}$ und $a_i$ entlang Achse $i$
		- variabel für Lineargelenk
	- Rotationswinkel $\theta_i$
		- Winkel zwischen $a_{i-1}$ und $a_i$
		- variabel bei Drehgelenk

Also beschreibt man ein Gelenk $i$ durch die vier DH-Parameter $(\alpha_{i}, a_{i}, d_{i}, \theta_{i})$.

![[DH-Parameter.png|500]]

Jedes Glied hat sein eigenes Koordinatensystem. Bestimmung per Rechte-Hand-Regel:
- x (Zeigefinger) ist die Verbindungsachse
- z (Daumen) ist die Rotationsachse
- y zeigt in Richtung Mittelfinger
- Ursprung ist am Schnittpunkt zwischen Verbindungs- und Rotationsachse

**Sonderfälle:**
- Rotationsachsen schneiden sich $\to\,a_{i}=0$
- Rotationsachsen sind parallel $\to\,\alpha_{i}=0$

**Konventionen:**
- Die Achse 0 ist unbeweglich und beschreibt die Basis.
- Man setzt $a_0=0$ und $\alpha_0=0$. Achse 1 ist also gleich Achse 0 - alles was daran hängt, kann mit $d_1$ verschoben bzw. mit $\theta_1$ rotiert werden.
- An einer Achse ist *entweder* ein Lineargelenk *oder* ein Rotationsgelenk.
	- Bei einem Rotationsgelenk setzt man $d_{i}=0$, bei Lineargelenk $\theta_{i}=0$.
- Der Endeffektor ist an Achse $n+1$. Man setzt $a_n=0$ und $\alpha_n=0$. Der Endeffektor wird also mit $d_n$ verschoben bzw. mit $\theta_n$ rotiert.

Mittels der DH-Parameter lässt sich für jedes Gelenk die dazugehörige [[Robotik - VL 4#Transformationsmatrix|elementare Transformationsmatrix]] bestimmen:
$$^{i-1}_{i}T=\left[\begin{matrix}\cos \theta_{i} & -\sin \theta_{i} & 0 \\ \cos \alpha_{i-1}\sin \theta_{i} & \cos \alpha_{i-1} \cos \theta_{i} & -\sin \alpha_{i-1} \\ \sin \alpha_{i-1} \sin \theta_{i} & \sin \alpha_{i-1}\cos \theta_{i} & \cos \alpha_{i-1}  \\ 0 & 0 & 0 \end{matrix}\right|\left.\begin{matrix}a_{i-1} \\ -\sin \alpha_{i-1}d_{i} \\ \cos \alpha_{i-1}d_{i}  \\ 1\end{matrix}\right]$$

Die komplette kinematische Kette von Basis zum Endeffektor ist nun das Produkt $$^{0}_{N}T = \,^{0}_{1}T \cdot \,^{1}_{2}T \cdot\; \ldots\; \cdot \,^{N-1}_{N}T.$$
Datum: 20.10.
[[Slides_2023_01_26.pdf|Folien]] von Seite 37 bis 55

# Lineare Ausgleichsrechnung
*Kapitel 2*


*Gegeben:* eine Menge von Punkten $(u_{i},v_{i})$ im $\mathbb{R}^2$
*Gesucht:* ein Polynom, welches die Lage dieser Punkte "am besten" approximiert

## Kleinste Quadrate

Beispiel im $\mathbb{R}^2$:
Wir möchten die Parameter $x_0$ und $x_1$ einer Gerade $g(u):=x_0+x_1u$ so wählen, dass der quadratische Approximationsfehler minimiert wird:
$$\sum_{i=1}^{n}|v_{i}-g(u_{i})|^{2}=\sum_{i=1}^{n}(v_{i}-x_{0}-x_{1}u_{i})^{2}\to\min$$
Bzw. äquivalent: $$\left\|\begin{pmatrix}v_{1} \\ \vdots \\ v_{n}\end{pmatrix} - \begin{pmatrix}1 & u_{1} \\ \vdots & \vdots \\ 1 & u_{n}\end{pmatrix}\cdot \begin{pmatrix}x_0 \\ x_1\end{pmatrix}\right\|_{2}\to\min$$
Allgemein:
> [!abstract] Definition *Lineares Ausgleichsproblem*
> Seien $A \in \mathbb{C}^{m\times n}$, $b \in \mathbb{C}^{m}$ und $m\geq n$.
> Dann ist $x \in \mathbb{C}^{n}$ gesucht, sodass $$x=\arg\min\limits_{\!\!\!\!\!\!y \in \mathbb{R}^{n}}\left\|b - Ay\right\|_{2}.$$

$m$ ist hierbei die Anzahl der Datenpunkte und $n$ ist der Grad des Polynoms.

D.h.: $$b=\begin{pmatrix}v_{1} \\ \vdots \\ v_{m}\end{pmatrix},A= \begin{pmatrix}1 & u_{1} & u_{1}^{2} & \ldots & u_{1}^{n} \\ \vdots & \vdots & \vdots & \ddots & \vdots \\ 1 & u_{m} & u_{m}^{2} & \ldots & u_{m}^{n}\end{pmatrix}, x= \begin{pmatrix}x_0 \\ \vdots  \\ x_{n}\end{pmatrix}$$
### Lösung

> Jede Lösung $x$ des linearen Ausgleichsproblems $x=\arg\min\limits_{\!\!\!\!\!\!y \in \mathbb{R}^{n}}\left\|b - Ay\right\|_{2}$ ist eine Lösung der *Gaußschen Normalengleichung:* $$A ^{\ast}Ax=A ^{\ast}b.$$

^2db2dd

> Das lineare Auslgeichsproblem $x=\arg\min\limits_{\!\!\!\!\!\!y \in \mathbb{R}^{n}}\left\|b - Ay\right\|_{2}$ kann durch die [[Matrizen#Pseudoinverse|Pseudoinverse]] gelöst werden: $$x = A^{+}b.$$

### Residuum

Sei $x$ die Lösung für ein lineares Ausgleichsproblem $\|b-Ax\|\to\min$. Dann heißt $$r = b-Ax$$
das **Residuum** dieses Ausgleichsproblems.

Das Residuum steht orthogonal zum Bild von $A$: 
![[Residuum.png|400]]

Das bedeutet, $r$ gehört zum Kern von $A ^{\ast}$, also ist $A ^{\ast} r = 0$.

Daraus lässt sich die gaußsche Normalengleichung herleiten: $$\begin{align*}
A ^{\ast} r &= 0\\
\iff A ^{\ast} (b - Ax) &= 0\\
\iff A ^{\ast} b - A ^{\ast} Ax &= 0\\
\iff A ^{\ast}b &= A ^{\ast} Ax.
\end{align*}$$

## Thikonov-Regularisierung

Kleinste-Quadrate-Methode ist im höherdimensionalen meistens nicht ganz so gut.

Die Tikhonov-Regularisierung versucht, die Parameter für sein Polynom möglichst klein zu halten:

> Sei mit $x=\arg\min\limits_{\!\!\!\!\!\!y \in \mathbb{R}^{n}}\left\|b - Ay\right\|_{2}$ ein lineares Ausgleichsproblem gegeben. 
> 
> Die *Thikonov-Regularisierung* steuert die Norm des Lösungsvektors $x$ mithilfe von $\lambda > 0:$ $$\hat x = \arg\min\limits_{\!\!\!\!\!\!x \in \mathbb{R}^{n}}(\left\|b - Ax\right\|_{2} + \lambda\|x\|_{2}).$$
> 
> Ausgedrückt als Kleinste-Quadrate-Problem: $$\hat x =\arg\min\limits_{\!\!\!\!\!\!y \in \mathbb{R}^{n}}\left(\left\|\begin{pmatrix}A \\ \sqrt{\lambda} \cdot E\end{pmatrix}x-\begin{pmatrix}b \\ 0\end{pmatrix}\right\|^{2}_{2}\right).$$

Je größer $\lambda$, desto kleiner die Parameter $x_{0}, \ldots, x_{n}.$

Beispiel bei einer Gerade: man möchte z.B., dass der y-Achsen-Abschnitt nahe 0 ist.
Bei Polynomen höheren Grades bewirkt es, dass die Kurven weniger steil sind.

Die zugehörige Normalengleichung ist: $$(A ^{\ast} A + \lambda \cdot E) x = A ^{\ast} b.$$
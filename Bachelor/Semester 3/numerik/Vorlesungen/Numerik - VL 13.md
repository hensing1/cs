Datum: 19.01.
[[Skript_2023_01_26.pdf|Skript]] von S. 121 bis 130

# Differenzierbare Funktionen
*Kapitel 8 ff.*

## Orthogonalität von Gradient und Niveaumenge

> [!abstract] Definition *Niveaumenge*
> Sei $f: \mathbb{R}^{n} \to \mathbb{R}$  und $c \in \mathbb{R}$. Dann heißt $$N_{c}=\set{x \in \mathbb{R}^{n} \mid f(x) = c} \subseteq \mathbb{R}^{n}$$ die **Niveaumenge** von $f$ zum Niveau $c$.
> 

^2dab39

Sei also $\gamma: \mathbb{R} \supseteq I \to N_{c}$ eine differenzierbare Kurve in der Nullmenge.
Dann ist $f(\gamma(t))=c \, \forall t \in I$. Man bewegt sich gewissermaßen entlang einer Höhenlinie auf einer Landkarte.

Dann ist die Ableitung $\dot\gamma(t)$ der *Tangentialvektor* an einem Punkt $t$, und es gilt: $$\nabla f(\gamma(t)) \;\; \bot \;\; \dot\gamma(t) \quad \forall t \in I.$$
Der Gradient von $f$ entlang der Niveaumenge steht also senkrecht auf dem Tangentialvektor.

## Schrankensatz

Wir betrachten den [[Analysis - VL 15#Mittelwertsatz|Mittelwertsatz]], umformuliert als: 

> **Mittelwertsatz für mehrdimensionale Funktionen**
> Sei $f: \mathbb{R}^{n} \supseteq U \to \mathbb{R}$ differenzierbar und $a,b \in U$, sodass die Verbindungsstrecke in $U$ liegt.
> Dann gibt es einen Punkt $\xi \in [a,b]$ auf der Verbindungsstrecke(?), sodass $$f(b) - f(a) = f'(\xi)(b-a).$$

> **Schrankensatz**
> Sei $f: \mathbb{R}^{n} \supseteq U \to \mathbb{R}$ eine stetig differenzierbare Funktion, also in $C^{1}(U)$.
> Dann ist $f$ auf jeder *kompakten, konvexen Teilmenge*[^1] $K \subseteq U$ [[Stetigkeit#Lipschitz-Stetigkeit|lipschitzstetig]], d.h. $$|f(x) - f(y)|\leq \|f'\|_{K}\cdot\|y-x\|_{\infty}$$ mit $\|f'\|_{K} = \max\limits_{\xi \in K}(|\partial_{1}f(\xi)|, \ldots, |\partial_{n}f(\xi)|).$

[^1]: Kompakte Menge := abgeschlossene und beschränkte Menge

Das bedeutet, dass die Ableitung einer stetig differenzierbaren Funktion beschränkt ist, wenn man den Definitionsbereich einschränkt.

## Ableitungen höherer Ordnung

Die partiellen Ableitungen einer partiellen Ableitung heißen *partielle Ableitungen 2. Ordnung*.
Bezeichnungen hierfür: $$\partial_{i}(\partial_{j}f) =: \partial_{ij}f = f_{x_{j}x_{i}} = \frac{\partial^{2}f}{\partial x_{j}\partial x_{i}}.$$

> $\partial_{ij}f = \partial_{ji}f$ gilt im Allgemeinen nur dann, wenn $\partial_{ij}f$ oder $\partial_{ji}f$ *stetig* ist. ([[Analysis - VL 17#^a548c8|Satz von Schwarz]])


> **$k$-mal stetig differenzierbare Funktionen**
> Wenn man eine Funktion $f: \mathbb{R}\supseteq U \to \mathbb{C}$ $k$-mal ableiten kann, also alle partiellen Ableitungen $k$-ter Ordnung *existieren und stetig* sind, dann ist diese Funktion im [[Vektorräume|Vektorraum]] $C^{k}(U)$ der $k$-mal stetig differenzierbaren Funktionen auf $U$.
> 
> Der Vektorraum $C^{\infty} := \bigcap\limits_{k=1}^{\infty}C^{k}(U)$ ist der Raum aller unendlich oft stetig differenzierbaren Funktionen auf $U$.

> **Verallgemeinerung der [[Differenzialrechnung#Differenzierbarkeit im Mehrdimensionalen|Linearisierung]]**
> Man kann auch höhere Ableitungen linearisieren:
> - Erste Ableitung (bekannt): $df(a)u = (\partial_{1}f(a), \ldots, \partial_{n}f(a))\begin{pmatrix}u_{1} \\ \vdots \\ u_{n}\end{pmatrix}$
> - Zweite Ableitung: $d^{(2)}f(a)(u,v) := \partial_{u}(\partial_{v}f)(a)$
> - $p$-te Ableitung: $d^{(p)}f(a)(v^{1},\ldots,v^{p}) := \partial_{v^{1}}\ldots\partial_{v^{p}}f(a)$

Man kann wegen des Satz von Schwarz die Argumente von $d^{(p)}$ beliebig vertauschen.
Außerdem ist $d^{(p)}$ linear in jedem Argument.

Die 2. Ableitung ist darstellbar als ***Hesse-Matrix***: $$f''(a) = H_{f}(a) := \begin{pmatrix}\partial_{11}f(a) & \ldots & \partial_{1n}f(a) \\ \vdots & & \vdots \\ \partial_{n1}f(a) & \ldots & \partial_{nn}f(a)\end{pmatrix}.$$

Es gilt: $$d^{(2)}f(a)(u,v) = u^{t}f''(a)v.$$
## Taylor-Approximation

> **Taylorpolynom der Ordnung $p$ von $f$ in $a$:**
> $$T_{p}f(x;a) := \sum_{k=0}^{p}d^{(k)}f(a)(x-a)^{k}.$$

$T_{p}f(x;a)$ ist ein Polynom $p$-ten Grades, welches die Funktion $f$ in einem Bereich um den Punkt $a$ herum approximiert. 

$T_{1}$ ist also die bekannte lineare Approximation.

*Taylorformel mit Rest:*
Für $f: \mathbb{R}^{n}\supseteq U \to \mathbb{R}$ mit $f \in C^{p+1}(U)$ und $a,x \in U$ Punkte, deren Verbindungsstrecke in $U$ liegt, gilt: $$f(x) = T_{p}f(x;a) + R_{p+1}(x;a),$$ wobei das Restglied $R_{p+1}$ dargestellt werden kann als $$R_{p+1}(x;a) = \frac{1}{(p+1)!}d^{(p+1)}f(\xi)(x-a)^{p+1}$$für ein $\xi \in [a,x]$.

*Qualitative Taylorformel:*
Die Approximationsgüte des Taylorpolynoms lässt sich abschätzen mit: $$f(x) = T_{p}f(x;a) + \mathcal{o}(\|x-a\|^{p}).$$ Der Fehler $f(x) - T_{p}f(x;a)$ geht also schneller als $\|x-a\|^{p}$ gegen Null.

*Taylorreihe:*
Die Reihe $$\sum_{k=0}^{n} \frac{1}{k!}d^{(k)}f(a)(x-a)^{k}$$heißt Taylorreihe von $f$  im Punkt $a \in U$, für $f \in C^{\infty}(U)$.
$f$ heißt *reell-analytisch* in $U$, wenn jeder Punkt $a \in U$ eine Umgebung hat, in der $f$ durch die Taylorreihe in $a$ dargestellt wird.

- $e^{x}$ lässt sich vollständig durch die Taylorreihe in $a=0$ darstellen.
- Für $\ln(x)$ gibt es lediglich eine Umgebung um $a=1$, in welcher die Taylorreihe gegen $ln(x)$ konvergiert.
Datum: 22.12.
[[Skript_2023_01_26.pdf|Skript]] von S. 110 bis 120
# Differenzierbare Funktionen
*Kapitel 8*

Analysis! Nichtlineare Funktionen! Jaaaa!
Wir betrachten zunächst den Fall $\mathbb{R}^{n} \to \mathbb{R}$ bzw. $\mathbb{R}^{n}\to \mathbb{C}$.
$\mathbb{R}^{n} \to \mathbb{R}^{m}$ kommt später.
## Differenzierbarkeit

![[Differenzialrechnung#^05cbd8]]

Hierbei ist $h$ ein Vektor aus dem $\mathbb{R}^{n}$. Welche [[Numerik - VL 1#Vektornorm|Norm]] man für $\|h\|$ verwendet, spielt keine Rolle. 
$L$ beschreibt die Tangentialebene (relativ zum Punkt $a$). Im Fall $\mathbb{R}\to \mathbb{R}$ ist es also eine Gerade durch den Ursprung.

Die Tangential(hyper-)ebene selbst lässt sich mithilfe von $L$ als linear-affine Funktion darstellen (lineare Funktion mit additiver Konstante): $$Tf(x;a) := f(a) + df(a)(x-a).$$
$L$ lässt sich auch (wie in [[Analysis - VL 13#Differenzierbarkeit und Ableitungen|Analysis]]) mit einer Restemethode deifinieren:
$$f(a+h)-f(a) - R(h)=Lh$$
mit
$$\lim\limits_{h \to 0} \frac{R(h)}{\|h\|}=0.$$
Das heißt also, dass der Fehler, den man durch eine lineare Approximation macht, bei $a$ gegen Null geht.

## Ableitung

> [!abstract] Definition *Ableitung*
> Den *Zeilenvektor* $$f'(a) := (df(a)e_{1},\ldots,df(a)e_{n})$$ nennen wir **Ableitung** von $f$ in $a$.

### Differenzierbarkeit

Man kann eine Funktion $f: \mathbb{R}^{n} \to \mathbb{C}$ in irgendeine Richtung $h \in \mathbb{R}^{n}$ ableiten: $$df(a)h = D_{h}f(a) = \lim_{t \to 0}\frac{f(a+th)-f(a)}{t}$$
für den Skalar $t \in \mathbb{R}$.

> Die Ableitungen in den Richtungen der *Standardbasis* $e_{1},\ldots,e_{n}$ heißen **partielle Ableitungen** von $f$. 
> Notationen der partiellen Ableitung: $$D_{e_{1}}f(a) = \partial_{1}f(a) = \frac{\partial f}{\partial x_{1}}(a) = f_{x_{1}}(a).$$
> Existieren alle partiellen Ableitungen $D_{e_{1}}f(a), \ldots, D_{e_{n}}f(a)$, hießt $f$ in $a$ **partiell differenzierbar.**

Die Existenz der partiellen Ableitungen impliziert nicht die Differenzierbarkeit: für

$$f(x,y) = \left\{\begin{align*}0\quad\,\,& \text{ falls }(x,y) = (0,0)\\\frac{xy}{x^{2}+y^{2}}& \text{ sonst}\end{align*}\right.$$
ist $\partial_{x}f(0,0)=0$ und $\partial_{y}f(0,0)=0$, jedoch ist die Funktion im Nullpunkt nicht stetig.

Auch die Existenz aller *Richtungsableitungen* impliziert nicht die Differenzierbarkeit.
Die Richtungsableitungen liegen nämlich nicht zwangsweise in einer Ebene.
Ein Beispiel ist $$f(x,y) = \left\{\begin{align*}0\quad\,\,& \text{ falls }(x,y) = (0,0)\\\frac{x^{2}y}{x^{2}+y^{2}}& \text{ sonst}\end{align*}\right.$$ im Punkt $(0,0)$.
Die Funktion ist dort zwar stetig, die partielle Ableitung $\partial_{x} f$ aber nicht, wegen $\partial_{x}f(0,y) = \frac{1}{y}$ für $y \neq 0$.


Daher fordert die *hinreichende Bedingung* für Differenzierbarkeit etwas mehr:
> Exisiteren in einer Umgebung $U$ von $a \in \mathbb{R}^{n}$ alle partiellen Ableitungen $\partial_{1}f, \ldots, \partial_{n}f$ *und* sind diese im Punkt $a$ [[Stetigkeit#Reelle Funktionen|stetig]], dann ist $f$ in $a$ **differenzierbar**.

Ist die Ableitung $f'$ auf dem gesamten Urbild ebenfalls stetig, heißt $f$ **stetig differenzierbar**.
$f$ ist genau dann stetig differenzierbar, wenn *alle $n$ partiellen Ableitungen* $\partial_{1}f, \ldots, \partial_{n}f$ existieren und *stetig* sind.

Man unterscheidet zwischen differenzierbar und stetig differenzierbar wegen lustigen Funktionen wie $$f(x)=\begin{cases}
    x^2 \cos \left( \frac{1}{x} \right) & x\ne 0\\
    0 & x=0
  \end{cases}$$

mit $$f'(x)=\begin{cases}
2x\cos(\tfrac{1}{x}) + \sin (\tfrac{1}{x})& x\neq 0 \\
0 & x=0.
\end{cases}$$
$f$ ist in $0$ stetig und differenzierbar, aber $f'$ ist nicht in $0$ stetig.

Alle stetig differenzierbaren Funktionen auf $U \subseteq \mathbb{R}^{n}$ bilden einen [[Vektorräume|Vektorraum]]. Dieser Vektorraum heißt $C^{1}(U)$.

### Gradient

Der Gradient kann durch das Differenzial $L: \mathbb{R}^{n}\to \mathbb{R}$ und ein [[Matrizen#Skalarprodukt|Skalarprodukt]] beschrieben werden:

> Der Gradient $\text{grad}f(a)$ von $f$ im Punkt $a$ ist derjenige (eindeutig bestimmte) Vektor, für den gilt: $$Lh=df(a)h = \partial_{h}f(a) = \langle \text{grad}f(a), h \rangle \,\,\forall h \in \mathbb{R}^{n}.$$
> für ein gegebenes Skalarprodukt $\langle \cdot, \cdot \rangle$.

Mit anderen Worten ist $\text{grad} f(a)^{t} = DM(L)$.

Für das Standardskalarprodukt wird $\text{grad}f(a)$ mit $\nabla f(a)$ bezeichnet und es gilt: $$\nabla f(a) = \begin{pmatrix}\partial_{1}f(a) \\ \vdots  \\ \partial_{n}f(a)\end{pmatrix}.$$
Der Vektor $\nabla f(a)$ zeigt im Urbildraum gewissermaßen in die Richtung, in die von $a$ aus die Funktion am stärksten ansteigt. $|\nabla f(a)|$ sagt aus, wie stark die Funktion in diese Richtung ansteigt.

### Rechenregeln

Es gelten auch für $f, g: \mathbb{R}^{n} \to \mathbb{R}$ die Ableitungsregeln:
![[Analysis - VL 13#^c9d29c]]

Spezialfall der Quotientenregel: $$\left(\frac{1}{f}\right)'(a)=\frac{-f'(a)}{f^{2}(a)}.$$

Für die Linearisierungen gilt analog:
- $d(f+g)(a) = df(a) + dg(a)$
- $d(f \cdot g)(a) = df(a) \cdot g(a) + f(a) \cdot dg(a)$
- $d\left(\frac{1}{f}\right)(a) = \frac{-df(a)}{f^{2}(a)}$ für $f(a) \neq 0$

Für stetige Differenzierbarkeit gilt ebenfalls:
> Sind $f$ und $g$ in $U$ stetig differenzierbar, dann sind auch $f+g$, $f \cdot g$ und $f/g$ in $\set{x \in U \mid g(x) \neq 0}$ stetig differenzierbar.

- Polynomfunktionen sind stetig differenzierbar.
- Gebrochenrationale Funktionen (Quotienten von Polynomen) sind in ihrem Definitionsbereich stetig differenzierbar.

#### Kettenregel für mehrdimensionale Funktionen

> Es sei $\gamma: \mathbb{R}^{m} \to \mathbb{R}^{n}$ differenzierbar in $t_0$ und $f: \mathbb{R}^{n} \to \mathbb{R}$ differenzierbar in $\gamma(t_{0})$. 
> Dann ist $f \circ \gamma$ in $t_{0}$ differenzierbar.
> Die Ableitung ist: $$\frac{d(f \circ \gamma)}{dt}(t_{0}) = df(\gamma(t_{0})) \dot\gamma(t_{0}) = f'(\gamma(t_{0}))\dot \gamma(t_{0}) = \sum_{i=1}^{n}\partial_{i}f(\gamma(t_{0})) \cdot \dot \gamma_{i}(t_{0}) = \langle \nabla f(\gamma(t_0)), \dot\gamma(t_{0}) \rangle.$$


[[atcg2-05-Mesh_Smoothing.pdf]]

## Smoothing ist wie Hitzeverteilung

Gegeben seien:
- Ein Skalarfeld $\rho: \mathbb{R}^{2} \times \mathbb{R}_{\geq0} \to \mathbb{R}$ mit $(x,t) \mapsto \rho(x,t)$
	- Also ein Skalar auf jedem Punkt der Oberfläche, veränderlich über die Zeit
	- Wir interprätieren das als Temperaturfeld
- Die Umrandung eines Objekts: $\partial \Omega$

Das Smoothing eines Objekts ist jetzt die Diffusion der Hitze über die Grenze des Objekts.

Die Hitze verteilt sich in die entgegengesetzte Richtung des Gradienten (Fouriersches Gesetz): $$f= -\lambda \cdot \nabla \rho(x,t).$$
Mit Hitzefluss $f$ und Normalenvektor $n$ des Objekts ist der Gesamtfluss (Flux), der sich über die Objektgrenze bewegt: $$\Phi=\int_{\partial \Omega}\langle f \mid n \rangle \,dA.$$
Dieser Wert lässt sich anders ausdrücken als die Menge an Hitze, die das Gesamtobjekt an Hitze verliert: $$\Phi=- \int_{\text{interior}(\Omega)}\frac{ \partial  }{ \partial t } \rho(x,t)\,dV.$$
> **Diffusionsgleichung** (Diffusion Equation, Heat Equation)
> $$\frac{ \partial  }{ \partial t } \rho(x,t)=\lambda \cdot \nabla \rho(x,t)$$

Für Bilder entspricht die Diffusion über Zeit $t$ der Konvolution mit einem [[CV 2 - Filtering#Gauß-Filter|Gauß-Filter]] mit $\sigma=t:$
$$\rho(\cdot,t)=g(\cdot,t) \otimes \rho(\cdot,0)$$
mit $g(x,t)= \frac{1}{\sqrt{ 2 \pi t^{2} }}\exp\left( - \frac{\|x\|_{2}^{2}}{2t^{2}} \right).$

## 1D-Diffusion Flow

Die zweite Ableitung beschreibt die Krümmung. Um den nächsten Zeitschritt der Diffusion zu erhalten, ändern wir die Funktion also proportional zur zweiten Ableitung: $$f^{(t+1)}(x_{i})=f^{(t)}(x_{i})+\lambda \cdot \frac{ \partial ^{2} f^{(t)} }{ \partial ^{2}x^{2} } $$
Das nennt man den *expliziten Eulerschritt*
Wir können $\lambda=dt$ interprätieren - je kleiner $\lambda$, desto mehr Zeitschritte brauchen wir, aber desto genauer orientiert sich alles an der Hitze-Analogie.

Um die zweite Ableitung effizient zu berechnen: $$\frac{ \partial ^{2}f^{(t)}(x_{i}) }{ \partial x^{2} } \approx \frac{f^{(t)}(x_{i+1})-2f^{(t)}(x_{i})+f^{(t)}(x_{i-1})}{2}$$

Das ist der *Laplace-Operator*.
Eingesetzt: $$f^{(t+1)}(x_{i})=f^{(t)}(x_{i})+\lambda \cdot  \frac{f^{(t)}(x_{i+1})-2f^{(t)}(x_{i})+f^{(t)}(x_{i-1})}{2}.$$

### Smoothing von Polygonen

Wir nehmen unsere Vertices $v_{i}$ und sagen $f^{(0)}(x_{i})=v_{i}.$ Dann können wir unseren Laplace-Operator von oben direkt anwenden:
$$v_{i}^{(t+1)}=v_{i}^{(t)}+\lambda \cdot \frac{v_{i+1}^{(t)}-2v_{i}^{(t)}+v_{i-1}^{(t)}}{2}.$$
Für $\lambda=1$ ist das neue $v_{i}$ einfach das geometrische Mittel der beiden Nachbarpunkte:
$$v_{i}^{(t+1)}=\frac{v_{i+1}^{(t)}+v_{i-1}^{(t)}}{2}.$$

Als lineare Funktion
$V^{(t)}$ ist der Vektor mit unseren ganzen Punkten zum Zeitpunkt $t$
$$V^{(t+1)}=V^{(t)}+\lambda L V^{(t)}=(I+\lambda L)V^{(t)}$$
Laplace-Operator: nimmt Funktion, gibt Funktion zurück

$L=\frac{1}{2}\begin{pmatrix}-2 & 1 & 0 & \dots & 0 & 1 \\ 1 & -2 & 1 & 0 & \dots & 0 \\ 0 & 1 & -2 & 1 & \ddots & 0 \\ \vdots  & \ddots & \ddots & \ddots & \ddots  & \vdots  \\ 1 & 0 & \dots & 0 & 1 & -2\end{pmatrix}$
$=\frac{1}{2} A-D$, A ist "stiffness matrix", D ist "mass matrix".

> **Explicit Euler Step als Matrix**
> Mit Vertices $V=(v_{1},\dots,v_{n})^{T}$:

Problem: Smoothing hiermit schrumpft das Polygon zu einzelnem Punkt

Laplace-Beltrami: das ganze für 2D
Für Laplace-Beltrami bitte in den nächsten Foliensatz gucken da ist die Formel richtig

Der Laplace-Operator ist die Divergenz der Ableitungsmatrix

$B_{\varepsilon}$ ist der $\varepsilon$-Ball aber nicht der Ball sondern die Hülle
Kontinuierlicher Laplacian:
$$\nabla u(x_{0})=\int_{B_{\varepsilon}} \dots$$


## Implicit Smoothing

Wir wenden den Laplace-Operator nicht am aktuellen sondern am nächsten Zeitpunkt an

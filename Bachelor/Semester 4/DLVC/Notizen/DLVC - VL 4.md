Datum: 08.05.
[[Slides 04.pdf|Folien]]
# Feed-Forward-Netzwerke

![[Neuronale Netze#Neuron]]

![[Neuronale Netze#Multilayer Perceptron]]

![[Neuronale Netze#Layer]]

![[Neuronale Netze#Aktivierungsfunktionen]]

![[Neuronale Netze#Symmetrien und Universal Approximation Theorem]]

# Backpropagation

> Ziel der Backpropagation ist es, den *Gradienten der Fehlerfunktion* bezüglich der *Parameter* (dh. den Gewichtsmatrizen und Bias-Vektoren) des Neuronalen Netzes zu berechnen.

Basiert auf Kettenregel: $$(g \circ f)'(x) = g'(f(x)) \cdot f'(x)$$
oder anders ausgedrückt: $\frac{\partial}{\partial x}g(f(x)) = \frac{\partial g}{\partial f}\frac{\partial f}{\partial x}.$

Die Ableitung einer Funktion $f(x,y)$ ist bekanntermaßen ein Vektor aus den partiellen Ableitungen $\frac{\partial f}{\partial x},\, \frac{\partial f}{\partial y}$.

Werden $x$ und $y$ durch einen Pfad $(x(s), y(s))$ vorgegeben, ist die Ableitung von $f$ nach $s$:
$$\frac{\partial f}{\partial s} = \frac{\partial f}{\partial x}\frac{\partial x}{\partial s}+\frac{\partial f}{\partial y}\frac{\partial y}{\partial s}$$

Allgemein ist die Ableitung einer derart verschachtelten Funktion die Summe aller *Pfade* durch diese Funktion:
![[Ableitung.png]]

Für die Berechnung der Ableitungen gibt es zwei Möglichkeiten der [[Algorithmen#Dynamische Programmierung|dynamischen Programmierung]]:

**Berechnung der Ableitung bzgl. der *Eingabe* durch Forward Accumulation**

- Ziel: Berechnung von $\frac{\partial L}{\partial s}$
- Berechnung: vorne nach hinten
	- Am Beispiel oben:
		- Layer 1: berechne $\frac{\partial x}{\partial s}$, $\frac{\partial y}{\partial s}$, $\frac{\partial z}{\partial s}$
		- Layer 2: $\frac{\partial f}{\partial s}$ = $\frac{\partial f}{\partial x}\frac{\partial x}{\partial s}+\frac{\partial f}{\partial y}\frac{\partial y}{\partial s}+\frac{\partial f}{\partial z}\frac{\partial z}{\partial s}$
		- Layer 3:
			- $\frac{\partial g}{\partial s} = \frac{\partial g}{\partial f}\frac{\partial f}{\partial s}$
			- $\frac{\partial h}{\partial s} = \frac{\partial h}{\partial f}\frac{\partial f}{\partial s}$
		- Layer 4: $\frac{\partial L}{\partial s}=\frac{\partial L}{\partial g}\frac{\partial g}{\partial s}+\frac{\partial L}{\partial h}\frac{\partial h}{\partial s}$.

**Berechnung der Ableitung bzgl. *aller Knoten* durch Backpropagation**

- Ziel: Berechnung aller Gradienten $\frac{\partial L}{\partial g}$, $\frac{\partial L}{\partial h}$, $\frac{\partial L}{\partial f}$, ...
- Anwendung: Ist $L$ die Loss-Funktion und die Knoten sind Netzwerkparameter, können wir hierdurch das Netzwerk trainieren und den Loss verringern.
- Berechnung: hinten nach vorne
	- Letztes Layer: berechne $\frac{\partial L}{\partial g}$, $\frac{\partial L}{\partial h}$
	- Vorletztes Layer: $\frac{\partial L}{\partial f}=\frac{\partial L}{\partial g}\frac{\partial g}{\partial f}+\frac{\partial L}{\partial h}\frac{\partial h}{\partial f}$
	- Layer davor: $\frac{\partial L}{\partial x}=\frac{\partial L}{\partial f}\frac{\partial f}{\partial x}$, usw.

Voraussetzung ist, dass man vorher diesen Berechnungsgraphen generiert hat. Die Erstellung davon heißt *Forward Pass*.

## Ableitung konkret

Die Ableitung für eine Funktion $f: \mathbb{R}^{m} \to \mathbb{R}^{n}$ ist die [[Funktionen#Gradient, Jacobi-Matrix, Hesse-Matrix|Jacobi-Matrix]] $J_{f} \in \mathbb{R}^{n \times m}$.

Die Ableitung einer *verketteten* Funktion $g \circ f: \mathbb{R}^{n} \to \mathbb{R}^{k}$ mit $f: \mathbb{R}^{n} \to \mathbb{R}^{m}$ und $g: \mathbb{R}^{m} \to \mathbb{R}^{k}$ ist die Multiplikation zweier Jacobi-Matrizen: $$\frac{\partial }{\partial x}g(f(x)) = \frac{\partial g}{\partial f}\frac{\partial f}{\partial x} = J_{g}(f(x))J_{f}(x) = J_{g \circ f}(x) \in \mathbb{R}^{k\times n}.$$
Ein neuronales Netz ist eine Verkettung sehr vieler Funktionen, also ergeben sich die Ableitungen als Multiplikation vieler Jacobi-Matrizen.

Ableitung für die Aktivierung eines Layers:
$$a(W,b,x) = Wx+b$$
Dimensionen: $x \in \mathbb{R}^{n}$, $W \in \mathbb{R}^{m\times n}$, $b \in \mathbb{R}^{m}$.

Ableitung nach $x$: $J_{a}(x) = W$
Ableitung nach $b$: $J_{a}(b) = \text{Id}_m$
Ableitung nach $W$: $J_a(W)=\frac{\partial a_{i}}{\partial w_{kl}}=\begin{cases}0 & i\neq k \\ x_{l} & \text{sonst}\end{cases}=\text{Id}_{m}\otimes x$
- 3D-Tensor, denn für das $i$-te Neuron brauchen wir die Ableitung der gesamten 2D-Gewichtsmatrix
- $\otimes$ ist das äußere Produkt
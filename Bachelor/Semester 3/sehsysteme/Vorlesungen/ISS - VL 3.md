Datum: 31.10.
[[ISS03_WS2324_EdgeDetection_231031.pdf|Folien]]

[[ISS_WS2324_Aufgabenblatt03.pdf]]

# Kantenhervorhebung

## Sobel-Operator

Betrachtet man die Intensitätswerte eines Bildes als zweidimensionale Funktion, entsprechen Kanten hohen Absolutwerten in der ersten Ableitung.

Mit einem eindimensionalen Filter kann die Ableitung approximiert werden:
$$\frac{\partial I(x,y)}{\partial x}\approx\begin{pmatrix}-1 & 0 & 1\end{pmatrix} \ast I(x,y)$$
$$\frac{\partial I(x,y)}{\partial y}\approx\begin{pmatrix}-1 & 0 & 1\end{pmatrix}^t \ast I(x,y)$$

Kombiniert man dies mit einem $B^{2}$-Binomialfilter in orthogonaler Richtung, erhält man das **Sobel-Filter**:
$$\begin{align*}
S_x:=\begin{pmatrix}1 \\ 2 \\ 1\end{pmatrix} \cdot \begin{pmatrix}-1 & 0 & +1\end{pmatrix}&=\begin{pmatrix}-1 & 0 & +1 \\ -2 & 0 & +2 \\ -1 & 0 & +1\end{pmatrix}\\
S_{y}:=\begin{pmatrix}+1\\0\\-1\end{pmatrix} \cdot \begin{pmatrix}1 & 2 & 1\end{pmatrix}&=\begin{pmatrix}+1 & +2 & +1\\
0 & 0 & 0\\
-1 & -2 & -1\end{pmatrix}
\end{align*}$$

Der [[Analysis - VL 17#^71f57b|Gradient]] an einer Bildstelle $x,y$ ist also $$\nabla I(x,y) \approx \begin{pmatrix}S_{x}(x,y)\\ S_{y}(x,y)\end{pmatrix}.$$
Entsprechend der Gradientenbetrag: $$S \approx \sqrt{S_{x}(x,y)^{2}+ S_{y}(x,y)^2}$$
und die Gradientenrichtung: $$\Theta \approx \left\{\begin{alignat}{2}
&\arctan\left(\frac{S_{y}(x,y)}{S_{x}(x,y)}\right) &&\text{ für } S_{x}(x,y) \neq 0,\\
&90°&&\text{ für }S_{x}(x,y) = 0, S_{y}(x,y) \neq 0
\end{alignat}\right.$$
Will man die errechneten Gradientenwerte darstellen, sollte man sie vorher per [[ISS - VL 1#Lineare Grauwertspreizung]] oder [[ISS - VL 1#Histogrammlinearisierung]] normieren, damit alle Werte abgebildet werden können.


> [!warning] Konvolution vs. Korrelation
> Durch die Konvolution wird der Offset für den Kernel von der Bildkoordinate *abgezogen*, d.h. der Kernelwert an der Stelle $(-1, -1)$  (oben links) wird mit dem Bildwert an der Stelle $(x+1,y+1)$ (unten rechts) verrechnet - insgesamt ergibt sich also eine Punktspiegelung.
> 
> Weil das verwirrend ist, wird die Konvolution $\ast$ gerne durch die **Korrelation** $\oplus$ ersetzt, bei der der Offset stattdessen draufaddiert wird.


## Laplace-Operator

Idee: Man möchte die Kantenzentren herausfinden, d.h. die Extremstellen der ersten Ableitung bzw. die Nulldurchläufe der zweiten Ableitung.

Mit $\frac{\partial I}{\partial x} \approx - I(x,y) + I(x+1, y)$ erhält man $\frac{\partial^{2}I}{\partial x^{2}}\approx I(x+1, y) - 2 \cdot I(x,y) + I(x-1, y)$, also einen horizontales Filter $$(1,-2,1).$$
Die Kombination aus $\frac{\partial^{2}}{\partial x^{2}}$ und $\frac{\partial^{2}}{\partial y^{2}}$ nennt man **L4-Laplace-Operator:** $$L_{4}=\begin{pmatrix}0 & 1 & 0 \\ 1 & -4 & 1 \\ 0 & 1 & 0\end{pmatrix}\text{ bzw. } \begin{pmatrix}0 & -1 & 0 \\ -1 & 4 & -1 \\ 0 & -1 & 0\end{pmatrix}$$
Mit allen vier partiellen Ableitungen erhält man den **L8-Laplace-Operator:** $$L_{8}=\begin{pmatrix}1 & 1 & 1 \\ 1 & -8 & 1 \\ 1 & 1 & 1\end{pmatrix} \text{ bzw. } \begin{pmatrix}-1 & -1 & -1 \\ -1 & 8 & -1 \\ -1 & -1 & -1\end{pmatrix}.$$

Der Laplace-Operator approximiert also die zweite Ableitung. 
Ein Nulldurchgang liegt vor, wenn der Laplace-Operator in einem der vier (bei $L_4$) bzw. acht (bei $L_8$) Nachbarpixeln ein anderes Vorzeichen berechnet als im zentralen Pixel.

## Laplacian-of-Gaussian-Operator (LoG-Filter)
Der Laplace-Operator ist sehr rauschempfindlich. Daher wendet man ihn erst auf die Gauß-Funktion $$f_{G,\sigma}(x,y) = \frac{1}{\sqrt{2\pi \sigma^{2}}}\cdot e^{-(x^{2}+y^2)/2\sigma^{2}}$$an und erhält das LoG-Filter: $$\begin{align*}
LoG(x,y) &= \nabla^{2}f_{G,\sigma}(x,y)\\
&= \frac{\partial^{2}f_{G,\sigma}}{\partial x^{2}}(x,y)+\frac{\partial^{2}f_{G,\sigma}}{\partial y^{2}}(x,y)\\
&= - \frac{1}{\pi \sigma^{4}}\left(1- \frac{x^{2}+y^{2}}{2 \sigma^{2}}\right)e^{-(x^{2}+y^2)/2\sigma^{2}}
\end{align*}$$
Dieses wird genauso diskretisiert wie das [[ISS - VL 2#Gauß-Filter]]:
- Filtergröße angemessen wählen ($k = 2 \cdot \lceil 3 \sigma\rceil + 1$)
- Durch Normierung sicherstellen, dass die Filterwerte in Summe 0 ergeben

Der LoG-Filter heißt auch *Mexican Hat Filter:*
![[LoG-Filter.png|250]]

Nulldurchgänge können besser bestimmt werden, wenn man das LoG-Filter mit verschiedenen $\sigma$-Werten mehrfach anwendet. Punkte, die bei mehreren Filtern einen Nulldurchgang haben, sind mit höherer Wahrscheinlichkeit eine Kante.

## Difference-of-Gaussian-Filter
Man erhält einen sehr ähnliches Ergebnis, wenn man das Bild mit zwei Gauß-Filtern mit unterschiedlichen Standardabweichungen $\sigma_1$ und $\sigma_{2}\approx 1,6 \cdot \sigma_{1}$ glättet und die Ergebnisse voneinander abzieht.
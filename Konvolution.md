# Konvolution (Faltung)

Im Eindimensionalen (verwendet in [[INF 132 - Grundlagen der Robotik]]):

![[Robotik - VL 11#^4f9ffa]]

![[Robotik - VL 11#^13aa2f]]

Im Zweidimensionalen (verwendet in [[INF 131 - Intelligente Sehsysteme]], [[B57 - Photogrammetrie I]], [[MA-2201 Computer Vision]]):

![[ISS - VL 2#^6f8c9c]]

## Eigenschaften

Es gelten:
- Assoziativität
- Kommutativität
- Distributivität
- [[Lineare Funktionen|Linearität]]
- Verschiebungsinvarianz
	- $\text{filter}(\text{shift}(f)) = \text{shift}(\text{filter}(f))$

*Jeder* lineare, verschiebungsinvariante Operator kann als Konvolution dargestellt werden.

Die [[Robotik - VL 11#Dirac-Impuls|Dirac-Funktion]] ist das neutrale Element der Konvolution.

## Separierbarkeit

Kann ein zweidimensionales Konvolutionsfilter in zwei eindimensionale separiert werden, d.h. $R^{(2)}_{n} =\langle  R^{(1)}_{n} , (R^{(1)}_{n})^{t}\rangle$, (vgl. [[Matrizen#Äußeres Produkt|Äußeres Produkt]]) kann die Konvolution mit einer Funktion $f$ schneller berechnet werden: $$\begin{align*}
\langle  R^{(1)}_{n} , (R^{(1)}_{n})^{t}\rangle &\to \mathcal{O}(2n) = \mathcal{O}(n) \text{ Operationen}\\
R^{(2)}_{n} \ast f &\to \mathcal{O}(n^{2}) \text{ Operationen}
\end{align*}$$
Ein Kernel kann separiert werden, g.d.w. nur der erste Singulärwert der [[Matrizen#SVD|SVD]] ($R_{n}^{(2)} = \sum_{i}\sigma_{i}u_{i}v_{i}^{T}$) des Kernels ungleich 0 ist.
Dann ist der vertikale Kernel: $R_{n}^{(1)}=\sqrt{\sigma_{0}}u_{0}$
und der horizontale Kernel: $(R_{n}^{(1)})^{T}=\sqrt{\sigma_{0}}v_{0}^{T}$


## Konvolutionstheorem

Die Konvolution hat einen engen Bezug zur [[Fourier-Transformation]] und [[Laplace-Transformation]]:
![[Robotik - VL 11#^463ea0]]


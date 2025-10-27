# Gauß-Funktion

Die Gaußsche Normalverteilung mit Standardabweichung $\sigma$ ist:

$$G_{\sigma}(x)=\frac{1}{\sqrt{2\pi}\sigma} e^{\Large- \frac{x^{2}}{2\sigma^{2}}}$$
Im zweidimensionalen Fall:

$$\begin{align}G_{\sigma}(x,y)&=\frac{1}{2\pi\sigma^{2}} e^{\Large- \frac{x^{2} + y^{2}}{2\sigma^{2}}}\\
&= \left(\frac{1}{\sqrt{2\pi}\sigma} e^{\Large- \frac{x^{2}}{2\sigma^{2}}}\right) \cdot \left(\frac{1}{\sqrt{2\pi}\sigma} e^{\Large- \frac{y^{2}}{2\sigma^{2}}}\right)\end{align}$$

^3f72da

## Konvolution

- Zur Glättung eines Bildes nimmt man einen [[Konvolution|Konvolutionskernel]] mit Halb-Breite ca. 3 $\sigma$. ^c660fd
- [[Konvolution#Separierbarkeit|Separierung]] eines 2D-Filters in zwei 1D-Filter mit demselben $\sigma$ ^cfe2d2
	- Für $n\times n$ Bild und Kernel der Größe $m$:
		- $\mathcal{O}(n^{2}m^{2})$ für nicht-separierten Kernel
		- $\mathcal{O}(n^{2}m)$ für separierten Kernel
- Zweimal mit $\sigma$ glätten ist dasselbe wie einmal mit $\sqrt{2}\sigma$ glätten ^53b147
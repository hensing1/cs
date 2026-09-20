[[vda-12-Image-Based-Flow-Vis.pdf]]

Wir möchten ein [[Vektoren#Vektorfeld|Vektorfeld]] visualisieren mit Bild

## Line Integral Convolution

- Starten mit random Textur (schwarz/weiß)
- wir verschmieren jeden Pixel entlang der stream lines

Verschmieren geht so:
mache ein 1D Blurring (z.B. Gauss-Kernel), aber entlang der Stream Line $\varphi_{0}$ mit $\varphi_{0}(0)=(x_{0},y_{0})$. Die Bildintensität an diesem Punkt ist dann $$I(x_{0},y_{0})=\int_{-L}^{L}k(-t) \cdot T(\varphi_{0}(t))\,dt$$
mit $k$ dem Kernel mit Support $2L$, und $T$ der Textur.

Je größer $L$, desto länger die Linien und desto schlechter der Kontrast.
Kontrast kann aber noch nachträglich verbessert werden.

*Verbesserungen*
- Schneller machen: Stream Lines so lang wie möglich machen, neue Lines nur an Punkten die noch nicht verarbeitet wurden
- Color Coding: weitere Skalarfelder überlagernd darstellen, z.B. Partikelgeschwindigkeit
- Color Weaving: Farben werden kontinuierlich entlang Stream Lines verschmiert - Farben aus verschiedenen Bereichen werden dann auch bei Überlappungen erhalten
- Oriented LIC: Orientierung des Vektorfelds durch asymmetrischen Konvolutionskernel erhalten
- Adaptive Kernel Length: Länge des Konvolutionsintegrals hängt von Magnitude des Vektorfelds ab

## 3D LIC

Erweiterung auf 3D mathematisch trivial, aber schwerer zu rendern -> müssen Teile des Vektorfelds verbergen

- Ray Casting
	- Transfer Function verteilt Opazität z.B. nach Curl
- Slice based Volume Rendering
	- Interaktivität mit Clipping Plane, die verschoben werden kann
- Sparse Noise
- LIC auf Oberflächen von 3D-Modellen anwenden
	- kann auch erst Vektorfeld auf Oberfläche projizieren und dann 2D-LIC anwenden
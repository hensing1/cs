[[atcg1-08-Filtering.pdf]]

- Path Tracing generiert Rauschen
- statt immer Pixelzentrum Strahl generieren, bisschen jittern dann besser
- wir samplen ein Signal, das wir rekonstruieren möchten
	- lineare Interpolation führt zu reconstruction error
	- unzureichendes Sampling führt zu Aliasing
- Fourier-Transformation
- Konvolution
- Konvolutionstheorem
- Nyquist-Samplingtheorem

## Anti-Aliasing-Ansätze

- mehr samplen, lol
	- supersampling, dann Durchschnitt berechnen
- *Prefiltering:* Signal vor dem Samplen band-limiten (blurren, zu hohe Frequenzen rauswerfen)

Supersampling-Strategien:
- regulär
- jittered (besser)
	- *converts aliases into broadband noise*
	- $\sum_{i=-\infty}^{\infty}\delta(x-(i + \xi)T)$

White noise: enthält Rauschen in *allen* Frequenzen -> wenn geblurrt: rauschen immer noch da (von den niedrigeren Frequenzen)
Blue noise: Rauschen nur in hohen Frequenzen
- für generieren: sicherstellen, dass Distanzen zwischen Sample-Punkten einigermaßen regulär bleibt
- Blue Noise Generation ist eine Wissenschaft für sich

Bei jittering wird eben hochfrequentes Rauschen erzeugt, was gut mit blurring unterdrückt werden kann

Problem beim Rendering: wir haben eine rauschfreie Textur, aber die gesampelte Beleuchtung ist wegen Monte Carlo stark verrauscht.
Würden wir die Texturfarben direkt mit der Beleuchtung zusammenmultiplizieren, verlieren wir hochfrequente Details der Textur

> **G-Buffer**
> Stores geometric or material attribute of the *closest visible surface point* for every pixel

Bilateraler Filter für edge-preserving reconstruction
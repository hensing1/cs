[[atcg1-08-Filtering.pdf]]

- Path Tracing generiert Rauschen
- statt immer Pixelzentrum Strahl generieren, bisschen jittern dann besser
- wir samplen ein Signal, das wir rekonstruieren möchten
	- lineare Interpolation führt zu reconstruction error
	- unzureichendes Sampling führt zu Aliasing
- Fourier-Transformation
- Konvolution
- Konvolutionstheorem
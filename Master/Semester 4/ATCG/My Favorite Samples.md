[Video](https://www.youtube.com/watch?v=bHDfETTS550)

## Alex Keller, NVIDIA

Samples, um Integral zu berechnen

*Stratified Sampling*
- vermeiden, dass komplette Regionen ausgelassen werden
- keine Garantie, dass Punkte nicht sehr nah beieinander landen
- curse of dimensionality, Anzahl der benötigten Strata wächst exponentiell mit den Dimensionen

Quasi-Monte Carlo: Punkte sind nicht mehr unabhängig voneinander
progressive Stratification

unbiased := Erwartungswert entspricht mathematischem Objekt, das modelliert werden soll (reicht aber nicht, um Konvergenz zu garantieren)

Bias nicht so schlimm wenn man Fehler kontrollieren kann


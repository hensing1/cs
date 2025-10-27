## Grundlagen


![[CV 3 - Pyramids#Grundlagen Fourier und Frequenzraum]]


## Eigenschaften

| Eigenschaft         | Signal                                    | Frequenzraum                                                   |
| ------------------- | ----------------------------------------- | -------------------------------------------------------------- |
| Linearität          | $\alpha f + \beta g$                      | $\alpha\hat{f}+\beta \hat{g}$                                  |
| Konvolutionstheorem | $(f \otimes g)(x)$                        | $(\hat{f}\cdot \hat{g})(\nu)$                                  |
| Skalierung          | $f(\alpha x)$                             | $\frac{1}{\|\alpha\|}\hat{f}\left( \frac{\nu}{\alpha} \right)$ |
| Separabilität       | $f(x,y)$                                  | $\mathcal{F}_{y}(\mathcal{F}_{x}(f))$                          |
| Ableitung           | $\frac{\partial^{n}}{\partial x^{n}}f(x)$ | $(2\pi i \nu)^{n}\hat{f}(\nu)$                                 |

Das Frequenzbild eines *reellwertigen Signals* ist *symmetrisch* im Ursprung.

## Fourierpaare

Die Funktionspaare gelten in beide Richtungen.

| Name                                              |                                         |                                                                            |
| ------------------------------------------------- | --------------------------------------- | -------------------------------------------------------------------------- |
| Konstantes signal $\iff$ Dirac-Puls               | $1$                                     | $\delta(\nu)$                                                              |
| Schah-Funktion (Periode $T$) $\iff$ Periode $1/T$ | $\sum_{n=-\infty}^{\infty}\delta(x-nT)$ | $\frac{1}{T}\sum_{k=-\infty}^{\infty}\delta\left( \nu-\frac{k}{T} \right)$ |
| Box $\iff$ Sinc                                   | $\mathrm{rect}(x)$                      | $\frac{\sin(\nu)}{\nu}$                                                    |
| Gauss $\iff$ invers skalierter Gauss              | $e^{-\alpha x^{2}}$                     | $\sqrt{ \frac{\pi}{\alpha} }e^{-(\pi \nu)^{2}/\alpha}$                     |
## Nyquist-Theorem

> Die Abtastrate eines kontinuierlichen Signals muss mindestens doppelt so hoch sein wie die höchste Frequenz des Signals, um alle Frequenzen zu behalten.

Wird unser Signal mit Periode $T$ abgetastet, wird es *punktweise* mit einer Schah-Funktion multipliziert.
Nach Konvolutionstheorem haben wir also eine Konvolution im Frequenzraum, und zwar mit einer Schah-Funktion der Periode $\frac{1}{T}$:

![[Nyquist.png|400]]

Überlappen die Kopien der Frequenzbilder der Funktion, kann nicht mehr rekonstruiert werden, ob ein bestimmter Wert durch eine hohe oder eine niedrige Fequenz der Funktion verursacht wurde.
Diesen Effekt nennt man **Aliasing**.
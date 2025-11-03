## Grundlagen


![[CV 3 - Pyramids#Grundlagen Fourier und Frequenzraum]]

***3D-Fourier:***
Analog zum 2D, man nimmt zur Einfachheit Vektoren ($r \in \mathbb{R}^{3}$ für Bild-Domäne, $s \in \mathbb{R}^{3}$ für Zeit-Domäne).
Vorwärts:$$F(s) = \iiint_{-\infty}^{\infty}f(r)e^{-2\pi i(r \cdot s)}\,dr$$
Rückwärts:$$f(r) = \iiint_{-\infty}^{\infty}F(s)e^{2\pi i(r \cdot s)}\,ds$$ ^c06726

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
## Konvolutionstheorem

Eine Konvolution von Signalen (time domain) entspricht einer punktweisen Multiplikation im Frequenzraum, und anderherum:
![[ISS - VL 7#^616f5d]]

## Nyquist-Theorem

> Die Abtastrate eines kontinuierlichen Signals muss mindestens doppelt so hoch sein wie die höchste Frequenz des Signals, um alle Frequenzen zu behalten.

Wird unser Signal mit Periode $T$ abgetastet, wird es *punktweise* mit einer Schah-Funktion multipliziert.
Nach Konvolutionstheorem haben wir also eine Konvolution im Frequenzraum, und zwar mit einer Schah-Funktion der Periode $\frac{1}{T}$:

![[Nyquist.png|400]]

Überlappen die Kopien der Frequenzbilder der Funktion, kann nicht mehr rekonstruiert werden, ob ein bestimmter Wert durch eine hohe oder eine niedrige Fequenz der Funktion verursacht wurde.
Diesen Effekt nennt man **Aliasing**.

> Ein kontinuierliches Signal oberhalb der Nyquist-Frequenz sieht abgetastet genauso aus wie ein Signal, das rückwärts läuft:
> - ein diskretes Signal der Länge $N$ hat $N$ mögliche Frequenzen
> - jede Frequenz $N-k$ mit $k < \frac{N}{2}$ sieht aus wie die Frequenz $-k$
> - alles oberhalb Frequenz $\frac{N}{2}$ wäre im Bild oben bereits Teil von der nächsten Kopie des Signals (bzw. würde von links wieder mit den negativen Frequenzen überlappen)
>   
>   ![[aliasing2.png]]


## Gibbs-Ringing

- Das Fourier-Paar der Box-Funktion ist die Sinc-Funktion
- Wenn man nur begrenzt Frequenzen messen kann (oder sie irgendwo abschneidet), ist das so, als würde man im Frequenzraum punktweise mit der Box-Funktion multiplizieren
- Per [[Fourier-Transformation#Konvolutionstheorem|Konvolutionstheorem]] entspricht dies der Konvolution mit einer Sinc-Funktion in der Signaldomäne
- Das wiederum erzeugt Ringe an scharfen Kanten:

![[Gibbs.png]]

Andersherum: eine scharfe Kante im Bild lokal eine Box-Funktion, also eine Sinc-Funktion in der Frequenzdomäne. Die Sinc-Funktion hat unendlichen Support, man bräuchte also unendlich Frequenzen.

Lösung: drübergaußen (glättet die Kanten), das Fourierpaar einer Gauß-Kurve ist ebenfalls eine Gauß-Kurve. Man löscht die hohen Frequenzen also graduell, anstatt mit einem harten Cut-off.
![[gauss statt gibbs.png]]


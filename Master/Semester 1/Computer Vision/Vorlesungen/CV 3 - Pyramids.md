[[03pyramids_WS2425_slides.pdf]]

# Pyramids

## Grundlagen: Fourier und Frequenzraum

Jedes Signal kann als Summe von Sinüssen geschrieben werden. Pro Sinus hat man die Parameter:
$$
A \sin(\omega x + \phi)
$$
- $A$: Amplitude
- $\omega$: Frequenz
- $\phi$: Phase

> **Fourier-Transformation** eines Signals $f$:
> $$F(\omega)=\int_{x=-\infty}^{\infty}f(x)e^{-2\pi j \omega x}\,dx \in \mathbb{C}$$

Für eine Frequenz $\omega$ erhält man eine komplexe Zahl $c=a+jb$, welche die Parameter des zugehörigen Sinus wie folgt kodiert:
- Amplitude: $A=\pm \sqrt{ R(c)^2 + I(c)^2 } = |c|$
- Phase: $\phi=\tan^{-1} \frac{I(c)}{R(c)}$

Im zweidimensionalen hat die Frequenz eine Richtung (zwei Komponenten $u,v$): 
$$
F(u,v)=\int_{x=-\infty}^{\infty}\int_{y=-\infty}^{\infty}f(x,y)e^{-2\pi j (ux+vy)}\,dxdy \in \mathbb{C}
$$
Umkehrfunktion:
$$
f(x,y)=\int_{u=-\infty}^{\infty}\int_{v=-\infty}^{\infty}F(u,v)e^{+2\pi j (ux+vy)}\,dudv \in \mathbb{R}
$$

Interprätation: Amplitude kodiert Vorhandensein einer Frequenz, Phase kodiert Ortsinformation (indirekt):
![[Fourierzebra.png]]


> **Konvolutionstheorem**
> Eine *Konvolution* im Ortsraum entspricht einer *Multiplikation* von Kernel und Bild im Frequenzraum: $$F[g \ast h] = F[g] F[h]$$

![[FFT.png]]

Das ist praktisch z.B. für Convolutional Neural Nets mit großen Kerneln, weil pixelweise Multiplikation wesentlich schneller geht als Konvolution.

## Subsampling (Gaußpyramide)

Wenn wir ein Foto runterskalieren möchten, könnten wir z.B. jede zweite Reihe und Spalte wegwerfen.
Damit tasten wir das Bild quasi ab, jedoch liegen dann die Bildfrequenzen oberhalb der Nyquist-Frequenz (halbe Abtastrate), und es kommt zu *Aliasing*.

Wir müssen also die hohen Frequenzen erst loswerden - das machen wir mit einem Gauß-Filter.

## Template Matching

Wir haben ein Template $g$ und ein Bild $f$, und wir möchten das Template im Bild wiederfinden (bei Koordinaten $(m,n)$.

*Ansatz mit SSD* (Sum Squared Difference):
$$
h[m,n] = \sum_{k,l}(g[k,l]-f[m+k,n+l])^2
$$
Problem: keine guten Matches wenn das Bild eine andere Helligkeit hat als die Template

*Ansatz mit normalisierter Kreuzkorrelation:*
$$
h[m,n]=\frac{\sum_{k,l}(g[k,l]-\bar{g})(f[m+k,n+l]-\bar{f}_{m,n})}{\left( \sum_{k,l}(g[k,l]-\bar{g})^2 \sum_{k,l}(f[m+k,n+l]-\bar{f}_{m,n})^2 \right)^{0.5}}
$$

- $\bar{g}$ ist Mittelwert des Templates
- $\bar{f}$ ist Mittelwert des Bild-Patches

### Schneller

Mache Templatesuche erst auf einem hohen Level der Gaußpyramide (Suchraum wesentlich kleiner). Führe die Suche dann nur in einem kleinem Bereich um das Match auf einem niedrigeren Pyramiden-Level durch.

## Laplace-Pyramide

Speichere neben kleinstem Gaußpyramiden-Bild nur die Kanteninformationen, die pro Pyramidenlevel dazukommen (Differenz zwischen Gauß-Level und hochskaliertem Gaußlevel darüber).

Anwendung: *Blending* zwischen zwei Bildern $A,B$.
- Wir haben eine Maske $M$, die pro Pixel angibt, aus welchem Bild der Wert übernommen werden soll (0 oder 1)
- Wir generieren Laplacepyramiden $LA,LB$ von beiden Bildern
- Wir generieren Gaußpyramide $GM$ der Maske
- Forme gemeinsame Laplacepyramide $L$: auf jedem Level $l$ ist ein Pixel $L_{l}(i,j)=GM_{l}(i,j) \cdot LA_{l}(i,j) + (1-GM_{l}(i,j)) \cdot LB_{l}(i,j)$.
- Durch abwechselnd hochskalieren/aufaddieren lässt sich aus der Laplacepyramide das Bild in Originalgröße wiederherstellen.

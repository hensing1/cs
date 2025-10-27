Datum: 11.10.
[[02filtering_WS2425_slides.pdf]]

# Filter

## Was sind Bilder?

- Bilder sind Funktionen - $f: \Omega \to \mathbb{R}$ bzw. $f: \Omega \to \mathbb{R}^{3}$
- **Farbrepräsentationen:**
	- RGB
	- Normalisiertes RGB ($\frac{r}{r+g+b}$ speichern)
	- Farben von Intensität trennen:
		- Lab
		- HSV

## Pixeltransformationen
Unseren Bildoperator nennen wir $h$: $h(f(x))$, $x = (i,j)$
- Lineare Interpolation: $g(x) = (1-\alpha)f_{0}(x) + \alpha f_{1}(x)$
- [[ISS - VL 1#Gamma-Korrektur|Gammakorrektur]]: bei uns $f(x)^\frac{1}{\gamma}$ (wenn Bildwerte in $[0,1]$ liegen)
	- Auf Wikipedia eigentlich $f(x)^\gamma$
	- Umwandlung von linearen Sensordaten für nichtlineare menschliche Wahrnehmung
- [[ISS - VL 1#Histogrammlinearisierung|Histogrammlinearisierung]]
	- Histogramm: $p_{f}(y) = \frac{|\set{x\in \Omega: f(x)=y}|}{|\Omega|}$
	- Kumulatives Histogramm: $F_{f}=\sum_{y'=0}^{y}p_{f}(y')$
	- Linearisierung: $$h(f(x))=F(f(x)) \cdot 255$$
		- Effekt (im Kontinuierlichen): $p_{h_{f}}=\frac{1}{255}$

## Lineare Filterung

### [[Konvolution]]
- Eigenschaften:
	- Linearität: $k \ast (f_{1}+f_{2}) = k \ast f_{1} + k \ast f_{2}$
	- Shiftinvarianz: $k \ast \text{shift}(f) = \text{shift}(k \ast f)$
	- *Jede* lineare, shift-invariante Funktion kann als Funktion dargestellt werden. 
		- Beweis: fange an mit $f(i,j) = \sum_{p=-\infty}^{\infty}\sum_{q=-\infty}^{\infty}f(p,q) \delta(i-p, j-q)$, dann zeige $(T \circ f)(i,j) = (f \ast (T \circ \delta))(i,j)$
- [[Photo I - VL 5#^9b86d7|Integralbild]]
- Box-Filter
- *Verschärfungsfilter:* $\begin{pmatrix}0 & 0 & 0 \\ 0 & 2 & 0 \\ 0 & 0 & 0\end{pmatrix} - \frac{1}{9} \begin{pmatrix}1 & 1 & 1 \\ 1 & 1 & 1 \\ 1 & 1 & 1\end{pmatrix}$
	- 2 * Original - Verwischung = Original + Kanten
- Eine Rotation ist *nicht* mit einer Konvolution darstellbar, da sie nicht translationsinvariant ist.

#### Gauß-Filter

Der Gauß-Filter ist die bessere Alternative zum Boxfilter.

![[Gauss-Funktion#^3f72da]]

![[Gauss-Funktion#^c660fd]]
![[Gauss-Funktion#^cfe2d2]]
![[Gauss-Funktion#^53b147]]

#### Separierbarkeit

**Wann ist ein Konvolutionskernel separierbar?**
*-> wenn bei der [[Matrizen#SVD|Singulärwertzerlegung]] der Kernel-Matrix **nur** der erste Singulärwert $\sigma_{0}$ nicht-null ist.*

Leicht zu sehen:
- $K=\sum_{i}\sigma_{i}u_{i}v_{i}^{T}$ (Singulärwertzerlegung)
- Wenn nur $\sigma_{0} \neq 0$: Vertikaler Kernel ist $\sqrt{ \sigma_{0} }u_{0}$, horizontaler Kernel ist $\sqrt{ \sigma_{0} }v_{0}^{T}$
- Wenn nicht, ist $\sigma_{0}u_{0}v_{0}^{T}$ nur eine Approximierung

## Nichtlineare Filterung

- Gegen Impulsrauschen: Medianfilter statt Gaußfilter

### Bilaterales Filter
*Kantenerhaltene Rauschfilterung*

Zwei Komponenten:
- ein normales Gaußfilter: $\exp\left( -\frac{(i-k)^2 + (j-l)^2}{2\sigma^{2}_{d}} \right)$ ($k,l$ sind Pixel-Offsets, $\sigma_{d}$ ist Parameter für Gaussian), genannt *Domain Kernel*
- ein *Range Kernel*, abhängig von Pixelwerten (daher nicht Shiftinvariant): $\exp\left( -\frac{\|f(i,j)-f(k,l)\|^2}{2 \sigma_{r}^{2}} \right)$
	- Dieser Kernel ist nahe 1, wenn $f(i,j)$ und $f(k,l)$ ähnlich sind, und nahe 0, wenn sie verschieden sind

Diese beiden Kernel werden miteinander multipliziert:
$$
\exp\left( -\frac{(i-k)^2 + (j-l)^2}{2\sigma^{2}_{d}} -\frac{\|f(i,j)-f(k,l)\|^2}{2 \sigma_{r}^{2}} \right)
$$
Das Ergebnis ist ein Gaußfilter, das nahe einer Kante aber *abgeschnitten* für alle Pixel jenseits der Kante ist.
Diese Methode ist langsam, aber es existieren Annäherungen.

### Binärbilder

*Erosion:* ändere einen Pixel von Vorder- zu Hintergrund, wenn in seiner 4-Nachbarschaft ein Hintergrundpixel ist.

*Dilation:* ändere einen Pixel von Hinter- zu Vordergrund, wenn in seiner 4-Nachbarschaft ein Vordergrundpixel ist.

**Öffnen:** Erosion -> Dilation, entfernt kleine Vordergrund-Inseln

**Schließen:** Dilation -> Erosion, entfernt kleine Löcher
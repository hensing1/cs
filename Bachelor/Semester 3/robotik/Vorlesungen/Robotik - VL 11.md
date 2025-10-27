Datum: 21.12.
[[Robotik_11_Konvolution_Frequenzraum.pdf|Folien]]

Übung: [[Uebung_10.pdf]]

# Konvolution und Frequenzraum

Wir erinnern uns: [[Robotik - VL 7#^534ff5|lineare zeitinvariante Systeme]] erlauben es, das Systemverhalten auf komplizierte Eingaben in eine Linearkombination aus simplen Eingaben zu dekomponieren.

## Zerlegung zeitdiskreter Systeme

### Dirac-Impuls

Die Funktion 
$$\delta: \mathbb{Z} \to \set{0,1}$$
$$\delta(n) = \left\{
\begin{align*}
1 &\text{ für } n=0\\
0 &\text{ für } n\neq 0
\end{align*}
\right.$$

heißt *zeitdiskreter Dirac-Impuls* oder *$\delta$-Impuls*.

### Impulsantwort

Die Ausgabe $h(n)$ eines Systems bei Eingabe eines Dirac-Impulses $\delta(n)$ heißt *Impulsantwort:* $$h(n) = \mathcal{T}\set{\delta(n)}.$$
> Die Impulsantwort eines LTI-Systems beschreibt die Systemantwort *vollständig.*

Dasselbe gilt für die *Sprungantwort* auf die Sprungfunktion $s(n) = \left\{\begin{align*}1 \text{ falls } n \geq 0 \\0 \text{ falls } n < 0\\\end{align*}\right.$ .
Die $\delta$-Funktion ist die Ableitung der Sprungfunktion.
Die Impulsantwort ist die Ableitung der Sprungantwort.
### Zerlegung

Eine beliebige (Eingabe-)[[Folgen#^731648|Folge]] $u(n)$ kann nun zerlegt werden wie folgt: $$u(n)=\sum_{\nu=-\infty}^{\infty} u(\nu)\delta(n-\nu).$$

Entsprechend gilt für die Systemantwort eines LTI-Systems:
$$\begin{align*}
y(n) &= T \left\{ \sum_{\nu=-\infty}^{\infty}u(\nu)\delta(n-\nu)\right\}\\
&= \sum_{\nu=-\infty}^{\infty}u(\nu)T \set{\delta(n-\nu)}.
\end{align*}$$
## Konvolution

### Konvolution zeitdiskreter Systeme

Wir beschreiben die (verschobene) Impulsantwort als eigenes LTI-System: $$T \set{\delta(n-\nu)}=h(n-\nu)$$
Aus $y(n) = \sum_{\nu=-\infty}^{\infty}u(\nu)T \set{\delta(n-\nu)}$ (s.o.) definiert sich damit die

> ***Konvolution*** zweier zeitdiskreter LTI-Systeme $u$ und $h$:
> $$y(n) = u(n) \ast h(n) := \sum_{\nu=-\infty}^{\infty}u(\nu)h(n-\nu)$$

^4f9ffa

Praktisch: $u$ kann ein beliebiges Eingabesignal sein, und $h$ die Impulsantwort. Dann beschreibt $u \ast h$ das gesamte Systemverhalten.

**Die Konvolution $h_1(n) \ast h_2(n)$ ist die *sequenzielle* Komposition zweier Systeme $h_1$ und $h_2$:**
![[Pasted image 20240101190140.png]]

### Konvolution zeitkontinuierlicher Systeme

Wir vergewaltigen die Mathematik und sagen:
$$\delta(t)=\lim\limits_{\epsilon \to 0}\left\{
\begin{align*} \frac{1}{\epsilon}&\text{ für }|t|\leq \frac{\epsilon}{2}\\
0 &\text{ sonst}
\end{align*}\right.$$
$$=\left\{\begin{align*}
\infty &\text{ für }t=0\\
0& \text{ sonst}
\end{align*}\right.$$
mit $$\int_{-\infty}^{\infty}\delta(t)dt=1$$
und $$\frac{d}{dt}s(t)=\delta(t).$$

Mit derselben Logik wie oben ist die
> ***Konvolution*** zweier zeitkontinuierlicher LTI-Systeme $u$ und $h$: $$y(t)=u(t)\ast h(t) :=\int_{-\infty}^{\infty}u(\tau)h(t-\tau)\,d \tau$$

^13aa2f


### Eigenschaften der Konvolution

Es gelten *Kommutativität*, *Assoziativität* und *Distributivität*.

## Fourier-Transformationen

> [!note] Satz
> Sei $\mathcal{T}$ ein LTI-System und $u(t)=\hat u e^{i \omega t}$ eine *sinusoide Eingabe* mit Frequenz $\omega$. 
> Dann ist $u$ eine *Eigenfunktion* von $\mathcal{T}$, d.h. die Ausgabe des Systems $$y(t) = \mathcal{T}\set{u(t)}=H \hat u e^{i \omega t}$$ist ebenfalls sinusoid, ebenfalls mit Frequenz $\omega$ und die Amplitude ist skaliert mit $H \in \mathbb{C}$. 

Es beschreibt $|H|$ die Amplitudenverstärkung und der Winkel $\arg(H)$ die Phasenverschiebung des Signals durch $\mathcal{T}$.

> **Beschreibung der Nichtlinearität eines Systems**
> Ist ein System nichtlinear, enthält die Ausgabe neben der skalierten Eingangsfrequenz auch ganzzahlige Vielfache der Eingangsfrequenz $u_1$ (Oberwellen): $u_{n}=n \cdot u_1$
> 
> Das Verhältnis der Oberwellen zum Gesamtsignal heißt *Klirrfaktor*: $$k = \frac{\bar U_\text{Harmonics}}{\bar U_\text{Entire Signal}}=\frac{\sqrt{u_{2}^{2}+u_{3}^{2}+\ldots}}{\sqrt{u_{1}^{2}+u_{2}^{2}+u_{3}^{2}+\ldots}}.$$

### Transferfunktion

Der Skalar $H$ ist abhängig von der Frequenz $\omega$ (bzw. $i \omega$, da es um die komplexe Exponentialfunktion geht, und geschrieben $j \omega$, weil Elektrotechniker).

Der Skalar in Abhängigkeit der Frequenz ist $H(j \omega)$ und heißt *Transferfunktion*.

Sei $h(t)$ die Impulsantwort. Dann ergibt sich die Transferfunktion als: $$H(j \omega)=\int_{-\infty}^{\infty}h(\tau)e^{-j \omega \tau}\,d \tau.$$
Das Ding heißt *Fourier-Integral*. [3Blue1Brown](https://www.youtube.com/watch?v=spUNpyF58BY) hat eine sehr gute intuitive Erklärung, warum es so aussieht wie es aussieht. ^5b1115

Rücktransformation: $$h(t) = \frac{1}{2\pi}\int_{-\infty}^{\infty}H(j \omega)e^{j \omega t}\,d\omega$$

### Eigenschaften der Fourier-Transformation

Für $f(t) \stackrel{\text{FT}}{\longrightarrow} F(j \omega)$ gilt:
- Ableitung:
	- $f'(t)\stackrel{\text{FT}}{\longrightarrow}j \omega F(j \omega)$
- Linearität:
	- $k_{1}f_{1}(t) + k_{2}f_{2}(t) \stackrel{\text{FT}}{\longrightarrow} k_{1}F_{1}(j \omega) + k_{2}F_{2}(j \omega)$
- Zeitliche Skalierung:
	- $f(at) \stackrel{\text{FT}}{\longrightarrow} \frac{1}{|a|}F(j \frac{\omega}{a}), a \in \mathbb{R}$
- Zeitliche Verschiebung:
	- $f(t - t_{0}) \stackrel{\text{FT}}{\longrightarrow} e^{-j \omega t_{0}}F(j \omega)$
	- zeitliche Verschiebung ändert nicht den Betrag der Transformation, verursacht jedoch eine frequenzabhängige Phasenverschiebung

### Konvolutionstheorem

> Eine Mulitplikation im Frequenzraum entspricht einer Konvolution im zeitlichen Raum:
> $$y(t) = u(t) \ast h(t) \stackrel{\text{FT}}{\longrightarrow} Y(j \omega) = U(j \omega) H(j \omega)$$

^463ea0

Faltung für zeitdiskrete Systeme: $\mathcal{O}(n^2)$
Mit Fourier-Transformationen: $\mathcal{O}(n \cdot \log(n))$


## Laplace-Transformation

Wir haben ein Problem: das [[Robotik - VL 11#^5b1115|Fourier-Integral]] existiert nicht immer. 
Es existiert nur dann, wenn $\int_{-\infty}^{\infty}|f(t)|\,dt$ existiert.

Die Lösung ist die Laplace-Transformation: $$\begin{align*}
F(\sigma+j \omega) &= \int_{0}^{\infty}f(t)e^{-(\sigma+j\omega)t}\,dt\\
&= \int_{0}^{\infty}f(t)e^{-\sigma t}e^{-j \omega t}\, dt\\
&= \text{FT}(f(t) \cdot e^{-\sigma t}).
\end{align*}$$

Die Funktion $f$ wird also über den Parameter $\sigma$ mit einem exponentiell abfallenden Gewicht versehen, sodass die Konvergenz sichergestellt wird.

Für $\sigma=0$ erhält man die gewöhnliche Fourier-Transformation.
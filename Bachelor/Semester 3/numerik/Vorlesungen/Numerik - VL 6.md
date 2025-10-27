Datum: 17.11.
[[Skript_2023_01_26.pdf|Skript]] S. 65 bis 78

# Kondition und Stabilität
*Kapitel 5*

## Kondition

> [!abstract] Definition *Relativer und Absoluter Fehler*
> Sei $f: \mathbb{R}\to \mathbb{R}$ eine Funktion und $\tilde{f}$ ein Algorithmus zur Berechnung von $f$.
> 
> Dann heißt:
> $$\|\tilde{f}(x) - f(x)\| \text{ \textit{absoluter Fehler} und}$$
> $$\frac{\|\tilde{f}(x) -f(x)\|}{\|f(x)\|} \text{ \textit{relativer Fehler}.}$$

Der Rechner wertet wegen *Daten-* oder *Rundungsfehlern* die Funktion nicht unbedingt an der Stelle $x$, sondern $\tilde{x}=x + \Delta x$.

Dann heißt $$\Delta y = f(x + \Delta x) - f(x)$$der *fortgepflanzte absolute Fehler*.

Ist $f$ [[Analysis - VL 9#^ca29df|stetig]], dann gilt nach [[Analysis - VL 15#Mittelwertsatz|Mittelwertsatz]]: $$\exists \xi \in [x, x + \Delta x]: \Delta y = f'(\xi)\Delta x.$$
Ist $f$ Lipschitz-stetig,[^1] dann gilt sogar: $$\Delta y = f'(x) \Delta x + \mathcal{O}(|\Delta x|^2).$$

[^1]: $\exists L \in \mathbb{R}: |f(x_{1})-f(x_{2})|\leq L \cdot |x_{1}-x_{2}|$

Der quadratische Term kann dabei vernachlässigt werden.

> [!abstract] Definition *Konditionszahl*
> Die Zahl $$K_\text{abs}=|f'(x)|$$heißt *absolute Konditionszahl* des Problems $x \mapsto f(x).$
> Für $x \cdot f(x) \neq 0$ ist die Zahl $$K_\text{rel}=\left|\frac{f'(x)\cdot x}{f(x)}\right|$$ die *relative Konditionszahl* des Problems.

Also ist $$|\Delta y|\approx K_\text{abs}\cdot |\Delta x|$$

und $$\left|\frac{\Delta y}{y}\right|\approx K_{\text{rel}}\cdot \left| \frac{\Delta x}{x}\right|$$
(wegen [^2] ).

[^2]: $\frac{f'(x)}{f(x)}\Delta x = f'(x) \cdot \frac{x}{f(x)} \frac{\Delta x}{x} \approx \frac{\Delta y}{y}.$


> **Gut und schlecht konditionierte Probleme**
> Ein Problem heißt *schlecht konditioniert*, falls eine der beiden Zahlen "deutlich größer als 1" ist.

### Kondition einer Matrix

Wir betrachten ein LGS der Form $Az=b$ mit:
- Lösung $z = A^{-1}b$ und
- berechneter Lösung $z + \Delta z=A^{-1}(b + \Delta b) = A^{-1}b + A^{-1}\Delta b$.

Dann ist: $$\begin{align*}
\frac{\|\Delta z \|}{\|z\|} &= \frac{\|A^{-1}\Delta b\|}{\|z\|}\\
	&\leq \|A^{-1}\|_{M}\frac{\|\Delta b\|}{\|b\|}\frac{\|Az\|}{\|z\|} & \text{(wegen Dreiecksungleichung)}\\
	&\leq \|A^{-1}\|_{M}\|A\|_{M}\frac{\|\Delta b\|}{\|b\|}
\end{align*}$$
sofern die Matrixnorm $\|\cdot\|_{M}$ mit der Vektornorm $\|\cdot\|$ verträglich ist (d.h. die Dreiecksungleichung gilt).

Also ist $\frac{\|\Delta z \|}{\|z\|} \leq \|A^{-1}\|_{M}\|A\|_{M}\frac{\|\Delta b\|}{\|b\|}$.

> [!abstract] Definition *Kondition einer Matrix*
> Der Faktor $$K_{M}(A):=\|A^{-1}\|_{M}\cdot\|A\|_{M}$$ heißt Kondition der Matrix $A$ bezüglich der Norm $\|\cdot\|_{M}$.


Ist $A$ singulär, dann ist $\|A^{-1}\|_{M}=\infty$.

Falls $A$ nicht singulär:
- $\|A\|=\|U \Sigma V ^{\ast}\|=\|\Sigma\|=\sigma_1$ und
- $\|A^{-1}\|=\|V \Sigma^{-1} U ^{\ast}\|=\|\Sigma^{-1}\|=\frac{1}{\sigma_{n}}$.

$$\Rightarrow K(A)=\frac{\sigma_1}{\sigma_{n}}\text{ für }A \in \mathbb{C}^{m\times n}, m\geq n.$$

Die Matrixnorm kann als Exzentrizität der Ellipse, die das Bild der Einheitskugel unter $A$ ist, interpretiert werden.
$K(A)=1 \Rightarrow$ Bild der Einheitskugel ist Kreis, ansonsten ist $K(A) > 1$.


## Floating Point Arithmetik

Wir betrachten Berechnungsfehler bei [[Kodierung von Binärzahlen#IEEE 754|Gleitkommazahlen]].

Wenn eine Zahl $x \neq 0$ auf $0$ gerundet wird, hat man einen ==Underflow==. 

Sei $\circ$ die Mathematische Grundoperation und $\bullet$ die vom Rechner realisierte Operation. Dann ist $$x \bullet y \leq (x \circ y)(1 + \epsilon_{M})$$mit $\epsilon_{M}=\inf\set{x > 0: 1 \oplus x \neq 1}$.
Es ist $\epsilon_{M}\approx 10^{-16}$ für 64-Bit-Gleitkommazahlen und $e_{M}\approx 10^{-8}$ für 32-Bit-Gleitkommazahlen.


### Stabilität

> [!abstract] Definition *Vorwärtsstabilität*
> Ein Algorithmus $\tilde{f}$ heißt vorwärts stabil, wenn $$\left|\frac{\tilde{f}(x)-f(x)}{f(x)}\right|=\left|\frac{\Delta y}{y}\right|\leq c_{V}K_{\text{rel}}\epsilon_{M}$$
> erfüllt ist für ein "mäßig großes" $c_{V}>0$, das von $x$ unabhängig ist.

Dann heißt $\tilde{f}$ auch ein "guter Realisierungsalgorithmus".

Vorwärtsanalyse ist leider schwierig. Lösung: Rückwärtsanalyse.

Bei der Rückwärtsanalyse interpretiert man $\tilde{f}(x)$ als exakte Lösung mit gestörten Eingangsdaten, d.h. $\tilde{f}(x)=f(x+ \Delta x)$.
Gibt es mehrere Urbilder $x + \Delta x$, wählt man das mit kleinster Störung $\Delta x$.

> [!abstract] Definition *Rückwärtsstabilität*
> Ein Algorithmus $\tilde{f}$ heißt rückwärts stabil, wenn $$\left|\frac{\Delta x}{x}\right|\leq c_{R}\epsilon_{M}$$ erfüllt ist für ein "mäßig großes" $c_{R}>0$, das von $x$ unabhängig ist.

Für einen rückwärts stabilen Algorithmus gilt: $$\left|\frac{\tilde{f}(x)-f(x)}{f(x)}\right|=\left|\frac{f(x+\Delta x)-f(x)}{f(x)}\right|\leq K_\text{rel}\left|\frac{\Delta x}{x}\right|\leq c_{R}K_{\text{rel}}\epsilon_{M}$$

> Ist ein Algorithmus rückwärts stabil, dann ist er auch vorwärts stabil.
> Die Umkehrung gilt i.A. nicht.


[[FOCVE_09_Neural_Radiance_Fields.pdf]]

## Differenzieller Lichtstrahl

Anstatt *Surface Rendering*: mehr von der plenoptischen Funktion modellieren, insb. durchscheinende Objekte

Betrachtung von **Differenziellem Lichtstrahl** und dessen Interaktion mit Materie:

- Lichstrahl parametrisiert mit $z$
- Position: $x(z)$
- Richtung: $v$
- (Akkumulierte) Leuchtkraft: $L(x(z), v)$
- An einem Punkt abgegebene Leuchtkraft: $L_{e}(x(z), v)$

- Absorption
	- Lichstrahl wird um Faktor $\mu_{a}$ abgeschwächt (W.keitsdichte der Absorption)
	- $\frac{dL(x(z), v)}{dz}=-\mu_{a}(x(z))L(x(z), v)$
- Emission
	- Lichtstrahl wird um $\mu_{a}$ verstärkt
		- Derselbe Koeffizient, denn Emission ist Absorption rückwärts
	- $\frac{dL(x(z), v)}{dz}=\mu_{a}(x(z))L_{e}(x(z), v)$
- Brechung
	- Out-Scattering: Lichtstrahl wird um $-\mu_{s}$ abgeschwächt
		- $\frac{dL(x(z), v)}{dz}=-\mu_{s}(x(z))L(x(z), v)$
	- In-Scattering: Strahlen aus anderen Richtungen verstärken Licht um $\mu_{s}$
		- $\frac{dL(x(z), v)}{dz}=\mu_{s}(x(z))L_{s}(x(z), v)$
		- $L_{s}(x(z), v)=\int_{S^{2}}f_{\text{phase}}(x(z), l, v)L(x(z), l)\,dl$

Die **Radiative Transfer Equation** ist die Summe aus diesen vier Termen und beschreibt die Veränderung des Lichtstrahls an einem Punkt vollständig.

## Notation für NeRFs

Scattering ist (wie die Renderinggleichung für Oberflächen) rekursiv, deshalb schmeißen wir die weg und beschränken uns bei Neural Radience Fields (NeRFs) nur auf Emission und Absorption.

**Andere Notation:**
- Lichtstrahl geht von der Kamera aus, also in die *andere Richtung*

Lichtstrahl: $r(t):=x(-z)$
*Dichte:* $\sigma(r(t)):=\mu_{a}(x(-z))$, notiert kürzer als $\sigma(t)$,
*Leuchtkraft* an einem Punkt in Richtung $d$: $$c(r(t), d):=L_{e}(x(-z),v)$$
notiert als $c(t)$,
*Akkumulierte **verbleibende** Leuchtkraft* eines Strahls an einem Punkt in Richtung $d$: $$\hat{C}(r(t), d):=L(x(-z),v)$$
notiert als $\hat{C}(t)$.

Radiative Transfer Equation: $$\frac{d\hat{C}(t)}{dt}=\sigma(t)\hat{C}(t)-\sigma(t)c(t).$$
Der Term für $c$ ist negativ, weil die Leuchtkraft entlang des Strahls *abnimmt* (wir starten ja bei der Kamera).

Lichtdurchlässigkeit (Transmittance) von Punkt $a$ nach Punkt $b$: $$T(a \to b)=\exp\left( -\int_{a}^{b}\sigma(u)\,du \right)$$

> **Volume Rendering Equation** (NeRF-Notation):
> $$\hat{C}(t)=\int_{t}^{t_{\text{end}}}\underbrace{T(t \to s) }_{\text{Sichtbarkeit von }r(s)}\ \ \underbrace{\sigma(s)c(s)}_{\text{Emission von }r(s)}\,ds + T(t\to t_{\text{end}})\underbrace{C_{\text{const}}}_{\text{Hintergrundfarbe}}$$


Für einen Strahl durch zwei durchscheinende Objekte sieht der Integrand dann so aus:
![[NeRF-Integrand.png|465]]

## Volume Rendering mit NeRFs

Wir können das Integral für $\hat{C}$ nicht analytisch lösen.
Wir nehmen also an, dass die Dichte $\sigma(t)$ und die Farbe $c(t)$ *stückweise konstant* sind.
Pro Segment samplen wir einmal: $\delta_{i}=t_{i+1}-t_{i}$

Dann wird die Durchlässigkeit zum $i$-ten Segment: $$T_{i}=\prod_{j=1}^{i-1}e^{-\sigma_{j}\delta_{j}}$$
> **Approximative Volume Rendering Equation** (für NeRFs):
> $$\hat{C}=\sum_{i=1}^{N}T_{i} \cdot (1-e^{-\sigma_{i}\delta_{i}})c_{i}+T_{N+1}\hat{C}_{\text{bg}}$$

Jetzt möchten wir unser $\sigma$ und $c$ mit einem [[Neuronales Netz|KNN]] schätzen. Dann können wir für jeden Pixel im Kamerabild dieses Integral ausrechnen und neue Blickwinkel ausrechnen.

> [!info] *Positional Encoding*
> Wir haben in Bildern oft starke Diskontinuitäten. Um nahegelegene Punkte für das KNN besser unterscheidbar zu machen, encoden wir jede Achsenposition $p$ mit extra Sinus- und Kosinus-Bändern: $$\gamma(p)=(\sin(2^{0}\pi p), \cos(2^{0}\pi p),\dots,\sin(2^{L-1}\pi p),\cos(2^{L-1}\pi p))^{T}$$

Die Position können wir mit 10 Frequenzen encoden, die Richtung mit 4.

Architektur:
![[NeRF-Architektur.png|450]]

Die Richtung wird erst am Ende eingespeist, weil sie keinen Einfluss auf die Dichte $\sigma$ haben soll.

### Training

**Forward Pass:** Integral ausrechnen
1. $K$ Kamera-Strahlen marchen
2. (Uniform) Punkte samplen
3. MLP an diesen Punkten für Dichte und Farbe auswerten
4. Werte akkumulieren -> $\hat{C}_{k}$

**Backward Pass:** Loss berechnen und Differenzial für KNN-Parameter bestimmen
$$\mathcal{L}(\Theta)=\sum_{k}\|C_{k}-\hat{C}_{k}(\Theta)\|^{2}$$


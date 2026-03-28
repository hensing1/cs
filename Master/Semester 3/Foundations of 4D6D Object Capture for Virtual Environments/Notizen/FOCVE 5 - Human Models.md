[[FOCVE_05_Human_Models.pdf]]

Wir möchten den Nutzer *modellieren* und Bewegungen *tracken*.
Wir müssen dafür einmal die Pose statisch schätzen, und dann für einzelne Punkte die Bewegung verfolgen.
## Dynamic Fusion

### Warp Field

Quelle: Sequenz von RGB-D-Bildern

Referenz: z.B. erster Frame
Tracking mit ICP Kram
Bewegung eines Punktes $x$ beschrieben durch homogene Koordinaten:

$$T_{\text{warp}}(x)=\left[
\begin{array}{ccc|c}
\\
& R(x) & & t(x) \\
\\ \hline
& \mathbf{0} & & 1
\end{array}
\right]$$

## SMPL
**Skinned Multi-Person Linear model** - für Aussehen + Posierung einer menschlichen Figur

*Parameter:*
- Pro Gelenk: 3 Rotationsparameter (+ Orientierung von Root-Node (beim Bauchnabel))  $\theta = (\omega_{0},\dots,\omega_{K})^{T} \in \mathbb{R}^{3K+3}$
	- $K=23$ Gelenke
	- Jedes $\omega^{K}$ ist Achse+Winkel-Darstellung relativ zum Parent-Gelenk
	- $\omega_{0}$ ist globale Orientierung vom Root Node (Pelvis) rel. zu Weltkoordinaten
- Körperform (Größe, Statur usw.): $\beta \in \mathbb{R}^{10}$

Wir starten mit einem *Template Model* $\overline{T}$ (von einem Künstler erstellt).
Es gibt ein männliches, ein weibliches, und ein geschlechtsneutrales mit je $N \approx 7000$ Vertices, in einer Ruhepose $\theta_{\text{rest}}$.

Zuerst verformen wir $\overline{T}$ bzgl. der Körperparameter $\beta$: Vertices werden additiv verschoben mit $$\overline{T}+B_{S}(\beta)= \overline{T} + \mathcal{S}\beta.$$
[^1]
Dadurch verschieben sich die $K$ Gelenkpositionen. Diese recovern wir mit einer gelernten Matrix $\mathcal{J} \in \mathbb{R}^{3K \times 3N}$: $$J(\beta)=\mathcal{J}(\overline{T}+B_{S}(\beta))$$
Die Gelenkpositionen können wir jetzt mit den Parametern $\theta$ verschieben und erhalten mit Vorwärtskinematik pro Gelenk $k$ die globale Verschiebung & Rotation $T_{k}$ zum globalen Frame.

Damit können wir jetzt schon *linear blend skinning* (LBS) machen, in dem wir jedem Vertex des Modells ein paar Gelenke zuweisen, die auf ihn Einfluss nehmen:
$$v_{i}'=\sum_{k=1}^{K}w_{ik}T_{k}v_{i}.$$

Die Gewichtungen können wir in der Matrix $\mathcal{W} \in \mathbb{R}^{N \times K}$ zusammenfassen.

Das reicht aber noch nicht, weil mit LSB va. bei großen Gelenkwinkeln oder Twist-Bewegungen Artefakte auftreten können. Die müssen wir vor LBS noch korrigieren: 
$$B_{P}(\theta)=\mathcal{P} \cdot (R(\theta)-R(\theta_{\text{rest}}))$$
mit einer erlernten Matrix $\mathcal{P}$.
Die Vertices, die wir mit LBS in ihre Pose verschieben können, sind dann gegeben durch $$\overline{T}_{S,P}=\overline{T}+B_{S}(\beta)+B_{P}(\theta).$$
$B_{S}$ und $B_{P}$ heißen **Blend Shapes**.

![[SMPL.png]]

[^1]: $\mathcal{S}$ ist die Basis für die linearen Körperparameter, die mit PCA bestimmt wurden.

## SMPL-X

Dasselbe Spiel können wir jetzt nochmal für das Gesicht (FLAME-Modell) und für die Hand (MANO-Modell) spielen. SMPL, FLAME und MANO bilden zusammengenommen SMPL-X.
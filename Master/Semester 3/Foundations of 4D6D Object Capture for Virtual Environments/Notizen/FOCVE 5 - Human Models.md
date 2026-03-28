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

Zuerst verformen wir $\overline{T}$ bzgl. der Körperparameter $\beta$

Die Matrix $\mathcal{W} \in \mathbb{R}^{N \times K}$ sagt für jeden Punkt, welche Gewichtung jedes Gelenk für diesen Punkt hat. Sie ist sparse (Schultergelenk hat keinen Einfluss auf Vertices am Knie).
Die Gelenkposition

Wir wenden die Shape-Parameter $\beta$ an, um neue Gelenk-Koordinaten zu erhalten.
Wir haben ein zugrundeliegendes Skelett, dessen Node-Positionen wir mit Vorwärtskinematik bestimmen.
- $\mathcal{J}$: Zusammengenommene Gewichtungen:
	- $\mathcal{W} \in \mathbb{R}^{N \times K}$: Überblendungs-Gewichte pro Punkt
	- $\mathcal{P} \in \mathbb{R}^{3N \times 9K}$: Linear Blend Skinning: Pose
	- $\mathcal{S} \in \mathbb{R}^{3N \times 10}$


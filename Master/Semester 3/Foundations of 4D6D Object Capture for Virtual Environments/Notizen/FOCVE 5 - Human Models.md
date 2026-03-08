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
Skinned Multi-Person Linear model

Menschmodell mit den folgenden Parametern:
- Pro Gelenk: 3 Rotationsparameter (+ Orientierung von Root-Node (beim Bauchnabel))  $\theta \in \mathbb{R}^{3K+3}$
	- $K=23$ Gelenke
	- Darstellung in Winkel-Achse relativ zum Parent-Gelenk
- Körperform: $\beta \in \mathbb{R}^{10}$

Intern wurden für dieses Modell die folgenden Parameter trainiert:
- $\overline{T} \in \mathbb{R}^{3N}$: Template-Mesh für männliches, weibliches und geschlechtsneutrales Basis-Modell, mit $N\approx7000$ Vertices
- $\mathcal{J}$: Zusammengenommene Gewichtungen:
	- $\mathcal{W} \in \mathbb{R}^{N \times K}$: Überblendungs-Gewichte pro Punkt
	- $\mathcal{P} \in \mathbb{R}^{3N \times 9K}$: Linear Blend Skinning: Pose
	- $\mathcal{S} \in \mathbb{R}$
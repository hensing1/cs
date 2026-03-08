[[FOCVE_05_Human_Models.pdf]]

Wir möchten den Nutzer *modellieren* und Bewegungen *tracken*.
Wir müssen dafür einmal die Pose statisch schätzen, und dann für einzelne Punkte die Bewegung verfolgen.
## Dynamic Fusion

### Warp Field

Quelle: Sequenz von RGB-D-Bildern

- Einzelne statische Pose schätzen
- pro Punkt die Bewegung

Bewegung von Punkt $x$:
$$T_{\text{warp}}(x)=\left[
\begin{array}{ccc|c}
\\
& R(x) & & t(x) \\
\\ \hline
& \mathbf{0} & & 1
\end{array}
\right]$$

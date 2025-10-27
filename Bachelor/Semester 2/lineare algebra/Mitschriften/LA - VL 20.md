Datum: 27.06.
[[ThR_LA_Skript.pdf|Skript]] - Seiten 107 bis 112

# Matrix Matrix 

> Für eine lineare Abbildung $f: V \to W$ mit $\text{Rg}(f)=\text{dim}(\text{Bild}(f))=r$ existieren immer zwei Basen $B$ von $V$ und $C$ von $W$, sodass $$\text{DM}_{B,C}(f)=\begin{pmatrix}1 & \ldots & 0 & \ldots & 0 \\ \vdots & \ddots &  &  \\ 0 &  & 1 & \\ \vdots & & & \ddots \\ 0 & & & & 0 \end{pmatrix},$$wobei die ersten $r$ Stellen der Diagonalen aus Einsen und der gesamte Rest aus Nullen besteht.

Diese Basen findet man wie folgt:
- Suche Basis $B'$ von $\text{Kern}(f)\subseteq V$. Diese Basisvektoren bilden die Nullspalten rechts.
- Ergänze $B'$ zu Basis $B$ von $V$.
- Wähle $(f(v_{1}), f(v_{2}), \ldots, f(v_{r}))$ als Basis $C'$ von $\text{Bild}(f)\subseteq W$.
	- $v_{i}$ sind dabei die $r$ Vektoren, die in Schritt 2 ergänzt wurden.
- Ergänze $C'$ zu Basis $C$ von $W$.

![[Matrizen#Transponierte Matrix]]
## Spiegeln

Ein Vektor zusammen mit seiner Spiegelung ist eine Basis für den $\mathbb{R}^{2}$, solange er nicht direkt auf der Spiegelachse liegt, oder im 90°-Winkel dazu.

Legt man eine solche Basis $C$ zugrunde, dann ist für die Spiegelfunktion $f$ im $\mathbb{R}^{2}$ die darstellende Matrix: $$\text{DM}_{C}(f)=\begin{pmatrix}0 & 1 \\ 1 & 0\end{pmatrix}.$$
Bei einer Spiegelung werden nämlich die beiden Basisvektoren vertauscht. Die Spiegelachse ist diejenige, die genau zwischen den beiden Basisvektoren durch den Nullpunkt verläuft.

Hat man eine Basis $D$ für den $\mathbb{R}^2$, bei dem die beiden Basisvektoren im 90°-Winkel zueinander stehen, und man möchte mit der Funktion $f$ am ersten Vektor spiegeln, dann ist $$\text{DM}_{D}(f)=\begin{pmatrix}1 & 0 \\ 0 & -1\end{pmatrix}.$$


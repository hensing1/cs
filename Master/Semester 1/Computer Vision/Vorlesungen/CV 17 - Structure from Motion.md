[[17sfm_WS2425_slides.pdf]]

# Structure from Motion

- Wir kennen die Kameraparameter nicht
- Wir kennen die 3D-Punkte nicht
- Wir haben aber Korrespondenzen: $m$ Bilder von $n$ 3D-Punkten: $$x_{ij}=P_{i}X_{j},\quad P_{i},X_{j}\text{ unbekannt}$$

Es gibt eine Mehrdeutigkeit: wir können eine Transformation $Q$ auf die Szene anwenden, und $Q^{-1}$ auf die Kameraparameter, und haben dasselbe Resultat: $$x=PX=(PQ^{-1})(QX)$$

$Q$ kann in dem allgemeinsten Fall nur bis auf eine projektive Transformation bestimmt werden:
![[Ambiguities.png|500]]

Was wir gerne hätten: Lösung bis auf Skalierung. Wenn man dann irgendwas in der Szene hat, dessen Größe man kennt, kann man die Skalierung noch im Nachhinein bestimmen.

## Affine Kamera

Annahme für Kameramodell: wir haben eine affine Transformation in den Weltkoordinaten, dann eine [[CV 15 - Calibration#Orthografische Projektion|orthografische Projektion]] in die Bildkoordinaten, dann nochmal eine affine Transformation. $$P=[3 \times 3 \text{ affin}] \begin{bmatrix}
1 & 0 & 0 & 0 \\
0 & 1 & 0 & 0 \\
0 & 0 & 0 & 1
\end{bmatrix} [4 \times 4 \text{ affin}] = \begin{bmatrix}
a_{11} & a_{12}  & a_{13} & b_{1} \\
a_{21} & a_{22} & a_{23} & b_{2} \\
0 & 0 & 0 & 1
\end{bmatrix} = \begin{bmatrix}
A & b \\
0 & 1
\end{bmatrix}$$
Die Vektoren $a_{1}$ und $a_{2}$ spannen hierbei die Bildebene auf - die Projektion eines Puntkes $x$ sind die Skalarprodukte $a_{1}x$ und $a_{2}x$, plus den Vektor $b$.
-> der Nullvektor wird auf $b$ projiziert.

Mit einer affinen Kamera ist die Mehrdeutigkeit von $Q$ nur noch eine *affine* Transformation.

$2mn$ Observationen, $8m$ gesuchte Kameraparameter, $3n$ gesuchte Punktkoordinaten, 12 Freiheitsgrade:
$2mn \geq 8m+3n-12$

=> für 2 Kameras, $\geq 4$ Punkte benötigt.

***Freiheitsgrade reduzieren***
- Durchschnitt aller Punkte abziehen: $\hat{x}_{ij}=x_{ij}- \frac{1}{n}\sum_{k=1}^{n}x_{ik}$
	- fixiert das Zentrum der Weltkoordinaten bei $\vec{0}$
	- kein $b$ mehr: $\hat{X}_{ij} = A_{i}X_{j}$

Wir machen aus allen Punkten eine große $2m \times n$-Matrix $D$, die wir in alle Matrizen und 3D-Punkte aufteilen wollen: $$D=\begin{bmatrix}
\hat{x}_{11} & \dots & \hat{x}_{1n} \\
 & \ddots  &  \\
\hat{x}_{m1} & \dots & \hat{x}_{mn}
\end{bmatrix} = \begin{bmatrix}
A_{1} \\
\vdots \\
A_{m}
\end{bmatrix} \begin{bmatrix}
X_{1} & \dots & X_{n}
\end{bmatrix}$$
Kameramatrix-Stapel: $2m\times 3$
Punktereihe: $3 \times n$

lösbar bis auf 9 Freiheitsgrade

- Bildachsen sind senkrecht: $a_{1} \cdot a_{2}=0$
- Bildachsen normieren: $\lvert a_{1} \rvert^{2} = \lvert a_{2} \rvert^{2}=1$


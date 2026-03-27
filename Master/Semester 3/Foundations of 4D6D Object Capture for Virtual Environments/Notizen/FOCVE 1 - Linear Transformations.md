[[FOCVE_01_Motivation_and_Linear_Transformations.pdf]]

**Plenoptic Function**
$$P(\theta,\phi,\lambda,t,V_{x},V_{y},V_{z})$$
beschreibt das Licht, welches
- am Punkt $(V_{x}\ V_{y}\ V_{z})$
- am Zeitpunkt $t$
- mit Wellenlänge $\lambda$
- aus Richtung $(\theta\ \lambda)$ (Kugelkoordinaten)
*empfangen* wird.

## Rotationsbeschreibungen

### Eulerwinkel
Rotationsmatrizen: gegen den Uhrzeigersinn (bei Blick aus $+\infty$ auf die Rotationsachse)
Eulerwinkel: $R_{\text{Euler}}(\alpha, \beta, \gamma) = R_{z}(\gamma) R_{x}(\beta) R_{z}(\alpha)$ (z-x-z, x,y,x, ...)
Tait-Bryan-Winkel: (x-y-z, y,z,x, ...)
Achtung: Gimbal Lock, wenn mittlere Rotation die beiden äußeren Drehachsen identisch macht

### Quarternionen

- gegeben Einheits-Rotationsvektor $r_{0}=(r_{x},r_{y},r_{z})^{T}$
- und Rotationswinkel $\theta \in \mathbb{R}^{2}$
- und $q_{a}=ia_{1}+ja_{2}+ka_{3} \in \mathbb{H}$ für einen Punkt $a \in \mathbb{R}^{3}$
- sowie $q_{r_{0}}=e^{(ir_{x}+jr_{y}+kr_{z}) \theta/2}$
ist der rotierte Punkt:
$$q_{x,\text{rot}}=q_{r_{0}} \cdot q_{x} \cdot q_{r_{0}}^{-1}.$$
Das Resultat $q_{x,\text{rot}}$ ist, genau wie $q_{x}$, rein imaginär (kein reeller Part).

Wir mögen Quarternionen, weil sie keine singuläre Konfiguration haben, mit 

### Achs-Winkel-Repräsentation

Definiere eine Rotationsachse mit (Einheits-)vektor $r_{0}$ und einen Rotationswinkel $\theta$.
Dann ist die Rotation um $r_{0}$ und $\theta$ gegeben durch die

> **Rodriguez-Formel**
> $$a_{\text{rot}}=a + \sin(\theta)(r_{0} \times a) + (1-\cos(\theta))(r_{0}\times (r_{0} \times a))$$

Mit $[r_{0}]_{\times}$ der [[Vektoren#^adaeb8|Kreuzproduktmatrix]] ergibt sich: $$R_{\text{axis-angle}}=I+\sin(\theta)[r_{0}]_{\times}+(1-\cos(\theta))[r_{0}]_{\times}^{2}.$$

## Homogene Koordinaten

[[Homogene Koordinaten]]

> [!abstract] Definition *Rigide Transformation*
> Eine Transformation $T$ heißt rigide (rigid), wenn sie Distanzen zwischen Punkten erhält: $$\|T(x)-T(y)\|=\|x-y\|\ \forall x, y.$$

Es gibt: Rotationen, Reflektionen, Translationen (und Kombinationen davon).

## Koordinatentransformation

Mit $b_{x},b_{y},b_{z}$ den Koordinatenachsen von $b$ in $a$, und $t$ dem Ursprung von $b$ in $a$, ist $$T=\begin{bmatrix}
b_{x} & b_{y} & b_{z} & t \\
0 & 0 & 0 & 1
\end{bmatrix}$$
die homogene Transformationsmatrix von $b$ nach $a$.
Man kann diese Matrix invertieren und erhält die Transformationsmatrix von $a$ nach $b$.

Im Kontext dieser Vorlesung brauchen wir das für Skelette, bei denen wir jedes Gelenk in Relation eines übergeordneten Gelenks definieren: $$T_{\text{Welt} \to \text{Knie}}=T_{\text{Hüfte}\to \text{Knie}} \cdot T_{\text{Pelvis}\to \text{Hüfte}} \cdot T_{\text{Welt}\to \text{Pelvis}}.$$
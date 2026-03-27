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

### Achs-Winkel-Repräsentation

Definiere eine Rotationsachse mit (Einheits-)vektor $r_{0}$ und einen Rotationswinkel $\theta$.
Dann ist die Rotation um $r_{0}$ und $\theta$ gegeben durch die

> **Rodriguez-Formel**
> $$a_{\text{rot}}=a + \sin(\theta)(r_{0} \times a) + (1-\cos(\theta))(r_{0}\times (r_{0} \times a))$$
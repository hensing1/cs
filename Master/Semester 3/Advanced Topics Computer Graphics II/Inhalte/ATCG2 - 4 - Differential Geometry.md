[[atcg2-04-Differential_Geometry.pdf]]

- Wir definieren [[CG VL 9 - Parametrische Flächen#^3afcd1|reguläre parametrische Flächen]]
- Mapping: $q: \mathbb{R}^{2} \supset \mathcal{D} \to \mathbb{R}^{3}$, $(u,v)^{T} \mapsto (x(u,v), y(u,v), z(u,v))^{T}$
- Hält man einen Parameter fest, erhält man eine parametrische Kurve auf dieser Fläche
- Tangenten:
	- $q_{u}(u,v)=\frac{ \partial q(u,v) }{ \partial u }$
	- $q_{v}(u,v)=\frac{ \partial q(u,v) }{ \partial v }$
- Normale:
	- $n(u,v):= \frac{q_{u}(u,v)\times q_{v}(u,v)}{\|q_{u}(u,v) \times q_{v}(u,v)\|_{2}}$

Um die Tangente in eine beliebige Richtung $w \in \mathcal{D}$ ($w$ ist im Parameterraum) zu erhalten, nehmen wir die [[Funktionen#Gradient, Jacobi-Matrix, Hesse-Matrix|Jacobi-Matrix]]:
$$J(u,v) = \begin{pmatrix}
& \\
q_{u}(u,v) & q_{v}(u,v) \\
&
\end{pmatrix} \in \mathbb{R}^{3 \times 2}$$
und dann ist die *Richtungsableitung* von $w$: $$dq_{w}(u,v)=J(u,v)w.$$
$dq_{w}(u,v)$ liegt in der Tangentialebene aufgespannt von $q_{u}(u,v)$ und $q_{v}(u,v)$.

## First Fundamental Form

> [!abstract] Definition **Erste Fundamentalform**
> Es seien $q_{u}(u,v)$ und $q_{v}(u,v)$ die Richtungsableitungen nach Parameter-Basisvektoren $u$ und $v$. Dann ist $$M_{1}=J^{T}(u,v) J(u,v)=\begin{pmatrix}E & F \\ F & G\end{pmatrix}$$ mit $$E=\langle q_{u} \mid q_{u} \rangle, \quad F=\langle q_{u} \mid q_{v} \rangle , \quad G=\langle q_{v} \mid q_{v} \rangle$$
> die Matrix der ersten Fundamentalform mit Basis $q_{u}$, $q_{v}$.

Die erste Fundamentalform erlaubt es, zwei Richtungen $w_{1},w_{2}$ im *Parameterraum* zu nehmen, und daraus das Skalarprodukt zwischen den jeweiligen Richtungsableitungen $dq_{w_{1}}(u,v)$ und $dq_{w_{2}}(u,v)$ zu bilden: 

$$\begin{align}
\omega_{1} &\to J \omega_{1} \\
\omega_{2} &\to J \omega_{2} \\
\langle J \omega_{1} \mid J \omega_{2} \rangle &= (J \omega_{1})^T (J \omega_{2}) = \omega_{1}^T J^T J \omega_{2} = \omega_{1} M_{1} \omega_{2}.
\end{align}$$
## Shape Operator

$$\begin{align}
W_{p}&: TP_{p} \to TP_{p} \\
W_{p}(v) &= -d_{p}n(v)
\end{align}$$
Sagt aus, wie sich der Normalenvektor verändert, wenn man sich ein bisschen entlang der Tangentialebene bewegt

$$W_{p}(\omega_{1})^{T}\begin{pmatrix}
E & F \\
F & G
\end{pmatrix}\omega_{2}$$
misst irgendwas

Wir haben $u$ und $v$ im Parameterraum, und wir wollen Berechnungen im Parameterraum machen
- $q$ mappt $u$ und $v$ in den $\mathbb{R}^{3}$
- $q_{u}$, $q_{v}$ sind Tangentialvektoren
- 

Second Fundamental Form: erzählt uns die Änderung des Normalenvektors


- Wir spannen Ebene mit Normale und einem Tangentenvektor auf
- Wir haben eine Krümmung nach unten/oben entlang dieser Ebene
- Je nachdem, wie man den Tangentenvektor rotiert, erhält man verschiedene Krümmungen
- Die Tangentenvektoren für maximale und minimale Krümmung sind *orthogonal*

"Principal Curvatures": Maximale und minimale Krümmung, $\kappa_{1}$ und $\kappa_{2}$
Interpolierung von Krümmungen gemäß der Euler-Beziehung: $$\kappa_{n}(\omega)=\kappa_{1}\cdot \cos(\phi)^{2}+\kappa_{2} \cdot \sin(\phi)^{2}$$
mit $\phi$ dem Winkel zwischen der durch $\omega$ induzierten Ebene und der Ebene von $\kappa_{1}$.

Gauss-Krümmung: $\kappa_{G}=\kappa_{1} \cdot \kappa_{2}$
Durchschnittliche Krümmung (mean curvature): $\kappa_{M}:= \frac{1}{2}(\kappa_{1} + \kappa_{2}) = \frac{1}{\pi}\int_{0}^{\pi}\kappa_{n}(\omega(\theta))\,d\theta$


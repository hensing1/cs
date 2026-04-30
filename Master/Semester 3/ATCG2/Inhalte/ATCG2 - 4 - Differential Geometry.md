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
> Es sei $p=q(u,v)$ ein Punkt auf einer Oberfläche und $TP_{p}$ die Tangenzialebene am Punkt $p$.
> Es ist $$\begin{align}
> I_{p}: TP_{p} \times TP_{p} &\to \mathbb{R} \\
> I_{p}(w_{1},w_{2}) := \langle w_{1} \mid w_{2} \rangle 
> \end{align}$$ die *Erste Fundamentalform* am Punkt $p$.

> **Matrix der Ersten Fundamentalform**
> Es seien $q_{u}(u,v)$ und $q_{v}(u,v)$ die Richtungsableitungen nach Parameter-Basisvektoren $u$ und $v$. Dann ist $$M_{1}=J^{T}(u,v) J(u,v)=\begin{pmatrix}E & F \\ F & G\end{pmatrix}$$ mit $$E=\langle q_{u} \mid q_{u} \rangle, \quad F=\langle q_{u} \mid q_{v} \rangle , \quad G=\langle q_{v} \mid q_{v} \rangle$$
> die Matrix der ersten Fundamentalform mit Basis $q_{u}$, $q_{v}$.

Das ist der [[ATCG2 - 7 - Differential Forms#Metrischer Tensor|metrische Tensor]] an diesem Punkt der Oberfläche.
$M_{1}$ hängt von der Parametrisierung ab. Die Fundamentalform $I_{p}$ selbst ist unabhängig von der Parametrisierung - sie interessiert sich nur für Tangenzialvektoren.

Die Matrix der ersten Fundamentalform erlaubt es, zwei Richtungen $w_{1},w_{2}$ im *Parameterraum* zu nehmen, und daraus das Skalarprodukt zwischen den jeweiligen Richtungsableitungen $dq_{w_{1}}(u,v)$ und $dq_{w_{2}}(u,v)$ zu bilden: 

$$\begin{align}
\omega_{1} &\to J \omega_{1} \\
\omega_{2} &\to J \omega_{2} \\
\langle J \omega_{1} \mid J \omega_{2} \rangle &= (J \omega_{1})^T (J \omega_{2}) = \omega_{1}^T J^T J \omega_{2} = \omega_{1} M_{1} \omega_{2}.
\end{align}$$

$E$ sagt uns die quadrierte Länge von $q_{u}$ und $G$ die quadrierte Länge von $q_{v}$.
$F$ sagt uns den Winkel zwischen $q_{u}$ und $q_{v}$.

### Bogenlänge berechnen
Für eine Kurve $q(u(t), v(t))$ auf der durch $q$ definierten Oberfläche ist deren Bogenlänge, ab einem Startpunkt $a$: $$s(t)=\int_{a}^{t}\left\| \frac{dq(u(\tau),v(\tau))}{d \tau}\right\|\,d\tau .$$
Das Differenzial von $q \circ u$ ist also ebenfalls proportional zur Länge, die man mit einem Zeitschritt zurücklegt.
Mit $u_{t}:=\frac{du}{dt}$ und $v_{t}:=\frac{dv}{dt}$ ist die Bogenlänge der Kurve: $$s(a,b)=\int_{a}^{b} \sqrt{ (u_{t},v_{t})M_{1}(u_{t},v_{t})^{T} }\,dt$$
dh. $\left\| \frac{dq(u(\tau),v(\tau))}{d \tau}\right\| = \sqrt{ (u_{t},v_{t})M_{1}(u_{t},v_{t})^{T} }$.

### Fläche berechnen
Für eine Fläche $\mathcal{D}$ definiert als Intervall von $u$ und $v$, von wo bis wo die Fläche reichen soll, ist die Fläche: $$A = \iint_{\mathcal{D}}\|q_{u} \times q_{v}\|\,du\,dv = \iint_{\mathcal{D}}\sqrt{ EG-F^{2} }\,du\,dv.$$

## Shape Operator

An einem Punkt $u,v$ ist $n(u,v)$ der Normalenvektor auf der Oberfläche $q$. Eine Fläche ist *orientierbar*, wenn $n$ im gesamten Parameterraum kontinuierlich ist.

Die Richtungsableitung in Richtung $w$ (Vektor im Parameterraum) für die Normale ist $dn_{w}(u,v)=w_{1}n_{u}(u,v)+w_{2}n_{v}(u,v)$.

> Die Richtungsableitung der Normale ist immer rechtwinklich zur Normalen.

Das Mapping, das einem Vektor auf der Tangenzialebene am Oberflächenpunkt $p$ die entsprechende Änderung vom Normalenvektor in diese Richtung sagt, nennen wir $d_{p}n: TP_{p} \to TP_{p}$.

> [!abstract] Definition **Shape Operator** (Weingarten Map)
> $$\begin{align}
> W_{p}&: TP_{p} \to TP_{p} \\
> W_{p}(v) &= -d_{p}n(v)
> \end{align}$$

Sagt aus, wie sich der Normalenvektor verändert, wenn man sich ein bisschen entlang der Tangentialebene bewegt (nicht im Parameterraum, sondern auf der Oberfläche!).

> [!abstract] Definition **Zweite Fundamentalform**
> Für einen Punkt $p$ auf der Oberfläche ist die bilineare Zuordnung 
> $$\begin{align}
> II_{p}: TP_{p} \times TP_{p} &\to \mathbb{R} \\
> II_{p}(w_{1},w_{2}) &= I_{p}(W_{p}(w_{1}),w_{2})
> \end{align}$$
> die zweite Fundamentalform am Punkt $p$.

> **Matrix der zweiten Fundamentalform**
> Es sei $q_{u}$ und $q_{v}$ die Richtungsableitungen nach $u$ und $v$ und $n$ der Normalenvektor. Die Matrix $$M_{2}=\begin{pmatrix}L & M \\ M & N\end{pmatrix}$$
> mit $$L=\langle q_{uu} \mid n \rangle,\ M=\langle q_{uv} \mid n \rangle,\ N=\langle q_{vv} \mid n \rangle$$
> ist die Matrix der zweiten Fundamentalform, mit Basis $\{ q_{u} ,q_{v}\}$.


- Wir spannen Ebene mit Normale und einem Tangentenvektor auf
- Wir haben eine Krümmung nach unten/oben entlang dieser Ebene

Diese Krümmung nennen wir *normal curvature* $\kappa_{n}$. Sie ist unabhängig von der Parametrisierung.
Wir können sie berechnen als $$\kappa_{n}=\frac{w^{T}M_{2}w}{w^{T}M_{1}w}$$
wobei $w=(u,v)$ ein Vektor im Parameterraum ist.

- Je nachdem, wie man den Tangentenvektor rotiert, erhält man verschiedene Krümmungen
- Die Tangentenvektoren für maximale und minimale Krümmung sind *orthogonal*.

"Principal Curvatures": Maximale und minimale Krümmung, $\kappa_{1}$ und $\kappa_{2}$
Interpolierung von Krümmungen gemäß der Euler-Beziehung: $$\kappa_{n}(\omega)=\kappa_{1}\cdot \cos(\phi)^{2}+\kappa_{2} \cdot \sin(\phi)^{2}$$
mit $\phi$ dem Winkel zwischen der durch $\omega$ induzierten Ebene und der Ebene von $\kappa_{1}$.

Gauss-Krümmung: $\kappa_{G}=\kappa_{1} \cdot \kappa_{2} = \frac{LN-M^{2}}{EG-F^{2}}$
Durchschnittliche Krümmung (mean curvature): $\kappa_{M}:= \frac{1}{2}(\kappa_{1} + \kappa_{2}) = \frac{1}{\pi}\int_{0}^{\pi}\kappa_{n}(\omega(\theta))\,d\theta$


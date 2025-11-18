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
und dann ist die Tangente von $w$: $$dq_{w}(u,v)=J(u,v)w.$$
$dq_{w}(u,v)$ liegt in der Tangentialebene aufgespannt von $q_{u}(u,v)$ und $q_{v}(u,v)$.

> [!abstract] Definition **Erste Fundamentalform**
> Es sei $p=q(u,v)$ ein Punkt auf der Oberfläche $q$, und 
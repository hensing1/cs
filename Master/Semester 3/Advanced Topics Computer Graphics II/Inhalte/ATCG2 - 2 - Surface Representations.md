[[atcg2-02-Surface-RepresentationsI.pdf]]

**Explizite und Implizite Darstellungen**

*Explizit:* Mapping von Koordinaten zu einem bestimmten Punkt auf der Oberfläche.
Die Oberfläche ist das [[Funktionen#Bild und Urbild|Bild]] dieses Mappings.
Beispiel für einen Kreis: $p(t)=r \begin{pmatrix}\cos(t) & \sin(t)\end{pmatrix}^{T},\ t \in [0,2\pi]$

-> einfach auszuwerten, davon zu samplen, linear zu approximieren

*Implizit:* Oberfläche ist Isofläche einer Funktion, $\mathcal{I}=\{ p \in \mathbb{R}^{n} \mid f(p)=0 \}$.
Beispiel Kreis: $f(x)=x^{2}+y^{2}-r^{2}$

**Parametrisierte Oberfläche**
Explizite Darstellung $$\begin{align}
q: D &\to \mathbb{R}^{d},\ D \subseteq \mathbb{R}^{2} \\ \\

(u,v) &\mapsto \begin{pmatrix}
x(u,v) \\
y(u,v) \\
z(u,v) \\
\dots
\end{pmatrix}
\end{align}$$
Hält man einen Parameter fix, erhält man eine eindimensionale parametrisierte Kurve (Parameterkurve).
Ist die Parameterkurve diff.bar, ist ihre Ableitung der *Tangentenvektor* bzw. die Richtungsableitung der Oberfläche: $q_{u}(u,v)=\frac{ \partial q(u,v) }{ \partial u }$.

Sind $q_{u}$ und $q_{v}$ *immer linear Unabhängig*, heißt die Oberfläche *regulär*.

Das normierte Kreuzprodukt von $q_{u}$ und $q_{v}$ ist der *Normalenvektor*. Er ist unabhängig von der Parametrisierung.

## Tensorproduktoberflächen

Man nehme zwei parametrisierte Kurven mit Basisfunktionen (z.B. Bernsteinpolynome vom Grad $m$ und $n$, dh. zwei Kurven mit $m+1$ bzw. $n+1$ Basisfunktionen ).
Jede *Kombination* dieser Basisfunktionen liefert uns eine neue Basisfunktion, welche ein bivariates Polynom ist: $$B_{i}^{m}B_{j}^{n}(u,v)=B_{i}^{m}(u) \cdot B_{j}^{n}(v)$$
Der Raum aller Bezierkurven vom Grad $n$ ist ein $n+1$-dimensionaler Vektorraum $P^{n}$, jedes Bernsteinpolynom ist ein Basiselement.
Die obenstehende Kombination ist ein **Tensorprodukt**. Sein Resultat $P^{m}\otimes P^{n}$ ist ein $(m+1) \cdot (n+1)$-dimensionaler Vektorraum.

Man kann nun also eine *Oberfläche* mit $(m+1) \cdot (n+1)$ Kontrollpunkten machen: $$q(u,v)=\sum_{i=0}^{m}\sum_{j=0}^{n}c_{ij}B_{i}^{m}(u) \cdot B_{j}^{n}(v).$$
![[Tensorproduktfläche.png|400]]

"Twist Vector" eines Quads an einem Vertex: der pinke Vektor
![[Twist Vector.png|300]]

## Rationale Bézier-Oberfläche

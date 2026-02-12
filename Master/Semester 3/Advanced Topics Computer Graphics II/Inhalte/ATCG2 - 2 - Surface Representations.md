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




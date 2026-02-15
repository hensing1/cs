[[atcg2-03-Surface RepresentationsII.pdf]]

## Implizite Darstellungen

Funktion $g(x,y,z)$, sodass:
- $\{ p \in \mathbb{R}^{3} \mid g(p) <0 \}$ das Innere
- $\{ p \in \mathbb{R}^{3} \mid g(p) =0 \}$ die Oberfläche
- $\{ p \in \mathbb{R}^{3} \mid g(p) >0 \}$ das Äußere des Objekts ist.

> [!abstract] Definition *Quadrik*
> Sei $g: \mathbb{R}^{2}\to \mathbb{R}$ ein multivariates Polynom $$g(x,y)=\sum_{i+j=2}a_{ij}x^{i}y^{j}\ + a_{00}.$$
> Dann erhält man durch $$Q:= \{ p \in \mathbb{R}^{2} \mid g(p)=0 \}$$
> eine **Quadrik**, also die implizite Darstellung von einem *Kegelschnitt* (Conic Section).

Ein Kegelschnitt ist eine Parabel oder eine Ellipse.
Haben wir das Argument von $g$ in [[Homogene Koordinaten|homogenen Koordinaten]], können wir auch schreiben: $$g(x,y,w)=\sum_{i+j+k=2}a_{ijk}x^{i}y^{j}w^{k}.$$

Allgemein:

> **Algebraische Oberfläche** (von Grad $n$)
> Für homogene Koordinaten: $$g(x,y,z,w)=\sum_{i+j+k+l=n}a_{ijkl}x^{i}y^{j}z^{k}w^{l}$$

Damit kann man Oberflächen darstellen aber das zu modellieren ist sehr schwierig.

Man kann für diese Funktionen aber den Gradienten berechnen. *Die Normale einer implizt dargestellten Oberfläche zeigt genau in die Richtung des Gradienten.*

Vereinigung von $n$ impliziten Volumen: $\bigcup_{i=1}^{n}g_{i}(p):=\min_{i=1,\dots,n}g_{i}(p)$
Schnitt von $n$ impliziten Volumen: $\bigcap_{i=1}^{n}g_{i}(p):=\max_{i=1,\dots,n}g_{i}(p)$

Smooth blending: $$\begin{align}
f \cup g&=\frac{1}{1+\alpha}\left(f+g-\sqrt{ f^{2}+g^{2}-2 \alpha fg }\right) \\
f \cap g &= \frac{1}{1+\alpha}\left(f+g+\sqrt{ f^{2}+g^{2}-2 \alpha fg }\right)
\end{align}$$
Für $\alpha=1$ erhält man dadurch $\min$ und $\max$ (also kein Smoothing), für kleinere $\alpha$ bekommt man größeres Smoothing.

Die SDFs von mehreren Primitives kann man damit zu immer komplexeren Formen zusammensetzen.

### Sampling von SDFs
Wir haben irgendein Objekt gegeben, z.B. als Mesh, implizite Funktion - irgendwas für das wir ein SDF berechnen können. Das wollen wir jetzt auf effiziente Weise *speichern*, indem wir das SDF *samplen*.
Wenn wir aber irgendwo auf dem Objekt feine Details haben und global regelmäßig samplen, haben wir sehr schnell sehr viele Daten.

**Adaptively Sampled Distance Fields (ADFs)**


## Implizit -> Explizit: Marching Cubes

Der Marching Cubes-Algorithmus wandelt eine implizit gegebene Oberfläche (Isosurface) in eine explizite Darstellung (Dreiecks-Mesh) um.

- Man nimmt einen Würfel
- Jede der 8 Würfelecken ist entweder innerhalb des Objekts oder außerhalb
- Für jede der 256 Kombination von Innen-/Außen-Vertices werden im Würfel entsprechende Oberfläche anhand einer Lookup-Table eingefügt (wegen Symmetrie gibt es genau 15 verschiedene Fälle)

![[Marching Kubus.png]]

Erweiterungen:
- Füge Mesh-Vertices nicht am Mittelpunkt ein, sondern mache lineare Interpolation zwischen sdf-Werten um deren Nulldurchgang zu approximieren
oder
- Berechne Gradienten an jedem Würfel-Vertex, und bestimme Normale der Oberfläche des eingefügten Dreiecks mit linearer Interpolation
oder
- speichere pro Vertex nicht nur einen sdf-Wert (minimale Distanz zur Oberfläche), sondern den Abstand entlang jeder Achse -> bessere lineare Interpolation

Falls Feature-Vertices bekannt sind (z.B. Verlauf einer Kante, die erhalten bleiben soll): füge eine Vertex für dieses Feature ein, mache Triangulation innerhalb des Würfels, und flippe Kanten:
![[Extended_MC.png|550]]

### Dual Contouring
Füge an Würfelkanten keine Punkte, sondern Flächen (Quads) ein:
![[Dual_Contouring.png|450]]

Das ist in 3D ein bisschen schwierig, weil die Schnittkanten der Quads nicht a priori bekannt sind. 
Approximative Lösung:
- Finde Eckpunkt eines Quads durch bilineare Interpolation der Punkte an den Würfelkanten -> vier Punkte
- diese sind aber nicht unbedingt innerhalb einer Ebene -> Fitten einer Ebene mit Least-Squares-Optimierung
![[Dual_Contouring_3D.png|500]]

## Explizit -> Implizit: Fast Marching

???
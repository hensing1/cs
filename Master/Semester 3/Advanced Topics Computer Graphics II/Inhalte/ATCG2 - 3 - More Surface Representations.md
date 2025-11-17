[[atcg2-03-Surface RepresentationsII.pdf]]

## Implizite Darstellungen

Funktion $g(x,y,z)$, sodass:
- $\{ p \in \mathbb{R}^{3} \mid g(p) <0 \}$ das Innere
- $\{ p \in \mathbb{R}^{3} \mid g(p) =0 \}$ die Oberfläche
- $\{ p \in \mathbb{R}^{3} \mid g(p) >0 \}$ das Äußere des Objekts ist.

> [!abstract] Definition *Quadrik*
> Sei $$g(x,y,z)=\sum_{i+j+k=2}a_{ijk}x^{i}y^{j}z^{k}.$$
> Dann erhält man durch $$Q:= \{ p \in \mathbb{R}^{2} \mid g(p)=0 \}$$
> äh, was?

Eine Parabel oder eine Ellipse und das heißt dann Quadrik oder so

Allgemein:

> **Algebraische Oberfläche**
> Für homogene Koordinaten: $$g(x,y,z,w)=\sum_{i+j+k+l=n}a_{ijk}x^{i}y^{j}z^{k}w^{l}$$

Damit kann man Oberflächen darstellen aber das zu modellieren ist sehr schwierig.

Man kann für diese Funktionen aber den Gradienten berechnen. *Die Normale einer implizt dargestellten Oberfläche zeigt genau in die Richtung des Gradienten.*

Vereinigung von $n$ impliziten Volumen: $\bigcup_{i=1}^{n}g_{i}(p):=\min_{i=1,\dots,n}g_{i}(p)$
Schnitt von $n$ impliziten Volumen: $\bigcap_{i=1}^{n}g_{i}(p):=\max_{i=1,\dots,n}g_{i}(p)$

Smooth blending: $$f \cup g=\frac{1}{1+\alpha}\left(f+g-\sqrt{ f^{2}+g^{2}-2 \alpha fg }\right)$$
### Marching Cubes

Der Marching Cubes-Algorithmus wandelt eine implizit gegebene Oberfläche (Isosurface) in eine explizite Darstellung (Dreiecks-Mesh) um.

- Man nimmt einen Würfel
- Jede der 8 Würfelecken ist entweder innerhalb des Objekts oder außerhalb
- Für jede der 256 Kombination von Innen-/Außen-Vertices werden im Würfel entsprechende Oberfläche anhand einer Lookup-Table eingefügt (wegen Symmetrie gibt es genau 15 verschiedene Fälle)

![[Marching Kubus.png]]


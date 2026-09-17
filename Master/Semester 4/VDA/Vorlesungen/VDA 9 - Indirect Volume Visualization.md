[[vda-09-Indirect-Volume-Visualization.pdf]]

Ziele: Oberflächen von Volumen extrahieren, die dann mit traditionellen Renderingmethoden dargestellt werden können


## Isokurven mit Marching Squares

**Marching Squares:** 2D Marching Cubes
Im Falle von Mehrdeutigkeit (gegenüberliegende Ecken haben dasselbe Vorzeichen): Entscheide nach vorbestimmter Regel
- *Mittelpunkt-Entscheider:* bestimme das Vorzeichen vom Mittelpunkt mit bilinearer Interpolation
- *Asymptotischer Entscheider:* bestimme das Vorzeichen am Sattelpunkt (Schnittpunkt der Asymptoten)
	- Anschaulich: finde dieses Kreuz (die zwei Asymptoten), und verbinde die Punkte, die im selben Rechteck liegen: ![[Asymptotic Decider.png|116]]


## Ableitungen finden
Wir wollen den Oberflächengradienten finden, damit wir die Oberfläche shaden können.
Wir können die partiellen x- und y-Ableitungen mit forward bzw. backward bzw. central difference finden.
Forward und backward können höhere Frequenzen in der Ableitung entdecken und sind daher anfälliger für Rauschen.
Noch mehr glätten tut der Sobel-Operator.

3D Sobel: $$\frac{1}{32h} \times \begin{bmatrix}
-1 & 0 & 1 \\
-2 & 0 & 2 \\
-1 & 0 & 1
\end{bmatrix} \begin{bmatrix}
-2 & 0 & 2 \\
-4 & 0 & 4 \\
-2 & 0 & 2
\end{bmatrix} \begin{bmatrix}
-1 & 0 & 1 \\
-2 & 0 & 2 \\
-1 & 0 & 1
\end{bmatrix}$$

Wichtig: will man die Magnitude des Gradienten an einem Punkt zwischen den Grid Points haben, muss man *erst den Gradienten interpolieren*, und dann davon die Magnitude nehmen. 
## Isosurface Extraction

### Contour Tracing
- Volumen in Scheiben schneiden
- Isolinien in jeder Scheibe finden
- Isolinien miteinander verbinden

Funktioniert nicht so gut, wenn hohe Varianz innerhalb der Schieben besteht

### Marching Cubes

Siehe [[ATCG2 - 3 - More Surface Representations#Implizit -> Explizit Marching Cubes|ATCG 2]]

***Marching Tetrahedra:*** Wie Marching Cubes, bloß hat man ein Tetrahedra-Grid
Vorteil: nur zwei Base Cases: entweder ein Punkt verschieden von den anderen, oder zwei
Marching Cubes kann auf Marching Tetrahedra reduziert werden, indem man den Würfel in 5 oder 6 Tetrahedra kleinhaut
Kann auch auf unstrukturierte Grids angewandt werden

## Shading

Wir besprechen nur Phong Shading:
Helligkeit eines Pixels ist
- Ambientes Licht (konstant), plus
- Diffuser Term (Lambert, Kosinus zwischen einfallendem Licht und Normale)
- Specular Term (Kosinus hoch irgendein $n$)

## Post Processing Isosurfaces

### Mesh Smoothing

Laplacian Smoothing
Auch Taubin Smoothing, was wir hier "HC" nennen

### Mesh Decimation

Vertices raus, ohne Topologie zu verändern und Geometrie bestmöglich zu approximieren

Algorithmus:
1. Geometrie und Topologie für einen gegebenen Vertex bestimmen
2. Kriterium anwenden, um zu entscheiden, ob Vertex gelöscht werden kann
3. Ggf. resultierendes Loch re-triangulieren

Klassifizierung von Vertices:
- normal
	- wird gelöscht, wenn Distanz zur durchschnittlichen Ebene der umliegenden Punkte kleiner als ein Threshold ist
- komplex (an nicht-Mannigfaltigkeitspunkten)
	- werden nicht gelöscht
- Teil der Grenze vom Mesh
	- Distanz zur Grenzlinie der umliegenden Punkte berechnen
- Teil einer Feature-Edge
	- Distanz zur Kante zwischen den benachbarten Feature-Vertices berechnen
- Schnittpunkt von Feature-Edges
	- wird nicht gelöscht


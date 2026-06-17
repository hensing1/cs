Ziele: Oberflächen von Volumen extrahieren, die dann mit traditionellen Renderingmethoden dargestellt werden können

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

Phong Shading

## Post Processing Isosurfaces

### Mesh Smoothing

Laplacian Smoothing + HC extension

### Mesh Decimation

Vertices raus


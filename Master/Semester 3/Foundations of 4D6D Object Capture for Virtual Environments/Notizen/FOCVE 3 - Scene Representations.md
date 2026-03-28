[[FOCVE_03_Scene_Representations.pdf]]
## Surface Representations
Wir haben Punktwolken, Surfels, Dreiecksnetze, Voxel, und Constructive Solid Geometry.

### Surfels
- Punktwolke, aber jeder Punkt ist eine Scheibe
	- mit Normale
	- mit Radius

### Polygon Mesh
- Approximation error $\mathcal{O}(h^{2})$: doppelt so viele Vertices bedeutet ca. viermal bessere Approximierung der Oberfläche
- Vertices der Dreiecke ordnen wir *gegen den Uhrzeigersinn* an, damit der Normalenvektor $\frac{(v_{2}-v_{1})\times (v_{3}-v_{1})}{\|(v_{2}-v_{1})\times (v_{3}-v_{1})\|}$ nach außen zeigt
- Wir möchten, dass unser Netz eine Mannigfaltigkeit ist
	- keine zwei geschlossenen oder offenen Fächer an einem Vertex
	- höchstens zwei Dreiecke an einer Kante
- Ein Netz ist "wasserdicht", wenn kein Wasser herausläuft
	- es ist mannigfaltig
	- genau zwei Dreiecke an einer Kanten
- Texturierung mit Bild und Texturkoordinaten entkoppelt Mesh-Auflösung und Textur-Auflösung

### Implicit Surfaces and SDF
Level Surface: für eine Funktion $g: \mathbb{R}^{3} \to \mathbb{R}$ die Menge $\mathcal{I}=\{ p \in \mathbb{R}^{3} \mid g(p)=l \}$ (meistens $l=0$)

Oberflächennormalen: $n \propto \nabla g(p)$

Signed Distance Funktion bestimmt die Distanz zur Oberfläche (innerhalb ist negativ)
Erfüllt die **Eikonal-Gleichung:** $\|\nabla \text{sdf}(p)\|=1$

## Marching Cubes

Konvertierung von impliziter Oberfläche zu Dreiecksnetz
Wir besprechen:
- standard marching cubes
- Verschiebung der Meshpunkte entlang des Grids, um Oberfläche genauer zu approximieren
	- geht mit linearer Interpolation über die Funktionswerte an den Gridpunkten
- Berechnung der Normalen an jedem Vertex
	- Bestimmung des Gradienten durch zentrale Differenz der Gridpunkte
	- Normalisieren, um Normalen zu erhalten
	- Linear interpolieren, um Normalen an Meshpunkten zu erhalten

## Mesh Smoothing

- Laplace-Operator
	- gleichmäßige Gewichtung -> führt zu gleichmäßigeren Dreiecken
- Laplace-Beltrami-Operator
	- Kotangens-Gewichtung -> Glättung erfolgt entgegen der tatsächlichen Krümmung

## Ray Marching und Sphere Tracing

**Ray Marching:**
- sampling entlang eines Strahls in äquidistanten Abständen
- wenn Isofläche getroffen wurde, Sampling in dem entsprechenden Intervall mit kleineren Abständen wiederholen

**Sphere Tracing:**
- Sampling der SDF
- nächsten Schritt so groß setzen wie der Wert der SDF es zulässt
- Oberfläche gefunden, wenn die Schritte sehr klein werden



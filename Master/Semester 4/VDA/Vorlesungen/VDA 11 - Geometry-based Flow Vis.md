[[vda-11-Geometry-Based-Flow-Vis.pdf]]

**Flow Vis:** ein Vektorfeld visualisieren

Ansatz in der Realität: z.B. Wollfäden am Objekt befestigen, die in Richtung des Winds gepustet werden; Injektion von Rauch

*Geometriebasiert:* Geometrie definieren (Kurven oder Oberflächen), die direkt mit dem Flow zusammenhängen und traditionell gerendert werden können; kann physikalische Visualisierungen (s.o.) nachbilden

## Vektorfelder

können statisch (steady) oder in Bewegung (unsteady) sein.
Bsp. für unsteady vector field: $$v(x,y,t)=\begin{pmatrix}
u(x,y,t) \\
v(x,y,t)
\end{pmatrix}$$
Kann auf einem Grid oder auf unstrukturierten Punkten definiert sein

Flow-Daten bekommen: mit Messungen, oder per Simulation (Navier-Stokes-Gleichungen lösen)

Diskretes -> Kontinuierliches Vektorfeld mittels Interpolation
Interpolation für scattered data: *radial basis functions* (?)

Die Ableitung von einem Vektorfeld ist ein Tensorfeld.
Der Wert von diesem Tensorfeld an einem Punkt $(x,y)$ ist die [[Funktionen#^a487cd|Jacobimatrix]] vom dazugehörigen Vektor.

![[Vektoren#^fc6a9b]]

Ist die Divergenz überall gleich 0, ist das Vektorfeld *inkomprimierbar*.

![[Vektoren#Curl]]

## Vektor Field Glyphs

**Pfeile**
Richtung des Vektorfelds: Richtung des Pfeils
Magnitude des Vektorfelds: Länge/Dicke des Pfeils
Weitere Attribute: Farbe des Pfeils

Man kann mehrere Attribute auch mittels **Layering** darstellen, z.B. Skalarfeld farblich im Hintergrund, Pfeile des Vektorfelds im Vordergrund

**In 3D**
3D-Pfeile mit entsprechendem Shading, damit man weiß in welche Richtung sie zeigen
Vorsicht mit zu vielen Pfeilen im 3D, sonst wird es unübersichtlich

**Gekrümmte Pfeile** mit Extra-Gizmos für mehr Information (die z.B. aus der Jacobi-Matrix abgeleitet wurden)
Mehr Kram pro Pfeil -> noch mehr Vorsicht bei vielen Pfeilen
zB. interaktive Initialisierung/Platzierung

## Charakteristische Kurven

- **Stream Line:** Kurve, die in jedem Punkt 
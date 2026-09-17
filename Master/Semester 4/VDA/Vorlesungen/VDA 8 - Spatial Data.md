[[vda-08-Spatial-Data.pdf]]

Bisher war InfoVis: abstrakte Daten sollen visualisiert werden
Jetzt ist SciVis: Daten sind grundlegend räumlicher Natur

## Arten räumlicher Daten

Grundsätzlich haben wir eine *Domäne*, in dem sich die Datenpunkte befinden (also $\mathbb{R}^{2}$ oder $\mathbb{R}^{3}$), und eine *Data Range*, also die Art von Attributen, die sich an einem bestimmten Punkt in der Domäne befinden. Räumliche Daten sind also eine Funktion $f: \mathbb{R}^{n}\to \mathbb{R}^{m}$.

*Skalarfeld:* $f: \mathbb{R}^{n}\to \mathbb{R}$
*Vektorfeld:* $f: \mathbb{R}^{n}\to \mathbb{R}^{m}$
*Tensorfeld:* $f: \mathbb{R}^{n}\to \mathbb{R}^{m_{1}\times m_{2}}$

## Visualisierungs-Pipelines
Standardisierte Abfolge, wie Daten eingelesen, gefiltert, gemappt und gerendert werden.
Beispiel: VTK (Visualization Toolkit)

Eine Pipeline hat grundsätzlich die folgende Struktur, die wir jetzt nach und nach durchgehen:
![[Vis Pipeline.png|263]]

Eine *Interaktion* ist z.B. Perspektive ändern, Visualisierung wechseln, Daten filtern
*Filtering* ist cropping und denoising, aber auch Erstellen von Isolinien, Pfeilen, Symbolen etc.
*Mapping* erstellt die tatsächlichen Meshes, Linien, etc.
*Rendering* ist z.B. Direct Volume Rendering
## Datenstrukturen & Grids

Die zu visualisierenden Daten sind als *Datenpunkte in 2 oder 3 Dimensionen* vorhanden.

Datenpunkte haben entweder eine Konnektivität, oder nicht.

Positionen der Punkte bestimmt die *Geometrie*
Konnektivität der Punkte bestimmt die *Topologie*

### Strukturierte Grids
Haben reguläre *Toplogie*, aber nicht unbedingt reguläre *Geometrie* (Punkte können rumwabern, solange sich die Kanten nicht verändern)

Topologie z.B. aneinandergereihte Parallelogramme

- **Kartesisches Netz** - gleichmäßiges Netz (2D oder 3D) mit *isotropischen* Pixeln oder Voxeln
- **Uniform Grid** - Abstand gleichmäßig pro Dimension (rechtecke Erlaubt). Pixel und Voxel sind *anisotropisch*. Theoretisch müssen die Achsen nicht mal rechtwinklich zueinander sein
- **Rectilinear Grid** - Abstände können auch entlang Achse irregulär sein
- **Curvilinear Grid** - Topologie immer noch wie beim kartesischen (implizit), aber Vertices können irgendwo sein
### Unstrukturierte Grids
Haben zusätzlich irreguläre Topologie - Puntke können wie auch immer verbunden sein (z.B. als Resultat einer Triangulierung)

Vorteile: weniger Elemente benötigt, um gesamte Domain abzudecken
Nachteile: alle Gridpunkte und alle Konnektivitäten müssen separat gespeichert werden, Datenstruktur muss effizientes Abklappern erlauben

Speichern als Dreiecksnetz, z.B. als [[CG - VL 4#Indizierte Dreiecke|indizierte Dreiecke]]

## Interpolierung

Bi/Trinileare Interpolation zwischen Gridpunkten, wie baryzentrische Koordinaten

Konvolutionsbasierte Interpolierung:
- Diskrete Messpunkte sind ein Dirac Train: $g(x)=\sum_{i=1}^{n}y_{i}\delta(x-x_{i})$
- Interpolation zwischen den Dirac-Punkten kann nun als Konvolution mit einem Kernel interpretiert werden

Kernel für nearest-neighbor: $w(x)=\begin{cases}1 & \text{falls}\ x \in [-0.5, 0.5)\\0 & \text{sonst}\end{cases}$
Kernel für lineare Interpolation: Zelt von -1 bis 1
Kernel für Catmull-Rom: Positiv für $|x|<1$, negative Tails für $1<|x|<2$
Kernel für cubic B-Spline hat $w(0)<1$, interpoliert also nicht

Die Kernel für 2D ergeben sich als äußeres Produkt aus den 1D-Kerneln (2D ist also separabel)

Es gibt pre-filtering für cubic B-Splines, sodass man hinterher einen interpolierenden Spline hat

## Koordinatensystem-Transformation

Bei einem strukturierten Grid gibt es, weil Speicher eindimensional ist, eine "fast axis" (Index der sich beim iterieren durch den linearen Speicher schnell ändert) und eine "slow axis" (index der sich nur nach jeder Zeile / jeder Ebene ändert).

Eine Matrix heißt "row major", wenn die Zeile die schnelle Achse ist (Zeilenindex kommt zuerst), und "column major", wenn entlang der Spalte die schnelle Achse ist.

## Slicing
ist der häufigste Modus, wenn 3D-Daten angezeigt werden sollen

Windowing: zeige nur eine Range der Werte an, clampe die übrigen Werte

Housfield Units: Einheiten für die Skalarfelder aus Computertomographie - reicht von -1024 bis 3071. Verschiedene Gewebe manifestieren sich als verschiednee Ranges von Hounsfield Units. Wasser hat eine HU von 0.
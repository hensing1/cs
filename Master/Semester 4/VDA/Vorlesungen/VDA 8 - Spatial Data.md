[[vda-08-Spatial-Data.pdf]]

SciVis: Daten sind grundlegend räumlicher Natur -> Darstellung, Interaktion, etc.

3D Skalarfelder, 3D Vektoren, 2D/3D Tensoren

## Datenstrukturen & Grids

Die zu visualisierenden Daten sind als *Datenpunkte in 2 oder 3 Dimensionen* vorhanden.

Datenpunkte haben entweder eine Konnektivität, oder nicht.

Positionen der Punkte bestimmt die *Geometrie*
Konnektivität der Punkte bestimmt die *Topologie*


- Z.B. Resultat von Triangulierung 

### VTK File Format

## Interpolierung

Bi/Trinilear
Analog zu baryzentrischen Koordinaten

Konvolution
Es gibt pre-filtering für Catmull-Rom, sodass man hinterher einen interpolierenden Spline hat

## Koordinaten-Transform


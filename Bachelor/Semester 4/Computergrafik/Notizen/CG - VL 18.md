Datum: 24.06.
[[cgintro-17-(10.2) Interpolation.pdf|Folien]]

Flat shading: jedes Polygon bekommt eine Farbe
Gouraut shading: an jedem Vertex wird ein Farbwert ausgerechnet, dann wird über das Dreieck hinweg interpoliert 

HDR-Mapping: verwendet cornsweet-effekt
Der umgekehrte Cornsweet-Effekt heißt Mach-Banding

Phong shading: interpoliere die Normale (müssen danach wieder normiert werden!)

# Schatten
schattenfan in the house

Harte Schatten wenn Lichquelle klein oder weit weg

Jedes Objekt erzeugt ein Schattenpolygon bzgl. Lichquelle
Berechnung von Schattenvolumen nicht wirklich in Gebrauch

## Shadow Mapping

-> am weitesten verbreiteter Ansatz

- funktioniert für jede Geometrie
- für jede Geometrie gleich schnell
- ist nichts anderes als ein Z-Buffer
- Artefakte

Für jeden Punkt berechne ich z-Wert im Bezug zur Lichtquelle
Ist z-Wert von Punkt kleiner/gleich Wert im Z-Buffer, wird er beleuchtet(?)

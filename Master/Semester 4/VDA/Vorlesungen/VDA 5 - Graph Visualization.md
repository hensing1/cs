[[vda-05-Graph-Visualization.pdf]]

## Node-Link Diagrams

Baumknoten sind im Raum verteilt und mit geraden oder gekrümmten Linien miteinander verbunden.

![Star Wars-Verbindungen|300](https://kirellbenzi.com/img/wEtnGCQRKG-960.avif)

*Häufige Designziele:*
- Nodes mit derselben Tiefe sollen dieselbe vertikale Position haben
- Horizontaler Leerraum soll Hierarchie verstärken (Kinder desselben Knotens horizontal gruppieren)
- Fläche minimieren
- Kantenlängen minimieren
- Gutes Seitenverhältnis erzielen

*Ziele für Binärbäume* (nach Reingold/Tilford 1981):
- Elternknoten soll über Kindknoten zentriert sein
- Ein Baum und sein Spiegelbild sollten als Reflektionen voneinander dargestellt werden
- Ein Unterbaum sollte immer gleich dargestellt werden, egal wo im Baum er vorkommt

### Layout-Algorithmen

#### Reingold-Tilford
Rekursive Defintion:
- Annahme: Linker und rechter Subbaum wurden schon gezeichnet
- verschiebe sie horizontal, bis ein bestimmter horizontaler Abstand erreicht wurde
- zentriere Elternknoten zwischen ihnen

Threading:
- 

## Indentation

## Treemaps
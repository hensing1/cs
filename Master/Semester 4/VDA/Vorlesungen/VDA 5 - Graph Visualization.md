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
*Layout von Binärbäumen*

Rekursive Defintion:
- Annahme: Linker und rechter Subbaum wurden schon gezeichnet
- verschiebe sie horizontal, bis ein bestimmter horizontaler Abstand erreicht wurde
- zentriere Elternknoten zwischen ihnen

Threading:
- Kontouren links und rechts verfolgen mit virtuellen Kanten von einem Kontourknoten zum nächsten
- Werden zwei Bäume zusammengefügt, müssen oben (und ggf. unten) neue Threads hinzugefügt werden

Kann für allgemeine Bäume verallgemeinert werden - wenn man aber die Sub-Bäume von links nach rechts verarbeitet, klumpen kleine Sub-Bäume nach links. Man kann sie deshalb mit den Positionen eines Durchgangs von rechts nach links mitteln, ist aber immer noch nicht ideal

#### Walker-Algorithmus
*Layout für beliebige Bäume*

Erweiterung von Reingold-Tilford, bei dem:
- erst versucht wird, neue Sub-Bäume (vlnr) so weit links wie möglich anzubringen,
- wenn aber ein Baum nach rechts verschoben werden muss, wird diese Verschiebung auch auf alle Bäume angewandt, die darüber und dazwischen liegen

Reingold-Tilford kann auch auf Bäume in Polarkoordinaten angewandt werden, die nach außen hin wachsen, wenn das Seitenverhältnis vom normalen Layout zu breit wäre

#### Bubble-Tree Layout
Jeder Node ist ein Bubbel im Zentrum all seiner Kindknoten

## Einzug (Indentation)
Man kennt's von ausklappbaren Listen von Datei-Browsern

## Treemaps
Jeder Node ist ein Rechteck, und die Kinder sind im Rechteck vom Parent

Vorteile:
- Ganzer Baum im Bild, optimierbar für Seitenverhältnis
- Größe eines Nodes direkt ersichtlich
- weitere Attribut leicht hinzuzufügen (z.B. als Farbe)

Nachteil: Tiefe eines (Teil-)Baums nicht direkt ersichtlich

### Simpler Algorithmus
Abwechselnd (je nach Level) vertikal und horizontal den Node teilen
-> kann zu schlechten Seitenverhältnissen eines Nodes führen

### Squarified Treemaps
Optimale Splits sind NP-schwer, also: füge nach und nach Kindsknoten hinzu und nimm greedy den Split der am quadratischsten ist
- ordne Kindsknoten nach Größe
- teile größere Dimension zuerst
so:
![[Squarified Treemap.png|239]]

### Cushion Shading
WinDirStat
bestimme Surface Normals, indem immer weiter "Kissen" auf den jeweiligen root nodes gestapelt werden:
![[Cushion Shading.png]]
Man kann zusätzlich auch noch die größeren Knoten umranden:
![[Cushion Shading 2.png]]

## Sunburst Displays
Gnome Festplattenbelegung
Eine Mischung aus Treemap und radial node link diagram

# Force-Directed Graph Layouts
Wie wenn `Strg-G` in Obsidian

Sind Knoten $i$ und $j$ verbunden, übt $j$ auf $i$ die fogende Kraft $f$ aus:
$$f(p_{i},p_{j})=\underbrace{k_{ij}(\|p_{j}-p_{i}\|-s_{ij})}_{\text{Kraft}} \cdot\underbrace{\frac{p_{j}-p_{i}}{\|p_{j}-p_{i}\|}}_{\text{Richtung}}$$
mit
- Positionen $p_{i},p_{j}$
- bevorzugter Federlänge $k_{ij}$
- Federspannung $s_{ij}$

Hinzukommt abstoßende Kraft zwischen allen Knoten:
$$g(p_{i},p_{j})=-\frac{r_{ij}}{\|p_{j}-p_{i}\|^{2}} \cdot \frac{p_{j}-p_{i}}{\|p_{j}-p_{i}\|}$$

Die werden iterativ berechnet. Die step size ist die "Temperatur", die auch über die Zeit verringert werden kann

Die abstoßenden Kräfte können ab einer bestimmten Distanz auch auf 0 gesetzt werden, um nicht-zusammenhängende Graphen nicht vollständig auseinanderdriften zu lassen und die Berechnung zu beschleunigen

# Matrix Views

Man zeigt die Adjazensmatrix
Bei entsprechender Sortierung sind [[Graphen#^961695|Cliquen]] direkt ersichtlich

Für stark verbundene Subgraphen kann eine Matrix genommen werden, die dann wiederum mit anderen Subgraphen verbunden wird (hybride darstellung aus Matrix und Node-Link-Diagramm)

Für sehr große Graphen kann man rauszoomen und aggregieren

# Edge Bundling
Was wenn sowohl Hierarchie, aber auch (unabhängig davon) Adjazenz zwischen beliebigen Nodes?
-> Edge Bundling: Adjazenz-Kanten, die von nahegelegenen Punkten der Hierarchie ausgehen, werden gebündelt

Idee: male zuerst den Hierarchiegraphen, Adjazenzkanten sind dann [[CG VL 8 - Splines#B-Spline|B-Splines]] mit den Kanten als Kontrollpunkte

Da dadurch Mehrdeutigkeiten entstehen: bewege die Kontrollpunkte als Interpolation zwischen den Hierarchieknoten und der Kante direkt zwischen den adjazenten Knoten. $\beta=1$: Kontrollpunkt direkt an dem Hierarchieknoten, $\beta=0$: Kontrollpunkt direkt auf der Verbindungslinie

- Einzelne Kanten auswählen
- Kanten transparent machen
- Kanten einfärben

Anwendung z.B. in fMRI
Datum: 19.12.

[[ISS10_WS2324_ObjectDetection_231219_231219.pdf|Folien]]

[[ISS_WS2324_Aufgabenblatt10.pdf|Aufgabenblatt]], [[Blatt 10|Lösungen]]

# Objekterkennung

## Merkmale und Merkmalsräume

- Wir betrachten eine Menge von $M$ Merkmalen pro Segment

Ein Merkmal ist ein gutes Merkmal, wenn:
- das within-class-scattering gering ist (Distanz zwischen Merkmalswerten derselben Klasse)
- das between-class-scattering hoch ist (Distanz zwischen Merkmalswerten verschiedener Klassen)

*Within-Class Scatter (Intragruppenvarianz)* $S_{w}$ für eine Segmentmenge $T$ mit $K$ Klassen: 
Mittlerer quadratischer Abstand der Merkmalsvektoren vom jeweiligen Klassenmittelwert.
$$S_{w}=\frac{1}{|T|} \sum_{k=1}^{K}\sum_{s\in T_{k}}\|m(s)-\mu_{k}\|^{2}$$

*Between-Class Scatter* $S_b$: 
Mittlerer quadratischer Abstand der Mittelwerte einzelner Klassen.
$$S_{b}=\frac{1}{\binom{K}{2}}\sum_{k_{1}=1}^{K}\,\sum_{k_{2}=k_{1}+1}^{K}\left\|\mu_{k_{1}}-\mu_{k_{2}}\right\|^2$$


## Formbasierte Merkmale

- Flächeninhalt $F(s)$
- Randlänge $R(s)$
- Kompaktheit: $K(s)=\frac{F(s)}{R(s)^{2}}$
- Kreisähnlichkeit $Kr(s) = \frac{4\pi F(s)}{R^{2}(s)}$
- Bounding Box
- Differenz zwischen Fläche der Konvexen Hülle des Segments und der Segmentfläche
- Schwerpunkt
- Flächenträgheitsmomente $m_x$ und $m_y$: Summierte quadratische Abweichung in $x$- bzw. $y$-Richtung vom Schwerpunkt
- Gemischtes Trägheitsmoment: $m_{xy}(s)=\sum_{(i,j)\in s}(i-i_\mu)(j-j_\mu)$
- Drehwinkel $\alpha$: $\tan(2 \alpha)=2m_{xy}/(m_y-m_x)$

## Anforderungen an Klassifikationsmodelle
- den Segmenten sollen *Bedeutungen* zugeordnet werden
- diesen Entscheidungen sollen *Qualitätsangaben* zugeordnet werden
- die *Wahrscheinlichkeit einer Fehlzuordnung* soll *minimal* sein

## MAP-Klassifikation

> **Maximum-a-Posteriori-Klassifikation:**
> Berechne für ein Segment $s$ die A-Posteriori-Wahrscheinlichkeit, dass es zur Klasse $c_{k}$ gehört, ausgehend vom Merkmalsvektor $m(s)$: $$P(s=c_{k} \mid m(s))$$und wähle für $s$ die Klasse mit der maximalen A-Posteriori-Wahrscheinlichkeit.




Datum: 03.05.
[[cgintro-05-OpenGL-Pipeline.pdf|Folien (Pipeline)]]
[[cgintro-06-Clipping.pdf|Folien (Clipping)]]

# Die OpenGL-Pipeline

Die Bilddaten werden in den **Framebuffer** geschrieben. Der wird dann ausgelesen und auf dem Bildschirm dargestellt.

Zwischen Framebuffer und Bildschirm wird der Pixelwert in einer **Lookup Table** (Farbtafel, LUT) nachgesehen, die die tatsächliche Intensität und Farbe ausgibt.

![[OpenGL#^94ddb2]]

Wir rendern einen Drachen:

- Vertices holen (Vertex Puller):
  ![[Drache1.png|300]]
- Vertexpositionen berechnen (Vertex Shader):
  ![[Drache2.png|300]]
- Dreiecke füllen (Rasterizer):
  ![[Drache3.png|300]]
- Fragments färben (Fragment shader):
  ![[Drache4.png|300]]
- Verdeckung durch andere Objekte berechnen und in Szene einfügen (Output Combiner): ![[Drache5.png|300]] ![[Drache6.png|300]]

Wir besprechen [[OpenGL#Vertex Array Objects|VAO]], [[OpenGL#Vertex Buffers|VBO]] und [[OpenGL#Index Buffers|EBO]].

Man kann die Vertexdaten aus den VBOs ziehen und mit `glDrawArrays(GL_TRIANGLES, ...)`, `glDrawArrays(GL_TRIANGLE_STRIP, ...)` oder `glDrawArrays(GL_TRIANGLE_FAN, ...)` zeichnen - das ist aber ineffizient, weil man viele solcher draw-calls machen muss und Vertexdaten nicht gecacht werden.

Daher verwandelt man lieber mit einem EBO die Strips und Fans in indizierte Dreiecke, und man braucht nur einen draw-Aufruf: `glDrawElements(GL_TRIANGLES, ...);`.

# Clipping

Wir müssen in der Lage sein, Teile eines Polygons abzuschneiden, wenn diese nicht innerhalb einer *Darstellungsfläche (Viewport)* befinden. Das ist Aufgabe vom **Rasterizer**.

## Clipping von Liniensegmenten

Linie zwischen $P_0$ und $P_1$ in Parameterform: $P(t) = P_{0}+t \cdot (P_{1}-P_{0}),\;0\leq t \leq 1.$

Schnitt mit einer vertikalen Clippingkante bei $x=a:$ $t'=\frac{a-x_{0}}{x_{1}-x_{0}}$.
Wenn $t'<0$ oder $t'>1$, oder $x_{1}=x_{0}$ (Linie ist Vertikal), hat man keinen Schnittpunkt.

## Liang-Barsky-Algorithmus

Stelle jede Clippingkante als implizite Gerade zwischen zwei Punkten $Q_0$ und $Q_1$ dar: $$Q_{0}=\begin{pmatrix}x_{0} \\ y_{0}\end{pmatrix},\quad Q_{1}=\begin{pmatrix}x_{1} \\ y_{1}\end{pmatrix}$$
Normalenvektor (zeigt nach Konvention ins Innere): $$n=\begin{pmatrix}\Delta y \\ -\Delta x\end{pmatrix}=\begin{pmatrix}y_{1}-y_{0} \\ x_{0}-x_{1}\end{pmatrix}$$
Für einen Punkt $P$ betrachtet man nun: $$E(P) = \langle n, P \rangle -\langle n, Q_{0} \rangle $$
$E(P)<0$: $P$ liegt außerhalb, $E(P)>0$: $P$ liegt innerhalb, $E(P)=0$: $P$ liegt auf der Geraden.

Wenn nun eine Gerade zwischen $P_0$ und $P_1$ liegt, und $\text{sign}(E(P_{0})) \neq \text{sign}(E(P_{1}))$, gibt es einen Schnittpunkt $P'$.

Durch einsetzen der Geradengleichung von oben in $E$ ergibt sich für den Parameter: $$t=\frac{\langle n, Q_{0} \rangle - \langle n, P_{0} \rangle }{\langle n, P_{1}-P_{0} \rangle }$$
Und damit der Schnittpunkt: $$P'=P_{0}+\frac{\langle n, Q_{0} \rangle - \langle n, P_{0} \rangle }{\langle n, P_{1}-P_{0} \rangle } \cdot (P_{1}-P_{0}).$$
### Erweiterung auf 3D

Die Halbräume sind nun nicht durch Geraden, sondern durch Ebenen definiert.
Die Gleichung der zu clippenden Gerade bleibt unverändert, die Ebene ist wieder implizit durch Punkt und Normale gegeben.

## Cohen-Sutherland-Algorithmus

Jedem Punkt in der Ebene kann ein vierstelliger *Region Outcode* zugeordnet werden:
```
a b c d
| | | +---- links vom Fenster (x < x_min)
| | +------ rechts vom Fenster (x > x_max)
| +-------- unter dem Fenster (y < y_min)
+---------- über dem Fenster (y > y_max)
```

Outcode ist 0 $\to$ Punkt ist innerhalb vom Fenster.

Für Liniensegment zwischen Punkten mit Outcodes $C_0$ nach $C_1$ macht man bitweise Verknüpfungen:
- $C_{0} \land C_{1} \neq 0000 \Rightarrow$ komplett außerhalb
- $C_{0} \lor C_{1} = 0000 \Rightarrow$ komplett innerhalb
- $C_{0} \land C_{1} = 0000 \Rightarrow$ eventuell innerhalb

Nun clipt man an der Kante $i$, für die $(C_{0} \lor C_{1})_{i} \neq 0$ und berechnet neue Outcodes.

> *Bewertung*
> Der Cohen-Sutherland-Algorithmus ist *gut*, wenn die meisten Linien komplett innerhalb oder außerhalb sind.
> Er funktioniert *nicht*, wenn man Polygone clippen will, die eine Ecke des Fensters umschließen (die Ecke muss als neuer Punkt im Polygon dazukommen.

Man kann den Algorithmus auf 3D erweitern, er funktioniert aber nur für Quader (nur parallele und keine perspektivische Perspektiven, letztere haben eine Pyramide als Sichtvolumen).

## Sutherland-Hodgman-Algorithmus

Clippe das komplette Polygon *nacheinander* an den vier Kanten des Fensters.

Gegeben sei das Polygon als Liste von Punkten.

Dafür fangen wir an einer beliebigen Ecke an, überprüfen nacheinander die Polygonkanten und fügen die geclipten Punkte nacheinander in eine neue Liste ein:
- Beide Punkte liegen innen: füge Endpunkt ein
- Nur Endpunkt liegt außerhalb: füge Schnittpunkt ein
- Beide Punkte liegen außen: füge nichts ein
- Startpunkt liegt außerhalb: füge Schnitt- und Endpunkt ein

Wiederhole das ganze dann für die anderen Kanten des Fensters.


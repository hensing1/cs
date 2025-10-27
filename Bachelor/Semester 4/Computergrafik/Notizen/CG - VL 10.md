Datum: 17.05.
[[cgintro-10-Rasteralgorithmen.pdf|Folien]]

# Rasteralgorithmen

Eingabe: Dreiecke, Polygone
Ausgabe: Pixel (werden in *Framebuffer* geschrieben)

Aufgaben:
- Verdeckungsrechnung
- Transparenz
- Shading
- Texturierung

In OpenGL ist im Framebuffer ist die Koordinate (0,0) *links unten*.

## Linien malen
### Algorithmus von Bresenham
Ziel: Gerade zwischen zwei Pixelkoordinaten $a$ und $b$ zeichnen.

*Annahme:* Steigung $m = \Delta x / \Delta y, 0 \leq m \leq 1$.
Falls $m > 1$: spiegele an Gerade $y = x$
Falls $m < 0$: spiegele an $x$-Achse

Die Gerade geht für den Algorithmus also immer nach oben rechts.

![[Bresenham.png]]

Pixelweises Zeichnen der Gerade mit *Entscheidungsvariable:*
Initial:
$$E_{0} := \frac{\Delta y}{\Delta x} - \frac{1}{2}$$
Ist $E \leq 0$, liegt der nächste Pixel rechts oben, ansonsten direkt rechts.

Update der Entscheidungsvariable: $$E_{k+1} = \begin{cases}
E_{k} + \frac{\Delta y}{\Delta x} & \text{falls} & E_{k} \leq 0 \\
E_{k} + \frac{\Delta y}{\Delta x} - 1 & \text{sonst.}
\end{cases}$$

Wir wollen aber Floating-Point-Arithmetik vermeiden und deshalb auf die Berechnung der Steigung verzichten. Wir arbeiten nur mit Integer-Arithmetik:

$$E' = 2 \Delta x \cdot E = 2 \Delta y - \Delta x$$
Entsprechend ist $E'_{k}=2 \Delta x E_{k}$:$$E'_{k+1} = \begin{cases}
E'_{k} + 2 \Delta y & \text{falls} & E_{k} \leq 0 \\
E'_{k} + 2 \Delta y - 2 \Delta x & \text{sonst.}
\end{cases}$$

### Mittelpunktalgorithmus
Annahmen wie beim Bresenham-Algorithmus, es wird als nächster Pixel also immer entweder $(x+1, y)$ oder $(x+1, y+1)$ gewählt.

Entscheidungsfrage: *Liegt der Mittelpunkt der beiden möglichen Pixel oberhalb oder unterhalb der Geraden?*

Implizite Geradengleichung: $$g(x,y) = \Delta y \cdot x - \Delta x \cdot y + (\Delta x \cdot y_{1} - \Delta y \cdot x_{1}).$$
Diese Gleichung ist größer 0, g.d.w. $(x,y)$ oberhalb der Geraden ist.

Also ist die Entscheidung: $$\begin{align*}
g\left(x+1, y + \frac{1}{2}\right)\leq 0 & \implies \text{wähle Pixel }(x+1, y)\\
g\left(x+1, y + \frac{1}{2}\right)> 0 & \implies \text{wähle Pixel }(x+1, y+1).
\end{align*}$$
Inkrementelle Berechnung von nächstem Punkt:
Gegeben: $g_{1}=g(x+1, y + 1/2)$

$g\left(x+2, y+\frac{1}{2}\right)= g_{1}+\Delta y$
$g\left(x+2, y+ \frac{3}{2}\right) = g_{1} + \Delta y - \Delta x$

Je nachdem, ob wir $(x+1, y)$ oder $(x+1, y+1)$ gewählt haben, nehmen wir den ersten bzw. den zweiten Wert.

## Kreise malen

Um einen Kreis zu malen, müssen wir nur einen Oktanten ($1/8$ der Kreisbahn) zeichnen. Der Rest des Kreises entsteht durch Spiegelungen: 
![[Kreis.png]]

Wir malen den *zweiten* Oktant (bei $(y,x)$), denn:
- keine vertikalen Tangenten
- Betrag der Steigung $|m|\leq 1$

Also geht hier auch der Mittelpunktalgorithmus:

Die implizite Kreisgleichung ist $f(x, y) = x^{2} + y^{2} - R^{2}$.
Sei $k_{1} = f\left(x+1, y- \frac{1}{2}\right)$ gegeben. Dann ist analog:

$f\left(x+2, y- \frac{1}{2}\right) = k_{1} + 2x + 3$
$f\left(x+2, y- \frac{3}{2}\right) = k_{1}+2x-2y+5$.

## Linienglättung

Bresenham und Mittelpunktalgorithmus erzeugen bislang nur kantige Linien.

Einfache Glättung :skaliere Grauwert linear entsprechend des vertikalen Abstands zur Linie. Den Abstand erhält man durch dieselbe Rechnung wie für die Entscheidungsvariable.

Außerdem erscheinen schräge Linien dunkler als waage- oder senkrechte Linien (weniger Pixel pro Länge). Einfache Lösung: skaliere Grauwert um $1/\cos\alpha$ (für $|\alpha|\leq 45°$).

## Polygone malen

Die Umlaufzahl für einen Pixel bzgl. eines Polygons besagt, wie häufig die Linie dieses Polygons diesen Pixel im Uhrzeigersinn umkreist (vorausgesetzt, die Polygonkanten verlaufen im Uhrzeigersinn).

Even-Odd-Rule: Pixel, deren Umlaufzahl ungerade ist, werden gezeichnet.
Winding Rule: Pixel, deren Umläufzahl größer null ist, werden gezeichnet.

### Scan-Line-Algorithmus

Wir zeichnen das Polygon zeilenweise nach Even-Odd-Rule.

Ansatz:
- Finde Schnittpunkte der Zeile mit allen Kanten des Polygons
- Sortiere Schnittpunkte aufsteigend anhand x-Koordinate
- v.l.n.r.: Male Pixel nur dann, wenn bislang ungerade Anzahl von Schnittpunkten gesehen

Für Schnittpunkte: verwende Mittelpunktalgorithmus für Linien, um zu sehen ob Pixel innerhalb oder außerhalb des Polygons ist.
Durch den Mittelpunktalgorithmus kann man die Zeile auch in Abschnitte (Spans) unterteilen, die man dann gleichzeitig (z.B. mit `memset`) sehr effizient setzen kann.

Sonderfälle bei aneinanderliegenden Polygonen:
Man muss sich Regeln überlegen, dass man Pixel, die genau an der Grenze zwischen zwei Polygonen liegen, nicht mehrfach anrührt.
- Falls Schnitt ein Floating-Point-Wert: konsistent runden (z.B. zum Inneren des Polygons)
- Falls Schnitt ein Integer-Wert: z.B. linken Punkt des Spans zeichnen, rechten Punkt nicht
- Horizontale Kanten nicht in die Paritätsberechnung einbeziehen

## Dreiecke malen

### Algorithmus von Pineda

Annahme: Normalenvektoren der Kanten zeigen zum Dreiecksinneren

Gegeben: Punkte $P_{1},\,P_{2},\,P_{3}$
Normalenvektor für $\overline{P_{1}P_{2}}$: $n_{12}=\text{norm}(\Delta y_{12},-\Delta x_{12})$ 

Ist nun $E_{12}(x,y) = \langle (x,y)-P_{1}, n_{12} \rangle >0$, liegt der Punkt $(x,y)$ auf derselben Seite der Kante, zu der der Normalenvektor zeigt. 

Ist diese Entscheidungsvariable für alle drei Kanten größer Null, liegt der Punkt im Inneren des Dreiecks.

Inkrementelle Berechnung:
$E_{i}(x+1, y) = E_{i}(x,y) + (\Delta y)_{i}$
$E_{i}(x,y+1) = E_{i}(x,y) - (\Delta x)_{i}$

Nun kann man das Dreieck auf verschiedene Weisen traversieren, zum Beispiel mittels der Bounding Box.

### Baryzentrische Koordinaten (moderne GPUs)

Ansatz: berechne die [[CG - VL 2#Baryzentrische Koordinaten|baryzentrischen Koordinaten]] $\lambda_{1},\lambda_{2},\lambda_{3}$ des Punktes $(x,y)$ bzgl. des Dreiecks.
Gilt $0 \leq \lambda_{i} \leq 1$ für alle $i$, liegt der Punkt im Inneren des Dreiecks.

![[Baryzentrum.png|300]]
$$\lambda_{i}=\frac{A_{i}}{A_1+A_{2}+A_{3}}$$
$$\begin{align*}
A_{1} &= (\vec{P_{3}}-\vec{P_{2}})\times(\vec P - \vec P_{2}) / 2 & \text{(hälfte des Parallelograms)}\\
&= a_{1}x+b_{1}y+c_{1}
\end{align*}$$
Diese Berechnungen kann man wunderbar parallelisieren.

## Grauwerte mit Schwarz-Weiß-Werten (Dithering / Halbtonverfahren)

Wir stellen einen Grauwertpixel durch $(n \times n)$ Schwarz-Weiß-Pixel dar, womit wir also $n^{2}+1$ Grauwerte darstellen können.

$n=2$:
![[Dithering.png]]

Eine $n\times n$ *Dithering-Matrix* gibt an, in welcher Reihenfolge die Pixel gesetzt werden. 
Für einen Grauwert $k \in [0, n^{2}+1]$ werden alle Pixel, die in der Dithering-Matrix den Wert kleiner $k$ haben, auf $1$ gesetzt.

Dithering-Matrix für obiges Beispiel: $D^{2}=\begin{pmatrix}1 & 3 \\ 2 & 0\end{pmatrix}.$


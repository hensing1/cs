Datum: 07.11.
[[ISS04_WS2324_NonlinearFiltering_231107_231107.pdf|Folien]]

[[ISS_WS2324_Aufgabenblatt04.pdf]]

# Nichtlineare Filter

Wir hätten gerne rauschunterdrückende Filter, die *kantenerhaltend* sind. Rauschunterdrückende Lineare Filter haben das Problem, dass Kanten verschmiert werden.
## Medianfilter

Das Medianfilter gehört zu den **Ranordnungsfiltern**. 
Bei Rangordnungsfiltern werden für jeden Pixel alle Umgebungspixel nach ihrer Intensität sortiert, und dann wird irgendeins davon ausgewählt - z.B. das Minimum, das Maximum, oder eben der Median.

Das Medianfilter ist das Mittel der Wahl gegen [[ISS - VL 2#Impulsrauschen|Salt-and-Pepper-Rauschen]], da hier die meisten Pixel ungestört sind.

Damit das Medianfilter *kantenerhaltend* ist, müssen die folgenden Bedingungen erfüllt sein:
1. Konstante Werte auf jeder Seite der Kante
2. Kantensignal ist stärker als Rauschen
3. Die Kante verläuft innerhalb des Filters gerade

Bedingung 3 ist dann erfüllt, wenn man das Medianfilter klein wählt.

Ausnahme: Eckpunkte. Die werden abgerundet, müssen also in einer Nachbearbeitung wiederhergestellt werden.

## Diffusionsfilter

Idee: Simulation des physikalischen Diffusionsprozesses. Die Intensitätswerte werden als Konzentration einer Flüssigkeit oder eines Gases betrachtet, die sich mit der Zeit einander angleichen.

Wir besprechen drei Arten von Diffusionsfiltern:
- **Isotrope Homogene Diffusion**
	- *Gleichmäßiger Ausgleich in alle Richtungen*
	- Effekt ist identisch zum [[ISS - VL 2#Gauß-Filter]], daher ist dieses Filter in der Praxis nutzlos
- **Isotrope Inhomogene Diffusion**
	- *Ausmaß der Diffusion wird geschwächt, wenn eine Kante in der Nähe ist*
- **Anisotrope Diffusion**
	- *Diffusion verläuft in Kantennähe nur parallel zur Kante*

### Allgemeine Schritte des Diffusionsfilters

Das Filter wird iterativ durchgeführt. Je mehr Iterationen, desto länger wird der Diffusionsprozess simuliert.

Pro Iteration $t$ passieren folgende Schritte für jeden Pixel $(x,y)$:
1. Approximiere Intensitätsgradienten in x- und y-Richtung
	- bspw. $\frac{\partial I(x,y,t)}{\partial x} = I(x+1, y) - I(x-1,y)$
	- vgl. [[ISS - VL 3#Sobel-Operator|Gradientenberechnung beim Sobel-Operator]]
2. Berechne Diffusions[[Glossar#Tensor|tensor]] $D$
	- $D$ ist abhängig vom gewählten Diffusionsmodell
3. Berechne Fluss in x- und y-Richtung
	- $\overrightarrow{j}\,(x,y,t)=-D(x,y,t)\cdot \nabla I(x,y,t)$
4. Approximiere Flussgradienten in x- und y-Richtung
	- Berechnung analog zum Intensitätsgradienten
5. Die Divergenz ist die Summe über alle Gradientenwerte
	- $\text{div} \,j(x,y,t)=\frac{\partial j_{x}(x,y,t)}{\partial x}+\frac{\partial j_y(x,y,t)}{\partial y}$
6. Die Divergenz wird von der Intensität abgezogen
	- $I(x,y,t+1)=I(x,y,t) - \text{div} \,j(x,y,t)$

Die *Diffusionsrate* ist abhängig von Diffusionskoeffizient $D$ (meistens $2 \times 2$-Matrix).
Der Fluss ist proportional zum negativen Konzentrationsgradienten (Konzentration soll ja ausgeglichen werden).

### Wahl des Diffusionstensors

#### Isotrope homogene Diffusion

$$D = \begin{pmatrix}\epsilon_{0} & 0 \\ 0 & \epsilon_{0}\end{pmatrix}$$
Der Fluss hängt also lediglich vom Intensitätsgradienten ab, der Diffusionstensor ist konstant.

$\epsilon_0$ beschreibt die Diffusionsrate.

Die isotrope homogene Diffusion ist äquivalent zur Anwendung eines Gauß-Filters mit $\sigma=\sqrt{2t}$.

#### Isotrope inhomogene Diffusion
Idee: Diffusion soll abnehmen, wenn eine Kante in der Nähe ist - d.h., wenn der Gradientenbetrag hoch ist.

$$D=\begin{pmatrix}\epsilon(\|\nabla I\|^{2}) & 0 \\ 0 & \epsilon(\|\nabla I\|^{2}) \end{pmatrix} \quad\text{mit}\quad \epsilon(\|\nabla I\|^{2})=\epsilon_{0} \frac{\lambda^{2}}{\|\nabla I\|^{2}+\lambda^{2}}.$$

Der Parameter $\lambda$ steuert die Abnahme der Diffusion bei steigendem Gradienten:
- kleines $\lambda$: stärkere Kantenerhaltung, Diffusion sinkt rasch in Gebieten mit hohen Gradienten
- großes $\lambda$: schwächere Kantenerhaltung, annäherung an die homogene Diffusion

Problem: das Rauschen in Kantennähe wird nicht stark unterdrückt.

#### Anisotrope Diffusion

Idee: Diffusion in Richtung der Kante soll abnehmen, Diffusion *orthogonal* zur Kante soll konstant bleiben.

Lösung: setze $D$ zusammen aus einer [[Numerik - VL 4#SVD und EVD|Eigenwertzerlegung]].

Erster Eigenvektor: Intensitätsgradient $$e_1=\begin{pmatrix}e_{1,1} \\ e_{1,2}\end{pmatrix}=\frac{\nabla I}{\|\nabla I\|}$$
Zweiter Eigenvektor: orthogonal zum ersten Eigenvektor
$$e_{2}=\begin{pmatrix}e_{2,1} \\ e_{2,2}\end{pmatrix}=\begin{pmatrix}e_{1,2} \\ -e_{1,1}\end{pmatrix}$$

Erster Eigenwert wird skaliert, analog zur isotropen inhomogenen Diffusion
$$\begin{align*}
\lambda_{1}&=\epsilon(\|\nabla I\|^{2}) \\\\
\lambda_{2}&=1\\
\end{align*}$$
$D$ wieder zusammensetzen:
$$D=\begin{pmatrix}e_{1,1} & e_{2,1} \\ e_{1,2} & e_{2,2}\end{pmatrix}\begin{pmatrix}\lambda_{1} & 0 \\ 0 & \lambda_{2}\end{pmatrix}\begin{pmatrix}e_{1,1} & e_{1,2} \\ e_{2,1} & e_{2,2}\end{pmatrix}$$

# Farbbildverarbeitung

## HSI-Farbmodell

- Hue: Farbwert - $H \in [0,2\pi)$
- Saturation: Sättigung, Chroma - $S = 1 - 3 \cdot \frac{\min \set{R,G,B}}{R+G+B}$
- Intensity: Helligkeit - $I = \frac{R+G+B}{3}$

### Darstellung
Man nehme den RGB-Würfel:
![[RGB-Würfel.png]]

und stelle ihn auf die Ecke, sodass die Achse von $(0,0,0)$ nach $(255,255,255)$ senkrecht verläuft:
![[HSI-Doppelkegel.png]]

## Bearbeitung von Farbbildern

Mit dem HSI-Farbmodell hat man einen einzelnen Wert für die Intensität eines Pixels. 

Nun kann man die Bildglättenden Verfahren, die für Einkanalbilder definiert wurden, auch auf Farbbilder anwenden:
- Wandle die RGB-Werte in HSI um
- Wende das Filter auf den I-Kanal an
- Wandle das Resultat zurück in RGB
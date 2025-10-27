Datum: 19.04.
[[cgintro-02-EuklidischeGeometrie.pdf]]
[[cgintro-03-GeometrieRepräsentieren.pdf]]

# Basis und Koordinatensysteme

> [!abstract] Definition *Koordinatensystem*
> Ein *Koordinatensystem* ist ein Tupel aus einem *Ursprung* $0 \in \mathbb{A}^{n}$ und einer *Basis* $(e_{1},\ldots,e_{n})$.
> 
> Ein Punkt $p \in \mathbb{A}^{n}$ hat einen *Ortsvektor* $v = (0,p)$.
> Die Punkte $p_{i} = 0+e_i$ heißen *Einheitspunkte*.
> Das Tupel $(0,p_{1},\ldots,p_{n})$ heißt *affine Basis*.

## Rotation

Wenn wir aus $+\infty$ auf eine Achse schauen, und sich etwas gegen den Uhrzeigersinn um diese Achse dreht, dann ist diese Drehung *mathematisch positiv* um diese Achse.

Rechte-Hand-Regel: Daumen zeigt in die Achsenrichtung, Finger drehen sich positiv um die Achse.

### Rodrigues-Formel

- Sei $(r,\theta),\,\|r\|=1$ die Achse-Winkel-Repräsentation für eine Rotationsmatrix $R$ im $\mathbb{R}^3$.

Dann gilt $\forall v \in \mathbb{R}^3$: $$Rv =\cos \theta v + \sin \theta(r\times v)+(1-\cos \theta)(r \cdot v)r$$

### Rotation mit komplexen Zahlen

> Die Multiplikation mit einer komplexen Zahl $y = e^{i \theta}$ auf dem Einheitskreis entspricht einer Rotation um den Winkel $\theta$.

Ist $\mathfrak{Re}(y)=a$ und $\mathfrak{Im}(y)=b$, dann ist die dazugehörige Rotaionsmatrix $$\text{Rot}_{\theta}=\begin{pmatrix}a & -b \\ b & a\end{pmatrix}.$$

### Rotation mit Quarternionen

> Wir beschreiben Punkte im $\mathbb{R}^3$ mit *reinen Quarternionen* ohne Realteil: $$\mathbb{R}^{3} \ni p = \begin{pmatrix}p_x \\ p_{y} \\ p_z\end{pmatrix} \mapsto p_{x}i + p_{y}j + p_{z}k \in \mathbb{H}$$

Rotation mit Quarternionen funktioniert nun wie folgt: 

Die Rotationsachse sei durch eine reine Einheitsquarternion gegeben: $$r = r_{x}i+r_{y}j+r_{z}k, \quad|r| = r_{x}^2+r_{y}^{2}+r_{z}^{2}=1.$$
Um diese Rotationsachse möchten wir mit Winkel $\theta$ rotieren.

Also setzen wir $$q = e^{\Large\frac{\theta}{2}r} \normalsize= \cos \frac{\theta}{2} + r \cdot \sin \frac{\theta}{2}$$
und erhalten eine neue Quarternion $q$ auf der 4d-Einheitskugel ($|q|=1$).

Ähnlich wie eine Multiplikation mit einer komplexen Zahl auf dem Einheitskreis eine Rotation in der komplexen Ebene beschreibt, kann man mit Einheitsquarternionen eine Rotation im 4d-Quarternionenraum beschreiben: $$p' = q \cdot p \cdot q^{-1},$$ mit $q^{-1} = \cos \frac{\theta}{2} - r \cdot \sin \frac{\theta}{2}$.

Die so konstruierte Quarternion $q$ hat die Eigenart, dass durch diese Multiplikation alle reinen Quarternionen in ihrem Unterraum bleiben, dass also kein Realteil dazukommt. 
Sie bleiben also darstellbar als Punkt im $\mathbb{R}^3$, und werden genau um $\theta$ um die durch $r$ beschriebene Achse rotiert.

# Repräsentation von Objekten und Szenen

*Eplizite Objektdarstellung:* 
Man hat eine Funktion $f: \mathbb{R}^{2} \to \mathbb{R}^{3}$, mit der man alle Punkte auf der Objektoberfläche generiert: $$\vec x = f(u,v)$$
$\rightarrow$ einfach, Punkte zu erzeugen.

*Implizite Objektdarstellung:*
Das Objekt ist eine [[Numerik - VL 13#^2dab39|Niveaumenge]] (genauer eine [Isofläche](https://en.wikipedia.org/wiki/Isosurface)) einer Funktion $g: \mathbb{R}^{3} \to \mathbb{R}$: $$\set{\vec x \mid g(\vec x) = 0}$$
$\to$ einfach, Zugehörigkeit von Punkten zu Objekten zu testen.

## Grundkörper

Wir halten uns einen Zoo von Grundkörpern. Man kann Objekte miteinander vereinen oder voneinander abziehen.
Kann in CAD/CAM verwendet werden. Es ist aber umständlich, damit interessantere Objekte zu generieren.

## Dreiecke

Fast alles in der Computergrafik besteht aus Dreiecksnetzen.

In dieser Vorlesung guckt man auf die "äußere" oder "Vorderseite" eines Dreiecks, wenn die drei Eckpunkte entgegen dem Uhrzeigersinn angeordnet sind.
Die Oberflächennormale zeigt nach außen.

> *Berechnung der Oberflächennormale*
> Gegeben: Eckverteces $\vec x_{0}, \vec x_{1}, \vec x_{2}$
> Dann: $$\vec n = \frac{(\vec x_{1}-\vec x_{0}) \times (\vec x_{2} - \vec x_{0})}{|\vec x_{1}-\vec x_{0}| \cdot |\vec x_{2} - \vec x_{0}|}$$

**Annäherung eines Kreises durch Dreiecke**
- *Positionsfehler* auf dem Rand fällt quadratisch mit Anzahl der Dreiecke
- Fehler der *Normalenvektoren* fällt nur linear
	- gerne Interpoliert man die Normalenvektoren
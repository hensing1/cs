Datum: 15.04.
[[cgintro-02-EuklidischeGeometrie.pdf|Folien]]
# Euklidische Geometrie

Wir betrachten [[Vektoren]] als "*Verschiebungspfeile*" im $\mathbb{R}^{2}$ bzw. $\mathbb{R}^3$.

Wir unterscheiden also zwischen Punkten und Verschiebungen.

Ein Vektorraum mit einem *Ursprung* wird zu einem **Affinen Raum**, der mit $\mathbb{A}^{n}$ beschrieben wird. Seine Elemente sind Punkte.

## Homogene Koordinaten

Homogene Koordinaten vereinigen *Vektorraum* und *Affinen Raum*, können also sowohl Verschiebungen als auch Punkte beschreiben.

Wir erweitern unsere Vektoren um eine Komponente $w$: $$\begin{pmatrix}x \\ y\end{pmatrix} \Rightarrow \begin{pmatrix}x \\ y \\ w\end{pmatrix},\quad \text{bzw.}\quad\begin{pmatrix}x \\ y \\ z\end{pmatrix}\Rightarrow \begin{pmatrix}x \\ y \\ z \\ w\end{pmatrix}$$

Nun interpretieren wir Vektoren mit $w=0$ als *Verschiebung* und welche mit $w=1$ als *Punkte*.

Außerdem definieren wir eine [[Relationen#Äquivalenzrelation|Äquivalenzrelation]] $\asymp$ : $$\begin{pmatrix}x \\ y \\ 1\end{pmatrix}\asymp \begin{pmatrix}cx \\ cy \\ c\end{pmatrix},\, c\neq 0$$ stellen denselben Punkt dar.

Dadurch haben wir:
- Verschiebung + Verschiebung = Verschiebung
- Punkt + Verschiebung = Punkt
- Punkt - Punkt = Verschiebung (falls Werte für $w$ identisch)

Außerdem ist Punkt + Punkt = Mittelpunkt: $$\begin{pmatrix}a \\ b \\ 1\end{pmatrix}+\begin{pmatrix}c \\ d \\ 1\end{pmatrix} = \begin{pmatrix}a+c \\ b+d \\ 2\end{pmatrix}\asymp \begin{pmatrix}(a+c)/2 \\ (b+d)/2 \\ 1\end{pmatrix}.$$
Allgemein ist eine Summe über diese Vektoren der Schwerpunkt.
Man kann diese Vektoren verschieden mit Koeffizienten gewichten, wenn man ihnen verschiedene Massen zuweisen will.

Außerdem erlaubt uns das Ganze, *Translationen* als lineare Transformationen zu betrachten (siehe [[Robotik - VL 4#Transformationsmatrix|Robotik]]).

### Perspektivische Verkürzung

Gegeben: Vektor $(x,y,z)^t$, Projektionszentrum bei $z_0$, Bildebene bei $z_\text{Bild}$
Gesucht: in die Bildebene projizierter Vektor $(x_\text{Bild}, y_\text{Bild}, z_\text{Bild})^t$

![[Projektion.png|600]]

Wegen $\frac{x}{z-z_{0}} = \frac{x_\text{Bild}}{z_\text{Bild}-z_{0}}$ gilt: $$(x,y)_{\text{Bild}} = (x,y) \frac{z_{\text{Bild}}-z_{0}}{z-z_{0}}.$$
Daraus bestimmen wir die Projektionsmatrix $M_{\text{proj},z_{0}}$:
$$M_{\text{proj},z_{0}}(x,y,z) = \begin{pmatrix}\begin{pmatrix}1 & 0 & 0 \\ 0 & 1 & 0 \\ 0 & 0 & 1\end{pmatrix} & \begin{pmatrix}0 \\ 0 \\ 0\end{pmatrix} \\ \begin{pmatrix}0 & 0 & \frac{1}{z_\text{Bild}-z_{0}}\end{pmatrix} & \frac{-z_{0}}{z_\text{Bild}-z_{0}}\end{pmatrix}\begin{pmatrix}x \\ y \\ z \\ 1\end{pmatrix} = \begin{pmatrix}x \\ y \\ z \\ \frac{z-z_{0}}{z_\text{Bild}-z_{0}}\end{pmatrix} \asymp \frac{z_\text{Bild}-z_{0}}{z-z_{0}}(x,y,z) = (x,y,z)_\text{Bild}$$


### Baryzentrische Koordinaten

Anwendungen: Schnittpunktberechnung, Rasterisierung und Interpolation, Texture Mapping, uvm

Gegeben: 
- Dreieck $\Delta(p_{0},p_{1},p_{2})$
- Punkt $p$ in der Ebene des Dreiecks (muss nicht unbedingt vom Dreieck eingeschlossen sein)

Gesucht:
- Gewichte $\rho_{0},\rho_{1},\rho_{2}$ für die Dreieckspunkte $p_{0},p_{1},p_{2}$, sodass $p$ deren *Baryzentrum* wird, und $\sum_{i}\rho_{i}=1$

> **Baryzentrum**
> Das Baryzentrum ist der Schwerpunkt der mit $\rho_{i}$ gewichteten Punkte:
> $$\sum_{i}\rho_{i}\begin{pmatrix}x \\ y \\ 1\end{pmatrix} \asymp \frac{\sum_{i}\rho_{i}\begin{pmatrix}x_{i} \\ y_{i} \\ 1\end{pmatrix}}{\sum_{i}\rho_{i}}$$

Da $\sum_{i}\rho_{i}=1$, gilt $p = \rho_{0}p_{0}+\rho_{1}p_{1}+\rho_{2}p_{2}$.

Lösung: ergibt sich als Anteil der Fläche des von $p_{i}$ gegenüberliegenden Dreiecks: ![[Baryzentrum.png|300]]

$$\rho_{i}=\frac{A_{i}}{A_{0}+A_{1}+A_{2}}.$$

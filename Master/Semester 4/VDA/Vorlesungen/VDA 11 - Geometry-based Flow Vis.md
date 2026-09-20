[[vda-11-Geometry-Based-Flow-Vis.pdf]]

**Flow Vis:** ein Vektorfeld visualisieren

Ansatz in der Realität: z.B. Wollfäden am Objekt befestigen, die in Richtung des Winds gepustet werden; Injektion von Rauch

*Geometriebasiert:* Geometrie definieren (Kurven oder Oberflächen), die direkt mit dem Flow zusammenhängen und traditionell gerendert werden können; kann physikalische Visualisierungen (s.o.) nachbilden

## Vektorfelder

können statisch (steady) oder in Bewegung (unsteady) sein.
Bsp. für unsteady vector field: $$v(x,y,t)=\begin{pmatrix}
u(x,y,t) \\
v(x,y,t)
\end{pmatrix}$$
Kann auf einem Grid oder auf unstrukturierten Punkten definiert sein

Flow-Daten bekommen: mit Messungen, oder per Simulation (Navier-Stokes-Gleichungen lösen)

Diskretes -> Kontinuierliches Vektorfeld mittels Interpolation
Interpolation für scattered data: *radial basis functions* (?)

Die Ableitung von einem Vektorfeld ist ein Tensorfeld.
Der Wert von diesem Tensorfeld an einem Punkt $(x,y)$ ist die [[Funktionen#^a487cd|Jacobimatrix]] vom dazugehörigen Vektor.

![[Vektoren#^fc6a9b]]

Ist die Divergenz überall gleich 0, ist das Vektorfeld *inkomprimierbar*.

![[Vektoren#Curl]]

## Vektor Field Glyphs

**Pfeile**
Richtung des Vektorfelds: Richtung des Pfeils
Magnitude des Vektorfelds: Länge/Dicke des Pfeils
Weitere Attribute: Farbe des Pfeils

Man kann mehrere Attribute auch mittels **Layering** darstellen, z.B. Skalarfeld farblich im Hintergrund, Pfeile des Vektorfelds im Vordergrund

**In 3D**
3D-Pfeile mit entsprechendem Shading, damit man weiß in welche Richtung sie zeigen
Vorsicht mit zu vielen Pfeilen im 3D, sonst wird es unübersichtlich

**Gekrümmte Pfeile** mit Extra-Gizmos für mehr Information (die z.B. aus der Jacobi-Matrix abgeleitet wurden)
Mehr Kram pro Pfeil -> noch mehr Vorsicht bei vielen Pfeilen
zB. interaktive Initialisierung/Platzierung

## Charakteristische Kurven

- **Stream Line:** Kurve, die in jedem Punkt tangenzial zum Vektorfeld ist (generiert für einen fixen Zeitpunkt)
	- für jeden Punkt gibt es genau eine Tangenziallinie, die durch ihn hindurch führt
	- schneiden sich nicht (außer an kritischen Punkten)
	- parametrische Beschreibung normalerweise nicht möglich
- **Path Line:** Pfad, den ein Partikel über die Zeit in einem unstetigem Vektorfeld zurücklegt
	- genau ein Pfad pro Punkt $(x,t)$ in Raum-Zeit
- **Streak Line:** Ort aller Partikel, die über die Zeit hinweg am selben Punkt in das Vektorfeld geworfen wurden
	- viele pro Punkt, je nach Seeding
- **Time line:** Ort aller Partikel, die zum selben Zeitpunkt entlang einer Linie in das Vektorfeld geworfen wurden
	- viele pro Punkt, je nach Seeding

## Stream Line Integration

Ziel: stückweise lineare Approximierung von Stream Line

**Euler-Integration:** Immer den aktuellen Vektor draufaddieren, um zum nächsten Punkt zu kommen: $$x_{i+1}=x_{i}+s \cdot v(x_{i})$$
$s$ ist die step size.
Der Fehler ist in $\mathcal{O}(s^{2})$.

**Second-Order Runge Kutta Integration:** Halben (Euler-)Schritt machen, den Vektor von dort nehmen, und mit diesem Vektor den eigentlichen Schritt (vom Startpunkt aus) machen: $$x_{i+1}=x_{i}+s \cdot v\left( x_{i}+\frac{s}{2} v(x_{i}) \right)$$
Fehler von $\mathcal{O}(s ^{3})$.

**Fourth-Order Runge Kutta Integration** (Standard in vielen Anwendungen): Vektor ist konvexe Kombination von vier Vektoren: $$x_{i+1}=\text{RK4}(x_{i})=x_{i}+s \cdot \left( \frac{v_{1}}{6}+\frac{v_{2}}{3}+\frac{v_{3}}{3}+\frac{v_{4}}{6} \right)$$
mit $v_{1}=v(x_{i}),\quad v_{2}=v\left( x_{i}+\frac{s}{2}v_{1} \right),\quad v_{3}=v\left( x_{i}+\frac{s}{2}v_{2} \right),\quad v_{4}=v(x_{i}+sv_{3}).$

Fehler von $\mathcal{O}(s ^{5})$.

**Adaptive Step Size:** Zwei Punkte samplen: einmal zwei Schritte gehen mit $x_{2}=\text{RK4}(\text{RK4}(x,s),s)$, einmal doppelt so großen Schritt machen mit $x_{1}\text{RK4}=(x, 2s)$.
Falls Fehler $\Delta=\|x_{2}-x_{1}\|$ größer als Toleranz $\tau$, Schrittgröße verkleinern
Sonst: Schritt gehen und $s$ neu schätzen mit $s'=s \cdot \rho \cdot \sqrt[5]{\frac{\tau}{\Delta}}$, mit $\rho<1$ Hyperparameter

**Embedded Runge-Kutta:** Zwei verschieden genaue Integrationsschemata nehmen und deren Differenz nehmen, z.B. $\text{RK5}$ vs. $\text{RK4}$
Effizienter, weil man Zwischenergebnisse vom einen Schema im anderen Schema wiederverwenden kann.

## Stream Line Seeding & Selection

Welche Stream Line nehmen wir denn jetzt?

### 2D
- Einfache Ansätze: An Grid-Punkten starten, evtl. random jitter hinzufügen, zufällig starten
- Image Guided: mit sehr kurzen Stream Lines anfangen und versuchen, möglichst gleichmäßig die Domain mit Stream Lines abzudecken
- Evenly Spaced: Neue Stream Lines in der Nähe von existierenden Stream Lines platzieren
	- Stream Line in beide Richtungen erweitern, bis sie die Domäne verlässt, einen kritischen Punkt findet, oder einer anderen Stream line zu nahe kommt

### 3D
Stream Lines nur dort zeichnen, wo "interessante" Dinge passieren (Verwirbelungen)

Verwirbelungen da, wo Curl groß ist: $\| \nabla \times v \| \geq t$

Wir können die Jakobi-Matrix (Ableitung) vom Vektorfeld in einen *symmetrischen* Teil $S=\frac{1}{2}(J_{v}+J_{v}^{t})$ und einen *antisymmetrischen* Teil $\Omega=\frac{1}{2}(J_{v}-J_{v}^{t})$ aufteilen.

Ist $\|\Omega\|\gg \|S\|$ haben wir viel Vortex
Ist $\|S\|\gg\|\Omega\|$ haben wir viel gleichmäßigen Fluss
*Q-Kriterium:* $Q=\frac{1}{2}(\|\Omega\|^{2}-\|S\|^{2})$
Wir fangen mit unseren Stream Lines dort an, wo $Q$ groß ist (viel Vortex)

Dann machen wir noch nach cleveren Kriterien die Stream Lines mehr oder weniger opak, weil sonst zu unübersichtlich.

## Stream Line Rendering

Als lange Zylinder, oder

man kann auch für Stream Lines Diffuse & Specular Terme definieren (streamlines direkt beleuchten)

## Integral-Oberflächen
Analog zu Kurven kann man auch Oberflächen erzeugen:
- **Stream Surface:** Punkte, die von Seed-Kurve ausgehen, durch stetiges Vektorfeld verfolgen
- **Path Surface:** Punkte, die von Seed-Kurve ausgehen, durch unstetiges Vektorfeld verfolgen
- **Streak Surface:** Kontinuierlich Punkte von einer Seed-Kurve in unstetiges Vektorfeld werfen, dann Snapshot machen
- **Time Surface:** Einmal Puntke in einer Oberfläche seeden, dann Snapshots machen
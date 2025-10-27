Datum: 02.11.
[[Robotik_04_Kinematik.pdf]]

Übung: [[Uebung_03.pdf]]
# Kinematik

- *Vorwärtskinematik:* Mapping vom Konfigurationsraum (verschiedene Anstellwinkel der Gelenke) in den Arbeitsraum (Position der Glieder und des Endeffektors)
- *Rückwärtskinematik:* Mapping vom Arbeitsraum (gewünschte Endposition) in den Konfigurationsraum

## Vorwärtskinematik

### Kette von Starrkörpern
Man hat:
- Eine Basis, welche sich nicht bewegt
- beliebige bewegte Glieder
- Zwei Gelenkarten mit jeweils einem Freiheitsgrad (DOF):
	- Rotation 
	- Lineare Verschiebung 

Durch Hintereinanderschaltung von Gelenken kann man wieder allgemeinere Bewegungen zulassen.

### Konfigurationsparameter

> **Freiheitsgrade**
> Ein beliebiges System kann maximal 6 Freiheitsgrade besitzen: 3 Translationsachsen und 3 Rotationsachsen.

Generalisierte Parameter: Parameter, die voneinander unabhängig sind.
Die Anzahl der Freiheitsgrade der kinematischen Kette ist gleich der Anzahl der generalisierten Parameter.

Uns interessieren insbesondere die Parameter (=Gelenkstellungen), welche die Position und Rotation (=Arbeitskoordinaten) des Endeffektors beschreiben.

### Redundanz
Für jedes Gelenk erlaubt einen weiteren Freiheitsgrad. 
Ist die Anzahl $N$ der Gelenke größer als die Freiheitsgrade $M$ des Endeffektors, heißt der Manipulator *redundant*.

Dann gibt es $N - M$ redundante Freiheitsgrade (= Dimension des [[Lineare Funktionen#Bild und Kern|Nullraums]]). 

### Koordinatensysteme
Die Position eines Punkts ist ein [[Vektorräume|Vektor]] in einem Koordinatensystem.

Will man diese Position nicht nur relativ zum Ursprung, sondern auch relativ zu einem anderen Glied beschreiben, hat man denselben Punkt in verschiedenen Koordinatensystemen.

#### Beschreibung eines Koordinatensystems innerhalb eines anderen

Man habe zwei Koordinatensysteme $\{A\}$ und $\{B\}$. Deren Achsen heißen $\hat X_{A}$, $\hat Y_{A}$ und $\hat Z_{A}$ bzw. $\hat X_{B}$, $\hat Y_{B}$ und $\hat Z_{B}$.

Das System $\set{B}$ *relativ* zu System $\set{A}$ lässt sich wie folgt beschreiben:

**Ursprung von $\set{B}$:** Vektor $^A{P}$  (*Translation* von $\set{B}$ im Verhältnis zu $\set{A}$)

**Achsen von $\set{B}$:**
- drei [[Matrizen#^88ba7f|orthonormale]] Vektoren $^{A}\hat X_B$, $^{A}\hat Y_B$, $^{A}\hat Z_B$ (*Rotation* von $\set{B}$ im Verhältnis zu $\set{A}$)
- Können als *Rotationsmatrix* zusammengefasst werden:$$^{A}_{B}R = \begin{bmatrix}^{A}\hat X_B & ^{A}\hat Y_B & ^{A}\hat Z_B\end{bmatrix}.$$
	- es gilt: $^{B}_{A}R = (\,^{A}_{B}R)^{-1} = (\,^{A}_{B}R)^{t}$ (die Zeilen von $\,^{A}_{B}R$ sind die Achsen von $\set{A}$ in $\set{B}$).

Insgesamt lässt sich also die Ausrichtung von $\set{B}$ mit $\begin{Bmatrix}\,^{A}_{B}R & \,^{A}P\end{Bmatrix}$ beschreiben.
Mapping für einen Vektor $U$: $$^{A}U = \,^{A}_{B}R \cdot\, ^{B}U + \,^{A}P.$$

Berechnung von $^{A}\hat X_{B}$: $$^{A}\hat X_{B} = \begin{bmatrix}\langle \hat X_{B}, \hat X_{A}\rangle \\ \langle \hat X_{B}, \hat Y_{A}\rangle \\ \langle \hat X_{B}, \hat Z_{A}\rangle\end{bmatrix}$$
Für $^{A}P$ schreibt man auch $^{A}P_{B_\text{org}}$ und meint damit "den Vektor zum Ursprung (Origin) von B im Verhältnis zu A".

#### Transformationsmatrix

Das Mapping (inkl. Translation) ist als solches nicht in einer Matrix darstellbar, da mit einer Translation das ganze keine lineare Funktion mehr ist (z.B. würde der Nullvektor nicht auf Null abgebildet werden).

Also erweitert man das Ganze um eine Dimension und erhält eine *homogene Transformationsmatrix:* $$^{A}_{B}T = \begin{bmatrix} & ^{A}_{B}R &  & ^{A}P \\ 0 & \ldots & 0 & 1\end{bmatrix}$$
Jetzt kann man Translation und Rotation mit einer Matrix darstellen: $$\begin{bmatrix}^{A}U \\ 1\end{bmatrix} = \begin{bmatrix} & ^{A}_{B}R &  & ^{A}P \\ 0 & \ldots & 0 & 1\end{bmatrix} \begin{bmatrix}^{B}U \\ 1 \end{bmatrix}.$$
Das Inverse: $$^{A}_{B}T^{-1} = \,^{B}_{A}T = \begin{bmatrix} & ^{B}_{A}R &  & -^{B}_{A}R \,^{A}P \\ 0 & \ldots & 0 & 1\end{bmatrix}$$
Es ist $-^{B}_{A}R \,^{A}P_{B_\text{org}}=\,^{B}P_{A_\text{org}}$.

Interpretationen eines homogener Transformation:
- Beschreibung eines Koordinatensystems
- Ein Mapping von zwischen Koordinatensystemen
- Ein Operator, der eine Eingabe verschiebt und rotiert

### Transformationskette
Man kann mehrere Transformationsmatrizen aneinanderhängen: $$^{A}_{C} T = ^{A}_{B} T \,^{B}_{C} T = \begin{bmatrix} & ^{A}_{B}R\,^{B}_{C}R & & (^{A}_{B}R\,^{B}P_\text{Corg} + \,^{A}P_\text{Borg}) \\ 0 & \ldots & 0 & 1\end{bmatrix}$$
Hängt man jetzt alle Transformationsmatrizen hintereinander, hat man also die Transformationsmatrix vom Endeffektor relativ zur Basis.

## Positionsrepräsentationen
- Kartesisch: $(x,y,z)$
- Zylindrisch: $(\rho, \theta, z)$
- Sphärisch: $(r, \theta, \phi)$

![[Positionsrepräsentationen.png|300]]

## Rotationsdarstellungen

Man will irgendeine komplizierte Rotation beschreiben.

**Absolute Winkel:** Man rotiert immer um die Achse des unveränderten (absoluten) Koordinatensystems.

**Eulerwinkel:** Man rotiert um eine Achse, und dann rotiert man um die *resultierenden* Achsen weiter.

![[Eulerwinkel_vs_Absolute_Winkel.png|450]]

### Berechnung

*(X-Y-Z)-Absolutwinkel:* 
Erst Rotation um $X$ um $\gamma$, dann $Y$ um $\beta$, dann $Z$ um $\alpha$: $$^{A}_{B}R = \,^{A}_{B}R_{XYZ}(\gamma, \beta, \alpha) = R_{Z}(\alpha) \cdot R_{Y}(\beta) \cdot R_{X}(\gamma)$$
ist **äquivalent** zum *(Z-Y-X)-Eulerwinkel* $^{A}_{B}R_{ZY'X''}(\alpha,\beta,\gamma)$ (erst um $Z$ um $\alpha$, dann um $Y'$ um $\beta$, dann um $X''$ um $\gamma$). 

Dies stimmt auch im allgemeinen Fall: eine beliebige Eulerwinkel-Rotation (z.B. auch Z-Y-Z) entspricht einer Rotation um die ursprünglichen Koordinatenachsen, allerdings in umgekehrter Reihenfolge.

$$R_{ZY'Z''}(\alpha, \beta, \gamma) = R_{ZYZ}(\gamma,\beta,\alpha)=R_Z(\alpha)\cdot R_Y(\beta)\cdot R_{Z}(\gamma)$$


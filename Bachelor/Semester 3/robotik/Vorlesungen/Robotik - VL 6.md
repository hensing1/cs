Datum: 16.11.
[[Robotik_06_Differentielle_und_Inverse_Kinematik.pdf|Folien]]

Übung: [[Uebung_05.pdf]]
# Differentielle und Inverse Kinematik

Wir betrachten differenzielle Bewegungen. Das braucht man, wenn man später inverse Kinematik betreiben möchte.

- **Vorwärtskinematik**
	- Berechnung von Endeffektorpose $x$ (Position und Rotation) gemäß Gelenkwinkeln $\theta$
	- $\theta \to x$
- **Differenzielle Kinematik**
	- $\theta + \delta \theta \to x + \delta x$
- Beziehungen:
	- Zwischen Winkeländerung und Posenänderung: $\delta \theta \leftrightarrow \delta x$
	- Zwischen Gelenkgeschwindigkeit und Linear- bzw. Winkelgeschwindigkeit: $\dot \theta \leftrightarrow \dot x$

## Gelenkkoordinaten

Mit $q_{i}$ beschreiben wir eine *Gelenkkoordinate*:
$$q_{i}=\bar{\epsilon}_{i}\theta_{i}+\epsilon_{i}d_{i}$$
mit $\epsilon_i=1$ und $\bar{\epsilon}_i=0$ für Lineargelenke, andersherum für Drehgelenke.

Mit dem Vektor $q$ beschreiben wir die Gesamtheit aller Gelenkparameter: $q=(q_1,q_2,\ldots,q_n)^T$.


## Jakobi-Matrizen

Als Berechnung für einen Vektor von Endeffektorparametern $x$ aus Gelenkparametern $q$ sei die Funktion $f(q)=x$ gegeben: $$\begin{pmatrix}f_1(q) \\ f_2(q) \\ \vdots \\ f_m(q)\end{pmatrix}=\begin{pmatrix}x_1 \\ x_2 \\ \vdots \\ x_m\end{pmatrix}.$$
Die **Jakobi-Matrix** $J \in \mathbb{R}^{m\times n}$ enthält alle partiellen Ableitungen nach den jeweiligen Gelenkparametern: $$\delta x = J(q) \cdot \delta q = \begin{pmatrix}\frac{\partial f_{1}}{\partial q_{1}}(q) & \ldots & \frac{\partial f_{1}}{\partial q_{n}}(q) \\ \vdots & & \vdots \\ \frac{\partial f_{m}}{\partial q_{1}}(q) & \ldots & \frac{\partial f_{m}}{\partial q_{n}}(q)\end{pmatrix}\cdot \delta q.$$
Diese Matrix funktioniert sowohl für differenzielle Kinematik als auch für Geschwindigkeiten.
*Die Werte der Jacobi-Matrix hängen von der momentanen Gelenkkonfiguration ab*.

Diese Matrix hängt von der Konkreten Darstellung der Parameter ab (z.B. kartesische/zylindrische/sphärische Koordinaten, Eulerwinkel/Rationsmatrix/Eulerparameter für Ausrichtung).

Deshalb gibt es die **Basis-Jacobimatrix** $J_{0}$, welche Änderungen der $\dot q$ der Gelenkparameter auf die *Lineargeschwindigkeit* $\nu$[^1] und die *Winkelgeschwindigkeit* $\omega$[^2] abbildet: $$\begin{pmatrix}\nu \\ \omega\end{pmatrix}_{(6 \times 1)} = J_{0}(q)_{(6 \times n)}\dot q_{(n \times 1)}.$$

[^1]: gegeben als $\begin{pmatrix}\Delta x & \Delta y & \Delta z\end{pmatrix}^{t}$
[^2]: gegeben als Winkelgeschwindigkeit relativ zu den einzelnen Koordinatenachsen

Für die Basis-Jacobimatrix wird auch gerne die tiefgestellte Null weggelassen.

Die Matrix für die Umrechnungen aus $\nu$ und $\omega$ in Positions- und Rotationsrepräsentationen $\dot x_{P}$ und $\dot x_{R}$ nennen wir $E_{P}$ und $E_R$: $$\begin{align*}
\dot x_{P}&=E_{P}(x_P)\nu\\
\dot x_{R}&=E_{R}(x_{R})\omega.
\end{align*}$$
Dann können wir die Jacobi-Matrix $J_x$ bezüglich dieser Repräsentationen mithilfe von $E_P$ und $E_R$ und der Basis-Jacobimatrix $J_0=\begin{pmatrix}J_{\nu} \\ J_\omega\end{pmatrix}$ berechnen:
$$J_{x}=\begin{pmatrix}J_{x_{P}} \\ J_{x_{R}}\end{pmatrix} = \begin{pmatrix}E_{P} & 0 \\ 0 & E_{R}\end{pmatrix} \begin{pmatrix}J_\nu \\ J_\omega\end{pmatrix}.$$

### Positionsrepräsentationen

- Kartesische Koordinaten: $E_{P}(x, y, z)=I_3$
- Zylindrische Koordinaten:
	- $x= \rho \cos \theta$, $y=\rho \sin \theta$
	- $E_{P}(\rho, \theta, z) = \begin{pmatrix}\frac{\partial \rho}{\partial x} & \frac{\partial \rho}{\partial y} & 0 \\ \frac{\partial \theta}{\partial x} & \frac{\partial \theta}{\partial y} & 0 \\ 0 & 0 & 1\end{pmatrix} = \begin{pmatrix}\cos \theta & \sin \theta & 0 \\ \frac{-\sin \theta}{\rho} & \frac{\cos \theta}{\rho} & 0 \\ 0 & 0 & 1\end{pmatrix}$
	- $\to \begin{pmatrix}\dot \rho \\ \dot \theta \\ \dot z\end{pmatrix}=E_{P}(\rho, \theta, z) \cdot \begin{pmatrix}\dot x \\ \dot y \\ \dot z\end{pmatrix}$
	- Sehr hohe Winkelgeschwindigkeiten ($\dot \theta$) in der Nähe der Z-Achse
- Sphärische Koordinaten:
	- $x=r \cos \theta \sin \varphi$, $y = r \sin \theta \sin \varphi$, $z=r \cos \theta$
	- $E_{P}(r, \theta, \varphi) = \begin{pmatrix}\cos \theta \sin \varphi & \sin \theta \sin \varphi & \cos \varphi \\ \frac{-\sin \theta}{r \sin \varphi} & \frac{\cos \theta}{r \sin \varphi} & 0 \\ \frac{\cos \theta \cos \varphi}{r} & \frac{\sin \theta \cos \varphi}{r} & \frac{-\sin \varphi}{r}\end{pmatrix}$

### Rotationsbewegung

Gegeben sei Punkt mit Vektor $P$, welcher um eine Achse mit Vektor $\Omega$ rotiert (die Achse verläuft durch den Urspung).
$\Omega$ ist gleichzeitig der Vektor, der die Winkelgeschwindigkeiten pro Koordinatenachse angibt.
- Rotationsgeschwindigkeit: gegeben als $\|\Omega\|$
- Distanz von $P$ zur Achse: $\|P \sin \varphi \|$
	- $\varphi$ ist der Winkel zwischen $P$ und $\Omega$

> Lineargeschwindigkeit wird berechnet mit *Kreuzprodukt:* $$\nu_{P}=\Omega \times P$$

Es gilt: $\nu_{P} \,\bot\, \Omega$ und $\nu_{P}\,\bot\, P$.

> **Berechnung vom Kreuzprodukt**
> $$a \times b = \hat ab = \begin{pmatrix}0 & -a_{z} & a_{y} \\ a_{z} & 0 & -a_{x} \\ -a_{y} & a_{x} & 0\end{pmatrix}\begin{pmatrix}b_x \\ b_y \\ b_z\end{pmatrix}$$
> Es gilt: $$a \times b = \|a\|\cdot\|b\|\sin \theta \,n$$mit $\theta$ als Winkel zwischen $a$ und $b$ und $n$ als Einheitsvektor orthogonal zu $a$ und $b$.
> 
> Es ist $\|a \times b\|$ gleich der Fläche des Parallelogramms, das durch $a$ und $b$ aufgespannt wird.

^a9b165


### Geschwindigkeitspropagierung

Wir haben entweder ein Linear- oder ein Rotationsgelenk.

Das Koordinatensystem des Gelenks $i$ ist im Punkt $P_i$ verankert und bewegt sich mit Lineargeschwindigkeit $\nu_i$ und Winkelgeschwindigkeit $\omega_i$.
Das Gelenk verschiebt entweder entlang der Z-Achse oder rotiert um die Z-Achse (siehe [[Robotik - VL 5#Denavit-Hartenberg-Parameter|DH-Parameter]]).

Wir Bezeichnen mit $Z_{i}$ die Z-Achse von Gelenk $i$ relativ zum Ursprungskoordinatensystem: $$Z_{i}=\,^{0}Z_{i} = \,^{0}_{i}R \cdot\,^{i}Z_{i} = \,^{0}_{i}R \cdot \begin{pmatrix}0 & 0 & 1\end{pmatrix}^{t}$$mit $^{0}_{i}R = \,^{0}_{1}R \cdot \,^{1}_{2}R \cdot \ldots \cdot \,^{i-1}_{i}R$ als Rotationsmatrix des Koordinatensystems.

#### Winkelgeschwindigkeit
Aggregation der Rotationsgeschwindigkeiten aller Achsen: $$\omega_{i}=\omega_{i-1}+\Omega_{i} = \sum_{k=1}^{i}\Omega_{k}=\sum_{k=1}^{i}\dot \theta_{k} \,^{0}Z_{k}$$
Über Gelenkparameter ausgedrückt: $\omega_{i}=\sum_{k=1}^{i}\bar\epsilon_{k}Z_{k}\dot q_{k}$
$\to$ Jacobimatrix: $\omega = J_{\omega} \dot q = \begin{pmatrix}\bar \epsilon_{1}Z_{1} & ... & \bar\epsilon_{n}Z_{n}\end{pmatrix} \begin{pmatrix}\dot q_{1} \\ \vdots \\ \dot q_n\end{pmatrix}$


#### Lineargeschwindigkeit
$$\nu_{i}=\nu_{i-1} + \omega_{i-1} \times P_{i} + \dot d_{i} \cdot Z_{i}$$
Mit Gelenkparametern: $\nu_{i}= \sum_{k=1}^{i}[\epsilon_{k}Z_{k}+\bar \epsilon_{k}(Z_{k}\times P_{ki})]\dot q_{k}$
Beachte: $P_{ki}$ ist Vektor von Gelenk $k$ zu Gelenk $i$

$\to$ Jacobimatrix: $\nu= J_{\nu}\,\dot q = \begin{pmatrix}\epsilon_{1}Z_{1}+\bar \epsilon_{1}(Z_{1}\times P_{1n}) & \ldots &  \end{pmatrix} \cdot \begin{pmatrix}\dot q_{1} \\ \vdots \\ \dot q_{n}\end{pmatrix}$

### Direkte Differentation

Die Jacobimatrix für die Lineargeschwindigkeit lässt sich auch als Differentation der Vorwärtskinematik beschreiben (siehe oben, nur als Geschwindigkeit ausgedrückt): $$\nu=\begin{pmatrix}\dot x \\ \dot y \\ \dot z\end{pmatrix} = \dot x_{P} = \frac{\partial x_{P}}{\partial q_{1}} \cdot \dot q_{1} + \ldots + \frac{\partial x_{P}}{\partial q_{n}} \cdot \dot q_{n} \Rightarrow J_{\nu} = \begin{pmatrix}\frac{\partial x_{P}}{\partial q_{1}} & \ldots & \frac{\partial x_{P}}{\partial q_{n}}\end{pmatrix}$$
### Jacobimatrix des Endeffektors

Bislang haben wir die Jacobimatrix für alle $n$ Gelenke. Der Endeffektor $e$ ist aber (normalerweise) nicht direkt an einem Gelenk, sondern hat einen gewissen Offset $P_{ne}$ davon.

$$\nu_{e} = \nu_{n} + \omega_{n} \times P_{ne} = v_{n} - P_{ne} \times \omega_{n}$$
Die Winkelgeschwindigkeit bleibt gleich: $$\omega_{e} = \omega_{n}$$

Mit der Kreuzproduktmatrix ergibt sich: $$\begin{pmatrix}\nu_{e} \\ \omega_{e}\end{pmatrix} = \begin{pmatrix}I & -\hat P_{ne} \\ 0 & I\end{pmatrix} \begin{pmatrix}\nu_{n} \\ \omega_{n}\end{pmatrix}$$

Und die Jacobimatrix: $$^{0}J_{e} = \begin{pmatrix}I & -\hat P_{ne} \\ 0 & I\end{pmatrix} \,^{0}J_{n}$$
Ausgehend von der Jacobimatrix in Frame $\set{n}$, d.h. $^{n}J_{n}$ , muss man noch durch die Gegend rotieren: $$^{0}J_{e} = \begin{pmatrix}^{0}_{n}R & -\,^{0}_{n}R^{n} \,^{n}\hat P_{ne} \,^{n}_{0}R \\ 0 & ^{0}_{n}R\end{pmatrix} \,^{n}J_{n}$$

## Inverse Kinematik mit inverser Jacobimatrix

Die Jacobimatrix linearisiert (durch die Ableitungen) die Beziehung zwischen Änderungen der Gelenkwinkel $\delta \theta$ und Änderungen der Endeffektorpose $\delta x$ an der Stelle $\theta$: $$\delta x = J(\theta)\delta \theta.$$
Wenn man die Jacobimatrix also invertiert, kann man für ein Stückchen, um das man den Roboterarm in eine Richtung $\delta x$ bewegen will, die erforderlichen Änderungen der Gelenkwinkel berechnen: $$\delta \theta = J^{-1}(\theta)\delta x.$$

Ablauf:
- Berechne Endeffektorpose durch Vorwärtskinematik: $x = f(\theta)$
- Bestimme Differenz zu gewünschter Pose $x_{d}$: $\delta x = x_{d}-x$
- Benötigte Änderung der Gelenkwinkel: $\delta \theta = J^{-1} \delta x$
- Neue Gelenkwinkel: $\theta^{+} = \theta + \delta \theta$

Einschränkungen:
- Dieser Ansatz funktioniert nur bei langsamen Bewegung
- Es wird keine Dynamik berücksichtigt
### Kinematische Singularität

Eine Kinematische Singularität hat man erreicht, wenn der Endeffektor nicht mehr in alle Richtungen inkrementell bewegt werden kann.
Beispiel:
- Arm ist voll ausgestreckt $\to$ kann nicht mehr weiter wegbewegt werden
- (Planarer) Arm ist voll angewinkelt $\to$ kann nicht in Richtung Gelenk bewegt werden

> Eine kinematische Singularität tritt dann ein, wenn die [[Matrizen#Determinante|Determinante]] der Jacobi-Matrix gleich 0 ist. Sie ist dann nicht mehr invertierbar.
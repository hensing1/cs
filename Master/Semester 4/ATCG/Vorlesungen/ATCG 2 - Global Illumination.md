[[atcg1-02-Global_Illumination_Problem.pdf]]

**BSSRDF**
*Bidirectional Scattering Surface Reflectance Distribution Function*
- 12-dimensionale Funktion:
	- Eingangs- und Ausfallspunkt auf der Oberfläche (2x2 Freiheitsgrade)
	- Richtung des Lichtvektors (2x2 Freiheitsgrade)
	- Wellenlänge (2x1 Freiheitsgrad)
	- Zeitpunkt des Eintritts/Ausfalls (2x1 Freiheitsgrad)
- sehr schwer zu messen -> Messungen parallelisieren

Für BSDF: ignorieren von Zeitdifferenz (keine Phosphoreszenz), Wellenlängendifferenz (keine Fluoreszenz), Beschränkung der Wellenlängen (z.B. RGB), und Eingangspunkt = Ausfallspunkt (kein subsurface scattering)
-> 6-dimensional

$$f_{\text{BSDF}}(\theta_{i}, \phi_{i}, \mathbf{x}, \theta_{o}, \phi_{o})=\frac{dL_{o}(\theta_{i},\phi_{i},\mathbf{x},\theta_{o},\phi_{o})}{dE_{i}(\theta_{i},\phi_{i},\mathbf{x})} \left[ \frac{1}{\mathbf{sr}} \right]$$
mit:
- $\theta \in [0, 180°]$ Winkel zur Normalen (eingeschlossen Transmittance)
- $\phi \in [0, 360°)$ Himmelsrichtung
- $\mathbf{x}$ Punkt auf der Oberfläche
- $L_{o}$ reflektierte Radianz
- $E_{i}$ eingehende Irradianz

Aufteilen der BSDF in Reflektionsteil (BRDF) und Transmittance-Teil (BTDF).

**Beschreibung von BSDF/BRDF/BTDF**

Renderinggleichung:
![[CG - VL 4#^b35b91]]

Raumrichtung $\omega$ besteht aus den Winkeln $\theta$ und $\phi$ (s.o.).

$f$ ist die BSDF von oben, hier also zusätzlich abhängig von $\vec{x}$.
$\langle \vec{w_{i}} \mid \vec{n} \rangle$ ist der *Kosinus-Term* abhängig vom Winkel des einfallenden Lichts ($\cos(\theta_{i})$). Denn: der differenzielle Lichtstrahl verteilt sich über eine größere Fläche, je nach Winkel.

## Light Transport Equation

Grundlegende Annahme: *Licht verändert sich entlang des Strahls nicht*, also ist das einfallende Licht aus einer Richtung das ausgehende Licht am anderen Ende des Strahls: $$L_{i}(x, \omega_{i})=L_{o}(h(x, \omega_{i}), -\omega_{i}).$$
$h(x, \omega_{i})$ ist die *ray casting function*, die uns den Punkt gibt (auf einer Oberfläche in der Szene), von dem aus der Strahl losgeschickt werden muss, damit er am Punkt $x$ aus der Richtung $\omega_{i}$ ankommt. 

Die Renderinggleichung umformuliert, sodass nur noch ausgehendes Licht darin vorkommt, heißt **Light Transport Equation** (LTE): $$L_{o}(x, \omega_{o})=L_{e}(x, \omega_{o})+ \int_{\Omega}f_{\text{BSDF}}(\omega_{i},x,\omega_{o})L_{o}(h(x, \omega_{i}), -\omega_{i})\cos(\theta_{i})d \,\omega_{i}.$$
Wir können das ganze jetzt umschreiben als Lichtmenge, die von einem Punkt $x'$ zu einem anderen Punkt $x$ geworfen wird: $$L_{o}(x', \omega_{o})=L_{o}(x', x-x') =: L_{o}(x' \to x)$$
Mit dem einfallenden Licht $L_{i}(x', \omega_{i}) = L_{i}(x', x'-x'') =: L_{i}(x' \leftarrow x'')$ ist es ganauso. Die BSDF können wir dann auch schreiben als $f_{\text{BSDF}}(x'' \to x' \to x) := f_{\text{BSDF}}(\omega_{i},x',\omega_{o})$.

Weitere Zutaten:
- Anstatt differenzieller Richtung brauchen wir eine differenzielle *Fläche*, die Licht abgibt und über die wir integrieren können. Die Umwandlung ist: $$d \omega_{i}=\frac{\cos(\theta_{i})}{\|x''-x'\|^{2}}dA(x'')$$
	- $dA(x'')$ ist die Fläche, die mit dem abgebenden Punkt $x''$ assoziiert ist
	- Kosinusterm wegen siehe oben
	- Raumwinkel, den die Oberfläche einnimmt, wird proportional zur quadrierten Distanz kleiner
- Wir nennen $V(x'' \leftrightarrow x')$ den Term, der uns sagt, ob $x''$ von $x'$ aus überhaupt sichtbar ist (kann mit ray casting function $h(x', x''-x')$ ausgewertet werden)
- Für Lesbarkeit definieren wir den Geometrieterm $$G(x'' \leftrightarrow x'):= V(x'' \leftrightarrow x')  \frac{\cos(\theta_{i})\cos(\theta_{o})}{\|x''-x'\|^{2}}$$

Die LTE in diesem Kontext ausgedrückt: $$L(x' \to x)=L_{e}(x' \to x) + \int_{S}f_{\text{BSDF}}(x'' \to x' \to x)L(x' \leftarrow x'') G(x'' \leftrightarrow x') \, dA(x'').$$
Wir integrieren also über jeden einzelnen Punkt $x''$ in der Szene $S$.

Als kompakte Schreibweise fassen wir das Integral über die Szene als Integral-Operator $T$ zusammen. $L$ ist alles Licht in der Szene, und $TL$ ist das reflektierte Licht:

$$L=L_{e}+TL$$
Umgeschrieben: $L=(I-T)^{-1}L_{e}$ - um den gesamten Lichttransport zu bestimmen, müssen wir also $(I-T)$ bestimmen und invertieren.

### Radiocity Method

Wir wollen $I-T$ als Matrix darstellen.

Wir nehmen dafür erst mal an, dass alle Oberflächen diffus sind - die BSDF hängt also nur vom Oberflächenpunkt $x$ ab, aber nicht von Eingangs- oder Ausgangswinkel.
$$f_{\text{BSDF}}(\omega_{i},x,\omega_{o})=f_{\text{BSDF}}(x)$$
[^1]
Das machen wir, damit wir den BSDF-Term aus dem Integral der Renderinggleichung rausziehen können. Dann beschreibt das Integral nämlich nur noch einfallende *Radiocity* (Irradianz) ($\frac{W}{m^{2}}$).[^2]

Damit alles die Einheit der Radianz hat (Gesamtlichtmenge, die von einem Punkt in die gesamte Halbkugel abgestrahlt wird), mutliplizieren wir den Rest einmal mit $\pi$ (Halbkugel in Einheit Steradian ($sr$)): 
$$L(x)\pi=L_{e}(x)\pi+f_{\text{BSDF}}(x)\pi \int_{S}L(x')G(x \leftrightarrow x')\,dA(x')$$


Radiance in diffusen Oberflächen: 2-Dimensional (nur Oberfläche, kein Ausfallswinkel)

Innerhalb eines Dreiecks: Radiosity ist konstant
Galerkin-Methode: Fehler durch lineare approximierung minimieren

Oberfläche in diskrete Elemente unterteilen
Luminence des $i$-ten Elements: Step-Funktion, die nur auf dem $i$-ten Element positiv ist

$G(x \leftrightarrow x')$: Light exchange zwischen $x$ und $x'$

diagonally dominant Matrix: Hauptgewichtung auf Diagonale, Summe der übrigen Elemente auf derselben Zeile ist größer -1
Deshalb $\|T\|<1$ und deshalb $\lim_{ n \to \infty }T^{n}=0$
$T^{0}L_{e}=L_{e}$: direkte Emission, $T^{1}L_{e}$: nach einer Reflektion, $T^{2}L_{e}$ nach zwei Reflektionen, ...

Vergleich mit analytischer Lösung: $T^{n}$ ist ein $2n$-dimensionales Integral

> We work in path space

Integration über Pfade

$TL_{e}$ enthält keine Geometrie, also keine Schatten

Notation für Pfade (LSDSE usw)

## Tray Racing

Ray-Dreieck-Intersection

[^1]: (In der Renderinggleichung gibt es den Cosinus-Term für den Einfallswinkel natürlich trotzdem.)

[^2]: normalerweise beschreibt die Renderinggleichung die Radianz ($\frac{W}{m^{2}sr}$).

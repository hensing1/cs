[[atcg1-02-Global_Illumination_Problem.pdf]]

- BSSRDF - 12dimensionale Funktion
	- sehr schwer zu messen -> Messungen parallelisieren

**Beschreibung von BSDF/BRDF/BTDF**

Renderinggleichung
Cosinus-Term: Differenzieller Lichtstrahl verteilt sich über eine größere Fläche, je nach Winkel

Light Transport Equation: irgendwie mit Punkten
## Light Transport Equation

$$L=L_{e}+TL$$
$T$: Integral-Operator
$TL$: Function on the surface in space - the reflected part

### Radiocity Method
Alle Oberflächen diffus
Für diffuse Oberflächen (*lambertsch*) ist die BSDF *unabhängig von Eingangs- und Ausgangswinkel*: 
$$f_{\text{BSDF}}(\omega_{i},x,\omega_{o})=f_{\text{BSDF}}(x)$$

In der Renderinggleichung gibt es den Cosinus-Term für den Einfallswinkel natürlich trotzdem.

Radiosity $M$: total radiant power per unit area leaving a surface

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

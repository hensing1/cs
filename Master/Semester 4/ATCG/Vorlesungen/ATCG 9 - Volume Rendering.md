[[atcg1-09-Volume_Rendering.pdf]]

## Volume Rendering Equation herleiten

- Licht wird akkumuliert entlang eines Strahls

Ohne Absorptionsterm:

$$(\omega \cdot \nabla )L(x, \omega)=\sigma_{a}(x)L_{e}(x, \omega)$$

$\omega \cdot \nabla$: Richtungsableitung nach Omega (siehe Nabla-Operator)
$L$: akkumulierte Lichtmenge
$L_{e}$: Lichtquelle
$\sigma_{a}$: Proportionalitätskoeffizient, oft 1

Das ist eine Differenzialgleichung, die gelöst wird durch $$L(x_{0}+s \omega, \omega)=L(x_{0},\omega)+\int_{0}^{s}\sigma_{a}(x_{0}+t\omega)L_{e}(x_{0}+t\omega,\omega)\,dt$$
Zusätzlich Absorptionsterm mit $-\sigma_{a}L(x, \omega)$ und Scatteringterm mit $-\sigma_{s}L(x, \omega)$
zusammengefasst als "extinction coefficient" $\sigma_{t}(x, \omega)=\sigma_{a}(x, \omega)+\sigma_{s}(x, \omega)$, auch genannt Opazität

Lösung für extinction term: $$L(x_{0}+s\omega,\omega)=L(x_{0},\omega) \cdot e^{-\tau(x_{0},x)}$$
mit $$\tau(x_{0}, x=x_{0}+s\omega)=\int_{0}^{s}\sigma_{t}(x_{0}+t\omega)\,dt$$
die "kumulierte" optische Dichte von $0$ bis $s$.

Beide Dgl. zusammengenommen: $$(\omega \cdot \nabla )L(x, \omega)=\sigma_{a}(x)L_{e}(x, \omega)-\sigma_{t}(x)L(x, \omega)$$
heißt "inhomogene lineare gewöhnliche Differenzialgleichung" und kann mit einer Methode namens **variation of constants** gelöst werden.

Dann kommt folgendes bei raus: $$L(x_{0}+s \omega,\omega)=L(x_{0},\omega) \cdot e^{-\tau(x_{0},x)}+\int_{0}^{s}e^{-\tau(x_{0}+t\omega, x_{0}+s\omega)}\sigma_{a}(x_{0}+t\omega)L_{e}(x_{0}+t\omega,\omega)\,dt$$
innerhalb des Integrals: Lichtverlust von $t$ bis $s$

Schließlich haben wir noch in-scattering, welches denselben Koeffizienten $\sigma_{s}$ erhält wie das Out-Scattering: $$(\omega \cdot \nabla)L(x, \omega)=\sigma_{s}(x)\int_{\Omega}p(x, \omega', \omega)L_{i}(x, \omega')\,d\omega'$$
$p(x, \omega', \omega)$ ist dabei die *medium phase function*, die beschreibt, wie wahrscheinlich es ist, dass Licht von der Richtung $\omega'$ in Richtung $\omega$ umgelenkt wird.
Sie ist dimensionslos und normalisiert, dh. ihr Integral über die Kugel $\Omega$ ist 1.

Diese drei Differenzialgleichungen zusammengenommen ergeben nun also die **Radiative Transfer Equation** (RTE):
> $$(\omega \cdot \nabla)L(x, \omega)=\sigma_{a}(x)L_{e}(x, \omega)-\sigma_{t}(x)L(x, \omega)+\sigma_{s}(x)\int_{\Omega}p(x, \omega', \omega)L_{i}(x, \omega')\,d\omega'$$

Je nach Medium hat man verschiedene phase functions $p$.
Die meisten Medien sind *isotropisch*, dh. die phase function hängt nur von dem Winkel $\langle w' \mid w \rangle=\cos \theta$ ab.
Die einfachste ist die uniforme Funktion $p \equiv \frac{1}{4 \pi}$, es gibt aber auch z.B. die parametrisierte Funktion nach Henyey und Greenstein. Eine Approximation davon von Schlick et al. wird wegen höherer Effizienz gerne in der Computergrafik genutzt.

Schreiben wir nun das Integral für In-Scattering rechts in der RTE als $L_{s}(x', \omega)$ und die *Transmittance* $e^{-\tau(x', x)}$ als $T(x_{0},x)$, und lösen die RTE als Diff.gl., erhalten wir die **Volume Rendering Equation** (VRE):
> $$L(x, \omega)=L(x_{0},\omega)T(x_{0}, x)+\int_{0}^{s}T(x',x)[\sigma_{a}(x')L_{e}(x',\omega)+\sigma_{s}(x')L_{s}(x',\omega)]\,dt$$

## Volume Rendering Equation lösen

Wir schätzen die Helligkeit eines Pixels $j$ als $$L_{j}\approx \frac{1}{N}\sum_{i=1}^{N} \frac{f_{j}(\bar{x}_{i})}{p(\bar{x}_{i})}$$
wobei $\bar{x}_{i}$ ein Pfad durch die Szene von $j$ aus durch die Szene ist, $f_{j}(\bar{x}_{i})$ dessen Lichtfluss, und $p$ die dazugehörige W'keitsdichtefunktion.

stückweise konstante Opazität
-> alpha blending

lösen mit path integral

## Estimating Transmittance along a ray

### Distance sampling

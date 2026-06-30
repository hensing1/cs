[[atcg1-09-Volume_Rendering.pdf]]

- Licht wird akkumuliert entlang eines Strahls

Ohne Absorptionsterm:

$$(\omega \cdot \nabla )L(x, \omega)=\sigma_{a}(x)L_{e}(x, \omega)$$

$\omega \cdot \nabla$: Richtungsableitung nach Omega (siehe Nabla-Operator)
$L$: akkumulierte Lichtmenge
$L_{e}$: Lichtquelle
$\sigma_{a}$: Proportionalitätskoeffizient, oft 1

Das ist eine Differenzialgleichung, die gelöst wird durch $$L(x_{0}+s \omega, \omega)=L(x_{0},\omega)+\int_{0}^{s}\sigma_{a}(x_{0}+t\omega)L_{e}(x_{0}+t\omega,\omega)\,dt$$
Zusätzlich Absorptionsterm mit $-\sigma_{s}L(x, \omega)$ und Scatteringterm mit $-\sigma_{a}L(x, \omega)$
zusammengefasst als "extinction coefficient" $\sigma_{t}(x, \omega)=\sigma_{a}(x, \omega)+\sigma_{s}(x, \omega)$, auch genannt Opazität

Lösung für extinction term: $$L(x_{0}+s\omega,\omega)=L(x_{0},\omega) \cdot e^{-\tau(x_{0},x)}$$
mit $$\tau(x_{0}, x=x_{0}+s\omega)=\int_{0}^{s}\sigma_{t}(x_{0}+t\omega)\,dt$$

Beide Dgl. zusammengenommen: $$(\omega \cdot \nabla )L(x, \omega)=\sigma_{a}(x)L_{e}(x, \omega)-\sigma_{t}(x)L(x, \omega)$$
heißt "inhomogene lineare gewöhnliche Differenzialgleichung" und kann mit einer Methode namens **variation of constants** gelöst werden.

Dann kommt folgendes bei raus: $$L(x_{0}+s \omega,\omega)=L(x_{0},\omega) \cdot e^{-\tau(x_{0},x)}+\int_{0}^{s}e^{-\tau(x_{0}+t\omega, x_{0}+s\omega)}\sigma_{a}(x_{0}+t\omega)L_{e}(x_{0}+t\omega,\omega)\,dt$$
innerhalb des Integrals: Lichtverlust von $t$ bis $s$
aber noch kein In-Scattering

das ist dann drin in der *radiative transfer equation* (RTE)

stückweise konstante Opazität
-> alpha blending

lösen mit path integral

## Estimating Transmittance along a ray

### Distance sampling

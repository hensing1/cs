- Helmholtz-Reziprozität
	- $f_{\text{BRDF}}(\Omega_{i},x,\Omega_{o})=f_{\text{BRDF}}(\Omega_{o},x,\Omega_{i})$
- Physically Plausible
	- kein Licht wird durch reflektierende Oberfläche generiert
- Albedo: Farbe ("optical response"), wenn Oberfläche gleichmäßig aus allen Richtungen beleuchtet wird

*Diffuse BRDF:* Licht wird gleichmäßig in alle Richtungen reflektiert - $f_{\text{BRDF}}=c$
*Mirror-like BRDF:* $f_{\text{BRDF}}(l, v)= c \cdot \frac{\delta(1-\langle r \mid v \rangle)}{\cos(\theta_{i})}$

Delta: $\int g(x)\delta(x)\,dx=g(0)$

Fresnel-Gleichungen
Reflektanz abh. von Wellenlänge und von Einfallswinkel
zwei verschiedene Gleichungen für horizontale und vertikale Polarisierung

Fresnel reflectance: $\kappa_{s}=F(\lambda, \theta_{i})=\frac{F_{\perp}(\lambda,\theta_{i})^{2}+F_{\parallel}(\lambda,\theta_{i})^{2}}{2}$

$n_{i}$ refraction index
$n_{t}$ transmittence index

$\kappa_{s}=F=\left( \frac{n_{t}-n_{i}}{n_{t}+n_{i}} \right)^{2}$
$\kappa_{t}=T=\frac{4n_{t}\text{irgendwas}}{(n_{t}+n_{i})^{2}}$

Kamera: bei jeder Linse 4% zurückreflektiert -> Lens Flare

*Gauss-BRDF:* $\delta$ durch Gauss ersetzen
- nur sinnvoll für kleine $\sigma$
- nicht mehr physikbasiert

*Phong-BRDF:*
- Kosinus von Abweichung vom idealen Reflektanzwinkel hoch irgendeine Potenz
- nicht physikbasiert
- nicht reziprok
- 
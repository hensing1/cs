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
	- $f_{\text{BRDF}}(l, v)=\kappa_{s}\cdot \frac{\langle r \mid v \rangle^{m}}{\cos(\theta_{i})}=\kappa_{s} \cdot \frac{\langle r \mid v \rangle^{m}}{\langle l \mid n \rangle}$
	- $r$ ist der genau reflektierte Vektor von $l$ an der Oberfläche
- nicht physikbasiert
- nicht reziprok

reziproke Phong-BRDF:
$$f_{\text{BRDF}}(l, v)=\kappa_{s} \cdot \langle r \mid v \rangle ^{m}$$


$r=(I-2nn^{t})l$

damit reziprok: "reflektanz"-Matrix muss symmetrisch sein

$f_{\text{BRDF}}(l, v)=\kappa_{s} \cdot (l^{T}Mv)^{m}$

Lafortune-BRDF: Wahrscheinlichkeiten beliebig entlang Achsen anpassen - W'keit für Reflektion innerhalb Ebene wesentlich höher

### Microfacet-based BRDF

Annahme: Oberfläche besteht aus ganz vielen kleinen, perfekt spiegelnden, irregulär angeordneten Facetten

Drei Effekte:
- Normale der Facette weicht von der Oberflächennormale ab
	- Damit von $\omega_{i}$ nach $\omega_{o}$ reflektiert wird, muss die Facette die Normale $h=\frac{\omega_{i}+\omega_{o}}{\|\omega_{i}+\omega_{o}\|}$ (halfway vector)
- Manche in die richtige richtung reflektierten Strahlen werden von anderen Facetten *maskiert*
- Manche Facetten sind im *Schatten* (inverser Effekt von Maskierung)

insgesamt: $$w(\omega_{i},\omega_{o}) \,d \omega_{o}=Pr(\text{orientation}) \cdot Pr(\text{no shadowing or masking}) \cdot Pr(\text{reflection})$$
#### Cook-Torrance shadowing function

$Pr(\text{no masking}) = \frac{\cos(\beta)+\cos(\beta+2 \alpha)}{\cos(\beta)}$ und Gedöns

hängt nicht vom Winkel der Mikrofacette ab, sondern von Normale $n$ und Einfalls- und Ausgangswinkel $\omega_{i},\ \omega_{o}$

## Oren-Nayar

Der Mond zum Beispiel ist überhaupt nicht Lambertsch, da die Oberfläche sehr rauh ist.

Unterschied zu Microfacets: Oberfläche ist *diffus*, kein Spiegel


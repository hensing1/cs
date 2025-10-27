Datum: 07.06.
[[cgintro-12-Lokale Beleuchtungsmodelle.pdf|Folien]] (S. 21 bis Ende)

# Renderinggleichung und BRDFs

Einfallendes Licht wird teilweise von der Oberfläche absorbiert, unterhalb der Oberfläche gestreut, und irgendwo wieder abgegeben. Um das zu modellieren, gibt es die **BSSRDF** (Bidirectional Scattering Surface Reflectance Distribution Function) mit 8 Parametern. Diese beschreibt einen Proportionalitätsfaktor, den man mit dem einfallenden Licht verrechnet, um das austretende Licht zu berechnen.

Das ist aber kompliziert, also verwendet man lieber die **BRDF** (Bidirectional Reflectance Distribution Function) 4 Dimensionen, die nur *reine Reflexion* an der opaken Oberfläche modelliert.

Wenn man noch Rotationssymmetrie voraussetzt, hat man eine **isotropische BRDF** (3 Dimensionen).

Mit lambertschen Material wird alles Richtungsunabhängig, und es bleibt eine einzige Grundfarbe (Albedo).

Mit einer BRDF ergibt sich für den ==Reflexionsteil der Renderinggleichung== (Reflexionsgleichung):
$$L_{r}(x, \Omega_{r}) = \int_{\text{Halbraum} \,\Omega_{i}}\rho(x, \Omega_{r}, \Omega_{i}) \cdot L_{i}(x, \Omega_{i}) \cdot \cos(\theta_{i}) \,d \omega_{i}$$
mit:
- $\rho$ als BRDF, abhängig von Oberflächenposition $x$ sowie einfallender und ausgehender Richtung
- $L_i$ die einfallende Radianz
- $d \omega_{i}$ dem einfallenden differentiellen Raumwinkel

## Eigenschaften von BRDFs

**Helmholtz-Reziprozität**
- Die Reflektanz ändert sich nicht, wenn man die Strahlrichtung umkehrt
	- Praktisch für Raytracing, da man die Strahlen von der Kamera ausgehend berechnet
	
**Positivität**
- BRDFs sind immer positiv (es gibt kein negatives Licht)

**Anisotropie**
- Das reflektierte Licht ändert sich, wenn man die Oberfläche um ihre normale Dreht
	- z.B. bei Stoffen oder bestimmten Lacken
	
**Energieerhaltung**
$$\int_{\Omega_{r}} \rho(x, \Omega_{r},\Omega_{i})\cos(\theta_{r})\,d \omega_{r}\leq 1$$
$\to$ eine Oberfläche kann nicht mehr Licht reflektieren, als sie erhält

*Annahmen*
- Wellenlängen bleiben erhalten (keine Fluoreszenz)
- Licht wird sofort reflektiert (keine Phosphoreszenz)
- Lichttransport zwischen zwei Objekten erfolgt im Vakuum

## Arten von BRDFs

Mit BRDFs können modelliert werden:
- ideal diffuse (lambertsche) Oberflächen
- gerichtet diffuse Oberflächen
- grob spiegelnde Oberflächen
- ideal spiegelnde Oberflächen

Transmission (transparente Objekte) kann man genauso beschreiben, dann heißt es BTDF.

*Spekulare Highlights* entstehen, wenn Lichtquellen grob in hauptsächlich eine Richtung gespiegelt werden. Das modelliert man durch die Addition von diffusem Anteil $r_d$ mit spekularem Anteil $r_s$.
**Phong-BRDF:** $\rho = \frac{r_{d}}{\pi} + r_{s} \cdot \frac{\cos(\gamma)^{m}}{\cos(\theta_{r})}$
- $\gamma$: Winkel zwischen idealem Ausfallswinkel (gespiegeltem Einfallswinkel) und betrachtetem Ausfallswinkel
- je höher $m$, desto kleiner die spekularen Highlights

**Blinn-Phong-BRDF:** Rechne anstatt mit $\gamma$ mit Winkel zwischen Normalenvektor und Halbvektor von Einfalls- und Betrachtungsvektor. Das ganze ist dann irgendwie weniger aufwändig zu berechnen und ist physikgetreuer unter flachen Winkeln.

Probleme mit (Blinn-)Phong:
- nicht reziprok (Ein- und Ausfallsstrahl nicht vertauschbar)
- keine Energieerhaltung

**Cosine-Lobe-BRDF:** energieerhaltende Blinn-Phong

**LaFortune:** verallgemeinertes Cosine-Lobe-Modell, welches reziprok ist und mehrere spekulare Highlights pro Lichtstrahl erlaubt

**Torrence-Sparrow-Modell**
- Annahme: Oberfläche besitzt spiegelnde, mikroskopisch kleine V-förmige Facetten, die beliebig orientiert sind
	- $\to$ Selbstabschattung unter spitzen Einfallswinkeln
- das ermöglicht eine realistische Modellierung von Fresnel-Termen (Spiegelung unter flachen Winkeln)

*Problem:*
Diffuse BRDFs reichen nicht aus, um matte Oberflächen (Mond z.B.) zu modellieren.
Es können nur glatte Oberflächen dargestellt werden - je rauher die Oberfläche, desto flacher erscheint das Objekt.


*Erweiterte BRDF:* **Oren-Nayar**
Deckt ab:
- Selbstabschattung wie bei Torrence-Sparrow
- Interreflexionen (Mehrfachreflexionen in Mikrofacetten)
- Mikrofacetten nicht mehr spiegelnd, sondern diffus

> **Insgesamt**
> 
> |               | glatt                | rauh             |
> | ------------- | -------------------- | ---------------- |
> | spekular      | ideal spekulare BRDF | Torrance-Sparrow |
> | matt (diffus) | ideal diffuse BRDF   | Oren-Nayar       |


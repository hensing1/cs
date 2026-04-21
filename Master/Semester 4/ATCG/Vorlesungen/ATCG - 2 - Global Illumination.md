[[atcg1-02-Global_Illumination_Problem.pdf]]

- BSSRDF - 12dimensionale Funktion
	- sehr schwer zu messen -> Messungen parallelisieren

**Beschreibung von BSDF/BRDF/BTDF**

Renderinggleichung
Cosinus-Term: Differenzieller Lichtstrahl verteilt sich über eine größere Fläche, je nach Winkel

Light Transport Equation: irgendwie mit Punkten

## Radiocity Method
Für diffuse Oberflächen (*lambertsch*) ist die BSDF *unabhängig von Eingangs- und Ausgangswinkel*: 
$$f_{\text{BSDF}}(\omega_{i},x,\omega_{o})=f_{\text{BSDF}}(x)$$

In der Renderinggleichung gibt es den Cosinus-Term für den Einfallswinkel natürlich trotzdem.

Radiosity $M$: total radiant power per unit area leaving a surface
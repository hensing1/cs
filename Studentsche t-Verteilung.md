"Student's t-distribution"

Die Studentsche t-Verteilung ist eine parametrisierte Wahrscheinlichkeitsverteilung. 

Der Parameter $\nu$ bestimmt, wie schnell die Kurve nach 0 abfällt. 
Für $\nu=1$ erhält man die [[Cauchy-Verteilung]], die sehr langsam abfällt ("heavy-tailed");
für $\nu\to\infty$ erhält man die [[Gauss-Funktion|Gauß-Verteilung]].

Wahrscheinlichkeitsdichtefunktion:
$$f_{\nu}(x)=\frac{\Gamma\left( \frac{n+1}{2} \right)}{\sqrt{ \nu \pi }\Gamma\left( \frac{n}{2} \right)}\left( 1+\frac{x^{2}}{\nu} \right)^{- \frac{\nu+1}{2}}$$
mit $$\Gamma(x)=\int_{0}^{\infty}t^{x-1}e^{-t}\,dt.$$

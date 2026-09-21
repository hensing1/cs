[[vda-15-Ridges-and-Valleys.pdf]]

Definition von Ridge (Grat): über Separatrizen (siehe [[VDA 13 - Feature-Based Flow Vis]]), oder einfach über Gradienten (s.u.)

Anwendung für 3D-Skalarfelder, wo die Oberfläche als lokales Maximum definiert ist (nicht als Nulldurchlauf, den man für Marching Cubes bräuchte)

## Height Ridges
Leicht anders zu Wasserscheiden (lokal statt global): wenn Gradient rechtwinklig zur stärksten Krümmung nach unten ist, ist man auf einem Grat.

Konkret: betrachte Gradienten $g$ und Eigenvektoren der Hesse-Matrix (zweite Ableitung vom Skalarfeld). Ist der zweite Eigenvektor senkrecht zu $g$ und $\lambda_{2}<0$, dann ist man auf einem Grat.

Analog kann man ein Tal definieren, dann ist es der erste Eigenvektor und $\lambda_{1}>0$.

Das geht genauso in 3D:
- nur dritten EV betrachten -> Ridge Surface
- zweiten und dritten EV -> Ridge Line


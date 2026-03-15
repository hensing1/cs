[[FOCVE_09_Neural_Radiance_Fields.pdf]]

## Differenzieller Lichtstrahl

Anstatt *Surface Rendering*: mehr von der plenoptischen Funktion modellieren, insb. durchscheinende Objekte

Betrachtung von **Differenziellem Lichtstrahl** und dessen Interaktion mit Materie:

- Lichstrahl parametrisiert mit $z$
- Position: $x(z)$
- Richtung: $v$
- Leuchtkraft: $L(x(z), v)$

- Absorption
	- Lichstrahl wird um Faktor $\mu_{a}$ abgeschwächt (W.keitsdichte der Absorption)
	- $\frac{dL(x(z), v)}{dz}=-\mu_{a}(x(z))L(x(z), v)$
- Emission
	- Lichtstrahl wird um $\mu_{a}$ verstärkt
		- Derselbe Koeffizient, denn Emission ist Absorption rückwärts
	- $\frac{dL(x(z), v)}{dz}=\mu_{a}(x(z))L_{e}(x(z), v)$
- Brechung
	- Out-Scattering: Lichtstrahl wird um $-\mu_{s}$ abgeschwächt
		- $\frac{dL(x(z), v)}{dz}=-\mu_{s}(x(z))L(x(z), v)$
	- In-Scattering: Strahlen aus anderen Richtungen verstärken Licht um $\mu_{s}$
		- $\frac{dL(x(z), v)}{dz}=\mu_{s}(x(z))L_{s}(x(z), v)$
		- $L_{s}(x(z), v)=\int_{S^{2}}f_{\text{phase}}(x(z), l, v)L(x(z), l)\,dl$

Die **Radiative Transfer Equation** ist die Summe aus diesen vier Termen und beschreibt die Veränderung des Lichtstrahls an einem Punkt vollständig.

## Volume Rendering

Scattering ist (wie die Renderinggleichung für Oberflächen) rekursiv, deshalb schmeißen wir die weg und beschränken uns bei Neural Radience Fields (NeRFs) nur auf Emission und Absorption.

**Andere Notation:**
- Lichtstrahl geht von der Kamera aus, also in die *andere Richtung*

Lichtstrahl: $r(t):=x(-z)$
Emission: $\sigma(r(t)):=\mu_{a}(x(-z))$, notiert kürzer als $\sigma(t)$
Leuchtkraft an einem Punkt in Richtung $d$: $\hat{C}(r(t), d):=L(x(-z),v)$, notiert als $\hat{C}(t)$

Lichtdurchlässigkeit (Transmittance) von Punkt $a$ nach Punkt $b$: $$T(a \to b)=\exp\left( -\int_{a}^{b}\sigma(u)\,du \right)$$


# Blatt 7

- Henning Lehmann

## Aufgabe 1

Eine Ortsbasis für $2 \times 2$-Bilder ist $(b_0,b_1,b_2,b_3)$ mit 
$$b_{0}(i,j) = \left\{\begin{align*}1 &\quad\text{falls}\,i=j=0\\0 &\quad\text{sonst}\end{align*}\right.
$$
$$
b_{1}(i,j) = \left\{\begin{align*}1 &\quad\text{falls}\,i=0,\,j=1\\0 &\quad\text{sonst}\end{align*}\right.
$$
$$
b_{2}(i,j) = \left\{\begin{align*}1 &\quad\text{falls}\,i=1,\,j=0\\0 &\quad\text{sonst}\end{align*}\right.
$$
$$
b_{3}(i,j) = \left\{\begin{align*}1 &\quad\text{falls}\,i=j=1\\0 &\quad\text{sonst.}\end{align*}\right.
$$


## Aufgabe 3

$$\begin{align*}
f_{1}(0)&=\cos(0)+i \cdot \sin(0)&=1\\
f_{1}(1)&=\cos\left(\frac{2}{3}\pi\right)+i \cdot \sin\left(\frac{2}{3}\pi\right)&=-\frac{1}{2}+ \frac{\sqrt{3}}{2}i\\
f_{1}(2)&=\cos\left(\frac{3}{2}\pi\right)+i \cdot \sin\left(\frac{3}{2}\pi\right)&=-\frac{1}{2}- \frac{\sqrt{3}}{2}i\\
f_{1}(3)&=\cos(2\pi)+i \cdot \sin(2\pi)&=1\\
f_{1}(4)&=\cos\left(2\pi+\frac{2}{3}\pi\right)+i \cdot \sin\left(2\pi+\frac{2}{3}\pi\right)&=-\frac{1}{2}+ \frac{\sqrt{3}}{2}i\\
f_{1}(5)&=\cos\left(2\pi+\frac{3}{2}\pi\right)+i \cdot \sin\left(2\pi+\frac{3}{2}\pi\right)&=-\frac{1}{2}- \frac{\sqrt{3}}{2}i
\end{align*}$$

$$\begin{align*}
f_{2}(0)&=\cos(0)+i \cdot \sin(0)&=1\\
f_{2}(1)&=\cos\left(\frac{4}{3}\pi\right)+i \cdot \sin\left(\frac{4}{3}\pi\right)&=-\frac{1}{2}- \frac{\sqrt{3}}{2}i\\
f_{2}(2)&=\cos\left(\frac{8}{3}\pi\right)+i \cdot \sin\left(\frac{8}{3}\pi\right)&=-\frac{1}{2}+ \frac{\sqrt{3}}{2}i\\
f_{2}(3)&=\cos(4\pi)+i \cdot \sin(4\pi)&=1\\
f_{2}(4)&=\cos\left(4\pi+\frac{4}{3}\pi\right)+i \cdot \sin\left(4\pi+\frac{4}{3}\pi\right)&=-\frac{1}{2}- \frac{\sqrt{3}}{2}i\\
f_{2}(5)&=\cos\left(2\pi+\frac{8}{3}\pi\right)+i \cdot \sin\left(2\pi+\frac{8}{3}\pi\right)&=-\frac{1}{2}+ \frac{\sqrt{3}}{2}i
\end{align*}$$

Orthogonalität:
$$\begin{align*}
\langle f_{1}\mid f_{2}\rangle &= \sum_{i=0}^{5}f_{1} \cdot \bar{f_{2}}\\
&= (1 \cdot 1\\
&\quad\quad + \left(-\frac{1}{2}+ \frac{\sqrt{3}}{2}i\right)\cdot\left(-\frac{1}{2}+ \frac{\sqrt{3}}{2}i\right)\\
&\quad\quad + \left.\left(-\frac{1}{2}- \frac{\sqrt{3}}{2}i\right)\cdot\left(-\frac{1}{2}- \frac{\sqrt{3}}{2}i\right)\right)\cdot2\\
&=(1 + \frac{1}{4} -\frac{\sqrt{3}}{2}i+ \frac{3}{4}i^{2}+ \frac{1}{4}+ \frac{\sqrt{3}}{2}i+ \frac{3}{4}i^{2})\cdot 2\\
&=(1 + \frac{1}{4}- \frac{3}{4}+ \frac{1}{4}- \frac{3}{4})\cdot2\\
&= 0 \cdot 2\\
&= 0 \implies f_{1} \text{ und } f_{2} \text{ sind orthogonal.}
\end{align*}$$

## Aufgabe 4

### 4.1
Wenn alle Amplituden im Frequenzbereich verdoppelt würden, würden sich im in den Ortsraum rücktransformierten Bild alle Intensitätswerte ebenfalls verdoppeln.

Dies liegt daran, dass jeder Bildpunkt eine gewichtete Summe der Basisfrequenzen ist. Verdoppelt sich die Amplitude jeder Basisfrequenz bei gleichbleibenden Gewichten (oder: verdoppeln sich die Gewichtungen bei gleichbleibenden Amplituden), folgt aus dem Distributivgesetz, dass sich die Summe ebenfalls verdoppelt.

### 4.2
Rotiert man das Eingabebild um 90°, dann werden alle horizontale Frequenzen zu vertikalen Frequenzen und umgekehrt. 
Es werden also alle Bildfrequenzen 90° gedreht, und das resultierende Frequenzbild erscheint ebenfalls um 90° rotiert.

### 4.3
Um das große Quadrat im Frequenzbereich zu beschreiben, ist nur ein relativ schmaler Bereich von horizontalen und vertikalen Frequenzen benötigt, da die längeren Kanten eindeutige vertikale bzw. horizontale Strukturen darstellen. 
Es werden jedoch noch einige hohe Frequenzen benötigt, da die Kanten des Quadrats sehr scharf sind.

Hingegen ist das kleine Quadrat eine Struktur mit scharfen Kanten, aber weniger stark ausgeprägten horizontalen und vertikalen Komponenten. Entsprechend sind mehr diagonale Frequenzen nötig, um es darzustellen. 
Erneut werden wegen der scharfen Kanten viele hohe Frequenzen benötigt.

### 4.4
Der angewendete Bandpassfilter ist eine Kombination aus Hoch- und Tiefpassfilter.

Der Tiefpassfilter blockiert hohe Frequenzen, welche für schafe Kantenübergänge sorgen. Entsprechend sind die Kantenübergänge, ähnlich wie bei einem Gauss-Filter, etwas verschwommen.

Der Hochpassfilter hingegen blockiert tiefe Frequenzen, welche die Intensitätsinformationen für größere, homogene Segmente beinhalten. Ein Hochpassfilter hebt also die Kanten hervor.

Das Resultat des Bandpassfilters ist also eine Kantenhervorhebung, welche jedoch im Vergleich zu einem Hochpassfilter geglättet wurde.
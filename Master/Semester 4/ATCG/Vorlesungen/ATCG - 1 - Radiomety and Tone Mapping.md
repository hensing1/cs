[[atcg1-01-Radiometry_and_Tone_Mapping.pdf]]

## Licht
Lichtquellen emittieren in jeder Wellenlänge eine bestimmte Menge Energie.
Die insgesamt abgegebene Energiemenge ist das Integral über das gesamte Spektrum.

**Tristimulus-Theorie:** Die *wahrgenommene* Farbe einer Spektralverteilung kann vollständig mit drei Werten beschrieben werden.

Experimentelle Bestimmung (CIE 1931-Standard): man nehme drei monochromatische Emitter (436 nm, 546 nm, 700nm) und misst, wie hell man sie individuell machen muss, damit sie kombiniert genauso aussehen wie eine andere monochromatische Lichtquelle mit Wellenlänge $\lambda$.
Die Verteilungen für diese drei Lichtquellen nennen wir $\bar{x}(\lambda),\ \bar{y}(\lambda),\ \bar{z}(\lambda)$.
Es sind $\bar{x}(436\ \text{nm})=\bar{y}(436\ \text{nm})=0$,  $\bar{x}(546\ \text{nm})=\bar{z}(546\ \text{nm})=0$ und $\bar{y}(700\ \text{nm})=\bar{z}(700\ \text{nm})=0$.
![[CIE1931-Standard.png|300]]

Wir gehen davon aus, dass die menschliche Wahrnehmung linear ist. Um für ein Spektrum $S(\lambda)$ die erforderlichen Helligkeiten von $x$, $y$ und $z$ zu bestimmen, damit sie genauso aussehen, nehmen wir also das Integral: $$x=\int_{\lambda}S(\lambda)\bar{x}(\lambda)\,d\lambda\quad y=\int_{\lambda}S(\lambda)\bar{y}(\lambda)\,d\lambda \quad z=\int_{\lambda}S(\lambda)\bar{z}(\lambda)\,d\lambda.$$
Folge: vollkommen unterschiedliche Spektra können für das menschliche Auge identisch aussehen (Metamerie).
Es gibt einen Zweig in der Computergrafik, der das gesamte Spektrum betrachtet. Üblicherweise multiplizieren wir aber einfach die R, G und B-Kanäle miteinander, was zwar physikalisch inkorrekt, aber meistens eine ausreichend gute Annäherung ist.

## Radiometrie
Die Fläche, die ein Objekt im Sichtfeld einnimmt, wird in **Raumwinkel** (solid angle) gemessen:

> [!abstract] Definition *Raumwinkel*
> Sei $A$ eine Fläche, die auf eine Kugel mit Radius $r$ projiziert wurde.
> Der Raumwinkel dieser Fläche: $$\omega=4 \pi    \frac{A}{A_{\text{Kugel}}}=\frac{A}{r^{2}}\ [\text{sr}]$$
> Einheit: $\text{sr}$ (Steradian).

## HDR
**Camera Response Curve**
Doppelt so viel Licht in die Kamera -/-> Doppelt so hoher Pixelwert
Camera Response Curve (CRF): Einfallendes Licht auf der x-Achse (z.B. Belichtungszeit), Pixelwert auf der y-Achse

### HDR-Algorithmus nach Robertson

Gegeben: eine Serie von (LDR-)Bildern derselben Szene mit unterschiedlichen Belichtungszeiten
Gesucht: floating point HDR-Bild dieser Szene

$I_{m}$
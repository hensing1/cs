Datum: 18.04.
[[pho1-03-img-histo-1-histograms.pdf|Folien (1)]]
[[pho1-04-img-histo-2-transformations.pdf|Folien (2)]]

# Histogramme

Wir möchten Transferfunktionen für Bilder haben, die bestimmte Bildeigenschaften sicherstellen.

Sei $g(i,j) : \mathcal{B} \to \mathcal{G}$ die Bildfunktion, die Koordinaten aus $\mathcal{B} = \mathbb{Z} \times \mathbb{Z}$ Intensitätswerte aus $\mathcal{G} = \set{0, \ldots, 255}$ zuweist.

- Intensitätshistogramm
- Normalisiertes Intensitätshistogramm (PDF, Probability Distribution Function)
- Kumulatives Intensitätshistogramm (CDF, Cumulative Distribution Function)

**Helligkeit** kann beschrieben werden durch *Durchschnitt* und *Median* der Intensitätswerte
**Kontrast** kann beschrieben werden durch *Varianz*

## Transferfunktionen

> **Drei Arten von Transferfunktionen**
> - *Globaler Operator:* neuer Bildwert hängt vom kompletten Bild ab
> - *Lokaler Operator:* neuer Bildwert hängt von lokaler Nachbarschaft ab
> - *Punktoperator:* neuer Bildwert hängt nur von altem Bildwert ab

### Punktoperatoren

Bei Implementierung: evtl. Zeitersparnis, wenn man eine Lookup Table für alle möglichen Intensitätswerte generiert.

**Lineare (affine) Transferfunktion**
$$f(a) = k+ma$$
- $a$ ist alter Intensitätswert
- Neuer Mittelwert: $\mu_{b}=k+m \mu_a$
- Neue Standardabweichung: $\sigma_{b}=|m|\sigma_{a}$
- Helligkeit erhöhen: $k>0$, Helligkeit verringern: $k<0$
- Kontrast erhöhen: $m>1$, Kontrast verringern: $0<m<1$, Kontrast invertieren: $m=-1$

**Binäre Transferfunktion (mit Threshold $T$)**

$$b(a) = \begin{cases}0 \text{, falls }a<T \\
255 \text{ sonst}\end{cases}$$
Eine solche Funktion mit *mehreren Thresholds* ergibt eine **Quantisierung** (nützlich für Verringerung der Bitbreite).

**Tone Curve**
![[Tone Curve.png|500]]

**Histogrammlinearisierung**
Ansatz in dieser Vorlesung: wir überlegen uns, wie das Histogramm sich verändert, wenn man einen Punktoperator anwendet. 
Im Falle der linearen Transferfunktion: $$h_{b}(b) = \frac{h_{a}(\frac{b-k}{m})}{|m|}$$
Daraus berechnen wir rückwärts, wie die Transferfunktion für die Histogrammlinearisierung aussehen muss, und erreichen: $$f(a) = \text{round}\left(\frac{255(H(a) - H(0))}{H(255)-H(0)}\right),$$ wobei $H(a)$ das kumulative Histogramm vom Ursprungsbild ist.

**Rauschreduzierung**

- Nicht alle Regionen des Bilds haben dasselbe Rauschen
- Das Rauschen hängt von den Intensitätswerten ab: mehr Licht bedeutet mehr Varianz
	- (dunkle Bilder sehen verrauschter aus, weil dort konstante, additive Rauschkomponente deutlicher zu sehen ist)

Transferfunktion, um das Rauschen zu normalisieren: $$f(a) = \sqrt{255}\sqrt{a}$$
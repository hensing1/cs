[[05-inverseProblems.pdf]]

Wiederholung von [[Fourier-Transformation]] (insb. Nyquist-Theorem):
- Abgetastete Funktion sollte nicht zu hohe Frequenzen haben ("band-limited", z.B. mit Low-Pass-Filter), bzw.
- Abtastrate muss hoch genug sein
- Bei Rekonstruktion von abgetastetem Signal:
	- nimm nur die mittlere der unendlichen Kopien vom Signal
	- $\implies$ Multiplikation mit Box-Filter im Frequenzraum
	- $\iff$ Konvolution mit Sinc im Signalraum
	- $\implies$ Unendlicher Support, dh. man braucht *alle* Messungen für lokale Rekonstruktionen

## Motivation

Wir möchten aus einem Bild $o$ $$o=M(m)$$
wobei $M$ Imperfektionen im Bildgebenden Verfahren modelliert, die tatsächlichen Modellparameter $m$ bestimmen: $$m=M ^{-1}(o).$$
Ist $M$ unbekannt, ist das Problem **blind**.

$M$ könnte zum Beispiel *Rauschen* oder *Blur* sein.

## Dekonvolution

> **Point Spread Function**
> Eine PSF beschreibt, wie eine Punktlichtquelle in einem optischen System abgebildet wird.

*Optical Transfer Function (OTF):* Fourier-Transformation der PSF
*Modulation Transfer Function (MTF):* Magnitude der OTF

Annahme: $$\begin{align}
o&=m \otimes\mathrm{PSF} \\\iff \mathcal{F}(o)&=\mathcal{F}(m) \cdot \mathrm{OTF} \\
\implies \text{Rekonstruktion: } m_{r} &= \mathcal{F}^{-1}(\mathcal{F}(o) / \mathrm{OTF})
\end{align}$$
Problem: numerisch nicht stabil, da PSF normalerweise Tiefpassfilter ist und bei der Umkehrung hohe Frequenzen (=Rauschen) extrem verstärkt werden

Lösung: Clamping
$$\begin{align}
m_{r}&= \mathcal{F}^{-1}(\mathcal{F}(o) \cdot G) \\
G &= \begin{cases}
\frac{1}{\mathrm{OTF}}  & \text{falls} &  \frac{1}{\mathrm{OTF}} < \gamma \\
\gamma \frac{\mathrm{OTF}}{|\mathrm{OTF}|}  & \text{sonst}
\end{cases}
\end{align}$$
-> dieser Ansatz hält auch geringe Mengen an Rauschen aus

### Wiener-Filter

Schlaueres Clamping, wobei wir die [[ISS - VL 2#Signal-to-Noise ratio|SNR]] berücksichtigen. Für ein Filter $k$ (z.B. die PSF):

$$m_{r}=\mathcal{F}^{-1}\left( \frac{|\mathcal{F}(k)|^{2}}{|\mathcal{F}(k)|^{2}+\frac{1}{\mathrm{SNR}}}\cdot \frac{\mathcal{F}(o)}{\mathcal{F}(k)} \right).$$
Rechts steht weiterhin der Term aus der naiven Dekonvolution.

## Algebraische Dekonvolution

Die Konvolution ist *linear*. Also kann man die Konvolution eines Filters (z.B. Gauss) mit einem Bild als riesige Matrix $M$ darstellen: $o=Mm.$

Diese Matrix ist nicht unbedingt invertierbar, dh. sie hat keinen vollen Rang (anschaulich können beliebig verschiedene Szenen dasselbe verschwommene Bild erzeugen).
Wir können aber die Pseudoinverse berechnen:
$$\begin{align}
M^{-1}&=(U \Sigma V^{T})^{-1} \\
&= (V^{T})^{-1}\Sigma^{-1}U^{-1} \\
&= V \Sigma ^{-1} U, \, \Sigma ^{-1}=\mathrm{diag}\left( \frac{1}{\sigma_{i}} \right)
\end{align}$$

Auch hier wieder das Problem: ein Großteil der Singulärwerte $\sigma_{i}$ liegen unter der Maschinengenauigkeit ($10^{-16}$), sind also nicht verlustfrei zu invertieren.
Lösung: **Normalisieren**, indem zu kleine Singulärwerte nicht mehr berücksichtigt werden (Truncated SVD, TSVD):
$$M^{+}=V\Sigma^{+}U^{T}, \quad \Sigma^{+}=\mathrm{diag}\left( \begin{cases}
\frac{1}{\sigma_{i}} & \sigma_{i} > \epsilon \\
0 & \mathrm{sonst}
\end{cases} \right)$$

Alternativ kann man die [[Numerik - VL 2#Thikonov-Regularisierung|Thikonov-Regularisierung]] nehmen.
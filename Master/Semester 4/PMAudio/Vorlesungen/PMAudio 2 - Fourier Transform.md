## Discrete Fourier Transform (DFT)

Basisfunktion: $$u_{k}(n)=\exp\left( 2 \pi i \frac{kn}{N} \right)$$

- $N$: Länge des Signalvektors
- $k$: Frequenz, $k \in [0; N-1]$
- $n$: Zeit-Index, $n \in [0, N-1]$

Das ist eine Basis für $\mathbb{C}^{N}$, weil für verschiedene Frequenzen $k \neq l$ die Funktionen $u_{k}$ und $u_{l}$ orthogonal sind: $\langle u_{k} \mid u_{l} \rangle=\sum_{n=0}^{N-1}u_{k}(n) \overline{u_{l}(n)} = 0.$

Die Matrix: $\text{DFT}_{N}=\left[\overline{u_{k}(n)}\right]_{(n,k) \in [0; N-1]^{2}}$ ist die $N \times N$-Matrix, die für einen Signalvektor der Länge $N$ dessen Fourier-Transformation berechnet ( $\overline{u_{k}(n)}=\exp\left(-2 \pi i \frac{kn}{N} \right)$ ).
Setzen wir $\omega=\exp\left( -\frac{2\pi i}{N} \right)$, dann ist $\text{DFT}_{N}(k, n)=\omega^{k \cdot n}.$

Wir bezeichnen mit $\hat{x}$ oder $\mathbf{X}$ die Fourier-Transformation von einem Signal $x$.
$$\mathbf{X}(k) := \langle x \mid u_{k} \rangle = \sum_{n=0}^{N-1}x(n)u_{k}(n)=\sum_{n=0}^{N-1}x(n)\overline{\exp\left( 2 \pi i \frac{kn}{N} \right)}$$

### Bezeichnungen von Spektra

Magnitude spectrum: $|\mathbf{X}|$
Power spectrum: $|\mathbf{X}|^{2} := (|X(0)|^{2}, |X(1)|^{2}, \dots )^{T}$
Log of power spectrum: $10 \log_{10}|\mathbf{X}|^{2}= 20 \log_{10}|\mathbf{X}|$

Wir betrachten gerne das power spectrum anstelle des magnitude spectrums, da die Energie in vielen physikalischen Systemen proportional zur quadrierten Amplitude ist (akustische Intensität, elektromagnetische Intensität, etc).

Das magnitude spectrum eines reellwertigen Signals ist symmetrisch:

![[magnitude spectrum.png|581]]

slide 14 example exam relevant

> **Eigenschaften**
> Für $X$ und $Y$ Spektren von $x, y \in C^{N}$ gilt:
> - $$\langle X \mid Y \rangle =N \cdot\langle x \mid y \rangle $$
> - Ist $x$ ein zyklischer Shift von $y$, ist $X=Y$
> - $X(k)=\overline{X(n-k)}$ genau dann, wenn $x$ reelwertig
> - Ist $x(n)=y(N-n \mod N)$, dh. rückwärts (und evtl. zyklisch geshifted), dann ist $Y(k)=\overline{X(k)}.$

## Wiener Khinchin Theorem

- Autocorrelation
	- scalar product of two signals, one of which is cyclically shifted
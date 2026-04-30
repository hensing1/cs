Basisfunktion: $$u_{k}(n)=\exp\left( 2 \pi i \frac{kn}{N} \right)$$

- $N$: Länge des Signalvektors
- $k$: Frequenz, $k \in [0; N-1]$
- $n$: Zeit-Index, $n \in [0, N-1]$

Matrix: $\begin{bmatrix}u_{k}(n)\end{bmatrix}_{(n,k) \in [0; N-1]^{2}}$ ($N \times N$-Matrix, die für einen Signalvektor dessen Fourier-Transformation berechnet)

Wir bezeichnen mit $\hat{x}$ oder $\mathbf{X}$ die Fourier-Transformation von einem Signal $x$.

$\mathbf{X}(k) := \langle x \mid u_{k} \rangle = \sum_{n=0}^{N-1}x(n)u_{k}(n)=\sum_{n=0}^{N-1}x(n)\overline{\exp\left( 2 \pi i \frac{kn}{N} \right)}$ 

Magnitude spectrum: $|\mathbf{X}|$
Power spectrum: $|\mathbf{X}|^{2}$
Log of power spectrum: $10 \log_{10}|\mathbf{X}|^{2}= 20 \log_{10}|\mathbf{X}|$

slide 14 example exam relevant
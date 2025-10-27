Datum: 30.04.
[[pho1-06-local-op-part1.pdf|Folien (1)]]
[[pho1-07-local-op-part2.pdf|Folien (2)]]

# Lokale Operatoren

Zunächst: 
![[ISS - VL 2#^6f8c9c]]

Wir besprechen das [[ISS - VL 2#Mittelwertfilter|Mittelwertfilter]].


- Wir schreiben $R_{k}^{(n)}$ für ein Filter mit Nachbarschaft $k$ und Dimension $n$
	- $R_{3}^{(1)}$ ist ein $3 \times 1$-Vektor, $R_{3}^{(2)}$ ist eine $3 \times 3$-Matrix, etc.
- Wir unterstreichen den Wert, der in der Konvolution den Index 0 hat: $R_{3}^{(1)}=\frac{1}{3}\begin{pmatrix}1 \\ \underline{1} \\ 1\end{pmatrix}$

*Rauschreduzierung:*
Sei $g = R^{(1)}_{m} \ast f$. Dann wird das Rauschen (gemessen mit der Standardabweichung der Intensitätswerte) wie folgt reduziert: $$\sigma_{n_{g}}=\frac{1}{\sqrt{m}}\sigma_{n_{f}}.$$
Für $g = R^{(2)}_{m} \ast f$: $$\sigma_{n_{g}}=\frac{1}{m}\sigma_{n_{f}}.$$
> Allgemein gilt für einen Konvolutionskernel $w$: $$\sigma^{2}_{n_{g}} = \sum_{i}(w(i))^{2} \sigma^{2}_{n_{f}}.$$



Wir besprechen das [[ISS - VL 4#Medianfilter|Medianfilter]].
Optionen für Padding am Rand:
- Nullwerte
- Wrap: nimm andere Seite vom Bild
- Clamp: nimm den Randwert
- Mirror: spiegele das Bild am Rand

Wir besprechen das [[ISS - VL 2#Binomialfilter|Biniomialfilter]] und allgemeines Gedöns zur [[Konvolution]].

- Ein Binomialfilter mit sich selbst gefaltet ergibt ein größeres Binomialfilter.

Effiziente Berechnung des Mittelwertfilters durch **Integralbild** $S$: ^9b86d7
- jeder Punkt $S(x,y)$ im Integralbild ist die Summe aller Pixelwerte seines Rechtecks oben links
- Wert der Konvolution mit Mittelwertfilter der Größe $n$ an einem Pixel $(i,j)$ ist: $$S(i,j) - S(i-n, j) - S(i, j-n) + S(i-n, j-n).$$
## Gradientenfilter

### Erste Ableitung

Wir besprechen den [[ISS - VL 3#Sobel-Operator|Sobel-Operator]].

Die erste Ableitung der Bildfunktion ist eigentlich $f' \approx \Delta \ast f$ mit $\Delta=\begin{pmatrix}1 \\ \;\underline{-1}\;\end{pmatrix}$ bzw. $\Delta = \frac{1}{2} \begin{pmatrix}1 \\ \underline{0} \\ -1\end{pmatrix}$ (mit $B_{1}^{(1)}$ Binomialfilter geglättet).

Der Sobel-Operator ist nun $(B_{2}^{(2)})^{t} \ast \Delta$:

$$\Delta_{x}=\frac{1}{8}\begin{pmatrix}1 & 2 & 1 \\ 0 & \underline{0} & 0 \\ -1 & -2 & -1\end{pmatrix}$$

#### Scharr-Operator

Der Scharr-Operator ist ein verbesserter Sobel-Operator: $$\Delta_{x}^{\text{Scharr}}= \frac{1}{16}\begin{pmatrix}3 & \underline{10} & 3\end{pmatrix} \ast \frac{1}{2} \begin{pmatrix}1 \\ \underline{0} \\ -1\end{pmatrix}$$
$\to$ "10-mal so akkurat" bei der Bestimmung der Gradientenrichtung im Verlgeich zum Sobel-Operator


### Zweite Ableitung

Wir besprechen den [[ISS - VL 3#Laplace-Operator|Laplace-Operator]]. Bei uns sieht er so aus: $$\Delta_{L}=\frac{1}{4}\begin{pmatrix}1 & 2 & 1 \\ 1 & -\underline{12} & 2 \\ 1 & 2 & 1\end{pmatrix}.$$
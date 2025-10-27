Datum: 08.10.

# Einführung

## Erstellung von 3D-Objekten aus Linienzeichnungen

Gegeben: Orthografische Projektion eines Objekts (Punkte und Kanten), Punkte haben Koordinaten $x_{k},y_{k}$

Gesucht: Koordinate $z_k$ für plausibles 3D-Modell

Ansatz: minimiere Standardabweichung zwischen den einzelnen Winkeln: $$\arg\min_{z_{k}} \frac{1}{N-1}\sum\left(a_{ij}- \frac{1}{N} \sum a_{ij}\right)^{2}$$
mit $a_{ij}$ Winkel zwischen Vektoren $l_i$ und $l_j$ : $a_{ij}=\cos^{-1}\left(\langle \frac{l_{i}}{\|l_{i}\|}, \frac{l_{j}}{\|l_{j}\|} \rangle \right)$.


[Video](https://www.youtube.com/watch?v=bHDfETTS550)

## Alex Keller, NVIDIA

Samples, um Integral zu berechnen

*Stratified Sampling*
- vermeiden, dass komplette Regionen ausgelassen werden
- keine Garantie, dass Punkte nicht sehr nah beieinander landen
- curse of dimensionality, Anzahl der benötigten Strata wächst exponentiell mit den Dimensionen

Quasi-Monte Carlo: Punkte sind nicht mehr unabhängig voneinander
progressive Stratification

unbiased := Erwartungswert entspricht mathematischem Objekt, das modelliert werden soll (reicht aber nicht, um Konvergenz zu garantieren)

Bias nicht so schlimm wenn man Fehler kontrollieren kann

Wie macht man Sampling
Man transformiert sein Problem auf den $s$-dimensionalen Einheitswürfel $[0,1)^{s}$
man generiert einheitliche zufällige Samples in diesem Würfel

### Quasi-Monte Carlo Points

Für progressive Rendering muss man ggf. mehrere Sample-Mengen vereinigen
Vereinigung von mehreren einheitlichen Sample-Mengen sollte auch einheitlich sein

#### Radical Inversion

$$\begin{align}
\Phi_{b}: \mathbb{N}_{0} &\to \mathbb{Q} \cap [0,1) \\
i=\sum_{j=0}^{\infty}a_{j}(i)b^{j} &\mapsto \Phi_{b}(i) := \sum_{j=0}^{\infty}a_{j}(i)b^{-j-1}
\end{align}$$

- Man nimmt Zahl, schreibt sie in Basis $b$ (normalerweise $b=2$)
- man spiegelt sie und schreibt sie hinter das Komma
- -> $\Phi_{2}(0)=0,\ \Phi_{2}(1)=0.5,\ \Phi_{2}(2)=0.25,\ \Phi_{2}(3)=0.75,\ \Phi_{2}(4)=0.125,\ \dots$
- -> man füllt den Zahlenstrahl von 0 bis 1 gleichmäßig
	- die nächste Zahl fällt in die "größte Lücke"
	- maximal korreliert
	- alle $2^{k}$ Samples sind perfekt stratifiziert

##### Halton- und Hammersley Point Sets

Man hat mehrere Dimensionen. Für jede Dimension führt man stratified Sampling durch, jede Dimension mit einer anderen Basis $b$
Die Basen müssen jeweils **teilerfremd** (co-prime) sein

**Halton-Sequenz:** $x_{i}=(\Phi_{b_{1}}(i),\dots,\Phi_{b_{s}}(i))$

**Hammersley-Sequenz:** $x_{i}=\left( \frac{i}{n}, \Phi_{b_{1}}(i), \dots, \Phi_{b_{s-1}}(i)\right)$, wobei $n$ die Anzahl der Samples ist

##### Scrambling
Problem mit Halton-Punkten: wenn die Basen groß sind, aber man wenige Dimensionen hat, sind die Punkte zunächst sehr nah beieinander. 

Also würfelt jede Axis separat durcheinander:
- man nimmt die $\Phi$-Basis $b_{j}$ der Achse $j$
- man teilt das Volumen in $b_{j}$ gleich große Teile entlang der Achse $j$
- man permutiert diese Volumen
	- in Basis 2: z.B. zufällig entscheiden, ob man sie vertauscht oder nicht
- jedes Volumen teilt man wieder rekursiv in $b_{j}$ Teile entlang $j$ und permutiert wieder

-> Stratifizierung durch radical inversion wird dadurch nicht beeinflusst, es ist aber zwischendurch gleichmäßiger (& zufälliger) verteilt

Effizienter machen: Paare von Ziffern nehmen und Lookup-Tabelle verwenden

#### Rank-1 Lattices

- man braucht einen generator vector $(g_{0},\dots,g_{s-1}) \in \mathbb{N}^{s}$
- man multipliziert ihn und nimmt den Modulus, sodass er im Einheitswürfel landet: $$x_{i}=\frac{i}{n}(g_{0},\dots,g_{s-1}) \text{ mod } [0,1)^{s}$$
Um daraus eine Sequenz zu machen, kann man $\frac{i}{n}$ mit dem radical inverse ersetzen
Datum: 28.11.
[[ISS07_WS2324_FT&amp;ScaleSpace_231128.pdf|Folien]]

[[ISS_WS2324_Aufgabenblatt07.pdf]]
# Fourier-Transformationen

> **Fourier-Transformation**
> Eine Fourier-Transformation (FT) beschreibt eine beliebige Funktion als Summe von gewichteten periodischen Funktionen (Basisfunktionen) mit verschiedenen Frequenzen (*Frequenzraumrepräsentation*).

## Ortsraum vs. Frequenzraum

### Ortsraum

Üblicherweise werden Bilder im *Ortsraum* dargestellt. 

Ein (Grauwert-)Bild mit $n \cdot m$ Pixeln ist also ein Vektor im $\mathbb{R}^{n \cdot m}$. Die Basis besteht also aus $n \cdot m$ Basisfunktionen, die jeweils an genau einem Pixel den Wert 1 und in allen anderen den Wert 0 hat. Das Bild ist die gewichtete Summe der Basisfunktionen:

![[Ortsraum.png|300]]

### Transformation in den Frequenzraum

Wir wollen eine entsprechende Darstellung im *Frequenzraum* finden. 
Die Basisfunktionen sind hierbei Funktionen mit bestimmter *Frequenz* und *Richtung*.

Wir möchten, dass die Basisfunktionen [[Matrizen#^88ba7f|orthogonal]] zueinander sind.

Zwei Funktionen sind orthogonal, wenn ihr Skalarprodukt Null ist.

Also müssen wir das Skalarprodukt für zwei Funktionen definieren (hier: ganzzahliger, beschränkter Definitionsbereich):

$$\langle f_{1} \mid f_{2}\rangle = \sum_{n=0}^{N-1}f_{1}(n)\overline{f_{2}(n)} \stackrel{!}{=} 0$$
bzw. erweitert auf mehrdimensionale Funktionen:
$$\langle f_{1} \mid f_{2}\rangle = \sum_{n=0}^{N-1}\sum_{m=0}^{M-1}f_{1}(m,n)\overline{f_{2}(m,n)} \stackrel{!}{=} 0.$$
Die obigen Basisfunktionen für den Ortsraum sind offensichtlich paarweise orthogonal.

Eine Transformation in eine andere Basis ist invertierbar, wenn die Anzahl der Basisvektoren gleich ist. Also besteht unser Bild am Ende aus $n \cdot m$ skalierten Basisvektoren aus dem Frequenzraum.

> Jede orthogonale Basis kann durch Rotation (und Translation) aus jeder anderen orthogonalen Basis für die gleiche Funktion erzeugt werden.

Das gilt offensichtlich für den $\mathbb{R}^2$ und $\mathbb{R}^3$, und für die hier betrachteten Funktionen auch.

Naja jedenfalls rotiert man den Schrott irgendwie durch die Gegend mit der komplexen Sinus- und Kosinusfunktion. Wie genau ist für diese Zwecke eigentlich auch egal.

Man landet jedenfalls hier:
- man hat ein Bild der Größe $M \times N$ 
- $f(m,n)$ ist die Repräsentation des Bilds im Ortsraum (Intensität am Punkt $(m,n)$)
- $F(u,v)$ ist die Repräsentation des Bilds im Frequenzraum ($u$ und $v$ beschreiben zusammen die Richtung und Frequenz der Basisfunktion)

*Hintransformation (Ortsraum $\to$ Frequenzraum):*
$$F(u,v) = \sum_{m=0}^{M-1}\sum_{n=0}^{N-1}f(m,n)\cdot \huge e^{-i \cdot 2\pi \cdot(\frac{u \cdot m}{M}+ \frac{v \cdot n}{N})}$$
*Rücktransformation (Frequenzraum $\to$ Ortsraum):*
$$f(m,n) = \frac{1}{MN}\sum_{u=0}^{M-1}\sum_{v=0}^{N-1}F(u,v)\cdot \huge e^{-i \cdot 2\pi \cdot(\frac{u \cdot m}{M}+ \frac{v \cdot n}{N})}$$ ^0eb88b

## Bildeigenschaften im Orts- und Frequenzraum

Bei der Darstellung von $F$ als Bild wird der Betrag $|F(u,v)|$ genommen, da $F$ komplex ist. Die Amplituden der tiefen Frequenzen werden in den Bildmittelpunkt verschoben.

![[Darstellung_Frequenzraum.png|400]]

Auswirkungen von Bilddetails auf Frequenzdarstellung:
- Horizontale Strukturen im Bild $\to$ vertikale Komponenten im Spektrum
- Vertikale Strukturen im Bild $\to$ horizontale Komponenten im Spektrum
- Scharfe Kanten $\to$ viele hohe Frequenzbereiche

- Transformiere Bild (FFT)
- Transformiere Filter (FFT)
- Transformiertes Bild *multiplizieren* mit transformiertem Filter (statt Konvolution)
- Resultat rücktransformieren

## Fast Fourier Transform

Die Berechnung der obigen Formel benötigt für ein Bild der Größe $N \times N$ einen Rechenaufwand von $\mathcal{O}(N^4)$, also $\mathcal{O}(N^{2})$ pro Pixel.
Der *FFT* schafft dasselbe in $\mathcal{O}(N^{2}\log n)$, also nur $\mathcal{O}(\log N)$ pro Pixel.

Das macht den FFT für manche Konvolutionen schneller: *eine Konvolution im Frequenzraum ist nur eine Multiplikation mit einer Filterfunktion* (genauer: Multiplikation mit dem FT der Konvolutionsfunktion).

$$\begin{matrix}
\text{Ortsraum} & & \text{Frequenzraum} \\
f(m,n) & \stackrel{\text{FT}}{\longrightarrow} & F(u,v) \\
\downarrow & & \downarrow  \\
f \ast g & g \stackrel{\text{FT}}{\longrightarrow}G & F \cdot G \\ 
\downarrow & & \downarrow \\ 
f'(m,n) & \stackrel{\text{FT}^{-1}}{\longleftarrow} & F'(u,v) \end{matrix}$$

^616f5d

Komplexität für Konvolution mit Filtergröße $m$: $\mathcal{O}(m^{2}N^{2})$
Komplexität mit FFT: $\mathcal{O}(N^{2}\log N)$

Ist also $\log N \ll m^{2}$, ist die Konvolution mittels FFT effizienter.

## Anwendung

- **Tiefpassfilter**
	- tiefe Frequenzen passieren, hohe Frequenzen eliminieren
	- *glätten* das Bild
- **Hochpassfilter**
	- hohe Frequenzen passieren, tiefe Frequenzen eliminieren
	- *Kantenhervorhebung*
- **Bandpassfilter** ^c556d4
	- Kombination auf Tiefpass- und Hochpassfilter


# Multiskalenstrategien

Motivation: erkennbare bzw. interessante Bildmerkmale sind abhängig davon, auf welcher Skala (d.h. auf welchem Detailgrad) das Bild betrachtet wird. Wir möchten grobe, großflächige Merkmale sowie kleine Bilddetails beschreiben können.

*Implizit integrierte Multiskalenstrategie:* beispielsweise im [[ISS - VL 5#Region Merging]] werden im Split-Prozess kleinere und kleinere Skalen betrachtet.

*Explizite Multiskalenrepräsentation:* umgesetzt durch hoch- bzw. runterskalieren des Bildes

## Gauß-Pyramide

Mit einer Gauß-Pyramide wird das Bild schrittweise verkleinert, um Bildanalyse auf verschiedenen Skalen zu ermöglichen.

Runterskalieren (reduce): Jede Pyramidenstufe verkleinert das Bild um den Faktor $1/4$:
![[Gausspyramide.png]]

Hochskalieren (expand): Vergrößerung um Faktor $4$:
![[Gausspyramide_expand.png]]

## Laplace-Pyramide

Die Laplace-Pyramide ist eine nahezu redundanzfreie Repräsentation des Multiskalenraums: 
Man nimmt die Gaußpyramide, speichert aber nur die Differenz zwischen der aktuellen und der darüberliegenden Ebene:

![[Laplacepyramide.png]]

Das ganze entspricht einem [[ISS - VL 3#Difference-of-Gaussian-Filter]].
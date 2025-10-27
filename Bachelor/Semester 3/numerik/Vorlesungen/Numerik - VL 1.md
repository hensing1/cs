Datum: 13.10.
[[Slides_2023_01_26.pdf|Folien]] - Kapitel 1 (bis S. 34)
# Grundlagen
*Kapitel 1*

## Vektoren und Matrizen
![[Matrizen#Multiplikation]]

## Vektorräume

Wir besprechen:
- Bild und Kern
- Rang und Inverse
	- Es gibt Zeilenrang (Dimension des Bildes), und den Spaltenrang (???)
	- Die Nullen in der Einheitsmatrix schreibt man nicht.
- Basiswechsel
	- $Ax=b \iff x=A^{-1}b$

![[Matrizen#^fa9e35]]

![[Matrizen#^c43bcf]]
![[Matrizen#^88ba7f]]

Die Vektoren einer orthogonalen Menge sind linear unabhängig.

Einen $n$-dimensionalen Vektor $v$ kann man wie folgt als Linearkombination einer orthonormalen Menge $S=\set{q_{1},\ldots,q_{n}}$ darstellen:
$$v = \langle q_{1}, v \rangle q_{1} + \ldots + \langle q_{n}, v \rangle q_{n}$$

(Damit ist $(\langle q_{1}, v \rangle, \ldots , \langle q_{n}, v \rangle)$ die *Koordinatendarstellung* von $v$ zur Basis $(q_{1},\ldots,q_{n})$.)

Ist $|S|<n$, dann ist $r = v - \langle q_{1}, v \rangle q_{1} - \space\ldots\space - \langle q_{n}, v \rangle q_{n}$ orthogonal zu $S$.


![[Matrizen#^e32b56]]

## Normen
> [!abstract] Definition *Norm*
> Eine Norm ist eine Abbildung $\|\cdot\|: \mathbb{C}^{n}\to \mathbb{R}$ mit den folgenden Eigenschaften:
> - $\|x\|\geq 0$, $\|x\|=0\iff x=0$
> - $\|\alpha x\|=|\alpha|\cdot\|x\|$
> - $\|x+y\|\leq \|x\|+\|y\|$ (Dreiecksungleichung)

^5ed8e6

### Vektornorm

> ***p-Norm***
> Für $p \in \mathbb{R}_{\geq 1}$ ist für einen Vektor $x \in \mathbb{C}^{n}$ die $p$-Norm wie folgt definiert:
> $$\|x\|_{p}:=\left(\sum\limits_{i=1}^{n}|x_{i}|^{p}\right)^{\frac{1}{p}}.$$

Die 2-Norm heißt *euklidische Norm* und ist die Länge des Vektorpfeils.

### Matrixnorm

> [!abstract] Definition *Induzierte Matrixnorm*
> Seien $\|\cdot\|_n$ und $\|\cdot\|_m$ Vektornormen des Definitions- bzw. Bildbereichs von $A \in C^{m\times n}$.
> Dann ist die induzierte Matrixnorm von $A$ definiert als $$\|A\|_{(m,n)}=\sup\limits_{x\in C^{n}\setminus\set{0}} \frac{\|Ax\|_{m}}{\|x\|_{n}}.$$

$\|A\|_{(m,n)}$ ist also der größte Streckungsfaktor, den irgendein Vektor durch die Multiplikation mit $A$ erfährt.

> ***Allgemeine Matrixnorm***
> Im Allgemeinen muss eine Matrixnorm auch nur die drei Eigenschaften einer [[Numerik - VL 1#^5ed8e6|Norm]] erfüllen.

#### 1-Norm
> Die induzierte Matrixnorm $\|\cdot\|_1$ (1-Norm) einer Matrix ist die *maximale Spaltensumme* der Matrix. 

![[1-Norm_Matrix.png|400]]

Der Vektor $e_{2}$ wird auf $e_{2}^{\ast}$ mit $\|e_{2}^{\ast}\|_{1}=4$ abgebildet. Also ist die 1-Norm der entsprechenden Matrix gleich 4.

#### $\infty$-Norm
> Die induzierte Matrixnorm $\|\cdot\|_{\infty}$ einer Matrix ist die *maximale Zeilensumme*.

#### Gleichungen zum Rechnen mit Normen

> *Cauchy-Schwarz-Ungleichung*
> Es gilt für alle Vektoren $x,y \in \mathbb{C}^{n}$: $$|x ^{\ast} y| \leq \|x\|_{2}\cdot\|y\|_2.$$

Die Cauchy-Schwarz-Ungleichung ist ein Spezialfall der Hölder-Ungleichung:

> *Hölder-Ungleichung*
> Sei $\frac{1}{p}+ \frac{1}{q}=1$ mit $p,q \in \mathbb{R}_{>1}$.
> Dann gilt für alle Vektoren $x,y \in \mathbb{C}^{n}$: $$|x ^{\ast} y|\leq \|x\|_{p}\cdot\|y\|_{q}.$$

Außerdem gilt: $$\|a ^{\ast}\|_{2}=\|a\|_{2}.$$

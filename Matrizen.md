# Matrizen


> [!abstract] Definition *Matrix*
> Eine **$(n \times m)$-Matrix** über $\mathbb{K}$ besteht aus $n \cdot m$ Elementen mit Indizes $i \in \set{1,\ldots,n}$ und $j \in \set{1,\ldots,m}$ in folgendem Schema: $$M=\begin{pmatrix}a_{11}&a_{12}&\ldots&a_{1m}\\a_{21}&a_{22}&\ldots&a_{2m}\\\vdots&\vdots&\ddots&\vdots\\a_{n1}&a_{n2}&\ldots&a_{nm}\end{pmatrix}$$
> $n$ beschreibt also die Anzahl der Zeilen und $m$ beschreibt die Anzahl der Spalten.
> 
> Die Menge $\text{Mat}(n\times m, \mathbb{K})$ ist die Menge aller $(n \times m)$-Matrizen über $\mathbb{K}$.
> 
> Sei $f: \mathbb{K}^{m}\to \mathbb{K}^{n}$ nun eine [[Lineare Funktionen|Lineare Funktion]], $(e_1,\ldots,e_m)$ die kanonische Basis zu $\mathbb{K}^m$ und $f(e_1)=w_1,\ldots,f(e_m)=w_m$. 
> Dann heißt die Matrix $(w_1,\ldots,w_m)=\text{DM}(f)$ die *darstellende Matrix von $f$* (der Vektor $w_1$ bildet eine Spalte in der Matrix).
^628cdf
## Operationen

Die Menge aller Matrizen bildet mit folgenden Verknüpfungen einen [[Vektorräume#Vektorräume|Vektorraum]]: ^6bb850

> **Matrizenaddition**
> $$\begin{pmatrix}a_{11}&\ldots&a_{1m}\\\vdots&\ddots&\vdots\\a_{n1}&\ldots&a_{nm}\end{pmatrix}+\begin{pmatrix}b_{11}&\ldots&b_{1m}\\\vdots&\ddots&\vdots\\b_{n1}&\ldots&b_{nm}\end{pmatrix}=\begin{pmatrix}a_{11}+b_{11}&\ldots&a_{1m}+b_{1m}\\\vdots&\ddots&\vdots\\a_{n1}+b_{n1}&\ldots&a_{nm}+b_{nm}\end{pmatrix}$$
> **Skalare Multiplikation**
> $$\lambda \cdot \begin{pmatrix}a_{11}&\ldots&a_{1m}\\\vdots&\ddots&\vdots\\a_{n1}&\ldots&a_{nm}\end{pmatrix}=\begin{pmatrix}\lambda a_{11}&\ldots&\lambda a_{1m}\\\vdots&\ddots&\vdots\\ \lambda a_{n1}&\ldots&\lambda a_{nm}\end{pmatrix}$$
> **Nullmatrix**
> Die Matrix, die überall Nullen hat.

^23aee7

### Multiplikation

> [!abstract] Definition *Matrixmultiplikation*
> Sei $A=(a_{ik})\in \text{Mat}(r\times n, \mathbb{K})$ und $B=(b_{kj})\in \text{Mat}(n \times m, \mathbb{K})$. Das **Matrizenprodukt** ist definiert als:
> $$A \cdot B=AB=\left(\sum\limits_{k=1}^{n}a_{ik}b_{kj}\right)_{\begin{gather}i=1,\ldots,r\\j=1,\ldots,m\end{gather}}\in \text{Mat}(r\times m, \mathbb{K})$$
^83f3d5

![[Matrixmultiplikation.png|400]]

Es gilt:
- Die Matrixmultiplikation ist äquivalent zur Verknüpfung zweier linearen Funktionen: $DM(f \circ g) = DM(f) \cdot DM(g)$
- Die Spaltenzahl der ersten muss gleich der Zeilenzahl der zweiten Matrix sein.
	- Die resultierende Matrix hat die Zeilenzahl der ersten und die Spaltenzahl der zweiten Matrix.

Die Matrix-Vektor-Multiplikation $Av=b$ mit $A \in \text{Mat}(n\times m), v \in \text{Mat}(m \times 1)$ folgt direkt aus der Definition der Matrixmultiplikation, indem man den Vektor als einspaltige Matrix auffasst.

#### Linearkombination

Das Produkt ist eine [[Vektorräume#Linearkombination|Linearkombination]] der Spaltenvektoren der Matrix:
![[Matrix-Vektor-Produkt.png]]

Dasselbe gilt für Matrix-Matrix-Multiplikation: für $B=A \cdot C$ ist die Spalte $b_{j}=A \cdot c_{j}$, d.h. eine Linearkombination der Spalten von $A$, deren Koeffizienten in der Spalte $c_{j}$ stehen.

#### Rechenregeln

> - Assoziativität: $A \cdot (B \cdot C)=(A \cdot B) \cdot C$
> - Distributivität:
> 	- $A \cdot (B + C)= A \cdot B + A \cdot C$
> 	- $(A + B) \cdot C= A \cdot C + B \cdot C$
> - **Keine** Kommutativität: $A \cdot B \neq B \cdot A$

#### Äußeres Produkt
Das Produkt eines *Spaltenvektors* ($u \in \text{Mat}(l \times 1)$) mit einem *Zeilenvektor* ($v \in \text{Mat}(1 \times n)$) heißt **Äußeres Produkt:**
![[Äußeres_Produkt.png]]

## Norm
![[Numerik - VL 1#Matrixnorm]]

## Transponierung
### Transponierte Matrix
> Eine transponierte Matrix $A^{t}\in \text{Mat}(m \times n, \mathbb{K})$ einer Basis $A \in \text{Mat}(n \times m, \mathbb{K})$ erhält man, indem man die Zeilen zu Spalten macht:
> $$\begin{pmatrix}a & b & c \\ d & e & f\end{pmatrix}^{t}=\begin{pmatrix}a & d \\ b & e \\ c & f\end{pmatrix}.$$
> Die Matrix $A$ heißt **symmetrisch**, wenn $A^{t}=A$. Jede symmetrische Matrix ist quadratisch.

> Es gilt:
> $$(AB)^{t}=B^{t}\cdot A^{t}$$für quadratische Matrizen $A,B$.

### Adjungierte Matrix

> Die **hermitesch adjungierte Matrix** $A ^{\ast}$ (oder nur Adjungierte) erhält man, indem man die Einträge der Matrix $A$ [[Komplexe Zahlen#Konjugation und Betrag|komplex konjugiert]] und $A$ [[Matrizen#Transponierte Matrix|transponiert]], d.h. $$A ^{\ast}=\bar{A}^{T}=\begin{pmatrix}\bar{a}_{1,1} & \ldots & \bar{a}_{1,m} \\ \vdots & & \vdots \\ \bar{a}_{n,1} & \ldots & \bar{a}_{n,m}\end{pmatrix}^{T}.$$
> Ist $A = A^{\ast}$, heißt $A$ *hermitesch*.
> Für reelle $A$ ist die Ajungierte dasselbe wie die transponierte Matrix, $A ^{\ast}=A^{T}$.

^fa9e35

#### Rechenregeln

- $(A+B)^{\ast}=A ^{\ast} + B ^{\ast}$
- $(AB)^{\ast}=B ^{\ast} A ^{\ast}$
- $(A ^{\ast})^{\ast}=A$
- $(c \cdot A)^{\ast}=\bar{c}A ^{\ast}$ für einen Skalar $c \in \mathbb{C}$
- $(A^{-1})^{\ast}=(A ^{\ast})^{-1}$
- $\text{Bild}(A ^{\ast}) \,\bot\, \text{Kern}(A)$ und $\text{Bild}(A) \,\bot\, \text{Kern}(A ^{\ast})$

### Unitäre/orthogonale Matrix

> Sind alle Spalten- bzw. Zeilenvektoren einer quadratischen Matrix orthonormal, dann gilt:$$Q ^{-1}=Q^{\ast}.$$
> Also gilt $Q ^{\ast} \cdot Q = Q \cdot Q ^{\ast}= E$.
> Im komplexen heißt $Q$ dann **unitär**.

^e32b56

## Elementare Umformungen

### Permutationsmatrix

Eine *Permutationsmatrix* erhält man, indem man die Zeilen (bzw. Spalten) der Einheitsmatrix permutiert.

> Sei $P_{i,j}$ die Einheitsmatrix, bei der die Zeilen $i$ und $j$ vertauscht wurden, d.h. $p_{i,i}=p_{j,j}=0$ und $p_{i,j}=p_{j,i}=1$.
> $P_{i,j}$ heißt *elementare Permutationsmatrix*.
> 
> Dann ist $PA$ die Matrix $A$ mit vertauschten **Zeilen** $i$ und $j$.
> Andersherum ist $AP$ die Matrix $A$ mit vertauschten **Spalten** $i$ und $j$.

#### Sätze

- Eine elementare Permutationsmatrix ist selbstinvers: $P_{i,j}^{2}=I$.
- Jede beliebige Permutationsmatrix lässt sich als Produkt aus beliebigen elementaren Permutationsmatrizen $P_{i,j}$ darstellen.

## Determinante
> [!abstract] Definition *Laplace'scher Entwicklungssatz*
> Die **Determinantenfunktion** $\det : \text{Mat}(m \times m, \mathbb{K}) \to \mathbb{K}$ ist wie folgt rekursiv definiert:
> - Für $m=1$: $\det(A):=\det A:=|A| := a_{11}$.
> - Für $m\geq 2$: $$\sum\limits_{k=1}^{m}(-1)^{k+1}\cdot a_{k1} \det A_{k1}$$wobei $A_{k1} \in \text{Mat}(m-1 \times m-1, \mathbb{K})$ die Matrix $A$ ohne die Zeile $k$ und ohne die Zeile $1$ ist.

^61445a

Für $m=3$: $$\begin{vmatrix}a & b & c \\ d & e & f \\ g & h & i\end{vmatrix}=a \cdot \begin{vmatrix}e &  f \\ h & i\end{vmatrix} - d \cdot \begin{vmatrix}b & c \\ h & i\end{vmatrix} + g \cdot \begin{vmatrix}b & c \\ e & f\end{vmatrix}.$$ ^544eb4

Für eine $2 \times 2$-Matrix $A = \begin{pmatrix}a & b\\ c & d\end{pmatrix}$ ist $\det A=ad-bc$.

Es gilt:
 $$\det(AB)=\det(A)\det(B)$$für alle $n \times n$-Matrizen $A$ und $B$. ^f02bda

> [!info] Starre Transformation
> Eine lineare Transformation $T \in \mathbb{R}^{n\times n}$ heißt **starr** (en. rigid), wenn alle Abstände erhalten bleiben: $$\forall p,q \in \mathbb{R}^{n}: \|Tp-Tq\|=\|p-q\|.$$
> 
> Starre Transformationen sind: 
> - Rotationen: $\det T = 1$
> - Spiegelungen: $\det T = -1$.

Die Determinante ist das *Produkt der Eigenwerte*.
## Spur

> Die **Spur** (engl. *trace*) einer quadratischen Matrix $A \in K^{n\times n}$ ist die ***Summe der Elemente der Hauptdiagonalen.*** $$\text{spur}(A)=\sum_{j=1}^{n}a_{jj}.$$

Gleichzeitig ist die Spur auch die *Summe der Eigenwerte*. Irgendwie.

## Definitheit

> [!abstract] Definition *Definitheit*
> Eine [[Matrizen#^fa9e35|hermitesche]], quadratische Matrix $A \in \mathbb{C}^{n\times n}$ ist genau dann:
> - **positiv definit**, wenn alle Eigenwerte $>0$ sind;
> - **positiv semidefinit**, wenn alle EW $\geq 0$ sind;
> - **negativ definit**, wenn alle EW $< 0$ sind;
> - **negativ semidefinit**, wenn alle EW $\leq 0$ sind;
> - **indefinit**, wenn sie positive und negative Eigenwerte hat.

## Inverse

## Pseudoinverse

![[Numerik - VL 4#^7ab87e]]

![[Numerik - VL 4#^82b5b8]]

## Eigenwerte und Eigenvektoren

![[LA - VL 21#^97a8fe]]

### Geometrische und algebraische Vielfachheit

![[LA - VL 21#^b3db06]]

# Berechnung

Berechnung von Matrixprodukt mit $k$ Vektoren als Matrix-Matrix-Produkt:
$$M \cdot \begin{pmatrix}(v_{1}) & \ldots & (v_{k})\end{pmatrix} = \begin{pmatrix}(Mv_{1}) & \ldots & (Mv_{k})\end{pmatrix}$$

## Matrix Inversion Lemma

Sei die Matrix $B$ breiter als hoch, ist die Inverse von $B^{T}B$ aufwändiger als $BB^T$.
Seien außerdem die Matrizen $A$ und $C$ symmetrisch und positiv definit. Dann gilt die folgende Gleichung: $$(A^{-1}+B^{T}C^{-1}B)^{-1}=A-AB^{T}(BAB^{T}+C)^{-1}BA.$$
## Matrixzerlegungen

### EVD

### SVD
![[Numerik - VL 3#Singulärwertzerlegung]]

### QR
Datum: 03.11.

# Singulärwertzerlegung
*Kapitel 3 - Fortsetzung*
## SVD und EVD

Singulärwertzerlegung: funktioniert für jede Matrix, siehe [[Numerik - VL 3|letzte Vorlesung]]

> **Eigenwertzerlegung** (oder Spektralzerlegung)
> Zerlegung einer Matrix $A$ mit $$A = V \cdot \Lambda \cdot V^{-1}$$
> mit $\Lambda=\begin{pmatrix}\lambda_{1} & &  \\ & \ddots &  \\ & & \lambda_{n}\end{pmatrix}.$

Voraussetzung ist, dass $A$ $n$ linear unabhängige Eigenvektoren hat. *Diese müssen aber nicht zwingend orthogonal sein.*[^1]

[^1]: Im Gegensatz zur SVD, bei der die Rechts- und Linkseigenvektoren jeweils orthogonal sind.

$V$ enthält spaltenweise die Eigenvektoren von $A$: $Av_{i}= \lambda_{i}v_{i}$.

- Die SVD ist interessant zum Studium der Matrix $A$ selbst, da sie beschreibt, welche Vektoren aus dem Einheitskreis die Halbachsen der entstehenden Ellipse werden, und wie lang diese gestreckt werden.
- Die EVD ist interessant zum Studium von Matrixpotenzen:
	- $Av_{i}=\lambda_{i}v_{i} \iff A^{k}v_{i}=\lambda_{i}^{k}v_{i}$
	- $A^{k}=(V \Lambda V^{-1})^{k} = V \Lambda^{k} V^{-1}$

## SVD und lineare Ausgleichsrechnung

> [!abstract] Definition *Pseudoinverse*
> Sei $A = U \Sigma V ^{\ast}$ die [[Matrizen#SVD|SVD]] von $A \in \mathbb{K}^{m\times n}$. Dann heißt $$A^{+}= V \Sigma^{+}U ^{\ast} \in \mathbb{C}^{n \times m}$$ mit $$\Sigma^{+}=\begin{pmatrix}\sigma_{1}^{-1} & & & \\ & \ddots & &  \\ & & \sigma_{p}^{-1}  &  \\ & & & 0\end{pmatrix}$$ die **Pseudo-** oder **Moore-Penrose-Inverse** von $A$.

^7ab87e

Es ist $A^{+}=\sum_{i=1}^{p}v_{i}\sigma_{i}^{-1}u_{i} ^{\ast}$.

Außerdem:
$$\begin{align*}
(A^{+})^{+}&=A \\
(A ^{\ast})^{+}&=(A^{+})^{\ast} \\
(A A^{+})^{\ast}&=A A^{+} \\
(A^{+}A)^{\ast}&= A^{+}A
\end{align*}$$

^82b5b8

> Der Vektor $A ^{+}b$ ist die eindeutig bestimmte Lösung des linearen Ausgleichsproblems $$\|b-Ax\|_{2}\to\min.$$

# QR-Zerlegung
*Kapitel 4*

## Projektoren und Projektionsmatrizen

> Eine Matrix $P$ ist eine *Projektionsmatrix*, wenn gilt: $P^{2}=P$.

Das Bild von $P$ ist also z.B. eine Projektionsfläche ($\mathbb{R}^{3}\to \mathbb{R}^{2}$), auf den alle Vektoren projiziert werden. Liegt der Vektor bereits in dieser Fläche, bleibt er genau dort.

Man projiziert "entlang" des Kerns von $P$, d.h. $v - Pv \in \text{Kern}(P)$.

> *Komplementäre Projektionsmatrix*
> Ist $P$ eine Projektionsmatrix, dann ist $I-P$ auch eine (die komplementäre) Projektionsmatrix - nämlich die, die alles auf den Kern von $P$ projiziert.
> 
> Es gilt:
> - $\text{Bild}(P)=\text{Kern}(I-P)$,
> - $\text{Kern}(P)=\text{Bild}(I-P)$, und
> - $\text{Bild}(P) \cap \text{Bild}(I-P) = \text{Kern}(P) \cap \text{Kern}(I-P) = \set{0}$.

### Orthogonale Projektion

Sind Kern und Bild von $P$ orthogonal zueinander, ist $P$ eine **orthogonale Projektion**.

> Eine Projektion ist genau dann orthogonal, wenn gilt: $$P ^{\ast}=P.$$

### Projektion mit orthonormaler Basis

Sei $\set{q_{1},\ldots,q_{n}}\subset \mathbb{C}^{m}$ eine orthonormale Menge.

Dann gilt für alle $v \in \mathbb{C}^{m}$: $$v = r+ \sum_{i=1}^{n}(q_{i}q_{i}^{\ast})v.$$
Es gilt $(q_{i}q_{i}^{\ast})v=(q_{i}^{\ast}v) q_{i}.$

Das *Residuum* $r$ steht dann orthogonal zu den $q$'s: $$r \in \left<q_{1},\ldots,q_{n}\right>^{\bot}.$$

Sei $\hat Q$ die Matrix mit den $q_{i}$'s als Spalten. Dann gilt: $\sum_{i=1}^{n}(q_{i}q_{i}^{\ast})=\hat Q \cdot \hat Q ^{\ast}$.

Das heißt: $$v=r+\hat Q \hat Q ^{\ast}v.$$
> Also ist $\hat Q \hat Q ^{\ast}$ eine orthogonale Projektion, und zwar auf den Spaltenraum von $\hat Q$.

## Die QR-Zerlegung

Die *reduzierte QR-Zerlegung* $A = \hat Q \hat R$ einer Matrix $A\in \mathbb{C}^{m \times n}$, $m \geq n$ sieht aus wie folgt:

![[QR-Zerlegung.png]]

$\hat Q$ ist wieder eine orthonormale Matrix.

Das ganze liest sich wie folgt:

- $q_1$ ist eine normierte Version von $a_1$, d.h. $q_{1}= \frac{a_{1}}{\|a_{1}\|} = \frac{a_{1}}{r_{11}}.$
- $q_{2}$ ist $a_2$, projiziert entlang $q_{1}$ (bzw. das Residuum von $a_2$ projiziert auf $q_1$), und normiert.
- $q_3$ ist das Residuum von $a_3$ projiziert auf die Ebene von $q_{1}$ und $q_{2}$, normiert
- und so weiter

Das heißt:
$$\begin{align*}a_{1}&= r_{11}q_{1} \\ a_{2}&= r_{12}q_{1}+r_{22}q_{2} \\ a_{3}&= r_{13}q_{1}+r_{23}q_{2}+r_{33}q_{3} \\ \vdots\end{align*}$$

$\hat R$ heißt im Englischen gerne $U$ - im Deutschen ist es eine rechte obere Dreiecksmatrix, im Englischen eine upper triangle matrix.

Die *vollständige QR-Zerlegung* $A = QR$ füllt die Matrix $\hat Q$ per < Basisergänzungssatz > zu einer [[Matrizen#^e32b56|unitären]] Matrix auf, während $\hat R$ mit Nullzeilen aufgefüllt wird: 
![[QR_vollständig.png|400]]


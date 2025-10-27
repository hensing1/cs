Datum: 06.06.
[[ThR_LA_Skript.pdf|Skript]] Seiten 65 bis 72

*Kapitel 6: Lineare Abbildungen*
# Eigenschaften von linearen Abbildungen

![[Lineare Funktionen#^19ee91]]

Das ganze ist recht intuitiv: 
Man nehme eine Basis für den Kern. Da der Kern ein Unterraum von $V$ ist, kann man die Basis des Kerns zu einer Basis von $V$ ergänzen. 
Die ergänzen Basisvektoren müssen, wenn sie durch $f$ abgebildet werden, zwingendermaßen das gesamte Bild von $f$ aufspannen, da die übrigen Basisvektoren ja alle auf 0 abgebildet werden. Da sie in $V$ linear unabhängig sind und nicht auf 0 abgebildet werden, müssen sie auch in $W$ linear unabhängig sein. Sie bilden also abgebildet eine Basis für das Bild.

> Eine lineare Abbildung $f: V \to W$ ist genau dann *injektiv*, wenn $\text{Kern}(f)=\set{0}$.

Da bei linearen Abbildungen die 0 immer auf die 0 zeigt, muss bei einer injektiven Abbildung zwingend der Kern $\set{0}$ sein. 
Umgekehrt muss eine Abbildung mit trivialem Kern auch injektiv sein: wäre sie nicht injektiv, dann gäbe es $v_{1},v_{2}\in V$ mit $v_{1}\neq v_{2}$ und $f(v_{1})=f(v_{2})$ und damit $0=f(v_{1})-f(v_{2})=f(v_{1}-v_{2})$, womit $v_{k}=v_{1}-v_{2}\neq 0$ ebenfalls im Kern läge.

Übrigens:
- Der Polynomraum ist unendlich-dimensional.
- $\text{dim}(\set{0})=0$, da die Basis für den Nullraum die leere Menge ist.


> Für einen *Endomorphismus* $f: V \to V$ mit $\text{dim}(V)\neq \infty$ gilt: $$f\text{ ist injektiv} \iff f\text{ ist surjektiv.}$$

Denn:
$f \text{ ist injektiv} \iff \text{Kern}(f)=\set{0} \iff \text{Df}(f)=0\iff \text{Rg}(f)=\text{dim}(V)\iff f \text{ ist surjektiv.}$

# Matrizen

Wegen der Isomorphie jedes endlichen Vektorraums zu Pfeilräumen betrachten wir nur noch $f : \mathbb{K}^{m} \to \mathbb{K}^{n}$.

Zunächst: 
> Sei $(e_1,\ldots,e_m)$ die kanonische Basis zu $\mathbb{K}^m$. Sei für eine lineare Abbildung $f: \mathbb{K}^{m}\to \mathbb{K}^{n}$ außerdem: $$f(e_{i})=\begin{pmatrix}a_{1i}\\a_{2i}\\\vdots\\a_{ni}\end{pmatrix}.$$
> Dann ist für $v \in \mathbb{K}^{m}$: $$f(v)=\begin{pmatrix}a_{11}v_{1}+a_{12}v_{2}+\ldots+a_{1m}v_{m}\\a_{21}v_{1}+a_{22}v_{2}+\ldots+a_{2m}v_{m}\\\vdots\\a_{n1}v_{1}+a_{n2}v_{2}+\ldots+a_{nm}v_{m}\end{pmatrix}.$$

Die Vektoren $f(e_1),f(e_2),\ldots,f(e_m)$ beschreiben also vollständig die Abbildung $f$.
Dies nimmt man zur Grundlage, eine Matrix als kompaktes Darstellungsschema für eine lineare Abbildung zu verwenden:

![[Matrizen#^628cdf]]

Konkret:
aus einer Gleichung $g: \mathbb{R}^{3} \to \mathbb{R}^{2}$ mit $$g(\begin{pmatrix}x\\y\\z\end{pmatrix})=\begin{pmatrix}ax+by+cz\\dx+ey+fz\end{pmatrix}$$ wird die darstellende Matrix: $$\text{DM}(g)=\begin{pmatrix}a&b&c\\d&e&f\end{pmatrix}.$$ ^432b44

Jede Matrix ist als Darstellung einer linearen Abbildung interpretierbar.

$\text{Hom}(\mathbb{K}^{m},\mathbb{K}^{n})$ ist also quasi eine Kopie der Menge aller $n \times m$-Matrizen.

![[Matrizen#^6bb850]]
![[Matrizen#^23aee7]]

Matrixmultiplikation ist äquivalent zur Hintereinanderausführung zweier linearer Funktionen
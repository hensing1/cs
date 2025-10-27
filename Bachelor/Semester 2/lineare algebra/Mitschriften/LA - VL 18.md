Datum: 20.06.
[[ThR_LA_Skript.pdf|Skript]] von Seite 93 bis 100

*Kapitel 9*
# Matrizen und Lineare Gleichungssysteme

## Erweiterte Koeffizientenmatrix

Eine Matrizengleichung $$A \cdot x = b$$ ist äquivalent zu dem *linearen Gleichungssystem* $$\begin{align*}
a_{11}x_{1}+\ldots+a_{1m}x_{m}&=b_{1}\\
\vdots\quad&\quad\vdots\\
a_{n1}x_{1}+\ldots+a_{nm}x_{m}&=b_{n}
\end{align*}$$wobei $a_{ij}$ die Koeffizienten der $n\times m$-Matrix $A$ bilden und $x$ und $b$ jeweils Vektoren sind.

Die Matrix $$(A,b)=\begin{pmatrix}a_{11}&\ldots&a_{1m}&b_{1} \\ \vdots & & \vdots & \vdots  \\ a_{n1}&\ldots&a_{nm}&b_{n}\end{pmatrix}$$ heißt **erweiterte Koeffizientenmatrix** des Gleichungssystems $A \cdot x = b$.

> Das Gleichungssystem ist *lösbar*, wenn $b \in \text{Bild}(A)$ ist.

## Lösungsmenge eines Gleichungssystems

> Die Lösungsmenge $\text{Lös}(A,0)=\text{Kern}(A)$ ist ein [[Vektorräume#Untervektorräume|Untervektorraum]] des $\mathbb{K}^{m}$.
> 
> Für jedes $z \in \text{Lös}(A,b)$ gilt: $\text{Lös}(A,b)=z+\text{Lös}(A,0) := \set{z+x \mid x \in \text{Lös}(A,0)}.$

Die Lösungsmenge $\text{Lös}(A,b)$ ist also für $b\neq 0$ *kein* Unterraum (da z.B. der Nullvektor nicht drin ist), sondern ein verschobener Unterraum, der erzielt werden kann, indem man $\text{Kern}(A)$ um einen beliebigen Vektor aus $\text{Lös}(A,b)$ verschiebt.

Es gilt umgekehrt:
> Für *jeden* Unterraum $U$ des $\mathbb{K}^{m}$ gibt es ein homogenes lineares Gleichungssystem $(A,0)$, sodass $U=\text{Lös}(A,0)$.
> Zusätzlich gibt es für jeden dieser Unterräume und für jedes $z \in \mathbb{K}^{m}$ ein lineares Gleichungssystem $(A,b)$, sodass $z+U=\text{Lös}(A,b)$.

## Umformen einer Matrix

Wenn man ein lineares Gleichungssystem löst, dann bringt man es in Zeilenstufenform.
Genauso kann man eine Matrix in ZSF bringen. Eine Matrix in Zeilenstufenform heißt Zeilenstufenmatrix (ZSM).

Ist eine ZSM quadratisch, dann heißt sie *obere Dreiecksmatrix*. 
Wenn sie zusätzlich ebenfalls über den Pivot-Elementen nur Nullen hat, und es außerdem keine Nullzeile gibt (d.h. jede "Stufe" ist 1 breit), dann hat man eine *Diagonalmatrix*. Bei einer Diagonalmatrix sind alle Koeffizienten Null, außer die auf der Diagonalen, die sind alle ungleich Null.

> Man kann durch *elementare Zeilenumformungen* (a.k.a. Rumgaußen) eine Matrix $A$ in eine Matrix $A'$ in *Zeilenstufenform* umformen.
> 
> Sei nun $(A,b)$ ein lineares Gleichungssystem. Dann gilt für jede erw. Koeffizientenmatrix $(A',b')$, welche durch elementare Zeilenumformungen aus $(A,b)$ hervorgeht: $$\text{Lös}(A,b)=\text{Lös}(A',b').$$

## Invertieren einer Matrix

Zunächst:
> Nur quadratische Matrizen sind invertierbar.

Klar, denn die Dimension des Wertebereichs muss gleich der Dimension des Definitionsbereichs sein.

Es gilt für eine invertierbare Matrix $A \in \text{Mat}(m \times m, \mathbb{K})$: $$A \cdot A^{-1}=E_{m}.$$
Wenn $A$ invertierbar ist, dann lässt sich $A$ mittels elementarer Zeilenumformungen in die Einheitsmatrix überführen.
Ansonsten würde man nämlich eine Nullzeile erhalten, und für eine Matrix mit Nullzeile ist der Kern nicht trivial, was bedeutet, dass die Matrix nicht invertierbar ist.

*Algorithmus zum Invertieren einer Matrix:*
Starte links mit der zu invertierenden Matrix $A$. Schreibe rechts daneben die Einheitsmatrix.

$$\left(\begin{matrix}1&2&3 \\ 1&0&1 \\ 0&1&0\end{matrix}\space\right|\space\left.\begin{matrix}1&0&0 \\ 0&1&0 \\ 0&0&1\end{matrix}\right)$$

Gauß' so lange rum, bis links die Einheitsmatrix steht. Bei jeder elementaren Zeilenumformung muss die rechte Seite ebenfalls umgeformt werden.

$$\left(\begin{matrix}1&0&0 \\ 0&1&0 \\ 0&0&1\end{matrix}\space\right|\space\left.\begin{matrix}-\frac{1}{2}&\frac{3}{2}&1 \\ 0&0&1 \\ \frac{1}{2}&-\frac{1}{2}&-1\end{matrix}\right)$$

Jetzt steht auf der rechten Seite $A^{-1}$.

### Allgemeine Invertierung einer 2x2-Matrix

Inverses zu $A:=\begin{pmatrix}\alpha& \beta\\ \gamma& \delta\end{pmatrix}$ ist $A^{-1}=\frac{1}{\alpha \delta-\beta \gamma}\begin{pmatrix}\delta& -\beta\\ -\gamma&\alpha\end{pmatrix}=\frac{1}{\text{det}(A^{-1})}\cdot \begin{pmatrix}\delta& -\beta\\ -\gamma&\alpha\end{pmatrix}.$

Datum: 13.06.
[[ThR_LA_Skript.pdf|Skript]] von Seite 73 bis 76

*Kapitel 7*
# Matrizen

Zu jeder linearen Abbildung gibt es genau eine darstellende Matrix (und umgekehrt):

> Die Funktion $$\begin{align*}\Phi: \text{Hom}(\mathbb{K}^{m},\mathbb{K}^{n})&\to \text{Mat}(n\times m, \mathbb{K})\\f &\mapsto \text{DM}(f) \end{align*}$$ ist ein Isomorphismus von Vektorräumen.

Das heißt unter anderem:
- $\text{DM}(f + g) = \text{DM}(f) + \text{DM}(g)$
- $\text{DM}(\lambda \cdot f) = \lambda \cdot \text{DM}(f)$

## Matrixmultiplikation

Zur Erinnerung: ![[LA - VL 15#^432b44]]
Daraus machen wir nun die Matrixmultiplikation:

$$g(\begin{pmatrix}x\\y\\z\end{pmatrix})=\text{DM}(g) \cdot \begin{pmatrix}x\\y\\z\end{pmatrix}=\begin{pmatrix}a&b&c\\d&e&f\end{pmatrix}\cdot\begin{pmatrix}x\\y\\z\end{pmatrix}=\begin{pmatrix}ax+by+cz\\dx+ey+fz\end{pmatrix}$$

Um $\text{DM}(g \circ f) = \text{DM}(g) \cdot \text{DM}(f)$ zu bestimmen, kann man zunächst die einzelnen Spalten der resultierenden Matrix ausrechnen (da ja eine Spalte in der Matrix den Funktionswert von dem entsprechenden Basisvektor darstellt): $(g \circ f)(e_{j})=g(f(e_{j})) \to j$-te Spalte in $\text{DM}(g \circ f)$.

Damit rechtfertigen wir folgende Definition:

![[Matrizen#^83f3d5]]
Merkregeln:
- Die Matrixmultiplikation entspricht der Hintereinanderausführung zweier Funktionen (die Funktion auf der rechten Seite wird zuerst ausgeführt)
- Die Resultierende Matrix hat die Zeilenanzahl der ersten Matrix und die Spaltenanzahl der zweiten Matrix: "$(n \times k) \cdot (k \times m) \to (n \times m)$"
- Die Matrixmultiplikation ist im Allgemeinen *nicht* kommutativ: $A \cdot B \neq B \cdot A$
- Die Matrixmultiplikation lässt sich 1 zu 1 auf die Multiplikation einer Matrix mit einem Vektor übertragen, wenn man den Vektor als einspaltige Matrix betrachtet.

> **Rechenregeln für Matrizen**
> - Assoziativität: $A \cdot (B \cdot C)=(A \cdot B) \cdot C$
> - Distributivität:
> 	- $A \cdot (B + C)= \cdot A \cdot B + A \cdot C$
> 	- $(A + B) \cdot C= A \cdot C + B \cdot C$


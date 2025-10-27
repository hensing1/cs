Datum: 04.07.
[[ThR_LA_Skript.pdf|Skript]] - Seiten 123 bis 141
 
# Determinante
## Bestimmung von Eigenwerten

Für einen  Eigenwert $\lambda$ ist $f(v) = Av= \lambda \cdot v$, d.h. $$Av-\lambda v = (A - \lambda \cdot E) v = 0$$soll mehr als den Nullvektor als Lösung haben.

Damit ist $\text{Dim}(\text{Kern}(A-\lambda \cdot E))>0$ und nach Dimensionssatz $\text{Rg}(A-\lambda \cdot E)< \text{dim}(V)$, d.h. $A-\lambda \cdot E$ ist *nicht invertierbar*.

Eine Matrix ist genau dann nicht invertierbar, wenn die Determinante gleich null ist.

Für $\mathbb{R}^2$:
$$\begin{pmatrix}e & f \\ g & h\end{pmatrix}-\lambda \cdot \begin{pmatrix}1 & 0 \\ 0 & 1\end{pmatrix}=\begin{pmatrix}e-\lambda & f \\ g & h-\lambda\end{pmatrix} \text{ nicht invertierbar} \iff 0=(e-\lambda)(h-\lambda)-gf =: p_A(\lambda).$$

$p_{A}(\lambda)$ heißt **charakteristisches Polynom** und ist die Determinante in Abhängigkeit von $\lambda$. Für eine $m \times m$-Matrix $A$ hat $p_{A}$ den Grad $m$.
> Die Eigenwerte sind genau die Nullstellen des charakteristischen Polynoms.

Zusammengefasst:
$$p_{A}(\lambda):=\det (A-\lambda \cdot E_{n}) = 0 \iff \lambda \text{ Eigenwert}$$

## Determinante für beliebige Dimensionen

![[Matrizen#^61445a]]

![[Matrizen#^544eb4]]

Man kann nach einer *beliebigen* Zeile oder Spalte entwickeln. Welche Sub-Determinante man addieren und welche man subtrahieren muss, merkt man sich mit dem Schachbrettmuster: $$\begin{matrix}+ & - & + & - & \ldots \\ - & + & - & + & \ldots \\ + & - & + & - & \ldots \\ - & + & - & + & \ldots \\ \vdots & \vdots & \vdots & \vdots & \ddots \end{matrix}$$
d.h. erreicht man irgendwann z.B. den Term $a_{32} \cdot |A_{32}|$, muss man ihn subtrahieren.

Das ist praktisch, wenn man irgendwo Nullen in seiner Matrix hat. Es empfiehlt sich, nach einer Spalte oder Zeile mit möglichst vielen Nullen zu entwickeln, da dann der komplette Term und die Berechnung der Sub-Matrix wegfällt.

### Gauß Gauß Gauß

Wenn man Gauß-Schritte auf seiner Matrix durchführt, dann ändert sich ggf. die Determinante, aber es ändern *nicht die Nullstellen des charakteristischen Polynoms* (d.h. für eine umgegaußte Matrix $A$ zu $A'$ ist $|A|=0 \iff |A'|=0$):

> *Satz 12.7*
> Sei $A'$ die umgegaußte Matrix $A$.
> - Wurden zwei Zeilen vertauscht, dann ist $\det A' = -\det A$.
> - Wurde eine Zeile mit $\lambda$ multipliziert, dann ist $\det A' = \lambda \det A$.
> - Wurde eine Zeile auf eine andere draufaddiert, dann ist $\det A' = \det A$.

Der Beweis zu Satz 12.7 ist wie ein ICE und der braust einfach durch.

Das ist für uns interessant, weil:
> Ist die Matrix in ZSF, dann ist die Determinante einfach das Produkt der Hauptdiagonale.

Das folgt aus dem Laplace'schen Entwicklungssatz.
Das erklärt auch, warum die Determinante genau dann Null ist, wenn die Matrix nicht invertierbar ist: eine Matrix ist genau dann invertierbar, wenn alle Einträge auf der Diagonalen ungleich Null sind. Matrix in ZSF nicht invertierbar $\iff$ Es gibt eine Null auf der Hauptdiagonalen $\iff$ Determinante ist Null.

> [!example] Zusammenfassung
> Folgende Aussagen für $A \in \text{Mat}(n \times n, \mathbb{K})$ sind äquivalent:
> - $\det A \neq 0$
> - $\text{Rg}(A)=n$
> - $\text{Df}(A)=0$
> - Die Zeilenvektoren von $A$ sind linear unabhängig
> - Die Spaltenvektoren von $A$ sind linear unabhängig
> - $A^{-1}$ existiert
> - $Ax=0$ besitzt eine eindeutige Lösung (Nullvektor)
> - $Ax=b$ besitzt eine eindeutige Lösung für jedes $b$.

![[Matrizen#^f02bda]]

## Diagonalisierung

Zur Erinnerung: bei der Diagonalisierung suchen wir nach $n$ linear unabhängigen Eigenvektoren für $f: \mathbb{K}^{n}\to \mathbb{K}^{n}$.
Es können auch mehrere dieser l.u. Eigenvektoren zum *selben* Eigenwert gehören. 

> [!important] Algorithmus zur Diagonalisierung
> 1. Wähle Basis $B$ für $V$ und schreibe $f$ als $A = \text{DM}_{B}(f).$
> 2. Bestimme $p_{A}(\lambda)=\det(A - \lambda E_{n})$.
> 3. Berechne die Linearfaktoren von $p_{A}$.
> 	1. Ist $\mathbb{K}=\mathbb{R}$ und $p_{A}$ zerfällt nicht in Linearfaktoren, haben wir nicht genug Eigenwerte und wir können aufhören.
> 4. < Berechne> pro Eigenwert (pro Nullstelle) eine maximale Anzahl linear unabhängiger Eigenvektoren.
> 	1. Gibt es insgesamt weniger als $n$ linear unabhängige Eigenvektoren, können wir aufhören.
> 5. Die Menge aller gefundenen Eigenvektoren ist eine Basis $C$ für $V$. Spaltenweise nebeneinander geschrieben bilden sie eine < Transformationsmatrix> $T^{C}_{B}$.

Schließlich ist $DM_{C}(f)=(T^{C}_{B})^{-1} \cdot A \cdot T^{C}_{B}$ die gesuchte Matrix in Diagonalform. Auf der Hauptdiagonalen dieser Matrix stehen nacheinander die Eigenwerte von $f$.
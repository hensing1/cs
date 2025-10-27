Datum: 24.11.
[[Skript_2023_01_26.pdf|Skript]] von S. 79 bis 86

# LU-Zerlegung
*Kapitel 6*

> Bei der LU-Zerlegung wird eine Matrix $A$ in eine *untere linke Dreiecksmatrix* $L$ und eine *obere rechte Dreiecksmatrix* $U$ zerlegt wird.

Im Deutschen heißt es auch LR-Zerlegung.

## Ohne Pivotisierung

$L$ hat Einsen auf der Hauptdiagonalen.

Man arbeitet mit dem Gauß-Verfahren. Informelle Beschreibung:

Sei $A = \begin{pmatrix}a & b & c \\ d & e & f \\ g & h & i\end{pmatrix}$. 
Um im ersten Schritt das Feld von $d$ auf Null zu setzen, rechnet man II - $\frac{d}{a} \cdot$ I und III - $\frac{g}{a}\cdot$ I. 

Dann ist $A = \begin{pmatrix}1& &  \\ \frac{d}{a} & 1 &  \\ \frac{g}{a} & & 1\end{pmatrix} \cdot \begin{pmatrix}a & b & c \\ 0 & \times & \times \\ 0 & \times & \times\end{pmatrix}$.

Diesen Prozess wiederholt man dann mit der nächsten Spalte.

Das Diagonalelement $u_{k,k}$, durch welches im $k$-ten Schritt geteilt wird, heißt *Pivotelement*.

> **LU-Zerlegung**
> 
> $L = I$
> $U = A$
> `for` $k = 1 \to m-1:$ *// $k$ Spaltenindex*
> > `for` $j=k+1 \to m:$ *// $j$ Zeilenindex*
> > > $l_{j,k}=u_{j,k}/u_{k,k}\quad$ *// Zelle in $L$: Zelle in $U$ geteilt durch Pivotelement*
> > > $u_{j,k:m} = u_{j,k:m}-l_{j,k}u_{k,k:m}$


*Komplexität:*
Implementiert benötigt die LU-Zerlegung ca. $\frac{2}{3}m^{3}$ Operationen $\to$ Faktor 2 schneller als QR-Zerlegung.

*Probleme:*
- Dieser Algorithmus hängt starkt vom Pivot-Element ab:
	- Ist das Pivotelement sehr klein bzw. $u_{k,k} \ll u_{j,k}$, wird der Algorithmus [[Numerik - VL 6#Stabilität|instabil]].
	- Ist das Pivotelement gleich 0, ist die Zerlegung nicht möglich.
## Mit Pivotisierung

Um die Instabilität zu lösen, welche durch ein kleines Pivotelement entsteht, erlauben wir die Permutation von Zeilen von $A$. 
Konkret wählen wir das *betragsmäßig größte Element* unterhalb der Diagonalen als Pivotelement: 
![[LUP.png|500]]

Konkret erhalten wir eine Zerlegung der Form $$PA = LU,$$wobei $P$ eine [[Matrizen#Permutationsmatrix|Permutationsmatrix]] ist.

Bei jeder Pivotisierung werden die entsprechenden Zeilen von allen Matrizen $L$, $U$ und $P$ vertauscht:

> **LU-Faktorisierung mit Pivotisierung**
> 
> $P=I$
> $L=I$
> $U=A$
> `for` $k = 1 \to m-1:$
> > Wähle $i \geq k$ mit maximalem $|u_{ik}|$
> > Vertausche Zeilen $i$ und $k$ von $L$, $U$ und $P$
> > `for` $j=k+1 \to m:$ 
> > > $l_{j,k}=u_{j,k}/u_{k,k}\quad$
> > > $u_{j,k:m} = u_{j,k:m}-l_{j,k}u_{k,k:m}$

## Cholesky-Faktorisierung


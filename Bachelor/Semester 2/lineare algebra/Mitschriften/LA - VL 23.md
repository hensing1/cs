Datum: 06.07.

13.2 und 13.5 sind komplette Beispiele fürs Diagonalisieren

Matrix ist diagonalisierbar $\iff$ Matrix hat $\dim(V)$ viele Eigenvektoren

Geometrische Vielfachheit: Dimension des Eigenraums
Algebraische Vielfachheit: Anzahl der Nullstellen (mit Vielfachheiten) des charakteristischen Polynoms

Es gibt mindestens einen Eigenvektor (verschieden von 0):
1 $\leq$ geometrische Vielfachheit $\leq$ Algebraische Vielfachheit

Charakteristisches Polynom: $\det (A_{1}-\lambda E_{3})$

**Mega-Beispiel**
Erstes Abbruchkriterium: wenn man weniger Nullstellen im char. Polynom hat, als es Zeilen in der Matrix gibt, ist die Matrix nicht diagonalisierbar und man kann aufhören

$p_{A_{2}}(\lambda)$ : $\text{algVH}(1)=2$, $\text{algVH}(-1)=1$ (1 und -1 sind Eigenwerte). Weil man zwei Eigenwerte hat, hat man auf jeden Fall 2 Eigenvektoren. D.h. man muss nur noch prüfen, ob $\text{geoVH}(1)=2$

Rausfinden der Eigenvektoren $\lambda$: Lösen des LGS $(A - \lambda \cdot E_{m})x=0$. -> Einen Vektor pro Nullzeile, die man rausbekommt

Wenn ich meine Basis aus den Eigenvektoren mache, welche Reihenfolge muss ich nehmen?
-> egal

Man kann sich auch die Matrixmultiplikation mit den Transformationsmatrizen am Ende sparen und einfach die Eigenvektoren entsprechend in die Diagonale schreiben (wenn nichts weiter gefragt ist)


jetzt scrollen wir ganz weit vor
# Jordanform

Wenn ich so ne Matrix hier nehme $$\begin{pmatrix}3 & 0 & 0 \\ 0 & 3 & 1 \\ 0 & 0 & 3\end{pmatrix}$$
dann kann ich direkt irgendwas ablesen

3 kommt dreimal vor -> algebraische Vielfachheit 3
einmal geloost -> geometrische Vielfachheit 2

wir malen lustige Kästchen
man kann die Kästchen tauschen
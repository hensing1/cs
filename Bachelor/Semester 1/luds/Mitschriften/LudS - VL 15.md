Datum: 01.12.
[[15VL-Scan-Kardinalitaeten.pdf|Folien]]

![[Mengen#Kardinalität]]

# Beweise
## Abzählbarkeit von Teilmengen
**Theorem:**
> Seien $A,B$ unendliche Mengen und $A \subseteq B$.
> Wenn $B$ abzählbar unendlich ist, ist auch $A$ abzählbar unendlich.

**Beweis:**
Gesucht ist eine Funktion $g : \mathbb{N} \rightarrow A$.

Hierfür nehmen wir zunächst eine Funktion $f : \mathbb{N} \rightarrow B$, welche die Elemente aus $B$ durchnummeriert.
Nun suchen wir alle Indizes von $f$ raus, für die gilt: $f(i) \in A$ (muss es ja geben, denn $A \subseteq B$).

Dann definieren wir die Funktion $h : \mathbb{N} \rightarrow \mathbb{N}$, welche auf genau diese Indizes abbildet (also $h(1)$ ist der erste Index, für den $f$ auf ein Element auf $A$ abbildet, $h(2)$ der zweite, usw).

Die Verknüpfung beider Funktionen $g : f \circ h$, also $g(x) = f(h(x))$, ist die gesuchte Abbildung von $\mathbb{N}$ auf $A$.

## Abzählbarkeit von $\mathbb{Z}$
Die Abzählbarkeit von $\mathbb{Z}$ lässt sich mit folgender [[Funktionen#Bijektive Funktion|Bijektion]] zeigen:
$$
f(n)=
\left\{
\begin{array}{ll}
\frac{n}{2} & \text{falls } n \text{ gerade}\\
-\frac{n-1}{2} & \text{falls } n \text{ ungerade}
\end{array}
\right.
$$
$\rightarrow f(0)=0, \space f(1)=-1, \space f(2) = 1, \ldots$

## Abzählbarkeit von $\mathbb{N} \times \mathbb{N}$
![[Beweistechniken#Cantor'sches Paarungsprinzip]]

## Abzählbarkeit von $\mathbb{Q}$
Wir wissen ja schon, dass $\mathbb{Z}$ abzählbar ist.
Da das Kreuzprodukt zweier abzählbahren Mengen ebenfalls abzählbar ist, ist $\mathbb{Z} \times (\mathbb{Z} \setminus \set{0})$  abzählbar unendlich.
Schließlich ist leicht einzusehen, dass die Funktion $f : \mathbb{Z} \times (\mathbb{Z} \setminus \set{0}) \rightarrow \mathbb{Q}$ mit $f(a,b) = \frac{a}{b}$ komplett auf $\mathbb{Q}$ abbildet, also [[Funktionen#Surjektive Funktion|surjektiv]] ist - und damit ist $\mathbb{Q}$ abzählbar unendlich. 

Beweis für $A \text{ abzählbar},  B \text{ abzählbar} \Rightarrow A \cup B \text{ abzählbar}$: 
Wenn $A$ endlich und $B$ abzählbar unendlich ist, kann man erst $A \setminus B$ abzählen und dann $B$.
Wenn $A$ und $B$ beide abzählbar unendlich sind, kann man wieder das Cantor'sche Paarungsprinzip verwenden.

## Überabzählbarkeit von $\mathbb{R}$
[[Beweistechniken#Diagonalisierung|Diagonalisierung]]
**Theorem:**
> $\mathbb{R}$ ist überabzählbar

**Indirekter Beweis:**
Wäre $\mathbb{R}$ abzählbar, dann wäre das Intervall $(0,1)$ ebenfalls abzählbar.

Angenommen es gibt eine Bijektion zwischen $\mathbb{N}$ und $(0,1)$:
$$f : \mathbb{N} \rightarrow (0,1)$$
$$
\begin{aligned}
f(1)&=a_{1}&=0,\underline{a_{11}}a_{12}a_{13}a_{14}\ldots\\
f(2)&=a_{2}&=0,a_{21}\underline{a_{22}}a_{23}a_{24}\ldots\\
f(3)&=a_{3}&=0,a_{31}a_{32}\underline{a_{33}}a_{34}\ldots\\
\vdots
\end{aligned}
$$
Jetzt kann ich aber eine neue Zahl generieren, die nicht im Wertebereich von $f$ sein kann, indem ich jede Ziffer $a_{ii}$ manipuliere (z.B. $a_{ii}+1 \mod n$) und zu einer neuen Zahl zusammenfasse. Diese neue Zahl unterscheidet sich von jeder einzelnen Zahl aus dem Wertebereich von $f$ an mindestens einer Stelle, und daher kann $(0,1)$ nicht abzählbar sein.
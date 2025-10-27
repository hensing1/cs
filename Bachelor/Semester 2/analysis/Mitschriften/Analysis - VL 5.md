Datum: 19.04.
[Annotiertes Skript](https://ecampus.uni-bonn.de/goto_ecampus_file_3016272_download.html)
[Vorlesungsnotizen](https://ecampus.uni-bonn.de/goto_ecampus_file_3016271_download.html)

**Bemerkungen vorweg**
- Die Definition für den Grenzwert arbeitet mit dem Betrag. Der Betrag einer komplexen Zahl ist eine reelle Zahl, d.h. die Definition funktioniert auch für komplexe Zahlenfolgen.
- Man kann Zahlenfolgen auch induktiv definieren:
	- $a_{1}:= 1$
	- $a_{n+1}=1+ \frac{1}{a_{n}}$
	- Das Resultat ist ein *Kettenbruch:* $1+ \frac{1}{1+\frac{1}{1+\frac{1}{1+\ldots}}}$


*Kapitel 2: Folgen und Reihen*
# Sätze für die Grenzwertberechnung
## Schachtelungsprinzip

> Gegeben zwei Folgen $(a_n)$ und $(b_n)$ mit Grenzwerten $a$ und $b$ sowie $a_{n}\leq b_n$ für alle $n$, dann gilt auch für die Grenzwerte $a\leq b.$

Es gilt jedoch $a_{n} < b_{n} \not\Rightarrow a<b$. Ein Beispiel dafür ist $a_{n}=0$ und $b_{n}=\frac{1}{n}$; beide haben den Grenzwert $0$.

> **Schachtelungsprinzip**
> Hat man zwei Folgen $(a_n),(c_n)$ mit demselben Grenzwert, dann hat jede Folge $(b_n)$, die dazwischen liegt, also $a_{n}\leq b_{n} \leq c_{n} \forall n \in \mathbb{N}$, auch diesen Grenzwert.

Das Schachtelungsprinzip ist hilfreich für die Grenzwertberechnung einer Folge, wenn man zwei weitere Folgen mit demselben Grenzwert finden kann, deren Elemente jeweils kleiner bzw. größer sind.

Beispiel $b_{n}=\frac{n}{2^{n}}$: Wir definieren $a_n=0$ und $c_{n}=\frac{n}{n^{2}}$. Dann gilt für $n>3$:
$$0<\frac{n}{2^{n}}\leq \frac{n}{n^{2}}=\frac{1}{n}\rightarrow0.$$

## Satz der monotonen Konvergenz

![[Folgen#^4895db]]

![[Folgen#^863038]]

Anders formuliert: betrachtet man die Menge aller Folgeglieder einer beschränkten, monotonen Folge, ist das Supremum bzw. das Infimum gleich dem Grenzwert (je nachdem, ob die Folge wächst oder fällt).

### Anwendung

> **Wurzel**
> Die Wurzel aus $a$ kann man als Grenzwert folgender Folge beschreiben:
> $$\begin{gather}x_{1}:=a \\ x_{n+1}:=\frac{1}{2}\left(x_{n}+\frac{a}{x_{n}}\right)\text{ für }n\in \mathbb{N}\end{gather}$$

Für diese Folge kann man (durch Einsetzen für $x_n$	bzw. $x_{n+1}$) die folgenden Aussagen treffen:
- $x_{n}^{2}-a\geq 0$
- $x_{n}\geq x_{n+1}$.

Durch die erste Aussage wissen wir, dass die Folge nach unten beschränkt ist. Durch die zweite wissen wir, dass sie monoton fallend ist. Also muss die Folge einen Grenzwert haben.

Wir wissen noch nicht, welcher Grenzwert das ist. Aber wir können bestimmen, dass gilt:
$$x_{n}x_{n+1}=x_{n}\cdot \frac{1}{2}(x_{n}+ \frac{a}{x_{n}})= \frac{1}{2}(x_{n}^{2}+a).$$
Und da sowohl $x_{n}$ und $x_{n+1}$ zum selben Wert konvergieren, gilt:
$$\begin{align*}
&x^{2}= \frac{1}{2}(x^{2}+a)\\
\iff &x^{2}=a.
\end{align*}$$

Also ist $x$ die Quadratwurzel von $a$.

## Intervallschachtelung

Wir führen den Begriff des Intervalls ein:
![[Mengen#Abgeschlossenes Intervall]]
![[Mengen#Offenes Intervall]]
![[Mengen#Halboffenes Intervall]]
![[Mengen#Uneigentliche Intervalle]]

![[Folgen#^ec6401]]
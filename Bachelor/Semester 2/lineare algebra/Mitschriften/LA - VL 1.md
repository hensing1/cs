Datum: 06.04.
Inhalt: [[ThR_LA_Skript.pdf|Skript]] - Seiten 8 bis 12

# Lösungsmengen
Für eine Gleichung $t(x_1,\ldots,n)=b$ interessiert uns die Lösungsmenge $\set{(x_{1},\ldots,x_{n})\mid t(x_{1},\ldots,x_{n})=b}$, und zwar mit einer möglichst lesbaren (d.h. übersichtlichen und expliziten) Formel $\varphi(x_{1},\ldots,x_{n})$: $\set{(x_{1},\ldots,x_{n})\mid t(x_{1},\ldots,x_{n})=b} = \set{(x_{1},\ldots,x_{n})|\varphi(x_{1},\ldots,x_{n})}$.

# Lineare Gleichungssysteme

Eine lineare Gleichung mit $n$ Unbekannten $x_1,\ldots,x_n$ hat die Form $a_{1}\cdot x_{1} + a_{2}\cdot x_{2} + \ldots + a_{n}\cdot x_{n} = b$.

> [!abstract] Definition
> Sei $\mathbb{K}$ ein Körper. Für *Koeffizienten* $a_{i,j}$ und *Unbekannte* $x_{i}$ heißt eine Menge linearer Gleichungen
> $$\begin{align*}
> a_{1,1}x_{1}+&\ldots&+a_{1,m}x_{m}&=b_{1}\\
> \vdots&&\vdots&\\
> a_{n,1}x_{1}+&\ldots&+a_{n,m}x_{m}&=b_{n}
> \end{align*}$$
> **Lineares Gleichungssystem** (LGS), mit $a_{i,j}\in \mathbb{K}$ und $b_{i}\in \mathbb{K}$.
> Ein solches System lässt sich auch mit $Ax=b$ abkürzen. 
> 
> Die *Lösungsmenge* ist definiert als
> $\text{Lös}(A,b)=\{(x_{1},\ldots,x_{m})\mid x_{1},\ldots,x_{m}\in \mathbb{K} \text{ und}$
> $a_{1,1}x_{1}+\ldots+a_{1,m}x_{m}=b_{1}, \ldots, a_{n,1}x_{1}+\ldots+a_{n,m}x_{m}=b_{n}\}.$
> 
> Ein LGS $Ax=b$ heißt *lösbar*, wenn $\text{Lös}(A,b)\neq\emptyset$.
> Enthält die Lösungsmenge genau ein Element, heißt es *eindeutig lösbar*.

Gilt $b_{1}=\ldots=b_{n}=0$, heißt ein LGS *homogen*. Ein homogenes Gleichungssystem hat mit dem Nullvektor immer eine Triviallösung.

Im Allgemeinen gilt für ein LGS entweder:
- es gibt keine Lösung, z.B. wenn es eine Gleichung der Form $0\cdot x = b$ mit $b \neq 0$ gibt, *oder*
- es gibt genau eine Lösung, *oder*
- es gibt unendlich viele Lösungen, bspw. wenn es weniger Gleichungen als Unbekannte gibt. Dann stehen in der Lösungsmenge manche Variablen in Abhängigkeit voneinander.
	- Beispiel: $x+y=2 \iff \mathbb{L}=\set{(x,y)\mid x=2-y}$.

## Zeilenstufenform
Ein LGS in Zeilenstufenform sieht folgendermaßen aus:
$$
\begin{align*}
a_{1,j(1)}x_{j(1)}+&&&\ldots&+&\ldots&+a_{1,m}x_{m}=b_{1}\\
&a_{2,j(2)}&+&\ldots&+&\ldots&+a_{2,m}x_{m}=b_{2}\\
&&&\ddots&\vdots\\
&&&&a_{i,j(i)}x_{j(i)}+&\ldots&+a_{i,m}x_{m}=b_{i}
\end{align*}
$$

Hierber ist $j : \mathbb{N} \rightarrow \mathbb{N}$ streng monoton steigend.
$a_{1,j(1)},a_{2,j(2)},\ldots,a_{i,j(i)}\neq 0$ heißen *Pivot-Elemente*.

Solche Gleichungssysteme können von unten nach oben gelöst werden, d.h. die kürzesten Gleichungen zuerst. 
Alle Variablen hinter dem Pivot-Element sind frei wählbar.
Die Variable des Pivot-Elements selbst ist: $$x_{j(i)}=\frac{1}{a_{i,j(i)}}\cdot(b_{i}-a_{i,j(i)+1}\cdot x_{j(i)+1}-\ldots-a_{i,j}\cdot x_{m}).$$
Wenn man sich dann von unten nach oben durcharbeitet, kann man immer die Variable der vorherliegenden Pivot-Elemente einsetzen und dann vereinfachen. In der Lösungsmenge muss man dann nur noch die Formeln für die Pivot-Elemente angeben.
Datum: 23.06.
[Video](https://uni-bonn.sciebo.de/s/YVfBpu1J5oiqZGj#/files_mediaviewer/Vorlesung-11-12.mp4)
[[Folien-2023-6-23.pdf|Folien]]
[[Skript AlgoII.pdf|Skript]] - Seiten 95 bis 109

# Lineare Programmierung

*Technik für den Entwurf polynomieller Algorithmen*

> [!abstract] Definition *Lineares Programm*
> Ein lineares Programm ist ein Optimierungsproblem, bei dem für $d$ relle Variablen $x_{1},\ldots,x_{d}\in \mathbb{R}$ optimale Werte bestimmt werden sollen, sodass eine lineare Zielfunktion $$c_{1}x_{1}+\ldots+c_{d}x_{d}$$für gegebene Koeffizienten $c_{1},\ldots,c_{d}\in \mathbb{R}$ *minimiert* oder *maximiert* werden soll.
> 
> Dabei müssen *lineare Nebenbedingungen* eingehalten werden. Die Nebenbedingungen sind in der Form $$\begin{gather}a_{11}x_{1}+\ldots+a_{1d}x_{d}\leq b_{1} \\ \vdots \\ a_{m1}x_{1}+\ldots+a_{md}x_{d}\leq b_{m}\end{gather}$$für Koeffizienten $a_{i1},\ldots,a_{id}, b_{i}\in \mathbb{R}$ für alle $i \in \set{1,\ldots,m}$.

> **Lineares Programm (kompakt)**
> Enthalte der Vektor $x=(x_{1},\ldots,x_{d})^{t}$ die Variablen und $c=(c_{1},\ldots,c_{d})^{t}$ die Koeffizienten der Zielfunktion. Dann kann die Zielfunktion als [[Matrizen#Skalarprodukt|Skalarprodukt]] $c \cdot x$ geschrieben werden.
> 
> Sei außerdem $A \in \text{Mat}(m\times d, \mathbb{R})$ die Matrix mit den Einträgen $a_{ij}$ und $b^{t}=(b_{1},\ldots,b_{m})\in \mathbb{R}^{m}$. Dann entspricht jede Zeile der Matrix einer Nebenbedingung.
> 
> Die Nebenbedingungen kann man nun als $Ax\leq b$ schreiben.
> 
> | *Optimierungsproblem* | |
> |-|-|
> | Eingabe: | $c\in \mathbb{R}^{d},b\in \mathbb{R}^{m}, A \in \text{Mat}(m\times d, \mathbb{R})$ |
> | Lösungen: | alle $x \in \mathbb{R}^{d}$ mit $Ax\leq b$ |
> | Zielfunktion: | minimiere/maximiere $c \cdot x$ |

## Kanonische Form und Gleichungsform

Man kann sich die Beschreibung von Algorithmen für lineare Programme erleichtern, wenn man lediglich Programme in einer festen, standardisierten Form betrachtet.

> *Kanonische Form*
> - Minimiere $c \cdot x$,
> - sodass $Ax \leq b$,
> - wobei jedes $x_{i}\geq 0$.

> *Gleichungsform*
> - Minimiere $c \cdot x$,
> - sodass $Ax = b$,
> - wobei jedes $x_{i}\geq 0$.

### Umformen eines LPs in Gleichungs- oder kanonische Form
- Maximierungsproblem $c \cdot x$ kann umgeformt werden in Minimierungsproblem von $-c  \cdot x$.
- Sind für eine Variable $x_{i}$ negative Werte erlaubt, kann jedes Vorkommnis von $x_{i}$ durch $(x_{i}'-x_{i}'')$ ersetzt werden, wobei $x_{i}' \geq 0$ und $x_{i}''\geq 0$. Durch diese Differenz kann jede relle Zahl dargestellt werden.
- Hat man eine Bedingung $a_{i}\cdot x \geq b_{i}$, wird diese umgeformt zu $-a_{i}\cdot x \leq -b_{i}$.
- Eliminierung einer Gleichung:
	- ersetze $a_{i}\cdot x=b_{i}$ durch $a_{i}\cdot x \leq b$ und $a_{i}\cdot x \geq b$.
- Eliminierung einer Ungleichung:
	- ersetze $a_{i}\leq x = b$ durch $s_{i}+a_{i}\cdot x = b$ für eine Schlupfvariable $s_{i}\geq 0$.

## Geometrische Interpretation

Jede Variablenbelegung $x$ entspricht einem Punkt im $\mathbb{R}^{d}$, also $x \in \mathbb{R}^{d}$.

Eine Nebenbedingung $a_{i}\cdot x = b_{i}$ definiert eine *affine Hyperebene* $\set{x \in \mathbb{R}^{d} \mid a_{i} \cdot x = b_{i}}$. Im $\mathbb{R}^{2}$ ist dies eine Gerade.

Hat die Bedingung die Form $a_{i}\cdot x \leq b$, definiert sie den *abgeschlossenen Halbraum* $\mathcal{H}_{i}=\set{x\in \mathbb{R}^{d} \mid a_{i}\cdot x \leq b_{i}}.$ Nun erfüllt jede Variablenbelegung $x \in \mathbb{R}^d$ genau dann die Nebenbedingung $i$, wenn $x \in \mathcal{H}_{i}$ gilt.
Die Belegung $x \in \mathbb{R}^d$ ist genau dann *gültig*, wenn $x \in \mathcal{P}:=\mathcal{H}_{1}\cap \ldots\cap \mathcal{H}_{m}\cap \mathbb{R}_{\geq 0}^{d}$.

Im $\mathbb{R}^{2}$ kann man das alles noch zeichnen:[^1]
![[Lineares_Programm.png|400]]

[^1]: $x_{G} und x_{B}$ sind hier die Variablen, jede Gerade gehört zu einer Nebenbedingung, die blaue Fläche ist die Menge aller gültigen Variablenbelegungen.

Die entstandende Lösungsmenge ist ein *konvexes Polyeder*. Eine Menge $X \in \mathbb{R}^{d}$ heißt konvex, wenn für jedes Paar $x,y \in X$ alle Punkte, welche auf der Linie zwischen $x$ und $y$ liegen, ebenfalls in $X$ enthalten sind:
![[Konvexe_Menge.png|340]]

Die Konvexität der Lösungsmenge ist wichtig. Daraus folgt nämlich das folgende Theorem:

> Ist eine Lösung $x \in \mathcal{P}$ für ein lineares Programm mit Lösungspolyeder $\mathcal{P}$ *lokal optimal*, dann ist es auch *global optimal*, d.h. es gibt kein $y \in \mathcal{P}$ mit $c \cdot y < c \cdot x$.

Das liegt daran, dass *jeder* Punkt auf der Linie zwischen $x$ und $y$, der nicht gleich $x$ ist, nicht nur in $\mathcal{P}$ enthalten wäre, sondern auch eine bessere Lösung wäre als $x$. Das wiederum liegt daran, dass die Zielfunktion $c \cdot x$ linear ist.

Eine Variablenbelegung ist dabei lokal optimal, wenn es ein $\epsilon>0$ gibt, für das es kein $y \in \mathcal{P}$ mit $\|x-y\|\leq \epsilon$ und $c \cdot y < x \cdot x$ gibt. Für den Algorithmus bedeutet das, dass man sich nur einen kleinen Bereich um eine Variablenbelegung ansehen muss, um zu prüfen, ob sie optimal ist.

### Geometrische Interpretation der Zielfunktion
Alle Werte, für die die Zielfunktion irgendeinen Wert $w$ annimmt, beschreiben ebenfalls eine affine Hyperebene $\set{x \in \mathbb{R}^{d}\mid c \cdot x = w}$ mit Normalenvektor $c$. Will man den Wert $w$ verkleinern, verschiebt man die Ebene entgegen dem Vektor $c$. 
Ist der Schnitt zwischen $\mathcal{P}$ und dieser Hyperebene nichtleer, muss man für eine optimale Lösung die Ebene solange verschieben, bis man die Grenze von $\mathcal{P}$ erreicht hat:
![[Lineares_Programm_Lösung.png|600]]

## Simplex-Algorithmus

### Informelle Beschreibung

Der Simplex-Algorithmus findet für ein lineares Programm immer eine optimale Lösung, oder er stellt fest, dass es keine solche Lösung gibt.
Es gibt keine optimale Lösung, wenn:
- das Lösungspolyeder leer ist, d.h. es gibt Nebenbedingungen, die sich gegenseitig ausschließen, wodurch es gar keine Lösung gibt
- das Problem unbeschränkt ist, d.h. das Lösungspolyeder ist unendlich groß und die Lösung kann beliebig gut werden.

Der Simplex-Algorithmus funktioniert so:
- Finde eine beliebige Ecke $x$ des Lösungspolyeders.
- Solange diese Ecke nicht lokal optimal ist:
	- Gehe zu einer beliebigen Ecke $x'$, für die $c \cdot x'<c \cdot x$ ist. Setze $x=x'$.
	- Falls es keine solche Ecke gibt, ist $x$ lokal optimal.

Einen Schritt von einer Ecke zur nächsten heißt *Pivot-Schritt*. Die Laufzeit eines Pivot-Schritts ist polynomiell in der Eingabelänge.

Der Simplex-Algorithmus ist im Allgemeinen kein "effizienter" Algorithmus, da es Eingaben gibt, für die exponentiell viele Pivot-Schritte benötigt werden. In der Praxis ist es aber so, dass solche Eingaben so gut wie gar nicht vorkommen, weswegen der Simplex-Algorithmus sehr erfolgreich in der Praxis angewendet wird.

### Finden eines Initialwerts
Die erste Ecke findet man ebenfalls mit dem Simplex-Algorithmus, indem man aus jeder Bedingung $a_{i}\cdot x=b_{i}$ die neue Bedingung $a_{i}\cdot x+h_{i}=b_{i}$ macht, wobei $h_{1},\ldots,h_{m}\geq 0$ Hilfsvariablen sind. Die Zielfunktion wird ignoriert und duch $h_{1}+\ldots+h_{m}$ ersetzt.
Findet man eine Optimallösung $h_{1}=\ldots=h_{m}=0$, hat man eine gültige Variablenbelegung gefunden. Man kann zeigen, dass dies auch eine Ecke sein muss.

Ist die optimale Lösung derart, dass mindestens ein $h_{i}>0$ ist, dann gibt es keine gültige Lösung für das ursprüngliche Problem.
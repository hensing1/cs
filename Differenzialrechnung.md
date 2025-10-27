## Differenzierbarkeit

> [!abstract] **Differenzierbarkeit**
> Eine Funktion $f : I \to \mathbb{R}$ heißt *differenzierbar in $x_{0}\in I$*, falls ein $a \in \mathbb{R}$ und eine Funktion $r_{x_{0}}: I \to \mathbb{R}$ mit $$\lim\limits_{x \to x_{0}}\frac{r_{x_{0}}(x)}{x-x_{0}}=0$$ existieren, sodass für alle $x \in I$ $$f(x)=f(x_{0})+a(x-x_{0})+r_{x_{0}}(x)$$ gilt. Dann heißt $a$ die *Ableitung von $f$ an der Stelle $x_0$* und wird mit $f'(x_0)$ bezeichnet.
> Die Funktion $f$ heißt *differenzierbar* (auf ganz $I$), falls $f$ in allen Punkten $x\in I$ differenzierbar ist. Die Funktion $f': I \to \mathbb{R}$ mit $x \mapsto f'(x)$ heißt dann *Ableitung von $f$*.

^5a34fe

Alternative, gleichwertige Formulierungen:
> Eine Funktion $f: I \to \mathbb{R}$ heißt differenzierbar an einer Stelle $x_0$, falls der Grenzwert $$\lim_{h \to0}\frac{f(x_0+h)-f(x_0)}{h}$$ existiert.

### Differenzierbarkeit im Mehrdimensionalen

> [!abstract] Definition
> Eine Funktion $f: U \to \mathbb{C}$ auf einer [[Mengen#Abgeschlossene/Offene Mengen|offenen Menge]] $U \subseteq \mathbb{R}^{n}$ heißt *differenzierbar* im Punkt $a \in U$, wenn es eine [[Lineare Funktionen#^955b6a|lineare Abbildung]] $L: \mathbb{R}^{n}\to \mathbb{C}$ gibt, sodass für jedes beliebige $h \in \mathbb{R}^{n}$: $$\lim\limits_{h \to 0}\frac{f(a+h)-f(a)-Lh}{\|h\|}=0.$$
> 
> $L$ heißt auch *Differenzial* oder *Linearisierung* von $f$ im Punkt $a$ und wird mit $df(a)$ oder $df\,a$ bezeichnet.

^05cbd8


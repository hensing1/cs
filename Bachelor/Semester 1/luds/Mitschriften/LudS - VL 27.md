Datum: 26.01.

# Resolutionskalkül
Man hat eine Wissensbasis (eine Menge von logischen Aussagen) und möchte damit ergründen, ob eine neue Aussage (mit denselben Variablen) *gültig* ist.

Man kann das machen, indem man all seine Formeln in die KNF überträgt.

Für eine Formel in KNF bildet man eine Menge von Klauseln:

$\varphi_{1}=(\lnot x_{1} \lor x_{2}) \land x_3$
$K(\varphi_{1}) = \set{\set{x_{3}},\set{\lnot x_{1},x_{2}}}$

So eine Menge ist dann quasi eine eindeutige Darstellung einer Formel - jede gleichwertige KNF wird in dieselbe Menge übertragen.
Aus einer Klauselmenge $K$ kann man natürlich wieder eine Aussage $\varphi_K$ in KNF bauen. 

Der Wahrheitswert einer Klauselmenge $K$ bezüglich einer Bewertung $B$ ist dann definiert als $$[\![K]\!]_{B}:=[\![\varphi_K]\!]_{B}$$
Definition von Erfüllbarkeit von $K$: bitte hier einfügen

Spezialfälle:
$K = \set{}$ ist nach Def. erfüllbar
$K = \set{\set{}}$ ist nach Def. *nicht* erfüllbar

Symbol für $\set{\set{}}$: $\set{\square}$.
$\square \in K \Rightarrow K \text{ nicht erfüllbar}$.

Wir versuchen jetzt aus unserer Klausel ein $\square$ abzuleiten.


## Systematisches Rausfinden
-> wir möchten *alle möglichen Resolventen* bilden.

> Sei $K$ Klauselmenge.
> Sei $\text{Res}(K) := K \cup \set{c \mid C \text{ ist Resolvente von Klauseln aus } K}$
> Sei zudem
> - $\text{Res}^{0}(K) := K$
> - $\text{Res}^{n+1}(K) := \text{Res}(\text{Res}^{n}(K))$ für $n \in \mathbb{N}_0$
> - $\text{Res}^{*}(K) := \bigcup\limits_{n\in \mathbb{N}}\text{Res}^{n}(K)$

Nun gilt:
Ist $K$ endlich, dann gibt es ein $n$, sodass $\text{Res}^n(K)=\text{Res}^{n+i}(K)=\text{Res}^{*}(K)$ mit $i \in \mathbb{N}$. Also terminiert der Prozess der Resolventenbildung irgendwann.
Beweis: sei $m=\text{Var}(K)$. Dann kann man nicht mehr als $2^{2m}$ Klauseln ($x_{1},\lnot x_{1},\ldots$) bilden - da die Menge $\text{Res}^{i+1}(K)$ nicht kleiner sein kann als $\text{Res}^i(K)$, und nicht endlos Dinge dazu kommen können, muss irgendwann $\text{Res}^{i}(K)=\text{Res}^{i+1}(K)$ gelten.
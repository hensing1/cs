Datum: 20.12.
Kapitel: *Gruppen, Halbgruppen, Monoide*
[[20VL-Scan-Ringe-Koerper.pdf|Folien]]

# Einschränkung von Monoid zu Gruppe
Vgl: [[Gruppe]]
Betrachte: $\mathbb{Z}_{4}=\mathbb{Z}/4\cdot\mathbb{Z}=\set{\overline{0},\overline{1},\overline{2},\overline{3}}$

$(\mathbb{Z}_{4}, \odot)$, also Multiplikation Modulo 4, ist ein (abelscher) *Monoid*:
- $\odot$ ist assoziativ ($a \odot (b \odot c) = (a \odot b) \odot c$) und kommutativ ($a \odot b = b \odot a$)
- $\overline{1}$ ist neutrales Element
- $\overline{0}$ und $\overline{2}$ sind nicht invertierbar (man kann nicht bei $\overline{1}$ landen)

$(\set{\overline{1},\overline{3}}, \odot)$ hingegen ist eine *Gruppe*, da dies die invertierbaren Elemente aus $\mathbb{Z}_4$ bzgl. $\odot$ sind.
Man kann das rausfinden mit einer *Verknüpfungstabelle*:
![[Verknüpfungstabelle_mult_mod_4.png|250]]

$(\mathbb{Z}_4,\oplus)$ ist hingegen eine *abelsche Gruppe*:
![[Verknüpfungstabelle_add_mod_4.png|250]]

# Ringe und Körper

![[Ringe und Körper#Definition]]

Gemäß obigem Beispiel ist $(\mathbb{Z}_{4},\oplus,\odot)$ ein *kommutativer Ring mit Eins* ($\mathbb{1}=\overline{1}$).
$(\set{\overline{1},\overline{3}},\cdot)$ ist die *Einheitengruppe*.

Weitere Beispiele:
- $(\mathbb{Z},+,\cdot)$ ist kommutativer Ring mit Eins. $(\set{1,-1},\cdot)$ ist die Einheitengruppe.
- $(\set{2a \mid a \in \mathbb{Z}},+,\cdot)$ ist kommutativer Ring *ohne* Eins. Dementsprechend gibt es keine Einheitengruppe.
- $(\mathbb{R},+,\cdot)$ ist kommutativer Ring mit Eins, $R ^{*} = \mathbb{R} \setminus \set{0}$.

## Körper
![[Ringe und Körper#Körper#Definition]]

## Ach übrigens
![[Ringe und Körper#Eigenschaften]]
### Beweis
$$
\begin{aligned}
a \cdot \mathbb{0} &= (a \cdot \mathbb{0}) + \mathbb{0}\\
&= (a \cdot \mathbb{0}) + ((a \cdot \mathbb{0}) + (-(a \cdot \mathbb{0}))) & (\text{add. Inverse zu }(a \cdot \mathbb{0}))\\
&= ((a \cdot \mathbb{0}) + (a \cdot \mathbb{0})) + (-(a \cdot \mathbb{0})) & (\text{assoz. von }+)\\
&= (a \cdot (\mathbb{0}+\mathbb{0}))+(-(a \cdot \mathbb{0})) & (\text{Distributivgesetz})\\
&= (a \cdot \mathbb{0}) + (-(a \cdot \mathbb{0}))\\
&= \mathbb{0}
\end{aligned}
$$
## Restklassenkörper
Nächstes Theorem:
> $(\mathbb{Z}_{n}, \oplus_{n}, \odot_{n})$ ist ein Körper, genau dann wenn $n$ eine Primzahl ist.

$(\mathbb{Z}_{n},\oplus)$ ist für jedes $n$ eine abelsche Gruppe, weil man auf jeden Fall immer irgendwie auf die $[0]$ kommen kann ($[k] + [n-k] = [n] = [0]$). Weil bestimmt auch irgendwie die Distributivgesetze gelten, ist $(\mathbb{Z}_n,\oplus,\odot)$ auf jeden Fall ein Ring (Restklassenring).

Damit es jetzt zu einem Körper wird, muss jedes Element (außer $[0]$) ein multiplikatives Inverses besitzen, man muss also irgendwie auf die $[1]$ kommen.

**Beweis:**
$n \text{ Primzahl} \Rightarrow (\mathbb{Z_n},\oplus,\odot) \text{ Körper}$
Wenn $n$ Primzahl, dann sind alle $1 \leq a \leq n-1$ mit $n$ teilerfremd.
Wenn $p$ und $q$ teilerfremd, dann existiert $x,y \in \mathbb{Z}$ mit $p \cdot x + q \cdot y = 1$.

Also existiert ein $x,y \in \mathbb{Z}$ sodass:
$\begin{aligned}[] [a] \odot [x] &= ([a] \odot [x]) \oplus [0]\\&=([a] \odot [x])\oplus [ny]\\ &= [ax] \oplus [ny] \\ &= [ax+ny] \\ &= [1].\end{aligned}$

$n \text{ keine Primzahl} \Rightarrow (\mathbb{Z_n},\oplus,\odot) \text{ kein Körper}$
Sei $(\mathbb{Z_n},\oplus,\odot)$ Körper, dann müssten $[a],[b] \in \mathbb{Z}_{n}$ invertierbar bzgl. Multiplikation sein.
Da $n$ aber keine Primzahl ist, muss es $[a] \odot [b] = [ab] = [n] = [0]$ geben. $[0]$ ist nicht invertierbar.
Daher gibt es kein Inverses Element $[ab]^{-1}$, und da $[ab]^{-1} = [a]^{-1} \odot [b]^{-1}$, können nicht sowohl $[a]$ als auch $[b]$ invertierbar sein (wären beide invertierbar, dann wäre auch $[ab]$ invertierbar).
$\square$

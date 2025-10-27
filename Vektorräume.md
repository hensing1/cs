# Der Raum $\mathbb{K}^{n}$
> [!abstract] Definition
> Sei $\mathbb{K}$ ein [[Ringe und Körper#Körper|Körper]] und $n \in \mathbb{N}$. Es sei $\mathbb{K}^{n}:=\set{\mathbb{K}^{n}, +, \cdot, 0}$, definiert wie folgt:
> - $\mathbb{K}^{n}=\set{(x_{1},\ldots,x_{n})\mid x_{1}, \ldots, x_{n}\in \mathbb{K}}$. Die Elemente dieser Menge heißen **[[Vektoren]]**.
> - Die **Vektoraddition** "$+$" für zwei Vektoren $x,y \in \mathbb{K}^{n}$ ist definiert als $$(x_{1},\ldots,x_{n})+(y_{1},\ldots,y_{n}):=(x_{1}+y_{1},\ldots,x_{n}+y_{n}).$$
> - Die **Skalarmultiplikation** "$\cdot$" für einen *Skalar* $\lambda\in \mathbb{K}$ und einen Vektor $x \in \mathbb{K}^{n}$ ist definiert als $$\lambda\cdot(x_{1},\ldots,x_{n}):=(\lambda\cdot x_{1},\ldots,\lambda \cdot x_{n}).$$
> - Der **Nullvektor** ist $0=(0,\ldots,0) \in \mathbb{K}^{n}$.
> - Das **additive Inverse** für $x\in \mathbb{K}^{n}$ ist $-x=(-x_{1},\ldots,-x_{n})$.
> - Die **Vektorsubtraktion** "$-$" für $x,y \in \mathbb{K}^{n}$ ist definiert als $x-y=x + (-y)$.

^1ba9f8

# Vektorräume
> [!abstract] Definition
> Sei $\mathbb{K}$ ein [[Ringe und Körper#Körper|Körper]]. 
> Ein **$\mathbb{K}$-Vektorraum** oder **Vektorraum über $\mathbb{K}$** ist eine Struktur $V=(V,+,\cdot)$ mit den [[Funktionen|Abbildungen]] *Addition* $$+: V \times V \to V, \quad (x,y)\mapsto x+y$$ und *Skalarmultiplikation* $$\cdot : \mathbb{K} \times V \to V, \quad (\lambda,x) \mapsto \lambda \cdot x$$, für welche die folgenden Axiome gelten:
> - *Assoziativgesetz* gilt für $x,y,z \in V$
> - *Kommutativgesetz* gilt für $x,y \in V$
> - Es gibt ein $0 \in V$, sodass $\forall x \in V: x+0=x$
> - Jedes $x \in V$ hat ein *Inverses* $y \in V$, sodass $x+y=0$
> - *Assoziativgesetz* gilt für $\lambda,\mu\in \mathbb{K}$ und $x\in V$: $(\lambda \cdot \mu) \cdot x = \lambda \cdot (\mu \cdot x)$
> - Für $\mathbb{1} \in \mathbb{K}$ und $x \in V$ gilt $1 \cdot x = x$
> - Für die Skalarmultiplikation gelten beide *Distributivgesetze*.

^70bbb5

> In Vektorräumen ist das Nullelement eindeutig. Für jedes $x \in V$ gibt es genau ein additives Inverses.

^dfd735

## Basis
![[LA - VL 9#^567731]]

## Untervektorräume
> [!abstract] Definition
> Sei $V=(V,+,\cdot,0)$ ein $\mathbb{K}$-Vektorraum und sei $U \subseteq V$.
> $U$ heißt **Unterraum** oder **Untervektorraum** (UVR) von $V$, wenn:
> - $U \neq \emptyset$
> - $\forall x,y \in U: \forall \lambda \in \mathbb{K}: x+y \in U \land \lambda \cdot x \in U$ (Abgeschlossenheit bzgl. $+$ und $\cdot$).

> Ein Untervektorraum $U$ von $V$ ist auch ein Vektorraum, d.h. $0 \in V$ ist ebenfalls in $U$ und jedes $x \in U$ besitzt ein additives Inverses in $U$.

> Sind $U_{1},U_{2}$ Untervektorräume von $V$, dann ist der Schnitt $U_{1}\cap U_{2}$ ebenfalls ein Untervektorraum von $V$.

## Euklidischer Vektorraum
> [!abstract] Definition *Euklidischer Vektorraum*
> Ein euklidischer Vektorraum ist ein Paar $(V, \langle \cdot, \cdot \rangle)$ bestehend aus einem [[Vektorräume#^70bbb5|Vektorraum]] und einem [[Vektoren#Skalarprodukt|Skalarprodukt]].

## Linearkombination
xrandr
![[LA - VL 9#^9b8d50]]
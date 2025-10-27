# Ring
## Definition
> [!abstract] Definition
> Es sei $R$ eine [[Mengen|Menge]] mit zwei [[Verknüpfung|Verknüpfungen]] $+$ und $\cdot$.[^1] 
> $(R,+,\cdot)$ ist ein **Ring**, wenn die folgenden drei Eigenschaften gelten:
> 1. $(R,+)$ ist eine [[Gruppe#Definition|abelsche Gruppe]].
> 2. Die Verknüpfung $\cdot$ ist [[Verknüpfung#Definition|assoziativ]].[^2]
> 3. Es gelten die *Distributivgesetze*:
> 	- $a \cdot(b + c) = (a \cdot b) + (a \cdot c)$ (linke Distributivität)
> 	- $(a+b) \cdot c = (a \cdot c) + (b \cdot c)$ (rechte Distributivität)
> 
> $(R,+,\cdot)$ heißt **kommutativer Ring**, wenn $\cdot$ [[Verknüpfung#Definition|kommutativ]] ist.
> 
> Falls $(R,\cdot)$ ein [[Verknüpfung#Neutrales Element|neutrales Element]] besitzt[^3], nennt man $(R,+,\cdot)$ **Ring mit Eins**.
> 
> Alle $x \in R$, welche bezüglich $\cdot$ [[Verknüpfung#Inverses Element|invertierbar]] sind, heißen *Einheit*. $R ^{*} \subseteq R$ heißt *Menge der Einheiten*.
> $(R ^{*},\cdot)$ ist damit eine [[Gruppe]]. Diese heißt auch **Einheitengruppe** von $R$.

^b3466f

> Das neutrale Element von $(R,+)$ erhält die Bezeichnung **$\mathbb{0}$**.
> Falls es existiert, erhält das neutrale Element von $(R,\cdot)$ die Bezeichnung **$\mathbb{1}$**.

> Bezüglich $+$ wird das eindeutig inverse Element zu $x$ mit $-x$ bezeichnet.
> Bezüglich $\cdot$ wird es mit $x^{-1}$ bezeichnet.

[^1]: $+$ und $\cdot$ sind an dieser Stelle nur allgemeine Symbole für die Verknüpfungen. Sie haben im Allgemeinen nichts mit der gewöhnlichen Addition und Multiplikation zu tun.
[^2]: Damit ist $(R,\cdot)$ eine [[Gruppe#Definition|Halbgruppe]].
[^3]: also wenn $(R,\cdot)$ ein Monoid ist

## Eigenschaften
Für einen Ring $(R,+,\cdot)$ mit $\mathbb{0}$ als neutrales Element von $+$ und $\mathbb{1}$ als neutrales Element von $\cdot$ gilt:
$$\mathbb{0} \cdot a = a \cdot \mathbb{0} = \mathbb{0} \quad \forall a \in R.$$
Damit besitzt das neutrale Element der Addition kein multiplikatives Inverses.
Dasselbe gilt auch für [[Ringe und Körper#Körper|Körper]].

[[LudS - VL 20#Ringe und Körper#Beweis|Beweis]]

# Körper
## Definition
> [!abstract] Definition
> Sei $(R,+,\cdot)$ ein [[Ringe und Körper#Ring|Ring]]. Falls $(R \setminus \set{\mathbb{0}},\cdot)$ eine [[Gruppe#Definition|abelsche Gruppe]] ist, heißt $(R,+,\cdot)$ ein **Körper**.
> 
> Anders formuliert:
> Sei $\mathbb{K}$ ein kommutativer Ring mit Eins. $\mathbb{K}$ heißt *Körper*, wenn $0\neq 1$ und jedes $a \in \mathbb{K}$ mit $a \neq 0$ eine *Einheit* ist.

## Angeordneter Körper
> Ein Körper kann **angeordnet** werden, falls eine [[Relationen#Ordnungsrelation|Ordnungsrelation]] auf ihn definiert werden kann.

### Beschränkte Teilmengen
Sei $(K,+,\cdot,\leq)$ ein angeordneter Körper und $A \subseteq K$.

> [!abstract] **Schranken**
> Gibt es ein $S\in K$, sodass $x\leq S$ für alle $x \in A$ gilt, dann heißt $S$ *nach oben beschränkt*.
> $S$ heißt dann *obere Schranke von $A$* (ebenso wie alle $x\in K$ mit $S \leq x$).
> 
> Gleichermaßen ist die *untere Schranke* definiert.

> [!abstract] **Supremum und Infimum**
> Falls für $S\in K$ die *kleinste obere Schranke* ist, also wenn $S$ obere Schranke ist und für alle obere Schranken $S'$ gilt, dass $S\leq S'$, heißt $S$ *Supremum von $A$* und man schreibt $S=\text{sup}(A)$.
> 
> Gleichermaßen heißt die *größte untere Schranke* $s$ das *Infimum von $A$* und man schreibt $s=\text{inf}(A)$.

^10fa08

> [!abstract] **Minimum und Maximum**
> Gilt $\text{sup}(A)\in A$, heißt $\text{sup}(A)$ das *Maximum von $A$* und man schreibt $\text{sup}(A)=\text{max}(A)$.
> 
> Gilt $\text{inf}(A)\in A$, heißt $\text{inf}(A)$ das *Minimum von $A$* und man schreibt $\text{inf}(A)=\text{min}(A)$.

### Vollständigkeit
> Ein angeordneter Körper $K$ heißt **vollständig**, wenn jede nichtleere, nach oben beschränkte Teilmenge $A\subset K$ ein Supremum besitzt.

Ein $S\in K$ ist genau dann das Supremum von $A$, wenn für alle $x\in A: x\leq S$ gilt, und für jedes $\epsilon > 0$ ein $x \in A$ existiert, sodass $S-\epsilon<x\leq S$.

> [!info]- Beispiele
> - Der Körper $\mathbb{R}$ der reellen Zahlen ist vollständig.
> - Der Körper $\mathbb{Q}$ der rationalen Zahlen ist *nicht* vollständig: z.B. hat die Menge $\set{x\in \mathbb{Q} \mid x^{2} < 2}$ kein Supremum, da $\sqrt{2}\not\in \mathbb{Q}$.

### Betragsfunktion
> [!abstract] Definition
> Sei $\mathbb{K}=(K,+,\cdot)$ ein [[Ringe und Körper#Angeordneter Körper|angeordneter Körper]]. Für ein beliebiges $k\in K$ setzen wir
> $$|k|:=\left\{\begin{aligned}a, \text{ falls }a\geq \mathbb{0},\\-a, \text{ falls } a<\mathbb{0}.\end{aligned}\right.$$
> $|k|$ heißt der **Betrag von $k$.**

Nun gelten für alle $a,b\in K$:
1. *Definitheit:* $|a|\geq \mathbb{0}$ und $(|a|=\mathbb{0}\iff a=\mathbb{0})$
2. *Homogenität:* $|a \cdot b| = |a| \cdot |b|$
3. *Dreiecksungleichung:* $|a+b|\leq|a|+|b|$
4. $||a|-|b||\leq|a-b|$

Ist eine Abbildung $|\cdot|:K \rightarrow \mathbb{R},\quad x \mapsto |x|$ definiert, spricht man von einem **normierten Körper**. Ein angeordneter Körper ist *immer* normiert, jedoch kann ein normierter Körper nicht unbedingt angeordnet werden - ein Beispiel hierfür ist der Körper der [[Komplexe Zahlen|komplexen Zahlen]].
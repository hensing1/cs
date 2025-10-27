# Gruppe
## Definition

> [!abstract] Definition
> Für eine [[Mengen|Menge]] $G$ und eine [[Verknüpfung]] $\circ$ auf $G$ heißt $(G, \circ)$ **Gruppe**, falls die folgenden drei *Gruppenaxiome* gelten:
> 1. Die Verknüpfung $\circ$ ist *assoziativ*.
> 2. Es existiert ein *neutrales Element* $e \in G$.
> 3. Jedes Element $g \in G$ hat ein *inverses Element* $g^{-1}$.
> 
> Gilt (1), ist $(G, \circ)$ eine **Halbgruppe**.
> Gelten (1) und (2), ist $(G, \circ)$ ein **Monoid**.
> 
> Ist $\circ$ *kommutativ*, heißt $(G, \circ)$ **abelsch**.

^07c2a6

Es gibt also *abelsche Gruppen*, *abelsche Halbgruppen* und *abelsche Monoide*.

## Rechenregeln
Für eine Gruppe $(G, \circ)$ gelten die folgenden Rechenregeln:

> [!info] *Kürzungsregeln*
> Für alle $a,x,y \in G$ gilt:[^2] $$\begin{aligned}a \circ x = a \circ y \Rightarrow x=y\\x \circ a = y \circ a \Rightarrow x=y\end{aligned}$$
> Dies gilt, falls $a$ invertierbar ist, also auch für die Einheiten 

> [!stift] *Eindeutige Lösungen von Gleichungen*
> Für alle $a,b \in G$ existiert *genau ein* $x \in G$ mit $a \circ x = b$ sowie *genau ein* $y \in G$ mit $y \circ a = b.$[^3]

Für einen Monoiden $(M,\circ)$ gilt:
> Sind $a,b \in M$ invertierbar, dann ist auch $a \circ b$ invertierbar. Konkret ist $(a \circ b)^{-1} = a^{-1} \circ b^{-1}.$

^ffcaaa

Warum? $$\begin{align*}
(a \circ b) \circ (a^{-1} \circ b^{-1}) &= (a \circ b) \circ (b^{-1} \circ a^{-1}) & \text{(Kommutativität)}\\
&= a \circ (b \circ b^{-1}) \circ a^{-1} & \text{(Assoziativität)}\\
&= a \circ e \circ a^{-1}\\
&= a \circ a^{-1}\\
&= e
\end{align*}$$

[^2]: Beweis: $x = e \circ x = (a^{-1} \circ a) \circ x = a^{-1} \circ (a \circ x) = a^{-1} \circ (a \circ y) = (a^{-1} \circ a) \circ y = e \circ y = y.$
[^3]: Beweis: $a \circ (a^{-1} \circ b)=(a \circ a^{-1})\circ b=e\circ b=b$ $\Rightarrow x=a^{-1}\circ b$ ist Lösung für $a \circ x=b$. Aus den Kürzungsregeln folgt, dass $x$ eindeutig sein muss.

## Gruppenoperation

> [!abstract] Definition *Gruppenoperation*
> Sei $(G, \cdot)$ eine Gruppe und $X$ eine Menge, dann ist $\rhd: G \times X \to X$ eine *Gruppen(-links-)operation*, wenn:
> 1. 
> 2.

^7080f1


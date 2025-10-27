Datum: 03.04.
Inhalt: [[Skript Analysis - SS2023 - Welter.pdf#page=5|Skript]] bis S. 13

# Dinge vorweg
## Inhaltliche Voraussetzungen
- [[Mengen]] und [[Funktionen#Funktion / Abbildung|Abbildungen]]
- [[Mengen#Natürliche Zahlen|Natürliche Zahlen]], [[Beweistechniken#Vollständige Induktion|vollständige Induktion]]
- [[Gruppe|Gruppen]], [[Ringe und Körper]]

## Konventionen in dieser Vorlesungen
- $\mathbb{N}$ enthält *nicht* die $0$
- $A \subset B$ ist dasselbe wie $A \subseteq B$

# Die reellen Zahlen: archimedisch angeordneter Körper

Man kann die reellen Zahlen aus einem kleineren Axiomensystem "herleiten" (aus den natürlichen Zahlen), wir nehmen sie aber als eigenes Axiom an.

> **Axiom**
> $(\mathbb{R}, +, \cdot)$ ist ein [[Ringe und Körper|Körper]].

Für diesen Körper kann man (axiomatisch) eine *[[Relationen#Ordnungsrelation|Ordnungsrelation]]* $\leq$ definieren.
Dadurch kann man den Körper der reellen Zahlen einen **angeordneten Körper** nennen.

Die anderen Ordnungsrelationen $\geq, <, >$ lassen sich aus $\leq$ ableiten.

Gibt es eine Ordnungsrelation für einen Körper, dann muss dieser Körper unendlich viele Elemente haben: 
- Es gibt die beiden neutralen Elemente 1 und 0, die nicht gleich sind, also eine Ordnung haben müssen
- Sei $1 > 0$
- Dann gilt (gemäß Definition der Ordnungsrelation) auch $1+a>0+a$ für irgendein $a$
- Sei $a=1$: man kann nun $a$ beliebig oft draufaddieren

Monotonie der Quadratfunktion: $a < b \Rightarrow a^{2} < b^{2}$

> **Rekursive Definition von Potenzen mit ganzzahligen Exponenten:**
> $$\begin{gather}
a^{0}:=1\\
a^{n+1}:=a^{n}\cdot a
\end{gather}$$
> für $n\in \mathbb{N}_{0}$. Außerdem: $$a^{-n}:=(a^n)^{-1},$$ für $n\in \mathbb{N}$ und $a \neq 0$, sodass $a^{-n}$ das multiplikative Inverse von $a^{n}$ ist.

**Fortsetzung:** wir haben eine Funktion und *erweitern* deren Definitionsbereich. Mit diesem Ansatz kann man z.B. die Exponentialfunktion für Exponenten aus $\mathbb{Z}$ (wie oben definiert) auf Exponenten aus $\mathbb{Q}$ oder $\mathbb{R}$ erweitern.

> **Bernoulli-Ungleichung**
> $$(1+x)^{n}\geq1+n \cdot x$$
> für jedes $x\in\mathbb{R},x>-1$ und $n\in\mathbb{N}_0$.

Wir können für die reellen Zahlen eine Betragsfunktion definieren [[Ringe und Körper#Betragsfunktion|wie für jeden angeordneten Körper]].


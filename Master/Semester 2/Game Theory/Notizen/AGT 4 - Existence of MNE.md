[[lecturenotes04.pdf]]

Heute betrachten wir Normal Form Games, bei denen wir eine Utility $u$ maximieren statt Kosten $c$ minimieren. Das ist äquivalent.

## Nash's Theorem

> **Nash's Theorem**
> Jedes endliche Normal Form Game hat ein [[AGT 3 - NFGs and MNEs#^3cbea7|Mixed Nash Equilibrium]].

Wir beweisen das mit *Brouwers Fixpunkt-Theorem*: "Jede stetige Funktion $f: D \to D$, mit $D$ [[Mengen#Kompakte Mengen|kompakt]], konvex und nichtleer, hat einen Fixpunkt $f(x^{*})=x^{*}$."

Beweisidee:
- Wir setzen $D \subseteq \mathbb{R}^{m}$ mit $m=\sum_{i=1}^{n}|S_{i}|$. Nun ist jedes Mischstrategie-Profil ein Punkt in $D$.
- Wir definieren eine stetige Funktion $f: D \to D$, die einen Punkt $x \in D$ verschiebt, wenn jemand seine durch $x$ beschriebene Strategie verbessern kann.
- Die Fixpunkte von $f$ sind Mixed Nash Equilibria.

## Nash Equilibria berechnen


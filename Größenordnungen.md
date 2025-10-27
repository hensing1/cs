Größenordnungen in O-Notation sind der übliche Weg, um Laufzeiten von [[Algorithmen]] zu beschreiben.
# Obergrenze
Wenn **ab einem gewissen Punkt** eine Funktion $g(x)$, ggf. skaliert mit einer Konstante $c$, für jedes $x$ einen höheren Wert hat als eine Funktion $f(x)$, dann schreibt man:
$$f=O(g)$$
-> $f$ wächst nicht schneller als $g$.

Formell:
$$f=O(g) \iff \exists c \in \mathbb{R} : \exists n _{0} \in \mathbb{N} : \forall n \ge n_{0} : f(n) \le c * g(n)$$
Wächst $f$ *langsamer* als $g$ (also $\lim _{x \to \infty} \frac{f(x)}{g(x)} = 0$), schreibt man:
$$f=o(g)$$
# Untergrenze
Entgegengesetzt: wenn $f$ (skaliert) *mindestens* so schnell wächst wie $g$, schreibt man:
$$f=\Omega (g)$$
Wächst $f$ schneller als $g$, schreibt man:
$$f=\omega(g)$$
> [!info]
> $f=\Omega (g) \iff g=O(f)$
> $f=\omega (g) \iff g=o(f)$

# Gleiche Größenordnung
Wenn $f=O(g)$ und $f=\Omega (g)$, dann sind $f$ und $g$ in der gleichen Größenordnung und man schreibt:
$$f=\Theta(g)$$

---
# Geltungsbereich
Die O-Notation kann angewendet werden auf alle Funktionen, die asymptotisch positiv sind:
![[Glossar#Asymptotisch Positiv]]

---

Beispiele:
- $n^{2}=o(n^{3})$
- $n^{3}=\omega({n^{2}})$
- $999*n^{2}+90*n+2000=\Theta({n^{2}})$
- $\log(x)=o(\log^2(x))$
- $\log^2(x)=o(\sqrt{x})$:
	- ![[log^2_vs_sqrt.png]]

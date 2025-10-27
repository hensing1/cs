Datum: 12.04.
Unterlagen: 
- [Vorlesungsnotizen](https://ecampus.uni-bonn.de/goto_ecampus_file_3005096_download.html)
- [Annotiertes Skript](https://ecampus.uni-bonn.de/goto_ecampus_file_3005097_download.html)

# Vollständigkeit der reellen Zahlen

Die Vollständigkeit eines Körpers definieren wir mithilfe des Begriffs des *Supremums*: 
![[Ringe und Körper#^10fa08]]

Allgemein ist der Begriff der Vollständigkeit für Körper wie folgt definiert:
![[Ringe und Körper#Vollständigkeit]]

Wir sagen axiomatisch, dass der Körper $\mathbb{R}$ vollständig ist.

### Eindeutige Lösungen für Exponentialgleichungen
Hieraus folgt, dass z.B. $x^2=2$ in $\mathbb{R}$ genau eine positive Lösung hat:

- Die Menge $A=\set{x\in \mathbb{R}_{+}\mid x^{2}\leq 2}$ hat ein Supremum $b$.
- $b^{2}<2$ kann nicht sein:
	- dann gäbe es ein $n \in \mathbb{N}$, sodass $(b+ \frac{1}{n})^{2}<2$
	- das heißt, das $b+ \frac{1}{n} \in A$ und $b + \frac{1}{n}>b$, was nicht sein kann, da $b$ das Supremum ist.
- $b^{2}>2$ kann auch nicht sein:
	- dann gäbe es ein $n \in \mathbb{N}$, sodass $(b- \frac{1}{n})^{2}>2$.
	- damit wäre $b- \frac{1}{n}$ eine obere Schranke für $A$ und kleiner als das Supremum $b$, was nicht sein kann.
$\Rightarrow b^{2}$ muss also tatsächlich gleich $2$ sein.

Diese Argumentation funktioniert für alle Gleichungen der Form $b^k=a$ mit $a\in \mathbb{R}_{+}$ und $k \in \mathbb{N}$.

### Potenzen mit rationalen Exponenten
Wir definieren die allgemeine Wurzel für $k\in \mathbb{N}$ und $a\in \mathbb{R}_{+}$ wie folgt:
$$b^{k}=a \iff b=\sqrt[k]{a}$$

Damit können wir Potenzen mit rationalen Exponenten wie folgt definieren:
$$a^{\frac{p}{q}}=\left(\sqrt[q]{a}\right)^{p}$$
mit $p,q \in \mathbb{Z}$ und $a \in \mathbb{R}_{+}$.
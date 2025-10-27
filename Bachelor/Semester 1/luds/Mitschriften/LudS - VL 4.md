Datum: 20.10.22
Material: [[4VL-Scan-Induktion-Beweise.pdf|Zettel]]
# Vollständige Induktion
## Definition
![[Beweistechniken#Vollständige Induktion]]

## Beispiel
$$
\sum_{i=1}^ni=\frac{n*(n+1)}{2}
$$

### Direkter Beweis
$$
\begin{aligned}
&2\cdot\sum\limits_{i=1}^{n}i\\
=&1&+&2&+&...&+&n \\
+&n&+&(n-1)&+&...&+&1 \\
\hline \\
=&(n+1)&+&(n+1)&+&...&+&(n+1) \\
=&n\cdot(n+1)
\end{aligned}
$$
$$
\Rightarrow \sum_{i=1}^ni=\frac{n*(n+1)}{2}
$$

### Beweis mit vollständiger Induktion
#### Induktionsanfang
$A(1)=\sum\limits_{i=1}^{1}i=1=\frac{1\cdot 2}{2}$
#### Induktionsannahme
$A(n)$ ist wahr für $n\geq 1$.
#### Induktionsschluss
Zeige $A(n+1)$.
$$
\begin{align}
\sum\limits_{i=1}^{n+1}i&=\sum\limits_{i=1}^{n}i+(n+1)\stackrel{A(n)}{=}\frac{n\cdot(n+1)}{2}+(n+1) \\
&=\frac{n(n+1)+2(n+1)}{2} =\frac{(n+2)(n+1)}{2}
\end{align}
$$
$\Rightarrow A(n)\text{ gilt }\forall n\geq 1$.

## Weiteres

> [!attention] Achtung
> Man darf den Induktionsanfang nicht rauslassen, sonst kann man alles mögliche Verkehrte beweisen.
> Es gibt Probleme, die nicht mit vollständiger Induktion bewiesen werden können!

- $|\mathcal{P}(M)|=2^{|M|}$ kann auch mit vollständiger Induktion bewiesen werden.

## Strukturelle Induktion
(könnte auch in der Klausur kommen)
Auf den Zetteln: Aufbau von natürlichen Zahlen via Induktion

### Beispiel: Euler'sche Formel über planare Graphen
![[Glossar#Planarer Graph]]

**Euler'sche Formel:** Komponenten + 1 = Knoten - Kanten + Flächen

Die Euler'sche Formel kann mit einer strukturellen Induktion bewiesen werden.

#### Induktionsanfang
Man nehme einen leeren Graphen (ohne Knoten und Kanten). Für diesen Graphen gilt die Eulerformel (es gibt 0 Komponenten, 0 Knoten, 0 Kanten und 1 Fläche).

#### Induktionsannahme
Die Eulerformel gilt für einen beliebgen planaren Graphen.

#### Induktionsschritt
Man kann aus dem leeren Graphen einen beliebigen planaren Graphen basteln, indem man:
- Knoten hinzufügt
	- Wenn man ihn isoliert hinzufügt entsteht eine neue Komponente -> Eulerformel gilt weiterhin
	- Wenn man ihn auf eine bestehende Kante setzt entsteht eine neue Kante -> Eulerformel gilt weiterhin
- Kanten hinzufügt
	- Wenn man zwei Komponenten verbindet wird es eine Komponente weniger -> Eulerformel gilt weiterhin
	- Wenn man zwei Knoten derselben Komponente verbindet entsteht eine neue Fläche -> Eulerformel gilt weiterhin

## Indexshift
Man kann natürlich im Induktionsschritt auch zeigen, dass $A(n-1)\Rightarrow A(n)$ (für $n-1\geq k$).
Datum: 04.05.
[[ThR_LA_Skript.pdf|Skript:]] Seiten 42 bis 45

Die einzigen zwei Körper sind $\mathbb{R}$ und $\mathbb{R}^2$, mit $\mathbb{R}^{4}$ kriegt man noch einen Schiefkörper hin (Quarternionen, keine Kommutativität der Multiplikation). Wenn die Assoziation nicht verlangt (Divisionsalgebra), dann schafft man $\mathbb{R}^{8}$ (Oktonionen) auch noch.

1 ist die reelle Einheit, $i$ ist die imaginäre Einheit. Bei den Quarternionen kommen noch die Einheiten $j$ und $k$ dazu.

$$\Huge\mathbb{C} \text{ ist toll.}$$

# Linearkombinationen und Basen

## Linearkombinationen

> [!abstract] Definition **Linearkombination**
> Für einen $\mathbb{K}$-[[Vektorräume#Vektorräume|Vektorraum]] $V$ heißt ein Vektor $v$ eine **Linearkombination** von den Vektoren $v_1,v_2,\ldots,v_n\in V$, falls es $\lambda_{1},\lambda_{2},\ldots,\lambda_{n}\in \mathbb{K}$ gibt, sodass $$v=\lambda_{1}v_{1}+\ldots+\lambda_{n}v_{n}$$ gilt.
> Die Skalare $\lambda_{1},\ldots,\lambda_{n}$ heißen *Koeffizienten* dieser Linearkombination.
> Die Menge $\mathcal{L}(v_{1},\ldots,v_{n}):= \set{\sum_{i=1}^{n}\lambda_{i}v_{i} \mid \lambda_{1},\ldots,\lambda_{n}\in \mathbb{K}} \subseteq V$ aller Linearkombinationen von $v_{1},\ldots,v_{n}$ heißt *Lineare Hülle* von $v_{1},\ldots,v_{n}$.
> Im Fall $n=0$ setzen wir $\mathcal{L}(\emptyset):=\set{0}$.

^9b8d50

Beispiel: die lineare Hülle des Vektors $(1,1)\in \mathbb{R}^{2}$ ist die Menge aller Vektoren, die auf der 45°-Diagonale durch den Ursprung liegen.

Allgemein enthält jede lineare Hülle den Nullvektor, nämlich für die Koeffizienten $\lambda_{1}=\ldots=\lambda_{n}=0$ (für $n=0$ ist der Nullvektor axiomatisch enthalten).

Da für $v,w\in \mathcal{L}(v_{1},\ldots,v_n)$ gilt: $v+w \in \mathcal{L}(v_{1},\ldots,v_{n})$ und $v \cdot w \in \mathcal{L}(v_1,\ldots,v_n)$, gilt auch:

> Für $v_{1},\ldots,v_{n}\in V$ ist $\mathcal{L}(v_{1},\ldots,v_{n})$ ein *[[Vektorräume#Untervektorräume|Untervektorraum]]* von $V$.

> Ein Vektorraum $V$ heißt *endlich erzeugt*, wenn es eine endliche Folge $(v_{1},\ldots,v_{n}), v_{i}\in V$ gibt, sodass $\mathcal{L}(v_{1},\ldots,v_{n})=V$ gilt.

Zum Beispiel ist $R^{n}$ für $n \in \mathbb{N}$ endlich erzeugt.

## Lineare Unabhängigkeit

> Sei $V$ ein Vektorraum und $v_{1},\ldots,v_{n}\in V$.
> Ein $n$-Tupel $(v_1,\ldots,v_n)$ heißt **linear unabhängig**, wenn: $$\lambda_{1}v_{1}+\ldots+\lambda_{n}v_{n}=0 \iff \lambda_1=\ldots=\lambda_n=0.$$ Ein nicht linear unabhängiges Tupel heißt linear abhängig.
> Vereinbarung: das 0-Tupel für $n=0$ sei immer linear unabhängig.

^ae0c6d

Anders gesagt: ein $n$-Tupel ist linear unabhängig, wenn man keinen Vektor aus diesem Tupel als Linearkombination der anderen Vektoren aus dem Tupel darstellen kann.

Die obige definition ist aber einfacher zu handhaben: will man ein Tupel auf lineare Unabhängigkeit prüfen, reicht es, ein homogenes LGS all dieser Vektoren zu konstruieren und zu prüfen, ob nur die triviale Lösung (mit allen Koeffizienten gleich 0) existiert.

## Basen
> [!abstract] Definition **Basis**
> Ein $n$-Tupel $(v_{1},\ldots,v_{n})$ von Vektoren aus einem Vektorraum $V$ heißt **Basis von $V$**, falls es *linear unabhängig* ist und gilt: $\mathcal{L}(v_{1},\ldots,v_{n})=V.$

^567731


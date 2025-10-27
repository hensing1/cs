Datum: 25.10.22
Material: [[5VL-Scan-Induktion-Quantoren-Relationen.pdf|Zettel]]
# Induktion, Strukturelle Induktion, Fallstricke

## Vollständige Induktion, aber anders

![[Beweistechniken#Alternatives Induktionsprinzip]]

### Beispiel: Satz von Zermelo
> Jede natürliche Zahl $n>2$ lässt sich als Produkt von Primzahlen darstellen.

#### Induktionsanfang
$n=2$

#### Induktionsannahme
Alle Zahlen $m$ lassen sich als Produkt von Primzahlen darstellen, mit $2 \leq m \lt n$.

#### Induktionsschluss
Zu zeigen ist, dass die Aussage für $n$ gilt.

Entweder: $n$ ist Primzahl -> Aussage gilt.
Oder: $n$ ist keine Primzahl:
- $\Rightarrow$ $n=n_{1} \cdot n_2$ mit $n_{1}\geq 2$ und $n_{2} \geq 2$.
- laut Induktionsannahme haben $n_1$ und $n_2$ eine Primfaktorenzerlegung, sagen wir mal $n_{1}=p_{1}\cdot p_{2}\cdot ...\cdot p_{n}$ und $n_{2}=q_{1}\cdot q_{2}\cdot ...\cdot q_{n}$ ($p_i$ und $q_i$ sind Primzahlen)
- dann ist $n=p_{1}\cdot p_{2}\cdot ...\cdot p_{n}\cdot q_{1}\cdot q_{2}\cdot ...\cdot q_{n}$
- $\Rightarrow$ $n$ lässt sich als Produkt von Primzahlen darstellen.
$\square$

---
![[Aussagen#Quantoren]]

Bindungsreihenfolge (konventionell): $\lnot$ vor $\lor,\land$ vor $\Rightarrow,\Leftrightarrow$ vor $\exists,\forall$

# Relationen
![[Relationen#Definition]]


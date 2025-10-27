Datum: 18.10.22
Material: [[3VL-Scan-Direkt-Indirekt-Beweise-Aussagen.pdf|Zettel]]
# Anmerkungen zu logischen Aussagen
![[Aussagen#Logische Operatoren#Anmerkungen]]

![[Aussagen#De Morgan'sche Gesetze]]

# Direkte und indirekte Beweise
## Definition
![[Beweistechniken#Direkte und indirekte Beweise]]

## Beispiel für direkten Beweis
### Theorem
> Das Quadrat einer ungeraden Zahl ist ungerade.

### Beweis
$$
\begin{aligned}
\text{n ist ungerade} &\Rightarrow n=2\cdot k+1 \\
&\Rightarrow n^{2}=2(2k^{2}+2k)+1\text{ und }(2k^{2}+2k)\in\mathbb{N} \\
&\Rightarrow n^{2}\text{ ist ungerade. } \\\hfill\square
\end{aligned}
$$
## Beispiel für indirekten Beweis
### Theorem
> Es gibt unendlich viele Primzahlen.

> [!abstract] Axiom
> Jede natürliche Zahl $n\geq 2$ ist ein Produkt von Primzahlen.
### Beweis
> **Annahme:**
> Es existieren nur endlich viele Primzahlen.

Sei $P=\set{p_1,p_2,...,p_k}$ die Menge aller Primzahlen.

Dann ist $m=\prod\limits_{i=1}^{k}(p_i)+1>p_{i}\text{ für alle }p_{i}\in P$.
Entweder:
- $m$ ist Primzahl -> ↯, da $m\notin P$

Oder:
- $m$ ist keine Primzahl.
- Laut Axiom muss es dann eine Primzahl $q$ geben, die $m$ teilt. Jedoch ist $m \mod p_i=1$ für alle $p_i$.
- $\Rightarrow q\notin P$ ↯

$\square$

Weiterer besprochener indirekter Beweis: $\sqrt{2}\notin\mathbb{Q}$
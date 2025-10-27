Datum: 14.10.
[[lecture05-24-10-24.pdf]]

# Berechnung Konvexer Hüllen ($\mathbb{R}^{2}$)

Wir definieren heute einen Algorithmus, der aus einer Punktemenge das zugehörige konvexe Polygon berechnet.

Annahmen für unser Rechnermodell *(Random Access Machine)*:
- konstanter Speicherzugriff
- endloser Speicher
- Operationen in konstanter Zeit

**Lage der Punkte**
- Keine 3 Punkte in einer Linie ($\mathbb{R}^3$: keine 4 Punkte in einer Ebene).
- Keine parallelen Geraden, keine 3 Geraden schneiden sich in einem Punkt.
- In der Ebene: alle Punkte haben verschiedene $x$-$y$-Koordinaten.

**Orientierungstest**
Für den ersten Algorithmus brauchen wir ein *Prädikat*, das uns sagt, wie drei Punkte $p_{1},p_{2},p_{3}$ orientiert sind (Orientierungstest): 
$$
OT(p_{1},p_{2},p_{3}) = \begin{cases}
<0&: p_{3} \text{ ist rechts von } \overline{p_{1}p_{2}} \\
0&: \text{Punkte sind kolinear} \\
>0 &: p_{3} \text{ ist links}
\end{cases}
$$
Es gibt alle möglichen Prädikate, und diese können sehr präzise ausgewerted werden. 
Beispiel: 
$$
OT(p,q,r) = \det \begin{vmatrix}
p_{x} & p_{y} & 1 \\
q_{x} & q_{y} & 1 \\
r_{x} & r_{y} & 1 \\
\end{vmatrix} \quad (\text{Orientierter Flächeninhalt von }\triangle(p,q,r))
$$


## Graham Scan
**Vorbedingung:** Punkte sind sortiert nach Polarkoordinaten (Winkel) um Punkt mit geringster $x$-Koordinate (Punkt $p_1$). 

> **Graham Scan**
> $P = {p_3, p_4, \ldots, p_n}$ 
> $L = (p_1, p_2)$ *// auf jeden Fall Teil der konvexen Hülle*
> For i = 3 to n:
> > Append($L$, $p_i$)
> > While $OT(p_{|L|-2}, p_{|L|-1}, p_i) < 0$ (Rechtskurve):
> > > Entferne p_{|L|-1} aus L
> Return L

Invariante für Analyse:
Liste $L$ ist die konvexe Hülle von $(p_1, p_2, \ldots, p_i)$ (Ende von While).

**Laufzeit:**
- $\mathcal{O}(n \log n)$ für Vorsortieren.
- Jeder Punkt wird nur $2\times$ betrachtet $\Rightarrow \mathcal{O}(n \log n)$ insgesamt.

[[Konvexe_Huelle_Graham_Scan.png]]

## Untere Laufzeitgrenze
> **Theorem**
> Die Berechnung der konvexen Hülle für $n$ Punkte im $\mathbb{R}^2$ benötigt Zeit $\Theta(n \log n)$.

Beweis für $\Omega(n \log n)$:
Wir können die Sortierung von Zahlen auf die Berechnung einer konvexen Hülle zurückführen:
- Zahlenmenge $X=\{ x_{1},\dots,x_{n} \}$
- Eingabe für konvexe Hülle: $\{ (x_{i},x_{i}^2) \mid x_{i} \in X \}$
- $\to$ Konvexe Hülle ist eine Parabel
- Finden des linkesten Punktes benötigt lineare Zeit, danach sind alle Punkte entlang der Hülle aufsteigend sortiert

## Inkrementeller Algorithmus

**Vorbedingungen:**
- Punkte in beliebiger Reihenfolge.
- $(p_1, p_2, p_3)$ sind mathematisch positiv angeordnet (gegen den Uhrzeigersinn).

> **Inkrementeller Algorithmus**
> for $i=4$ to $n$:
> > Falls $p_{i}$ nicht in $CH(p_{1},\dots,p_{i-1})$:
> > > Berechne Tangenten $p_{1a},p_{1b}$ von $p_{i}$ zu $CH(p_{1},\dots,p_{i-1})$
> > > Ersetze Kette $a \to b$ mit $a,p_{i},b$

Tangentenberechnung:
Durch Orientierungstests, siehe nächste VL.

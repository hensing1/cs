[[lecturenotes13.pdf]]

- [[AGT 12 - Combinatorial Auctions#^745125|Combinatorial Auction]]

*Unit-demand function:* Bewertung für Set ist gleich Bewertung für wertvollstes Item, $v_{i}(S)=\max_{j \in S}v_{i,j}$.

*Lösung:* es hat keinen Sinn, einem Bieter mehr als ein Item zu geben. Man kann das Modell also als [[Relationen#Bipartiter Graph|bipartiten Graph]] darstellen:
- die $n$ Bieter auf der einen Seite
- die $m$ Objekte auf der anderen Seite
- Kantengewichte: Bewertung $v_{ij}$ von Bieter $i$ für Objekt $j$
- Maximierung von social welfare $\iff$ max-weight matching im Graphen

Mit VCG-Mechanismen, benannt nach Vickrey, Clarke, Groves, sind entweder eine Klasse von Mechanismen gemeint, oder "der" folgende Mechanismus:

> [!abstract] Definition *VCG-Mechanismus mit Clarke-Pivotregel*
> Sei $X$ die Menge der möglichen Zuordnungen, $V_{i}$ die Menge der für $i$ möglichen Bewertungsfunktionen $v_{i}: X \to \mathbb{R}$, und $V=V_{1} \times \dots \times V_{n}$. 
> Wir reden über *direkte Mechanismen*, dh. $f: V \to  X$ und $p: V \to \mathbb{R}^{n}$ (Gebote und Valuationen haben dieselben Einheiten).
> Jeder Bieter $i$ bewertet eine Zuweisung $x \in X$ mit $b_{i}(x)$ .
> 
> Der VCG-Mechanismus mit der Clarke-Pivotregel ist definiert als $$\mathcal{M}=(f,p),$$
> wobei:
> - $f$ die Items so zuordnet, dass die *deklarierte* Welfare maximiert wird: $$f(b) \in \arg\max_{x \in X}\sum_{i}b_{i}(x)$$
> - $p$ Spieler $i$ die Differenz zahlen lässt, um die $i$ die deklarierte Welfare der anderen Spieler verringert: $$p_{i}(b)=\max_{x \in X}\sum_{j \neq i}b_{j}(x)-\sum_{j \neq i}b_{j}(f(b)).$$

^440374

Der VCG-Mechanismus ist *ehrlich* (DSIC):
$$\begin{align}
v_{i}(f(v_{i},b_{-i})) + \sum_{j \neq i}b_{j}(f(v_{i},b_{-i})) &\geq v_{i}(f(b_{i}',b_{-i})) + \sum_{j \neq i}b_{j}(f(b_{i}',b_{-i}))\\
v_{i}(f(v_{i},b_{-i})) -\max_{x \in X}\sum_{j \neq i}b_{j}(x) + \sum_{j \neq i}b_{j}(f(v_{i},b_{-i})) &\geq v_{i}(f(b_{i}',b_{-i})) - \max_{x \in X}\sum_{j \neq i}b_{j}(x)  + \sum_{j \neq i}b_{j}(f(b_{i}',b_{-i}))  \\
v_{i}(f(v_{i},b_{-i}))-p_{i}(v_{i},b_{-i}) &\geq v_{i}(f(b_{i}',b_{-i})) - p_{i}(b_{i}', b_{-i}) \\
u_{i}((v_{i}, b_{-i}), v_{i}) &\geq u_{i}((b_{i}',b_{-i}),v_{i}).
\end{align}$$

Lässt man den VCG-Mechanismus auf eine Single-item auction los, erhält man genau die Zweitpreisauktion.
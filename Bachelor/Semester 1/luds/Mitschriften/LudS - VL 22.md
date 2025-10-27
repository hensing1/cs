Datum: 10.01.
[[22VL-Scan-Euklid-Anwendungen.pdf|Folien]]

# Chinesischer Restesatz

> [!abstract] Chinesischer Restesatz
> Für alle $a,b \in \mathbb{Z}$ und $n,m \in \mathbb{N}$ mit *$\text{ggT}(n,m)=1$* existiert *genau eine* Lösung $x \in \set{0,1,\ldots,mn - 1}$ für das *[[Glossar#Kongruenz|Kongruenzsystem]]* $$\begin{aligned} x &\equiv a \!\!\!\!\mod n \\ x &\equiv b \!\!\!\!\mod m. \end{aligned}$$

Derartige Kongruenzsysteme tauchen relativ oft auf, weswegen dieses Resultat sowie die effiziente Berechnung der Lösung relativ wichtig sind.

## Beweis
Sei $\varphi : \mathbb{Z}_{n \cdot m} \rightarrow \mathbb{Z}_{n} \times \mathbb{Z}_m$ Funktion, sodass $[\![k]\!]_{n \cdot m} \mapsto ([\![k]\!]_{n},[\![k]\!]_{m})$.

Man nimmt einen also einen Repräsentanten einer Klasse aus $\mathbb{Z}_{n \cdot m}$ und bildet ihn ab auf $\mathbb{Z}_{n} \times \mathbb{Z}_{m}$. 

Insbesondere ist für $k \neq k'$ mit $[\![k]\!]_{nm} = [\![k']\!]_{nm}$ auch $\varphi([\![k]\!]_{nm}) = \varphi([\![k']\!]_{nm})$.

Der chinesische Restsatz ist also äquivalent zu der Aussage, dass es immer eine eindeutige Lösung für $\varphi([\![x]\!]_{nm})=([\![a]\!]_n,[\![b]\!]_m)$ für gegebene $a,b,n,m$ gibt, d.h. dass $\varphi$ bijektiv ist.

**$\varphi$ ist injektiv:**
$$\begin{align*}
&\varphi([\![k]\!]_{nm})=\varphi([\![l]\!]_{nm})\\
\iff&([\![k]\!]_{n},[\![k]\!]_{m})=([\![l]\!]_{n},[\![l]\!]_{m})\\
\iff&[\![k]\!]_{n}=[\![l]\!]_{n} \land [\![k]\!]_{m}=[\![l]\!]_{m}\\
\iff&n \mid k-l \quad\land \quad m \mid k-l\\
\stackrel{\text{ggT}(n,m)=1}\Longrightarrow\space&n \cdot m \mid k-l\\
\iff&[\![k]\!]_{nm}=[\![l]\!]_{nm}
\end{align*}$$
**$\varphi$ ist surjektiv:**
Das geht rein über Kardinalität: die Abbildung ist injektiv, und $|\mathbb{Z}_{m \cdot n}|=|\mathbb{Z}_{n} \times \mathbb{Z}_{m}|=nm$, d.h. jedes Element aus der Zielmenge wird getroffen.
Damit ist diese Abbildung auch bijektiv.[^1]

[^1]: Für Funktionen, bei welchen Definitions- und Zielmenge dieselbe endliche Kardinalität haben, sind die Begriffe injektiv, surjektiv und bijektiv äquivalent.

## Berechnung 
Das Kongruenzsystem kann wie folgt mit dem [[Euklidischer Algorithmus#Erweiterter euklidischer Algorithmus|erweiterten euklidischen Algorithmus]] gelöst werden.

Wir wissen, dass $\text{ggT}(n,m)=1$. 
Das heißt, gemäß dem Lemma aus der [[LudS - VL 21#Euklidischer Algorithmus|letzten Vorlesung]] wissen wir, dass:$$\exists v,w \in \mathbb{Z} : nv+mw=1.$$
Wir wenden nun den Euklidischen Algorithmus an, um $v$ und $w$ zu berechnen.

Nun haben wir mit $x=b \cdot n \cdot v + a \cdot m \cdot w$ eine Lösung für unser Kongruenzsystem:
$$[\![x]\!]_{n}=[\![bny+amz]\!]_{n}=[\![amz]\!]_{n}=[\![a]\!]_{n} \odot_{n} [\![mz]\!]_{n}=[\![a]\!]_{n} \odot_{n} [\![1]\!]_{n}=[\![a]\!]_{n}$$
und
$$[\![x]\!]_{m}=[\![bny+amz]\!]_{m}=[\![bny]\!]_{m}=[\![b]\!]_{m} \odot_{m} [\![ny]\!]_{m}=[\![b]\!]_{m} \odot_{m} [\![1]\!]_{m}=[\![b]\!]_{m}$$

## Verallgemeinerung
Derselbe Ansatz funktioniert für Kongruenzsysteme mit beliebig vielen Variablen:
$$\begin{align*}
x \equiv& \space a_{1} \!\!\!\!\mod n_{1}\\
x \equiv& \space a_{2} \!\!\!\!\mod n_{2}\\
&\vdots\\
x \equiv& \space a_{r} \!\!\!\!\mod n_{r},
\end{align*}$$
sodass alle $n_i$ paarweise teilerfremt sind. Dann gibt es eine eindeutige Lösung $x \in \set{0,1,2,\ldots,N-1}$ mit $N = \prod\limits_{i=1}^{r} n_i$.
Man berechnet mit dem eulerschen Algorithmus $v_{i}$ und $w_{i}$, sodass $n_{i} \cdot v_{i} + \frac{N}{n_{i}}w_i=1$. Dann ist die Lösung $x=\sum\limits_{i=1}^{r}a_{i}\frac{N}{n_{i}}w_i$.
Datum: 12.10.

Wir beweisen: 
> Eulers Algorithmus arbeitet korrekt und hat Laufzeit $\mathcal{O}(n+m)$.

Wir zeigen per Induktion nach $|E(G)|$, dass `Euler(v)` für einen beliebigen Knoten $v$ in einem eulerschen nicht notwendigerweise zusammenhängenden Graphen $G$ einen eulerschen Spaziergang in der Zusammenhangskomponente $G_{v}$ von $G$ liegt, die $v$ enthält.
Wegen der Euler-Bedingung ist der Spaziergang geschlossen (d.h. endet in $v$), wenn wir Schritt 4 erreichen. Sei $G'$ der Graph zu diesem Zeitpunkt. $G'$ ist eulersch.

Für $e \in E(G_{v})\cup E(G')$ existiert ein minimales $i \in \set{2,\ldots,k}$, sodass $v_{i}$ in derselben Zusammenhangskomponente von $G'$ wie $e$ ist.
Nach Induktionsvoraussetzung gehört $e$ zu $W_{i}$.
Am Ende haben wir also einen geschlossenen Spaziergang, der alle kanten von $G_v$ enthält, und jede nur einmal (weil wir jede verwendete Kante direkt löschen).
Die Laufzeit ist linear, da proportional zur Anzahl der Kanten in $G_v$. $\square$

---

Kreis $\equiv$ geschlossener Kantenzug ohne Knotenwiederholungen
Hamiltonkreis: Kreis, der alle Knoten enthält

Einen Hamiltonkreis zu finden, ist NP-schwer.

> **Satz (Dirac 1952)**
> Jeder einfache ungerichtete Graph mit $n \geq 3$ Knoten und minimalem Grad $\geq \frac{n}{2}$ enthält einen Hamiltonkreis.

*Beweis*
Ein solcher Graph $G$ ist zusammenhängend, da sonst jeder Knoten in einer Zusammengangskomponente mit $\leq \frac{n}{2}$ Knoten Grad $< \frac{n}{2}$ hätte.
Sei $P$ ein längster Weg in $G$, mit Knoten $x_{1},\ldots,x_{k+1}$. Die Nachbarn von $x_{1}$ und von $x_{k+1}$ liegen alle auf $P$. Sei $$\begin{align*}
A &:= \set{i \in \set{1,\ldots,k}: \set{x_{i},x_{k+1}}\in E(G)}\\
B &:= \set{i \in \set{1,\ldots,k}: \set{x_{1},x_{i+1}}\in E(G)}
\end{align*}$$
Nach Vorraussetzung ist $|A| \geq \frac{n}{2}$, $|B| \geq \frac{n}{2}$. Außerdem $k<k+1\leq n$.
$\Rightarrow A \cup B \neq \emptyset$. 

Sei $j \in A \cap B$.

Dann ergibt $(E(P)\setminus \set{\set{x_{j},x_{j+1}}})\cup \set{\set{x_{1}, x_{j+1}}, \set{x_{j}, x_{k+1}}}$ einen Kreis mit den $k+1$ Knoten von $P.$
Angenommen, dieser Kreis wäre nicht hamiltonsch. Dann gibt es eine Kante $\set{v_{i},w}$ mit $w\not\in V(P)$. Dann erhält man aus $e$ und $C$ einen Weg mit $k+2$ Knoten, was ein Widerspruch ist zur Wahl von $P.\square$

Bemerkung: die Schranke an dem Grad ist bestmöglich: ![[hamilton't.excalidraw]]
Jeder Knoten hat Grad $\geq \frac{n-1}{2}$, offensichtlich ist kein Hamiltonkreis möglich.

--- 

Wir besprechen [[Graphen#Breitensuche|Breitensuche]] und [[Graphen#Tiefensuche|Tiefensuche]]. Mit beiden kann man testen, ob ein Graph zusammenhängen ist.

Um zu testen, ob ein Graph < stark zusammenhängend> ist, könnte man natürlich die Breitensuche von jedem Knoten starten.
In linearer Zeit:

> **Strongly Connected Component Algorithm**
> *Eingabe:* ein gerichteter Graph $G$
> *Ausgabe:* eine Funktion $\text{comp}: V(G) \to \mathbb{N}$, die aussagt, in welcher starken Zusammenhangskomponente jeder Knoten liegt.
> 
> 1. $R \leftarrow \emptyset$, $N \leftarrow 0$
> 2. for all $v \in V(G)$ do: if $v \not\in R$ then `Visit1(v)` //erster DFS
> 3. $R \leftarrow \emptyset$, $K \leftarrow 0$
>    for $i = |V(G)|, \ldots, 1$ do:
> 	   if $\psi^{-1}(i) \not\in R$ then $K \leftarrow K+1$, `Visit2(`$\psi^{-1}(i)$`)` //zweiter DFS
> 
> **Visit1(v):**
> 1. $R \leftarrow R \cup \set{v}$
> 2. for all $(v,w)\in \delta^{+}(v)$$: if $w \not\in R$ then `Visit1(w)`
> 3. $N \leftarrow N+1$, $\psi(v) \leftarrow N$, $\psi^{-1}(N) \leftarrow v$.
>    
> **Visit2(v):**
> 1. $R \leftarrow R \cup \set{v}$
> 2. for all $(w,v)\in \delta^{-}(v)$ do: if $w\in R$ then `Visit2(w)`
> 3. $\text{comp}(v) \leftarrow K$

*Korrektheitsbeweis*
Zwei Knoten $v$ und $w$ in derselben starken Zusammenhangskomponente bekommen dieselbe comp-Nummer, denn: einer von beiden, wagen wir $v$, besuchen wir zuerst in `Visit2`.
Bevor wir $v$ die Nummer $k$ geben, besuchen wir alle Knoten, von denen aus $v$ erreichbar ist (also auch $w$) und geben ihnen Nummer $K$.

Rückrichtung:
Sei $r(u)$ bzw. $r(v)$ der Knoten, der von $u$ bzw. $v$ aus erreichbar ist und die höchste $\psi$-Nummer hat.
Da $\text{comp}(u)=comp(v)$, liegen $u$ und $v$ in derselben Anti-Aborreszenz des zweiten DFS, d.h. $r=r(u)=r(v)$ ist die Wurzel dieser Anti-Aborreszenz.
$\Rightarrow$ $f$ ist von $u$ und von $v$ aus erreichbar.
$r$ ist von $u$ aus erreichbar und $\psi(r)\geq \psi(u)$.
Also wurde $r$ nicht später als $u$ zu $R$ in erste DFS hinzugefügt.
Das erste DFS-Branching enthält also einen Weg von $r$ nach $u$.
$\Rightarrow$ $r$ und $u$ (und analog $r$ und $v$) gehören zur selben starken Zusammenhangskomponente. $\square$

> Der Algorithmus bestimmt eine topologische Ordnung des gerichteten Graphen, der durch Kontraktion der starken Zusammenhangskomponenten entsteht.
> D.h.: $\text{comp}(v)<\text{comp}(w)\Rightarrow (w,v) \not\in E(G)$.

*Beweis:*
Seien $X,Y$ starke Zusammenhangskomponenten von $G$, $\text{comp}(x)=k_{1}\forall x \in X$, $\text{comp}(y)=k_{2}\forall y \in Y$, $k_{1}<k_{2}$.
Wir zeigen $\delta^{+}(Y)\cap \delta^{-}(X)=\emptyset$
Angenommen, es gebe $(y,x)\in E(G)$ mit $x\in X$, $y \in Y$. \mathfrak{Im}zweiten DFS besuchen wir alle Knoten in X, bevor wir Knoten in Y besuchen. Ins. betrachten 
Datum: 22.11.
[[12VL-Scan-DFA-Minimierung-Zusammenhang-Reg.-Sprache.pdf|Folien]]

# Nerode-Relation und Äquivalenzklassenautomaten

Vgl.:
< hier bitte Link zu Nerode-Relation einfügen >

Jetzt hab ich einen Automaten. Wie finde ich raus, ob die Zustände minimal sind?
-> Wenn man für zwei beliebige Zustände immer ein Wort findet, für das das Verhalten unterschiedlich ist, dann ist der Automat schon minimal. (Siehe Nerode-Klassen)

Die Nerode-Klassen sind dann Mengen von *Wörtern*, für die ein Äquivalenzklassenautomat in identischen Zuständen landet.

> Wenn es eine Sprache $L$ mit $l=index(\mathrel{R_L})$ vielen Nerode-Klassen gibt, muss es mindestens $l$ viele Wörter geben, die paarweise nicht in Nerode-Relation zueinander stehen.

> [!Beweis]-
> Wenn es nun einen Automaten mit weniger als $l$ Zuständen gäbe, der $L$ entscheiden kann, dann hieße das ja, dass es zwei Worte $w_{i}$ und $w_{j}$ gibt, für die Gilt:
> $w_{i}\not\mathrel{R_{L}}w_{j}$ und trotzdem $\delta^{*}(q_{0},w_{i})=\delta^{*}(q_{0},w_{j})$[^1].
> 
> Das heißt, für den Automaten gilt:
> $\delta^{*}(q_{0},w_{i}z) = \delta^{*}(\delta^{*}(q_{0},w_{i}),z) = \delta^{*}(\delta^{*}(q_{0},w_{j}),z) = \delta^{*}(q_{0},w_{j}z) \in F$.
> 
> was im Widerspruch steht zu:
> $(w_{i},w_{j})\not\in\mathrel{R_{L}}\Rightarrow\exists z : w_{i}z\in L,w_{j}z\not\in L$
> 
> Deshalb muss ein DFA mindestens $index(\mathrel{R_{L}})$ viele Zustände haben, um $L$ zu entscheiden.


> Umgekehrt gilt aber auch für Äquivalenzklassenautomaten, dass sie nicht *mehr* Zustände haben können als $index(\mathrel{R_{L}})$.

> [!Beweis]-
> Wenn zwei Wörter $w_{i}$ und $w_{j}$ in $\mathrel{R_{L}}$ sind, dann heißt das:
> $\forall z \in \Sigma^{*}:w_{i}z \in L \iff w_{j}z \in L$
> und damit auch:
> $\forall z \in \Sigma^{*}:\delta^{*}([q_{0}],w_{i}z)\in F \iff \delta^{*}([q_{0}],w_{j}z)\in F$, das heißt das Akzeptanzverhalten für beide Wörter ist gleich - das heißt wiederum, dass es keine zwei verschiedenen Zustands-Äquivalenzklassen geben kann für dieselbe Nerode-Äquivalenzklasse.


Daraus folgt nun auch:

> Genau die Sprachen, die einen endlichen Nerode-Index haben, können von DFAs entschieden werden.

Denn wenn ein DFA die Sprache entscheiden kann, gibt es eine endliche Zustandsmenge, und die Anzahl der Zustände des entsprechenden Äquivalenzklassenautomaten ist der Nerode-Index. 
Andersrum kann man, wenn man, wenn man die Nerode-Klassen gegeben hat, einen **Nerode-Automaten** bauen:

Dieser Automat hat dann die Nerode-Klassen als *Zustände*. Konkret ist er folgendermaßen definiert:
- $Q_{L}:=\set{[[u]]_\mathrel{R_{L}}|u\in\Sigma^{*}}$
- $q_{0_{L}}:=[[\epsilon]]_{\mathrel{R_{L}}}$
- $F_{L}:=\set{[[u]]_\mathrel{R_{L}}|u\in L}$
- $\delta_{L}([[u]]_{\mathrel{R_{L}}},a):=[[ua]]_{\mathrel{R_{L}}}$

> [!Anwendungsbeispiel]
> Der Nerode-Index der Sprache $L=\set{a^{n}b^{n}|n\in\mathbb{N}}$ ist unendlich, weil  *alle* Wörter $a^n$ in einer anderen Nerode-Klasse sind (man kann an keine zwei dieser Wörter dasselbe dranhängen, damit beide Wörter gültig sind).
> Damit kann es für diese Sprache auch keinen DFA geben.[^2]

# DFAs und reguläre Grammatiken

> Die Klasse der Sprachen, die von DFAs entschieden werden, stimmt genau mit der Klasse der regulären Sprachen überein.

$\exists \text{ reguläre Grammatik G für L} \iff \exists \text{ DFA, der L entscheidet}$.

## Umformen eines DFA in eine reguläre Grammatik

Gegeben sei ein DFA $M=(Q,\Sigma,\delta,q_0,F)$ für $L(M)=L$.

Daraus definieren wir eine [[Formale Sprachen und Grammatiken#Grammatiken#Definition|Grammatik]] $G=(\Sigma,V,S,P)$ mit:
- $V=Q$
- $S=q_{0}$
- $P$, sodass
	- $\forall q,q',a : \delta(q,a)=q' \Rightarrow q \rightarrow aq' \in P$
	- $\forall q : q \in F \Rightarrow q \rightarrow \epsilon \in P$

Die Generierung eines Wortes $w \in L$ mit $G$ sieht nun wie folgt aus:
$$q_{0} \rightarrow w_{1}q_{1} \rightarrow w_{1}w_{2}q_{2} \rightarrow \cdots \rightarrow w_{1}\ldots w_{n}q_{n} \rightarrow w_{1}\ldots w_{n}\epsilon = w.$$

## Umformen einer Grammatik in einen NFA

Gegeben sei eine Grammatik $G=(\Sigma,V,S,P)$.

Daraus definieren wir einen NFA $M=(Q,\Sigma,\delta,q_0,F)$ mit:
- $Q=V$
- $\delta : Q \times \Sigma \rightarrow P(Q)$
	- $\delta(A,a)=\set{B \in V \space | \space (A \rightarrow aB) \in P}$
- $q_{0}=S$
- $F=\set{A \in V \space | \space (A \rightarrow \epsilon) \in P}$

Wenn wir einen NFA generieren können, können wir daraus immer auch einen DFA generieren < Link>.

[^1]: Schubfachprinzip 
[^2]: Turing-Maschinen können aber solche Sprachen entscheiden. Aber es gibt auch wiederum Sprachen, die von *gar keinem* Rechnermodell entschieden werden können. Das bespricht man dann in Algo I / Algo II.
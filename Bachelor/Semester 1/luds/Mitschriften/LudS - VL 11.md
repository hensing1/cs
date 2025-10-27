Datum: 17.11.
[[11VL-Scan-NFA-DFA-Potenzmengen-Aequivalenzklassen.pdf|Folien]]

Es gibt ja zu jedem NFA $M$ einen DFA $M'$. Heute wollen wir zeigen, dass $L(M)=L(M')$.

# Umformung von NFAs in DFAs
## Vorgehensweise
Gegeben sei ein [[Endliche Automaten#Endliche Nichtdeterministische Automaten|NFA]] $M$. Die Zustände des zugehörigen DFAs $M'$ werden Elemente aus der Potenzmenge der Zustände des NFAs sein ($Q'\subseteq\mathcal{P}(Q)$).

Sei $q_{0}$ der Startzustand von $M$. Dann ist der Startzustand von $M'$: $q_{0}'=\set{q_{0}}$.

Nun guckt man sich an, welche Zustände für jeden Buchstaben aus $\Sigma$ auf $q_{0}$ folgen können. Sei beispielsweise $\delta(q_0,1)=\set{q_{0},q_{1}}$, dann wird $\set{q_{0},q_{1}}$ zu einem neuen Zustand von $M'$. Der Folgezustand von $\set{q_{0},q_{1}}$ (bzw. einer beliebigen Menge von Zuständen $p=\set{q_{z0},\ldots,q_{zn}}$, die im NFA durch dasselbe Teilwort erreicht werden können) ist im DFA für einen Buchstaben $b$: $\delta'(p,b)=\bigcup\limits_{q\in b}\delta(q,b)$.
So baut man sich dann nach und nach seinen DFA auf. Wenn man fertig ist, kann es natürlich sein, dass irgendwelche Elemente aus $\mathcal{P}(Q)$ nicht verwendet wurden, da man sie gar nicht erreichen kann. Die müssen dann natürlich nicht mehr in den DFA (auch wenn man sie der Vollständigkeit halber trotzdem manchmal hinschreibt).

Untenstehend ist ein Beispiel für einen NFA, der entscheidet, ob das letzte Zeichen eines Wortes eine 1 ist.
![[NFA_zu_DFA.png]]


Da die NFAs nun bewiesenermaßen genauso mächtig sind wie die DFAs, können wir jetzt, wenn wir zeigen wollen, dass die DFAs genau die regulären Sprachen entscheiden können, das auch für die NFAs zeigen (wäre dann äquivalent).

## Minimierung endicher Automaten
### Äquivalente Zustände
Ziel: einen DFA $M$ in einen DFA $M'$ mit möglichst wenig Zuständen übertragen, sodass $L(M)=L(M')$. 

Dafür definiert man zunächst eine [[Relationen#Äquivalenzrelation|Äquivalenzrelation]] $\equiv$. Für zwei DFA-Zustände $p$ und $q$ gilt:
$$
p \equiv q :\iff(\delta^{*}(p,w)\in F \iff \delta^{*}(q,w) \in F).
$$
Die [[Äquivalenzklassen|Äquivalenzklasse]] $[\![p]\!] \subseteq Q$ ist die Menge aller Zustände, die zu $p$ äquivalent sind.

### Äquivalenzklassenautomat
Man kann mithilfe dieser Äquivalenzrelation nun jeden Automaten $M=(Q,\Sigma,\delta,q_{0},F)$ in einen Äquivalenzklassenautomaten $M'=(Q',\Sigma,\delta',q_{0}',F')$ überführen:
- $Q'=\set{[\![q]\!] \space | \space q \in Q}$, also Menge der Äquivalenzklassen $Q/\equiv$
- $q_{0}'=[\![q_{0}]\!]$
- $F'=\set{[\![q]\!] \space | \space q \in F}$
- $\delta':Q' \times \Sigma \rightarrow Q'$ mit $\delta'([\![q]\!],a):=[\![\delta(q,a)]\!]$.

Dieser Automat verhält sich genauso wie $M$, nämlich derart, dass $\delta(q,a)=q_{2}$ übereinstimmt mit $\delta([\![q]\!],a)=[\![q_{2}]\!]$ und damit $\delta^{*}(q_{0},w) \in F \iff \delta'^{*}([\![q_{0}]\!],w) \subseteq F$.

Unter der Annahme, dass man alle überflüssigen Zustände (also die, die von $[\![q_0]\!]$ nicht erreicht werden können) aus $Q'$ entfernt hat, hat man nun einen Automaten mit einer minimalen Anzahl von Zuständen, um $L(M)$ zu entscheiden.

#### Beweis
Um zu zeigen, dass ein Äquivalenzklassenautomat $M'$ zu einem DFA $M$ ein minimaler DFA für die Sprache $L(M)$ ist, kann man die Nerode-Relation verwenden:

> [!abstract] Nerode-Relation
> Sei $L \subseteq \Sigma^{*}$ eine Sprache, $x,y \in \Sigma^{*}$
> $x\mathrel{R_{L}}y :\iff \forall z \in \Sigma^{*} : (xz \in L \iff yz \in L)$

Für Äquivalenzautomaten heißt das: mit $x$ und $y$ landet man im selben Zustand.

Das ist eine Äquivalenzrelation. $\Sigma^{*}$ wird also in Äquivalenzklassen aufgeteilt ($\Sigma^{*}/\mathrel{R_{L}}$).
In einer Nerode-Äquivalenzklasse sind alle Wörter enthalten, mit denen man in denselben Zustand eines Äquivalenzklassenautomaten kommt.

> [!Beispiel]-
> Sei $L$ die Sprache mit allen Worten aus $\Sigma^{*}$, deren Länge durch 3 teilbar ist:
> $$L=\set{w \in \Sigma^{*} \space | \space |w| \text{ ist durch 3 teilbar}}.$$
> Dann hat $\mathrel{R_{L}}$ drei Äquivalenzklassen:
> $$\begin{aligned}
w_{3n}&=\set{w \in \Sigma^{*} \space | \space |w|=3n,n \in \mathbb{N}} \\
w_{3n+1}&=\set{w \in \Sigma^{*} \space | \space |w|=3n+1,n \in \mathbb{N}}\\
w_{3n+2}&=\set{w \in \Sigma^{*} \space | \space |w|=3n+2,n \in \mathbb{N}}
\end{aligned}$$

Nun gilt:
- Jeder DFA hat mindestens $index(\mathrel{R_{L}})$ viele Zustände
- $M'$ hat maximal $index(\mathrel{R_{L}})$ viele Zustände.
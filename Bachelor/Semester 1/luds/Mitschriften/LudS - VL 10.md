Datum: 15.11.
[[10VL-Scan-PL-NFAs.pdf|Folien]]

# Beweis, dass Sprache nicht von DFA entschieden werden kann
Wenn eine Sprache $L$ nur endlich viele Wörter hat, kann sie in jedem Fall von einem DFA entschieden werden (man braucht in jedem Fall nur endlich viele Zustände).

Wir haben [[LudS - VL 9|letzte Vorlesung]] gezeigt:
$$
\text{L wird von DFA akzepziert} \Rightarrow \text{Pumping-Lemma gilt}
$$

Nun zeigen wir (als äquivalente Aussage):
$$
\lnot (\text{Pumping-Lemma gilt}) \Rightarrow \lnot(\text{L wird von DFA akzeptiert})
$$

## Umgekehrtes Pumping-Lemma
Wir nehmen zunächst an, es gibt einen DFA $M$, der $L$ akzeptiert.
Dann zeigen wir die entgegengesetze Aussage zum Pumping-Lemma:
> $\forall n \in \mathbb{N}:\exists z \in L,|z|\geq n$, sodass *für alle* Zerlegungen $z=uvw$ mit $|uv|\leq n$ und $|v|\geq 1$ gilt: $\exists i \geq 0:uv^{i}w \not\in L$.

## Beweis mit zwei Gegenspielern
Es gibt einen Prover, welcher die Aussage beweisen möchte, und einen Verifier, welcher den Beweis so schwer wie möglich machen möchte.

### Ablauf für umgekehrtes Pumping-Lemma
1. Runde: Verifier wählt ein beliebiges $n\in\mathbb{N}$
2. Runde: Prover wählt ein Wort $z\in L$ mit $|z|\geq n$
3. Runde: Verifier wählt beliebige Zerlegung $z=uvw$ mit $|uv|\leq n$ und $|v|\geq 1$
4. Runde: Prover wählt ein $i \geq 0$ mit $uv^{i}w\not\in L$.

### Beispiel
Gegeben sei die Sprache $L=\set{0^{i}1^{i}|i\in\mathbb{N}}$, ein Verifier Vera und ein Prover Peter.
1. Runde: Vera wählt beliebiges $n$.
2. Runde: Peter wählt $z=0^{n}1^{n}$, da $|z|=2n\geq n$.
3. Runde: Vera wählt beliebiges $z=uvw$ mit $|uv|\leq n$ und $|v|\geq 1$
	- Note: $uv$ kann nur aus Nullen bestehen
4. Runde: Peter wählt $i=2$.

Da $v$ aus mindestens einer 0 besteht (und keiner 1), hat das Wort $uv^2w$ auf jeden Fall mehr Nullen als Einsen. Damit ist $uv^{2}w\not\in L$.

## Andersrum geht es leider nicht
Nur weil das Pumping-Lemma gilt, bedeutet das nicht, dass die Sprache auch von einem DFA entschieden werden kann.
Dies ist zum Beispiel der Fall für die Sprache $L=\set{a,b}^{*}\cup \set{c^ka^{n}b^{n}|k,n\geq 0}$ 

# Nichtdeterministische Endliche Automaten
![[Endliche Automaten#Endliche Nichtdeterministische Automaten#Definition]]

![[Endliche Automaten#Endliche Nichtdeterministische Automaten#Nutzen und Mächtigkeit]]
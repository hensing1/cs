Datum: 08.11.
[[8VL-Scan-Sprachen-Grammatiken.pdf|Folien]]

## Wiederholung von letzter Vorlesung
Man kann mit den Repräsentanten einer Äquivalenzklasse rumrechnen und kriegt dann den Repräsentanten der resultierenden Äquivalenzklasse raus.

Es gilt für $\equiv_n$: 
$$
([[a]] = [[a']] \land [[b]] = [[b']]) \Rightarrow ([[a+b]] = [[a'+b']] \land [[a\cdot b]] = [[a' \cdot b']])
$$

## Ach übrigens
![[Aussagen#Hinreichende und notwendige Bedingungen]]

Angewandt auf Implikation ($\Rightarrow$):
Falls $A \Rightarrow B$ gilt, dann ist:
- $A$ *hinreichend* für $B$, und
- $B$ *notwendig* für $A$.

# Endliche Automaten und Formale Sprachen

In der theoretischen Informatik hat man ja andauernd mit abstrakten Rechnermodellen zu tun. Ein sehr einfaches Rechnermodell ist ein *endlicher Automat*. 

Alles, was ein endlicher Automat macht, ist, für eine beliebige Zeichenkette zu entscheiden, ob sie gültig ist oder nicht. Das ist zum Beispiel praktisch für das Erkennen von gültigen Tokens in einer Programmiersprache.

> Jedes Rechnungsproblem kann man darstellen als die Frage, ob ein bestimmtes Wort in einer Sprache enthalten ist.

## Sprachen und Grammatiken
### Formale Sprachen
![[Formale Sprachen und Grammatiken#Formale Sprachen#Definition]]

![[Formale Sprachen und Grammatiken#Formale Sprachen#Beispiele]]

### Grammatiken
![[Formale Sprachen und Grammatiken#Grammatiken#Definition]]

#### Beispiel
- $\Sigma=\set{0,1}$
- $V=\set{S,A,B}$
- $P$ enthält:
	- $S \rightarrow AB$
	- $A \rightarrow \epsilon,0A$
	- $B \rightarrow \epsilon, 1B$

Mit dieser Grammatik kann man nun alle Wörter aus $\set{0^{m}1^{n}|m,n \in \mathbb{N}}$ zusammenbauen - es gilt $L(G)=\set{0^{m}1^{n}|m,n \in \mathbb{N}}$.

Zum Beispiel wird das Wort $0^{1}1^{2}=011$ folgendermaßen gebildet:
$$S \rightarrow AB \rightarrow 0AB \rightarrow 0\epsilon B = 0B\rightarrow 01B\rightarrow 011B\rightarrow 011\epsilon=011$$

![[Formale Sprachen und Grammatiken#Grammatiken#Chomsky-Hierarchien]]

In dieser Vorlesung befassen wir uns nur mit regulären Grammatiken, und wie man das Wortproblem für solche Grammatiken lösen kann.
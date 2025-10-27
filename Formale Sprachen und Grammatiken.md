# Formale Sprachen
## Definition
> Eine Formale Sprache ist eine [[Mengen|Menge]] von Zeichenketten (Wörtern).

Für eine formale Sprache benötigt man zunächst ein Alphabet.
Dieses Alphabet heißt $\Sigma$ und ist eine endliche Menge von Zeichen ($\Sigma\neq\emptyset$).

Ein Wort $w$ ist eine endliche Folge von Zeichen aus $\Sigma$.

$\Sigma^{*} := \text{Menge aller Wörter über } \Sigma$
$\epsilon := \text{leeres Wort}$, $\epsilon\in\Sigma^{*}$, $\Sigma^{+}:=\Sigma^{*}\setminus\set{\epsilon}$

> [!definition]
> **Formale Sprache**
> Menge $L\subseteq\Sigma^{*}$ heißt Formale Sprache über $\Sigma$.

## Beispiele
Mit dem Alphabet $\Sigma=\set{0,1}$ kann man sich z.B. folgende Sprachen basteln:
- $L=\set{\epsilon, 0, 010, 1111}$
- $L=\set{0^{m}1^{n} | m,n \in \mathbb{N}_0}$[^1]
- $L=\set{0^{n}1^{n}|n \in \mathbb{N}_0}$

[^1]: Eine Aneinanderreihung von $n$-mal dem Zeichen $a$ wird als $a^{n}$ dargestellt. $a^0$ ist das leere Wort $\epsilon$.

# Grammatiken
## Definition

> Eine Grammatik legt die Regeln für eine formale Sprache $L$ fest, sodass genau alle Worte aus $L$ mit diesen Regeln gebildet werden können.

> [!Definition]
> **Grammatik**
> $G=(\Sigma,V,S,P)$
> derart, dass:
> - $\Sigma$ ist endliches Alphabet aus sog. *Terminalsymbolen*
> - $V$ ist endliche Menge von *Nichtterminalsymbolen*, $\Sigma\cap V = \emptyset$
> - $S\in V$ ist das *Startsymbol*
> - $P$ ist endliche Menge von *Ableitungsregeln*. Eine Ableitungsregel $(l,r)$ bzw. $l \rightarrow r$ macht aus einer Reihe von Nichtterminalsymbolen $l \in V^+$ eine Reihe von Nichtterminal- oder Terminalsymbolen $r \in (V \cup \Sigma)^*$.

Mit der Grammatik kann man nun formulieren, welche Worte aus $\Sigma$ gültig sind und welche nicht. Die dadurch konstruierte Sprache nennt man dann $L(G)$ (="die von $G$ erzeugte Sprache").

## Chomsky-Hierarchien
### Motivation
> **[[Berechenbarkeitstheorie]]**
> Man hat eine Grammik $G$ und ein Wort $w\in\Sigma^{*}$. Das Wortproblem ist nun: ist $w\in L(G)$?

Wenn man keine Einschränkungen für seine Grammatik macht, ist das Wortproblem beliebig komplex und es gibt uU. *keine Algorithmen, um es zu lösen*. 

Das heißt, man muss Einschränkungen machen, und dafür gibt es die Chomsky-Hierarchien. Je höher die Chomsky-Nummer, desto mehr Einschränkungen sind definiert.

### Definition

> [!Definition]
> **Chomsky-Hierarchien**[^2]
> - Chomsky-0: *Grammatiken ohne Einschränkungen*
> - Chomsky-1: *Kontextsensitive Grammatiken*
> - Chomsky-2: *Kontextfreie Grammatiken*
> 	- Alle Ableitungsregeln $A \rightarrow v$ sehen so aus, dass links genau *ein* Nichtterminalsymbol steht ($A \in V$) und rechts eine beliebige Reihung von Nichtterminal- und Terminalsymbolen ($v \in (V \cup \Sigma)^*$).
> - Chomsky-3: *Reguläre Grammatiken*
> 	- Alle Ableitungsregeln $A \rightarrow v$ bilden von genau *einem* Nichtterminalsymbol ($A \in V$) auf ein Terminalsymbol gefolgt von einem Nichtterminalsymbol ab (also $v=\epsilon$ oder $v=aB$ mit $a \in \Sigma$ und $B \in V$). Man darf also nur von rechts was dranbauen.
> 		- $\Rightarrow$ "Rechtslineare Grammatik"
> 	- Es gibt auch linkslineare Grammatiken, die sind genau wie rechtslineare Grammatiken (also auch regulär), nur halt spiegelverkehrt $v=Ba$.


[^2]: $\forall n \in \set{1,2,3} :$ Chomsky $n$ ist in Chomsky $n-1$ enthalten.

### Kontextfreie Grammatiken

#### Backus-Naur-Form
Die Backus-Naur-Form ist die am weitesten verbreitete Darstellungsform einer kontextfreien Grammatik. Sie wurde unabhängig von den Chomsky-Hierarchien entworfen, bis irgendwer festgestellt hat, dass die BNF formal dasselbe beschreibt wie eine kontextfreie Grammatik.

In der BNF schreibt man die Ableitungsregeln zeilenweise auf. Eine Ableitungsregel steht in der Form `<Bezeichner des Nichtterminal> ::= *Reihung von Terminalen und Nichtterminalen*`. Nichtterminale stehen in spitzen Klammern `<>`, Terminale als einfache Buchstaben bzw. Ziffern. Gibt es mehrere Möglichkeiten, werden diese durch `|` getrennt.

Definition der PASCAL-Syntax in BNF:
```
 <Programm>               ::= 'PROGRAM' <Bezeichner> 'BEGIN' <Satzfolge> 'END' .
 <Bezeichner>             ::= <Buchstabe> <Restbezeichner>
 <Restbezeichner>         ::= | <Buchstabe oder Ziffer> <Restbezeichner>
 <Buchstabe oder Ziffer>  ::= <Buchstabe> | <Ziffer>
 <Buchstabe>              ::= A | B | C | D | … | Z | a | b | … | z
 <Ziffer>                 ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
 <Satzfolge>              ::= …
 …
```

#### Syntaxdiagramm
Man kann die BNF grafisch darstellen.

Terminale:
![[BNF_Diagramm_Terminale.png|400]]

Nichtterminale:
![[BNF_Diagramm_Nichtterminale.png|400]]

![[BNF_Diagramm_vereinfacht.png|500]]

Beschreibt das Syntaxdiagramm eine reguläre Grammatik, dann kann man daraus direkt das [[Endliche Automaten#Anschauliche Darstellung|Übergangsdiagramm eines DFAs]] ableiten.
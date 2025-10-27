# Reguläre Ausdrücke

## Definition
> [!abstract] Regulärer Ausdruck
> Ein **Regulärer Ausdruck** $R$ über Alphabet $\Sigma$ beschreibt die [[Formale Sprachen und Grammatiken#Chomsky-Hierarchien#Definition|reguläre Sprache]] $L(R)\subseteq\Sigma^{*}$. Er entsteht rekursiv über endliche Anwendungen folgender Regeln:
> Erstens: *Grundbausteine*
> - $\emptyset$ ist ein regulärer Ausdruck für die leere Sprache $\set{}$.
> - $\epsilon$ ist ein regulärer Ausdruck für die Sprache $\set{\epsilon}$.
> - $a$ für $a \in \Sigma$ ist ein regulärer Ausdruck für die Sprache $\set{a}$.[^1]
> 
> Zweitens: *Verknüpfungen*
> Sei $L(R_1)=L_1$ und $L(R_2)=L_2$. Dann gilt:
> - $(R_1)+(R_2)$ ist ein regulärer Ausdruck für die Vereinigung zweier Sprachen: $$L((R_1)+(R_2))=L_1+L_2:=L_{1} \cup L_{2}$$ (sprich: "$L_1$ oder $L_2$").
> - $(R_{1})\cdot(R_2)$ ist ein regulärer Ausdruck für die Konkatenation aller Wörter zweier Sprachen: $$L((R_{1})\cdot (R_{2})) = L_{1} \cdot L_{2} := \set{w_{1}w_{2} \in \Sigma^{*} \space | \space w_{1} \in L_{1}, w_{2} \in L_{2}}$$ (sprich: "Konkatenation von $R_{1}$ und $R_{2}$").
> - $(R_1)^*$ ist ein regulärer Ausdruck für den *Kleen'schen Abschluss* $L_{1}^{*}$ von $L_1$: $$L((R_{1})^{*}) = L_{1}^{*} := \bigcup\limits_{i\geq 0} L_{1}^{i}$$ mit $L_{1}^{0} := \set{\epsilon}$ und $L_{1}^{i} := L_{1} \cdot L_{1}^{i-1}$, also alle endlichen Konkatenationen von Wörtern aus $L_{1}$.

[^1]: Es gilt: $L(\emptyset)=\emptyset$, $L(\epsilon) = \set{\epsilon}$ und $L(a) = \set{a}$

## Schreibweise und Präzedenz
Präzedenz:
> $^{*}$ vor $\cdot$ vor $+$

Außerdem kann man die Klammern und oft auch den Punkt weglassen: 
$(0)\cdot(1)=01$
$(\epsilon)+(((1)\cdot(1))\cdot(1)) = \epsilon + 111$

Man schreibt auch $a | b$ statt $a+b$.
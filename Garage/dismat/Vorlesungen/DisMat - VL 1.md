Es geht um [[Graphen]]. 

Formal sind bei einem Weg (Folge von Knoten) keine Wiederholungen erlaubt, bei Kantenzügen schon.
Äquivalente Definition eines zusammenhängenden Graphen: jede Teilmenge hat eine Menge von Kanten, die aus dieser Teilmenge herausführen

Gerichterer Graph ist *stark zusammenhängend*
$\iff \forall v,w \in V(G) \space \exists$ $v$-$w$-Weg in $G$
$\iff \forall v,w \in V(G) \space \exists$ Kantenzug von $v$ nach $w$ in $G$
$\iff \forall \emptyset \neq X \subset V(G): \delta^{+}_{G}(X)\neq \emptyset$
$\iff \forall \emptyset \neq X \subset V(G): \delta^{-}_{G}(X)\neq \emptyset$
, wobei $\delta^{+}$ die ausgehenden bzw. $\delta^{-}$ die eingehenden Kanten von $G$ in die Teilmenge $X$ sind.

# Wir fangen an

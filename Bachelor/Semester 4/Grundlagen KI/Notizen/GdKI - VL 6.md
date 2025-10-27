Datum: 25.04.
[[AI06_SS24_Prop_Logic_240425_240418.pdf|Folien]]

# Logische Agenten

Wir erweitern unseren Agenten um eine *Wissensbasis* (knowledge base, kb).

Die KB enthält Sätze in einer Wissensrepräsentationssprache (Syntax). Diese Sätze können wir mit einer Wahrheitstheorie als Aussagen über die Welt interpretieren (Semantik).

Mit der KB haben wir zwei Schnittstellen:
- `Ask(KB, a)`: leite a aus KB ab
- `Tell(KB, a)`: ergänze KB um a

> **KB-Agent:** $\text{percept} \mapsto \text{action}$
> `Tell(KB, MakePerceptSentence(percept))`
> `action := Ask(KB, MakeActionQuery())`
> `Tell(KB, MakeActionSentence(action))`
> `return action`

Als Wissensrepräsentation bietet sich die [[Aussagenlogik]] an.

Zusammenfassung:
- Alphabet $\Sigma$ von automaren Aussagen
- Logische Verknüpfung ($\lnot$, $\land$, $\lor$, $\Rightarrow$, $\iff$)
- Literal: positives oder negiertes Atom
- Klausel: Disjunktion oder Konjunktion von Literalen
- Formel bzw. Satz: beliebige Verknüpfung von Literalen
- Interpretation: Zuweisung eines Wahrheitswertes zu jedem Atom: $\mathcal{I}: \Sigma \to \set{\text{True}, \text{False}}$
- Eine Interpretation kann eine Formel erfüllen oder nicht: 
	- $\mathcal{I} \models \varphi$ oder $\mathcal{I} \not\models \varphi$
	- Wenn $\mathcal{I} \models \varphi$, dann heißt $\mathcal{I}$ *Modell* von $\varphi$

Man kann jede Formel $\varphi$ in KNF bringen (siehe Luds & TI). 

Eine Formel $\varphi$ *folgt* aus einer KB ($\text{KB} \models \varphi$), wenn $\varphi$ unter allen Modellen von KB wahr ist.

> **Folgerungssätze für Wissensbasen**
> *Deduktionssatz:* $\text{KB} \cup \set{\varphi} \models \psi \iff \text{KB} \models \varphi \Rightarrow \psi$
> *Kontrapositionssatz:* $\text{KB} \cup \set{\varphi} \models \lnot \psi \iff \text{KB} \cup \set{\psi} \models \lnot \varphi$
> *Widerspruchssatz:* $\text{KB} \cup \set{\varphi} \text{ ist unerfüllbar} \iff \text{KB} \models \lnot \varphi$.

Nun möchten wir gerne entscheiden, ob $\text{KB} \models \varphi$, ohne alle möglichen Interpretationen betrachten zu müssen. Dafür brauchen wir ein Kalkül.

- Kalkül: Menge von *Inferenzregeln* und logischen Axiomen
- Beweisschritt: Anwendung einer Inferenzregel auf eine Menge von Formeln
- Beweis: Sequenz von Beweisschritten, wobei
	- die mit jedem Schritt neu abgeleiteten Formeln zu KB hinzugefügt werden
	- im letzten Schritt die *Zielformel* erzeugt wird

Wenn eine Formel $\varphi$ mit einem Kalkül $C$ aus einer KB beweisbar ist, schreiben wir $\text{KB} \vdash_{C} \varphi$ oder einfach $\text{KB} \vdash \varphi$. 

> [!abstract] Definition *Korrektheit* und *Vollständigkeit*
> Ein Kalkül $C$ heißt *korrekt*, wenn $$\text{KB} \vdash_{C}\varphi \Rightarrow \text{KB} \models \varphi.$$
> Ein Kalkül heißt *vollständig*, wenn jede Formel, die logisch aus KB folgt, sich auch mit $C$ ableiten lässt: $$\text{KB} \models \varphi \Rightarrow \text{KB} \vdash_{C}\varphi.$$

## Resolutionskalkül

- Man hat eine KB, deren Formeln alle in KNF vorliegen
- Eine Klausel besteht also aus $\lor$-verknüpften Literalen
	- Eine Klausel wird als Menge von Literalen geschrieben

***(Grund-)Resolutionsregel:*** aus Klauseln $K_{1} \cup \set{l}$ und $K_{2} \cup \set{\lnot l}$ wird neue Klausel $K_{3} = K_{1} \cup K_{2}$.

*Ableiten einer Klausel aus einer KB mit dem Resolutionskalkül:*
- Man nehme alle Klauseln aus der KB
- Man bilde alle möglichen Resolventen zweier Klauseln aus der KB
- Man füge diese Resolventen zur KB hinzu
- Man wiederhole das solange, bis die Klausel unter den Resolventen auftaucht
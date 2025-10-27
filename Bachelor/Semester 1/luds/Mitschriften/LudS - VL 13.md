Datum: 24.11.
[[13VL-Scan-DFA-Regulaere-Sprachen-Ausdruecke.pdf|Folien]]

# Reguläre Ausdrücke
Man hat nun gezeigt, dass ein DFA, ein NFA oder eine reguläre Sprache alles dasselbe ausdrücken. Um dieses Konzept zu verallgemeinern, gibt es *Reguläre Ausdrücke*.[^2]

[^2]: Auch bekannt als RegEx

![[Reguläre Ausdrücke#Definition]]
![[Reguläre Ausdrücke#Schreibweise und Präzedenz]]

# Reguläre Sprachen, zusammengefasst

> Sei $L\subseteq\Sigma^{*}$ eine Sprache. Dann sind folgende Aussagen äquivalent:
> - $L$ wird von DFA entschieden.
> - $L$ wird von NFA entschieden.
> - $L$ hat endlichen Nerode-Index $index(\mathrel{R_L})$.
> - $L$ lässt sich durch reguläre (rechtslineare oder linkslineare) Grammatik darstellen.
> - Es existiert ein regulärer Ausdruck, der $L$ beschreibt.

**Wieso interessiert uns das?**
Man kann *jedes beliebige Entscheidungsproblem* als Wortproblem definieren. Ein Entscheidungsproblem ist ein Berechnungsproblem, welches als Ja-Nein-Frage formuliert werden kann. Alle Eingabewerte (=Worte), welche ein "Ja" als Antwort erhalten, können als [[Formale Sprachen und Grammatiken#Formale Sprachen|Formale Sprache]] zusammengefasst werden.[^3]

Ein Problem als Wortproblem zu formulieren, kann also helfen, die Komplexität dieses Problems einzuschätzen.

[^3]: Zum Beispiel das [[Travelling Salesman Problem|TSP]]: eine Formale Sprache könnte alle Lösungen enthalten, welche Kosten $\leq k$ besitzen.
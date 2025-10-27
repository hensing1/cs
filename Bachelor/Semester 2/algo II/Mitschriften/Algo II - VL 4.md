Datum: 26.04.
[[Folien-2023-4-26.pdf|Folien]]
[[Skript AlgoII.pdf|Skript:]] Seiten 33 bis 38
[Video](https://uni-bonn.sciebo.de/s/YVfBpu1J5oiqZGj#/files_mediaviewer/Vorlesung-03.mp4)

*Kapitel 3: Berechenbarkeitstheorie*
# Turing- und Many-One-Reduktionen

## Definitionen

![[Reduktionen#^f49894]]

Beispiel: Turing-Reduktion der Diagonalsprache $D$ auf das Halteproblem $H$
![[Turing-Reduktion_Halteproblem.png|600]]

![[Reduktionen#^27d8a2]]

Die Many-One-Reduktion ist ein Spezialfall der Turing-Reduktion.

Allgemeines Schema einer Many-One-Reduktion:
![[Many-One-Reduktion.png|300]]

Man geht also davon aus, dass die Sprache $B$ berechenbar ist. Also bildet man die Eingabe $x$, für die man entscheiden will, ob sie zu $A$ gehört, auf eine Eingabe für die Turingmaschine für die Sprache $B$ ab.
Hierbei ist es wichtig, dass diese Abbildung berechenbar ist, d.h. dass für jede Eingabe in endlicher Zeit eine Ausgabe berechnet werden kann. 
Ist dies gegeben dann gilt:
> Wenn $B$ entscheidbar ist, dann ist auch $A$ entscheidbar. 
> Wenn $A$ nicht entscheidbar ist, dann ist auch $B$ nicht entscheidbar.

Man kann Turing-Reduktionen also anwenden, wenn man:
- die Entscheidbarkeit von $A$ zeigen möchte und weiß, dass $B$ entscheidbar ist
- die Unentscheidbarkeit von $B$ zeigen möchte und weiß, dass $A$ unentscheidbar ist.

## Beispiele

### Universelle Sprache
$$U=\set{\langle M \rangle w \mid M \text{ akzeptiert }w}$$
Die Universelle Sprache $U$ ist ähnlich zu dem Halteproblem, nur dass $M$ nicht nur auf $w$ hält, sondern $w$ auch akzeptiert.

Wir zeigen die Unentscheidbarkeit von $U$, indem wir das Halteproblem $H$ auf $U$ reduzieren.
Mit anderen Worten: wir zeigen $H \leq U$.

Wir tun also so, als hätten wir eine Turingmaschine, die $U$ entscheidet. Diese benutzen wir, um $H$ zu entscheiden.

Für eine Eingabe $\langle M \rangle w \in \set{0,1}^{\ast}$, für welche wir entscheiden möchten, ob sie zu $H$ gehört, konstruieren wir erst eine Turingmaschine $\langle M^{\star} \rangle$. $M^{\star}$ verhält sich genauso wie $M$, nur, dass sie die Eingabe *immer* akzeptiert, sofern sie hält.
Unsere Many-One-Reduktion ist also $$f(x)=\left\{\begin{align*}
x, &\text{ falls } x \text{ nicht mit einer Gödelnummer beginnt}\\
\langle M^{\star} \rangle w &\text{ sonst.}
\end{align*}\right.$$
$\langle M^{\star} \rangle w$ nehmen wir nun als Eingabe für unsere Turingmaschine, die $U$ entscheiden kann. $\langle M^{\star} \rangle w$ ist nämlich genau dann in $U$, wenn $\langle M \rangle w$ in $H$ ist: wenn $\langle M \rangle w$ hält, dann akzeptiert $M^{\star}$ die Eingabe $w$, und wenn $\langle M \rangle w$ nicht hält, dann hält auch $\langle M^{\star} \rangle w$ nicht und ist somit auch nicht in $U$.

### Spezielles und vollständiges Halteproblem
$$H_{\epsilon}=\set{\langle M \rangle \mid M \text{ hält auf } \epsilon}$$
Das spezielle Halteproblem $H_\epsilon$ ist die Sprache aller Gödelnummern, deren Turingmaschinen auf das leere Wort halten.

Die Reduktion $H \leq H_\epsilon$ verläuft ähnlich wie $H \leq U$. Wir konstruieren aus einer Eingabe $\langle M \rangle w$ eine Maschine $M^{\star}$, welche jede Eingabe löscht und das Verhalten von $M$ auf $w$ simuliert. 
Das bedeutet:
- Falls $M$ auf $w$ hält, dann hält $M^{\star}$ auf das leere Wort.
- Falls $M$ auf $w$ nicht hält, dann hält $M^{\star}$ nicht auf das leere Wort.

Man muss also nur noch $\langle M^{\star} \rangle$ in die Turingmaschine stöpseln, die $H_\epsilon$ entscheidet, und schon kann man das Halteproblem entscheiden.

Exakt dieselbe Reduktion funktioniert auch für das *vollständige Halteproblem*:
$$H_\text{all} = \set{\langle M \rangle \mid M \text{ hält auf jeder Eingabe}}$$
also die Sprache aller Gödelnummern, deren Turingmaschinen auf jede Eingabe halten.

Hätte man also eine Turingmaschine, die $H_\text{all}$ entscheiden kann, könnte man mit derselben Reduktion auch das Halteproblem entscheiden.

# Der Satz von Rice
![[Berechenbarkeitstheorie#Semantische Eigenschaften von Turingmaschinen (Satz von Rice)]]
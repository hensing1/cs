[[ALSS25_04_L_Loop_L_Systems.pdf]]
## Von Neumanns Universal Constructor

Eine Maschine in einem CA, die dazu in der Lage ist, beliebige Dinge zu konstruieren - insbesondere sich selbst.

Besteht aus:
- Recheneinheit
- Konstruktionsarm (kann schneiden, fusionieren, und erkennen)
- Ein Band (wie eine [[Turingmaschine]])
- Bandlese- und schreibmaschine

Der zugrundeliegende CA hat 29 Zustände.

## Langton's Loop

Eine kleinere Version von Von Neumanns Konstruktor, der nicht beliebig, sondern nur sich selbst repliziert.

Der CA hat 8 Zustände, die meisten Regeln führen in den silent state.
Nachbarschaft: von-Neumann, $r=1$

Langtons Loop hat nun eine Schleife, in der Signale im Kreis laufen, und einen Konstruktionsarm, in den die Signale kopiert werden.

Nachdem der Loop einen Tochterloop gebaut hat, macht er gegen den Uhrzeigersinn mit dem nächsten Loop weiter. Ist er an allen vier Seiten fertig, hört er auf und wird inaktiv. 
So breiten sich die Loops in alle Seiten aus, der Kern ist inaktiv und nur die äußere Hülle macht mit der Generation von neuen Loops weiter.

## Lindenmayer Systems

Einfache Lindenmayer-Systeme (bezeichnet mit D0L) sind equivalent zu [[Formale Sprachen und Grammatiken#Chomsky-Hierarchien|kontextfreien Grammatiken]].

> [!abstract] Definition *Lindenmayer-System*
> Ein Lindenmayer-System ist ein 4-Tupel $(V,C,\omega,P)$, mit:
> - $V$: Menge von Nichtterminalsymbolen
> - $C$: Menge von Terminalsymbolen
> - $\omega$: Startsymbol (Axiom, $\omega \in V \cup C$)
> - $P$: Produktionsregel, mit
> 	- $P: A^{n} \to A^{m}$ (kontextsensitiv)
> 	- $P: A^{1} \to A^{m}$ (kontextfrei, D0L)

Mit L-Systemen können Fraktale definiert und dargestellt werden.
L-Systeme definieren Befehle für "Turtle Graphics" (Befehle wie "gehe zu Position x,y", "Stift absetzen", "vorwärts gehen", "rotieren", "Stift hochheben"):
- `+` und `-`:
	- drehe um $\alpha$ Grad nach links bzw. rechts, skaliere mit $s$
- `[`: tu aktuelle Position auf den Stack
- `]`: hole Position vom Stack und gehe dorthin

Fraktale wie das Pascal'sche Dreieck, die Drachenkurve, oder Koch-Schneeflocke können so dargestellt werden, aber auch biologisch anmutende Muster:
![[Lindenmayerbaum.png]]

![[Lindenmayerfarn.png]]


# Ganzzahlen
> [!abstract] $g$-adische Darstellung
> Darstellung einer positiven Ganzzahl $w$ in Basis $g$:
> $$w=\sum\limits_{i=0}^{n-1}b_ig^{i}\text{, mit }0\leq b_{i}<g$$
> Die Zahl $w$ wird dann dargestellt durch die Aneinanderreihung der Ziffern $b_{n-1}$ bis $b_0$.

## Vorzeichenlose Binärzahlen
Durch 2-adische Darstellung kann mit $n$ Bits eine Zahl von $0$ bis $2^{n}-1$ dargestellt werden. Ein Vorzeichenbit wird nicht dementsprechend nicht verwendet.
$$w:\set{0,1}^{n}\rightarrow\mathbb{N}_0$$
Zahlen in diesem Format können als ganz normal wie Dezimalzahlen per Hand addiert, subtrahiert und multipliziert werden.

## Vorzeichenbehaftete ganze Zahlen
Genau wie die 2-adische Darstellung, nur dass das erste Bit als Vorzeichen interpretiert wird (0 = positiv, 1 = negativ).
$$
w:\set{0,1}^{n}\rightarrow\mathbb{Z}
$$

Dadurch ist der Zahlenbereich symmetrisch (von $-(2^{n-1}-1)$ bis $+2^{n-1}-1$), insgesamt $2^{n}-1$ Zahlen (die Null ist doppelt).

Vergleichsoperationen und Additionen werden tricky, sobald man negative Zahlen in der Rechnung hat.

## Zweierkomplement
Typische Darstellung von ganzen Zahlen in Computern.

Ist das erste Bit $b_{n-1}$ positiv, wird $2^{n-1}$ von dem Wert subtrahiert, der von $b_{n-2}$ bis $b_{0}$ kodiert ist.

![[Zweierkomplement.png|450]]

Die Null ist also nicht mehr doppelt, und der Zahlenbereich nicht symmetrisch.

Der Vorteil: Addition funktioniert ganz normal, auch mit negativen Zahlen! Wenn man zwei negative Zahlen addiert, muss man das Übertragsbit entsprechend ignorieren.

$$
\begin{aligned}
&0011_{2}&&3_{10}\\
+&1001_{2}&-&7_{10} \\
\hline \\
=&1011_2&-&4_{10}
\end{aligned}
$$
$$
\begin{aligned}
&1100_{2}&-4_{10}\\
+&1101_{2}&-3_{10} \\
\hline \\
=&\not11011_2&-7_{10}
\end{aligned}
$$

### Negation einer Zahl im Zweierkomplement
1. 1 abziehen
2. alle Bits invertieren

Funktioniert in beide Richtungen.

## Einerkomplement
Genau wie Zweierkomplement, nur dass bei $b_{n-1}=1$ nun $2^{n-1}-1$ abgezogen wird. Dadurch ist der Zahlenbereich wieder symmetrisch, die Null ist wieder doppelt, und man erhält die Negation einer Zahl durch Invertierung aller Bits.

## Einbettung
Wenn man, warum auch immer, eine $n$-Bit-Einer-oder -Zweierkomplementzahl in ein Wort mit $m>n$ Bits einbetten will, kann man *alle* Bits $b_{m-1},b_{m-2},...,b_{n}$ als Vorzeichenbit verwenden, und die Mathematik mit der Addition funktioniert immer noch.

# Kommazahlen
## Fixpunktdarstelung
Jedes Bit hat seine eigene Wertigkeit: ($\ldots,2^{2},2^{1},2^{0},2^{-1},2^{-2},\ldots$)
Man hat nun einen Tradeoff zwischen Genauigkeit der Zahl & Größe der darstellbaren Zahlen, je nachdem wo man das Komma (bzw. den Punkt) hinsetzt.

Mit $n$ Vorkommastellen und $m$ Nachkommastellen:
- Abstand zw. darstellbaren Zahlen: $\Delta f=2^{-m}$
- Wertebereich (mit Zweierkomplement): $-2^{n-1}\leq f \leq 2^{n-1}-n^{-m}$

Spezialfall $n=1$:
- Wertebereich: \[-1,1\[ (die -1 ist noch enthalten, die 1 nicht)
- Abgeschlossenheit bzgl. Multiplikation, d.h. das Ergebnis aller Multiplikationen ist darstellbar (bis auf $-1\cdot -1$)
- Wird bei bestimmten Signalprozessoren verwendet

Verschiebung des Kommas:
- $k$ Stellen nach rechts: selbe Bitfolge wird um $2^k$ größer
- nach links entsprechend um $2^{-k}$

Umrechnung von Dezimalzahl ins Binär-Fixpunktformat:
- skalieren: Zahl \* $2^m$
- runden
- umrechnen
- Binärpunkt setzen

## Gleitpunktdarstellung
Gewünschte Verbesserung gegenüber Fixpunktdarstellung: 
- Größerer Wertebereich
- (Nach Möglichkeit) konstante **relative** Distanz zwischen zwei darstellbaren Zahlen, anstatt konstanter *absoluter* Distanz wie bei Fixpunktdarstellung

Umsetzung: man macht es im Prinzip wie bei der wissenschaftlichen Darstellung von Dezimalzahlen ($2.9979\cdot 10^8$):
- Man nehme:
	- Vorzeichen
	- Mantisse
	- Exponent
- mehr Bits für Mantisse: höhere Genauigkeit
- mehr Bits für Exponent: höherer Zahlenbereich
- relative Genauigkeit weitgehend konstant über gesamten Zahlenbereich (es gibt kleinere "Sprünge" wenn sich der Exponent ändert)
- Damit man eine eindeutige Darstellung hat, muss man die Mantisse *normalisieren*:[^1]

> Normalisierte Mantisse in Basis 2: $1 \leq |w(m)| < 2$

Da eine normalisierte Mantisse in Basis 2 immer eine 1 vor dem Komma hat, kann man sie in der Darstellung auch weglassen. Diese Darstellung der Mantisse nennt man auch **Signifikand**.

### IEEE 754
Man braucht nun eine Standardisierung, sonst gibt es endlos viele Interpretationen derselben Binärfolge. Darum gibt es seit 1985 den Standard IEEE 754:
![[IEEE_754.png]]

Der Exponent steht vor der Mantisse, damit die signifikanteren Bits weiter vorne sind (Änderung des Exponenten hat höheren Einfluss auf den Wert der gesamten Zahl als Änderung der Mantisse).

Der Exponent wird nicht klassisch wie eine Ganzzahl repräsentiert, sondern mit einem "bias" - das nennt man dann **Charakteristik**. Bei einem Bias von 127 stellt die Charakteristik $00000000$ den Wert -127 dar.

|                    | Single Precision | Double Precision |
| ------------------ | ---------------- | ---------------- |
| Bits               | 32               | 64               |
| Bits im Exponenten | 8                | 11               |
| Bits in Mantisse   | 23               | 52               |
| Bias               | 127              | 1023             |

#### Sonderregeln
- Sind alle Bits der Charakteristik 0, ist die Mantisse denormalisiert (d.h. man denkt sich 0.\* statt 1.\*). Dadurch werden noch kleinere Zahlen darstellbar, und Mantisse = 000....0 heißt tatsächlich auch 0 (statt $1\cdot 2^{-\text{irgendwas}}$).
- Sind alle Bits der Charakteristik 1, dann ist die Zahl:
	- $+\infty$ oder $-\infty$ (abhängig vom Vorzeichenbit), wenn alle Bits der Mantisse 0 sind
	- NaN (not a number), falls mindestens ein Bit der Mantisse 1 ist.
		- Anscheinend hat man so wahnsinnig viele NaNs, damit man irgendwie Fehlercodes in der Gleitkommazahl speichern kann. Wird aber in der Praxis nicht wirklich gemacht.

[^1]: So, als würde man in Basis 10 immer nur eine Ziffer vor dem Komma haben.
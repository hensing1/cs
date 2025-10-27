Datum: 08.11.
[[TI_03_Boolesche_Algebra.pdf|Folien]] (Seiten 23 bis 38)

# Boolesche Funktionen

**Äquivalenz**
> Zwei [[Boolesche Algebra#Boolesche Funktionen|boolesche Ausdrücke]] $\Phi$ und $\Psi$ sind genau dann äquivalent, wenn beide genau dasselbe ausdrücken (dieselbe boolesche Funktion repräsentieren.)

In TI wird die [[Aussagen#Logische Operatoren|Äquivalenz]] mit $\leftrightarrow$ dargestellt, ist halt so.

Feststellung von Äquivalenz zweier Ausdrücke: 
- Darstellung durch Wahrheitstabelle
- Algebraische Umformung
	- Man kann einen Ausdruck in den anderen umformen
	- Man kann auch den Ausdruck $\Psi\leftrightarrow\Phi$ zu 1 umformen (manchmal einfacher)
- Erzeugen einer Normalform
	- Normalform $:\iff$ eindeutige Darstellung eines Ausdrucks
	- Beispiele
		- Wahrheitstabelle
		- Disjunktive & konjunktive Normalform (siehe unten)
		- Entscheidungsdiagramme

# Theoreme
![[Boolesche Algebra#Boolesche Funktionen#Theoreme#Negationstheorem]]
![[Boolesche Algebra#Boolesche Funktionen#Theoreme#Dualitätsprinzip der booleschen Algebra]]

# Strukturelle Induktion
Man kann [[Beweistechniken#Strukturelle Induktion|Strukturelle Induktion]] auch auf Boolesche Ausdrücke anwenden (bzw. Aussagen über Boolesche Ausdrücke).
Dann induktioniert man über die Formellänge $n$ (man zeigt eine Aussage für $n=1$, und zeigt, dass unter der Annahme, dass die Aussage für alle $k<n$ gilt, dass $A(n)\Rightarrow A(n+1)$).

## Beispiel: Negationstheorem
Zu zeigen: $$\lnot f(0,1,x_{1},\ldots,x_{n},\land,\lor,\lnot)=f(1,0,\lnot x_{1},\ldots,\lnot x_{n},\lor,\land,\lnot)$$
Ein beliebiger Ausdruck kann negiert werden, indem:
- jede 0 zu einer 1 wird und umgekehrt,
- jede Variable $x_i$ negiert wird, und
- jedes $\land$ zu einem $\lor$ wird und umgekehrt.

### Induktionsanfang
Man zeigt die Aussage für $n=1$ (für alle Formeln der Länge 1) - kann nur entweder $0$, $1$, oder $x$ sein ($x$ ist eine boolesche Variable).

### Induktionsannahme
Die Aussage gilt für alle $k$ mit $k<n$.

### Induktionsschritt
Eine beliebige Funktion (mit $n>1$) kann nur folgendermaßen aussehen:
1. $f=\lnot f_1$
2. $f=f_{1}\land f_{2}$
3. $f=f_{1}\lor f_{2}$

Unter der Annahme, dass die Aussage für $f_{1}$ und $f_{2}$ gilt, kann man nun die doppelte Negation und die De Morganschen Regeln anwenden, um alle drei Varianten algebraisch zu beweisen.

![[Boolesche Algebra#Boolesche Funktionen#Begriffsdefinitionen]]

![[Boolesche Algebra#Boolesche Funktionen#Vollständige Operatorensysteme]]
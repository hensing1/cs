Datum: 27.10.
[[6VL-Scan-Relationen-Abbildungen-Eigenschaften.pdf|Folien]]

# Beispiele für Relationen
![[Relationen#Relationsbeispiele#Kongruenz]]
Beispiel:
$7 \equiv_{5}2 \equiv_{5} -3$, denn:
- $7=1\cdot 5+2$
- $2=0\cdot 5+2$
- $-3=-1\cdot 5+2$

![[Relationen#Relationsbeispiele#Teilbarkeitsrelation]]
![[Relationen#Relationsbeispiele#Teilmengenrelation]]
# Darstellung
![[Relationen#Graphen]]
# Definitionen
Folgende Begriffe gelten für binäre Relationen:
![[Relationen#Eigenschaften binärer Relationen#Reflexive Relation]]
![[Relationen#Eigenschaften binärer Relationen#Symmetrische Relation]]
![[Relationen#Eigenschaften binärer Relationen#Antisymmetrische Relation]]

> [!attention] Achtung
> Relationen, bei denen $a \mathrel{R} b \land b \mathrel{R} a$ nie eintritt, sind trotzdem Antisymmetrisch.

![[Relationen#Eigenschaften binärer Relationen#Transitive Relation]]
![[Relationen#Eigenschaften binärer Relationen#Äquivalenzrelation]]
## Beispiele
- $<$
	- nicht symmetrisch: $1<2$, doch $2\not <1$
	- nicht reflexiv: $1\not <1$
	- transitiv: $a<b<c\Rightarrow a<c$
	- antisymmetrisch: $(a<b\land b<a)\Rightarrow a=b$
		- Bedingung wird nie erfüllt, daher gilt diese Implikation und $<$ ist daher antisymmetrisch
- $\leq$
	- wie $<$, nur dass $\leq$ reflexiv ist
- $\equiv_n$
	- Äquivalenzrelation
- $\subseteq$
	- reflexiv, transitiv, antisymmetrisch

## Auswirkungen der Relationseigenschaften auf Graphdarstellung
- reflexiv: an jedem Knoten eine Schlinge
- symmetrisch: Jeder Pfeil ist ein Doppelpfeil (oder eine Schlinge)
- antisymmetrisch: keine Doppelpfeile
- transitiv: es gibt Abkürzungen

# Abbildungen (Funktionen)
![[Funktionen#Definition]]

![[Funktionen#Schreibweise]]

---
![[Funktionen#Surjektive, Injektive und Bijektive Funktionen]]
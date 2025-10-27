# Strassen-Algorithmus
## Funktionsweise
Man hat zwei $(n\times n)$ Matrizen, die man miteinander [[Matrizen#Operationen|multiplizieren]] möchte.

Man könnte natürlich gemäß der Definition hingehen und alle Felder einzeln ausrechnen, das würde aber eine Laufzeit von $\Theta(n^3)$ haben: n\*n, um jedes Feld der Matrix zu besuchen, und dann $n$ multiplikationen pro Berechnung eines einzelnen Feldes.

Der Strassen-Algorithmus macht das Ganze etwas effizienter:
Er löst das Problem rekursiv, indem er 7 rekursive Aufrufe mit jeweils $n/2*n/2$-Matrizen macht, und diese am Ende wieder miteinander kombiniert - wie genau das passiert, ist erst mal egal, steht aber unten im Bild:
![[Strassen-Algorithmus.png]]

## Laufzeit
Wie sich herausstellt, ist dieser Algorithmus in der Komplexitätsklasse $\Theta(n^{\log_27})\approx\Theta(n^{2,81})$, und damit effizienter als die naive Berechnung. 

Warum das so ist, erfährt man mit einer [[Rekursionsgleichungen|Rekursionsgleichung]] $T(n)=a*T(n/b)+f(n)$ mit:
- $a=7$, da sieben rekursive Aufrufe getätigt werden
- $b=2$, da sich die "Seitenlänge" $n$ der Matrix für jeden rekursiven Aufruf halbiert
- $f(n)=c*n^2=\Theta(n^2)$, da man für die Addition zweier $n*n$-Matrizen auch $n^2$ Operationen braucht (eine pro Feld)
	- (in diesem Fall sind es Matrizen der Größe $n/2*n/2$, aber man kann es immer noch schreiben als $c*n^2$)

Und wenn man das ganze dann ausrechnet:
![[Rekursionsbaum_Strassen.png]]
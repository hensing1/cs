# Was ist das?
Mit einer Rekursionsgleichung kann man die [[Größenordnungen|Komplexitätsklasse]] eines rekursiven Algorithmus ermitteln. 
Diese Gleichung schreibt man $T(n)$, und man definiert sie folgendermaßen: ^f829ae
- Für $n=1$ geht man von einer konstanten Laufzeit aus: $T(1)=\Theta(1)$
- Für $n>1$ sagt man:
	- Es passieren $a$ rekursive Aufrufe, bei denen die Problemgröße um einen Faktor $1/b$ geringer wird
	- Dann passiert noch irgendein anderer Kram, der unter Umständen auch von $n$ abhängt - die Lauftzeit von diesem anderen Kram fasst man unter $f(n)$ zusammen
Also insgesamt:
$$T(n)=aT(n/b)+f(n)$$
für $n>1$.

# Rekursionsbäume
Wie man das Ganze dann ausrechnet, kann man anhand eines Rekursionsbaumes illustrieren:
![[Rekursionsgleichung.png]]

Die eigentliche Arbeit des Algorithmus (also das was Zeit kostet) findet ja nur in $f$ statt, und dann rechnet man quasi zusammen, wie oft und mit welchen Parametern $f$ aufgerufen wird.

## Beispiele
Angewandt auf [[Mergesort]]:
![[Rekursionsbaum_Mergesort.png]]

Angewandt auf [[Strassen-Algorithmus]]:
![[Rekursionsbaum_Strassen.png]]

# Master-Theorem
Für eine Rekursionsgleichung der Form $T(n)=a \cdot T\left(\frac{n}{b}\right)+ f(n)$ gilt:

1. Wenn $f(n)$ in $O(n^{\log_b(a)-\epsilon})$ mit $\epsilon > 0$, dann: $$T(n)=\Theta(n^{\log_ba})$$
2. Wenn $f(n)=\Theta(n^{\log_ba})$, dann: $$T(n)=\Theta(n^{\log_ba}*\log n)$$
3. Wenn $f(n)=\Omega(n^{log_b(a)+\epsilon})$ mit $\epsilon>0$, und zusätzlich $af(n/b)\le cf(n)$ ab einem hinreichend großen $n$ und $c<1$, dann: $$T(n)=\Theta(f(n))$$

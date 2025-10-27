Datum: 03.05.
[Annotiertes Skript](https://ecampus.uni-bonn.de/goto_ecampus_file_3031135_download.html)
[Notizen aus der Vorlesung](https://ecampus.uni-bonn.de/goto_ecampus_file_3031136_download.html)

*Bemerkungen zur letzten Vorlesung*
$a_n:=\sqrt[n]{n}$ konvergiert zu 1, obwohl das Wurzelkriterium für $(a_n)$ nicht gilt. Das Wurzelkriterium ist also ein hinreichendes, aber kein notwendiges Kriterium für absolute Konvergenz.

# Dezimalbrüche

> [!abstract] Dezimalbruch
> Die Reihe $$\pm \sum\limits_{n=-k}^{\infty}a_{n}10^{-n}$$ mit $k \in \mathbb{N}_0$ und $a_{n}\in \set{0,1,\ldots,9}$ heißt **Dezimalbruch**.

Die übliche Darstellung für einen Dezimalbruch ist $\pm a_{-k}\ldots a_{-1}\space a_{0},\space a_{1}\space a_{2}\space a_{3}\ldots$

Jeder Dezimalbruch konvergiert zu einer rellen Zahl. Umgekehrt lässt sich jede relle Zahl auch als Dezimalbruch darstellen.

Genau dann, wenn $x\in \mathbb{R}$ eine *periodische* Dezimalbruchdarstellung besitzt, ist auch $x \in \mathbb{Q}$.

# Cauchy-Produkt
![[Reihen#^0f6c76]]

![[Reihen#^0eac68]]

# Potenzreihen

![[Reihen#^7dce3b]]

Die Koeffizientenfolge darf hierbei nicht von $x$ abhängen. 

## Konvergenz von Potenzreihen

Für welche $x$ eine Potenzreihe konvergiert, kriegt man meistens mit dem Quotientenkriterium raus:
Man betrachtet$$\left| \frac{a_{n+1}(x-x_{0})^{n+1}}{a_n(x-x_{0})^{n}} \right|$$und errechnet den Grenzwert für $n \to \infty$ (man verwendet das Quotientenkriterium, weil sich meistens alles hübsch rauskürzt).
Für alle $x$, für die dieser Grenzwert $<1$ ist, konvergiert die Reihe absolut. 

![[Reihen#Konvergenzradius von Potenzreihen]]
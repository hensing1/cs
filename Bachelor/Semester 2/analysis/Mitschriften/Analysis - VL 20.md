Datum: 26.06.
[Annotiertes Skript](https://ecampus.uni-bonn.de/goto_ecampus_file_3073216_download.html)
[Notizen aus der Vorlesung](https://ecampus.uni-bonn.de/goto_ecampus_file_3073217_download.html)

# Lineare Differentialgleichungen

> [!abstract] Definition *Lineare Differentialgleichung*
> Eine Gleichung der Form $$y'(x)+a(x)y(x)=g(x)$$ heißt **lineare Dgl. erster Ordnung**.
> 
> Die Funktion $a$ heißt *Koeffizientenfunktion*.
> Die Funktion $g$ heißt *Inhomogenität*. Ist $g=0$, heißt die Dgl. *homogen*, ansonsten *inhomogen*.

Für die Lösungsmenge einer linearen Dgl. gilt dasselbe wie für die [[LA - VL 18#Lösungsmenge eines Gleichungssystems|Lösungsmenge eines linearen Gleichungssystems]]:

> Sei eine lineare Dgl. gegeben durch $$y'(x)+a(x)y(x)=g(x).$$
> Dann ist die Lösungsmenge für diese Gleichung: $$\mathcal{L}=\set{y_{p}+y_{h} \mid y_{h} \text{ löst }y_{h}'(x)+a(x)y_{h}(x)=0},$$ wobei $y_{p}$ eine *beliebige* Lösung für die oben gegebene Dgl. ist.

Also ist die Lösungsmenge für eine inhomogene Dgl. gleich der um $y_p$ "verschobenen" Lösungsmenge für die dazugehörige homogene Dgl.

## Lösung einer linearen Dgl.

> **Allgemeine Lösung der homogenen Differentialgleichung**
> Besitzt $a$ eine Stammfunktion $A$, dann ist die allgemeine Lösung für $$y'(x)+a(x)y(x)=0$$ gegeben durch $$y_{h}(x)=K \cdot e^{-A(x)},$$ wobei $K\in \mathbb{R}$ beliebig.

Denn: $\frac{d}{dx}K \cdot e^{-A(x)}=K \cdot e^{-A(x)} \cdot -a(x)$ (Kettenregel).
Die Lösungsmenge für eine homogene lineare Dgl. bildet einen [[Vektorräume|Vektorraum]].

> **Allgemeine Lösung der inhomogenen Differentialgleichung**
> Für eine Dgl. $$y'(x)+a(x)y(x)=g(x)$$ ist $y(x)=y_{p}(x)+y_{h}(x)$ mit $$y_{p}(x)=K(x) \cdot e^{-A(x)},$$ wobei $$K(x)=\int g(x)e^{A(x)}\,dx.$$ Da $y_{h}$ auch die Nullfunktion sein kann, ist insbesondere $y_{p}$ selbst eine Lösung für die inhomogene Dgl.

*Spezielle Lösung:*
Hat man ein *Anfangswertproblem* für eine lineare Dgl. gegeben, dann muss man ein bestimmtes $K$ finden.

Alles was wir uns angeschaut haben sind *gewöhnliche* Differentialgleichungen.

An klausurrelevantem Kram fehlen jetzt nur noch bestimmte Integrale

# Bestimmte Integrale
## Das Integral von Treppenfunktionen
Wir möchten jetzt die Fläche unter einer Funktion berechnen und da kommt das Integral ins Spiel

> [!abstract] Definition *Treppenfunktion*
> Eine Funktion $\varphi : \left[a,b\right] \to \mathbb{R}$ heißt **Treppenfunktion**, wenn es eine Zerlegung $Z := \set{t_{0},\ldots,t_{n}}$ von $\left[a,b\right]$ gibt[^1], sodass die Funktion für jedes $i$ im Intervall $\left]t_{i},t_{i+1}\right[$ konstant ist.
> Die Werte $\varphi(t_{i})$ an den Sprungstellen $t_{i}$ sind also *beliebig*.
> 
> $T(\left[a,b\right])$ bezeichnet die *Menge aller Treppenfunktionen* auf $\left[a,b\right]$.

[^1]: Zerlegung heißt: $a = t_{0} < t_{1} < \ldots < t_{n}=b.$

Eine Treppenfunktion ist überall definiert (auch an den Sprungstellen), aber sie muss an den Sprungstellen nicht den Wert links oder den Wert rechts haben.
Das wird später wichtig: wenn ich die Funktion an einer Stelle abändere, dann ändert sich das Integral nicht.

Ein paar einfache Sätze:
> - Wenn man eine Treppenfunktion bzgl. einer Zerlegung $Z$ hat, dann bleibt es eine Treppenfunktion bzgl. jeder feineren Zerlegung $Z' \supset Z$.
> - Die Summe von zwei Treppenfunktionen ist wieder eine Treppenfunktion.
> - Die Menge aller Treppenfunktionen ist ein [[Vektorräume#Untervektorräume|Untervektorraum]] der Menge aller Funktionen auf diesem Integral.

Der **(orientierte) Flächeninhalt** unter einer Treppenfunktion $\varphi$ bzgl. einer Zerlegung $Z$ ist: $$F_{a}^{b}(\varphi,Z):=\sum\limits_{k=1}^{n}c_{k}(t_{k}-t_{k-1}),$$wobei $c_{k}$ der Funktionswert im Intervall $\left]t_{k-1},t_{k}\right[$ ist.

Ist wieder $Z' \supset Z$, dann ist $F_{a}^{b}(\varphi,Z')=F_{a}^{b}(\varphi,Z)$.

> Es ist $$\int_{a}^{b}\varphi(x)\,dx:=F_{a}^{b}(\varphi):=F_{a}^{b}(\varphi,Z),$$wobei $Z$ eine beliebige Zerlegung ist, bezüglich der $\varphi$ eine Treppenfunktion ist.

> *Standardabschätzung für ein bestimmtes Integral*
> $$\left|\int_{a}^{b}\varphi(x)\,dx\right|\leq \|\varphi\|_{[a,b]}(b-a).$$


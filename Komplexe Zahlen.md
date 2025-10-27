# Komplexe Zahlen

> [!abstract] Definition
> Der **[[Ringe und Körper#Körper|Körper]] der komplexen Zahlen** ist definiert als $(\mathbb{R}^{2},+,\cdot)$, mit den Verknüpfungen definiert wie folgt:$$\begin{align*}(a,b)+(x,y)&:=(a+x,b+y)\\(a,b)\cdot(x,y)&:=(ax-by,bx+ay).\end{align*}$$

^62e4a2

## Schreibweise
Wir setzen $i:=(0,1)$ und schreiben $x$ für $(x,0)$ für alle $x\in \mathbb{R}$.
Somit kann die Gleichung $$(0,1)\cdot(0,1)=(-1,0)$$ geschrieben werden als $$i^{2}=-1.$$
Gleichzeitig gilt für $\lambda\in\mathbb{R}$ und $(a,b)\in\mathbb{R}^{2}$: $$\lambda(a,b)=(\lambda,0)(a,b)=(\lambda a,\lambda b)$$und somit $$a+ib=(a,0)+(0,b)=(a,b).$$
Genau wie $\mathbb{N}$ order $\mathbb{R}$ kann nun die Zahlenmenge $\mathbb{C}$ definiert werden als: $$\mathbb{C}:=\set{a+ib \mid a,b\in\mathbb{R}}.$$
Durch $i^{2}=-1$ gelten mit komplexen Zahlen in der Form $a+ib$ dieselben Rechenregeln wie bei den reellen Zahlen.

Ist $z=a+ib\in\mathbb{C}$, ist $\text{Re}(z)=a$ und $\text{Im}(z)=b$.

## Konjugation und Betrag

> [!abstract] Definition
> Sei $z=a+ib\in\mathbb{C}$.
> Das **Konjugierte** von $z$ ist definiert als $$\bar{z}:=a-ib.$$

Für $z_1,z_2\in\mathbb{C}$ gilt: $\overline{z_{1}z_{2}}=\overline{z_1}\cdot\overline{z_2}$ und $\overline{z_{1}+z_{2}}=\overline{z_1}+\overline{z_2}$.

Weiterhin ist $z\cdot\bar{z}=(a+ib)\cdot(a-ib)=a^{2}-(ib)^{2}=a^2+b^2\in\mathbb{R}$. 

Der *Betrag* von $z$ ist äquivalent zur euklidischen Distanz von $z$ zum Nullpunkt, wenn man $z$ in der Ebene darstellt: $$|z|:=\sqrt{z\cdot\bar{z}}=\sqrt{\text{Re}(z)^{2}+\text{Im}(z)^{2}}.$$
Es gilt $|z\cdot w|=|z|\cdot|w|$: $$\begin{align*}
|z \cdot w|&=\sqrt{z \cdot w \cdot \overline{z \cdot w}}\\
&=\sqrt{z \cdot w \cdot \bar{z} \cdot \bar{w}}=\sqrt{z \cdot \bar{z} \cdot w \cdot \bar{w}}\\
&=\sqrt{z \cdot\bar{z}}\cdot\sqrt{w \cdot\bar{w}}\\
&=|z|\cdot|w|.
\end{align*}$$
Die Addition zweier komplexer Zahlen ist äquivalent zur Vektoraddition im $\mathbb{R}^{2}$. Daher gilt auch die Dreiecksungleichung $|a|+|b|\geq|a+b|$ für komplexe Zahlen.

Bei der Multiplikation werden geometrisch gesehen die Winkel zusammenaddiert und die Beträge multipliziert.

## Neutrale und Inverse Elemente
Sei $z=a+ib$.


|               | Neutrales Element | Inverses Element                             |
| ------------- | ----------------- | -------------------------------------------- |
| Additiv       | $0$               | $-z=-a-ib$                                   |
| Multiplikativ | $1$               | $$z^{-1}=\frac{\bar{z}}{ \lvert{z}\rvert ^{2}}=\frac{(a-bi)}{a^{2}+b^{2}}$$ | 

## Wichtige Sätze
- Dreiecksungleichung
- "Fundamentalsatz der Algebra": Jedes komplexe Polynom hat eine komplexe Nullstelle
	- Ein Polynom von Grad n hat n Nullstellen (mit Vielfachheiten)
	- Jedes Polynom über $\mathbb{C}$ lässt sich schreiben als $a_{n}z^{n}+a_{n-1}z^{n-1}+\ldots+a_{1}z_{1}+a_{0}=a_{n}(z-\alpha_{1})(z-\alpha_{2})\ldots(z-\alpha_{n})$
	

## Polynome

Die Gleichung $x^{2}+px+q=0$ (mit $p,q\in\mathbb{R}$) hat im komplexen *immer* zwei Lösungen.

![[Glossar#PQ-Formel]]

Falls $q>\frac{p^{2}}{4}$, ist die Wurzel negativ und hat somit keine reelle Lösung. Für $a\in\mathbb{R}^{+}$ gilt $\sqrt{-a}=i\sqrt{a}$.

Für Polynome mit komplexen Koeffizienten gibt es eine Anleitung zur Bestimmung der Nullstellen [[Skript Analysis - SS2023 - Welter.pdf|im Ana-Skript auf S. 16]].

## Rechnen mit komplexen Zahlen
### Dividieren
Man dividert durch eine Zahl $z=a+bi$, indem man mit $\frac{a-bi}{a^{2}+b^{2}}$ multipliziert (siehe Inverses Element).

### Wurzelziehen

## Polarkoordinaten
### Grundlagen
Gegeben sei eine Zahl $z=a+ib$. $\varphi$ sei der Winkel zwischen dem Ortsvektor von $z$ und der reellen Achse:
![[Polarkoordinaten.png|300]]

Dann ist $a= |z| \cdot \cos \varphi$ und $b=|z| \cdot \sin \varphi$. Damit gilt: $$z=|z| \cdot (\cos \varphi + i \cdot \sin \varphi).$$

Aus irgendeinem Grund ergibt die *komplexe Exponentialfunktion* die folgende Gleichung:
$$e^{i \varphi}=\cos\varphi + i \cdot \sin \varphi,$$
und entsprechend die für $z\neq 0$ eindeutige **Polarkoordinatenschreibweise:** $$z=|z| \cdot e^{i\varphi}.$$
Hierbei gilt $-\pi < \varphi \leq \pi$.
Entsprechend gilt für die Berechnung von $\varphi$, gegeben eine Zahl $z=a+ib$:
$$\varphi=\left\{\begin{align*}
\arccos\left(\frac{a}{|z|}\right) &\text{ für } b \geq 0,\\
	-\arccos\left(\frac{a}{|z|}\right) &\text{ für } b<0.
\end{align*}\right.$$

Der Winkel $\varphi$ einer komplexen Zahl $z$ heißt auch $\arg(z)$.

### Multiplikation
Polarkoordinaten machen die Multiplikation komplexer Zahlen sehr einfach, denn es gilt: $$(|z_{1}|\cdot e^{i \alpha})\cdot(|z_{2}|\cdot e^{i \beta})=|z_{1}|\cdot |z_{2}|\cdot e^{i(\alpha + \beta)}.$$
![[Komplexe_Multiplikation.png|300]]

### Wurzelberechnung
Für die Wurzel einer komplexen Zahl $z$ gilt:  $$\sqrt[n]{z}=\sqrt[n]{|z|\cdot e^{i \varphi}}=\sqrt[n]{|z|}\cdot e^{i \frac{\varphi}{n}}.$$
Da jedoch $e^{i(\varphi+\tau)}=e^{i \varphi}$, gibt es für die $n$-te Wurzel auch $n$ Lösungen: $$z_{k}=\sqrt[n]{|z|}\cdot e^{i \frac{\varphi+k\space\tau}{n}}$$
für $k \in \set{0,1,\ldots,n-1}$.

Die 16 16-ten Wurzeln sehen geometrisch so aus:
![[Komplexe_Wurzel.png|400]]


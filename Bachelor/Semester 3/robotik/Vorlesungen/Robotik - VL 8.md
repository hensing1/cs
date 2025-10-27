Datum: 30.11.
[[Robotik_08_Dynamische_Systeme.pdf|Folien]]
# Dynamische Systeme

## Regelung durch Rückführung

*Situation*
Wir haben ein [[Robotik - VL 7#Systeme|System]], welches einen bestimmten Zustand erreichen soll.
Der gewünschte Zustand ist eine Referenzeingabe. 

- Vor das System wird ein *Regler* geschaltet. 
	- Der Regler verarbeitet die Differenz zwischen aktuellem und gewünschtem Systemzustand.
- Die Ausgabe vom Regler wird durch Aktuatoren umgesetzt. Die Ausgabe ist die Stellgröße $u$ für das System.
- Das Verhalten des Systems (gennant "Strecke") wird durch Sensoren gemessen.
	- Die Sensordaten werden rückgeführt und als Eingabe für den Regler verwendet.
- Durch Rechnenungenauigkeiten, Messfehler und äußere Einflüsse können Störungen in das System geraten.

![[Systemregelung_Rückführung.png]]

*Regelungsmodi*
Im Wesentlichen gibt es zwei Fälle:
- Die Regelgröße soll einen bestimmten Sollwert erreichen und sich danach nicht mehr verändern (Einschwingverhalten)
- Die Referenzeingabe ist veränderlich und die Regelgröße soll dieser Eingabe folgen (Folgeverhalten)

### Regler

Erwünschte Eigenschaften:
- Verfolgung des Referenzsignals
	- Regelgröße $y(t)$ soll Referenzeingabe $y_{r}(t)$ genau und schnell folgen
- Rückweisung von Störungen
	- Einfluss von $n(t)$ und $d(t)$ soll so gering wie möglich gehalten werden
- [[Robotik - VL 7#^9004a8|Stabilität]]
- Robustheit
	- Kleine Änderung der Parameter sollen nur kleine Effekte haben
- Realisierbarkeit
	- Regler soll einfach zu implementieren sein

Zielkonflikte:
- Rückweisung von Störungen vs. Robustheit
- Ideales Folgeverhalten vs. Realisierbarkeit

### Modellierung physikalischer Systeme

Ein physikalisches System (z.B. mit Federn, Massen und Dämpfern) lässt sich wie folgt modellieren:
- Zustand: unabhängige physikalische Größen, die die Fortschreibung der Systemdynamik erlauben (wenn die Eingaben bekannt sind)
	- im Beispiel: Position + Geschwindigkeit der Massen
- Eingaben: Anregungen des Systems von außen, die unabhängig vom Zustand sind
- Dynamik: Regeln, die die Änderung des Zustands aus dem aktuellen Zustand und der Eingabe beschreiben
	- $\to$ < Differenzialgleichung > erster Ordnung: $\frac{dx}{dt} = f(x,u)$
- Ausgaben: Kennzahlen für den Zustand
	- sind häufig Teilmengen des Zustands

Die Wahl der Modellierung ist nicht festgelegt.
## Lineare Systeme
Wir ziehen uns auf lineare Systeme zurück, damit wir es etwas einfacher haben.

> [!abstract] Definition *Lineares System*
> Ein System mit Zustand $x \in \mathbb{R}^{n}$, Eingabe $u \in \mathbb{R}^{p}$ und Ausgabe $y \in \mathbb{R}^{q}$ heißt linear, wenn die Übergangsfunktion $f$ und Ausgabefunktion $h$ gegeben ist als
> $$\begin{align*}\\
> \frac{dx}{dt}&=f(x, u)=Ax+Bu\\
> y &= h(x, u) = Cx+Du.
> \end{align*}$$
> mit $A \in \mathbb{R}^{(n,n)},\, B \in \mathbb{R}^{(n,p)},\,C \in \mathbb{R}^{(q,n)}$ und $D \in \mathbb{R}^{(q, p)}$.

## Auflösen von Dgl. höherer Ordnung

Bei der Beschreibung von physikalischen Systemen hat man häufig gewöhnliche lineare Dgl. *höherer Ordnung*, d.h. man hat Ableitungen $n$-ter Ordnungen vom Zustand:
$$\begin{gather}
\frac{d^{n}q}{dt^{n}}+a_{1}\frac{d^{n-1}q}{dt^{n-1}}+\ldots+a_{n}q = u \\
y = b_{1}\frac{d^{n-1}q}{dt^{n-1}} + \ldots + b_{n-1} \frac{dq}{dt}+b_{n}q
\end{gather}$$
Anstatt dass man nur einen Zustand $q$ hat und die riesige Differentialgleichung löst, kann man es in ein System von Dgl. erster Ordnung umwandeln und die ganzen Ableitungen in den Zustand aufnehmen: 
$$\frac{dx}{dt} = \frac{d}{dt} \begin{pmatrix}x_{1} \\ x_{2} \\ \vdots \\ x_{n-1} \\ x_{n}\end{pmatrix} = \frac{d}{dt}\begin{pmatrix}\frac{d^{n-1}q}{dt^{n-1}} \\ \frac{d^{n-2}q}{dt^{n-2}} \\ \vdots \\ \frac{dq}{dt} \\ q\end{pmatrix} = \begin{pmatrix}-a_{1} & -a_{2} & \ldots & -a_{n-1} & -a_{n} \\ 1 & 0 & \ldots & 0 & 0 \\ 0 & 1 & & 0 & 0 \\ \vdots & & \ddots & & \vdots \\ 0 & 0 & & 1 & 0\end{pmatrix}x + \begin{pmatrix}1 \\ 0 \\ 0 \\ \vdots \\ 0\end{pmatrix}u$$
$$y = \begin{pmatrix}b_{1} & b_{2} & \ldots & b_{n}\end{pmatrix}x$$

## Fixpunkte

Für ein System mit $\dot x = Ax$ (d.h. $B=0$) ist ein Fixpunkt eine Stelle, an der $\dot x = 0.$

Fixpunkt heißt:
- stabil, wenn nahe Startzustände in der Nähe bleiben
- Asymptotisch stabil, wenn nahe Startzustände zum Fixpunkt konvergieren
- Instabil, wenn es Startpunkte gibt, die sich vom Fixpunkt entfernen

Wenn alle Eigenwerte unserer Ableitungsmatrix (im Realteil) kleiner Eins sind, hat man einen asymptotisch stabilen Fixpunkt.

Für $\dot x = Ax$ ist der Fixpunkt immer Null.

Nichtlineare Systeme: um Fixpunkt herum linearisieren

## Phasenportraits

Ist der Zustand zweidimensional, kann man die Zustandsänderungen $\dot x = f(x, u(x))$ in der Ebene Zeichnen.


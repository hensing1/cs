Datum: 23.11.
[[Robotik_07_Inverse_Kinematik__Trajektoriengenerierung__Systeme.pdf|Folien]]

Übung: [[Uebung_06.pdf]]
# Trajektoriegenerierung

## Inverse Kinematik mit redundanten Gelenken

Die inverse Kinematik (aus [[Robotik - VL 6|letzter Vorlesung]]) ist nicht immer eindeutig: hat man [[Robotik - VL 4#Redundanz|redundante]] Gelenke, kann dieselbe Endeffektorpose aus mehreren Gelenkwinkelstellungen resultieren.

Die Jacobimatrix ist dann nicht mehr quadratisch. Man nutzt also die [[Matrizen#Pseudoinverse|Pseudoinverse]] $J^{+}.$

## Ansätze

### Interpolation im Gelenkraum
- Bestimme Gelenkwinkel in Start- und Zielpose (mit inverser Kinematik)
- Interpoliere zwischen den Gelenkstellungen

*Vorteile:*
- Wenig Rechenaufwand
- Keine Probleme mit [[Robotik - VL 6#Kinematische Singularität|Singularitäten]]

*Nachteil:*
- Roboterarm folgt keiner geraden Linie

### Interpolation im Arbeitsraum
- Generiere Trajektorie als Interpolation zwischen gewünschten Koordinaten des Endeffektors
- Löse inverse Kinematik für jeden Zeitschritt

*Vorteile:*
- Roboterarm kann genauer Linie / Trajektorie folgen

*Nachteile:*
- Hoher Rechenaufwand
- Zwischendurch kann eine singuläre Konfiguration erreicht werden, oder der Roboterarm kann einen Punkt auf der Trajektorie überhaupt nicht erreichen
	- Bei Annäherung an Singularität können die benötigten Gelenkgeschwindigkeiten beliebig groß werden

## Arten von Interpolation

### Lineare Interpolation

Gegeben: zwei Gewünschte Gelenkwinkel $\theta_0$ und $\theta_f$ zu den Zeitpunkten $t_0$ und $t_f$: $$\begin{align*}
\theta(t_{0}) &= \theta_0\\
\theta(t_{f}) &= \theta_f
\end{align*}$$

$\to$ finde Koeffizienten $a_0$ und $a_1$ für $\theta(t) = a_{0} + a_{1}t$, sodass diese Randbedingungen erfüllt sind.

Hat man mehrere Zwischenbedingunen, kann es zu Unstetigkeiten der Geschwindigkeit kommen.

### Kubische Interpolation (Splines)

Gesucht: Koeffizienten $a_i$ für $$\theta(t) = a_{0}+ a_{1}t + a_{2}t^{2}+ a_{3}t^{3}$$
sodass:
$$\begin{align*}
\theta(0) &= \theta_{0},&\theta(t_{f}) &= \theta_{f} & \text{(Randbedingungen für Position)}\\
\dot\theta(0) &= 0, & \dot \theta(t_{f}) &= 0 & \text{(Geschwindigkeit an Rändern gleich Null)}
\end{align*}$$

Damit folgt die Geschwindigkeit einem quadratischen Polynom. Entsprechend ist die Beschleunigung linear und der Ruck (Beschleunigung der Beschleunigung) ist konstant.

Alternativ können auch mit $\dot\theta(0) = \dot\theta_{0}$ und $\dot\theta(t_{f}) = \dot\theta_f$ Randgeschwindigkeiten gesetzt werden, zwischen denen dann interpoliert wird.
# Systeme

Wir befassen uns mit **Regelungstechnik:** Wir möchten den Zustand eines Systems regulieren, welches auf Eingaben reagieren und gleichzeitig äußere Störeinflüsse zurückweisen soll.

Die Regelung besteht also aus:
- Messung der zu regelnden Größe
- Berechnung der erforderlichen Reglerparameter
- Aktuation des Reglers
in einer Rückkopplungsschleife.

*Ziele:*
- *Statische Performanz* - System hält gewünschten Zustand (z.B. Geschwindigkeit)
- *Dynamische Performanz* - System reagiert schnell auf Änderungen der Eingabe
- *Robustheit* - System toleriert Änderungen in der Dynamik (Störungen, Änderungen der Systemparameter, etc.)

## Definitionen

Ein **Dynamisches System** ist ein System mit einem internen Zustand.

> **Systemklassen**
> - *Zeitdiskret* - Zustand aktualisiert sich in regelmäßigen Abständen
> - *Zeitkontinuierlich* - Zustand ändert sich kontinuierlich
> - *Ereignisbasiert* - Zustand ändert sich nur bei Ereignissen

> [!abstract] Definition *Zeitdiskretes System*
> Ein zeitdiskretes System ist ein dynamisches System, welches wie folgt modelliert wird:
> - *Zeitbasis* $T$ isomorph zu den natürlichen Zahlen: $$T = t_{c} \cdot \mathbb{N}$$
> - *Zustandsmenge* $X$
> - *Eingabemenge* $U$
> - *Ausgabemenge* $Y$
> - *Zustandsübergangsfunktion* $$\varphi : U \times X \to X$$
> - *Ausgabefunktion* $$\eta : X \to Y$$

Die Eingabefolge wird beschrieben mit $u : T \to U$ mit $n \mapsto u[n]$.
Gleichermaßen für die Ausgabefolge: $y : T \to Y$ mit $n \mapsto y[n]$.


> [!abstract] Definition *Zeitkontinuierliches System*
> Ein zeitkontinuierliches System ist ein dynamisches System, welches wie folgt modelliert wird:
> - *Zeitbasis* $T = \mathbb{R}$
> - *Zustandsmenge* $X = \mathbb{R}^{n}$
> - *Eingabemenge* $U = \mathbb{R}^{m}$
> - *Ausgabemenge* $Y = \mathbb{R}^{p}$
> - *Zustandsübergangsfunktion* $$\varphi : U \times X \to X$$ ist beschreiben durch < Differenzialgleichungen>, z.B. $\dot x = f(x,u)$
> - *Ausgabefunktion* $$\begin{gather}\eta : X \to Y \\ \text{oder} \\ \eta : X \times U \to Y\end{gather}$$

> [!note] Notation
> - für zeitdiskrete Systeme nimmt man eckige Klammern: $u[t]$, $y[t]$
> - für zeitkontinuierliche Systeme nimmt man runde: $u(t)$, $y(t)$
> - mit $\mathcal{T}$ bezeichnet man den mathematischen Zusammenhang zwischen Eingabe $u(t)$ und Ausgabe $y(t)$: $$\mathcal{T} \set{u(t)} = y(t)$$
> 	- man nimmt die Mengenklammern, weil... die Ausgabe von einer Menge von Eingaben bis $t$ abhängt..? Oder so?

> **Open Loop vs. Closed Loop**
> Bei einem Closed-Loop-System gibt es eine Rückkopplung, d.h. die Ausgabe von einem System ist die Eingabe vom anderen System, und umgekehrt.
> Bei Open-Loop-Systemen gibt es keine Rückkopplung.

> **Zustandslose Systeme vs. Systeme mit Zustand**
> Bei einem zustandslosen System hängt die Ausgabe $y(t)$ nur von der Eingabe $u(t)$ ab.
> Bei einem System mit Zustand hängt sie auch von Eingaben $u(t')$ zu anderen Zeitpunkten $t'$ ab.

> **Kausalität**
> 
> > *Kausales System*
> > Ein System ist kausal, wenn eine Reaktion nicht zeitlich vor der Ursache $u(t)$ erfolgen kann.
> > 
> > Formal ausgedrückt: ein System ist genau dann kausal, wenn zwei bis zu einem Zeitpunkt $t$ identische Eingabesignale $u_{1}(t), u_{2}(t)$ dieselbe Ausgabe verursachen.
> 
> > *Kausales Signal*
> > Ein Signal $f(t)$ ist kausal, wenn $$f(t) = 0 \;\forall t<0.$$

> **Linearität**
> 
> > *Skalierungseigenschaft*
> > Ein System erfüllt die Skalierungseigenschaft, wenn die Skalierung der Eingabe mit Faktor $k$ auch die Ausgabe mit $k$ skaliert: $\mathcal{T} \set{k \cdot u(t)} = k \cdot \mathcal{T} \set{u(t)}$
> 
> > *Superpositionseigenschaft*
> > Ein System erfüllt die Superpositionseigenschaft, wenn es keinen Unterschied macht, ob zwei Signale vor oder nach dem Durchgang durch das System addiert werden: $T \set{\sum_{i=1}^{n}u_{i}(t)} = \sum_{i=1}^{n}T \set{u_{i}(t)}$
> 
> Ein System ist linear, wenn es die Skalierungseigenschaft und die Superpositionseigenschaft erfüllt. $$\mathcal{T} \left\{\sum_{i=1}^{n}k_{i}u_{i}(t)\right\} = \sum_{i=1}^{n}k_{i}\mathcal{T} \set{u_{i}(t)}$$

^9b9431

> **Zeitinvarianz**
> Ein System ist zeitinvariant, wenn das Systemverhalten nicht von der Zeit abhängt: $$\mathcal{T} \set{u(t-t_{0})} = y(t-t_{0}) \; \forall t \in T, \, t-t_{0}\in T$$

^c8979f


Wir mögen lineare Systeme, weil komplexes Systemverhalten als Summe aus einfachen Systemverhalten dargestellt werden kann.
1. Zerlege (komplexe) Eingabe in einfache Eingaben, für die das Systemverhalten einfach bestimmt werden kann
2. Berechne Ausgaben
3. Addiere Ausgaben

> **LTI-System**
> Ein System, welches die [[Robotik - VL 7#^9b9431|Linearität]] und [[Robotik - VL 7#^c8979f|Zeitinvarianz]] erfüllt, heißt LTI-(Linear Time-Invariant-) oder LZI-System.

^534ff5

> **Stabilität**
> Ein System heißt stabil, wenn eine begrenzte Eingabe nur eine begrenzte Ausgabe erzeugt. $$|u(t)|<M<\infty \Rightarrow \exists N: |\mathcal{T}\set{u(t)}|<N<\infty$$

^9004a8


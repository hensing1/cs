Datum: 14.12.
[[Robotik_10_Beobachter.pdf|Folien]]

Übung: [[Uebung_09.pdf]]

# Beobachter

## Beobachtbarkeit

Bislang haben wir klammheimlich die Annahme gemacht, dass wir Zugriff auf den Zustand haben. Das ist aber meistens nicht so.

Anstatt $$u = -Kx + k_{r}r$$ schätzen wir den Zustand mit einem Beobachter.

> [!abstract] Definition *Beobachtbarkeit*
> Ein dynamisches System $$\begin{align*}\dot x&=f(x,u)\\y &= h(x,u)\end{align*}$$ ist beobachtbar, wenn es für jedes $T>0$ möglich ist, den Zustand des Systems $x(T)$ aus den Messungen von $y(t)$ und $u(t)$ im Intervall $[0,T]$ zu bestimmen.

Die Beobachtbarkeit eines linearen Systems $\dot x = Ax+Bu,\,y=Cx+Du$ hängt von den Matrizen $A$ und $C$ ab.

### Beobachtbarkeitstest
Ein lineares System ist genau dann beobachtbar, wenn die Beobachtbarkeitsmatrix $W_{o}$ vollen Rang hat: $$W_{o}=\begin{pmatrix}C \\ CA \\ CA^{2} \\ 
\vdots \\ CA^{n-1}\end{pmatrix}.$$
Insbesondere ist die Beobachtbarkeit damit unabhängig von dem gewählten Zustandsraum, sondern hängt nur vom System ab.

### Normalform zur Beobachtung

???

Was ist $z$? Was sind die Koeffizienten $a_1$ und $b_1$??

$$\frac{dz}{dt} = \begin{pmatrix}-a_{1} & 1 & 0 & \ldots & 0 \\ -a_{2} & 0 & 1 & & 0 \\ \vdots & & \ddots &  \\ -a_{n-1} & 0 & 0 & & 1 \\ -a_{n} & 0 & 0 & \ldots & 0\end{pmatrix}z + \begin{pmatrix}b_1 \\ b_{2} \\ \vdots \\ b_{n-1} \\ b_n\end{pmatrix}u$$
$$y = \begin{pmatrix}1 & 0 & 0 & \ldots & 0\end{pmatrix}z + Du$$

## Design

Wir haben das lineare System $$\begin{align*}
\dot x &= Ax + Bu\\
y &= Cx.
\end{align*}$$
Der Beobachter hat keinen Zugriff auf den Zustand $x$, aber wir kennen die Matrizen $A$, $B$ und $C$.

Für den geschätzten Zustand $\hat x$ modellieren wir die Änderung als: $$\dot {\hat x} = A \hat x + Bu + L(y-C\hat x).$$

Dabei ist: 
- $A \hat x + Bu$ die Zustandsvorhersage
- $y - C \hat x$ der Ausgabefehler
- $L$ die *Gain-Matrix*, durch welche der geschätzte Zustand anhand des Vorhersagefehlers angepasst wird.

### Bestimmen der Gain-Matrix

Mit $\tilde x = x-\hat x$ beschreiben wir den Fehler des geschätzten Zustands.

Es ist: $$\begin{align*}
\dot{\tilde x} &= \dot x - \dot{\hat x}\\
&= Ax + Bu - (A \hat x + Bu + L(y-C\hat x))\\
&= Ax - A\hat x - L(y - C\hat x)\\
&= Ax - A\hat x - L(Cx - C \hat x)\\
&= A(x - \hat x) - LC (x - \hat x)\\
&= (A - LC) (x - \hat x)\\
&= (A - LC) \tilde x.
\end{align*}$$
Wenn wir also $L$ so wählen, dass die *Eigenwerte* von $(A - LC)$ *negative Realteile* besitzen, dann gilt $\lim\limits_{t \to \infty}\tilde x(t) = 0$.
Voraussetzung ist natürlich, dass $(A, C)$ beobachtbar ist, also dass $W_o$ vollen Rang besitzt.

Das Bestimmen der Beobachter-Gains $L$ ist also analog zur Bestimmung des [[Robotik - VL 9#Zustandsrückführung|Feedback-Gains]] $K$ für den Regler.

## Separationsprinzip

Oft ist es so, dass man den *Regler* (mit Zustandsrückführung) *auf Grundlage des Beobachters* (mit Zustandsschätzung) entwirft: 

![[System_Beobachter_Regler.png|500]]

Das **Separationsprinzip** besagt: 
> Das System ist [[Robotik - VL 7#^9004a8|stabil]], wenn Regler und Beobachter jeweils stabil sind. Der Regler darf dabei auch vom tatsächlichen Zustand $x$ anstatt vom geschätzten $\hat x$ ausgehen.



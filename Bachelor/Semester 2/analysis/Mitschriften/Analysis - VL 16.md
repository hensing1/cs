Datum: 12.06.
[Annotiertes Skript](https://ecampus.uni-bonn.de/goto_ecampus_file_3062029_download.html)
[Notizen aus der Vorlesung](https://ecampus.uni-bonn.de/goto_ecampus_file_3062030_download.html)

# Mehr Sinus
Wir schauen uns erst mal die Sinus- und Cosinusfunktion analytisch an:

Mit dem < Satz von Taylor > kann man zeigen, dass die Sinusfunktion im Intervall $]0,2[$ überall positiv ist, was bedeutet, dass der Cosinus in diesem Bereich streng monoton fällt (weil $\cos'(x)=-\sin(x)$).
Weil $\cos(0)=1$ und $\cos(2)\leq -\frac{1}{3}$ (letzteres kann man auch mit dem Satz von Taylor zeigen), folgt aus dem < Mittelwertsatz>, dass es *mindestens* eine Nullstelle in $]0,2[$ gibt. Wegen der strengen Monotonie kann es nur *höchstens* eine Nullstelle geben, woraus folgt, dass es *genau eine* Nullstelle in diesem Intervall gibt.
Diese Nullstelle nennen wir $\frac{\pi}{2}$.

> **Periodizität von Sinus und Cosinus**
> Die Funktionen $\sin, \cos : \mathbb{R}\to \mathbb{R}$ sind *periodisch mit Periode $2 \pi$*, d.h. für alle $x\in \mathbb{R}$ gilt: $$\begin{gather}\cos(x+2\pi)=\cos(x)\\ \sin(x+2\pi)=\sin(x)\end{gather}$$
> Außerdem: $$\begin{align*}
\cos(x+\pi)&=-\cos(x)\\
\sin(x+\pi)&=-\sin(x)\\
\cos\left(x+ \frac{\pi}{2}\right)&=-\sin(x)\\
\sin\left(x+ \frac{\pi}{2}\right)&=\cos(x)
\end{align*}$$

Schließlich gilt für alle $z\in \mathbb{C}$: $\sin^{2}(z)+\cos^{2}(z)=1$.

Nullstellen:
> $\cos(x)=0 \iff x\in \set{\frac{\pi}{2}+k \pi \mid k \in \mathbb{Z}}$
> $\sin(x)=0 \iff x \in \set{k \pi \mid k \in \mathbb{Z}}$

Wir definieren noch geschwind die [[Komplexe Zahlen#Polarkoordinaten|Polarkoordinaten]].

Der komplexe Logarithmus macht vollkommen wylde Dinge und ich hab nicht den Kopf das alles zu verstehen, aber es kommt ziemlich oft $\pi$ drin vor und der komplexe Teil ist spiralförmig aus Gründen.

# Der Satz von de l'Hospital

> **Satz von de l'Hospital**
> Seien $f,g: I \to \mathbb{R}$ stetige, differenzierbare Funktionen und $I$ ein < verallgemeinertes Intervall>, sowie $a\in I$.
> Gelte außerdem $f,g \stackrel{x \to a}{\longrightarrow}0$ oder $f,g \stackrel{x \to a}{\longrightarrow}\infty$, und seien zudem $g(x)$ und $g'(x)$ ungleich 0 in der Nähe von $a$.
> 
> Falls nun der Grenzwert $\lim\limits_{x \to a} \frac{f'(x)}{g'(x)}$ existiert, dann existiert auch der Grenzwert $\lim\limits_{x \to a} \frac{f(x)}{g(x)}$ und es gilt $$\lim\limits_{x \to a} \frac{f(x)}{g(x)}=\lim\limits_{x \to a} \frac{f'(x)}{g'(x)}.$$

Man kann damit also Grenzwerte ausrechnen, die eigentlich aussehen wie "$\frac{0}{0}$" oder "$\frac{\infty}{\infty}$".
Wenn dazu Aufgaben drankommen, gibt es die Hälfte der Punkte allein schon, wenn man die ganzen Vorbedingungen prüft.

# Newton-Verfahren

Mittels des Newton-Verfahrens kann man iterativ eine approximative Lösung für Gleichungen der Form $f(x)=0$ bestimmen.

Das geht so:
- Wähle einen Punkt $x_{0}$, welcher im Idealfall irgendwo in der Nähe der Nullstelle liegt und für den $f'(x_{0})\neq 0$ gilt.
- Bestimme die Tangentengleichung von $f$ an der Stelle $x_{0}$: $$g(x):=f(x_{0})+f'(x_{0})(x-x_{0})$$
- Bestimme die Nullstelle $x_{1}$ dieser Geraden: $x_{1}:=x_{0}- \frac{f(x_{0})}{f'(x_{0})}.$ Diese Nullstelle liegt (hoffentlich) näher an der Nullstelle von $f$.
- Wiederhole Schritt 2 mit $x_{1}$.

![[Newton-Verfahren.png|400]]

Falls dieser Prozess *konvergiert*, hat man eine Nullstelle gefunden. 

> Im Allgemeinen konvergiert das Newton-Verfahren *nicht*.
> Es gibt jedoch Kriterien, die eine Konvergenz garantieren.


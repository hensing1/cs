Datum: 11.01.
[[Robotik_12_DFT_Z-Transformation.pdf|Folien]]

Übung: [[Uebung_11.pdf]]

# Laplace-Transformation II

Die Rücktransformation der Laplace-Transformation ist: $$f(t) = \frac{1}{2\pi j}\int_{\sigma-j\infty}^{\sigma+j \infty}F(s)e^{st} \,ds$$mit $s = \sigma + j \omega$, also Integral entlang der Vertikalen bei $\sigma$.

Für $\sigma = 0$ ergibt sich die normale Fourier-Transformation.

> Das [[Robotik - VL 11#Konvolutionstheorem|Konvolutionstheorem]] gilt auch für Laplace-Transformationen.

## Eigenschaften der Laplace-Transformation

- Ableitung:
  $\frac{d}{dt}f(t) \stackrel{\text{LT}}{\longrightarrow}s F(s) - f(0)$
- Linearität: 
  $k_{1}f_{1}(t)+k_{2}f_{2}(t)\stackrel{\text{LT}}{\longrightarrow} k_{1}F_{1}(s)+k_{2}F_{2}(s)$
- Zeitverschiebung: 
  $f(t-t_{0})\stackrel{\text{LT}}{\longrightarrow}F(s)e^{-st_{0}}$

## Rationale Laplace-Transformation
*Zweck: Stabilitätsanalyse*

Man hat ein System beschrieben als Differentialgleichung, d.h. *der Output und die Änderungen des Outputs* hängen ab von dem *Input und den Änderungen des Inputs:*

$$\begin{align*}
b_{0}y(t) &+ b_{1}\frac{d}{dt}y(t) + \ldots + b_{n} \frac{d^{n}}{dt}y(t)\\
=a_{0}u(t) &+ a_{1} \frac{d}{dt}u(t) + \ldots + a_{m} \frac{d^{m}}{dt}u(t)
\end{align*}$$

Mit Startpunkt $y(0) = y'(0) = \ldots = u(0) = u'(0) = \ldots = 0$ ergibt sich die folgende Laplacetransformation: $$
\begin{align*}
b_{0}Y(s) &+ b_{1}sY(s) + \ldots + b_{n}s^{n}Y(s)\\
= a_{0}U(s) &+ a_{1}sU(s) + \ldots + a_{m}s^{m}U(s).
\end{align*}$$
Ausklammern und umformen: 
$$\begin{align*}
&\quad\,\,Y(s)(b_{0}+b_{1}s + \ldots + b_{n}s^{n})\\
&=U(s)(a_{0}+a_{1}s + \ldots + a_{m}s^{m})\\
\iff \frac{Y(s)}{U(s)}&=\frac{a_{0}+a_{1}s+\ldots+a_{m}s^{m}}{b_{0}+b_{1}s+\ldots+b_{n}s^{n}}
\end{align*}$$

Wir betrachten $H(s) = \frac{Y(s)}{U(s)} = \frac{\sum_{j=0}^{m}a_{j}s^{j}}{\sum_{i=0}^{n}b_{i}s^{i}}$ als [[Robotik - VL 11#Transferfunktion|Transferfunktion]] mit reellen Koeffizienten $a_{i},b_{j}$.
- Zähler und Nenner sind Polynome von $s$
- Genannt *rationale* Transferfunktion

Wir schreiben $H(s)$ in Produktform: $$H(s) = \frac{a_{m}}{b_{n}}\frac{(s-s_{0,1})(s-s_{0,2})\ldots(s-s_{0,m})}{(s-s_{\infty,1})(s-s_{\infty,2})\ldots(s-s_{\infty,n})}$$

Es gilt:
- $s_{0,j}$ sind die Nullstellen des Zählers und damit Nullstellen von $H(s)$. Signale mit dieser Frequenz werden also *ausgelöscht*.
- $s_{\infty,i}$ sind die Nullstellen des Nenners und damit Polstellen von $H(s)$. Signale mit dieser Frequenz werden *unendlich verstärkt*.

> **$H(s)$ beschreibt ein stabiles System, wenn die Realteile *aller* Polstellen negativ sind.**

Heißt: $\mathfrak{Re}(s_{\infty,i})<0 \;\forall j \in [0,n] \Rightarrow$ System ist stabil.

Schließlich:
- Wir zerlegen $H(s)$ via [[Partialbruchzerlegung.excalidraw|Partialbruchzerlegung]] in eine Summe von Partialbrüchen
	- Einen Partialbruch $\frac{A}{s-s_{\infty,i}}$ pro Polstelle
- Die Partialbrüche können wir jeweils leicht rücktransformieren
	- $\frac{A}{s+a}\stackrel{\text{LT}}{\longrightarrow} A \cdot s(t)e^{-at}$
- Wegen der Linearität ist die Rücktransformation $h(t)$ die *Summe* aus den rücktransformierten Partialbrüchen
	- $\sum_{i=1}^{n} \frac{A_{i}}{s-s_{\infty,j}}\stackrel{\text{LT}}{\longrightarrow}\sum_{i=1}^{n}A_{i}s(t)e^{s_{\infty,i}t}$
- $h(t)$ ergibt sich als die **[[Robotik - VL 11#Impulsantwort|Impulsantwort]]** des Systems.

> Wenn eine Polstelle im Realteil Null ist, ist die Systemantwort für einen bestimmten Impuls konstant $\to$ System merkt sich den Impuls beliebig lange.
> 
> Ist er größer als Null, reicht ein einzelner Impuls für exponentielle Anstieg der Systemantwort.

### Analyse von Feedbacksystem mit rationaler Laplace-Transformation

Man hat ein System mit bereits laplacetransformierten Eingabe-, Ausgabe- und Systemfunktionen:

![[Feedbacksystem.png|400]]

Wir schreiben den Output als: $$Y(s) = H_{1}(s)U(s)+H_{1}(s)H_{2}(s)Y(s)$$
(siehe [[Robotik - VL 11#^463ea0|Konvolution]] und [[Robotik - VL 11#Konvolutionstheorem|Konvolutionstheorem]]).

Umgeformt: $$H(s) = \frac{Y(s)}{U(s)}=\frac{H_{1}(s)}{1-H_{1}(s)H_{2}(s)}$$
Nun kann man $H_1$ und $H_2$ einsetzen, in die Produktform bringen und mittels der Polstellen auf Stabilität prüfen.

# Zeitdiskrete Systeme
## Diskrete Fourier-Transformation

Wir möchten die Fourier- und Laplacetransformation ins Zeitdiskrete bringen, da z.B. Computer getaktet arbeiten und nichts mit kontinuierlichen Systemen anfangen können.

- Zeitdiskreter Sinus(oid) kann ganz viele zugrundeliegende Frequenzen haben

Für eine Frequenz $\Omega=\omega T$ (Winkel pro Zeiteinheit) ist die diskrete Fouriertransformation (DFT) einer zeitdiskreten Funkton $f$: $$F\left(e^{j \Omega}\right)=\sum_{n=-\infty}^{\infty}f[n]e^{-jn\Omega}$$
und die Rückwärtstransformation (iDFT): $$f[n] = \frac{1}{2\pi}\int_{-\pi}^{\pi}F\left(e^{j \Omega n}\right)e^{j \Omega n} \,d \Omega$$
Die DFT konvergiert genau dann, wenn $\sum_{-\infty}^{\infty}|f[n]|<\infty$.

## Z-Transformation

Die z-Transformation ist ähnlich zur Laplace-Transformation, nur eben für zeitdiskrete Systeme.

Idee: wir berechnen die DFT der Eingabe $f[n]$ multipliziert mit der geometrischen Reihe $r^{-n}$.

$$\begin{align*}
f[n]r^{-n} \quad\stackrel{\text{DFT}}{\longrightarrow}\quad &\sum_{n=-\infty}^{\infty}f[n]r^{-n}e^{-jn \Omega}\\
= &\sum_{n=-\infty}^{\infty}f[n]\left(r\,e^{j \Omega}\right)^{-n}
\end{align*}$$

Nun schreiben wir $z \in \mathbb{C}$ für $r \,e^{j\Omega}$ und erhalten: $$F(z)=\sum_{n=-\infty}^{\infty}f[n]z^{-n}.$$
Die Rücktransformation benutzt irgendwelche komischen mathematischen Symbole die ich nicht kenne.

Man kann aber dasselbe Gedöns machen wie bei der rationalen Laplace-Transformation: mit Impulsantwort $h[n] \stackrel{\text{ZT}}{\longrightarrow} H(z)=\frac{Y(z)}{U(z)}$ kann man wieder über die Produktdarstellung die Polstellen finden. 

> **Das zeitdiskrete System ist genau dann stabil, wenn alle Polstellen im Einheitskreis liegen**, also $|z_{\infty,i}|<1$.



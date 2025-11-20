[[3_Chapter_FASP_Signals_Handout.pdf]]

Wir haben CT- (continuous time) und DT- (discrete time) Signale.

Gerade (even) Signale: $f(-x) = f(x)$ (z.B. Cosinus)
Ungerade (odd) Signale: $f(-x)=-f(x)$ (z.B. Sinus)

> **Theorem**
> Jede Funktion $f(x)$ kann man als Summe einer geraden und einer ungeraden Funktion darstellen: $$\begin{align}
f^{+}(x)&= \frac{1}{2}(f(x)+f(-x)) \\
f^{-}(x) &= \frac{1}{2}(f(x)-f(-x))
\end{align}$$

(Normalisierte) Sinc-Funktion: $$\text{sinc}(t):= \begin{cases}
\frac{\sin(\pi t)}{\pi t}  & \text{falls }t \neq 0 \\
1 & \text{falls } t=0.
\end{cases}$$

Chirp Signal: Sinal mit linear (mit $k$) steigender Frequenz: $$t \mapsto \sin\left( 2\pi\left( f_{0}+\frac{k}{2}t \right)t \right)$$

Heaviside-Funktion: Step-Funktion (1 für $t\geq 0$)


[[3_Chapter_FASP_Signals_Handout.pdf]]

Wir haben CT- (continuous time) und DT- (discrete time) Signale.

Gerade (even) Signale: $f(-x) = f(x)$ (z.B. Cosinus)
Ungerade (odd) Signale: $f(-x)=-f(x)$ (z.B. Sinus)

> **Theorem**
> Jede Funktion $f(x)$ kann man als Summe einer geraden und einer ungeraden Funktion darstellen: $$\begin{align}
f^{+}(x)&= \frac{1}{2}(f(x)+f(-x)) \\
f^{-}(x) &= \frac{1}{2}(f(x)-f(-x))
\end{align}$$

Sinc-Funktion: $$\text{sinc}(t):= \begin{cases}
\frac{\sin(\pi t)}{\pi t}  & \text{falls }t \neq 0 \\
1 & \text{falls } t=0.
\end{cases}$$

Chirp Signal
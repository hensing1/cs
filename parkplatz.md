$$
\begin{align}
e^{2 \pi i (N-k) \frac{n}{N}} &= e^{2 \pi i n \frac{(N-k)}{N}} \\
&= e^{2\pi i n \left( 1 - \frac{k}{N} \right)} \\
&= e^{ 2\pi i n - 2\pi i n\frac{k}{N} } \\
&= e^{ 2\pi i n} \cdot e^{- 2\pi i n\frac{k}{N} } \\
&= 1 \cdot e^{- 2\pi i n\frac{k}{N} } & \text{(n is integer)} \\
&= e^{- 2\pi i k\frac{n}{N} } \\
\end{align}
$$


$$\begin{align}
\Delta f(x) &= \frac{ \partial ^{2} }{ \partial x^{2} } f(x) \\
&\approx \frac{ \partial }{ \partial x } (f(x+1)-f(x-1)) \\ 
&= \frac{ \partial  }{ \partial x } f(x+1)-\frac{ \partial  }{ \partial x } f(x-1) \\
&\approx [f(x+1)- f(x)] - [f(x) - f(x-1)] \\
&= f(x+1)-2f(x)+f(x).
\end{align}$$
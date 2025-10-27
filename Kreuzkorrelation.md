# Kreuzkorrelation

Die Kreuzkorrelation ist die kleine Schwester der [[Konvolution]].

> [!abstract] Definition *Kreuzkorrelation*
> Die Kreuzkorrelation einer Funktion $x(t)$ mit einer Funktion $y(t)$ ist definiert als: $$\begin{align*}(x \star y)(t) &= \int_{\mathbb{R}^{n}} x(\tau)y(t+\tau)\,d \tau\\
&= \int_{\mathbb{R}^{n}}x(t-\tau)y(\tau)\,d \tau\\
&= (x(-t)\ast y(t))(t)\end{align*}$$

Die Kreuzkorrelation gibt ein (nicht normiertes) Maß für die Ähnlichkeit zweier Funktionen an einem Zeitpunkt $t$.

![[Faltung_vs_Korrelation.png|400]]

## Eigenschaften

Die Kreuzkorrelation ist distributiv: $x \star (y+z) = x \star y + x \star z$.
Anders als die Konvolution ist sie im Allgemeinen *nicht* kommutativ und *nicht* assoziativ.

## Ähnlichkeitsmaß

Ein Spezialfall der Kreuzkorrelation ist der *Korrelationskoeffizient*, welcher die Kreuzkorrelation bei $t=0$ angibt und normiert ist(?).
Er gibt jedenfalls auch ein Maß für den linearen Zusammenhang zwischen zwei Verteilungen $f$ und $g$: $$cc_{f,g}=\frac{\text{Cov}(f,g)}{\sigma_{f}^{2}\sigma_{g}^{2}}$$
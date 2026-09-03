[[5.PM2L4Audio_handout.pdf]]

- Verschiedene Versionen desselben Songs wiedererkennen

Ansatz: Herausfinden, welche Noten (wohltemperiert, 440Hz) gespielt werden.
> **MIDI-Pitch:** $p \in [0, 127]$
> $$F_{\text{pitch}}(p)=2 ^{\frac{p-69}{12}} \cdot 440\ \text{Hz}$$

$p=69$ ist also das A bei 440Hz.
Die 88 Noten auf dem Piano gehen von $p=21$ bis $p=108$.

$p\ \text{mod}\ 12$ gibt die Note mit C=0.

## Log Frequency Spectrogram

Recap STFT:
- Fenster $w \in \mathbb{R}^{N}$
- Hop size $H \in [1, N]$
- Die Frequenz $k$ im $n$-ten STFT-Fenster ist also $$\mathcal{X}(n,k)=\sum_{\ell=0}^{N-1}x(nH+\ell) \cdot w(\ell) \cdot \exp\left( -2\pi ik\frac{\ell}{N} \right).$$
Bei einer Sampling-Rate $F_{s}$ ist der Zeitpunkt der Messung $T_{\text{coef}}(n)=\frac{nH}{F_{s}}$.
Die Frequenz in Hz ist $F_{\text{coef}}=\frac{kF_{s}}{N}$.

Für jede Note $p$ sind die zugehörigen $k$'s: $$P(p) := \{ k \mid F_{\text{pitch}}(p-0.5)\leq F_{\text{coef}}(k)<F_{\text{pitch}}(p+0.5) \}.$$
Für das Log-Frequenz-Spektrogramm rechnen wir dann die Power Spektren der einzelnen $k$'s zusammen: $$\mathcal{X}_{\text{LF}}(n, p):= \sum_{k \in P(p)}|\mathcal{X}(n,k)|^{2}.$$
## Chromagramm

Die Note $p\ \text{mod}\ 12$, die ein Midi-Ton $p$ hat, nennen wir *Chroma*. 
Ein **Chromagramm** rechnet alle Werte des Spektrogramms mit derselben Chroma zusammen: $$\mathcal{C}(n, c) := \sum_{p \in [0, 127]:\ p \ \text{mod}\ 12=c}\mathcal{X}_{\text{LF}}(n, p).$$
Um leisere Töne besser zu erkennen, können wir eine Art Gammakorrektur mit dem Chromagramm machen: $$(\Gamma \circ \mathcal{C})(n, c):=\log(1 + \gamma \cdot \mathcal{C}(n, c))$$
Chromagramme sind einigermaßen immun gegen verschiedene Klangfarben.


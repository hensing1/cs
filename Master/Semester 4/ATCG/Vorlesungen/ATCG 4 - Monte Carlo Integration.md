Wir möchten die Renderinggleichung lösen. Sie ist aber rekursiv, und allein für spiegelnde Oberflächen ist sie $2l$-dimensional für Rekursionstiefe $l$.
Wir müssen das Integral also *schätzen*.

Ein gewöhnliches 1D-Integral können wir schätzen, indem wir Samples $z_{i}$ (in der Integrationsdomäne) generieren: $$I \approx \hat{I}=\sum_{i=1}^{n}w(z_{i})f(z_{i}),$$
wobei $f$ die zu integrierende Funktion und $w$ eine Gewichtungsfunktion.
Beispiele: Mittelpunktregel, Trapezregel

Der Approximierungsfehler für 1D schrumpft mit der Geschwindigkeit $\mathcal{O}(n^{-k})$. Für de Trapezregel ist $k=2$.
Problem: ist die Domäne $d$-dimensional, geht der Exponent für steigende $d$ gegen Null: $\hat{I}-I \in \mathcal{O}(n^{-k/d})$. Das ist die **curse of dimensionality**.

Um den Approximierungsfehler um den Faktor $\delta<1$ zu verringern, brauchen wir $\left( \frac{1}{\delta} \right)^{d/k}$ mehr Samples.
Für eine doppelt so gute Approximierung braucht man also $2^{2l/k}$-mal so viele Samples. Eine einfache Quadratur geht also nicht mehr.

## Samples generieren

> [!abstract] Definition *Monte Carlo Estimator*
> Der Monte-Carlo Estimator löst das Integral $F=\int_{D}f(x)\,d\mu(x)$ mit $$\langle F \rangle_{N}=\frac{1}{n}\sum_{i=1}^{n} \frac{f(x_{i})}{q(x_{i})}$$
> wobei $q(x)$ eine Wahrscheinlichkeitsdichtefunktion über $D$ ist, nach der auch die Samples $x_{i}$ gezogen werden.

In 1D: 
zu sampelnde Funktion -> CDF -> Inverse CDF uniform samplen -> gesampelte y-Werte als x-Werte für ursprüngliche Funktion verwenden

Funktioniert leider nur in 1D, weil wir mehrdimensionale Funktionen nicht invertieren können
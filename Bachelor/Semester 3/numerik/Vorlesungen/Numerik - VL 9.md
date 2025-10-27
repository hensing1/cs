Datum: 08.12.

Folien bis 225


# Eigenwertprobleme
*Kapitel 7 ff.*

## Iterationsverfahren

Eigenwertprobleme sind im Allgemeinen nicht algorithmisch lösbar, da das charakteristische Polynom, dessen Nullstellen man berechnen müsste, beliebig hohen Grad haben kann.

Uns interessieren also Algorithmen, die iterativ die Eigenwerte (und -vektoren) bestimmen, und irgendwann konvergieren.

### Rayleigh-Quotient

Sei $A$ eine symmetrische, reellwertige Matrix.

Sei $x$ nun irgendein Vektor ungleich 0. Wir suchen nun ein $\alpha \in \mathbb{R}$, welches bezüglich $x$ am ehesten wie ein Eigenwert aussieht, d.h. $\|Ax-\alpha x\|_2$ soll minimiert werden.

Das löst man mit der [[Numerik - VL 2#^2db2dd|Gaußschen Normalengleichung]]. In diesem Falls ist $x$ die "Matrix" (damals $A$), $\alpha$ der gesuchte "Vektor" (damals $y$ bzw. $x$), und $Ax$ ist die rechte Seite (damals $b$).

Also: $$\begin{align*}
x \text{ löst }\|Ax-x\alpha\|_{2}\to \text{min} &\iff x ^{\ast} x \alpha = x ^{\ast}Ax\\
&\iff \alpha = \frac{x ^{\ast}Ax}{x ^{\ast}x}
\end{align*}.$$

> [!abstract] Definition *Rayleigh-Quotient*
> Sei $A \in \mathbb{R}^{n \times n}$ symmetrisch und $x \in \mathbb{R}^{n}$. Dann ist $$r(x) := \frac{x^{T}Ax}{x^{T}x}$$ der *Rayleigh-Quotient* von $x$.

Ist $x$ ein Eigenvektor zum Eigenwert $\lambda$, dann ist $r(x)=\frac{x^{T}Ax}{x^{T}x}=\frac{x^{T}\lambda x}{x^{T}x}=\lambda$.

Betrachten wir $x$ als Variable, können wir den Gradienten $\nabla r(x)$ bilden. 

> Ist $x\neq 0$ und $\nabla r(x)=0$, dann ist $x$ ein Eigenvektor.

Konkret ist $\nabla r(x)= \frac{2}{x^{T}x}(Ax-r(x)x)$.

Insbesondere ist der Rayleigh-Quotient eine **quadratisch genaue Approximation** eines Eigenwerts, d.h. für einen Eigenvektor $q_{j}$ ist $$r(x)-r(q_{j}) \in \mathcal{O}(\|q_{j}-x\|^{2}).$$

### Potenziteration

Sei $x \in \mathbb{R}^{n}$ wieder irgendein Vektor.

Wir approximieren den normierten *Eigenvektor* $q_{1}$ zum *größten Eigenwert* $\lambda_{1}$ mit der Folge: $$(v^{(n)})=\frac{A^{n}x}{\|A^{n}x\|}=\frac{x}{\|x\|},\frac{Ax}{\|Ax\|},\frac{A^{2}x}{\|A^{2}x\|},\ldots\,.$$
Als Algorithmus:
> **Potenziteration**
> $v^{(0)}$ sei Vektor, $\|v^{(0)}\|=1$
> `for` $k = 1, 2, \ldots$:
> > $w = Av^{(k-1)}$
> > $v^{(k)}=\frac{w}{\|w\|}$
> > $\lambda^{(k)}=(v^{(k)})^{\ast}Av^{(k)}$

$\lambda^{(k)}$ ist der Rayleigh-Quotient von $v^{(k)}$.

Diese Folge konvergiert, wenn $\lambda_1>\lambda_2$: es ist $\lim\limits_{k \to \infty}v^{(k)}=q_1$ und $\lim\limits_{k \to \infty} \lambda^{(k)}=\lambda_1$.

Warum?
- Der Betrag jedes Folgeglieds ist 1
- Bei jeder zusätzlichen Multiplikation mit $A$ wird der Vektor $v$ am meisten in Richtung des größten Eigenwerts gestreckt
- Normiert man ihn dann zurück, zeigt er im Vergleich zu vorher ein bisschen weiter in Richtung des Eigenvektors

Konkret ist $|\lambda^{(k)}-\lambda_{1}|\in \mathcal{O}\left(\left|\frac{\lambda_2}{\lambda_1}\right|^{2k}\right)$.

### Inverse Iteration

Wir können also mit der Potenziteration den größten Eigenwert bestimmen. Nun möchten wir die restlichen Eigenwerte auch bestimmen.

> *Theorem*
> Sei $\mu \in \mathbb{R}$, wobei $\mu$ kein Eigenwert von $A$ ist. 
> Dann besitzt $(A-\mu I)^{-1}$ dieselben Eigenvektoren wie $A$.

Weil: $$\begin{align*}Av=\lambda v&\iff (A-\mu I)v=(\lambda-\mu)v\\&\iff (A-\mu I)^{-1}v=(\lambda-\mu)^{-1}v\end{align*}$$

Wenn das $\mu$ nun schon nah an einem Eigenwert $\lambda_{j}$ liegt, dann ist $(\lambda_{j}-\mu)<(\lambda_{i}-\mu)$ bzw. $(\lambda_{j} - \mu)^{-1}>(\lambda_{i}-\mu)^{-1}\, \forall i \neq j$, d.h. Anwendung der Potenzmethode auf $(A - \mu I)^{-1}$ konvergiert gegen den Eigenvektor $q_{j}$.

### Rayleigh-Quotient-Iteration

Jetzt können wir:
1. eine Eigenwert-Schätzung aus einer Eigenvektor-Schätzung berechnen (Rayleigh-Quotient), und
2. eine Eigenvektor-Schätzung aus einer Eigenwert-Schätzung berechnen (Inverse Iteration).

Mit dem folgenden Algorithmus kombiniert man das Ganze:
> **Rayleigh-Quotient-Iteration**
> $v^{(0)}$ sei Vektor, $\|v^{(0)}\|=1$
> $\lambda^{(0)}=(v^{(0)})^{\ast}Av^{(0)}$ ist Rayleigh-Quotient von $v^{(0)}$
> `for` $k=1,2,\ldots$ :
> > $w = \text{Lösung für } ((A-\lambda^{(k-1)}I)w=v^{(k-1)})$
> > $v^{(k)}=\frac{w}{\|w\|}$
> > $\lambda^{(k)}=(v^{(k)})^{\ast}Av^{(k)}$.




Konvergenz davon ist kubisch

aber langsam ($\mathcal{O}(n^{3})$) $\to$ Beschleunigung mit QR-Verfahren



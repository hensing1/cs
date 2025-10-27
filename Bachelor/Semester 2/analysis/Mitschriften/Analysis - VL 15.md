Datum: 07.06.
[Annotiertes Skript](https://ecampus.uni-bonn.de/goto_ecampus_file_3058966_download.html)
[Notizen aus der Vorlesung](https://ecampus.uni-bonn.de/goto_ecampus_file_3058965_download.html)

*Kapitel 4*
# Differenzialrechnung
## Mehr zu Taylorpolynomen

*Taylorpolynom*
$$T_{f,n}(x)=\sum\limits_{k=0}^{n}\frac{f^{(k)}(x_{0})}{k!}(x-x_{0})^{k}$$
$T_{f}(x):=T_{f,\infty}(x)$ heißt *Taylorreihe*. Manchmal konvergiert die Taylorreihe gegen die ursprüngliche Funktion.

Zur Erinnerung:
> Wenn ich eine Funktion, die durch eine Potenzreihe gegeben ist, nur durch eine Nullfolge kenne, dann kenne ich sie überall. (Identitätssatz von Potenzreihen)

Hat man also eine Funktion, deren $n$-te Ableitung am Entwicklungspunkt für alle $n$ gleich 0 ist (sowas gibt es), dann ist die Taylorreihe die Nullfunktion. Aber es gibt auch Funktionen, die diese Eigenschaft haben und nicht die Nullfunktion sind.

> Sei $f: I \to \mathbb{R}$ beliebig oft differenzierbar und $x_{0}\in I$. Gibt es ein $\delta > 0$, sodass das Restgleid aus dem Satz von Taylor (der Term mit dem $\xi$) für alle $x\in \set{x\in \mathbb{R}\mid |x-x_{0}|< \delta}\subseteq I$ gegen 0 konvergiert, dann lässt sich $f$ in einer Umgebung von $x_{0}$ in eine Potenzreihe entwickeln und es gilt dort $f(x)=T_{f}(x)$.

Will man obigen Satz anwenden, muss man sich ansehen, wie das Bildungsgesetz für die $n$-te Ableitung aussieht:

$$\begin{align*}
f(x)&=\ln x\\
f'(x)&=\frac{1}{x}\\
f''(x)&=- \frac{1}{x^{2}}\\
f'''(x)&=2 \cdot \frac{1}{x^{3}}\\
f''''(x)&=-2 \cdot 3 \cdot \frac{1}{x^{4}}\\
\Rightarrow f^{(n)}(x)&=(-1)^{n+1}\cdot(n-1)!\cdot x^{-n}
\end{align*}$$

Einsetzen in die Taylorreihe mit Entwicklungspunkt 1:

$T_{f}=\sum\limits_{n=0}^{\infty}\frac{f^{(n)}(1)}{n!}(x-1)^{n}=\sum\limits_{n=0}^{\infty}\frac{(-1)^{n+1}(n-1)!}{n!}(x-1)^{n}=\sum\limits_{n=0}^{\infty} \frac{(-1)^{n+1}}{n}(x-1)^{n}.$

Für ein Taylorpolynom $T_{f,n}$ sieht das Restglied folgendermaßen aus:
$r_{n}(x,1)= \frac{f^{(n+1)}(\xi)}{(n+1)!}(x-1)^{n+1}=(-1)^{n+2} \frac{(x-1)^{n+1}}{(n+1)\xi^{n+1}}$. Man sieht, dass für alle $x$ mit $|x-1|<|\xi|$ dieses Restglied gegen 0 konvergiert, und für all diese $x$ also $f(x)=T_{n}(x)$ gilt.

## Extremstellen

> Eine Funktion $f$ hat in einem Punkt $x$ ein *lokales Minimum*, wenn es ein $\epsilon>0$ gibt, sodass für alle $x_{0}\in \left]x_{0}-\epsilon,x_{0}+\epsilon\right[$ gilt: $$f(x_{0})\geq f(x).$$ Tritt die Gleichheit nur für $x_{0}=x$ ein, dann hat man ein *isoliertes, lokales Minimum*.

Für lokale Maxima gilt das ganze analog.

> Gilt $f'(x_{0})=f^{(2)}(x_{0})=\ldots=f^{(n)}(x_{0})=0$ und $f^{(n+1)}\neq 0$, dann ist $x_{0}$:
> - ein *Sattelpunkt*, falls $n$ gerade
> - ein *lokales Minimum*, falls $n$ ungerade und $f^{(n+1)}(x_{0})>0$
> - ein *lokales Maximum*, falls $n$ ungerade und $f^{(n+1)}(x_{0})<0$.

Man kann sich das ganze anhand der Polynome $x^{2}$, $x^{3}$, $-x^{4}$ usw. verdeutlichen.

## Mittelwertsatz

Eine Sekankte ist die Gerade zwischen zwei Punkten $(a,f(a))$ und $(b,f(b))$

Der Mittelwertsatz sagt: irgendwo zwischen $a$ und $b$ ist die Ableitung gleich der Sekantensteigung. Formell: $$\exists \xi \in \left]a,b\right[: f'(\xi)=\frac{f(b)-f(a)}{b-a}.$$

Wenn ich die Sekante also parallel verschiebe, wird sie irgendwann zur Tangente. 
![[Mittelwertsatz.png|350]]


> **Verallgemeinerter Mittelwertsatz**
> Seien $a<b$ und $f,g: \left[a,b\right]\to \mathbb{R}$ stetig und auf $\left]a,b\right[$ differenzierbar, sowie $g'(x)\neq 0$ für alle $x \in \left]a,b\right[$. Dann gibt es ein $\xi \in \left]a,b\right[$, sodass $$\frac{f'(\xi)}{g'(\xi)}=\frac{f(b)-f(a)}{g(b)-g(a)}.$$

Für $g(x)=x$ folgt der normale Mittelwertsatz.
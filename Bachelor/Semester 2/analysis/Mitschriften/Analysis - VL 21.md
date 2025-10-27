Datum: 28.06.
[Annotiertes Skript](https://ecampus.uni-bonn.de/goto_ecampus_file_3090895_download.html)
[Notizen aus der Vorlesung](https://ecampus.uni-bonn.de/goto_ecampus_file_3090894_download.html)

# Regelfunktionen

> [!abstract] Definition *Regelfunktion*
> Eine Funktion $f: [a,b]\to \mathbb{R}$ heißt **Regelfunktion**, wenn es eine *Folge von Treppenfunktionen* $(\varphi_{n})$ in $T([a,b])$ gibt, die < gleichmäßig gegen $f$ konvergiert>.

> [!info] Intermezzo: *Gleichmäßige Stetigkeit*
> 
> > **Gleichmäßige Stetigkeit**
> > Eine Funktion $f: D \to \mathbb{C}$ heißt *gleichmäßig stetig*, wenn für jedes $\epsilon>0$ ein $\delta>0$ existiert, sodass für alle $x,y \in D$ gilt:
> > $$\text{Wenn } |y-x|<\delta \text{, dann }|f(y)-f(x)|<\epsilon.$$
> 
> Unterschied zur Stetigkeit ist der Quantorenwechsel:
> - Stetigkeit:
> 	- $\forall \epsilon>0 \space \forall x \space \exists \delta>0: \ldots$
> - Gleichmäßige Stetigkeit:
> 	- $\forall \epsilon>0 \space \exists \delta>0 \space \forall x: \ldots$
> 
> *Beispiele* ([[ANA_Skript_Main.pdf|Räsch-Skript]] Seite 58):
> - Eine Gerade ist gleichmäßig stetig
> - Parabeln (auf ganz $\mathbb{R}$) sind nicht gleichmäßig stetig, da es kein globales $\delta$ für alle $x$ geben kann (Steigung wächst immer weiter)
> - Wurzelfunktion ist gleichmäßig stetig
> - $\frac{1}{x}$ ist nicht gleichmäßig stetig
> 
> > Jede auf einem abgeschlossenen Intervall stetige Funktion ist auch gleichmäßig stetig.

Zurück zu Regelfunktionen:
> Jede stetige Funktion $f: [a,b] \to \mathbb{R}$ ist eine Regelfunktion.

Außerdem:
> Jede *stückweise* stetige Funktion (also jede Funktion, die für eine Zerteilung $Z=(t_{0},t_{1},\ldots$) in jedem Intervall $]t_{i},t_{i+1}[$ stetig *und* in jedem $t_{i}$ (von beiden Seiten) stetig fortsetzbar ist), ist eine Regelfunktion.

# Bestimmte Integrale

> [!abstract] Definition *Bestimmtes Integral*
> Ein **bestimmtes Integral** einer Regelfunktion $f: [a,b] \to \mathbb{R}$ ist definiert als $$\int_{a}^{b}f(x)\, dx:= \lim\limits_{n \to \infty}\int_{a}^{b}\varphi_{n}(x)\,dx,$$wobei $(\varphi_n)$ eine Folge von Treppenfunktionen ist, welche gleichmäßig gegen $f$ konvergiert.
> 
> Es ist $$\int_{a}^{a}f(x)\, dx:=0$$und $$\int_{b}^{a}f(x)\,dx=-\int_{a}^{b}f(x)\,dx.$$

Der oben definierte Integralbegriff heißt *Regelintegral*. Etwas allgemeiner ist das *Riemann-Integral*, dies macht in der Praxis aber zumeist keinen Unterschied.
Eine signifikant größere Klasse an integrierbaren Funktionen erhält man mittels des *Lebesgue-Integrals*. Damit kann man sowas integrieren wie $f(x)=\left\{\begin{align*}1& \text{ falls }x \in \mathbb{Q} \\ 0& \text{ falls } x \in \mathbb{R}\setminus \mathbb{Q}\end{align*}\right.$ .

Jede Funktionsfolge, welche gegen die gleiche Regelfunktion konvergiert, hat denselben Grenzwert für das bestimmte Integral.

> Bestimmte Integrale sind < linear>, genau wie unbestimmte Integrale.
> Ist $f\leq g$, dann ist auch $\int_{a}^{b}f(x)\,dx \leq \int_{a}^{b}g(x)\, dx$.

Wenn man das Integral einer Funktion approximieren möchte, kann man sich eine Zerlegung suchen und dann innerhalb dieser Zerlegungsbereiche einen Punkt der Funktion aussuchen, welcher die obere Grenze des Flächeninhalts bestimmt. Formalisiert ist das eine Riemannsche Summe:
> **Riemannsche Summe**
> Sei $f: [a,b]\to \mathbb{R}$ eine Funktion und $Z$ eine Zerlegung von $[a,b]$.
> Dann sei $\underline{\xi}=\set{\xi_{1},\ldots,\xi_{n}}$ eine Folge von *Stützstellen*, wobei $\xi_{i}\in [t_{i},t_{i+1}]$. Dann ist die Riemannsche Summe von $f$ bzgl. $Z$: $$R_{f}(Z,\underline{\xi}):=\sum\limits_{i=1}^{n}f(\xi_{i})(t_{i}-t_{i-1}).$$
> Hat man eine Stützstellenfolge, dann heißt die Folge der zugehörigen Riemannschen Summen die *Riemann-Folge* von $f$. Der Grenzwert der Riemann-Folge ist das Integral von $f$ von $a$ nach $b$.


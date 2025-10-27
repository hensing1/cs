Datum: 21.06.
[Annotiertes Skript](https://ecampus.uni-bonn.de/goto_ecampus_file_3069965_download.html)
[Notizen aus der Vorlesung](https://ecampus.uni-bonn.de/goto_ecampus_file_3069966_download.html)

Er hat keine Basis-Superkräfte

# Stampfunktionen
Wir gucken uns die Beispiele im Skript an.

- $\int \frac{g'(x)}{g(x)}\,dx=\ln(|g(x)|)$
- $\int \tan(x)\,dx=-\int \frac{-\sin(x)}{\cos(x)}\,dx=-\int \frac{(\cos(x))'}{\cos(x)}\,dx=-\ln(|\cos(x)|)$

## Bestimmung der Stammfunktion einer gebrochenrationalen Funktion

![[Partialbruchzerlegung.excalidraw|650]]
#bruh 
Beispiel gibts im Skript, das geht drei Seiten und das schreib ich jetzt ganz bestimmt nicht hier hin.

# Differentialgleichungen erster Ordnung

> [!abstract] Definition *Differentialgleichung erster Ordnung*
> Es sei $D \subseteq \mathbb{R}^{2}$ offen und $f: D \to \mathbb{R}$ stetig.
> 
> Eine Gleichung der Form $$y'(x)=f(x,y(x))$$ heißt **gewöhnliche Differentialgleichung** (Dgl.) **erster Ordnung**.
> Eine Lösung ist eine differenzierbare Funktion $\varphi: I \to D$, die für alle $x\in I$ die gegebene Differentialgleichung erfüllt.

*Gewöhnlich* deshalb, weil nur eine Unbekannte ($x$) drin vorkommt. *Erster Ordnung* deshalb, weil nur die erste Ableitung darin vorkommt.

Am einfachsten sind Dgl. mit $f(x,y(x))=h(x)\cdot g(y(x))$. Diese Dgl. heißen *trennbar*.
Man schreibt gerne auch $y'$ und $y$ statt $y'(x)$ und $y(x)$.
Hat man also sowas wie $y'=x \cdot y^{2}$, kann man das lösen indem man alles mit $x$ auf eine und alles mit $y$ auf die andere Seite schickt, und dann von beiden Seiten die Stammfunktion bildet:
$$\begin{align*}
y'=x \cdot y^{2}\\
\frac{y'}{y^{2}}=x\\
\text{?}
\end{align*}$$
Für sowas gibt es in aller Regel unendlich viele Lösungen, da es unendlich viele Stammfunktionen gibt und man daher eine Lösung mit einer frei wählbaren additiven Konstante rausbekommt. 

> **Anfangswertproblem**
> Eine Differentialgleichung $y'=f(x,y(x))$ mit der zusätzlichen Bedingung $$y(x_{0})=y_{0}$$ heißt *Anfangswertproblem*.

Die Anfangswertbedingung kommt zum Tragen, wenn die o.g. additive Konstante explizit bestimmt werden soll.
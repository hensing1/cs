Datum: 29.11.
[[14VL-Scan-Regulaere-Sprachen-Ausdruecke.pdf|Folien]]

# Reguläre Ausdrücke $\iff$ DFAs
Wir möchten heute die Äquivalenz zwischen [[Reguläre Ausdrücke|regulären Ausdrücken]] und [[Endliche Automaten#Endliche Deterministische Automaten|DFAs]] bzw. [[Endliche Automaten#Endliche Nichtdeterministische Automaten|NFAs]] beweisen.

## Regulärer Ausdruck $\Rightarrow$ NFA
Herangehensweise: [[Beweistechniken#Strukturelle Induktion|Strukturelle Induktion]] über der Aufbau von regulären Ausdrücken.

### Induktionsanfang
Zeige für die "Grundbausteine" von regulären Ausdrücken, dass ein entsprechender NFA existiert.

Grundbausteine:
- $\emptyset$ - Regulärer Ausdruck für die leere Sprache
- $\epsilon$ - Regulärer Ausdruck für die Sprache, die das leere Wort enthält
- $a$ - Regulärer Ausdruck für die Sprache, die den Buchstaben $a$ enthält

Entsprechende NFAs:
![[NFAs_fuer_Regex.png|450]]

### Induktionsannahme
Für reguläre Ausdrücke $R_{1},R_{2}$ existieren NFAs $M_{1}$ und $M_{2}$, die $L(R_{1})$ und $L(R_{2})$ entscheiden.

### Induktionsschritt
Zeige, dass unter der Induktionsannahme die Behauptung auch gilt für $R=(R_{1})+(R_{2})$, $R=(R_{1})\cdot (R_{2})$ und $R=(R_{1})^{*}$.

#### Vereinigung
$R=R_{1}+R_{2}$

Man nimmt die beiden NFAs $M_{1}$ und $M_{2}$ für $L(R_{1})$ und $L(R_{2})$ und schnappt sich einen neuen Startzustand $q_{0}$. Mit $q_{0}$ verbindet man nun alle Folgezustände von $q_{0}^{1}$ und $q_{0}^{2}$. Falls $q_{0}^{1}$ oder $q_{0}^{2}$ akzeptierende Zustände waren, wird $q_{0}$ auch akzeptierende Zustand.
Das Ergebnis ist ein NFA, der $L(R_{1})\cup L(R_{2})$ entscheidet.

#### Konkatenation
$R=R_{1}\cdot R_{2}$

Man hängt die Folgezustände von $q_{0}^{2}$ jeweils an die akzeptierenden Zustände von $M_{1}$. Falls $L(R_{2})$ nicht das leere Wort enthält, werden die akzeptierenden Zustände von $M_1$	zu nicht-akzeptierenden Zuständen.
Das Ergebnis ist ein NFA, der $L(R_{1}\cdot R_{2})$ entscheidet.

#### Kleen'scher Abschluss
$R=(R_{1})^{*}$

Man schaltet seinen Automaten für $L(R_{1})$ hinter sich selbst (alle akzeptierenden Zustände kriegen wieder dieselben Verbindungen wie der Startzustand). Der Startzustand wird dabei auf jeden Fall akzeptierend.
Das Ergebnis ist ein NFA, der die Sprache $L((R_{1})^{*})$ entscheidet.

## DFA $\Rightarrow$ Regulärer Ausdruck
Herangehensweise: [[Algorithmen#Methoden zum Entwurf von Algorithmen#Dynamische Programmierung|Dynamische Programmierung]]

Gegeben sei eine reguläre Sprache $L$: dann gibt es einen Regulären Ausdruck $R$, der diese Sprache beschreibt ($L(R)=L$)
Um das zu beweisen, formt man einen DFA $M$ mit $L(M)=L$ in einen regulären Ausdruck um.

Idee: man definiert sich einen Haufen Teilsprachen $L_{i,j}^{k}$. Eine Teilsprache ist folgendermaßen definiert:
$L_{i,j}^{k}$ ist die Sprache aller Wörter, mit denen ich von Zustand $i$ in Zustand $j$ komme, und dabei nur die ersten $k$ Zustände als Zwischenzustände verwende. (Die Zustände beziehen sich jeweils auf unseren DFA $M$.)

Für jedes $L_{i,j}^{k}$ mache ich jetzt einen Ausdruck $R_{i,j}^{k}$. Am Ende will ich alle Regulären Ausdrücke, für die $i=q_0$, $j$ = akzeptierender Zustand, und $k=|Q|$. Dann muss ich nur all diese Ausdrücke konkatenieren, und ich hab meinen regulären Ausdruck, der $L$ beschreibt.

Damit kann man jetzt eine vollständige Induktion machen (über $k$):
Induktionsanfang:
Für $k=0$ ist $L_{i,j}^{k}$ einfach nur die Menge der Buchstaben (z.B. $\set{a,b,c}$), die von $i$ zu $j$ führen, und dafür gibt es natürlich einen regulären Ausdruck ($a+b+c$).

Induktionsschritt:
Aus einem Ausdruck $R_{i,j}^{k-1}$ für $L_{i,j}^{k-1}$ kann man einen Ausdruck für $L_{i,j}^{k}$ machen: entweder man kommt schon mit den ersten $k-1$ Zuständen von $i$ nach $j$, dann ist man schon fertig. Falls nicht, besucht man zwischenzeitlich den Zustand $k$ - den Weg von $i$ nach $k$ kann man aber schon mit seinem alten Ausdruck beschreiben, und den Weg von $k$ nach $j$ auch. Das heißt, man kann schreiben: $L_{i,j}^{k}=L_{i,k}^{k-1} \cdot (L_{k,k}^{k-1})^{*} \cdot L_{k,j}^{k-1}$. Das heißt, der neue reguläre Ausdruck ist $R_{i,j}^{k}=R_{i,j}^{k-1}+R_{i,j}^{k-1}(R_{k,k}^k-1)^{*}R_{k,j}^{k-1}$.

# Kapitel 4
## Abzählbare und überabzählbare Mengen

> Wenn es zwei Mengen $A$ und $B$ mit $|A|>|B|$, sowie eine Funktion $f:A\rightarrow B$, dann ist $f$ nicht injektiv ($\exists a \not = a' : f(a)=f(a')$).


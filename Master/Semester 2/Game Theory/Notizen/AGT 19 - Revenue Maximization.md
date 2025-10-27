[[lecturenotes19.pdf]]

Wir möchten den Preis maximieren, den der Gewinner zahlen muss.
Wir kennen seine Bewertung nicht, wir können sie nur schätzen (anhand einer W'keitsverteilung).

## Modellierung

Wir verkaufen ein einzelnes Item unter den Käufern.

Jeder $b$ Käufer bietet $b_{i}$.

Die Verteilung, aus der die Bewertung $v_{i}$ gezogen wird, nennen wir $\mathcal{D}_{i}$ mit Support $[0, v_{\max}]$, deren Dichtefunktion $f_{i}$ und deren kumulative Dichtefunktion $F_{i}$, dh. $F_{i}(t)=Pr[v_{i}\leq t]$.

Wir nehmen an, dass $f$ **stetig** ist.

Die Zuweisungsfunktion nennen wir diesmal $x: \mathbb{R}^{n} \to [0,1]^{n}$ - bedeutet, wir mappen die $n$ Gebote auf *Wahrscheinlichkeiten* von Zuordnungen, mit der Einschränkung $\sum_{i \in N}x_{i}(b) \leq 1$.

**Ziel:** einen *ehrlichen* Mechanismus $\mathcal{M}=(x,p)$ finden, sodass der erwartete Gewinn $E_{v}\left[ \sum_{i \in N}p_{i}(v) \right]$ maximiert wird.

## Ein Item, ein Käufer

Nach [[AGT 11 - Single-Parameter Mechanisms#^203433|Myersons Lemma]] gilt: je höher das Gebot, desto höher muss die Zuweisung sein.

Ist $\mathcal{D}_{1}$ die Gleichverteilung auf $[0,1]$, dann ist der erwartete Gewinn für einen Preis $p^{*}\in [0,1]$:
$$E_{v}[p_{1}(v)]=p^{*}\,Pr[v_{1}\geq p^{*}]=p^{*}\,(1-p^{*}).$$
Dieser Wert wird für $p^{*}=\frac{1}{2}$ maximiert.

## Virtual Value & Virtual Welfare

Nach Myersons Lemma:
- $x$ muss monoton sein
- $p$ folgt Myersons Formel - umgeschrieben: $$p_{i}(v_{i},b_{-i})=\int_{t=0}^{v_{i}}tx_{i}'(t,b_{-i})$$
mit $x(b)$ der Zuweisungsfunktion ($f$ ist ja schon die Dichtefunktion).

Zusammen mit $$\mathbf{E}_{v_{i}}[p_{i}(v_{i},b_{-i})] = \int_{v_{i}=0}^{v_{\max}}f_{i}(v_{i})p_{i}(v_{i},b_{-i})\,dv_{i}$$
und Einsetzen von $p_{i}$ integrieren wir ein bisschen rum und führen die *virtual value* $\varphi$ ein: $$\varphi_{i}(t)=t- \frac{1-F_{i}(t)}{f_{i}(t)}$$
und erhalten: $$\mathbf{E}_{v}[p_{i}(v)]=\mathbf{E}_{v}[\varphi_{i}(v_{i})x_{i}(v)].$$
In Summe über alle Bieter: $$\mathbf{E}_{v}\left[ \sum_{i \in N}p_{i}(v) \right]=\mathbf{E}_{v}\left[\sum_{i \in N}\varphi_{i}(v_{i})x_{i}(v)\right].$$
Der Ausdruck $\sum_{i \in N}\varphi_{i}(v_{i})x_{i}(v)$ heißt *virtual welfare*.


## Reguläre Verteilungen

> Eine Verteilung $\mathcal{D}_{i}$ ist **regulär**, wenn die damit verbundene Virtual-Value-Funktion $\varphi_{i}$ *streng monoton steigend* ist.

Unser Mechanismus *maximiert* nun die *virtual welfare* (und damit die erwarteten Einnahmen), indem er eine Zuweisung $x^{*}$ findet, sodass bei Gebotsprofil $b$ der Term $\sum_{i \in N}\varphi_{i}(b_{i})x_{i}^{*}(b)$ maximiert wird, und die Zahlungensfunktion $p$ anhand Myerson's Lemma festlegt.

> Dieser Mechanismus $\mathcal{M}=(x^{*},p)$ ist DSIC, wenn die Verteilungen aller Bieter regulär sind.
> Außerdem maximiert er die erwarteten Einnahmen unter allen ehrlichen Mechanismen.


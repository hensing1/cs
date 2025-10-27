# Scheduling auf identischen Maschinen

> ***Definition des Problems***
> **Gegeben:**
> - Eine Menge $J=\set{1,\ldots,n}$ von *Jobs* mit je einer Größe $p_{j}\in \mathbb{R}_{>0}$
> - Eine Menge $M=\set{1,\ldots,m}$ von *Maschinen*, auf die die Jobs verteilt werden müssen
> - Ein *Schedule* $\pi: J \to M$, der jedem Job eine Maschine zuweist
> 
> Die *Last* einer Maschine $i \in M$ in Schedule $\pi$ wird mit $L_{i}(\pi):=\sum\limits_{j\in J:\pi(j)=i}p_j$ definiert.
> Der *Makespan* eines Schedules $\pi$ ist die maximale Last, die einer Maschine zugewiesen wird: $$C(\pi):=\max\limits_{i\in M}L_{i}(\pi).$$
> 
> **Gesucht:** Ein Schedule $\pi$ mit möglichst geringem Makespan $C(\pi)$. 

^bc085a

Man kann < Partition> auf dieses Problem polynomiell reduzieren, wodurch es #NP-vollständig ist. ^feba34

### Least-Loaded-Approximation
Der Least-Loaded-Algorithmus greift sich die Jobs in einer beliebigen Reihenfolge heraus und weist sie der Maschine zu, die zu diesem Zeitpunkt die geringste Last hat.

> Least loaded ist ein $(2- \frac{1}{m})$-Approximationsalgorithmus.

> [!example]- Beweis
> 
> *Schritt 1 - Bestimme eine untere Schranke für die Optimallösung*
> Die optimale Schedule kann nicht schneller gehen als die Summe aller Jobs geteilt durch die Anzahl der Maschinen, und er kann auch nicht schneller gehen als die Länge des längsten Jobs, also $$OPT(I)\geq \frac{1}{m}\sum\limits_{j\in J}p_{j} \quad \text{und} \quad OPT(I)\geq \max\limits_{j\in J}p_{j}.$$
> 
> *Schritt 2 - Bestimme eine obere Schranke für die Lösung $\pi$ des Algorithmus*
> Betrachte die Maschine $i\in M$, für die $L_{i}(\pi)=C(\pi)$ ist.
> Sei $j\in J$ der Job, der $i$ als letztes hinzugefügt wurde. Die Last von $i$ zum Zeitpunkt dieser Zuweisung kann man nach oben abschätzen durch $\frac{1}{m}\sum\limits_{k=1}^{j-1}p_{k}$, denn $i$ war zu diesem Zeitpunkt die Maschine mit der geringsten Last und es kann nicht jede Maschine eine geringere Last besitzt haben als der Durchschnitt aller Lasten.
> Also lässt sich die Laufzeit von $M$ nach oben abschätzen durch $$L_{i}(\pi)\leq \frac{1}{m}\left(\sum\limits_{k=1}^{j-1}p_{k}\right)+p_{j}.$$
> Dies kann man nun umformen zu $L_{i}(\pi)\leq (2- \frac{1}{m}) \cdot OPT(I)$, wodurch die obere Schranke in Abhängigkeit der Optimallösung dargestellt ist.
> 
> *Schritt 3 - Finde ein Beispiel, bei dem der Approximationsfaktor tatsächlich erreicht wird*

Worst-Case-Beispiel:
> $n = m(m-1)+1$
> $p_{1}=\ldots=p_{m(m-1)}=1$
> $p_{m(m-1)+1}=m$
> 
> Makespan von Least Loaded (größter Job kommt zuletzt):
> $C(\pi)=(m-1)+m=2m-1$
> 
> Jedoch:
> $OPT=m$
> $\frac{C(\pi)}{OPT}=2- \frac{1}{m}$.
### Longest Processing Time
Der Longest-Processing-Time-Algorithmus (LPT) sortiert erst die Jobs nach ihrer Länge, und führt dann den Least-Loaded-Algorithmus aus.

> LPT ist ein $\frac{4}{3}$-Approximationsalgorithmus.

Der Beweis funktioniert etwas anders: 
Man nimmt an, es gäbe eine Instanz, für die LPT länger brauchen würde als $\frac{4}{3}$ der Optimalzeit. Wählt man diese Instanz kleinstmöglich (also mit möglichst wenigen Jobs), kommt man zu dem Schluss, dass dann jeder Job größer sein muss als $OPT/3$ und man deshalb nicht mehr als zwei Jobs pro Maschine in der Optimallösung haben kann. Dann kann man die Optimallösung für eine solche Instanz explizit angeben und stellt fest, dass dies genau die Lösung von LPT ist, wodurch es zum Widerspruch kommt.
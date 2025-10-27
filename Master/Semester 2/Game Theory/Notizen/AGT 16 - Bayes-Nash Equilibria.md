[[lecturenotes16.pdf]]

Wir kennen noch die *eigene* Bewertung $v_{i}$ *nicht* mehr die Bewertungen $v_{j \neq i}$ der anderen Spieler.
Wir haben W'keitsverteilungen $\mathcal{D}_{j}$ für die Valuationen der anderen Spieler.

Wir schreiben $\beta_{i}:V_{i}\to B_{i}$ für die Funktion, die für unser $v_{i}$ ein Gebot $b_{i}$ bestimmt. Ein ehrliches Gebot ist $\beta_{i}(v_{i})=v_{i}$.

> [!abstract] Definition *(Pure) Bayes-Nash Equilibrium*
> Ein BNE ist ein Profil von *Gebotsfunktionen* $(\beta_{i})_{i \in N}$, sodass für alle Spieler $i \in N$, alle Valuationen $v_{i} \in V_{i}$ und alle alternativen Gebote $b_{i}' \in B_{i}$ gilt: $$E_{v_{-i}\sim \mathcal{D}_{-i}}[u_{i}(\beta(v),v_{i})] \geq E_{v_{-i}\sim \mathcal{D}_{-i}}[u_{i}((b_{i}', \beta_{-i}(v)), v_{i})],$$
> mit $\beta(v)=(b_{1}(v_{1}),\dots ,\beta_{n}(v_{n}))$.


> **Price of Anarchy** für BNE
> Wir betrachten die schlechtestmögliche Verteilung und das schlechtestmögliche Equilibrium. $$PoA_\text{BNE} = \max_{\mathcal{D}} \max_{\beta\text{ ist BNE für} \mathcal{ D}} \frac{E_{v \sim \mathcal{D}}[\text{OPT}(v)]}{E_{v \sim D}[\text{SW}_{v}(\beta(v))]}.$$


> In einer single-item *Erstpreisauktion* ist $PoA_{\text{BNE}}\leq 2$.

Man erhält $\sum_{i \in N} u_{i} \geq \max_{i \in N} \frac{v_{i}}{2}$ mit $\beta_{i}(v_{i})=\frac{v_{i}}{2}$.

Allgemeiner für [[AGT 15 - Smooth Mechanisms#^ec5d66|smooth mechanisms]]:

> **Theorem**
> Ist ein Mechanismus $\mathcal{M}$ $(\lambda,\mu)$-smooth, und alle Spieler können zurückziehen, dann ist $$PoA_{\text{BNE}}\leq  \frac{\max\{ \mu,1 \}}{\lambda}.$$


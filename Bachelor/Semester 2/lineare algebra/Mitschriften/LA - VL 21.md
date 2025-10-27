Datum: 29.06.
[[ThR_LA_Skript.pdf|Skript]] - Seiten 113 bis 122 (Kapitel 11)

# Eigenwerte und Eigenvektoren

> [!abstract] Definition *Diagonalisierbarkeit*
> Ein < Endomorphismus> $f: V \to V$ heißt **diagonalisierbar**, wenn es eine Basis $C$ von $V$ gibt, sodass $\text{DM}_{C}(f)$ eine *Diagonalmatrix* ist.

D.h., eine diagonaliserte darstellende Matrix hat die Form $$\text{DM}_{C}(f)=\begin{pmatrix}\lambda_{1} &  & 0 \\ & \ddots &  \\ 0 & & \lambda_{m}\end{pmatrix}.$$
Offenbar gilt für $C=(v_{1},\ldots,v_{m})$: $$f(v_{i})=\lambda_{i}\cdot v_{i}.$$
> [!abstract] Definition *Eigenwert und Eigenvektor*
> Sei $V$ ein $\mathbb{K}$-Vektorraum und $f: V \to V$ ein Endomorphismus.
> - Ein Skalar $\lambda\in \mathbb{K}$ heißt **Eigenwert** von $f$, wenn es ein $v \in V\setminus \set{0}$ gibt mit $f(v)=\lambda \cdot v$.
> - Ein Vektor $v \in V$ heißt **Eigenvektor** von $f$ zum Eigenwert $\lambda \in \mathbb{K}$, wenn $v \neq 0$ und $f(v)=\lambda \cdot v$.

^97a8fe

> Ein Endomorphismus $f: V \to V$ ist diagonalisierbar **genau dann, wenn** es eine Basis $C$ von $V$ gibt, deren Vektoren Eigenvektoren von $f$ sind.

> [!example] Herausfinden eines Eigenvektors
> Man hat eine Matrix $A \in \mathbb{K}^{m \times m}$ mit einem Eigenwert $\lambda_{1}$ gegeben. Für den Eigenvektor muss man nun das LGS der Gestalt $A \cdot v=\lambda_{1}\cdot v$ lösen. Also: $$0=Av-\lambda_{1}v=A \cdot v - \lambda_{1}\cdot E_m \cdot v = (A - \lambda_{1}\cdot E_m)\cdot v.$$
> 
> Die Matrix $(A - \lambda_{1}\cdot E_m)$ kann man nun ausrechnen, und dann hat man mit $(A - \lambda_{1}\cdot E_m)\cdot v=0$ ein homogenes LGS, das man mit Gauß leicht lösen kann.

## Eigenräume
> Sei $V$ ein $\mathbb{K}$-Vektorraum und $f: V \to V$ ein Endomorphismus.
> Ein Vektor $v \in V \setminus \set{0}$ ist genau dann Eigenvektor von $f$ zum Eigenwert $\lambda$, wenn $$v \in \text{Kern}(f-\lambda \cdot \text{Id}_{V}).$$

Der Beweis hierfür ist analog zum Rausfinden des Eigenvektors oben. 

> [!abstract] Definition *Eigenraum*
> Für einen Endomorphismus $f$ eines $\mathbb{K}$-Vektorraums $V$ mit *Eigenwert* $\lambda \in \mathbb{K}$ heißt $$E(\lambda):=\text{Kern}(f - \lambda \cdot \text{Id}_{V})$$der **Eigenraum** von $f$ zum Eigenwert $\lambda$.
> Die *geometrische Vielfachheit* des Eigenwerts $\lambda$ ist die Dimension von $E(\lambda)$.

^b3db06

Der Eigenraum ist die lineare Hülle aller Eigenvektoren zu diesem $\lambda$.
Die geometrische Vielfachheit eines Eigenwerts ist also mindestens 1. 

> Eigenvektoren zu paarweise verschiedenen Eigenwerten sind linear unabhängig.

Also kann es in einem $m$-dimensionalen Vektorraum höchstens $m$ verschiedene Eigenwerte geben.

> Seien $\lambda_{1},\ldots,\lambda_{r}$ paarweise verschiedene Eigenwerte von $f: V \to V$ mit geometrischen Vielfachheiten $m_{1},\ldots,m_{r}$. 
> - Die Summe der geometrischen Vielfachheiten ist höchstens $\dim(V)$.
> - Basisvektoren aus *verschiedenen* Eigenräumen sind immer linear unabhängig.
> - $f$ ist genau dann diagonalisierbar, wenn die Summe der geometrischen Vielfachheiten *gleich* $\text{Dim}(V)$ ist.



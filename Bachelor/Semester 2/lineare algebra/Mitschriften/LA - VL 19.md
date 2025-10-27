Datum: 22.06.
[[ThR_LA_Skript.pdf|Skript]] - Seiten 101 bis 107

# Koordinatentransformation

> [!abstract] *Transformationsmatrix*
> Seien für einen $\mathbb{K}$-Vektorraum $V$ zwei Basen gegeben als $$\begin{gather}B=(v_{1},\ldots,v_{m}) \text{ und} \\ C=(w_{1},\ldots,w_{m}).\end{gather}$$
> Um einen Vektor $z\in V$, der bzgl. der Basis $B$ gegeben ist, in die Darstellung zur Basis $C$ zu bringen, braucht man eine **Transformationsmatrix**: $$T^{B}_{C}=\begin{pmatrix}(v_{1})_{C} & (v_{2})_{C} & \ldots & (v_{m})_{C}\end{pmatrix},$$d.h. $v_{j}=\sum\limits_{i=1}^{m}t_{ij}w_{i}.$
> 
> Dann gilt für $z=\sum\limits_{i=1}^{m}\lambda_{i}v_{i}=\sum\limits_{i=1}^{m}\mu_{i}w_{i}$: $$T^{B}_{C} \cdot \begin{pmatrix}\lambda_{1} \\ \vdots \\ \lambda_{m}\end{pmatrix} = \begin{pmatrix}\mu_{1} \\ \vdots \\ \mu_{m}\end{pmatrix}.$$

Es gilt für $\mathbb{K}^{m}$:
> - $T_{B}^{B}=E_{m}$
> - $T^{B}_{D}=T^{C}_{D} \cdot T^{B}_{C}$
> - $T^{C}_{B}=(T^{B}_{C})^{-1}$

Transformation in die kanonische Basis ist ganz einfach: Ist $C$ eine wylde Basis und $K$ die kanonische Basis, dann besteht die Transformationsmatrix $T^{C}_{K}$ einfach spaltenweise aus den Vektoren der Basis $C$.

An $T^{K}_{C}$ kommt man dann durch einfaches < Invertieren> von $T^{C}_{K}$.

> **Darstellende Matrix bezüglich Basen**
> Die darstellende Matrix einer Funktion $f: V \to W$, welche die Funktion $f$ anwendet und gleichzeitig einen Basiswechsel von einer Basis $B$ von $V$ in eine Basis $C$ von $W$ durchführt, schreibt man $$\text{DM}_{B,C}(f).$$
> Es gilt:
> - $\text{DM}_{B,C}(f)=\begin{pmatrix}(f(b_{1}))_{C}&(f(b_{2}))_{C}&\ldots&\end{pmatrix}$ mit $B=(b_{1}, b_{2},\ldots)$,
> - $\text{DM}_{B,C}(f)=T^{K}_{C}\cdot \text{DM}(f) \cdot T^{B}_{K}$ mit $K$ als kanonische Basis,
> - $\text{DM}_{B,C}(\text{id})=T^{B}_{C}$.
> - Für < Endomorphismen>: $\text{DM}_{B}(f):=\text{DM}_{B,B}(f)$

$\text{DM}(f)$ meint also $\text{DM}_{K,K}(f)$, wenn nichts Weiteres spezifiziert ist.
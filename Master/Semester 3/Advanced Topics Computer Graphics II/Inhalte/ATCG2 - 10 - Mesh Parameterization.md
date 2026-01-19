[[atcg2-10-Mesh_Parameterization.pdf]]

Wir wollen eine 2D-Textur auf ein 3D-Mesh mappen.
$q$ ist unsere *Parametrisierung* von 2D auf 3D: $$q: \mathbb{R}^{2}\supset \mathcal{D} \to \mathbb{R}^{3}.$$

Wir brauchen dieses Mapping nur für die Punkte eines Dreiecks. Das Mapping für einen Punkt $u,v$ *innerhalb* eines $v_{i},v_{j},v_{k}$ Dreiecks ergibt sich mit den **baryzentrischen Koordinaten** $\lambda_{i},\lambda_{j},\lambda_{k}$ mit $\lambda_{i}+\lambda_{j}+\lambda_{k}=1$ und $\lambda_{i},\lambda_{j},\lambda_{k}\geq0$ (konvexe Kombination der Dreieckspunkte): $$q(u,v)=\lambda_{i}v_{i}+\lambda_{j}v_{j}+\lambda_{k}v_{k}.$$
> **Theorem (Tutte 1963) über Parametrisierung**
> Gegeben ein Dreiecksnetz im $\mathbb{R}^{3}$, das topologisch eine Scheibe ist.
> Dann erhält man davon eine Einbettung in die Ebene (und damit ein valides uv-Mapping, dh. dass sich keine Dreiecke überlappen), wenn man die Grenz-Vertices in ein konvexes Polygon formen kann, und dann jeder Vertex eine konvexe Kombination seiner unmittelbaren Nachbarpunkte ist.

Daraus folgt der folgende Algorithmus:
1. Separiere die Vertices $\mathcal{V}$ in $n$ innere und $N-n$ äußere Punkte: $$\mathcal{V}=\{ v_{1},\dots,v_{n} \} \cup \{ v_{n+1},\dots,v_{N} \}$$
2. Wähle Parametrisierung $(u_{i},v_{i}),\ i=n+1,\dots,N$ für die äußeren Punkte
3. Für alle $i \in \{ 1,\dots,n \}$ und $j \in \{ 1,\dots,N \}$, wähle *irgendwelche* Zahlen $\lambda_{ij}$, sodass $$\lambda_{ij}=0\ \text{falls}\ (i,j) \not\in E,\quad\lambda_{ij}\geq 0\ \text{sonst},\quad\sum_{j=1}^{N}\lambda_{ij}=1$$
4. Löse für $$(u_{i},v_{i})=\sum_{j=1}^{N}\lambda_{ij}\cdot(u_{j},v_{j}),\quad i =1,\dots,n$$ indem wir alle Unbekannten ($i=1,\dots,n$) auf die linke Seite holen mit $$(u_{i},v_{i})-\sum_{j=1}^{n}\lambda_{ij}\cdot(u_{j},v_{j})=\sum_{j=n+1}^{N}\lambda_{ij}\cdot(u_{j},v_{j})$$ woraus wir ein LGS bauen können: $$\begin{pmatrix}
1 & -\lambda_{12} & \dots & -\lambda_{1n} \\
-\lambda_{21} & \ddots &  &  \\
\vdots &  & \ddots & \lambda_{(n-1)n} \\
-\lambda_{n1} &  & \lambda_{n(n-1)} & 1
\end{pmatrix} \begin{pmatrix}
u_{1} & v_{1} \\
\vdots & \vdots \\
u_{n} & v_{n} 
\end{pmatrix} = \begin{pmatrix}
\lambda_{1(n+1)} & \dots & \lambda_{1N} \\
 & \ddots  &  \\
\lambda_{n(n+1)} & \dots & \lambda_{nN}
\end{pmatrix} \begin{pmatrix}
u_{n+1} & v_{n+1} \\
\vdots & \vdots \\
u_{N} & v_{N}
\end{pmatrix}$$
Wir können die beiden unabhängig voneinander Lösen als $Au=u_{b}$ und $Av=v_{b}$. 
$A$ ist hierbei eine **[[ATCG2 - 5 - Mesh Smoothing|Laplace-Matrix]]**.

*Wie wählen wir clevererweise die $\lambda_{ij}$?*
-> Kanten gewichten mit $\lambda_{ij}=\frac{w_{ij}}{\sum_{j}w_{ij}}$
- Uniforme Koordinaten: $w_{ij}=1$
- p
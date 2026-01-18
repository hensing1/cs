[[atcg2-10-Mesh_Parameterization.pdf]]

Wir wollen eine 2D-Textur auf ein 3D-Mesh mappen.
$q$ ist unsere *Parametrisierung* von 2D auf 3D: $$q: \mathbb{R}^{2}\supset \mathcal{D} \to \mathbb{R}^{3}.$$

Wir brauchen dieses Mapping nur für die Punkte eines Dreiecks. Das Mapping für einen Punkt $u,v$ *innerhalb* eines $v_{i},v_{j},v_{k}$ Dreiecks ergibt sich mit den **baryzentrischen Koordinaten** $\lambda_{i},\lambda_{j},\lambda_{k}$ mit $\lambda_{i}+\lambda_{j}+\lambda_{k}=1$ und $\lambda_{i},\lambda_{j},\lambda_{k}\geq0$: $$q(u,v)=\lambda_{i}v_{i}+\lambda_{j}v_{j}+\lambda_{k}v_{k}.$$

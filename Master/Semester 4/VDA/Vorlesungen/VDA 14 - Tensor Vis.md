[[vda-14-Tensor-Vis.pdf]]

Tensorfeld: wie Vektorfeld, aber an jedem Punkt ein Tensor (meist eine Matrix)

Kann genauso interpoliert werden wie ein Vektorfeld.
(Semi)definitheit bleibt erhalten, wenn die Interpolation eine Konvexkombination ist (also nicht z.B. mit Catmull-Rom Splines)
$M$ ist Positiv semidefinit wenn $v^{T}Mv\geq 0\ \forall v$ (Vektoren werden nicht weiter rotiert als 90°)
Strikt positiv definit wenn $v^{T}Mv>0$

Tensorvisualisierung schon gesehen in [[IAAN 8 - Diffusion MRI]]

- ein Diffusionstensor $D$ hat drei Eigenwerte $\lambda_{1}\geq \lambda_{2}\geq \lambda_{3}$
- er hat auch drei orthogonale Eigenvektoren

## Tensor-Glyphs

**Tensor-Ellipsoiden**
Tensor $D$ ist symmetrisch und positiv definit. Wir malen eine Ellipse deren Halbachsen gegeben sind durch die Eigenvektoren (und deren Eigenwerte)

**Superquadric Tensor Glyphs**
Ellipsen sind visuell mehrdeutig. Superquadriken ändern ihre Form dramatischer, zeigen aber immer noch die Eigenvektoren und -werte. Die sind dann kapsel-, oreo-, kugel- oder seifenförmig

*Westin Measures*
beschreiben Eigenwerte $\lambda_{1}\geq \lambda_{2}\geq \lambda_{3}$:
$$\begin{align}
c_l &= \frac{\lambda_1-\lambda_{2}}{\lambda_{1}+\lambda_{2}+\lambda_{3}} & \text{beschreibt Linearität} \\
c_{p} &= \frac{2(\lambda_{2}-\lambda_{3})}{\lambda_{1}+\lambda_{2}+\lambda_{3}} & \text{beschreibt Planarität} \\
c_{s} &= \frac{3\lambda_{3}}{\lambda_{1}+\lambda_{2}+\lambda_{3}} & \text{beschreibt Kugeligkeit}
\end{align}$$

![[Westin Measures.png|627]]

Für $c_{s}=1$ eine Kugel zu haben ist gut, weil z.B. bei der Itentitätsmatrix jeder Vektor ein Eigenvektor ist. Die Identität also z.B. mit einem Box-Glyph zu beschreiben, hebt drei willkürliche Vektoren hervor.

Für $c_{p} \approx_{1}$ ist ein flacher Zylinder aus denselben Gründen gut. In der Mitte vom Dreieck ist eine Box am besten. Die Superduperquadrik interpoliert gleichmäßig zwischen Zylinder, Box und Kugel
Wir haben dann noch einen Superparameter $\gamma$, mit dem wir die Scharfkantigkeit steuern können.

Für die Visualisierung kann es ganz hilfreich sein, die Glyphs von einem regulären Grid dorthin zu bewegen, wo sie sich selber nicht überdecken und trotzdem noch möglichst gut alles abdecken (Glyph Packing)
[[atcg2-09-Mesh_Editing.pdf]]

Wir möchten ein Dreiecksnetz innerhalb einer Region of Interest (ROI) *verformen*, sodass es 
1. eine bestimmte Pose eines "Griffs" innerhalb der ROI erfüllt, und
2. bestimmte Glattheits-Einschränkungen erfüllt.

Die Dreiecke des Griffs sollen unverändert bleiben.

Modellierung mit Displacement-Funktion $d$ für eine Oberfläche $\mathcal{S}$: $$\begin{align}
d&: \mathcal{S} \to \mathbb{R}^{3} \\
p &\mapsto p + d(p).
\end{align}$$
Ähnlich wie bei [[CV 6 - Snake 🐍|Snakes]] (?) wollen wir, dass alles in der ROI, das nicht der Griff ist, einen Energie-Term minimiert: $$E=\int_{\mathcal{S}}k_{s}\left\|M_{1}'(u) - M_{1}(u)\right\|_{F}^{2}+k_{b}k_{s}\left\|M_{2}'(u) - M_{2}(u)\right\|_{F}^{2}\,du$$

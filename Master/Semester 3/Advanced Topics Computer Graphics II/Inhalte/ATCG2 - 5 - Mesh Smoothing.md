[[atcg2-05-Mesh_Smoothing.pdf]]

Gegeben seien:
- Ein Skalarfeld $\rho: \mathbb{R}^{2} \times \mathbb{R}_{\geq0} \to \mathbb{R}$ mit $(x,t) \mapsto \rho(x,t)$
	- Also ein Skalar auf jedem Punkt der Oberfläche, veränderlich über die Zeit
	- Wir interprätieren das als Temperaturfeld
- Die Umrandung eines Objekts: $\partial \Omega$

Das Smoothing eines Objekts ist jetzt die Diffusion der Hitze über die Grenze des Objekts.

Die Hitze verteilt sich in die entgegengesetzte Richtung des Gradienten (Fouriersches Gesetz): $$f= -\lambda \cdot \nabla \rho(x,t).$$
Mit Hitzefluss $f$ und Normalenvektor $n$ des Objekts ist der Gesamtfluss (Flux), der sich über die Objektgrenze bewegt: $$\Phi=\int_{\partial \Omega}\langle f \mid n \rangle \,dA.$$
Dieser Wert lässt sich anders ausdrücken als die Menge an Hitze, die das Gesamtobjekt an Hitze verliert: $$\Phi=- \int_{\text{interior}(\Omega)}\frac{ \partial  }{ \partial t } \rho(x,t)\,dV.$$

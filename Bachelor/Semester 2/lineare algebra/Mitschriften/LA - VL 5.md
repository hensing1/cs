Datum: 20.04.
[[ThR_LA_Skript.pdf|Skript:]] Seiten 22 und 23

Wir beweisen Satz 2.11 aus dem Skript und betrachten verschiedene Beispiele von [[Vektorräume#Untervektorräume|Untervektorräumen]]:

Die *Menge aller Funktionen von $\mathbb{R}$ nach $\mathbb{R}$*, d.h. $\text{Abb}(\mathbb{R},\mathbb{R})=\set{f \mid f : \mathbb{R} \to \mathbb{R}}$, ist mit den Verknüpfungen $+$ und $\cdot$ ein **Vektorraum**.

Dann ist die Menge aller Achsensymmetrischen Funktionen $U=\set{f \in \text{Abb}(\mathbb{R},\mathbb{R}) \mid \forall x \in \mathbb{R}: f(x) = f(-x)}$
ein Untervektorraum von $\text{Abb}(\mathbb{R},\mathbb{R})$.

Dafür ist zu zeigen:
- $U \neq \emptyset$
	- Hierfür reicht ein Beispiel für eine achsensymmetrische Funktion, z.B. die Nullfunktion.
- Abgeschlossenheit bzgl. $+$
	- Heißt: $f,g \in U \Rightarrow f+g \in U$
	- Beweis: $(f+g)(x)=f(x)+g(x)=f(-x)+g(-x)=(f+g)(-x)$.
- Abgeschlossenheit bzgl. $\cdot$
	- Heißt: für alle Skalare $\lambda\in \mathbb{R}$ und alle $f \in U$ gilt: $\lambda \cdot f \in U$.
	- Beweis: $(\lambda\cdot f)(x)=\lambda \cdot f(x)=\lambda \cdot f(-x)=(\lambda \cdot f)(-x)$


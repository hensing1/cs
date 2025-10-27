Datum: 02.10.

# DCG - VL 1

Wir sitzen im $\mathbb{R}^d$, d-dimensionaler euklidischer Raum.  
-> Punkt: $(x_1, \dots, x_d) \in \mathbb{R}$  

## Lineare, Affine und Konvexe Hüllen

**Lineare Hülle:** alle Linearkombinationen der Punkte $p_1, \dots, p_n$:

$$
\text{lin}(p_1, \dots, p_n) = \left\{ \sum_{i=1}^n \alpha_i p_i \mid \alpha_i \in \mathbb{R} \right\}
$$
-> $n$-dimensional, falls $p_i$ unabhängig.
- Lin. Hülle von 1 Punkt: Gerade durch den Ursprung
- Lin. Hülle von 2 Punkten: Ebene

**Affine Hülle:**
$$
\text{aff}(p_1, \dots, p_n) = \left\{ \sum_{i=1}^n \alpha_i p_i \mid \alpha_i \in \mathbb{R}, \sum_{i=1}^n \alpha_i = 1 \right\}
$$

- Affine Hülle von 2 Punkten: Gerade  
- Affine Hülle von 3 Punkten: Ebene (alle Punkte in allgemeiner Lage)  

**Konvexe Hülle:** ^719510
$$
\text{conv}(p_1, \dots, p_n) = \left\{ \sum_{i=1}^n \alpha_i p_i \mid \alpha_i \in \mathbb{R}, \sum_{i=1}^n \alpha_i = 1, \alpha_i \geq 0 \right\}
$$

- Konvexe Hülle von 2 Punkten: Strecke  
- Konvexe Hülle von 3 Punkten: Dreieck  
- Konvexe Hülle von 4 Punkten: Viereck (im $\mathbb{R}^2$)  

## Radons Lemma

**Affin abhängig:** Eine Menge von Punkten $p_1, \dots, p_n$ ist affin abhängig, falls ein $p_i$ als affine Kombination der anderen Punkte dargestellt werden kann.  

**Affine Abhängigkeit in $\mathbb{R}^d$:** Eine Menge von $d+2$ Punkten in $\mathbb{R}^d$ ist immer affin abhängig.

> [!abstract] Radons Lemma  
> Für jede Menge von $d+2$ Punkten $A \subset \mathbb{R}^d$ existiert ein Punkt $q$, sodass $A$ aufgeteilt werden kann in zwei Mengen $A_1, A_2 \subset A$ mit:  
> - $A_1 \cap A_2 = \emptyset$  
> - $q \in \text{conv}(A_1) \cap \text{conv}(A_2)$  
> Der Punkt $q$ heißt **Radon-Punkt**.

### Radons Lemma im $\mathbb{R}^2$
**Gegeben:** $A = \{a, b, c, d\}$  

**Fall 1:**  
$$
A_1 = \{a, b, c\}, \, A_2 = \{d\}
$$

**Fall 2:**  
$$
A_1 = \{a, b\}, \, A_2 = \{c, d\}
$$

$q$ ist der Radon-Punkt.  

[[Radons_Lemma_Zeichnung.png]]

---

## Weitere Begriffe

**Linear Subspace:** Untervektorraum.  
**Affine Subspace:** Linear verschobener Untervektorraum.  

**Affine Funktion:** Lineare Funktion mit Translation.  

**Hyperebene:** Für $a \in \mathbb{R}^d \setminus \{0\}$ und $b \in \mathbb{R}$:  
$$
\{x \in \mathbb{R}^d \mid \langle a, x \rangle = b \}
$$  
Dies ist ein $(d-1)$-dimensionaler affiner Unterraum von $\mathbb{R}^d$.  

**k-flat:** Name für einen $k$-dimensionalen affinen Unterraum.  
- Darstellung als Schnittmenge von Hyperebenen oder Bildmenge einer affinen Funktion.  

**Halbraum:** Menge begrenzt durch eine Hyperebene, also  
$$
\{x \in \mathbb{R}^d \mid \langle a, x \rangle \geq b \}
$$  
für $a \in \mathbb{R}^d$ und $b \in \mathbb{R}$.  

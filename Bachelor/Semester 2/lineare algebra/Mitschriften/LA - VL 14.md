Datum: 25.05.
[[ThR_LA_Skript.pdf|Skript]] von Seite 61 bis Seite 65

# Mehr über Homomorphismen

> [!abstract] Definition
> Die *Menge aller linearen Abbildungen* zwischen zwei $\mathbb{K}$-Vektorräumen $V$ und $W$ bezeichnen wir mit $$\text{Hom}(V,W):=\set{f \mid f : V \to W \text{ linear}}.$$
> Mit den Verknüpfungen [^1]$$\begin{gather}+: \text{Hom}(V,W) \times \text{Hom}(V,W) \to \text{Hom}(V,W)\\(f+g)(x):=f(x)+g(x)\end{gather}$$ und $$\begin{gather}\cdot : \mathbb{K} \times \text{Hom}(V,W) \to \text{Hom}(V,W) \\(\lambda \cdot f)(x):=\lambda \cdot f(x)\end{gather}$$ sowie der Nullabbildung $0(x):= 0_W$ bildet die Struktur $$(\text{Hom}(V,W), +, \cdot, 0)$$ einen **$\mathbb{K}$-Vektorraum.**

[^1]: eigentlich: $(f+_{\text{Hom}(V,W)} g)(x) = f(x)+_{W}g(x)$

## Arten von Homomorphismen

![[Lineare Funktionen#^b41f20]]

Offensichtlich gilt: ist $f$ ein Isomorphismus, dann ist $f^{-1}$ ebenfalls ein Isomorphismus.

Sind $f$ und $g$ zwei Automorphismen, dann ist $(f \circ g)(x)=f(g(x))$ ebenfalls ein Automorphismus. 
Mit $\text{Aut}(V):= \set{f : V \to V \mid f \text{ ist Automorphismus}}$ ist folglich die Struktur $$(\text{Aut}(V), \circ)$$ eine [[Gruppe]] (die *Automorphismengruppe*).


## Isomorphie zu Pfeilräumen

Es gilt: 
> Jeder beliebige $n$-dimensionale $\mathbb{K}$-Vektorraum ist zu dem Raum $\mathbb{K}^{n}$ isomorph.

Um das zu zeigen, hilft das folgende Lemma: 
> Seien $V$ und $W$ zwei $\mathbb{K}$-Vektorräume. Sei $(v_1,\ldots,v_n)$ eine Basis von $V$, und $w_{1},\ldots,w_{n}\in W$. 
> Dann existiert genau eine lineare Abbildung $f : V \to W$, sodass $f(v_i)=w_i$ für alle $i \in \set{1,\ldots,n}$ gilt.

Konkret ist dies die Abbildung $f(v):=\sum\limits_{i=1}^{n}\lambda_{i}\cdot f(v_{i})$ mit $v = \sum\limits_{i=1}^{n}\lambda_{i}\cdot v_{i}$ und $f(v_i)=w_i$.

Das bedeutet, es gibt für einen endlichdimensionalen $\mathbb{K}$-Vektorraum $V$ für jede Basis $(v_1,\ldots,v_{n})$ genau einen Isomorphismus $f$, sodass $f(v_i)=e_i$, wobei $e_{1},\ldots,e_n$ die kanonische Basis des $\mathbb{K}^{n}$ ist.

Das ist praktisch, da wir mit dem $\mathbb{K}^n$ konkret mittels Vektoren und Matrizen rechnen können, welche lediglich Elemente aus $\mathbb{K}$ enthalten, wohingegen ein Vektorraum $V$ eine beliebig komplizierte Struktur haben kann.
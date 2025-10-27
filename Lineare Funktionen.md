# Lineare Funktionen


> [!abstract] Definition *Lineare Funktion*
> Für zwei $\mathbb{K}$-[[Vektorräume]] $V$ und $W$ heißt eine Abbildung $f : V \to W$ **linear**, wenn $$f(x)+f(y)=f(x+y)$$ und $$f(\lambda\cdot x)=\lambda \cdot f(x)$$ mit $\lambda \in \mathbb{K}$ gilt. Dann heißt $f$ auch **Homomorphismus**. 

^955b6a

Die Verknüpfung $g \circ f$ von zwei linearen Abbildungen $f : V \to W$ und $g: W \to X$ ist ebenfalls linear. ^014f88

> [!abstract] Definition *Spezielle Homomorphismen*
> Sei $f : V \to W$ ein Homomorphismus. Dann heißt $f$:
> - **Isomorphismus**, falls $f$ *bijektiv*
> 	- Monomorphismus, falls $f$ *injektiv*
> 	- Epimorphismus, falls $f$ *surjektiv*
> - **Endomorphismus**, falls $V=W$, also $f$ *Verknüpfung*
> - **Automorphismus**, falls $f$ *bijektive Verknüpfung*.

^b41f20

## Bild und Kern

> [!abstract] Definition *Bild und Kern*
> Sei $f: V \to W$ eine *lineare Abbildung* zwischen zwei Vektorräumen.
> - Die Menge $\set{v \in V \mid f(v)=0}$ heißt **Kern** der Abbildung $f$.
>   Man schreibt $f^{-1}[\set{0}]$, $f^{-1}(0)$ oder $\text{Kern}(f)$.
> - Die Menge $\set{w \in W \mid \exists v \in V : f(v)=w}$ heißt **Bild** von $f$.
>   Man schreibt $f[V]$ oder $\text{Bild}(f)$.

Der Kern ist also die Lösungsmenge von $f(x)=0$ und wird auch als *Nullraum* bezeichnet. Genau dann, wenn der Kern nur $0_V$ enthält, ist $f$ [[Funktionen#Injektive Funktion|injektiv]].

Für eine lineare Abbildung $f : V \to W$ gilt:
> $\text{Kern}(f)$ ist Untervektorraum von $V$, und
> $\text{Bild}(f)$ ist Untervektorraum von $W$.

> [!abstract] Definition *Rang und Defekt*
> Die *Dimension des Bildes* einer linearen Abbildung $f$ heißt **Rang** von $f$: $$\text{Rg}(f) := \dim(\text{Bild}(f)).$$
> Die *Dimension des Kerns* von $f$ heißt **Defekt** von $f$: $$\text{Df}(f):= \dim(\text{Kern}(f)).$$

^a400ac

Um den Rang einer Abbildung zu finden, ist es hilfreich, zunächst Koeffizienten für eine Linearkombination für das Bild zu bestimmen. Hat man bereits eine Linearkombination für die Ursprungsmenge, ist dies mit dem folgenden Satz sehr einfach: 

> Sei $F : V \to W$ linear und $V = \mathcal{L}(v_1,\ldots,v_n)$. Dann gilt: $$\text{Bild}(F)=\mathcal{L}(F(v_{1}),\ldots,F(v_n)).$$

> **Dimensionssatz**
> Für eine lineare Abbildung $f: V \to W$ mit $\text{dim}(V)=n \in \mathbb{N}$ gilt: $$\text{dim}(\text{Kern}(f))+\text{dim}(\text{Bild}(f))=\text{dim}(V).$$
> Also: $\text{Df}(f)+\text{Rg}(f)=n.$

^19ee91


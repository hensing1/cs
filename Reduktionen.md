# Reduktionen
Mithilfe von Reduktionen lassen sich Aussagen über Eigenschaften und Zusammenhänge [[Formale Sprachen und Grammatiken#Formale Sprachen|formaler Sprachen]] treffen.

Reduktionen spielen eine große Rolle in der [[Berechenbarkeitstheorie]] und [[Komplexitätstheorie]].

> [!abstract] Definition **Turing-Reduktion**
> Eine *Turing-Reduktion* einer Sprache $A$ auf eine Sprache $B$ ist eine Turingmaschine, die die Sprache $A$ mithilfe eines (hypothetischen) Unterprogramms für die Sprache $B$ löst.
> Turing-Reduktionen bezeichnet man auch als *Unterprogrammtechnik*.

^f49894

> [!abstract] Definition **Many-One-Reduktion**
> Eine *Many-One-Reduktion* einer Sprache $A \subseteq \Sigma_{1}^{\ast}$ auf eine Sprache $B \subseteq \Sigma_{2}^{\ast}$ ist eine *berechenbare* Funktion $f:\Sigma_{1}^{\ast}\to\Sigma_{2}^{\ast}$ mit der Eigenschaft, dass $$x \in A \iff f(x) \in B$$ gilt.
> Existiert eine solche Reduktion, heißt $A$ *auf $B$ reduzierbar* und wir schreiben $A \leq B$.

^27d8a2

Gilt $A \leq B$, dann kann man $A$ mithilfe eines Entscheiders für $B$ lösen. Also folgt: $$A \leq B \Rightarrow (A \text{ ist unentscheidbar} \Rightarrow B \text{ ist unentscheidbar}).$$
Reduktionen sind transitiv: $$(A \leq B \land B \leq C)\Rightarrow A \leq C.$$
^cd6bde

Für die Aufzählbarkeit zweier Sprachen $A$ und $B$ bedeutet die Reduktion $A \leq B$:
$$B \text{ rekursiv aufzählbar} \Rightarrow A \text{ rekursiv aufzählbar}$$ bzw. $$A \text{ nicht rekursiv aufzählbar} \Rightarrow B \text{ nicht rekursiv aufzählbar.}$$ ^5e4d90

> [!abstract] Definition **Polynomielle Reduktion**
> Eine *polynomielle Reduktion* einer Sprache $A \subseteq \Sigma_{1}^{\ast}$ auf eine Sprache $B \subseteq \Sigma_{2}^{\ast}$ ist eine Many-One-Reduktion $f: \Sigma_{1}^{\ast} \to \Sigma_{2}^{\ast}$, die in *polynomieller Zeit berechnet* werden kann. 
> Man schreibt hierfür $A \leq_{p} B$.

^94ab81

Gilt $A \leq_{p} B$, dann gilt $$B\in P \Rightarrow A \in P$$ (vgl. [[Komplexitätstheorie#P|Komplexitätsklasse P]]).
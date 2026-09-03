[[6_PM2L4_handout.pdf]]

Sei $\mathcal{X}$ die Menge aller möglichen Folgen von Feature-Vektoren (Raum aller möglichen Beobachtungen), und $\mathcal{Y}$ eine Menge von Labeln.

Die Wahrscheinlichkeit $P(y | x)$ ist die Wahrscheinlichkeit, dass Beobachtung $x \in \mathcal{X}$ die Klasse $y \in \mathcal{Y}$ hat.

> [!abstract] Definition *Hidden Markov Model*
> Wir haben:
> - Eine Menge von **Zuständen** $\mathcal{A}=\{ a_{1},\dots,a_{I} \}$
> - Eine Matrix, die uns die Übergangswahrscheinlichkeit von einem Zustand in den nächsten angibt: $A=(a_{ij}) \in [0,1]^{I \times I}$
> - Eine Menge von möglichen **Beobachtungen** $\mathcal{B}=\{ \beta_1,\dots,\beta_{K} \}$
> - Eine Matrix, die uns sagt, mit welcher Wahrscheinlichkeit ein bestimmter Zustand in einer bestimmten Beobachtung resultiert: $B=(b_{ik})\in [0,1]^{I \times K}$
> - Ein initialer Vektor $C \in [0,1]^{I}$ mit der W'keitsverteilung der Zustände am Anfang.

$\mathcal{A}$ und $\mathcal{B}$ sind üblicherweise gegeben, $A,B$ und $C$ werden durch Experten oder überwachtes Lernen ermittelt.

In einem gewöhnlichen Markov-Modell hätten wir nur $\mathcal{A},A$ und $C$.

Wir haben also eine Folge aus Beobachtungen aus $\mathcal{B}$, zum Beispiel Chroma-Vektoren. Wir möchten eine Folge aus $\mathcal{A}$ finden (zum Beispiel Akkorde), die diese Beobachtungen am besten erklären.
Das macht der **Viterbi-Algorithmus**.


## Formale Definition

> [!abstract] Definition
> Ein **Kellerautomat** (*Push Down Automaton*, *PDA*) $A$ ist ein Tupel $(Q, \Sigma, \Gamma, \delta, q_{0}, Z_{0}, F)$ bestehend aus folgenden Komponenten:
> - Eine *endliche Zustandsmenge* $Q$
> - Ein *endliches Eingabealphabet* $\Sigma$
> - Ein *endliches Stack-Alphabet* $\Gamma$
> - Eine *Zustandsübergangsrelation* $\delta \subseteq Q \times (\Sigma \cup \set{\epsilon}) \times \Gamma \times Q \times \Gamma ^{\ast}$, wobei $Q \times (\Sigma \cup \set{\epsilon})\times \Gamma$ die aktuelle Konfiguration und $Q \times \Gamma ^{\ast}$ den Folgezustand und die auf den Stack geschriebene Zeichenfolge beschreibt
> - Ein *Anfangszustand* $q_{0}\in Q$
> - Das *Stack-Startsymbol* $Z_{0}\in \Gamma$
> - Eine Menge von *akzeptierenden Zuständen* $F \subseteq Q$.

Ein Kellerautomat kann genau die [[Formale Sprachen und Grammatiken#Kontextfreie Grammatiken|kontextfreien Sprachen]] entscheiden. Da es sich um eine Übergangsrelation handelt, ist ein Kellerautomat im allgemeinen *nichtdeterministisch*.
Ein deterministischer Kellerautomat kann nur eine Teilmenge der kontextfreien Sprachen entscheiden, jedoch auch manche nicht-regulären Sprachen. Im Gegensatz zu [[Endliche Automaten|DFAs und NFAs]] kann man also nicht zu jedem nichtdeterministischen PDA einen deterministischen PDA konstruieren.

Ein PDA ist also mächtiger als ein DFA, jedoch weniger mächtig als eine [[Turingmaschine]].
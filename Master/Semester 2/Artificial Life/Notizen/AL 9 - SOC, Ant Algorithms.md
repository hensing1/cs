[[ALSS25_09_SOC_Ant-Alg.pdf]]
## Self-Organized Criticality

> [!abstract] Definition *Self-Organized Criticality (SOC)*
> Self-organized criticality (oder Self organitation *to* criticality) ist eine Tendenz mancher Systeme, sich von selbst zu eineim **kritischen Punkt** hin zu entwickeln.
> Ein kritischer Punkt ist ein Zustand, in welchem nur eine kleine lokale Veränderung eine große globale Veränderung verursachen kann.
> In SOC ist der kritische Punkt also ein *Attraktor*.

Beispiel ist ein Sandhaufen, der durch herabrieselnde Sandkörner entsteht. 
Die Steigung des Haufens ist gerade so niedrig genug, dass keine Lawine entsteht - allerdings kann eine leichte Erschütterung oder ein einzelnes zusätzliches Sandkorn eine auslösen.

Das Auftreten einer großen, plötzlichen Veränderung mit eindeutigem Beginn und Ende nennen wir ein *Event*.
Die Häufigkeit des Auftretens $N(s)$ eines Events ist invers proportional zu seinem Schweregrad $s$:

$$\begin{gather}
N(s) \propto \frac{1}{s ^{\gamma}} \\
\log(N(s)) \propto -\gamma \log(s)
\end{gather}$$

**Scaling Law:**
$$f(\lambda x)=C(\lambda)f(x)$$


## Ant Algorithms

Ameisen laufen zufällig in alle möglichen Richtungen und hinterlassen dabei eine Spur von Pheromonen.
Die Pheromone verdunsten exponenziell.

Hat eine Ameise etwas zu essen gefunden, folgt sie der höchsten Pheromonkonzentration (ihrer eigenen Spur). Dadurch ist auf diesem Pfad nun die doppelte Konzentration vorhanden, und andere Ameisen folgen diesem Pfad eher.

Finden mehrere Ameisen verschiedene Pfade zum Futter, wird der kürzere dadurch bevorzugt, dass Ameisen auf ihm schneller zwischen Nest und Futter hin und herlaufen, wodurch die Pheromonkonzentration höher ist als auf dem längeren Pfad.

Ameisenalgorithmen können leicht als Suchalgorithmen auf Graphen übertragen werden.
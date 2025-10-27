Datum: 29.05.
[[Slides 05.pdf|Folien]]

# Gradient Clipping

Es ist möglich, dass die Lossfunktion steile Klippen hat, bei denen der Gradient äußerst hoch wird.
Wenn man eine solche Klippe während der Optimierung trifft, macht man durch den hohen Gradienten einen sehr großen Schritt, wodurch ein großer Teil der bisherigen Optimierung kaputt gemacht werden kann.

*Gradient Clipping:* setzt Gradienten herunter, sobald sie einen Schwellwert übersteigen.
- Norm-Clipping: der gesamte Gradientenvektor wird herunterskaliert, wenn seine [[Vektoren#Norm|Norm]] einen Schwellwert überschreitet
- Value-Clipping: nur der einzelne Gradienteneintrag, der einen Schwellwert überschreitet, wird auf diesen Schwellwert herabgesetzt.

# Initialisierung

*Zu kleine Netzwerkgewichte:* $Wx+b \approx 0$, Aktivierungsfunktion wie $\sigma$ sind nahe 0 annähernd linear -> Netzwerk kollabiert zu linearer Funktion

*Zu große Netzwerkgewichte:* Ableitung von $\sigma$ für große Werte annähernd 0 -> Training wird äußerst langsam

> **Skalierung der Eingabedaten**
> Der Wertebereich der Eingabedaten bestimmt den effektiven Wertebereich der Gewichte in den ersten Layern, was einen großen Einfluss auf die Qualität des gesamten Neuronalen Netzes hat.
> Es wird empfohlen, alle *Eingabedaten* so zu *skalieren*, sodass der Mittelwert = 0 und die [[Glossar#Standardabweichung|Standardabweichung]] = 1 ist.
> Das garantiert, dass alle Eingangsdimensionen gleich behandelt werden und die Initialisierung der Gewichtsmatrizen in einem vernünftigen Intervall liegen.

Wir initialisieren unsere Gewichte also mit Zufallszahlen nahe 0. Das Netzwerk ist zu Beginn also annähernd linear und wird im Verlaufe des Trainings nichtlinearer.
Zufallszahlen deshalb, weil es keine Symmetrien innerhalb eines Layers geben darf: sind die Gewichte gleich, sind auch die Gradienten gleich, und man kann keine unterschiedlichen Verhalten für verschiedene Neuronen trainieren.

$\sigma$ in inneren Schichten führt zu vanishing gradients: die Jacobi-Matrizen werden pro Layer aufmultipliziert (siehe [[DLVC - VL 4#Ableitung konkret|letzte VL]]), und wenn die Eigenwerte dieser Matrizen zu klein sind, werden die Gradienten pro Layer eponentiell kleiner.
Sind die Eigenwerte hingegen größer als 1, werden die Gradienten pro Layer exponentiell größer.

$\to$ ReLU(-artige) in inneren Layern ist sinnvoll, da die Ableitung für positive Eingaben genau 1 ist. 
Gleichzeitig sollten ReLU-Gewichtungen tendentiell positiv initialisiert werden, da ansonsten zu viele Ableitungen (nahe) 0 sind.

Zusammengefasst:
- **Eingangssignale** normalverteilt mit Mittelwert 0 und Varianz 1
- **Gewichte** sinnvollerweise skaliert mit $1/\sqrt{n_{\text{in}}}$, wobei $n_\text{in}$ die Anzahl der Eingangssignale ist
- **Bias** bei 0 ok, bei ReLU-artigen leicht positiv

# Regularisierung

Ziel: Netzwerkkapazität steuern, um under/overfitting zu vermeiden.

> [!abstract] Definition *Regularisierung*
> Jede Art der Modifikation eines Lernalgorithmus mit dem Zweck, den *Generalisierungsfehler* zu reduzieren, ohne den *Trainingsfehler* signifikant zu erhöhen.

Strategien:
- Extra-Terme in der Lossfunktion
- Extra-Bedingen für die Modellparameter

NNs haben sehr hohe Kapazität, wir möchten sie künstlich wieder verringern.
"Modell-Kapazität" bezieht sich bei tiefen NN nicht nur auf Anzahl der Parameter, sondern auch auf Regularisierung.

***Weight Decay:***

Regularisierte Loss-Funktion mit Penalty-Term für Parameternorm $\Omega$: $$\tilde{L}(\theta; X,y) = L(\theta; X,y) + \alpha \cdot \Omega (\theta)$$
$\alpha$ ist Hyperparameter, um den Effekt des Penalty-Terms zu steuern.
Eine Regularisierung der *Gewichtungen* ist sinnvoll, wohingegen die der Bias-Werte zu underfitting führen kann.

Thikonov-Regularisierung (auch $L_2$ oder Ridge Regression): $\Omega(\theta) = \frac{1}{2} \|w\|^{2}$
$\Rightarrow \tilde{L}(\theta; X,y) = L(\theta; X, y) + \alpha \frac{1}{2}\|w\|^2$
$\Rightarrow \nabla_{w}\tilde{L}(w;X,y) = \nabla_{w}L(w;X,y)+\alpha w$.

$L_1$- (auch Lasso-)Regularisierung: $\Omega(\theta) = \|w\|_1=\sum |w|$ 

## Reduktion der Modellkapazität

Um Overfitting zu vermeiden, trainiert man lieber mit mehr Regularisierung als mit weniger Layern.

**Early stopping:**
- nicht zu lange trainineren (aufhören, wenn loss für Validation am geringsten)
- danach noch mal mit Validation set bis zum beim early stopping bestimmten Zeitpunkt trainieren (plus evtl. ein bisschen länger weil mehr Trainingsdaten)

Early stopping ist auch eine Art Regularisierung, weil wir den Raum der trainierbaren Werte einschränken.

**Exponential Moving Average:**
Das [[DLVC - VL 3#Momentum]] ist ebenfalls eine Form der Regularisierung.

**Parameter Sharing:**
Wenn zwei Modelle ähnliches Problem lösen sollten, sollten die Parameter einigermaßen ähnlich sein. Parameter Penalty: $\Omega(\theta_{A}, \theta_{B})=\|\theta_{A}-\theta_{B}\|_{2}^{2}$

Stattdessen verwendet man für beide Models dann dieselben Parameter (spart Speicherplatz).

# Data Augmentation

Wir hätten gerne eine höhere Varianz in Trainingsdaten, also können wir z.B. für Bilddaten Rauschen, Translationen, Rotationen oder Verformungen einführen.

Man kann auch in den hidden Units Rauschen hinzufügen, oder auch in den Netzwerkgewichten selbst.

Output-Labels können auch Fehler haben, z.B. mit Wahrscheinlichkeit $\epsilon$. 
Dann würden wir in den Trainingsdaten nicht 1 für das korrekte und 0 für die inkorrekten Label als Zielwert angeben, sondern $1-\epsilon$ bzw. $\frac{\epsilon}{k-1}$.

# Bagging & Dropout

> **Bagging: Bootstrap AGGregatING**
> Wir trainieren $k$ Modelle mit einer jeweils zufälligen Teilmenge der Trainingsdaten und hoffen, dass die jeweiligen Fehler, die gemacht werden, unkorreliert sind. 

Alternativ kann man auch immer das gesamte Trainingsset nehmen. Die Modelle unterscheiden sich dann durch unterschiedliche Initialisierungen, unterschiedliche Mini-Batches, Hyperparameter, etc.

Bagging ist teuer, deswegen: 

> **Dropout:**
> Units werden während des Trainings zufällig mit Binärmaske ein- und ausgeschaltet.

Man macht quasi Bagging mit Parameter sharing: durch die verschiedenen Masken können exponentiell viele Sub-Netzwerke modelliert werden.

Für jede Trainingsiteration kann eine zufällige Binärmaske gezogen werden, mit der mit einer gewissen Wahrscheinlichkeit Units ausgeschaltet werden (typischerweise 0.2 für Eingabewerte und 0.5 für Hidden Units).

Experimentell zeigt Dropout hohe Regularisierungseigenschaften und kann mit z.B. weight decay kombiniert werden.

- Dropout ist auch Modell-agnostisch, funktioniert also für alle möglichen Modellarten
- Man braucht aber größere Modelle
- "Verantwortung" für das Lernen von Features wird auf alle Units verteilt

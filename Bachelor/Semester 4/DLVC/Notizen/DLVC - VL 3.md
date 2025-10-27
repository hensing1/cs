Datum: 24.04.
[[Slides 03.pdf|Folien]]

# Fehlerfunktionen

Ein Machine Learning Algorithmus, der eine Fehlerfunktion minimieren will, die durch die NLL (Kreuzentropie, L1- oder L2-Loss) gegeben ist, ist ein [[DLVC - VL 2#Maximum-Likelihood-Schätzer|Maximum Likelihood Punktschätzer]].

Mit $\theta$ bezeichnen wir die Modellparameter, also z.B. die Gewichte und Bias-Werte eines KNNs.

Gesucht: $\hat \theta = \arg\min_{\theta} f(\theta)$

$\hat \theta$ ist das globale Minimum der NLL-Funktion.
Hat man ein lineares Modell, kann man [[Numerik - VL 2#Kleinste Quadrate|durch Normalengleichung mit least squares fitten]].
Nichtlineare Modelle kann man üblicherweise nur iterativ optimieren, da es zu viele Parameter für eine analytische Lösung gibt.
Hat $\theta$ bis 100-1000 Parameter, kann man $\hat \theta$ auch über genetische Algorithmen bestimmen.
Darüber hinaus können wir gradientenbasierte Verfahren nehmen.

# Gradientenabstieg

Wir versuchen mit dem Gradienten, ein lokales Minimum in der Fehlerfunktion zu finden.

Steepest descent: Mache einen kleinen Schritt entlang der Richtung des negativen Gradienten der Fehlerfunktion: $\theta_{i+1} = \theta_{i} - \epsilon \nabla f(\theta_{i})$ . Der Parameter $\epsilon$ heißt **learning rate**.

Ist $\epsilon$ zu klein, konvergiert das Verfahren zu langsam. Ist $\epsilon$ zu groß, konvergiert es gar nicht.

## Näherungsweise Methoden zweiter Ordnung

Wir suchen letztendlich eine Nullstelle des Gradienten. Diese können wir auch mit dem [[Analysis - VL 16#Newton-Verfahren|Newtonverfahren]], welches wir dadurch effizienter gestalten, indem wir die zweite Ableitung (die [[Funktionen#Gradient, Jacobi-Matrix, Hesse-Matrix|Hesse-Matrix]]) mit dazu nehmen (wir machen also eine [[Taylor-Reihe|Taylorentwickung]]): $$0 \stackrel{!}{=}\nabla f(\theta ^{\ast}) \approx \nabla f(\theta_{i}) + H_{f}(\theta_{i})(\theta ^{\ast} - \theta_{i})$$
Damit ergibt sich als Update-Schritt: $$\theta_{i+1} = \theta_{i}-(H_{f}(\theta_{i}))^{-1}\nabla f(\theta_{i}).$$
Initialisiert man das nahe genug an einem Minimum und ist $H_{f}$ [[Matrizen#Definitheit|positiv definit]], konvergieren wir gegen dieses Minimum.
## Stochastic Gradient Descent

> Wir schätzen den wahren Gradienten (der auf dem Loss über alle Samples basiert) mit Gradienten über *kleine Teilmengen der Trainingsdaten* (sog. Batches).

- Gradienten für kleinere Batches sind leichter zu berechnen, da man alle Daten im Arbeitsspeicher behalten kann
- Je kleiner die Batchgröße, desto höher die Varianz des Gradienten
	- $\to$ kleinere Batches benötigen **niedrigere Lernraten**, damit das Training stabil bleibt
- Meist ist der GPU-Speicher die limitierende Größe für Batchgrößen
- Mehrprozessor-Architekturen sind bei zu kleiner Batchgröße nicht vollständig ausgelastet
- Die meisten GPUs können besser mit Arraygrößen arbeiten, die eine **Zweierpotenz** sind
- Kleine Batchsizes können praktisch sein, weil man durch das Rauschen aus schlechten lokalen Minima rausspringen kann. 
	- $\to$ **Regularisierungseffekt** durch Rauschen

Die Batches werden während des Trainings uniform zufällig aus der Trainingsmenge ausgewählt.

### Lernrate

Bedingung von Konvergenz von SDG: $\sum_{k=1}^{\infty}\epsilon_{k}=\infty$.

Beispielhafte, abnehmende Lernrate abhängig von Interation $k$:$$e_{k}=(1-\alpha)\epsilon_{0}+\alpha \epsilon_{\tau},\quad\alpha=\min\left(\frac{k}{\tau},1\right)$$
Ab einer festgelegten Iteration $\tau$ bleibt die Lernrate also konstant.
Die Werte für $\epsilon_0$, $\epsilon_\tau$ und $\tau$ werden allgemein durch Rumprobieren bestimmt.

![[learningrates.jpeg|300]]

Vernünftige Lernrate mit etwas zu kleiner Batch size (sieht man am Rauschen):
![[loss.jpeg|300]]

Man kann auch den Validation Error während des Trainings beobachten und die LR verringern, sobald dieser Fehler ein Plateau erreicht.

### Momentum

Gibt es starke Gradientkrümmungen, kleine aber konsistente Gradienten, oder verrauschte Gradienten, kann *Momentum* den SDG beschleunigen.

Der Gradient wird dabei über vergangene Update-Schritte mit exponentieller Abnahme aggregiert, damit sich die Varianz der Updates verringert (eine Art Low-Pass-Filter für den Gradienten).

### Adaptive Lernraten

Es gibt fancy Algorithmen, die die Lernrate dynamisch anpassen(hohe Sensitivität in einigen Richtungen $\to$ für jede Richtung separat den Gradienten betrachten):
- **AdaGrad:** feste Lernrate wird invers-proportional zur Wurzel aus der Summe aller vorhergeganenen quadrierten Gradienten skaliert
	- summieren quadrierten Gradienten auf & gewichten invers mit der Wurzel
	- dh.: in die Richtungen, in die schon große/viele Gradienten berechnet wurden, wollen wir nur noch kleine Schritte machen, und andersherum
	- $\Rightarrow$ nahe des Minimums kleine Schritte, weiter weg große Schritte
	- *Problem:* Langsam, Summe der Gradienten wächst nur $\to$ irgendwann trainieren wir kaum noch
- **RMSProp:** AdaGrad mit exponentiell gewichtetem, gleitenden Mittelwert (moving average)
	- Momentum auf quadrierten Gradienten -> schneller
	- quadrierte Summe wächst nicht unkontrolliert
	- Es wird nur die lokale Situation betrachtet
- **Adam:** RMSProp mit Momentum
	- der heilige Adam

Die Wahl des Algorithmus hängt von Präferenz und Problem ab.
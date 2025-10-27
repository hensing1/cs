[[09temporalfiltering_WS2425_slides.pdf]]

# Temporal Filtering

Wir möchten *Objekte tracken*. Wir möchten eine Abfolge von Zuständen $\{ w_{t} \}_{t=1}^{T}$ aus einer Abfolge von Messungen $\{ x_{t} \}_{t=1}^{T}$ vorhersagen.

## Temporal Models (Allgemein)

Unser Modell teilt sich in zwei Komponenten:
- *Messungs-Modell:* $P(x_{t} \mid w_{t})$ (Likelihood)
	- beschreibt, wie aus einem Zustand eine Messung hervorgeht
	- hängt lediglich vom aktuellen Zustand ab: $P(x_{t}|w_{t-1},\ldots,w_{1}) = P(x_{t}|w_{t})$
- *Temporal Model:* $P(w_{t} \mid w_{t-1})$
	- beschreibt den Übergang zwischen Zuständen
	- Markov-Annahme: $P(w_{t}|w_{t-1},\ldots,w_{1}) = P(w_{t}|w_{t-1})$
	- Beispiele:
		- Brown'sche Bewegung: $w_{t}=w_{t-1}+\epsilon_{p}$, mit $\epsilon_{p}$ Zufallswert
		- Konstante Bewegung
		- Rotationsbewegung
		- Durch die Parameter gewichtete Oszillationen
		- ...


Für ersten Frame: Wahrscheinlichkeitsverteilung mit Bayes-Formel: $$P(w_{1}\mid x_{1}) = \frac{P(x_{1}|w_{1})P(w_{1})}{\int P(x_{1}\mid w_{1})P(w_{1})\,dw_{1}}$$
**Measurement Update** für alle weiteren Frames: $$P(w_{t}\mid x_{1\ldots t}) = \frac{P(x_{t}|w_{t})P(w_{t} \mid x_{1\ldots t-1})}{\int P(x_{t}\mid w_{t})P(w_{t} \mid x_{1\ldots t-1})\,dw_{t}}$$
-> Posterior (neue Schätzung) = Likelihood (Messungsmodell) \* Prior (basierend auf altem Posterior + Temporal Model), normalisiert über alle erlaubten Zustände

Benötigt:
**Temporal Evolution**: Berechnung des Prior, gegeben durch die Chapman-Kolmogorov-Gleichung:
$$P(w_{t}|x_{1,\ldots,t-1}) = \int P(w_{t}|w_{t-1})P(w_{t-1}\mid x_{1\ldots t-1})\,dw_{t-1}$$
-> Integral aus dem Temporal Model und dem Posterior von $t-1$.
Es ist ein Integral, weil wir $w_{t-1}$ nicht kennen, sondern nur dafür eine Verteilung haben.

*Problem:* Die beiden Integrale sind im Allgemeinen nur sehr teuer zu berechnen, da wir über alle Zustände integrieren müssen.

*Lösung:* wir machen alles linear und Gaussian, mit dem Kalman-Filter.

## Kalman-Filter

Die Kalmanfilter-Gleichungen sagen, wie man den Posterior (als Gaussian) aktualisiert. 

Die Vorhersage durch das Temporal Model, sowie die Messung ($P(x_{t}\mid w_{t}$) sind Gaussian.

![[Kalman-Filter.png|400]]

*Temporal Model:* $$w_{t} = \mu_{p} + \Psi w_{t-1}+\epsilon_{p}$$ mit Konstantem $\mu_{p}$, Transitionsmatrix $\Psi$ und Gauß-Rauschen $\epsilon_{p}$. 

Als Vertreilung: $P(w_{t}\mid w_{t-1}) = \text{Norm}_{w_{t}}[\mu_{p}+\Psi w_{t-1}, \Sigma_{p}]$ 

*Messungs-Modell:* $$x_{t}=\mu_{m} + \Phi w_{t} + \epsilon_{m}$$ ^df044e

Als Verteilung: $P(x_{t}\mid w_{t}) = \text{Norm}_{x_{t}}[\mu_{m}+\Phi w_{t}, \Sigma_{m}]$.


Selbst wenn das dynamische Modell ungenau ist (nur Brown'sche Bewegung), erhält man noch bessere Vorhersagen, als wenn man bloß die Messpunkte interpoliert.


### Aktualisierung der Gaussians

Das Temporal Model in den Temporal Evolution step einbauen:
$$
\begin{align}
P(w_{t} \mid x_{1\dots t-1}) &= \int P(w_{t} \mid w_{t-1})P(w_{t-1} \mid x_{1\dots t-1})\,dw_{t-1} & \text{(Chapman-Kolmogorov)} \\
&= \int \text{Norm}_{w_{t}}[\mu_{p} + \Psi w_{t-1}, \Sigma_{p}] \,\text{Norm}_{w_{t-1}}[\mu_{t-1},\Sigma_{t-1}] \,dw_{t-1} & \text{(Temporal Model + Posterior)} \\
&= \text{Norm}_{w_{t}}[\mu_{p} + \Psi \mu_{t-1}, \Sigma_{p} + \Psi \Sigma_{t-1} \Psi^T] & \text{(Gaussian integrieren } \to \text{ neuer Gaussian)} \\
&= \text{Norm}_{w_{t}}[\mu^+, \Sigma^+]
\end{align}
$$

Das Measurement Model & Temp. Evolution-Ergebnis in das Measurement Update einbauen:
$$
\begin{align}
P(w_{t} \mid x_{1\dots t}) &= \frac{P(x_{t} \mid w_{t}) P(w_{t} \mid x_{1\dots t-1})}{P(x_{1\dots t})}\\
&= \frac{\text{Norm}_{x_{t}}[\mu_{m}+\Phi w_{t}, \Sigma_{m}] \text{Norm}_{w_{t}}[\mu^+,\Sigma^+]}{P(x_{1\dots t})} \\
&= \text{Norm}_{w_{t}} \left[(\Phi^T \Sigma_{m}^{-1}\Phi + \Sigma_{+}^{-1})^{-1} (\Phi^T \Sigma_{m}^{-1}(x_{t}-\mu_{m})+\Sigma_{+}^{-1}\mu_{+}), (\Phi^T \Sigma_{m}^{-1}\Phi+\Sigma_{+}^{-1})^{-1}\right] \\
 &= \text{Norm}_{w_{t}}[\mu_{t},\Sigma_{t}]
\end{align}
$$

Man muss für $\mu_{t}$ und $\Sigma_{t}$ eine Inverse berechnen.
Wenn man *mehr Zustände als Messwerte* hat (z.B. Position + Geschwindigkeit als Zustand, nur Position als Messung) ist die Matrix $\Phi$ breiter als hoch (z.B. $\begin{pmatrix}1 & 0 & 0 & 0 \\ 0 & 1 & 0 & 0\end{pmatrix}$). Dann ist $\Phi^{T}\Phi$ eine große Matrix (hier: 4x4), für die es ineffizient ist, die Inverse zu berechnen.
Deshalb: **Kalman Gain** $$K = \Sigma_{+}\Phi^{T}(\Sigma_{m}+\Phi \Sigma_{+}\Phi^{T})$$
Diese Umformung ist eine Anwendung des [[Matrizen#Matrix Inversion Lemma|Matrix Inversion Lemma]].
Neue Formulierung des Zustands:
$$
\mu_{t} = \mu_{+}+K(x_{t} - \mu_{m} - \Phi \mu_{+})
$$
In Klammern steht die Differenz zwischen der tatsächlichen Messung $x_{t}$ und der vorhergesagten Messung $\mu_{m}+\Phi \mu_{+}$ gemäß unserem [[CV 9 - Temporal Filtering#^df044e|Messungsmodell]].
Wenn wir eine schlechte Messung, aber ein genaues Bewegungsmodell haben ($\sigma_{m} \gg \sigma_{+}$), ist der Kalman-Gain $K \approx 0$.
Haben wir eine gute Messung, aber ein schlechtes Bewegungsmodell ($\sigma_{m}\ll \sigma_{+}$), ist der Kalman-Gain $K \approx 1$.

### Kalman-Filter insgesamt

- **Vorhersage des Zustands:** $\mu_{+}=\mu_{p}+\Psi \mu_{t-1}$    <- dynamisches Modell
- **Vorhersage der Kovarianz:** $\Sigma_{+} = \Sigma_{p} + \Psi \Sigma_{t-1} \Psi^{T}$
- **Aktualisierung des Zustands:** $\mu_{t}=\mu_{+}+K(x_{t}-\mu_{m}-\Phi \mu_+)$   <- Mapping von Vorhersage zum Measurement Space
- **Aktualisierung der Kovarianz:** $\Sigma_{t}=(I-K \Phi)\Sigma_{+}.$

## Extended Kalman Filter


## Unscented Kalman Filter

immer noch gaussian

nichtlineare zwei Funktionen

Posterior ist Gaussian (vom letzten Frame), approximiert durch Partikel

Summe der Partikel: Mittelwert $\mu$
Standardabweichung der Partikel: Kovarianz $\Sigma$

- Partikel haben Gewichtungen
	- Gewichtung für Mittelwert $a_0$ festgelegt
	- Gewichtungen für alle anderen Partikel berechnet durch $\frac{1-a_{0}}{2D_w}$
- Partikel 0 ist Mittelwert
- Pro Dimension 2 Partikel (nach links und nach rechts auf der Achse)

Setzen von $a_{0}$: je größer (je näher an 1), desto weiter sind Punkte auseinander

Jetzt wendet man die nichtlineare Funktion auf seine Partikel an (einfach)

Problem: wenn sich die nichtlineare Funktion irgendwie aufteilt, hat man einen großen Gauß-Blob für eigentlich zwei Punkthaufen (keine gute Repräsentierung)

## Particle Filter

Kann nicht-gaußsche, multimodale Dichtefunktionen darstellen

Resampling step: 
- Summe der Gewichte ist 1
- Nach dem Resampling haben alle dasselbe Gewicht
- Partikel mit höherem Gewicht wird mehrere kleine Partikel
- verhindert, dass man irgendwann ein dickes Partikel mit 0,99 Gewicht hat

*Beispiel*
- Fußgänger tracken
- Jedes Partikel ist eine Bounding Box

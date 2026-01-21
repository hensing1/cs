[[iaan-07-Functional-MRI.pdf]]

Statt einem hochauflösendem Bild (in *structural MRI*) machen wir wiederholt (z.B. alle 2 Sekunden) ein Bild mit niedriger Auflösung (z.B. 3x3x5 mm³).

Das passiert mit *Echoplanar Imaging*.

Wir messen damit "Aktivierungen" im Gehirn. 

> **BOLD effect**
> > *B*lood *O*xygenation *L*evel *D*ependency
> Die MR-Signalintensität hängt von der Sauerstoffkonzentration im Blut ab.
> Je weniger Sauerstoff, desto schwächer wird das Signal ($T_{2}^{\ast}$-Zeit wird verringert).

Wird eine Gehirnregion stimuliert, passiert folgendes:
- Neuronen verbrauchen Sauerstoff. Dadurch sinkt die Blut-O2-Konzentration in der Region und man erhält ein schwächeres Signal.
	- schwacher / manchmal gar nicht beobachteter Effekt
- Lokaler Blutfluss wird erhöht, höhere O2-Konzentration
	- Signal steigt 2 - 3% gegenüber der Baseline für die Dauer des Stimulus
	- genannt *Hämodynamische Reaktion*
- Nach Stimulus: Undershoot für mehrere Dutzend Sekunden

![[BOLD-response.png|500]]

Vorbehalt: wir sehen Venen, nicht die Neuronen (können ein paar Zentimeter neben den eigentlich aktivierten Neuronen verlaufen).

## Hemodynamic Response Function

Wir erfassen die positive Änderung im MR-Signal über die Zeit.
Weil die absoluten Änderungen recht klein sind, wiederholen wir das Signal mehrfach und bilden den Durchschnitt, um das Rauschen zu verringern.

Die Hämodynamische Reaktion ist *ungefähr linear*, dh. ein 2-sekündiger Stimulus sieht etwa so aus wie zwei 1-Sekündige Stimuli zusammengeklebt (bzw. eine Kombination von zwei Stimuli):
![[HRF-Linearität.png|500]]

Vorbehalte:
- Sind die Stimuli zu nah beieinander, ist die HRF kleiner als von Linearität erwartet
- Reaktionen auf sehr kurze Stimuli sind wesentlich höher als erwartet
-> diese Stimuli werden bei solchen Untersuchungen vermieden

Die HRF sieht etwa so aus wie eine *Gamma-Verteilung*, deshalb nimmt man diese gern als **kanonische HRF**.
Um den Undershoot zu modellieren, kann man zwei Gamma-Verteilungen voneinander abziehen.

Die HRF sieht für verschiedene Menschen verschieden aus, und auch für verschiedene Gehirnregionen.

Modellierung von kleinen Abweichungen von der kanonischen HRF irgendwie mit Taylor-Approximierung

Faltung der kanonischen HRF mit "Neural Response", um das BOLD-Signal zu erhalten.

## General Linear Model

Um Hypothesentests für Messungen aus dem MRT (z.B. für einzelne Voxel in fMRI-Bildern) durchzuführen, bedienen wir uns eines allgemein gehaltenen Frameworks.
Mit diesem General Linear Model (GLM) können wir z.B. lineare regressionen, t-Tests und ANOVA abbilden.

- Messpunkte: Werte mit $p$ unabhängigen Variablen (z.B. 3D-Koordinaten) und einer abhängigen (z.B. MRT-Intensitätswert)
	- $\{ (x_{1,1},\dots,x_{p,1},y_{1}), \dots, (x_{1,N},\dots,x_{p,N},y_{N}) \}$
- Ein Vektor $y \in \mathbb{R}^{N \times 1}$ mit unseren $N$ Messwerten
- $p$ Vektoren $x_{i} \in \mathbb{R}^{N\times 1}$ mit den zugehörigen $N$ Werten für die unabhängige Variable $i$
- $p$-Lineares Modell ($L(x_{1},\dots,x_{p})$) mit (im Beispiel Regression) $p+1$ Koeffizienten und [[DLVC - VL 2#^3e9587|iid.]] Gauß-Rauschvektor $\varepsilon$: $$y=\beta_{0}+\beta_{1}x_{1}+\dots+\beta_{p}x_{p} + \varepsilon$$
In Matrixschreibweise: $$y=X\beta+\varepsilon$$
mit $\beta=\begin{bmatrix}\beta_{0} & \dots & \beta_{p}\end{bmatrix}^T$ und $X=\begin{bmatrix}1 & x_{1,1} & \dots & x_{p,1} \\ \vdots &\vdots &  &  \vdots \\ 1 & x_{1,N} & \dots & x_{p,N}\end{bmatrix} \in \mathbb{R}^{N \times (p+1)}.$


Die durch das lineare Modell unerklärten Variationen werden als Rauschen ($\varepsilon$) modelliert.
Wir wollen eine least-squares-Lösung finden, also $\varepsilon$ minimieren.

Mit einem GLM kann man auch ungewollte Variablen, wie z.B. Kopfbewegungen, "raus-regressieren", indem man sie mit als unabhängige Variable aufnimmt.

## Task-fMRI Processing Pipeline
- generische Pipeline für Durchführung und Auswertung von fMRI-Experimenten
- Probanden werden darum gebeten, eine bestimmte Aufgabe durchzuführen oder werden bestimmten Stimuli ausgesetzt
- Man möchte herausfinden, ob Aktivität in einer bestimmten Gehirnregion mit einer bestimmten Aktivität / einem bestimmten Stimulus korreliert ("Localisationism")

### Datenerfassung und -Aufbereitung
Rohdaten: mehrere fMRI-Bilder über die Zeit

Verarbeitungsschritte:
- Realignment: Kopfbewegungen können zu starken false positives führen, weil sich einzelne Voxel-Werte durch Translation natürlich stark verändern können
	- -> *rigid registration* zu Referenzbild, z.B. aus der zeitlichen Mitte
	- Output: korrigierte Bilder und die geschätzten *Bewegungsparameter* (Translation und Rotation)
	- können als zusätzliche unabh. Variablen aufgenommen werden (sind aber leider meist nicht linear)
- Slice-Timing-Korrektur
	- 2D-Slices werden nicht parallel, sondern sequenziell aufgenommen -> einzelnes Bild ist nicht ein Zeitpunkt
	- Bilder über Zeit interpolieren
	- benötigt sehr genaue Scanner-Timings
- Normalisierung
	- erst: (rigides) Mappen von fMRI-Bildern zu hochauflösendem sMRI-Scan desselben Subjekts:
	- dann: (nichtlineares) Mappen vom strukturellen Bild zu einem Atlas (z.B. MNI)
- Glätten
	- verringert Rauschen
	- kompensiert für übrig gebliebenes Misalignment
	- Verstärkt Aktivierungen in der Größenordnung des Kernels
- High-Pass-Filter
	- kompensiert das Driften der Baseline-MR-Intensität

### Erstellen des GLM

- Pro-Voxel-Modellierung
- Die ersten paar Messungen werden meist verworfen, damit sich die $T_{1}$-Relaxation stabilisiert (dauert länger als unsere Mess-Intervalle, weswegen das Signal schwächer ist)
- Fitten von der gemessenen BOLD-Reaktion zur erwarteten BOLD-Reaktion aus der Hypothese
- Überprüfen, ob der High-Pass-Filter keine relevanten Teile des erwarteten Signals verschluckt

### Statistische Inferenz

Output des GLMs: t-Scores pro Voxel
Das können wir jetzt, analog zu vorherigen Kapiteln, in z.B. Gaussian Mixture Models reinpacken

### Group Analysis

## Resting State fMRI

Beobachtungen von Gehirnaktivitäten, wenn der Proband keine besondere Aufgabe durchführt
- "Globalismus"-Annahme: Gehirn funktioniert als Ganzes
- Gehirne können bestimmte Funktionen wiedererlernen, wenn andere Gehirnareale beschädigt werden
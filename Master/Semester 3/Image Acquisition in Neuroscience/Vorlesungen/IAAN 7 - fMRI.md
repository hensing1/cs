Statt einem hochauflösendem Bild (in *structural MRI*) machen wir wiederholt (z.B. alle 2 Sekunden) ein Bild mit niedriger Auflösung (z.B. 3x3x5 mm³).

Das passiert mit *Echoplanar Imaging*.

Wir messen damit "Aktivierungen" im Gehirn. 

> **BOLD effect**
> > *B*lodd *O*xygenation *L*evel *D*ependency
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

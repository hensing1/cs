Datum: 18.01.
[[Robotik_13_Digitale_Filter__Regler_Performanz__Verhaltenssteuerung.pdf|Folien]]

# Digitale Filter

Wir betrachten *Lineare Digitale Filter*.

> Ein Linearer Digitaler Filter ist die Realisierung eines zeitdiskreten, [[Robotik - VL 7#^9b9431|linearen Systems]] mit digitalen Schaltkreisen.
> 
> Er hat ein digitales Eingabesignal $u[n]$ und ein digitales Ausgabesignal $y[n]$.
> Mit [[Robotik - VL 12#Z-Transformation|Z-Transformation]]: 
> - Eingabe: $U(z)$
> - Ausgabe: $Y(z) = U(z)H(z)$

*Klassifikation:* 
- FIR-Filter (Finite Impulse Response)
	- Immer stabil
- IIR-Rilter (Infinite Impuse Response)
	- mächtiger
	- möglicherweise instabil
	- einfacher zu implementieren


## FIR-Filter
Auch: Moving Average (MA)-Filter

Ausgabe: Gewichtete Summe von Eingaben:
$$y[n] = \sum_{k=0}^{M}b_{k}u[n-k]$$
Transferfunktion: $H(z) = \sum_{k=0}^{M}b_{k}z^{-k}$
$\to$ keine Polstellen, d.h. Stabilität unabhängig von der Wahl der Parameter

> [!example]- Beispiel
> $$y[n]= \frac{1}{4}u[n] + \frac{1}{2}u[n-1] + \frac{1}{4}u[n-2]$$
> - Konstante Eingabe (Frequenz 0): Konstante Ausgabe
> - Alternierende Eingabe (maximale Frequenz): Ausgabe 0 (Signal wird ausgelöscht)
> $\to$ Tiefpassfilter.
> 
> $$y[n] = u[n] - u[n-1]$$
> - Konstante Eingabe: wird ausgelöscht
> - Alternierende Eingabe: wird um Faktor 2 verstärkt
> $\to$ Hochpassfilter.

## IIR-Filter
Auch: Auto-Regressive Moving Average-Filter (ARMA)

Ausgabe: Gewichtete Summe vergangener Ausgaben plus gewichtete Summe von Eingaben
$$y[n] = \sum_{k=1}^{N}a_{k}y[n-k] + \sum_{k=0}^{M}b_{k}u[n-k]$$

Stabilität nur, wenn Betrag der Polstellen $<1$
- Stabiler Tiefpass: $y[n] = 0.01 u[n] + 0.99 y[n-1]$
- Instabiler Tiefpass: $y[n] = 0.01 u[n] + 1.01 y[n-1]$


## Zurückweisung von Störungen

Wir haben Störungen entweder vor oder nach der Strecke.

$PT_1$-Strecke: ??

### Proportionalregler für $PT_1$-Strecke

Was ist $H$??

Open Loop:
$$H_{OL}=H_{R}H_{PT_1}=\frac{K_{S}K_R}{1+sT_{1}}$$

Closed-Loop-Verhalten $H_{CL}$ kann man aus Open-Loop-Verhalten berechnen (wenn Rückführung negativ(?))

Ideales Folgeverhalten dann, wenn $H_{CL}=1$

Folie 18: Konstante Störungen (vor der Strecke) werden perfekt zurückgewiesen

Folie 19: Für konstante Störungen nach der Strecke dasselbe


## Praktisches Problem: Totzeiten

Wir haben bislang so getan, als ob wir instantan Feedback hätten. Das ist in der Realität nicht der Fall.

- Latenz im Regelkreis

Lösungsansatz:
- Man macht eine Vorhersage (negative Latenz) basierend auf:
	- Aktuelle (latenzfreie) Aktionen (vor der Strecke)
	- Aktuelle (latenzbehaftete) Messungen (nach der Strecke)
- Arbeiten mit vorhergesagtem Zustand

Special Regler für solche Sachen


# Verhaltenssteuerung

*Ansätze für Architekturen*
- Deliberativ
	- Messen $\to$ Planen $\to$ Agieren
	- Langsam und Komplex
- Reaktiv
- Kombination
- Verhaltensbasiert
	- Kombination aus mehreren einfachen Verhalten
	- Verhalten werden situativ aktuvieren

## Reaktive Verhaltenssteuerung

"Die Welt ist ihr eigenes bestes Modell"
- man hat kein internes Modell
- man benötigt gute Sensoren
- Braitenberg-Vehikel

*Typ 1 Braitenberg-Vehikel:*
- Ein Sensor
- Ein Motor
- Verhalten: Motorkraft hängt direkt ab von der Messung

*Typ 2 Braitenberg-Vehikel:*

Typ 2c verhält sich genauso wie Typ 1
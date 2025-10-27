Datum: 28.06.

# Globale Beleuchtung
*Monte Carlo-Integration*

Wir möchten dieses fiese rekursive Integral der Renderinggleichung berechnen

Analytisch geht nicht -> Schätzung mit Monte Carlo-Verfahren

Stützstellen für die Samples werden aufgrund von Wahrscheinlichkeitsdichtefunktion zufällig gezogen -> Erwartungswert über unendlich viele Samples ist der Wert des Integrals


*Numerische Bestimmung eines Integrals*
- 1D: gewichtete Summe
	- Mittelpunktregel: regelmäßige Stützstellen, Gewichtung immer gleich
		- Konvergenz invers Quadratisch mit der Menge der Stützstellen
	- Trapezregel: Mittelwert aus zwei benachbarten Stützstellen
		- Konvergenz immer noch Quadratisch, aber Faktor 2 schlechter
	- 
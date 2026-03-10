[[FOCVE_10_Gaussian_Splatting.pdf]]

Nachteil von NeRF: wir müssen über sehr viele Punkte im Volumen integrieren, auch wenn viele davon nicht viel beitragen
Im Vergleich Surface Rendering: überspringt leeren Raum komplett

Splatting: projizieren von unstrukturierten Daten auf die Bildebene (z.B. Surfels)

Volume Splatting mit Gauss-Kerneln: stelle Surfels als Gauss-Kernel dar

Gaussians sind abgeschlossen unter affinen Transformationen und Integrationen entlang einer Koordinatenachse (wir können einen 3D-Gauß in einen 2D-Gauß machen)

Schritte im Volume Splatting:
- Gaussian von Weltkoordinaten in Kamerakoordinaten umwandeln
- perspektivische Projektion anwenden
	- perspektivische Projektion ist nicht affin
	- -> linear approximeren mit Taylor-Entwicklung

Gaussians zusammenmischen: statt voller volumetrischer Integration
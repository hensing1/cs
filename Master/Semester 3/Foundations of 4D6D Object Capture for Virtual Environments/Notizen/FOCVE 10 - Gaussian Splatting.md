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

Gaussians zusammenmischen: statt voller volumetrischer Integration, dings

**Rekonstruktion**
SfM-Punkte -> Gaussians Initialisieren -> mit Kamera und Rasterisierer zu einem Bild machen
Aus dem Bild mit differenziellem Rendering (weil alle Schritte diff.bar sind) die Gaussians updaten

*Initialisieren*
- Man hat zwei Kameras
- Man findet Korrespondenzen (mit COLMAP)
- Für means $\mu$: 3D-Punktwolke der Korrespondenzen, eine Gaussian pro Punkt
- Für Kovarianzen $\Sigma$: für jeden Punkt seine 3 nächsten Nachbaren finden, mit mittlerer Distanz $\bar{d_{3}}$: $\Sigma = \bar{d_{3}}\cdot I$

*Density Control*
Wir haben eventuell nicht die korrekte Anzahl von Gaussians

- Zu wenige Gaussians in einer Region:
	- Unter-Rekonstruktion (Gaussian zu klein): Gaussian klonen
		- wir optimieren mit ADAM
		- für den Klon setzen wir das Adam-Momentum auf 0, für das Original nicht
	- Über-Rekonstruktion (Gaussian zu groß): Gaussian teilen
		- zwei kleinere Gaussians statt der größeren
		- Heuristischer Faktor: $\Sigma$ durch $1.6$ teilen
- Zu viele Gaussians:
	- Gaussians mit geringer Opazität entfernen ($o<0.005$)

*Rasterisierung*
- Gaussians in 16x16 Tiles sortieren
- $\alpha$ Blending zum Zusammenfassen

## Farben
Wir parametrisieren die Farbe eines Splats mit [[Spherical Harmonics]] (SH).
Mit spherical harmonics erhalten wir eine Funktion, die *parametrisiert nach Richtung* ist, und wir optimieren die Farbe je nach Blickrichtung.

Mit SH nullter Ordnung haben wir nur eine einzelne Farbe pro Splat.
Je höher die Ordnung, desto mehr Detail können wir in die einzelnen Richtungen erfassen.

## Optimierung (Loss)

- Ground Truth $C_{k}$: Referenzbild
- Output $\hat{C}_{k}$: gerenderte (rasterisierte) Gaussian Splats aus derselben Perspektive wie die Kamera

Pixelweiser Loss:
- L1-Loss: $L_{1}(C_{k}, \hat{C}_{k}) = \|C_{k}-\hat{C}_{k}\|$
- Dissimilarity Loss (DSSIM): $\text{DSSIM}(C_{k},\hat{C}_{k})=\frac{1-\text{SSIM}(C_{k},\hat{C}_{k})}{2}$
	- SSIM: Structured Similarity

Andere Loss-Funktion die ist besser

Verbesserung für Sortierung
Erweiterung für bewegte Szenen
Optimierung für Mensch
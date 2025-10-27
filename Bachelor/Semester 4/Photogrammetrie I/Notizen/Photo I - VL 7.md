Datum: 07.05.
[[pho1-09-matching-cc.pdf|Folien]]

# Image Matching

Wir besprechen [[ISS - VL 9#Template Matching|Template-Matching]].

Am besten geht das mit der [[Kreuzkorrelation]], damit wir Robustheit gegenüber Helligkeits- und Kontrastunterschieden haben.

Man kann für jeden Pixel den Korrelationskoeffizienten berechnen. Einen ähnlichen Effekt erhält man, wenn man die Kreuzkorrelation direkt anwendet (die Template nimmt den Platz vom Kernel bei der Konvolution ein). Das Ergebnis ist dann bloß nicht normiert.

## Subpixel-Matching

Um das Maximum der diskreten Korrelationswerte fitten wir eine quadratische Funktion. Dann rechnen wir das Maximum dieser kontinuierlichen Funktion aus.

Mit diesem Ansatz kann man mit einer Genauigkeit bis zu $\frac{1}{10}$ Pixel die Position des Templates bestimmen.

*Performance von Template Matching*
- Rotation der Template um nicht mehr als 20°
- Skalierung um nicht mehr als 30%
- Translations-, Helligkeits- und Kontrastinvariant
- Laufzeit linear in Bild- und Templategröße


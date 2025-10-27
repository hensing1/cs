[[12imagealign_WS2425_slides.pdf]]

# RANSAC und Image Alignment

Wir haben in mehreren Bildern Keypoints extrahiert, Korrespondenzen gefunden, und möchten jetzt mehrere Bilder zu einem Panorama zusammenfügen.

Ansatz:
- Nimm kleine Anzahl von Korrespondenzen heraus
- Berechne Hypothesen-Transformation $T$ zwischen Bildern, um diese zu alignen
- Prüfe, ob andere Matches konsistent mit $T$ sind

Problem: wir könnten falsche Korrespondenzen haben, und wenn wir die Transformation als einfaches lineares Ausgleichsproblem lösen, sind wir äußerst empfindlich gegenüber Ausreißern.

Stattdessen:
## RANSAC

**RAN**dom **S**ample **C**onsensus

> **RANSAC-Algorithmus**
> 1. Wähle zufällig eine minimale Gruppe von Korrespondenzen
> 2. Berechne Transformation für diese Gruppe
> 3. Finde *inlier* zu dieser Transformation
> 4. Sobald genug inlier gefunden, berechne Transformation für all diese Inlier

Was ist ein Inlier?
-> Beispiel Ausgleichsgerade:
- man nimmt zwei Punkte
- Berechne Gerade durch diese zwei Punkte
- Inlier sind alle Punkte, die einen geringen Abstand zu dieser Gerade haben
- Wir merken uns, welche Gerade die meisten Inlier produziert hat
- Am Ende berechnen wir eine Ausgleichsgerade auf Grundlage genau dieser Inlier

-> Beispiel Translation zwischen zwei Bildern
- Für eine Korrespondenz, finde alle weiteren Korrespondenzen, die zur selben Translation passen -> das sind unsere Inlier

Wie häufig muss ich die Korrespondenzen samplen?
-> Bestimmen auf Grundlage von:
- $N$: Anzahl von Korrespondenzen
- $I$: ungefähr erwartete Anzahl von Inliern
- $m$: Größe des Samples (für Geraden: $m=2$)
dann: $$P(\text{Sample enthält nur Inlier})=\frac{\binom{I}{m}}{\binom{N}{m}} = \prod_{j=0}^{m-1} \frac{I-j}{N-j}$$
damit gutes Sample mit $p=95\%$-Wahrscheinlichkeit gefunden wird, $k$-mal wiederholen, sodass $$P(k\text{-mal schlechtes Sample}) = (1-P(\text{Sample enthält nur Inlier}))^{k} < 5\%$$
oder umgeformt für Konfidenz $p$ $$k \geq \frac{\log(1-p)}{\log(1-P(\text{nur Inlier})).}$$
Vorteile:
- Einfach und allgemein
- Funktioniert in der Praxis häufig und mit verschiedenen Anwendungsgebieten
Nachteile:
- Wenn Anteil der Inlier gering, kann komplett falsches Ergebnis ausgegeben werden, oder braucht sehr viele Iterationen
- Oft ist eine gute Initialisierung/Transformation nicht mit minimalem Sample möglich (z.B. wenn zu viel Rauschen)

## Image Alignment

Um ein Bild auf ein anderes zu warpen, reicht eine affine Transformation $\begin{pmatrix}a & b & c \\ d & e & f \\ 0 & 0 & 1\end{pmatrix}$ nicht mehr aus (denn bei so einer bleiben parallele Linien parallel, was bei Bildprojektionen nicht der Fall ist).
Wir brauchen eine *projektive Transformation*, auch genannt *Homographie:* $$\begin{pmatrix}wx' \\ wy' \\ w\end{pmatrix} = \begin{pmatrix}a & b & c \\ d & e & f \\ g & h & i\end{pmatrix}\begin{pmatrix}x \\ y \\ l\end{pmatrix}$$
*Annahme:* wir rotieren die Kamera um ihre eigene Achse.

Ausgehend vom [[Photo I - VL 2#^6603db|Pinhole-Kameramodell]] machen wir quasi aus mehreren Bildern eine sehr große Weitwinkel-Pinholekamera:
![[Weitwinkel-Pinhole.png|150]]

Wir haben in unserer Homographie 9 Parameter, aber nur 8 Freiheitsgrade (wir sind in Homogenen Koordinaten, also dividieren wir $w$ beim Ergebnis raus -> Skalierungsfaktor der Matrix nicht relevant).
Pro Punktepaar können wir zwei Gleichungen definieren, also brauchen wir mindestens vier Punktepaare.

Bei 70% korrekten Puntepaaren bräuchte RANSAC nur 11 Iterationen für 95% Konfidenz.
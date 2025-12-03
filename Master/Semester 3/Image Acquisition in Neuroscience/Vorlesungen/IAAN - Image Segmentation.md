[[iaan-05-Segmentation.pdf]]

Wir schauen uns an: Segmentierung (Partition eines Bildes), Clustering (Gruppierung ähnlicher Datenpunkte), Klassifizierung (Voxel oder Segment einer Kategorie zuordnen).

Anwendungsfälle:
- Gehirn extrahieren
	- vor Normalisierung
	- vor statistischen Analysen
- Einzelne Gehirnregionen messen
	- Altersstudien
	- Inter-Gruppen-Vergleiche: Funktionen von Gehirnbereichen bestimmen
- Andere Analysen auf Regionen einschränken

## Segmentierungen auswerten
Eine Segmentierung A können wir anhand einer Ground Truth B bewerten:

**Dice Score:**
$$\text{DSC}(A,B)= \frac{2 \left|A \cap B\right|}{|A| + |B|}$$

**Intersection over Union:** $$\text{IoU}(A,B) = \frac{|A \cap B|}{|A \cup B|}$$
DSC und IoU sind Modelle normalisiert zw. 0 (keine Übereinstimmung) und 1 (perfekte Übereinstimmung).

**Hausdorff-Distanz:**
Konturen-basiert: für jeden Punkt auf der Oberfläche von A wird der nächstgelegene Punkt von B gefunden
$$\begin{align}
d(a,B) &= \min_{b \in B} d(a,b) \\
\text{HD}(A, B) &= \max\{ \max_{a \in A}d(a,B), \,\max_{b \in B}d(b, A)\}
\end{align}$$
**Hausdorff 95. Quantil:**
$$\begin{align}
d_{95}(A,B) &= \underset{a \in A}{x_{95}}\{ \min_{b \in B} d(a,b) \} \\
\text{HD}_{95}(A, B) &= \max\{ d_{95}(A, B), d_{95}(B, A)\}
\end{align}$$

Robuster gegenüber Ausreißern

## Deformierbare Modelle
Um in einzelnen Slices eine Kontur zu finden, nehmen wir [[CV 6 - Snake 🐍|Snakes]].

*How to Gehirn extrahieren*
- Initialisierung: kleine Kugel innerhalb des Gehirns
	- Bild binärisieren mit $I_{\theta_{g}}=I_{2}+0.1(I_{98} - I_{2})$
		- 2% der Bildintensitäten sind oberhalb $I_{98}$ bzw. unterhalb $I_{2}$
	- Kugelmittelpunkt: Durchschnittsposition aller weißen Pixel
	- Kugelvolumen gleich dem Volumen aller weißen Pixel
- Externe Energie: Bildkanten (Grenze des Gehirns ist recht eindeutig zu sehen)
- Interne Energie: Krümmungsgrad gering halten, gleichmäßiges Sampling entlang der Snake

- Active Contours
- 

## Segmentierung mit Gaussian Mixture Models

Expectation Maximization


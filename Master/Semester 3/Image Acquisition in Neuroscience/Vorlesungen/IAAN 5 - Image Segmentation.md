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

**Tversky Index:**
$$\text{Tversky}(A,B)=\frac{|A \cap B|}{|A \cap B| + \alpha \,|A \setminus B| + \beta \,|B \setminus A|},\ \alpha \geq 0, \beta \geq 0$$
Kombination von Dice und IoU. Für $\alpha=\beta=\frac{1}{2}$ erhält man den Dice-Score, für $\alpha=\beta=1$ IoU.
Mit $A$ Hypothese und $B$ Ground Truth bestraft $\alpha$ false positives und $\beta$ false negatives.

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
- Mesh initialisieren
	- Mesh-Kugel mit halben Radius von oben errechneter Kugel
	- absichtlich zu klein, damit es auf jedem Fall innerhalb vom Gehirn ist
- Mesh expandieren (via externer Energie)
	- jeden Vertex mit Kraft $f_{D}$ in Normalenrichtung verschieben
		- Normale schätzen: Durschnitt der Normalen aller angrenzenden Dreiecke
		- Normale eines Dreiecks: Kreuzprodukt zweier Kantenvektoren
		- Jede Dreiecksnormale wird mit der Fläche des jeweiligen Dreiecks gewichtet
	- Bei *lokalem* Itensitäts-Grenzwert $I_{\theta_{l}}$ sagen wir, dass wir das Gehirn verlassen haben: $$I_{\theta_{l}}=I_{2}+b(I_{\max}-I_{2})$$
		- $I_{\max}$ bezieht sich auf maximale Intensität in lokaler Nachbarschaft
		- $b \in [0, 1]$ ist Parameter für den Algorithmus
		- je kleiner $b$, desto größer Gehirnsegmentierung
	- Berechnung von $f_{D}$: $$f_{D}=\frac{2(I_{\min}-I_{\theta_{l}})}{I_{\max}-I_{2}}$$
		- Nachbarschaft für $I_{\min}$ und $I_{\max}$: entlang $-n$ (nach innen) für bestimmte Distanz - z.B. 20mm für $I_{\min}$, 10mm für $I_{\max}$
		- Wachstum nach außen wenn $I_{\min}>I_{\theta_{l}}$, zurück nach innen wenn $I_{\min}<I_{\theta_{l}}$
- Krümmung kontrollieren (interne Energie)
	- Verschiebe Vertex ein Stückchen entlang Tangentenrichtung, hin zur durchschn. Position der Nachbarn -> uniform spacing
	- Verschiebe Vertex auch ein bisschen entlang der Normalenrichtung -> geringere Krümmung

## Segmentierung

### Mit Clustering
Güte-Term für $k$ Kluster: mit $\gamma(i)$, der einem Vertex-Index $i$ einen Cluster zuweist, und Cluster-Zentren $\mu_{1}$ bis $\mu_{k}$, minimiere $$D=\sum_{i}\|v_{i}-\mu_{\gamma(i)}\|^{2}.$$
$D$ heißt *Distortion*. Genaue Lösungen sind aber schon für $k=2$ #NP-schwer, also müssen wir approximieren.

#### k-Means Clustering
- $k$ Cluster-Zentren zufällig wählen
- Wiederhole bis Konvergenz:
	- jeden Punkt dem nächsten Zentrums-Punkt zuweisen
	- neues Zentrum ist der Mittelwert aller Punkte

Probleme:
- abhängig von Initialisierung
- leere Cluster möglich
- Annahme: Cluster sind gleich groß und kugelförmig
- $k$ empirisch zu wählen

#### Gaussian Mixture Models
Mehrere Gauß-Verteilungen als Grundlage für Daten annehmen, z.B. Intensitätswerte:
![[GMM-Gehirn.png]]

Parametrisierung einer Gauß-Kurve:
$$G_{k} = \pi_{k} \cdot \frac{1}{\sqrt{ 2 \pi }\sigma_{k}} \exp\left( -\frac{(x-\mu_{k})^{2}}{2\sigma_{k}^{2}} \right)$$
- $\pi_{k}$ ist Gewichtung
- $\sigma_{k}$ ist Standardabweichung
- $\mu_{k}$ ist Mittelwert

Es ist $\sum_{k=1}^{K}\pi_{k}=1$. Die Gesamtverteilung $p(x)$ ist die Summe über alle $G_{k}$.



## Segmentierung mit Gaussian Mixture Models

Expectation Maximization


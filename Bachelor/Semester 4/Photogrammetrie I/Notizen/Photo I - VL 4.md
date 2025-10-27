Datum: 25.04.
[[pho1-05-binary-imgs.pdf|Folien]]
# Binärbilder

Beispiele für Binärbilder:
- gescannte Dokumente
- Handschrift
- Masken für Ausschneiden eines Hintergrunds

Wir besprechen den [[ISS - VL 5#Connected-Component-Labeling|Algorithmus für das Finden von Zusammenhangskomponenten]] in Bildern (connected component labeling). Derselbe Algorithmus funktioniert für die N4- und N8-Nachbarschaft.

## Distanztransformation

Ziel: für jedes Pixel innerhalb einer Komponente möchten wir angeben, wie groß die *Distanz zum Rand* ist. Genauer: die Distanz vom Pixelzentrum zum Zentrum des nächstgelegenen Pixels außerhalb der Komponente.

Distanzfunktionen:$$\begin{align*}
D_{4}((r,c),(u,v)) &= |u-r|+|v-c|\\
D_{8}((r,c), (u,v)) &= \max(|u-r|,|v-c|)
\end{align*}$$
![[Distanztransformation.png|400]]

Algorithmus zur Berechnung: 
1. Initialisiere: $$\forall (r,c): d(r,c) = \begin{cases}\infty,& \text{falls}\; b(r,c) = 1 \\ 0 & \text{sonst.}\end{cases}$$
2. Erster Durchlauf: zeilenweise von oben, links nach rechts: $$d(r,c) = \min (d(r,c), d(\text{nachbarn oben + links}) + 1)$$
3. Zweiter Durchlauf:zeilenweise von unten, rechts nach links: $$d(r,c) = \min(d(r,c), d(\text{nachbarn unten + rechts}) + 1)$$

Die $D_4$-Distanz (Manhattan-Distanz) *überschätzt* die tatsächliche (Euklidische) Distanz.
Die $D_8$-Distanz *unterschätzt* die tatsächliche Distanz.

Für eine bessere Approximation der Euklidischen Distanz kann man den Mittelwert der $D_4$- und $D_8$-Distanz nehmen: $D_{o}=\frac{1}{2}(D_{4}+D_{8})$ bzw. $D_{o}=D_{4}+D_{8}$ für hübsche Integer-Werte.

## Morphologische Operatoren

**Erosion:** entferne alle Pixel in der $N_4$-Nachbarschaft des Segmentrands (alle Pixel mit $d(r,c)=1$)
- verkleinert den Vordergrund
- entfernt Artefakte wie Pixelrauschen und dünne Linien

**Erweiterung (Dilation):** füge alle $N_4$-Segmentnachbarn dem Segment hinzu
- vergrößert Vordergrund
- füllt Löcher

Anwendung:
**Opening:** Erosion, dann Erweiterung - entfernt Artefakte vom Vordergrund
**Closing:** Erweiterung, dann Erosion - füllt Löcher im Vordergrund

![[Opening_Closing.png]]


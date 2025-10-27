Datum: 14.11.
[[ISS05_WS2324_Segmentation1_231114.pdf|Folien]]

[[ISS_WS2324_Aufgabenblatt05.pdf]]

# Segmentierung
Die Bildsegmentierung ist zentraler Gegenstand der *Med Level Vision.*

Einzelne Pixel(-gruppen) geben keinen Aufschluss über Kontext (Objekte, zu denen sie gehören). Daher gruppiert man Pixel in Segmente, um die Bildinterpretation auf Eigenschaften dieser Segmente zu begründen.

> [!abstract] Definition *Segmentierung*
> Erzeugung von zusammenhängenden Regionen anhand eines Homogenitätskriteriums, sodass die Zerlegung *vollständig* und *überdeckungsfrei* ist.
> Die erzeugten Regionen heißen **Bildsegmente**.

Die Daten zu einem Segment beschränken sich nicht nur auf Geometrie, sondern es können auch Attribute wie Topologie (Anzahl Komponenten, Anzahl Löcher) oder Textur (siehe Haralick) dazu gespeichert werden.

Man kann trennen anhand:
- Regionen
- Texturen
- Diskontinuitäten

## Histogrammbasierte Segmentierung

> Objekte werden unterschieden anhand ihrer Intensitätswerte (z.B. dunkler Text vor hellem Hintergrund).

*Binäre Klassifikation:* trennen der Pixel anhand Schwellwert.

*Multimodale Klassifikation:* trennen der Pixel anhand mehrerer Schwellwerte.

Die Schwellwerte liegen i.A. zwischen Intensitätshäufungen, d.h. an lokalen Minima zwischen lokalen Maxima im Histogramm.

Bestimmung der Schwellwerte:
- manuell (z.B. durch Fachleute)
- automatisierte Suche nach lokalen Minima im Histogramm		

![[Otsu.png]]
### Clustering-Methode nach Otsu

> Die Methode von Otsu bestimmt optimale Schwellwerte im Bezug auf Inter- bzw. Intraklassenvarianz.

Ansatz:
- Schwellwert wird exhaustiv gesucht
- Intraklassenvarianz, d.h. die Varianz der Intensitätswerte innerhalb der Klassen, wird minimiert

Ein gegebener Schwellwert $T \in [I_\text{min}, I_\text{max}]$ teilt das Bild in die *zwei Klassen* $B$ (Hintergrundpixel) und $O$ (Vordergrundpixel) ein:

$$n_{B}(T)=\sum_{i=0}^{T-1}p(i),\,\,n_{O}(T)=\sum_{i=T}^{I_\text{max}}p(i).$$

Mit den *Mittelwerten* $\mu_B(T)$ und $\mu_O(T)$ ergibt sich die **Interklassenvarianz** als $$\sigma_\text{between}^{2}(T)=n_{B}(T) \cdot n_{O}(T) \cdot (\mu_{B}(T)-\mu_{O}(T))^{2}$$
Die **Intraklassenvarianz** ist die Gesamtvarianz minus Interklassenvarianz:
$$\sigma_\text{within}^{2}(T)=\sigma^{2}-\sigma_\text{between}^{2}(T)$$

Es wird also jeder mögliche Schwellwert $T$ durchprobiert. Es wird derjenige gewählt, der $\sigma_\text{within}$ minimiert bzw. $\sigma_\text{between}$ maximiert.

Formeln für effiziente iterative Berechnung:
$$\begin{align*}
n_{B}(T+1) &= n_{B}(T)+n_{T}\\
n_{O}(T+1) &= n_{O}(T)-n_{T}\\
\mu_{B}(T+1) &= \frac{\mu_{B}(T) \cdot n_{B}(T) + n_{T} \cdot T}{n_{B}(T+1)}\\
\mu_{O}(T+1) &= \frac{\mu_{O}(T)\cdot n_{O}(T) - n_{T} \cdot T}{n_{O}(T+1)}
\end{align*}$$
### Region Labeling

> Das Region Labeling ordnet *zusammenhängenden Pixeln derselben Objektklasse* dasselbe Label zu.

Zuordnung von Regionen durch Connected Component Labeling (s.u.):
![[CCL.png]]

#### Connected-Component-Labeling

Eingabe: Binärbild

Ausgabe: Bild, in dem die Labels durch gut unterscheidbare Farben visualisiert sind

Verarbeitung:
- Betrachte Pixel zeilenweise:
	- Falls Pixel Objektpixel, weise ihm das kleinste Region Label in der 8-Nachbarschaft zu
	- Existiert noch keins, erstelle ein neues Region Label
	- Sind zwei verschiedene Label in der 8-Nachbarschaft, fasse sie zusammen (z.B. mit [[Union-Find-Datenstruktur]])
- Färbe die verschiedenen Regionen anhand ihrer Label ein

Das ganze geht auch als Floodfill mit einer Queue.
## Segmentierung nach Homogenitätskriterien

Die beschriebenen Verfahren für Region Merging und Split-and-Merge lassen sich auch für Clustering verallgemeinern.
### Region Merging

Das Region merging fasst Regionen zusammen, deren Pixel ein bestimmtes Homogenitätskriterium erfüllen (z.B. ein maximaler Intensitätsunterschied $\leq 100$).

Datenstruktur: *Region Adjacency Graph (RAG)*
- Knoten: Region
	- Knotenwert: Daten zu Homogenitätskriterien
- Kante: zwischen benachbarten Regionen
	- Kantenwert: Homogenitätswert, der sich bei Fusion der beiden Regionen ergeben würde

*Vorgehen*
- Start: jedes Pixel ist ein Segment
- Merging: zwei benachbarte Pixel werden zusammengefasst, wenn sie gemeinsam das Homogenitätskriterium erfüllen
- Terminierung: wenn keine Segmente mehr zusammengefasst werden können

> Das Region Merging ist nicht eindeutig. Je nach Bearbeitungsreihenfolge können verschiedene Regionen entstehen.

### Split-and-Merge

Erst splittet man:
- Man betrachtet das gesamte Bild als Segment
- Wenn das Bild nicht den Homogenitätskriterien entspricht, wird es entlang der mittleren Horizontal- und Vertikalachse in vier Teile geteilt
	- Stichwort: Quadtree
- Mit den resultierenden Segmenten passiert rekursiv dasselbe

Und dann mergt man:
- siehe Region Merging

Hoffnung: durch das Splitten erspart man sich Merging-Schritte im Vergleich zum gewöhnlichen Region Merging.
![[SplitnMerge.png]]
## Texturbasierte Segmentierung

> *Textur*
> Die Textur einer Region ist eine beschreibbare Bildungsregel für die Intensitätsverteilungen innerhalb dieser Region.

Unterscheidung von Regionen:
- Texturen gemäß verschiedenen Bildungsregeln
- Texturen derselben Bildungsregel, unterschiedlich parametrisiert

*Definitionsansätze für Textur:*
- Strukturell
	- Zusammensetzung von Texturelementen ("texels"), wie z.B. linienförmige Pixelgruppen
- Statistisch
	- Charakterisierung von Intensitätsmustern
- Stochastisch
	- Ergebnis eines parametrisierten, stochastischen Prozesses, wie z.B. Gauß-verteilte Varianz
- Spektral
	- Eigenschaften in einer Repräsentation des Frequenzraums (nach Fourier- oder Wavelet-Transformation)

### Texturmaße nach Haralick

Die Grundlage der Haralick'schen Texturmaße bildet die Co-Occurrence-Matrix:

> *Co-Occurrence-Matrix*
> Eine Matrix, welche beschreibt, wie häufig Pixel mit einem bestimmten Helligkeitsunterschied in einem gegebenen Abstand $(\Delta x, \Delta y)$ bzw. $(\Delta, \alpha)$ vorkommen:
> - Ein Bild(-ausschnitt) mit $256$ verschiedenen Intensitätswerten produziert eine $256\times 256$-Co-Occurrence-Matrix.
> - Der Eintrag $(i,j)$ der Matrix beschreibt, wie häufig die Intensität $i$ und die Intensität $j$ in dem gegebenen Abstand vorkommen.
> 
> Formal: $$P_{\Delta x, \Delta y}(I_{1},I_{2})= \frac{1}{N}\sum_{x=1}^{n}\sum_{y=1}^{m}\left\{\begin{align*}
1,\, &\text{falls}\, I(x,y)=I_{1}\,\text{und}\,I(x+\Delta x, y + \Delta y))=I_{2}\\
0,\, &\text{sonst.}
\end{align*}\right.$$

Typische Werte für den Abstand sind $\Delta=1$ und $\alpha=0°,45°,90°,135°$. Das ergibt also vier Matrizen.
Die Matrizen werden normiert, sodass alle Einträge in Summe 1 ergeben:
$$p_{\Delta,\alpha}(I_{1},I_{2})=\frac{1}{S}P_{\Delta,\alpha}(I_{1},I_{2})\,\text{mit}\,S=\sum_{I_{1}=0,I_{2}=0}^{I_{max}}P_{\Delta,\alpha}(I_{1},I_{2}).$$

Anhand dieser Matrix lassen sich nun ein Haufen Parameter für die Textur generieren:
- Uniformität: $\sum_{I_{1},I_{2}=0}^{I_{max}} p^2_{\Delta, \alpha}(I_1,I_2)$
- Kontrast: $\sum_{I_{1},I_{2}=0}^{I_{max}} (I_{1}-I_{2})^{2}p_{\Delta,\alpha}(I_{1},I_{2})$
- Entropie: $-\sum_{I_{1},I_{2}=0}^{I_{max}} (I_{1},I_{2}) \cdot \log_{2}(p_{\Delta, \alpha}(I_{1},I_{2}))$ mit $0 \cdot \log0 = 0$
- Homogenität/inverse Differenz: $\sum_{I_{1},I_{2}=0}^{I_{max}} \frac{p_{\Delta, \alpha}(I_{1},I_{2})}{1+|I_{1}+I_{2}|}$
- Inv. Diff.-Moment: $\sum_{I_{1},I_{2}=0}^{I_{max}} \frac{p_{\Delta, \alpha}(I_{1},I_{2})}{1+(I_{1}-I_{2})^{2}}$

### Segmentierung anhand der Haralick-Maße

Schritt 1: 
Bestimme die Größe $n$ für ein $n \times n$-Fenster, innerhalb welchem die Texturmaße bestimmt werden sollen. Man spricht von einer *Texturfrequenz von $n$ Pixeln.*

Schritt 2:
Grase mit diesem Fenster das Bild ab (als sliding window). Berechne jedes mal pro Fenster die Texturmaße. Es entstehen also $(Z-n+1)\cdot(S-n+1)$ Vektoren mit den jeweiligen Texturmaßen ("Texturbild"). Die jeweils betrachteten Fenster überlappen sich.
![[Sliding_Window.png|500]]

Schritt 3:
Finde Segmente in dem Texturbild, z.B. durch Split-and-Merge.
Für ein Homogenitätskriterium könnte man z.B. die 2-Norm der Vektoren betrachten und einen Schwellwert $d_{min}$ bestimmen, den die Differenzen der Normen innerhalb eines Segments nicht überschreiten dürfen.

Schritt 4:
Nun ist jeder Pixel im Texturbild einem Segment und $n \cdot n$ Pixeln im Originalbild zugeordnet. 
Also "stimmt" jeder Texturpixel bei allen zugehörigen Bildpixeln für sein Segment ab.

Schritt 5:
Jedes Pixel gehört zu dem Segment, für dessen Label die meisten Stimmen abgegeben wurden.

(Schritt 6:)
Um Artefakte an Texturrändern zu verhindern, kann das Resultat durch ein Glättungsfilter Nachbarschaftsanalyse geglättet werden.

*Texturfrequenz:*
Die Größe des sliding window kann entweder heuristisch oder durch einen Multiskalenansatz systematisch bestimmt werden.
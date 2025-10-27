Datum: 17.10.
[[ISS01_WS2324_Intro&amp;Histograms_231017-231010.pdf|Folien]]

[[ISS_WS2324_Aufgabenblatt01.pdf]]

# Begrifflichkeiten

Man nimmt eine Funktion $f$ an, welche die Umwelt $W$ auf den Sensorstimulus $S$ abbildet.

- ***Computergrafik:*** versucht, für den Bereich der visuellen Wahrnehmung die Funktion $S = f(W)$ für eine gegebene Umwelt $W$ zu modellieren
- ***Computersehen:*** versucht, ausgehend von einem Sensorstimulus die Umwelt zu bestimmen: $W = f^{-1}(S)$
	- Dieses Problem ist i.A. schlecht gestellt, da es keine eindeutigen Lösungen gibt.

**Bereiche des Computersehens**
- *Early/Low-Level Vision* - Bildverarbeitung
	- Kontrastoptimierung
	- Glättung (Eliminierung von Rauschen)
	- Hervorhebung relevanter Bildpunkte
- *Mid-Level Vision* - Segmentierung
	- Gruppierung von Konturpunkten zu Konturlinien
	- Einteilung des Bildes in Bildsegmente
- *High-Level Vision* - Klassifikation
	- Zuordnung der Bildsegmente zu Objektklassen
	- Inhaltliche Beschreibung des Bildes


# Histogramme
*Low-Level Vision*

## Histogramme für einkanalige Bilder
In einem einkanaligen Bild hat jedes Pixel genau einen Helligkeitswert $I \in \set{I_{\text{min}}, \ldots, I_\text{max}}=\set{0,\ldots,255}$.

Ein ***Intensitätshistogramm*** gibt für jede Intensität $I$ die Anzahl $n_{I}$ der Pixel an, die diese Intensität aufweisen: $$h_{I}(I)=n_{I}.$$
Ein ***normalisiertes Intensitätshistogramm*** skaliert jeden Histogrammwert durch die Gesamtzahl der Pixel $N$: $$p_I(I)=\frac{n_I}{N}.$$
> **Mittelwert und mittl. quad. Abweichung**
> Der *Mittelwert* der Intensitäten ist ein Maß für die Gesamthelligkeit des Bildes:$$m_{I}=\frac{1}{N}\sum\limits_{I=0}^{I_\text{max}}I \cdot h_{I}(I)=\sum\limits_{I=0}^{I_\text{max}}I \cdot p_{I}(I)$$
> Die *mittlere quadratische Abweichung* ist ein Maß für den Kontrast des Bildes: $$q_{I}=\frac{1}{N}\sum\limits_{I=0}^{I_\text{max}}(I-m_{i})^{2}\cdot h_{I}(I)=\sum\limits_{I=0}^{I_\text{max}}(I-m_{i})^{2}\cdot p_{I}(I)$$

Bei einem ***kumulativen Intensitätshistogramm*** werden die relativen Häufigkeiten bis zur jeweiligen Intensität aufsummiert: $$s_{I}(I)=\sum\limits_{i=0}^{I}p_{I}(i).$$
Es ist $s_{I}(I_\text{max})=1$.

## Histogramme für mehrkanalige Bilder
Für ein Bild mit $K$ Kanälen mit jeweils gleich vielen Intensitätswerten gibt es für jedes k-Tupel $(I_{0},\ldots,I_{K-1})$ (jede Farbe) einen Histogrammwert: $$h_{I}(I_{0},\ldots,I_{K-1})=n_{(I_{0},\ldots,I_{K-1})}.$$
Das normalisierte Histogramm funktioniert analog wie beim Grauwertbild.

## Histogrammbasierte Bildverarbeitung

Bearbeitung von Helligkeit und Kontrast:
![[Histogramm_Helligkeit.png|450]]
![[Histogramm_Kontrast.png|450]]

*Lineare Transferfunktion*
Die obigen Veränderungen können leicht mit der linearen Funktion $$T(I)=(I+c_{1})\cdot c_{2}$$modelliert werden.
- $c_1 > 0$: Aufhellung
- $c_1 < 0$: Abdunklung
- $c_2 > 1$: Kontraststeigerung (mit $c_{1}=-I_\text{minGiven}$)
- $c_2 < 1$: Kontrastminderung

### Globaler Kontrast

Seien $I_\text{minGiven}$ und $I_\text{maxGiven}$ der minimale bzw. maximale Intensitätswert, der im Bild vorhanden ist. Dann ist der *globale Kontrast* $C_\text{global}$ definiert als: $$C_\text{global}=\frac{I_\text{maxGiven}-I_ \text{minGiven}}{I_{\text{max}}-I_{\text{min}}}$$
Ist $C_\text{global}<1$, hat das Bild einen suboptimalen Kontrast.

#### Lineare Grauwertspreizung
Der globale Kontrast kann mit den Parametern $c_{1}=-I_\text{minGiven}$ und $c_{2}=\frac{I_\text{max}}{I_\text{maxGiven}-I_\text{minGiven}}=(C_\text{global})^{-1}$ für die lineare Transferfunktion maximiert werden.[^1]

[^1]: bzw. $c_{1}=I_\text{min}-I_\text{minGiven}$ und $c_{2}=\frac{I_\text{max}-I_{min}}{I_{\text{maxGiven}}-I_{\text{minGiven}}}$ für $I_\text{min}>0$.

Anwendungsbereich: z.B. Satellitenbilder, die oft nicht das volle Intensitätsspektrum ausnutzen

### Lokaler Kontrast
Der globale Kontrast hat wenig Aussagekraft, wenn wenige Pixel minimale und maximale Intensität haben, der Rest aber nahe beieiander liegt.

Für $Z$ Zeilen und $S$ Spalten ist der *lokale Kontrast* definiert als $$C_\text{local}(I)=\frac{1}{Z \cdot S}\sum\limits_{x=0}^{Z-1}\sum\limits_{y=0}^{S-1}\left|I(x,y)-\bar{I}(x,y)\right|,$$wobei $\overline{I\space}$ die durchschnittliche Intensität in der lokalen Nachbarschaft beschreibt (z.B. die 8 umliegenden Pixel).

Grundannahme: Pixel mit häufig auftretenden Intensitätswerten sind oft zueinander benachbart. Spreizt man also mittels einer Transferfunktion die hohen Histogrammwerte auseinander, ist davon auszugehen, dass hierdurch auch der lokale Kontrast erhöht wird.

#### Gamma-Korrektur
Mit der Gamma-Korrektur kann man den lokalen Kontrast erhöhen, insb. bei Über- oder Unterbelichtung.

Mit $N_G=I_\text{max}+1$ erhält man die folgende (nichtlineare) Transferfunktion:
$$T_{\gamma}(I)=\left[N_{G}\left( \frac{I-I_\text{min}}{I_\text{max}-I_\text{min}}\right)^{\gamma}+I_\text{min}\right]$$

- $\gamma<1$: 
	- Spreizung von niedrigen, Stauchung von hohen Intensitätswerten
	- Erhellung des Bildes
- $\gamma=1$:
	- Identitätsfunktion
- $\gamma>1$:
	- Stauchung von niedrigen, Streckung von hohen Intensitätswerten
	- Verdunkelung des Bildes

![[Gammakorrektur.png|600]]

### Entropie

Die Entropie ist ein Maß für den mittleren Informationsgehalt eines Bildes.

Für ein normalisiertes Intensitätshistogramm ($0 \leq p_{I} \leq 1$) ist sie definiert als $$H_{I}=-\sum\limits_{I=0}^{I_\text{max}}p_{I}(I) \cdot \log_{2}p_{I}(I)$$mit $0 \cdot \log(0) := 0$.

- Homogenes Bild: $H_I=0$
- Zweipegelbild ($p_I(I_1)=0.5$, $p_I(I_2)=0.5$): $H_I=1$
- Gleich verteiltes Grauwertbild ($p_I(I)=1/256$ für jedes $I$) hat maximale Entropie von 8

#### Histogrammlinearisierung
Wir wollen die Entropie maximieren, d.h. jede Intensität soll ungefähr gleich oft vorkommen.
Das Histogramm soll also konstant werden, bzw. das kumulative Histogramm soll die Identitätsfunktion werden.

Für (angenommene) kontinuierliche Intensitätswerte: $$T_{H}(I) = \int_{0}^{I}p_{I}(i)\,di$$
Diskrete Version: $$T_{H}(I)=\left[N_{G}\cdot \sum_{i=0}^{I}p_{I}(i)\right]$$Die äußerste Klammer ist die kaufmännische Rundung.

Effekt: häufige Intensitätswerte werden gespreizt, während seltene Intensitätswerte gestaucht (z.T. in einzelne Werte überführt) werden.
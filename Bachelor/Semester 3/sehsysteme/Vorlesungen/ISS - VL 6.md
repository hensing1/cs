Datum: 21.11.
[[ISS06_WS2324_Segmentation2_231121.pdf|Folien]]

[[ISS_WS2324_Aufgabenblatt06.pdf]]

# Segmentierung durch Kanten

[[ISS - VL 5|Letzte Vorlesung]]: Segmentierung nach Homogenitätskriterien.
Das Problem dabei: 
- die gewählten Kriterien müssen für *alle* Pixel des Segments gelten
- gibt es Variationen innerhalb des Segments, kommt es schnell zu einer *Übersegmentierung*

Deshalb diesmal: Segmentierung nach Diskontinuitäten, d.h. nach **Kantenzügen.**

Kanten können als Gradientenwerte bereits z.B. mit dem [[ISS - VL 3#Sobel-Operator]] hervorgehoben werden.
Nun möchten wir diese zu vollständigen und geschlossenen Kantenzügen verarbeiten.
Danach kann man mit einer Version des [[ISS - VL 5#Region Labeling]] in Regionen unterteilen. Das Homogenitätskriterium ist hierbei, dass alle Pixel der Region keine Kantenpixel sind.

*Eigenschaften von Kantenzügen:*
- Kantenstärke (bestimmt durch Gradientenbetrag)
- (Lokale) Kantenrichtung (bestimmt durch Gradientenrichtung)
- Kontinuität:
	- In der lokalen Umgebung eines Kantenpixels sollten weitere Kantenpixel mit ähnlichen Eigenschaften zu finden sein.
## Edge Linking

Sei ein Bild mit Gradientenbeträgen gegeben. 
Wird dieses Bild [[ISS - VL 5#Histogrammbasierte Segmentierung|binarisiert]], werden alle Pixel eindeutig als Kanten- oder Nichtkantenpixel klassifiziert.
Problem: Die Kantenzüge sind nun unter Umständen unterbrochen. Um diese Lücken zu schließen, gibt es den Edge-Linking-Algorithmus.

Edge Linking markiert Kantenzüge, auch wenn sie unterbrochen sind. Das Ergebnis kann dazu verwendet werden, um mit Linienalgorithmen aus der Computergrafik die Kanten nachzuzeichnen.

> ***Edge Linking***
> 1. Markiere alle Kantenpixel als unbearbeitet
> 2. Wähle ein beliebiges Kantenpixel $p_{a}$ aus und markiere es als aktives Pixel eines neuen Kantenzugs $k$.
> 3. Falls sich *in Kantenrichtung* in einer Umgebung $U(p_a)$ *unbearbeitete* Kantenpixel $p_i$ mit ähnlichen Kantenrichtungen und -beträgen befinden:
> 	- Ordne $p_{i}$ dem Kantenzug $k$ zu
> 	- Markiere $p_i$ als aktiv
> 	- Markiere $p_a$ als bearbeitet
> 	- Wiederhole Schritt 3 mit den nun aktiven Pixeln
> 4. Falls in $U(p_a)$ Pixel mit einem anderen Kantenlabel sind, wurde eine Verzweigung gefunden.
> 5. Falls es noch unbearbeitete Kantenpixel gibt: zurück zu Schritt 2

Alle Kantenpixel mit Kantenlänge 1 werden als Rauschen eingeordnet und entfernt.
Parameter für Edge Linking: Größe von $U(p_a)$, Ähnlichkeitsmaß von Gradientenrichtungen und -&zwnj;beträgen.

## Skelettierung

Nach Edge Linking hat man durchgehende Kanten, die jedoch ggf. breiter sind als ein Pixel.
Die Skelettierung verdünnt die Kanten auf die Kantenzentren.

> [!abstract] Definition *Skelett*
> Sei $F$ eine Fläche mit Grenze $G$. Sei $p$ ein Punkt in $F$.
> 
> Ein *nächster Grenzpunkt $g$ von $p$* ist ein Punkt $g$ in $G$ derart, dass kein anderer Grenzpunkt $g'$ in $G$ existiert mit Abstand $g'p<gp$.
> 
> **Hat $p$ mehr als einen nächsten Grenzpunkt, dann heißt $p$ Skelettpunkt von $F$.**
> 
> Die Menge aller Skelettpunkte von $F$ heißt Skelett oder Mittelachse von $F$.

![[spooky_scary_skeletons.png|350]]

Für die Skelettierung gibt es den Algorithmus nach Pavlidis:
- Für alle Randpixel eines Segments:
	- Evaluiere, ob es sich um ein Skelettpixel handelt:
		- Teste, ob die Umgebung in eines dieser beiden Muster (oder ihre rotierten Varianten) passt:
			- ![[Pavlidis-Muster.png|250]]
		- Ist in den Gruppen A und B je mindestens ein Pixel gesetzt, handelt es sich um ein Skelettpixel.
		- Falls kein Skelettpixel, markiere zum Löschen
- Lösche alle markierten Pixel
- Beginne von vorn, bis keine Pixel mehr gelöscht wurden

## Canny Edge Operator

Der Canny-Edge-Operator zielt auf folgende Ergebnisse ab:
- *Hohe Erkennungsrate:* möglichst viele Kanten sollen erkannt werden
- *Hohe Präzision:* möglichst ortsgenaue Lokalisierung der Kanten
- *Eindeutigkeit:* jedes Kantenpixel ist nur einer Kante zugeordnet

Vorgehen:
1. Glätten des Eingabebilds durch [[ISS - VL 2#Gauß-Filter]]
2. Bestimmung der Kantenpunkte (Intensität und Gradientenrichtung) durch [[ISS - VL 3#Sobel-Operator]]
3. Kanten werden durch Non-Maxima-Unterdrückung verdünnt
	- d.h. alle Kantenpunkte, die in Gradientenrichtung kein lokales Maximum sind, werden verworfen
4. Die resultierenden Kantenpunkte werden durch Hysterese-Schwellwertbildung zu Kantenverläufen zusammengefügt:
	- Beginne Kantenzug bei einem hellen Kantenpixel, der einen Schwellwert $t_1$ überschreitet
	- Verfolge diesen Kantenzug orthogonal zur Gradientenrichtung, solange ein Schwellwert $t_{2}$ mit $t_2<t_1$ nicht unterschritten wird.
		- Hohe Werte für $t_1$ verhindern das Erkennen schwach ausgebildeter Kantenzüge
		- Niedrige Werte für $t_2$ verhindern unterbrochene Kantenzüge
		- Empfohlenes Verhältnis: $3:1$ bis $2:1$ zwischen $t_1$ und $t_2$

## Optimale Kanzenzüge

> *Situation:* Start- und Zielpunkt einer Kante sind bereits festgelegt (z.B. durch Nutzer)
> *Ziel:* Es soll ein optimaler Kantenzug gefunden werden, der diese Endpunkte verbindet

Dies kann mit dem [[Kürzeste Wege#Dijkstra-Algorithmus|Dijkstra-Algorithmus]] gelöst werden. Die Pfadkosten $c(k)$ pro Knoten $k$ sind hierbei die Abweichung vom Mittelwert der Gradienten $\nabla I(s)$ und $\nabla I(e)$ von Start- und Endpunkt $s$ und $e$: $$c(k)=|g(k)-g_\text{mod}|=|\nabla I(k) - \left(\frac{1}{2}\cdot(\,\left|\nabla I(s) + \nabla I(e)\right|\,)\right)$$

## Wasserscheidentransformation

Wir tun jetzt so, als sei das Bild eine Landschaft und die Höhe an einem Punkt ist die Intensität des entsprechenden Pixels.

Jetzt fluten wir das Bild, beginnend bei den niedrigsten Intensitäten. Wenn sich zwei verschiedene "Becken" treffen, hat man eine Wasserscheide gefunden. Diese definiert dann die Grenze unseres Segments.

![[WST.png]]

***Algorithmus:***
- Für jede Flutungshöhe $h_\text{aktuell} \in \set{0,\ldots,h_\text{max}}$:
	- Für jedes neu überflutete Pixel $p$ mit $h(p)=h_\text{aktuell}$:
		- $p$ ist isoliert:
			- vergebe neues Segmentlabel für $p$
		- $p$ hat Überflutungsregion erweitert: 
			- Übernehme Label der erweiterten Region
		- $p$ grenzt an zwei Überflutungsregionen an:
			- $p$ ist Wasserscheide


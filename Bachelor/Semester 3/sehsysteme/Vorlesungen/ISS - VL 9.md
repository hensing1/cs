Datum: 12.12.
[[ISS09_WS2324_Model-BasedSegmentation_231212-231211.pdf|Folien]]

[[ISS_WS2324_Aufgabenblatt09.pdf]]
[[Blatt 9]]
# Modellbasierte Segmentierung
Wir möchten ein Objekt in einem Bild finden.

Benötigt: Repräsentation eines Modells, welches eine gesuchte Klasse von Objekten beschreibt.

Dieses Modell wird auf Bilddaten angewandt, um ggf. Segmentierung und Objekterkennung zu kombinieren.

## Template Matching

> **Template**
> Muster, das das gesuchte Objekt in seiner Form und Orientierung beschreibt, nicht aber in seiner Position.

Das Template enthält:
- die gesuchte Struktur,
- den Hintergrund in unmittelbarer Nähe.

Gesucht: Verschiebe-Koordinaten für das Template, sodass die Übereinstimmung zwischen Template und Bild maximal bzw. ein Abstandsmaß minimal wird.
Jede mögliche Verschiebung wird einmal ausprobiert.
### Abstandsmaße

Sei $I(x,y)$ der Intensitätswert eines Bildpuntkes und $t(p,q)$ ein Bildpunkt im Template mit Größe $P \cdot Q$.

Seien $x_k,y_k$ die Koordinaten der Ecke oben links des betrachteten Bildausschnitts.

#### MSD und MAD

**Mean Square Distance**
Durchschnittlicher quadratischer Abstand
$$\text{msd}(x_{k},y_{k})=\frac{1}{PQ}\sum_{p=0}^{P-1}\sum_{q=0}^{Q-1}\left(I(x_{k}+p, y_{k}+q)-t(p,q)\right)^2$$

**Mean Absolute Distance**
Durchschnittlicher absoluter Abstand
$$\text{mad}(x_{k},y_{k})=\frac{1}{PQ}\sum_{p=0}^{P-1}\sum_{q=0}^{Q-1}\left|I(x_{k}+p, y_{k}+q)-t(p,q)\right|$$
*Vorteile:*
- Robust gegenüber Rauschen
*Nachteile:*
- Mäßige rotationsinvarianz: je größer der Rotationswinkel, desto schlechter das Resultat
- Nicht robust gegenüber Kontrastveränderungen oder Helligkeitsunterschieden $\Rightarrow$ Muster muss sehr gut an das Bild angepasst werden

#### Korrelationskoeffizient
besser


### Diskussion
- schlecht für Skalierung / Rotierung
- geht auch mit Gradientenbeträgen
- schlecht für 3D-Szenen

## Hough-Transformation

Man sucht nicht nach Mustern, sondern nach Kantenzügen.


Datum: 12.06.
[[Slides 07.pdf|Folien]]

# CNN-Architekturen

## AlexNet

8 Layer

## VGG

19 Layer

## ResNet

152 Layer

- Ab einem bestimmten Punkt bewirken mehr Conv. Layers einen höheren Trainingsfehler
	- Problem liegt nicht beim Problem selbst, sondern beim Optimierer

Verbindung, die Layer überspringt (*residual net*): Output wird draufaddiert
bringt Vorteile, wenn man Gradienten durch das Netzwerk durchpropagiert
Vermeidung von vanishing gradients

Ist aber trotzdem effizienter als VGG in Sachen Parameter und FLOPs für die Berechnung, weil am Ende die fully connected layer aus VGG fehlen (weniger Parameter) und am Anfang keine kleinen 3x3-Konvolutionen (weniger Speicher & FLOPs) -> weniger Auflösung
# CNN - Visualisierung und Analyse

Man verdeckt verschiedene Bereiche des Eingabebilds und schaut, wie das den Output beeinflusst.
Hat man einen Bereich gefunden, in dem die Ausgabe besonders stark beeinflusst wird, ist dies wahrscheinlich der Bereich in dem sich das gefundene Objekt befindet 

-> ineffizient

*Saliency Maps:*
Berechne Gradienten der Ausgabeklasse bezüglich des Eingabebilds


*Filter Visualisieren*
- Erste Layer: Kantendetektoren
- nächste Layer: Visualisierung funktioniert nicht mehr

*Gradient Ascent*
Wir überlegen uns, welchen (regularisierten, d.h. gültigen) Input wir brauchen, um die Aktivierung eines bestimmtes Neuron so hoch zu machen wie möglich

*Deep Dream*
Neuronen, die bei einem Bild schon stark aktiviert sind, werden mit Gradient Ascent noch höher gemacht -> Features im Eingabebild werden verstärkt

*Feature Inversion*
Wir versuchen, aus Aktivierungen von bestimmten Layern das Eingabebild wieder zu rekonstruieren

*Textursynthese*
Gram-Matrix?

Zufälliges Eingabebild, dann ist der Loss die Distanz zur Gram-Matrix der Eingabetextur


Features vom Content Image + Gram-Matrix vom Style Image -> *Style Transfer*

## Adversarial Attacks
Man muss Eingabebilder nur geringfügig Verändern, um beliebig falsche Vorhersagen des Netzwerks zu verursachen.

# Transfer Learning

- Wir nehmen ein trainiertes CNN, welches Features aus Bildern erkennen kann
- wir möchten das wiederverwenden für ähnliche Aufgaben
- Für das Training der neuen Aufgabe können wir mit den Gewichten des alten Netzes anfangen
- Um Overfitting bei kleinen Datensets zu vermeiden, kann man das Training auf die oberen Layer beschränken

Vortrainierte Modelle können runtergeladen werden von:
- Pytorch
- OpenMMLab
- HuggingFace
- Modelzoo
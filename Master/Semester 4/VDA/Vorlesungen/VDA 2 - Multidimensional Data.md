[[vda-02-Multidimensional-Data.pdf]]

"Multidimensional Data" := diskrete Datenpunkte mit jeweils $d$ Attributen.
$d$ ist die Dimensionalität der Daten.

Ein Attribut kann *kategorisch* (nominal, ordinal) oder *numerisch* (diskret, kontinuierlich) sein.

## Grundlegende Visualisierungstechniken
Mehrdimensionale Daten liegen üblicherweise als Tabelle vor.
Die Zeilen und Spalten dieser Tabelle kann man 1:1 visualisieren, z.B. weist man jeder Zelle eine Farbe zu.

**Two Tone Coloring**
- Darstellung eines numerischen Wertes mit Farbe
- Farbwerte *diskretisieren*
- Reine Farbe repräsentiert einen bestimmten Wert
- Wert dazwischen wird mit zweifarbigem Farbbalken dargestellt
	- Wert $0.75 \cdot a+0.25 \cdot b$ bekommt einen Balken, der 75% mit der Farbe von $a$ und 25% der Farbe von $b$ gefüllt ist
	
![[Two tone coloring.png|531]]

**Table Lens**
Fähigkeit, in eine bestimmte Zeile reinzuzoomen

### Kernel Density Estimation
Wir haben ein *Histogramm*, welches irgendeine Verteilung angibt (eine Probability Distribution Function (PDF)).
Eine Kernel Density Estimation (KDE) ist eine *geglättete Schätzung* der PDF.

Jeder Datenpunkt wird durch einen Kernel $K$ ersetzt, z.B. Gauss-Funktion (zentriert am Datenpunkt).
Die kontinuierliche Version ist die (normierte) Summe aus all diesen Kerneln:
$$f(x)=\frac{1}{n}\sum_{i}K(x-x_{i}).$$
Die Größe des Kernels ist ein Hyperparameter. Zu klein, und das Resultat ist sehr verrauscht - zu klein, und der Plot ist zu sehr geglättet.
"Scott's rule of thumb" für Gauss-Kernel $K(x)=\frac{1}{h\sqrt{ 2\pi }}\exp\left( -\frac{x^{2}}{2h^{2}} \right)$:  $h \approx 1.06 \frac{\hat{\sigma}}{\sqrt[5]{ n }}$

### Violin Plot
Kombination aus Boxplot und KDE - Boxplot ist senkrecht zur KDE

## Scatterplots
halt scatterplots

**Bubble Charts:** man kann die Punkte verschieden groß machen gemäß eines dritten Attributs; skalieren nach Fläche, nicht Radius

Gegen Overdraw: z.B. 2D-Histogramm

**Splatterplots:** überlappende Cluster einfärben / farblich umranden - in überlappenden Regionen Farben vermischen (z.B. alpha blending, oder in einheitlichem Farbraum mischen und ggf. Sättigung und Helligkeit reduzieren)
KDE geht auch in 2D

**Strip plots:** falls ein Attribut kategorisch ist - random jitter kann dabei helfen, overdraw zu vermeiden


**SPLOM:** bei $p$ Dimensionen, alle Kombinationen von 2 Dimensionen darstellen als Matrix (Scatterplot Matrix -> SPLOM)
- Attribute sortieren für bessere Lesbarkeit
- ähnliche Scatterplots nebeneinander; Ähnlichkeit mit Korrelationskoeffizienten nach Pearson messen
	- alle Möglichkeiten ggf. zu aufwändig - Heuristik mit zufälligem Vertauschen

**Generalized Pairs Plot:** wieder alle möglichen Paare in einer Matrix, aber jede Zelle ist ein Plot dessen Art am besten zu den beiden Datentypen passt


> *Distance Consistency*
> Maß dafür, wie gut die Cluster in einem Plot voneinander differenziert sind
> Definition: Prozentsatz aller Punkte, die näher an ihrem eigenen Clusterzentrum sind als an allen anderen Clusterzentren

> *Distribution Consistency*
> Wird geringer, wenn sich Cluster in Bereichen überlappen (wenn lokale Entropie hoch ist)

View Selection (Scatterplot selection) von Scatterplots aus einem SPLOM, die bestimmte Features aufweisen (z.B. Outlier, Monotonie, mit Clustern, etc.): *Scagnostics*

Man kann dann zwischen den verschiedenen Views der Daten im SPLOM animieren

## Parallele Koordinaten

Pro jede der $p$ Dimensionen:
- Eine vertikale Achse, äquidistant zu den anderen vertikalen Achsen
- Achse skaliert zum min/max-Intervall des entsprechenden Attributs

Ein einzelner Datenpunkt wird dargestellt, indem seine Attributswerte auf den jeweiligen Achsen mit den benachbarten Achsen verbunden werden
![[Parallel Coordinates.png]]

Attributswerte sind positiv korreliert: Linien schneiden sich nicht
Attributswerte sind negativ korreliert: Linien schneiden sich alle in einem Punkt

Die Achsen können interaktiv neu geordnet werden

"Brushing": Daten mit der Maus auswählen (z.B. in einem Scatterplot einen Kasten drum malen)
"Linking": Die Daten werden beim brushing automatisch in anderen Views, z.B. parallelen Koordinaten, gehighlighted

*Hierarchical Parallel Coordinates:* nur Cluster statt Datenpunkten in den parallelel Koordinaten darstellen, um Overdraw zu vermeiden
mit Band darstellen, wo der Mittelwert ist, wie weit die Daten gestreut sind und wie dicht der Cluster ist

### Radar Charts
Achsen in alle Richtungen von einem gemeinsamen Zentrum aus (in der Ebene)
Wie dieses Attributs-Spinnennetz in FIFA

Man kann ein glyph daraus machen, um einem Datenpunkt eine direkt wiedererkennbare Form zu geben

## Weitere

### Charnoff Faces
Idee: Menschen sind gut darin, Gesichter zu unterscheiden
-> jedem Attribut ein Gesichtsattribut zuweisen, um ein Glyph (Gesicht) für einen Datenpunkt zu erstellen
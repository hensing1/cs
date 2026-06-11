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

## Distribution Consistency
?


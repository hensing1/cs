[[iaan-06-Statistical-Testing.pdf]]

> **Null-Hypothese**
> Die Null-Hypothese $H_{0}$ ist das, was wir in einer Studie *widerlegen* wollen.

Wahre Null-Hypothese verwerfen (false positive): Typ I-Fehler
Falsche Null-Hypothese nicht verwerfen (false negative): Typ II-Fehler

Typ II-Fehler: passieren, wenn das statistische Modell nicht aussagekräftig genug ist

## p-Wert

Gibt die Wahrscheinlichkeit der Messwerte an, unter der Annahme, dass $H_{0}$ wahr ist: $$p = P(\text{Messwerte, die mindestens so extrem sind wie die Beobachtungen} \mid H_{0}\ \text{ist wahr}).$$
-> je kleiner das $p$, desto mehr sprechen die Daten gegen $H_{0}$.
Üblicherweise ist ein Ergebnis mit $p<0.05$ "signifikant".

Anders ausgedrückt: der p-Wert sagt, wie kompatibel die beobachteten Daten mit einem statistischen Modell (das der Nullhypothese) sind.

Beispiel: 
- $H_{0}$: "Münze ist fair"
- Evidenz: 4 von 16 Würfen ist sind Kopf

Unter $H_{0}$ wäre der Münzwurf eine Binomialverteilung, also:
![[p-Wert.png|500]]

Einseitiger p-Wert: W'keit für Extremwerte an einem Ende der Verteilung
Zweiseitiger p-Wert: W'keit für Extremwerte an beiden Enden

Im Münz-Fall: $p=2 \cdot 0.038 = 0.076$
Zweiseitiges p ist hier korrekt, weil wir nicht von einem Bias in eine bestimmte Richtung ausgegangen sind -> nicht signifikant

## t-Tests

Mit t-Tests testet man Hypothesen über Mittelwerte von [[Gauss-Funktion|Gaussverteilungen]].

### Single-Sample t-Test
- Wir haben eine Population, von der wir Stichproben ziehen
- Null-Hypothese $H_{0}$: der Mittelwert dieser Stichproben weicht *nicht* von einem bestimmten Wert ab (z.B. Mittelwert aus der Literatur)
- Alternativ-Hypothese $H_{A}$: Mittelwert weicht ab (bei einseitigem Test: z.B. Mittelwert ist höher)

**Algorithmus**
1. Berechne Abweichung von Stichproben-Mittelwert $\bar{x}$ zum Wert $\mu_{0}$ aus $H_{0}$:
   $$\mu_{0}-\bar{x}=\mu_{0}-\frac{\sum_{i=1}^{n}v_{i}}{n}$$
2. Berechne Varianz der Stichprobe: $$s ^{2}=\frac{1}{n-1}\sum_{i=1}^{n}(v_{i}-\bar{x})^{2}$$
3. Berechne Standard-Fehler von $\bar{x}$: $$a = \frac{s}{\sqrt{ n }}$$
4. Berechne *t-Wert*: $$t=\frac{\bar{x}-\mu_{0}}{a}$$
Warum $n-1$:
- genannt "Freiheitsgrade"
- Wenn man mir nur $n-1$ Datenpunkte gibt und den Mittelwert, kann ich den $n$-ten Wert einfach berechnen, er ist also redundant - wir müssen die Daten also so behandeln, als hätten wir nur $n-1$ Datenpunkte

*Auswertung:*
Je höher $|t|$, desto signifikanter das Ergebnis.
Wie machen wir daraus einen p-Wert?

-> wir nehmen an, dass $t$ (unter der Null-Hypothese, dh. wenn es keinen Effekt gibt), einer [[Studentsche t-Verteilung]] mit $\nu=n-1$ folgen müsste.
Die Grundannahme war ja, dass wir eine Gauß-Verteilung haben, aber wir kennen $\sigma_{0}$ ja nicht. Wir können $\sigma_{0}$ bloß schätzen, und zwar mit den Werten aus unserer Stichprobe.

Damit den p-Wert zu berechnen, ist nicht leicht - in der Praxis nimmt man dafür vorhandene Software oder nimmt Lookup-Tabellen.

### Two-Sample t-Test
Vielleicht kam der Literaturwert anders zustande als die eigenen Messungen?
-> wiederhole die Stichproben-entnahme, einmal mit Testpopulation, und einmal mit Kontrollpopulation

**Algorithmus**
1. Berechne Differenz zwischen den Mittelwerten der beiden Stichproben
2. Jetzt sind *beide* Mittelwerte mit Unsicherheit behaftet - wir gehen davon aus, dass beide Stichproben dieselbe Varianz haben. Mit Testgruppe $T$ und Kontrollgruppe $K$: berechne *pooled sample variance* (Durchschnitt der beiden Varianzen, gewichtet mit den Größen der Gruppen): $$s_{T,K}^{2}=\frac{(n_{T}-1)s_{T}^{2}+(n_{K}-1)s_{K}^{2}}{n_{T}+n_{K}-2}$$
3. Berechne Standard-Fehler von *Differenz* der Stichproben-Mittelwerte: $$a=s_{T,K}\sqrt{ \frac{n_{T}+n_{K}}{n_{T} \cdot n_{K}} }$$
4. Berechne t-Wert: $$t=\frac{\overline{x^{T}}-\overline{x^{K}}}{a}.$$
Die Studentsche t-Verteilung hat nun den Parameter $\nu=n_{T}+n_{K}-2$.

#### Welch-Test
Wenn wir davon ausgehen, dass die Varianzen der Testpopulation und der Kontrollpopulation *nicht* gleich sind, können wir $t$ und $\nu$ wie folgt berechnen:
![[Welch-Test.png]]

### Paired t-Test
Wenn die beiden Gruppen *nicht* unabhängig voneinander sind (z.B. vorher/nachher bei denselben Subjekten), geht der gewöhnliche two-sample t-Test nicht.
Stattdessen macht man einen single-sample t-Test mit der **Differenz** der zusammengehörenden Werte. Die kann man dann mit der erwarteten Differenz vergleichen.

> **Häufige Herangehensweise in Neuro Imaging**
> - Ein t-Wert *pro Voxel*, um Veränderungen im Gehirn zu visualisieren
> - White Matter wird z.B. auf Skelettstruktur reduziert
> - Stichwort **Statistical Parametric Mapping** (SPM)

## ANalysis Of VAriance (ANOVA)
Situation: 
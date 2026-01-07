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
2. Berechne Varianz der Stichprobe: $$\sigma ^{2}=\frac{1}{n-1}\sum_{i=1}^{n}(v_{i}-\bar{x})^{2}$$
3. Berechne Standard-Fehler von $\bar{x}$: $$a = \frac{\sigma}{\sqrt{ n }}$$
4. Berechne *t-Wert*: $$t=\frac{\bar{x}-\mu_{0}}{a}$$

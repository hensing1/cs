Datum: 24.04.
[Notizen aus der Vorlesung](https://ecampus.uni-bonn.de/goto_ecampus_file_3021974_download.html)
[Annotiertes Skript](https://ecampus.uni-bonn.de/goto_ecampus_file_3021973_download.html)

# Teilfolgen und der Satz von Bolzano-Weierstraß

![[Folgen#^56f523]]

![[Folgen#^04716a]]

Der Beweis für diesen Satz funktioniert so, dass man sich zunächst das Intervall anschaut, welches alle Folgeglieder aus $(a_n)$ enthält. 
Dieses Intervall teilt man nun in der Hälfte. Mindestens eine dieser beiden Hälften muss ebenfalls unendlich viele Folgeglieder enthalten. Das nächste Element der Teilfolge wird nun das erste Element, welches aus $(a_n)$ innerhalb von dieser Intervallhälfte liegt.
Da sich diese Intervalle immer weiter verkleinern, kann man den Satz der *Intervallschachtelung* anwenden: genau ein $a \in \mathbb{R}$ liegt in sämtlichen Intervallen, und da jedes Intervall unendlich viele Folgeglieder enthält, ist $a$ der Grenzwert dieser Teilfolge.

# Cauchy-Folgen

![[Folgen#^5ce5ef]]

Es ist leicht zu zeigen, dass eine Cauchy-Folge immer *beschränkt* ist:
- Wir wissen, dass es für ein beliebiges $\epsilon$ einen Punkt $n_0$ gibt, sodass danach alle Folgeglieder in den Bereich $\left[a_{n_{0}}-\epsilon,a_{n_{0}}+\epsilon\right]$ fallen.
- Da davor nur endlich viele Folgeglieder sind, muss die Folge beschränkt sein.

Da Cauchy-Folgen beschränkt sind, gilt für sie auch der *Satz von Bolzano-Weierstraß*. Jede Cauchy-Folge hat also eine konvergente Teilfolge.
Die Elemente dieser Teilfolge weichen also irgendwann nicht mehr als ein Wert $\epsilon$ von einem Grenzwert ab. Für dasselbe $\epsilon$ gibt es aber auch einen Punkt, ab dem alle Folgeglieder nicht mehr als $\epsilon$ von den Teilfolgegliedern abweichen.
Es weichen also alle Folgeglieder nicht mehr als $2 \epsilon$ von dem Grenzwert der Teilfolge ab. Da dies für beliebig kleine $\epsilon$ gilt, ist der Grenzwert der Teilfolge auch der Grenzwert der Cauchy-Folge.

Also gilt:
> Jede Cauchy-Folge in $\mathbb{R}$ ist konvergent.

Ebenfalls ist leicht zu zeigen:
> Jede konvergente Folge in $\mathbb{R}$ ist eine Cauchy-Folge.

Also gilt für alle Folgen in $\mathbb{R}$ die folgende Äquivalenz: $$(a_{n})\text{ ist konvergent} \iff (a_{n}) \text{ ist Cauchy-Folge.}$$

Das ist manchmal praktisch, da in der Definition der Cauchy-Folge der Grenzwert nicht auftaucht. Man kann also die Konvergenz mancher Folgen zeigen, auch wenn man nicht weiß, was der Grenzwert ist.

# Weitere Arten von Konvergenzen

## Konvergenz in komplexen Zahlenfolgen

> Eine Folge $(a_n)$ in $\mathbb{C}$ hat einen Grenzwert $a$, wenn für jedes $\epsilon>0$ ein $n_0$ existiert, sodass $|a_{n}-a|<\epsilon$ für alle $n \geq n_0$.

Alle Eigenschaften reller Zahlenfolgen, deren Beweise sich nur auf die Eigenschaften des Betrags beziehen (und nicht z.B. auf die Anordenbarkeit), gelten damit automatisch auch für $\mathbb{C}$.
Dazu gehören etwa die < Rechenregeln für Beträge >.

Den Satz der Intervallschachtelung kann man nicht mehr formulieren, da es keine Intervalle in $\mathbb{C}$ gibt. 
Der Satz von Bolzano-Weierstraß gilt immer noch, man muss ihn aber anders beweisen (der Beweis für $\mathbb{R}$ nutzte die Intervallschachtelung).

Komplexe Zahlenfolgen können nicht mehr nach oben oder nach unten beschränkt sein. Sie können jedoch allgemein beschränkt sein, da sich der Begriff der Beschränktheit lediglich auf den Betrag bezieht.

Die Definition einer Cauchy-Folge sieht in $\mathbb{C}$ genauso aus wie in $\mathbb{R}$.

> [!warning] Konvention in Ana
> In der Vorlesung Analysis wird das Symbol $\mathbb{K}$ als Platzhalter in Sätzen verwendet, die sowohl für $\mathbb{R}$ als auch für $\mathbb{C}$ gelten.

## Konvergenz in $\mathbb{R}^{r}$ und $\mathbb{C}^{r}$

> Eine Folge im Körper $\mathbb{K}^{r}$ ist eine Folge von $r$-Tupeln.
> Eine solche Folge konvergiert gegen ein Tupel $a=(a^{(1)},\ldots,a^{(r)})$, wenn jede *Komponentenfolge* $(a_{n}^{(i)})$ gegen $a^{(i)}$ konvergiert.

Eine Folge in $\mathbb{C}$ kann man auch als eine Folge in $\mathbb{R}^{2}$ auffassen. Sie ist genau dann eine *Cauchy-Folge*, wenn die Folge der rellen Komponenten und die der komplexen Komponenten jeweils eine Cauchy-Folge ist.

Ebenfalls gilt: konvergiert eine Folge $(a_n)$ gegen $a$, dann konvergiert $\bar{a_n}$ gegen $\bar{a}$.
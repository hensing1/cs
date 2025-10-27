# Übungsblatt 2
- Henning Lehmann - 50045776

## Aufgabe 1

- Für $\gamma=3$ erkennt man eine Verdunkelung des Bildes, da hohe Intensitätswerte auf einen größeren Intensitätsbereich gespreizt werden, wohingegen kleinere Intensitätswerte gestaucht werden. An der Grafik lässt sich ablesen, dass Werte von 0 bis 0,6 durch die Gammakorrektur auf einen Bereich von 0 bis ca. 0,2 abgebildet werden, und Werte von 0,8 bis 1 ca. die obere Hälfte der resultierenden Intensitäten einnehmen.
- Für $\gamma=1$ erhält man die Identitätsfunktion, das Bild bleibt also unverändert.
- Für $\gamma=0.3$ wird das Bild aufgehellt. Wie man an der Grafik sieht, liegt jeder Punkt der grünen Kurve oberhalb der Identitätsfunktion, d.h. jeder Intensitätswert wird durch die Funktion erhöht. Dies ist insbesondere für geringe Intensitäten der Fall: Ursprungswerte von 0 bis 0,2 decken nach der Korrektur einen Bereich von 0 bis ca. 0,6 ab.

## Aufgabe 3

### A
Mittelwertfilter:

| $1/3$ | $1/3$ | $1/3$ | 
| ----- | ----- | ----- |

Resultierende Pixel:

| 255 | 170 | 85  | 0   | 
| --- | --- | --- | --- |

### B
Binomialfilter der Ordnung 2:

| $1/4$ | $1/2$ | $1/4$ | 
| ----- | ----- | ----- |

Resultierende Pixel:

| 255 | 191 | 64  | 0   | 
| --- | --- | --- | --- |

### C
Durch das Binomialfilter erhält man eine bessere Kantenerhaltung, wie man daran erkennt, dass die Differenz zwischen den mittleren beiden Pixeln (zwischen denen im Originalbild die Kante verlief) im unteren Bild höher ist als im oberen Bild.

## Aufgabe 4

### A
Gauss-Filter: $$\frac{1}{1.80} \cdot\begin{bmatrix}2.6 \cdot 10^{-5} & 0.0068 & 2.6 \cdot 10^{-5} \\ 0.0068 & 1.77 & 0.0068 \\ 2.6 \cdot 10^{-5} & 0.0068 & 2.6 \cdot 10^{-5}\end{bmatrix}=\begin{bmatrix}1.47 \cdot 10^{-5} & 0.0038 & 1.47 \cdot 10^{-5} \\ 0.0038 & 0.98 & 0.0038 \\ 1.47 \cdot 10^{-5} & 0.0038 & 1.47 \cdot 10^{-5}\end{bmatrix}$$

### B
Zweidimensionales Filter: $\mathcal{O}(N \cdot w_\text{kernel} \cdot h_\text{kernel})$ Operationen,

separiertes Filter: $\mathcal{O}(N \cdot w_\text{kernel} + N \cdot h_\text{kernel})=\mathcal{O}(N \cdot (w_\text{kernel} + h_\text{kernel}))$ Operationen.

### C
Die Filtergröße wird in Abhängigkeit von $\sigma$ gewählt, damit genügend Pixel gesamplet werden, für welche die Gauß-Funktion noch hinreichend große Werte annimmt.
Wählt man die Filtergröße kleiner, also z.B. als $m=2\cdot\lceil 2 \cdot \sigma \rceil + 1$, so wird die Gauß-Funktion "abgeschnitten", und man erreicht durch das diskrete Gauß-Filter eine schlechtere Approximation der zugrundeliegenden Gauß-Funktion.


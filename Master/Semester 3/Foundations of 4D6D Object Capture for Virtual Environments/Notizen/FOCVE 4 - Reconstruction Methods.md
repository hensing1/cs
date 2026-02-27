[[FOCVE___04_Reconstruction_Methods.pdf]]
## Volumetric Fusion
Wir haben aus verschiedenen Richtungen vom selben Objekt *Depth Maps* gegeben und möchten diese gerne zusammensetzen.
Vereinfachende Annahme: wir haben bereits alle Daten im *globalen Koordinatensystem*, müssen also nicht mehr kalibrieren/registrieren.

Ansatz:
- Aus jeder Map $D_{i}$ eine Signed Distance Function $\text{sdf}_{i}$ berechnen
- Bestimme Gewichtungen $w_{i}$ anhand von Rauschen in den Sensordaten
- Berechne gewichtete Summe $$\text{SDF}(x)= \frac{\sum_{i}w_{i}(x)\text{sdf}_{i}(x)}{\sum_{i}w_{i}(x)}$$
Online-Update der SDF (damit wir nicht alle SDF's gleichzeitig speichern müssen):
$$\begin{align}
\text{SDF}_{n+1}&=\frac{W_{n}\text{SDF}_{n}+w_{n+1}\text{sdf}_{n+1}}{W_{n}+w_{n+1}} \\

W_{n+1}&=W_{n}+w_{n+1}
\end{align}$$

**Truncated SIgned Distance Fields**
Man will nicht das gesamte SDF speichern, u.a. damit die Rückseite eines Scans nicht mit der Vorderseite ggü. von einem anderen Scan interferiert.

$$\text{tsdf}(p)=\begin{cases}
\mu & \text{sdf}(p)>\mu \\
\text{sdf}(p) & \mu > \text{sdf}(p)>-\mu \\
\text{N/A} & -\mu > sdf(p)
\end{cases}$$

![[TSDF.png|600]]


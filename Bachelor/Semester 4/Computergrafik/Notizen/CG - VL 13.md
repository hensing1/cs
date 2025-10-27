Datum: 03.06.
[[cgintro-12-Lokale Beleuchtungsmodelle.pdf|Folien]] (bis S. 28)

# Lokale Beleuchtungsmodelle

> **Beleuchtungsmodell**
> Vorschrift zur Berechnung von Farb- und Helligkeitswerten von Punkten auf Objekten

> **Shading**
> Prozess der Zuordnung von Farb- und Helligkeitswerten

## Physik

### Raumwinkel

Bogenmaß (2D): $$\beta=\frac{b}{R}$$
- Auf Einheitskreis normierte Bogenlänge
- $0 \leq \beta \leq \tau$
- angegeben in $\text{rad}$ (dimensionslos).

**Raumwinkel** (3D): $$\omega=\frac{A}{R^{2}}$$
- Auf Einheitskugel normierte Kreisfläche
- Produkt zweier Bogenmaße (ein Winkel für Breite, einer für Höhe der Fläche)
- $0 \leq \omega \leq 2 \tau$
- angegeben in $\text{sr}$ (Steradian, auch dimensionslos)

Differenzieller Raumwinkel: $$d \omega = d \theta(\sin(\theta)d \phi)$$
$\phi$ ist der horizontale Winkel (Breitengrad). Dessen Einfluss nimmt ab, je näher man zum Pol kommt (je näher $\theta$ an 90° ist).

Sei eine Fläche mit Inhalt $A$ im Raum gegeben, welche man auf eine Einheitskugel projizieren und ihren Raumwinkel bzgl. dieser Kugel bestimmen möchte.

Der Abstand zur Kugel sei $R$ und die Neigung zur Kugeloberfläche $\alpha$.

Raumwinkel verringert sich quadratisch mit Abstand und proportional zur Neigung: $$d \omega = dA \frac{\cos(\alpha)}{R^{2}}$$
Umgekehrt: $$dA = \frac{R^{2}}{\cos(\alpha)}\sin(\theta)d \theta d \phi$$
Der durch $A$ abgedeckte Raumwinkel ist dann: $$\int _{A} \frac{\cos(\alpha)}{R^{2}}dA.$$
### Radiometrische Größen

- Strahlungsenergie: $Q_{e}$ (Joule)
- Strahlungsenergiedichte (Strahlungsenergie pro Einheitsvolumen): $U_{e}= \frac{dQ_{e}}{dV}$ (Joule pro Kubikmeter)
- Strahlungsleistung: $\Phi_{e}=\frac{dQ_{e}}{dt}$ (Joule pro Zeit, Watt)

Die Strahlungsleistung ist proportional zur Anzahl der Photonen, die pro Zeiteinheit durch eine Oberfläche fließen.
Die Energie eines Photons ist invers proportional zur seiner Wellenlänge $\lambda$.

Wir interessieren uns für die Strahlungsleistung, denn diese bestimmt die Helligkeit.

Kommen alle Photonen aus derselben Richtung, ist die Strahlungsleistung, die auf eine Fläche trifft, proportional zum Cosinus des Winkels zwischen Flächennormale und Lichtrichtung (*Lambert'scher Cosinus-Term*).

Somit definiert sich die *Helligkeit* eines Punktes $x$ *in Richtung* $\Omega$ als **Strahldichte (Radiance)**:
$$L_{e}(x,\omega) = \frac{d^{2}\Phi_{e}(x, dA, \Omega, d \omega)}{\cos(\theta)dAd \omega}$$
Die Einheit ist Watt pro Steradian und pro Quadratmeter.

Integriert man die Radianz über die Fläche $A$, erhält man die **Intensität** $I_{e} = \frac{d \Phi_{e}}{d \omega}$, gemessen in Watt pro Steradian (Strahlungsleistung pro Einheits-Raumwinkel).

Die **Irradianz** ist die Strahlungsleistung, die *pro Fläche empfangen* wird (Watt pro Quadratmeter): $E_{e}=\frac{d \Phi_{e}}{dA}$.

Die **Radiocity** $M_e$ ist die Strahlungsleistung, die *pro Fläche gesendet* wird (selbe Einheit wie Irradianz).

![[Radiometrie.png]]

### Lichtquellen

> **Grundgesetz der Strahlungsübertragung**
> Wie wird die von einem Flächenelement $dA_{1}$ abgegebene Strahlungsleistung von einem anderen Flächenelement $d A_{2}$ im Abstand $R$ aufgenommen?
> $$d^{2}\Phi_{e,1\to2}=L_{e1}(\Omega_{12})\frac{cos(\theta_{1})\cos(\theta_{2})}{R^{2}}dA_{1}dA_{2}$$

- Energieerhaltung: die Strahldichte ändert sich auf dem Weg der Lichtausbreitung nicht
- $d^{2}\Phi_{e,1\to2}=d^{2}\Phi_{e,2\to1}$

#### Punktlichtquelle
Unendlich kleiner Punkt, der in alle Richtungen gleichermaßen abstrahlt (isotrop)
Parameter:
- Lichtstärke: $I(\lambda)$
- Strahldichte fällt mit Abstand $r$: $L_{i}=\frac{I(\lambda)}{r^2}$

#### Richtungslichtquelle
Lichtstrahlen verlaufen parallel, Intensität konstant unabhängig von der Distanz
Parameter:
- Ausbreitungsrichtung $V$
- Strahldichte $L_i(\lambda)$

Weit entfernte Lichtquellen, wie z.B. die Sonne, werden so modelliert

#### Lambertscher Flächenstrahler
Ein lambertscher Flächenstrahler ist eine ideal diffus abstrahlende Fläche.

Die *Intensität* nimmt proportional zum Cosinus des Betrachtungswinkels ab: $$I(\theta,\lambda) = L(\lambda) \cdot \cos(\theta)$$
Da aber der Raumwinkel der Fläche ebenfalls mit dem Cosinus abnimmt, bleibt die *Strahldichte* (die Helligkeit) konstant und unabhängig vom Betrachtungswinkel.

#### Spotlight
Lichtausbreitung ist durch einen Lichtkegel beschränkt, z.B.: $$I(\theta,\lambda) = I_{0}(\lambda) \cdot \cos(\theta)^{n}$$
Je größer das $n$, desto schmaler der Lichtkegel.

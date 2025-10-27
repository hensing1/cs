Datum: 06.12.
[[17VL-Scan-Kombinatorik-Urnen.pdf|Folien]]

# Urnenmodell
## Ziehungsmöglichkeiten
![[Abzählende Kombinatorik#Urnenmodell#Details]]

## Zusammenfassend
![[Abzählende Kombinatorik#Urnenmodell#Berechnung]]

## Zum Beispiel
Im Lotto (6 aus 49) gibt es $\binom{49}{6} \approx 14 \text{ Mio.}$ mögliche verschiedene Ziehungen (alle gleich wahrscheinlich).

Wahrscheinlichkeit für 6 richtige: $1/\binom{49}{6}$
Wahrscheinlichkeit für 4 richtige:
- Anzahl Möglichkeiten, vier aus sechs richtigen auszuwählen: $\binom{6}{4}$
- Anzahl Möglichkeiten, zwei aus 43 falschen auszuwählen: $\binom{43}{2}$
- $\rightarrow \binom{6}{4} \cdot \binom{43}{2}$ positive Ereignisse
$\Rightarrow P(\text{4 richtig})= \Large \frac{\binom{6}{4} \cdot \binom{43}{2}}{\binom{49}{6}} \normalsize \approx 0,0009$
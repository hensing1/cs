# Wichtige Begriffe
## Paritäts-Bit
> Extra-Bit, meist am Anfang eines Codeworts.
> Wird so gewählt, dass die Summe der Einsen im Code entweder immer gerade (*even parity*) oder immer ungerade (*odd parity*) ist.
> Ein-Bit-Fehler können auf diese Weise erkannt (aber nicht korrigiert) werden.


## Hamming-Distanz

> Die *Hamming-Distanz* zwischen zwei Codewörtern ist die Anzahl der Stellen, an welchen die jeweiligen Bits unterschiedlich sind. 
> Die *Code-Distanz* eines Codes ist die geringste Hamming-Distanz zwischen zwei Codewörtern.

# Grundlagen
Hat ein Code eine Code-Distanz d, dann können bis zu d-1 Bitfehler erkannt und bis zu $\lfloor(d-1)/2\rfloor$ Bitfehler korrigiert werden.
![[Fehlerkorrektur.png]]

# Arten von Codes
## Gray-Code
Code, bei dem von einem Codewort zum nächsten sich nur ein einziges Bit ändert. 
Das hat den Vorteil, dass sich der codierte Wert nicht besonders viel ändert, wenn ein Bit kippt (im Gegensatz zur normalen Binärdarstellung, wo ein Bit-Flip die Veränderung $2^n$ bewirkt).

## 1-aus-n-Code
Code, bei dem nur ein Bit 1 und alle anderen 0 sind. Ziemlich ineffizient und nur eine Code-Distanz von 2, wird aber trotzdem bei Adresskodierern und Multiplexern verwendet.

## Codes für bestimmte technische Anforderungen
### Häufige Signalwechsel
Wenn man einen Anwendungskontext hat, bei dem es wichtig ist, das Taktsignal wiederherzustellen, ist ein Code hilfreich bei dem so oft wie möglich das Bit wechselt.

### Gleichverteilung von Einsen und Nullen
Diese Codes sind hilfreich, um eine konstante mittlere Spannung zu halten.

Beispiele für sowas finden sich in PCI Express, SATA, Gigabit Ethernet, DVI, HDMI, uvm.
Hierbei werden dann 8-Bit-Codes auf 10 Bit erweitert, um bestimmte Regeln zu erfüllen ("8b/10b Code").
[[iaan-03-Magnetic-Resonance-Imaging.pdf]]

- since 1970's

Was wir nicht machen sind CT (Computertomographie), das funktioniert mit x-ray und ist für Knochen

*T1/T2 Gewichtung:*
Verschiedener Kontrast
T1: Struktur
T2: Lesions besser sichtbar

## Wer wie was

- Wassermolekül ist in quantum-superposition von zwei Spins (parallel oder antiparallel)
	- Phase: Position entlang Kreis um Vektor vom extrinsischen Magnetfeld(?) 
	- Weniger Energie: paralleler Spin
	- Mehr Energie: antiparalleler Spin
	- -> mehr Moleküle im parallelen Spin
		- genaues Verhältnis: hängt von Temperatur ab, sehr nah an 1, aber eben nicht ganz
		- Kleine Differenz ist der Grund dafür, dass die Magneten im MRI so stark sein müssen
	- Richtung des Spins prozessiert um externen Magnetvektor herum wie Gyroskop
	- Phasen sind insgesamt random
	- -> Alle Spinvektoren aufsummiert zeigen in Richtung externen Magnetvektor, weil sich Spin-Phasen aufheben
- müssen "excited" werden, um in den antiparallelen Zustand zu kommen
- Drehen des externen Magnetfelds (90° RF-Puls)
- Summe der Spinvektoren prozessiert dann auch

Spinvektoren brauchen eine gewisse Zeit, um sich (prozessierenderweise) an das gedrehte Magnetfeld auszurichten
Die Zeit, die das benötigt, heißt relaxation time

> Verschiedene Gewebearten haben andere T1- und T2- relaxation times

Absolute und relative Differenzen der relaxation times wird größer, je mehr Tesla man hat

*Wie misst man diese Signale?*
Der rotierende Summenvektor erzeugt selbst eine elektrische Spannung in den umgebenden Spulen

### Echo

Wir haben irgendeinen natürlich auftretenden Decay der Phase coherence, den wir nicht umkehren können
Wir haben aber auch extra-decay wegen Inhomogenitäten im Magnetfeld, den wir umkehren können 

- 180° - gedrehter Puls in Larmor-Frequenz am Zeitpunkt $\tau$, der das Signal (abgeschwächt) am Zeitpunkt $2\tau$ zurückkehren lässt

Dauert aber lange -> mache extra Gradient ins Magnetfeld (*Gradient Recalled Echo*): geht schneller, man braucht weniger Energie und es muss nicht genau 180° sein, aber wir verlieren das Signal schneller


Datum: 12.01.
[[TI_06_Register_Transfer_Entwurf.pdf|Folien]] (Seiten 1 bis 19)

# Register-Transfer-Entwurf
## Register-Transfer-Ebene
Die Register-Transfer-Ebene ist eine Abstraktionsstufe weiter oben als die Gatterebene. Man betrachtet also
- Datenworte statt einzelner Bits
- Register statt einzelner Flip-Flops
- Funktionseinheiten (wie Multiplexer, Register, ALUs etc.) statt einzelner Gatter

Man nennt das Register-Transfer-Ebene, weil Daten in jedem Takt von Register zu Register geschoben (und evtl. zwischendurch modifiziert) werden.

### Blockschaltbilder
Im Schaltbild hat man seine Funktionseinheiten abgebildet. Verbindungen (Datenpfade) zwischen den Einheiten können mehrere parallele Datenleitungen repräsentieren.

Typische abgebildete Bestandteile:
- Register
	- Bezeichnung "E" für Abspeicherung von Eingabewerten, "A" entsprechend für Ausgabewerte
- Funktionale Einheiten
	- Schaltnetze, wie z.B. Addierer
- Multiplexer
- Steuerleitungen
	- zur Steuerung von Multiplexern, Registern und funktionalen Einheiten

Manchmal werden Multiplexer auch weggelassen, dann gehen z.B. zwei Datenpfade in einen Register (der Multiplexer wird impliziert).

### Aufteilung in Steuer- und Rechenwerk
Man teilt Schaltwerke in Steuer- und Rechenwerke auf, um die Komplexität zu reduzieren und ggf. parallelisierte Entwicklung zu erlauben.
#### Rechenwerk
Auch genannt: Datenpfad, Operationswerk

Verarbeitet Eingangsdaten zu Ausgangsdaten. Wird über das Steuerwerk mittels Steuervariablen gesteuert und gibt ggf. Statusvariablen wieder zurück (wie z.B. Carry-Bit zur Signalisierung eines Überlaufs).

#### Steuerwerk
Erzeugt Steuersignale für den Datenpfad. 
Erhält als Input Statusvariablen und ggf. externe Steuersignale, z.B. zur Auswahl einer Operation im Datenpfad.

### Beispiel: Multiplizierer
Wir besprechen einen beispielhaften Multiplizierer, welcher zwei 4-Bit-Zahlen mithilfe eines 2-Bit-Multiplizierer miteinander Multipliziert.

Man teilt die Berechnung in mehrere Teilschritte.
Sei $A=4 \cdot A_H+A_L$ und $B=4 \cdot B_H + B_L$. Dann berechnen wir $A \cdot B$ wie folgt:
- Berechne $A_H \cdot B_H$
- Shifte um 2 nach links
- Addiere $A_H \cdot B_L$
- Addiere $A_L \cdot B_H$
- Shifte um 2 nach links
- Addiere $A_L \cdot B_L$
Man berechnet also $((A_HB_H)2^2+A_HB_L+A_LB_H)2^2+A_LB_L$ - entsprechend dem 
*Horner-Schema*: $ax^{3}+bx^{2}+cx+d=((ax+b)x+c)x+d$

Der Datenpfad dafür sieht dann so aus:
![[Multiplizierer_Datenpfad.png|250]]

Das Steuerwerk muss dann immer in der richtigen Reihenfolge laden, shiften und akkumulieren und durchläuft immer zyklisch 6 Zustände (für die 6 Rechenschritte von oben).

Um dieses Steuerwerk umzusetzen, macht man zuerst eine Wahrheitstabelle. Die hat dann links drei Zustandsbits (um die 6 Zustände zu kodieren), und rechts die vier Ausgangsbits für die Steuerung vom Datenpfad oben.
Dafür kann man dann mit KV-Diagrammen / Quine-McCluskey eine Schaltfunktion für jeden Ausgang berechnen.

Wenn man das resultierende Schaltnetz dann an einen Modulo-6-Zähler stöpselt, hat man sein Steuerwerk.

Falls man keinen Modulo-6-Zähler haben möchte, kann man das Steuerwerk auch als Moore-Automaten modellieren: dabei wird der nächste Zustand dann direkt durch das Schaltnetz, anstatt durch den Modulo-6-Zähler berechnet. Gespeichert wird der Zustand wie gehabt in einem Register.
Datum: 24.01.
[[TI_07_Mikroprozessortechnik.pdf|Folien]] (ab Seite 16)

# Einfacher Modellprozessor
*Spezifikationen:*
- Registerbreite (Länge der Datenworte): 4 Bit
- Breite d. Adressbus: 4 Bit
	- Programm kann also nur aus maximal 16 Befehlen bestehen
- Maschinenbefehl besteht aus 8 Bit:
	- 4-Bit-Operand (höherwertige Bits)
	- 4-Bit Opcode (niederwertige Bits)
- Kein I/O
- Befehl laden mit steigender Taktflanke (Fetch in erster Takthälfte)
- Ergebnis schreiben mit fallender Taktflanke (Decode, Execute & Write in zweiter Takthälfte)
- Datenpfad: nur ein einzelner Akkumulator

## Befehlssatz
| **Nr**  | **Befehl**    | **Beschreibung**                                                    |
| --- | --------- | --------------------------------------------------------------- |
| 0   | `NOP`     | No Operation (Wartezyklus)                                      |
|     |           | *Laden und Speichern*                                         |
| 1   | `LDA #n`  | Lädt Akkumulator mit Wert `n`                                   |
| 2   | `LDA (n)` | Lädt Akkumulator mit Inhalt der Speicherstelle `n`              |
| 3   | `STA n`   | Speichert den Akkumulatorinhalt in die Speicherstelle `n`       |
|     |           | *Arithmetik*                                                  |
| 4   | `ADD #n`  | Addiert `n` auf den Akkumulator                                 |
| 5   | `ADD (n)` | Addiert Inhalt der Speicherstelle `n` auf den Akkumulator       |
| 6   | `SUB #n`  | Subtrahiert `n` vom Akkumulator                                 |
| 7   | `SUB (n)` | Subtrahiert Inhalt der Speicherstelle `n` vom Akkumulator       |
|     |           | *Sprungbefehle*                                               |
| 8   | `JMP n`   | Setzt Instruktionszähler auf Wert `n`                           |
| 9   | `BRZ #n`  | Addiert `n` auf Instruktionszähler, falls Zero-Bit gesetzt      |
| 10  | `BRC #n`  | Addiert `n` auf Instruktionszähler, falls Carry-Bit gesetzt     |
| 11  | `BRN #n`  | Addiert `n` auf Instruktionszähler, falls Negations-Bit gesetzt |

## Aufbau
![[Modellprozessor.png|600]]

*Instruktionszähler:*
- Enthält einen eigenen Addierer, damit man relative Sprünge machen kann
- Steuersignale für relativen Sprung, absoluten Sprung, Inkrementierung und Reset
- Ausführung mit negativer Taktphase (Beginn der Fetch-Phase)

*RAM:*
- Enthält:
	- Programm (Daten- und Befehlsram)
	- Programmparameter (Datenram)
	- Zwischen- und Endergebnisse (Datenram)
- Asynchrones Lesen: sobald Adresse anliegt, erscheint Inhalt auf Lese-Datenbus
- Synchrones Schreiben: ist `we` (write enable) aktiv, wird mit negativen Taktflanke geschrieben

*Instruktions- und Datenregister:*
- Mit der positiven Taktflanke wird Inhalt aus RAM übernommen

*Instruktionsdecoder:*
- Macht aus Opcode einen 1-aus-n-Code
- Braucht man eigentlich nicht

*Statusregister:*
- Speichert die Statusbits vom Akkumulator mit der positiven Taktflanke (Anfang der Decode-Phase)

*Steuerwerk:*
- Kriegt den Op-Code als Input und hat als Output die Steuersignale für den Rest des Prozessors

*Akkumulator:*
- Akkumuliert mit der negativen Taktflanke (Ende der Write-Phase)
- Erhält als Input entweder den Inhalt des Datenregisters (*immediate address*), oder den Inhalt einer Speicheradresse (*direct address*):
  ![[Immediate vs direct address.png]]

Bei diesem Prozessor dauert jeder Befehl einen Takt. Es gibt auch Prozessoren, bei denen es Multi-Takt-Befehle gibt, d.h. man braucht ein Schaltwerk als Steuerwerk.
In diesem Beispiel braucht man prinzipiell nur ein Schaltnetz dafür - mit dem Unterschied, dass das Taktsignal auch ein Input für dieses Schaltnetz ist (was man ja eigentlich nicht macht), weil die Steuersignale bei der negativen Taktphase anders aussehen als in der positiven Taktphase.[^1]
Wenn einem das nicht gefällt, kann man auch die Taktung doppelt so schnell machen. Dann sind nur positive Taktflanken relevant, und die Bearbeitung eines Befehls benötigt zwei Takte. Im Steuerwerk muss man sich dann mit einem Zustandsbit merken, in welcher Bearbeitungsphase man gerade ist (z.B. mit T-Flip-Flop).

[^1]: Das ist prinzipiell nicht ok, aber in diesem Fall wird ja kein neues Taktsignal damit erzeugt, deshalb kommt man damit davon

## Beispielprogramm

Folgendes Programm multipliziert die Werte der Speicherstellen 13 und 14 und schreibt das Ergebnis in die Speicherstelle 15:
```asm
0 init:  LDA #0
1 begin: STA (15)
2        LDA (13)
3        BRZ #6    // end:
4        SUB #1
5        STA (13)
6        LDA (15)
7        ADD (14)
8        JMP 1     // begin:
9 end:   JMP 9
```

## Berechenbarkeitstheorie
Prinzipiell kann jede berechenbare Funktion mit diesem Befehlssatz beschrieben werden werden. 
Der Hauptspeicher ist allerdings für die allermeisten Anwendungen zu klein, und selbst einfache Berechnungen können sehr aufwändig werden (s.o.). 
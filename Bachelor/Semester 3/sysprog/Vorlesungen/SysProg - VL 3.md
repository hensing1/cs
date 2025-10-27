Datum: 31.10.
[[Kapitel_1.0_Maschinenprogrammierung_WS2324_v1023_Teil2.pdf|Folien zu Assembly]] (ab S. 14)
[[Kapitel_1.1_Ergaenzung-Speicherverwaltung_WS2324_v1023.pdf|Folien zu malloc und free]]
# Assembly

## Adressformate

Vgl. [[SysInf - VL 2#Adressierung]]

**3-Adress-Format**
$\rho(a) := \rho(b) \,\text{op} \,\rho(c)$
Gibt es bei x86 nicht, außer bei einer speziellen Variante von `imul` seit 80186-Prozessoren.

**2-Adress-Format**
*Implizierung:* $\alpha := \rho(a) \,\text{op}\, \rho(b)$ $\to$ gibt es nicht
*Überdeckung:* $\rho(a) := \rho(a) \,\text{op}\,\rho(b)$ $\to$ gibt es teilweise

**1-Adress-Format**
Die meisten Operationen verwenden das 1-Adress-Format.

- Bei `add dest, source` (Dest := Dest + Source) können die Operanden beliebige Register, Speicherzellen oder Konstanten sein, es darf jedoch nicht mehr als ein Speicherzugriff erfolgen (`add [a], [b]` geht also nicht).
- Dasselbe gilt für `sub`

## Operationen

- `rax` ist der Akkumulator (das $\alpha$ in $\alpha$-Notation)
- `mul Op` multipliziert den Akkumulatorinhalt mit dem Operanden `Op`
	- Bei Overflow: extra-Bits kommen in `rdx`, Statusflags O und C werden gesetzt
- Bei `div Op` setzt sich der Dividend aus mehreren Registern zusammen und wird durch `Op` geteilt:
	- Verwendete Register sind abhängig von Größe von Operand:
		- byte: Dividend ist `ax`, Ergebnis in `al`, Rest in `ah`
		- word: Dividend ist `dx:ax`[^1], Ergebnis in `ax`, Rest in `dx`
		- long: Dividend ist `edx:eax`, Ergebnis in `eax`, Rest in `edx`
		- quad: Dividend ist `rdx:rax`, Ergebnis in `rax`, Rest in `rdx`
	- Ist das Ergebnis zu groß, um ins Ergebnisregister zu passen, *stürzt das Programm ab*. Dasselbe passiert bei Teilen durch 0.

[^1]: Obere 16 Bits in `dx`, untere 16 Bits in `ax`

Wir gucken uns kurz [[ARM]] an.

# Speicherverwaltung mit malloc und free

- `malloc(BUFFER_SIZE)` allokiert Speicher auf dem Heap
	- Mengenangabe in Byte
	- Rückgabe: Zeiger wenn erfolgreich, `NULL` wenn nicht erfolgreich
- `free(void* buffer)` gibt ihn wieder frei

Wie arbeiten die intern?
-> ist nicht festgelegt

## Beispielimplementation

- Man hat einen großen Speicherbereich
- Der Speicherbereich wird in Blöcke geteilt
- Jeder Block hat einen Header. Inhalt:
	- Größe des freien Speicherblocks
	- Zeiger auf den nächsten freien Block
- letzter Block verweist auf den ersten block
- Am Anfang ist der Speicherbereich nur ein einziger Block, dessen Header auf sich selbst zeigt
- `malloc` sucht nach dem ersten Block, der groß genug ist
	- Falls der Block größer ist als benötigt, wird der neue Block hinten in den freien Block eingefügt. Die Größe des freien Blocks wird in dessen Header angepasst. Zeiger müssen keine umgebogen werden.
	- Falls der Block genau passt, muss der Zeiger vom Vorgängerblock auf den Nachfolgeblock geändert werden
- `free(p)` fügt nur den zu `p` gehörenden Block in die zyklisch verkettete Liste ein


Unter Linux gibt es den Speicher-Debugger `valgrind`, mit welchem man Speicherlecks finden und Tipps bekommen kann.
Der `clang`-Kompiler stellt den Address-Sanitizer ASAN zur Verfügung.
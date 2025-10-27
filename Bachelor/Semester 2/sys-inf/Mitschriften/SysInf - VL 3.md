Datum: 25.04.
[[SysInf_Kap_1_Teil_2_230311_1928.pdf|Folien]]

Wir haben uns letztes mal den Java Bytecode angeschaut. Der ist RISC.

Exkurs: Intels x86-Befehlssatz
[Intel 64 and IA-32 Architechtures Software Developer Manuals](https://intel.com/content/www/us/en/developer/articles/technical/intel-sdm.html)

*Kapitel  1.3.4*
# Adressierung
## Direkte Adressierung
Die Adresse ist direkt im Befehlswort. Also:

| Op-Code | Adresse |
| ------- | ------- |

- Vorteil: Schneller Zugriff
- Nachteile:
	- Eingeschränkter Adressraum
	- Keine Verschiebung der Daten
	- Keine Modifikation von Adressen

### Basisregister und Displacement
Adresse wird aufgeteilt in Basisadresse und relative Distanz (Displacement): 

| Op-Code | Adresse des Basisregisters | Displacement | 
| ------- | -------------------------- | ------------ |

Die tatsächlich im Befehl kodierte Adresse ist die Summe aus dem Wert im Basisregister und dem Displacement.
Wird nun der Programmcode im Hauptspeicher verschoben (z.B. durch das Betriebssystem), dann muss nur das Basisregister aktualisiert werden.
Nun hängt die Größe des Adressraums nur noch von der Länge des Basisregisters ab, wodurch man den Adressraum sehr groß machen kann.

### Adressierung mit Indexregister

Nachteil des Basisregisters: man kann immer noch nicht zur Laufzeit Adressänderungen durchführen, z.B. um über nacheinander im Speicher liegende Daten zu iterieren. Das liegt daran, dass der Inhalt des Basisregisters vom Betriebssystem kontrolliert wird und nicht vom Programm.

Lösung: zusätzliche additive Komponente (Indexregister).

| Op-Code | Adresse des Indexregisters | Adresse (ggf. relative Adresse mit Basisregister) |
| ------- | -------------------------- | ------------------------------------------------- |

Auf das Indexregister kann man ganz normal im Programmcode zugreifen.
In $\alpha$-Notation: $\gamma$ ist der Inhalt des Indexregisters und $\rho(\gamma)$ der Inhalt der Speicherzelle, auf die das Indexregister zeigt.

### Indirekte Adressierung
Interpretierung des Wertes an einer Adresse als eigene Adresse (analog zu Pointern in C).

$\alpha$-Notation: $\alpha := \rho(\rho(i));$  $\rho(\rho(i)) := a;$  $\alpha:= \alpha \text{ op } \rho(\rho(i));$


*Kapitel 1.3.5*
# Unterprogramme
## Grundlagen
Damit ein Unterprogramm (d.h. Methode/Funktion) realisiert werden kann, muss folgendes gewährleistet sein:
- Beim Aufruf muss die Rücksprungadresse irgendwo hingesichert werden
- Das Unterprogramm muss wissen, wo die Rücksprungadresse zu finden ist

Auch die Übergabe von Parametern muss in geregelter Form erfolgen.

## Einstufige Unterprogramme
Ein spezielles Register (nennen wir es $\delta$) wird für die Rücksprungadresse verwendet.

Damit kann genau ein Unterprogramm gleichzeitig aufgerufen werden, da sonst $\delta$ überschrieben und die ursprüngliche Rücksprungadresse zerstört wird.

## Mehrstufige Unterprogramme (ohne Rekursion)
Ein Unterprogramm beginnt mit einer Leerzelle, in die beim Aufruf die Rücksprungadresse geschrieben wird.

Startet ein Unterprogramm an der Speicherzelle $j$ und soll zurück an die Rücksprungadresse $k$ springen, wird am Anfang $\rho(j) := k$ gesetzt. 
Das Keyword $\text{return}$ hätte an dieser Stelle die Wirkung $\text{goto } \rho(j)$.

Hierdurch sind mehrere Unterprogramme aufrufbar, inklusive Verschachtelungen.
Ein Unterprogramm kann aber nicht mehr als einmal gleichzeitig aufgerufen werden, da nur eine Speicherzelle für die Rücksprungadresse verfügbar ist. Insbesondere ist keine Rekursion möglich.
# Side Channel Attacks

> [!abstract] Definition *Side Channel*
> **Physikalische Informationen**, die von einem System ungewollt preisgegeben werden und die von einem *meist passiven Angreifer* abgegriffen werden können.
> Sie können inhärent zum System sein oder induziert werden.

Side-channel attacks sind normalerweise passiv und nicht-invasiv.

> [!abstract] Definition *Covert Channel*
> **Kommunikationskanal**, über den Informationen über ein System abgegriffen werden. 
> Ein Covert Channel benötigt einen *aktiven Angreifer*.

Ein Side Channel kann oft als Baustein für einen Covert Channel verwendet werden.


*Einfache Beispiele*
- Tippgeräusche einer Tastatur (jede Taste hat einen leicht unterschiedlichen Klang)
- Fingerabdrücke

**Verschiedene Level:**
- Nur eine Messung
- Korrelierung zwischen mehreren Messungen (differenzielle Analyse)
- Kombinierung mehrerer Side-channels
- Kombinierung mit theoretischer Kryptoanalyse

**Gegenmaßnahmen**
- TEMPEST-Zertifizierung (NSA & NATO)
- Randomisierung der Timings und Befehlsausführungen
- Generierung von Rauschen

## Side Channels von außerhalb
### RSA

#timing-attack

Um mit [[RSA]] eine Nachricht $m$ zu signieren, berechnet man mit
- private key $d$
- $n=p \cdot q$
- $p$, $q$ Primzahlen

den Wert
$$
m^{d} \mod n
$$
mit dem *Square-and-Multiply*-Algorithmus ([binäre Exponentation](https://de.wikipedia.org/wiki/Bin%C3%A4re_Exponentiation)): 

> $y \leftarrow 1,\,s \leftarrow m$
> **for** bits $d_{0},\dots,d_{k}$ of $d$:
> > **if** $d_{i}=1$:
> > > $y \leftarrow y \cdot s \mod n$
> > $s \leftarrow s^2 \mod n$
> **return** $y$

Die Laufzeit $T$ dieses Algorithmus ist abhängig von der Anzahl der 1-Bits in $d$.

Nun kann man irgendwie die ersten $b$ bits von $d$ raten, daraus die erwartete Laufzeit errechnen und diese von $T$ abziehen. Ein korrekter Tipp verringert die Varianz über mehrere Samples.

Hat man genug Samples, kann man durch diesen Angriff den kompletten Private key herausfinden.

*Mögliche Gegenmaßnahme:*[^1]
> $y \leftarrow 1,\,s \leftarrow m$
> **for** bits $d_{0},\dots,d_{k}$ of $d$:
> > **$z \leftarrow y$**
> > **if** $d_{i}=1$:
> > > $y \leftarrow y \cdot s \mod n$
> > 
> > **else:**
> > > $z \leftarrow y \cdot s \mod n$
> > 
> > $s \leftarrow s^2 \mod n$
> 
> **return** $y$

[^1]: Achtung vor Compiler-Optimierungen!

### Power Analysis

Wir messen die *Leistung*, die ein Chip benötigt. Dadurch können wir herausfinden, welche **Operationen** ein Chip durchführt.

- Einfache Power Analysis
	- Mache eine Messung
	- Suche nach wiederholten Mustern
	- Lerne etwas über die Instrukitonen/Operationen, die ausgeführt werden
- Differenzielle Power Analysis
	- Mache tausende Messungen
	- Teile die Messungen in zwei Mengen, anhand, äh, geratenem Bit der Chiffre(?)
	- Bereche Durchschnit von irgendwas(?)
	- Profit?
- Correlation Power Analysis
	- Mache tausende Messungen
	- Modelliere den Side Channel anhand von Hypothese
	- Richtige Hypothese => höchste Korrelation zu Messungen

### Padding Oracle

damit kann man komplette Chiffren rausfinden

## Side Channels innerhalb eines Systems

Wenn wir schon Zugriff auf das System (aber nicht auf den Prozess selbst haben), können wir Seitenkanäle selbst erzeugen.

### Rowhammer
Wir flippen eine komplette Adresszeile sehr oft hin und her, was im RAM Bits in benachbarten Zellen flippen kann.
-> nicht berechenbar, aber reproduzierbar

Nette Bits, die man flippen kann:
- Superuser-Bit in pagetable
	- -> auf kernel pages vom userspace aus zugreifen, memory pages ausführbar machen, Schreibschutz aufheben, ...
- ein Bit im SSH public key
	- -> kann nun wahrscheinlich faktorisiert werden, und dann kann man den private key berechnen und einloggen
- Serveradresse in Paketmanager-Quelle
	- ubuntu.com -> ufuntu.com
- GPG key ring
	- funktioniert ähnlich wie der SSH key -> Pakete signieren und installieren

Das passiert alles im RAM, hinterlässt also keine Spuren auf der Platte.


### Flush + Reload

Man teilt sich irgendeine page mit dem Opfer (z.B. eine shared library). 
Nun kann man bestimmte cache lines immer wieder flushen, um sie danach neu zu laden. Wenn sie schnell laden, heißt das, dass das Opfer in der Zwischenzeit auf diesen Speicherinhalt zugegriffen hat.

Durch speculative execution des Prozessors kann der Angreifer auch bestimmte Daten in den Cache laden, auch auf Grundlage vor Informationen, auf die er eigentlich keinen Zugriff hat - die Überprüfung findet erst später statt. Durch die Dauer beim Reload dieser Daten kann er aber trotzdem inferieren, welche Daten in den Cache geladen wurden.

### Prime & Probe

Prime: der Angreifer füllt bestimmte Cache lines mit seinen eigenen Daten.
Probe: der Angreifer greift danach auf dieselben Daten zu. Die Daten, die länger brauchen, sind in der Zwischenzeit aus dem Cache verschwunden, also hat das Opfer diese Cache lines benutzt.

Unterschied zu Flush + Reload: man braucht kein shared memory, nur einen geteilten Cache.

Beispiel: bei RSA-Verschlüsselung (s.o.) könnten if- und else-branch in zwei verschiedenen Cache lines liegen. Wenn man das weiß, könnte man also den Private Key damit bitweise bestimmen.
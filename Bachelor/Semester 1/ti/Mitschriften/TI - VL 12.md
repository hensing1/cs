Datum: 29.11.
[[TI_04_Schaltnetze.pdf|Folien]] (Seiten 56 bis 82)

# Demultiplexer
Ein 1:$n$ Demultiplexer macht das Gegenteil von einem Multiplexer: Ein Eingangssignal wird, abhängig vom Steuersignal (bestehend aus $\log_{2}n$ Leitungen), auf eins von den $n$ Ausgangssignalen weitergeleitet. Der Rest der Ausgänge bleibt 0.

## Dekoder
Ein (Adress-)Dekoder funktioniert wie ein Demultiplexer, bei dem das Eingangssignal immer 1 ist. Ein 3-Bit-Adressdekoder hat also drei Eingangsbits und macht daraus einen 8-Bit [[Korrektur von Übertragungsfehlern#1-aus-n-Code|1-aus-n Code.]]

# Arithmetische Schaltnetze
## Logische Operationen
Bitweise verknüpfung von ganzen Wörtern: aus zwei Wörtern $A=a_{n-1}a_{n-2}\ldots a_{0}$ und $B=b_{n-1}b_{n-2}\ldots b_{0}$ wird $A \space \& \space B = (a_{n-1}\land b_{n-1})(a_{n-2}\land b_{n-2})\ldots(a_{0}\land b_{0})$.

Verknüpfungen mit OR und XOR sind auch üblich.

Diese logischen Operationen werden von so ziemlich allen Computern unterstützt.

## Shift
- *Logischer Shift*: schiebt einfach nur die Bits nach links oder rechts und füllt die Lücke mit einer 0
	- Rechtsshift verhält sich wie Division durch 2 (abgerundet)
	- Linksshift multipliziert mit 2
- *Arithmethischer Shift*: Beim Rechtsshift wird das Vorzeichenbit vorne drangehangen statt einer 0
	- Für positive Zahlen genau wie Logischer Shift
	- Bei negativen Zahlen im [[Kodierung von Binärzahlen#Ganzzahlen#Zweierkomplement|Zweierkomplement]] wird auch durch zwei geteilt, der Betrag aber aufgerundet (z.B. aus -9 wird -5)
	- Fun fact: die `>>`-Operation in Programmiersprachen macht einen arithmetischen Shift! (zumindest in Python und JavaScript)

Für einen einzelnen logischen Shift braucht man natürlich gar keine Gatter, man muss nur entsprechende Drähte legen. Für größere Shift-Ansprüche gibt es:
### Barrel-Shifter
Kann mehrere logische Shifts auf einmal machen (`<<= n`). Kann mit Multiplexern umgesetzt werden, ist dann aber auch relativ teuer: um für ein $n$-Bit-Wort jeden möglichen Shiftwert (nach links und rechts) möglich zu machen, bracht man $n$ Multiplexer mit jeweils $2n$ Eingängen.

# Addition
## Halbaddierer
Kann 2 Eingangsbits addieren - dabei entsteht ein Summen- und ein Carry-Bit. 
Für das Summenbit reicht ein XOR, für das Carry-Bit ein AND-Gatter.

## Volladdierer
Kann 3 1-Bit-Zahlen addieren - also zwei Eingangsbits plus ein Übertrag aus einer vorherigen Berechnung. Das passiert mit zwei hintereinandergeschlateten Halbaddierern: einer für die beiden Eingänge, und ein zweiter für das Resultat mit dem Carry-In. Die Carry-Outs der beiden Halbaddierer werden verodert und bilden das Carry-Out des Volladierers

## Ripple-Carry-Addierer
Schaltet ganz viele Volladdierer hintereinander.
Die *Laufzeit* sowie der *Materialaufwand* von so einem Addierer liegt in der [[Größenordnungen|Größenordnung]] $\mathcal{O}(n)$, mit $n=\text{ Anzahl der Bits}$.

## Paralleladdierer
Addiert zwei Zahlen via DNF - Laufzeit $\mathcal{O}(1)$ (3 Gatterlaufzeiten), Hardware $\mathcal{O}(n\cdot 2^{2n})$, also nicht praktikabel.

## Carry-Lookahead-Addierer
Das Summenbit ist recht schwer zu berechnen, da man nix wegoptimieren kann - ander sieht es beim Carry-Bit aus, das einfach durch eine Majoritätsfunktion bestimmt wird.
Der Carry-Lookahead-Addierer berechnet alle Carry-Bits parallel, und verrechnet die dann mit den Eingangsbits (Laufzeit: $\mathcal{O}(1)$, 6 Gatterlaufzeiten)

### Carry-Lookahead-Generator (CLAG)
Sei $C_{i}$ das Carry-Bit an der Stelle $i$ beim Addieren zweier Zahlen $A$ und $B$.
Es wird berechnet mit: $C_{i+1}=A_{i} B_{i} + (A_{i}+B_{i}) C_{i}$ (also letztendlich mit der Majoritätsfunktion aus $A_{i},B_{i}$ und $C_{i}$).

$A_{i}B_{i}=g_{i}$ heißt *carry generate*, da es nicht vom vorherigen Carry-Bit abhängt.
$A_{i}+B_{i}=p_{i}$ heißt *carry propagate*, da es das vorherige Carry-Bit weiterpropagiert.

Durch wiederholtes Einsetzen und Ausmultiplizieren ergibt sich:
$$
\begin{align}
C_{1}&= g_0+p_0C_o\\
C_{2}&= g_1+p_1C_1=g_1+p_1(g_0+p_0C_0)=g_1+p_1g_0+p_1p_0\\
C_{3}&= g_2+p_2C_2=\ldots=g_2+p_2g_1+p_2p_1g_0+p_2p_1p_0C_0\\
\vdots
\end{align}
$$
Bedeutet letztendlich: jeder Volladdierer, der das letztendliche Ergebnis berechnet, muss nicht auf die Carries von davorliegenden Volladdierern warten, sondern kriegt seine Carry-Ins direkt vom CLAG. Der CLAG hat eine Laufzeit von $\mathcal{O}(1)$.

![[CLAG.png]]

### CLA-Addierer stapeln
Man kann für das letzte Carry-Bit schreiben: $C_{4}=G+PC_{0}$, mit $G=g_3+p_3g_2+p_3p_2g_1+p_3p_2p_1g_0$ und $P=p_3p_2p_1p_0$.
Also produziert jeder CLAG seinen eigenen carry generate und -propagate, d.h. vier CLAGs können die Inputs für einen weiteren CLAG liefern, also kann man sie stapeln und längere Inputs berechnen. 
Im obigen Bild kann man einfach jeden Volladdierer durch einen CLA-Addierer ersetzen, und man hat eine Schaltung die 16 statt 4 Bit lange Zahlen addieren kann.

Das Ganze hat dann eine Laufzeit von $\mathcal{O}(log_{n})$, d.h. er wächst linear mit der Anzahl $k$ der CLAG-Schichten ($k=\log_{4}n$).
Der Hardwareaufwand liegt in $\mathcal{O}(n)$.
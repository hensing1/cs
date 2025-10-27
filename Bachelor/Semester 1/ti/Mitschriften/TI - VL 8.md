Datum: 15.11.
[[TI_03_Boolesche_Algebra.pdf|Folien]] (ab Seite 60)

# Vereinfachen boolescher Funktionen
Sehr praktisch hierfür:
![[Boolesche Algebra#Resolutionsregel]]

## KV-Diagramme
> hochgradig klausurrelevant!

Situation: man hat eine boolesche Funktion mit 3 oder 4 Eingängen. Nun möchte man gerne ein möglichst simples Polynom dafür entwickeln.

Dafür malt man sich zunächst die folgende Tabelle (hier für Werte $x_1,\ldots,x_4$):

| $x_1x_2\downarrow / x_3x_4\rightarrow$ | 00  | 01  | 11  | 10  |
| -------------------------------------- | --- | --- | --- | --- |
| 00                                     |     |     |     |     |
| 01                                     |     |     |     |     |
| 11                                     |     |     |     |     |
| 10                                     |     |     |     |     |

Es ist wichtig, dass die Reihenfolge der Werte einen [[Korrektur von Übertragungsfehlern#Gray-Code|Gray-Code]] bilden - so ändert sich von einer Zelle zur nächsten nur genau ein Literal.

Nun setzt man für jedes Monom in seiner DNF eine 1 an die entsprechende Stelle in der Tabelle.

Und nun kann man zusammenfassen, indem man alle Einsen mit Rechtecken der Größe $2m \times 2n$ einschließt. Jedes Rechteck wird zu einem neuen Monom: und zwar können Literale, die innerhalb des Rechtecks sowohl negiert als auch nicht negiert vorkommen, aus dem Monom rausgenommen werden. 

Wegen der Idempotenz können sich Rechtecke auch überlappen.

Rechtecke dürfen auch über die Ränder des KV-Diagramms hinausgehen, sie werden dann auf der gegenüberliegenden Seite fortgesetzt.

### Don't-Cares
Bei Eingaben, die nicht vorkommen können, kann ich im KV-Diagramm das hinschreiben, was mir besser passt. 
- Don't-Care-Term = 1: größere Blöcke -> Monome mit weniger Literalen
- Don't-Care-Term = 0: muss nicht überdeckt werden -> weniger Monome

## Quine-McCluskey
Alternatives Verfahren für die Vereinfachung von Schaltfunktionen.

- Schritt 1
	- Schreibe alle Minterme der DNF in eine Tabelle, mit einer 1 für $x_n$ und einer 0 für $x_{n}'$.
	- Das Resultat sieht pro Minterm so aus wie eine Binärzahl, also wird der Index dieses Monoms diese Zahl.
	- Also so ungefähr: ![[QMC-1.png|250]]
- Schritt 2
	- Fasse alle Monome anhand der Anzahl der Einsen, die sie enthalten, in Gruppen zusammen, und schreibe diese Gruppen untereinander auf
	- Terme aus benachbarten Gruppen können nun wegen Resolutionsregel zusammengefasst werden, sofern sie sich in genau einer Stelle unterscheiden (dieses Literal fällt dann im resultierenden Monom weg)
- Schritt 3
	- Markiere alle Monome, die man zusammenfassen kann. Alle Monome die übrig bleiben, sind *Primimplikanten*, die man sich für später merkt
	- Sieht dann so aus: ![[QMC-2.png|260]]
- Schritt 4
	- Wiederhole Schritte 2 und 3, solange bis nur noch Primimplikanten übrig sind
	- Falls durch das Zusammenfassen irgendwelche Monome doppelt auftreten, kann man die Duplikate natürlich rauswerfen (durchstreichen)
- Schritt 5
	- Trage alle Primimplikaten auf einer Tabelle auf mit den Monomen, die sie abdecken
	- Jedes Monom, welches nur von einem Primimplikanten abgedeckt wird, wird eingekreist
		- Dieses Monom heißt *Kernimplikant*, da es auf jeden Fall in der Minimalform erscheinen muss
	- Alle anderen Monome werden vertikal miteinander verbunden
	- ![[QMC-3.png|320]]

Alle Primimplikanten mit eingekreisten Monomen müssen auf jeden Fall genommen werden.
Unter Umständen bleibt dann irgendwas übrig - dann die minimale Anzahl von Primimplikanten zu finden, die alle Terme abdecken, ist ein NP-schweres Problem. Da muss man eben durch.

Wenn man Don't Care-Terme hat, tut man zunächst so, als wären sie 1'en - damit steigt die Chance, dass man mehr zusammenfassen kann. Diese Terme muss man am Ende in der Tabelle aber gar nicht hinmalen. Man sucht sich einfach die Primimplikanten raus, die alle Nicht-Don't-Cares[^1] abdecken.

[^1]: Do-Cares
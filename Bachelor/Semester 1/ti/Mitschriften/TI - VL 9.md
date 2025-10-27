Datum: 17.11.
[[TI_04_Schaltnetze.pdf|Folien]] (bis S. 10)

# Schaltnetze
## Technische Realisierung von Schaltfunktionen
### Halbleitertechnik
#### Grundlagen
- Ein Halbleiter heißt Halbleiter, weil seine Leitfähigkeit zwischen der von Leitern und Isolatoren liegt!
- Wir machen MOSFETS (das ist ein Transistor)
- Die Ladungsmenge $Q$ misst man in Coulomb (C)
- Ladungsmenge, die pro Sekunde an einer Stelle vorbeifließt, wird in Ampere gemessen ($1A=1C/s$)
- EIn Stromzählpfeil zeigt die Richtung, in die man den Strom positiv zählt (nomalerweise von + nach -; muss er aber nicht, dann ist die Spannung halt negativ)
- Man tut so, als fließe der Strom von + nach -, obwohl die Elektronen in Wirklichkeit anders rum reisen
- Energie wird in Joule (J) gemessen
- Spannung (U) ist definiert als Energie pro Ladungsmenge, gemessen in Volt: $1V=1J/C$
- Man zeigt das in Diagrammen manchmal als Spannungspfeil, der zeigt dann physikalisch gesehen aber auch in die falsche Richtung

Also:

| Formelzeichen | Bedeutung                           | Einheit               |
| ------------- | ----------------------------------- | --------------------- |
| $Q$           | Ladungsmenge                        | Coulomb (C)           |
| $I$           | Stromstärke (Ladungsmenge pro Zeit) | Ampere (A), $1A=1C/s$ |
| $E$           | Energie                             | Joule (J)             |
| $U$           | Spannung (Energie pro Ladungsmenge) | Volt (V), $1V = 1J/C$ |

#### Halbleiter
- Man hat einen Siliziumkristall
- Im Kristall ist jedes Siliziumatom mit vier anderen Siliziumatomen verbunden
- Das ganze leitet eigentlich nicht, da ja alles verbunden und glücklich ist
- Wenn man dem ganze jetzt Wärmeenergie zuführt, wackelt alles so rum
- Dadurch kann es passieren, dass ein Elektron frei wird und frei im Kristall rumfliegt
- Das entstandene "Loch" verhält sich dann genauso wie ein frei beweglicher positiver Ladungsträger
- Wenn man jetzt eine Spannung an den Halbleiter anlegt, bewegen sich die Elektronen in eine Richtung und die Löcher in die andere -> es fließt ein Strom
- Leitet nicht so gut wie z.B. Metalle; je höher die Temperatur, desto besser wird die Leitfähigkeit

#### Dotierte Halbleiter
- Wenn man jetzt alle paar Siliziumatome durch ein Atom mit 5 Valenzelektronen (wie Arsen, Antimon oder Phosphor) ersetzt, wird die Leitfähigkeit vom Halbleiter dramatisch erhöht (-> *n-dotierte Halbleiter*, das n steht für negativ)
	- Das fünfte Elektron ist dann ziemlich lose, da es keinen Bindungspartner findet
	- Wenn dieses Elektron dann irgendwo anders hinfliegt, hinterlässt es kein Loch
- Man kann anstatt dessen auch Atome mit nur 3 Valenzelektronen nehmen -> *p-dotierter Halbleiter* (das p steht für positiv)
	- Nun hat man ein frei bewegliches Loch

#### pn-Übergang
- Wenn man jetzt einen p-dotierten Halbleiter neben einen n-dotierten Halbleiter klatscht, passiert folgendes:
	- Die freien Elektronen aus dem n-dotierten Bereich sausen in die Löcher aus dem p-dotierten Bereich (zumindest in einer Übergangszone)
	- Das hinterlässt positiv geladene Phosphor-Rümpfe im n-dotierten Bereich und negativ geladene Bor-Atome im p-dotierten Bereich (deshalb heißt die Übergangszone "Verarmungszone")
	- Dadurch entsteht eine positive Spannung zwischen p- und n-dotiertem Bereich, die die Elektronen überwinden müssen, wenn sie in die Löcher im p-dotierten Bereich wollen (diese Spannung heißt "Diffusionsspannung")
	- Wenn man jetzt - an den p-Bereich und + an den n-Bereich anschließt, wird die Diffusionsspannung größer, weil immer mehr Elektronen und Löcher in die Mitte gedrückt werden und dort kombinieren. Diese Diffusionsspannung wirkt der außen anliegenden Spannung entgegen, und es fließt kein Strom.
	- ABER
	- Wenn man es andersrum anschließt, wird der Potentialwall zwischen den beiden Schichten abgebaut. Durch das neue elektrische Feld wird Ladungstransport im gesamten Kristall ermöglicht - es fließt Strom!
	- -> Man hat eine **Diode** gebaut!

Datum: 17.05.
[[Folien-2023-5-17.pdf|Folien]]
[[Skript AlgoII.pdf|Skript]] - Seiten 51 bis 56
[Video](https://uni-bonn.sciebo.de/s/YVfBpu1J5oiqZGj#/files_mediaviewer/Vorlesung-06.mp4)

*Kapitel 4: Komplexitätstheorie*
# Die Klassen P und NP
## Nichtdeterministische Turingmaschinen
![[Turingmaschine#Nichtdeterministische Turingmaschine#Definition]]
![[Turingmaschine#Nichtdeterministische Turingmaschine#Verhalten]]

## Die Klasse NP
![[Komplexitätstheorie#Die Klasse NP#Definition mittels nichtdeterministischer Turingmaschien]]

### Cliquenproblem
![[Cliquenproblem#Lösung mit nichtdeterministischer Turingmaschine]]

Analog kann das [[Rucksackproblem]] polynomiell mit einer NTM entschieden werden.

![[Komplexitätstheorie#Definition mittels Verifizierer]]

In der o.b. Variante des Cliquenproblems könnte das Zertifikat also die Zahl sein, welche von der NTM zufällig generiert wird. Der Verifizierer selbst durchläuft also lediglich die Schritte der NTM, welche ohnehin deterministisch sind. 

Man kann ebenfalls jeden nichtdeterministischen Zustandsübergang eins zu eins in dem Zertifikat kodieren, sodass für jeden möglichen Rechenweg ein Zertifikat existiert. Dann simuliert der Verifizierer die NTM anhand des Zertifikats.

![[Komplexitätstheorie#P versus NP]]
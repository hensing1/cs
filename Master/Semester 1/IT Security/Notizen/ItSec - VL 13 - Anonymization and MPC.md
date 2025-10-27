Datum: 16.01.
[[13 Anonymization Secure Multiparty Computation.pdf|Folien]]
[[13 Anonymization and SMC.pdf|Übung]]
# Anonymization & Secure Multi-Party-Computation

*Quasi-Identifier:* Menge an Attributen, die ausreichen, um ein Individuum eindeutig zu erkennen

Wir haben einen Datensatz $T$ über eine Menge $U$ an Individuen.

**Verschiedene Angreifermodelle**
- *Prosecutor*
	- Möchte Informationen über ein bestimmtes Individuum herausfinden
	- Weiß, dass das Individuum im Datensatz enthalten ist
- *Journalist*
	- Möchte auch Informationen über ein bestimmtes Individuum herausfinden
	- Weiß nicht, ob das Individuum im Datensatz ist
- *Marketer*
	- Möchte eine Vielzahl von Individuen wiedererkennen
	- Angriff wird als erfolgreich bewertet, wenn eine große Anzahl von Individuen wiedererkennbar sind

## Methoden für Anonymisierung

*Perturbative Methode:* füge normalverteiltes Rauschen zu den Daten hinzu


Nicht-perturbative Methoden:
- Reduziere Detailgrad der Daten (20-25J statt 23J)

Synthetische Daten: ersetze tatsächliche Daten durch modellierte Beispieldaten

### k-Anonymität

> *Definition*
> In einem k-anonymen Datensatz kommt jede Wertekombination von Quasi-Identifikatoren mindestens k-mal vor.
> Jede Gruppe von Einträgen, deren Quasi-Identifikatoren identisch sind, bildet eine *Äquivalenzklasse*.

Achtung: hat man mehrere Tabellen vom gleichen Datensatz, die jeweils k-anonym sind, muss man darauf achten, dass sie in unterschiedlicher Reihenfolge sind. 
Sonst kann man die Tabellen zusammenkleben - wenn die Einträge durch die Reihenfolge matchen, ist die k-Anonymität ggf. gebrochen.

### $l$-Diversität

Eine Äquivalenzklasse ist $l$-divers, wenn mindestens $l$ wohlrepräsentierte Werte pro sensibles Attribut darin vorkommen.

Was heißt "wohlrepräsentiert"?
- Distinct $l$-diversity: pro Äquivalenzklasse gibt es mindestens $l$ verschiedene sensible Attribute
- Entropy $l$-diversity: komische Entropiefunktion von Äquiv.kl. ist größer als $\log(l)$
- Rekursive $(c.l)$-diversity:
	- häufigster Wert nicht zu oft
	- seltenster Wert nicht zu selten

### $t$-Nähe
Eine Äquivalenzklasse erfüllt $t$-Nähe, wenn sich die Verteilungen sensibler Attribute innerhalb und außerhalb der Äquivalenzklasse um höchstens $t$ unterscheiden.
Man kann jede boolesche Funktion als binären Entscheidungsbaum darstellen.
Dabei bekommt jede Variable seine eigene Ebene, und die Blätter sind entweder 0 oder 1. Das heißt, wenn man den Baum von oben bis unten verläuft, hat man für jede Variable eine Entscheidung für deren Belegung getroffen und landet unten bei dem Ergebnis der Schaltfunktion.

![[Binaerer_Entscheidungsbaum_vollstaendig.png]]

## Geordnete binäre Entscheidungsdiagramme
Man kann am Baum doppelte Eigenschaften isolieren und dadurch das Ganze zu einem Graphen vereinfachen.

Man kann zum Beispiel anfangen, alle Blätter zu zwei Knoten 0 und 1 zusammenzufassen. Dann ist es kein Baum mehr, da mehrere Kanten zum selben Knoten zeigen, aber es ist übersichtlicher.

Dann gibt es noch weitere Vereinfachungsregeln, zum Beispiel kann man identische Teilgraphen miteinander Verschmelzen, und man kann Knoten löschen, die nur einen (oder zwei gleiche) Nachfolger haben.

Wenn man das oft genug macht, landet man irgendwann bei einem *Reduced Ordered Binary Decision Diagram* oder **ROBDD**.

Der ROBDD für die Paritätsfunktion sieht zum Beispiel so aus:
![[ROBDD.png|150]]

Ein ROBDD ist eine *eindeutige Darstellung* einer Booleschen Funktion, also eine Normalform. Dadurch wird öfter (v.a. im Computer) die Äquivalenz von Funktionen nachgewiesen.
Öfter sind ROBDDs wesentlich kompakter als die zugehörigen Entscheidungstabellen.

Wichtig:
![[Boolesche Algebra#Entwicklungssatz von Shannon]]

Einer der beiden eingeklammerten Terme fällt also immer weg, je nachdem, ob $x_{i}$ gerade 1 oder 0 ist. Dieser Satz beschreibt quasi eine Fallunterscheidung, mit der man Funktionen unter Umständen erheblich vereinfachen kann.

Dieser Entwicklungssatz formalisiert quasi den Prozess, sich die beiden Teilbäume in einem BDD isoliert anzuschauen.

Dadurch kann man, wenn man einen (RO)BDD gegeben hat, die ursprüngliche boolesche Funktion wieder herstellen. 
Alles was man dafür machen muss, ist für jeden Knoten die rechte Seite von diesem Entwicklungssatz einzusetzen. Dann setzt man wiederum für $f_{x_{i}=1}$ das ein, was im BDD dem Pfeil mit der 1 folgt, usw. Irgendwann landet man dann an einem Punkt, an dem man $\land 0$ oder $\land 1$ statt einer weiteren Entwicklung einsetzen kann.

Das Ergebnis ist dann meistens ziemlich unübersichtlich, dann muss man es halt noch vereinfachen.
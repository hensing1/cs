Datum: 23.05.
[[SysInf_Kap_2_230505_1035.pdf|Folien]]: Seiten 39 bis 76

# Endliche Automaten und deren Konstruktion aus Syntaxdiagrammen

Wir führen [[Endliche Automaten]] ein, mit welchen man die [[Der Kompilierprozess#Lexikalische Analyse|lexikalische Analyse]] des Kompilierprozesses bewältigen kann. Das schreib ich jetzt nicht noch mal auf.

Die [[Formale Sprachen und Grammatiken#Syntaxdiagramm|Syntaxdiagramme für kontextfreie Grammatiken]] aus der letzten Vorlesung kann man jedoch algorithmisch recht einfach in einen DFA umwandeln (solange dieses Diagramm eine reguläre Grammatik beschreibt):

- Knoten im Syntaxdiagramm werden zu Kanten (Übergängen) im DFA
- Kanten im Syntaxdiagramm werden zu Knoten (Zuständen) im DFA

![[Syntaxdiagramm_DFA.png]]

Konkret sieht der Algorithmus folgendermaßen aus:
1. Alle Knoten des Syntaxdiagramm werden durchnummeriert. Der "Ausgang" erhält die Bezeichnung 0.
2. Die Knoten, die unmittelbar vom Anfang aus erreichbar sind, bilden den Startzustand $q_0$.
3. Solange noch Knoten bzw. Kanten im Syntaxdiagramm übrig sind:
	1. Wähle einen Zustand $q$, zu welchem eine Marke gehört, welche noch nicht abgearbeitet wurde. Wähle eine solche Marke.
	2. ?

Komplexeres Beispiel:
![[Syntaxdiagramm_DFA_2.png]]

Zu Erinnerung: der Automat hält erst dann, wenn mit dem aktuellen Zeichen kein Übergang mehr möglich ist. Falls sich der Automat zu diesem Zeitpunkt in einem akzeptierendem Zustand befindet, ist die Eingabe bis dorthin ein gültiges Token.

# Syntaktische Analyse
![[Der Kompilierprozess#Syntaktische Analyse]]
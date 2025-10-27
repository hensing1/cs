# Von-Neumann-Architektur
### Grundlagen

Die *Von-Neumann-Architektur* ist eine Computerarchitektur, die sich durch die folgenden Bestandteile und Konzepte auszeichnet:
- Es gibt eine **zentrale Recheneinheit** (CPU), welche aus einem *Steuerwerk* (CU) und einem *Rechenwerk* (ALU) zusammensetzt (siehe [[TI - VL 19#Aufteilung in Steuer- und Rechenwerk|Register-Transfer-Entwurf]])
- Diese interpretiert *Maschinenbefehle*, die im Speicher (RAM und ROM) abgelegt sind
	- Befehlssatz ist mächtig genug, um Turing-Vollständigkeit zu erzielen
	- ROM dient zum Kaltstart nach Einschalten des Stroms
	- RAM ist der Hauptspeicher für Daten und Programme
- Das alles ist mit externer *Peripherie* verbunden
- Als Verbindung zwischen alledem gibt es ein Bussystem (gemeinsamen Übertragungsweg)

Hierbei werden Befehlsworte und Datenworte *nicht* strikt voneinander getrennt (beide liegen im selben Hauptspeicher). Dies ist der zentrale Unterschied zur **Harvard-Architektur**, bei welcher sich Daten und Befehle in verschiedenen Speichern befinden.

> Die Architektur fällt in die Klasse [[Glossar#Rechnerklassifikation nach Flynn|SISD]].

Heutzutage sind CPUs eine Mischung aus Von-Neumann- und Harvard-Architektur:
- Daten und Befehle sind im selben Hauptspeicher
- Es gibt aber getrennte Daten- und Befehls-Caches, auf die gleichzeitig zugegriffen werden kann

> [!info] Von-Neumann-Bottleneck
> Im Gegensatz zur direkten Kommunikation, bei der jede Komponente direkt mit jeder anderen verbunden ist (und die Zahl der Verbindungen mit $n^2$ wächst), verwendet die Von-Neumann-Architektur ein **Bussystem**.
> 
> Bei einem Bus sind alle Komponenten mit einem zentralen Transportweg verbunden. Dadurch kann immer nur eine Komponente gleichzeitig schreiben, alle anderen können vom Bus lesen.
> Dieses System ist sehr flexibel und erweiterbar, wird aber schnell zum Flaschenhals.
> Das ist insbesondere bei der Von-Neumann-Architektur der Fall, da Befehle und Daten im selben Speicher sitzen.
> 
> Die CPU kommuniziert mit den anderen Komponenten über einen *Adress-* und einen *Steuerbus*, auf den nur durch die CPU geschrieben wird, sowie über einen *Datenbus*, auf den auch die anderen Komponenten schreiben können.

[[01b Secure Software Engineering.pdf|Folien]]

Software Security := der Design-, Entwicklungs- und Testprozess von Software im Hinblick auf deren Sicherheit


| **Entwicklungsschritt**  | **Dinge, die zu bedenken sind**                               |
| ------------------------ | ------------------------------------------------------------- |
| Requirements & Use Cases | Wie könnte das System missbraucht werden?                     |
| Architektur und Design   | STRIDE - Risikoanalyse                                        |
| Testplanung              | Risikobasierte Sicherheitstests - Missbrauchsszenarien testen |
| Code                     | Code Review (Bugs finden)                                     |
| Test                     | Pen Testing: echtes Environment                               |
| Feedback                 | Admins und Netzwerkprofis zu Rückmeldungen ermuntern          |

Wir besprechen, was eine SQL-Injection ist.

## Mumbo Jumbo

*Asset:* etwas, das es zu beschützen gilt
*Threat & Adversary:* Gefahr/Gegenspieler, vor dem wir uns schützen möchten

*Attack Vector:* Die Route, über die ein Angriff ausgeführt wird (z.B. Social Engineering, DDoS, Man in the Middle, unsicherer Webclient, ...)
*Exploit:* das Ausnutzen einer Vulnerability (z.B. bestimmter SQL Command für SQL injection)
*Vulnerability:* Schwäche seitens des Opfers, das ausgenutzt werden kann (z.B. unsanitized user input)

### CIA-Triad

*3 Schutzziele:*
- **Confidentiality** - Geheimnisse sollen geheim bleiben
- **Integrity** - Assets sollen vor Zerstörung oder Verunstaltung geschützt sein
- **Availability** - der angebotene Service soll für Kunden erreichbar sein

Beispiel Onlineshop:
- Kundendaten dürfen nicht in falsche Hände geraten (Confidentiality)
- Preise und andere Daten vor Manipulation schützen (Integrity)
- Der Shop soll über das Internet erreichbar bleiben (Availability)

### STRIDE - Gefahren für die Schutzziele

- **S**poofing
	- So tun, als sei man etwas oder jemand anderes als man selbst
	- Beispiele:
		- IP Spoofing: Quell-IP auf eine andere setzen
		- E-Mail Spoofing: Falsche Senderadresse angeben
- **T**ampering
	- Daten verändern
	- Beispiel: Preise von Webshop ändern
- **R**epudiation
	- Behaupten, man hätte etwas nicht getan oder sei nicht verantwortlich
	- kann ehrlich oder bösartig sein
	- Beispiel: Logs oder Transaktionen löschen
- **I**nformation Disclosure
	- Geheime Informationen für unauthorisierten Parteien preisgeben
	- Beispiel: [Heartbleed-Bug](https://de.wikipedia.org/wiki/Heartbleed)
- **D**enial of Service
	- Ressourcen aufsaugen, die für die Verfügbarkeit des Services gebraucht werden
	- Beispiel: Botnet
- **E**levation of Priviledge
	- Jemandem erlauben, etwas zu tun, zu dem er keine Berechtigung hat
	- Beispiel: [ImageTragick](https://imagetragick.com/) (arbitrary code execution durch hochgeladene SVGs in ImageMagick)


## Misuse and Abuse

Normalerweise fragt sich der Softwareentwickler, zu was das System fähig sein soll.
Ein Sicherheitsbeauftragter (bzw. sicherheitsbewusster Softwareentwickler) fragt sich, wozu das System *nicht* fähig sein soll.

Schwachstellen liegen oft an Punkten, an denen das System mehr Fähigkeiten hat als vorgesehen.

Misuse: Schaden, der ungewollt durch User angerichtet wird
Abuse: Schaden, der absichtlich angerichtet wird
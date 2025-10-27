Datum: 19.12.

Monsieur Marc Ohm

# Software Supply Chain Attacks

## Threat Intelligence

### Threat Actors

Geringstes Niveau: 
- *Hacktivists* (Diffamierung von Websites & dergleichen)
- *Terroristische Gruppen*
	- Motivation: Ideologie / Ideologische Gewalt
- *Thrillseeker / Script Kiddies*
	- Motivation: for the lolz
-> copy/pasten einfache Scripts, um bekannte Sicherheitslücken auszunutzen

Mittleres Niveau:
- *Cyberkriminelle*
	- Motivation: Geld
-> man kann Menschen anheuern, um Angriffe auf Websites/Services durchzuführen

Höchstes Niveau:
- *Nation State* (Nationen oder Nationenverbund mit sehr viel Ressourcen, Personal, Planung und Koordination)
	- Motivation: geopolitische Ziele
-> "keine Chance"
Art der Angriffe: **APT** (Advanced Persistent Threats) - Angriffe, die langsam und allmählich und schwer detektierbar voranschreiten, häufig mit unbekannten Exploits


Menschen, die für die attackierten Organisationen arbeiten, sind *Insider* (können mit beliebigen o.g. Threat Actors zusammenhängen, können aber auch unzufriedene, allein handelnde Mitarbeiter sein).
Haben privilegierten Zugriff, Kenntnis von Internals, etc.

### Kill Chain

Wir modellieren die Phasen eines Cyberangriffs:
- **Reconnaissance**
	- Einbringen von technischen Fakten:
		- Verwendete Programme, Programmversionen, ...
		- IP-Adressen, Domänen, ...
	- Einbringen von nicht-technischen Fakten:
		- Persönliche Daten: Name, Freunde, Hobbies, ...
		- Geschäftsdaten: Vertragspartner, Lieferanten, ...
- **Weaponize**
	- Software vorbereiten, die an das Opfer geschickt wird
	- Software wird mit Backdoor gebündelt, damit sie ausgeliefert werden kann
- **Deliver**
	- Software beim Ziel einschleusen
- **Exploit**
	- Eine [[Software-Vulnerabilities|Vulnerability]] ausnutzen, um Zugriff zu erlangen
- **Install**
	- Persistenz sicherstellen, indem Payload installiert wird
	- ca. 2/3 sind Zugriffe über Webapp, 1/4 remote exploits, der Rest lokale exploits
- **Command and Control**
	- APT malware braucht häufig manuelle Interaktion
	- Command & Control (C2) server: Server, der mit der Malware kommuniziert
	- zu diesem Server muss die Malware einen Tunnel aufbauen
- **Act on Objective**
	- Ziel und Zweck der Malware wird ausgeführt
## Software Supply Chain Security
# Version Detection
[[Master/Semester 1/IT Security/Slides/10 Version Detection.pdf|Slides]]
[[Master/Semester 1/IT Security/Übungen/10 Version Detection.pdf|Übung]]

*Übliches Format einer Version (Semantic Versioning):* **X.Y.Z**
- **X:** Major Version - Hochgezählt bei rückwärts-inkompatiblen API-Veränderungen
- **Y:** Minor Version - Hochgezählt bei rückwärts-kompatiblen neuen Funktionen
- **Z:** Patch Version - Hochgezählt bei rückwärts-kompatiblen Bugfixes

*Warum Version Detection?*
-> wir möchten wissen, ob eine verwendete Software bestimmte Vulnerabilities enthält.

CVE (Common Vulnerabilities and Exposures) dokumentiert Vulnerabilities in Software und deren Versionsbereich

CVSS (Common Vulnerability Scoring System) bewertet Schweregrad einer CVE von 0 bis 10

## Banner Grabbing

Die meiste Software erzählt einem ihre Version (in einem "Banner"), wenn man nett fragt.

Banner Grabbing: diesen Banner auslesen.
Banner haben kein einheitliches Format.

Vorteil: einfach auszulesen
Nachteil: leicht zu fälschen/verstecken

*Wo findet man Banner?*
- Im Systemoutput:
	- der Paketmanager erzählt es einem
	- `--version` erzählt es einem
	- in der GUI: Help > About
	- für Web Server: im HTTP header
	- Metadaten in html:
		- `<meta>`-Tag
		- URLs in `<script>`-Tags, Stylesheet-Links, ...
- Metadateien (unbeabsichtigte Dateien, nicht zur Veröffentlichung beabsichtigt)
	- READMEs
		- bleiben oft in Wordpress-Extensions drin
	- Dateien von Paketmanagern
		- Auf Webservern: composer (php), npm (JavaScript)
	- Dateien von Versionskontrolle (git)
		- enthalten ggf. komplette Versionshistorie
		- enthalten kompletten Source Code, aber auch Credentials
	- build-Artefakte
		- Können Dateipfade zum source code leaken
- Binaries
	- `strings <binary> | grep -E '[0-9]+\.[0-9]+\.[0-9]+'`

### Kommerzielles Banner Grabbing

builtwith.com
shodan.com
Wappalyzer (open source)
WPScan (security scanner für WordPress)

## Structural Analysis

### Statische Analyse

#### XPath

Anstelle von Banner Grabbing schauen wir uns beispielhaft die Struktur von HTML-Dateien an. Damit finden wir raus, welches CMS genutzt wurde.

Vorteil: nicht so viel Scanning wie bei Banner grabbing - generisch, robust und passiv

Vorgehen (XPath-basierte Detektion):
- Wir extrahieren Features aus einer Datei

Beispiel: 
```html
<html>
	<head>
		<title>Example</title>
	</head>
	<body>
		<h1 class="example">
			Hello World!
		</h1>
	</body>
</html>
```
Features:
- `/html`
- `/html/head`
- `/html/head/title`
- `/html/body`
- `/html/body/h1`
- `/html/body/h1[@class=example]`

Zusätzliche Features: Hashing von statischen Assets (css und js-Dateien)

Daraus errechnen wir einen *Fingerprint*. Diesen Fingerprint vergleichen wir mit Fingerprints von bekannten Versionen von verschiedenen CMS.

#### Plariarism Detection

Wir möchten wissen, ob Quellcode irgendwoher geklaut wurde.

Aufgabe: finde aus $N$ Inputs untereinander Fragmente, die sich ähneln

Ein Service dafür heißt **Dolos**.

*Schritt 1: Tokenization*
- Wir bauen einen Abstract Syntax Tree (AST) für jede unserer Source Files

*Schritt 2: Fingerprinting*
- Zerlege Tokens in $k$-Gramme
- Hashe $k$-Gramme mit schneller Hashfunktion
- Wähle Hashes mit [Winnowing Algorithmus](https://theory.stanford.edu/~aiken/publications/papers/sigmod03.pdf)

*Schritt 3: Indexing*
?

*Schritt 4: Reporting*
Es gibt verschiedene Ähnlichkeits-Metriken, z.B. längste Kette von überlappenden Features


### Dynamische Analyse
Wir schauen uns das Verhalten des Systems an, und vergleichen es mit einer Referenz.

Irgendwas mit state machine und Observationen
System under Test ist Black Box
# Device Identification in Wireless Networks


> *Device Identification*
> Identifikation eines Gerätes auf Grundlage einer eindeutigen ID (MAC-Adresse, IMEI, MEID, ...).

Die meisten besprochenen Verfahren befassen sich mit kabelloser Identifizierung

Wir möchten auseinanderhalten:
- Gerätetypen (TVs, Smartphones, Laptops, ...)
- Hersteller
- Gerätemodelle
- Gerät-Eigenschaften (Support für Protokolle, Bildschirmgröße, ...)
- Verschiedene Geräte im selben Netzwerk

RF := Radio Frequency.

DID := Device Identifying Data

*Direct DID:* DID, die das Gerät alleine identifizieren
*Indirect DID:* DID, die alleine nicht für die Identifizierung reichen, aber zusätzliche Informationen über das Gerät preisgeben

Gemessene Charakteristika können mit einem trainierten *Klassifizierer* zugeordnet werden.

**Passive DI:**
- Nur den Traffic eines Gerätes aufzeichnen (Bluetooth, WLAN, ...)
- Abhängig von dem Kommunikationszustand, in dem sich das Gerät befindet (redseliger, wenn sie mit einem/dem eigenen Netzwerk verbunden sind)

Großes Ding im passiven DI: Machine Learning

**Aktive DI:**
- Wir erzeugen speziellen Traffic und schauen, wie sich das Gerät verhält
- Hängt ebenfalls vom Zustand des Geräts ab
- Ein Gerät kann ausgetrickst werden, sich mit dem eigenen Netzwerk zu verbinden

### Beispiele
**Passive DI:**
- Statistische Klassifizierung auf Grundlage von RF-Features
- Aufzeichnung des genauen Verlaufs der Sendeleistung (unterschiedlich von Chip zu Chip)
- Aufzeichnung der Modulation des Signals
- Bestimmung der Position durch Triangulierung / Signalstärke
- Paketinhalte anschauen
- Pakete werden ge*scrambled*, um eine höhere Entropie bei der Sendung zu erhalten:
	- normalerweise: pseudo-zufälliger String wird auf das Datensignal addiert
	- wir können die nächsten Frames des Scrambles vorhersagen
	- Lücken in der Übertragung können somit überwunden werden
- Device Identifiers (duh)
	- Methoden wie MAC-Randomisierung versuchen dies zu verhindern
- "Information Elements" (IEs) - bestimmter Teil des WiFi-Protokolls
	- Stichwort: Vanhoef fingerprinting

**Aktive DI:**
Um dem Gerät Sachen zu schicken, müssen wir es *adressieren* können -> MAC-Randomisierung ist ein Problem

- WLAN SSIDs:
	- Zuhören, zu welchen Netzwerken sich das Gerät verbinden will, und dann mit einer beobachteten SSID antworten
	- "Preferred Network List" herausfinden
	- Häufige SSIDs (wie "Starbucks WiFi") brute forcen
- Sobald mit WLAN verbunden: IMSI kann herausgefunden werden
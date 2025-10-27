Datum: 23.01.

# Web Authentication Schemes

*Warum?*
Nutzername+Passwort hat so seine Nachteile (Nutzer sind schlecht im Passwörter ausdenken, etc.)

## Deutscher Online-Ausweis

- basiert auf NFC-Chip im Ausweis
- kann Pseudonym generieren, um Nutzer wiederzuerkennen (Pseudonym einmalig für Nutzer+Anbieter)

- falls Dienst persönliche Daten haben will, braucht er dafür ein offizielles Zertifikat

### Identifizierungsprozess

Passwort Authenticated Connection Establishment

eID Service: auf der besuchten Website
eID Server: Teil der eID-Infrastruktur, wird zur Authentifizierung angesprochen
eID Client: hat der Nutzer installiert

### Widerruf

Mein Ausweis wurde gestohlen, was jetzt?
-> Es gibt Hotlines dafür

Das ist *kompliziert* wegen *Pseudonymen* -> es gibt revocation services

1. Nutzer informiert Authorität / Hotline
2. Authorität generiert Revocation code
3. bla

### Nutzung und Einschränkungen

- Verlinkt zu staatlich ausgestellten Dokumenten
- kompliziert
- relativ sicher

## FIDO2

Vom W3C (WWW Consortium)
FIDO = Fast IDentity Online

Ziele:
- sicherer als Passwörter

Ääh Dings
- Hardware-basierter Token

**Nutzerregistrierung**
- 
- Authenticator generiert Schlüsselpaar

## Browser Fingerprinting

### User Agent Request Header

Ich bin ein HTTP request header und ich enthalte Informationen (Systeminformationen, Browser, Auflösung, Dings)
-> nicht unbedingt einzigartig, ändert sich pro Gerät und nach Software-Updates
amiunique.org

## Risk Based Authentication


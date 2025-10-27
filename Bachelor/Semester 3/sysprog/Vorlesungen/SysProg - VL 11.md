Datum: 09.01.
[[Kapitel_3_Netzwerkprogrammierung_WS2324_v20231222_Teil1.pdf|Folien]] bis S. 61

# Netzwerkprogrammierung in C
*Kapitel 3*

## Wie funktioniert das Internet?

- Informationseinheiten werden paketweise über das **I**nternet **P**rotocol verschickt
- Ein IP-Paket ("Datagramm") besteht aus:
	- Header mit Absender- und Empfängerinfos
		- IP-Adresse
		- Protokoll
		- Portnummern
	- Daten
- Übersetzung von Web-Adresse in IP-Adresse: Domain Name System (DNS)
- Socket: Teil des Betriebssystem-Space

### Protokolle

#### IP
- Netzwerkprotokoll
	- Rechner $\leftrightarrow$ Router
	- Router $\leftrightarrow$ Router
- Ziel einzelner Datagramme als IP-Adresse (IPv4 oder IPv6) kodiert
- *Unzuverlässiges Protokoll:*
	- Es kann passieren:
		- Verlust von Datagrammen
		- Verdopplung
		- falsche Reihenfolge
		- Verfälschung (Bitfehler)
- Routing verläuft über IP
- Jeder Zwischenpunkt verwendet IP
- Alle anderen Netzwerkprotokolle bauen auf IP auf
#### UDP
- **User Datagram Protocol**
- Minimales, verbindungsloses und unzuverlässiges Protokoll
- Nutzt IP
- Wird nur von den Endpunkten verwendet
- Verwendet *Ports*, um Kommunikation mehrerer Prozesse parallel zu ermöglichen
- Datagramm enthält:
	- Source Port, Destination Port
	- Länge
	- Checksumme (optional)
	- Nutzdaten

#### TCP
- **Transmission Control Protocol**
- Komplexeres, verbindungsorientiertes und zuverlässiges Protokoll
- Nutzt IP
- Zwei-Wege-Kommunikation möglich (full duplex)
- Korrigiert Fehler von IP: Checksummen werden verwendet, bei bedarf werden Datagramme wiederholt/umsortiert/aussortiert
- Läuft ebenfalls über *Ports*
- Nutzdaten werden als Byte-Strom interpretiert (TCP entscheidet, wie die Segmentierung davon stattfindet)
- Wird verwendet für Web Browser

### Ports
- 21: FTP (nur TCP)
- 22: ssh
- 53: domain name server
- 80: http
- "Well known" ports: kleiner als 1024 
- Client-Prozesse können "beliebige" Portnummern bis 65535 verwenden

## Sockets

Jedes Betriebssystem stellt eine eigene API zur Verfügung, um die Netzwerkprotokolle zu verwenden.
- Sockets (ursprünglich "Berkeley Sockets") für Linux *$\leftarrow$ Sysprog*
- Winsock für Windows
- Asio C++ Library (plattformunabhängig)

*Eigenschaften von Sockets*
- Implementiert durch Menge von Systemfunktionen
- Ist eine Datenstruktur innerhalb eines Programms
- Abstrakte Repräsentation eines kommunizierenden Endpunktes

**Erzeugung**
```c
#include <sys/types.h>
#include <sys/socket.h>

int socket(int domain, int type, int protocol);
```

- `domain`: bestimmt Protokollfamilie
	- `AF_INET` für IPv4
	- `AF_INET6` für IPv6
	- `AF_LOCAL` oder `AF_UNIX` für lokale IPC
- `type`: bestimmt Socket-Typ
	- `SOCK_STREAM` für bytestromorientiertes Verfahren (bei Netzwerk: TCP)
	- `SOCK_DGRAM` für datagrammorientiertes Verfahren (bei Netzwerk: UDP)
	- `SOCK_RAW` für Direktzugriff auf Netzwerk via IP (z.B. für Routing)
- `protocol`: Spezialfeld für IP-Header
	- muss nur für `SOCK_RAW` gesetzt werden, ansonsten 0
- returnt file descriptor (nicht negativ), oder -1 wenn Fehler

`socket()` selbst kümmert sich nicht um die Adressierung, da ein Socket sehr generisch ist. 

> **Network Byte Order**
> Die Network Byte Order ist [[Glossar#Big-Endian|Big Endian]]. Wenn auf dem Hostsystem eine andere Byte Order vorliegt (wie z.B. bei Intel), muss alles in `sockaddr` konvertiert werden.
> 
> Dafür gibt es `htons()` (16 Bit, z.B. Ports) und `htonl()` (32 Bit, z.B. IPv4-Adresse) für Host zu Network, und `ntohs()` und `ntohl()` für Network to Host. Diese Funktionen sind im Header `<netinet/in.h>`.

**Adressierung**
Datenstruktur für Netzwerkadressen: `struct sockaddr_in`.

```c
struct sockaddr_in addr;
addr.sin_family = AF_INET;
addr.sin_port = htons(4711);
addr.sin_addr.s_addr = htonl(INADDR_ANY);
```

Wenn `sin_port = 0`: Betriebssystem wählt Port automatisch
Wenn `INADDR_ANY`: Betreibssystem wählt eigene IP-Adresse

Umwandlung von IPv4-Strings in bytes (network byte order):
```c
#include <arpa/inet.h>

in_addr_t inet_addr(const char* dotted); // dotted to network
char* inet_ntoa(struct in_addr network); // network to dotted
```

**Binden**
```c
#include <sys/types.h>
#include <sys/socket.h>

int bind(int sockfd, const struct sockaddr *myaddr, socklen_t addrlen);
```

- `sockfd`: File Descriptor des Sockets
- `myaddr`: Die Adresse, an den der Socket gebunden werden soll
	- Im Falle von Netzwerkverbindungen: `struct sockaddr_in` (muss zu `struct sockaddr` gecastet werden)

Wenn Prozess einen Port bindet und dann abstürzt, gibt das Betriebssystem den Port nicht sofort frei. Man muss ggf. auf Timeout warten oder neustarten.

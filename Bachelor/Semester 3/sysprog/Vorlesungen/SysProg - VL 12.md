Datum: 16.01.

[[Kapitel_3_Netzwerkprogrammierung_WS2324_v20231222_Teil1.pdf|Folien (UDP)]] - S. 62 bis Ende
[[Kapitel_3_Netzwerkprogrammierung_WS2324_v20240112-Teil2.pdf|Folien (Rest)]] - bis S. 29

# Netzwerkkommunikation über Sockets

## UDP

![[UDP-Kommunikation.png|500]]

**Senden**

```c
#include <sys/types.h>
#include <sys/socket.h>

int sendto(int sockfd, const void* buff, size_t nbytes,
		  int flags, const struct sockaddr* to, socklen_t tolen);
```

- `sockfd`: file descriptor vom Socket
- `buff`: Nachricht
- `nbytes`: Länge der Nachricht in Bytes
- `flags`: Optionen, Standard ist 0
- `to`: Adressstruktur für Empfänger
- Returnt: Anzahl der gesendeten Bytes, -1 wenn Fehler

**Empfangen**

```c
#include <sys/types.h>
#include <sys/socket.h>

int recvfrom(int sockfd, void* buff, size_t nbytes, int flags,
			 struct sockaddr* from, socklen_t* fromlen);
```

- `buff`: Puffer, in den die Nachricht kommt
- `nbytes`: Größe des Puffers

Blockiert so lange, bis Datagramm empfangen wurde.
Für Antwort: Adresse von `from` auslesen (`ntoa` bzw. `ntohs` nicht vergessen).

### Adressierung

Aus Sicht des Client:
- Eigener TCP-Port: automatisch zugewisen (von Betriebssystem)
- Eigene IP-Adresse: automatisch zugewiesen (von IP basierende auf Routing)
- Server-UDP-Port & IP-Adresse: muss explizit angegeben werden (bei `sendto()`)

Aus Sicht des Servers:
- Eigener UDP-Port: (i.d.R.) explizit angegeben (bei `bind()`)
- Eigene IP-Adresse: automatisch zugewiesen
- Client-UDP-Port & IP-Adresse: über `recvfrom()` bestimmt

## TCP

![[TCP-Kommunikation.png|500]]

**Listen**
```c
#include <sys/socket.h>

int listen(int sockfd, int backlog);
```

- `backlog`: Anzahl der Verbindungsaufbauvorgänge, die gleichzeitig möglich sind
	- Insbesondere dann relevant, wenn man einen iterativen Server hat
- Returnt 0 bei Erfolg und -1 bei Fehler

**Connect und Accept**
```c
#include <sys/types.h>
#include <sys/socket.h>

int connect(int sockfd, const struct sockaddr* serv_addr, socklen_t addrlen);
int accept(int sockfd, struct sockaddr* addr, socklen_t* addrlen);
```

- `connect`:
	- blockiert
	- returnt 0 oder -1
- `accept`:
	- blockiert
	- returnt neuen Socket file descriptor, der zur neuen Verbindung gehört und über den mit `read` und `write` dann Nachrichten über TCP versendet werden können (oder -1)

`read()`, `write()` und `close()` kommen aus `<unistd.h>`, arbeiten also allgemein auf file descriptors.

**Shutdown**
Anstatt `close()` kann man mit `shutdown()` den Socket nur in eine Richtung schließen:
```c
#include <sys/socket.h>

int shutdown(int sockfd, int howto);
```
- `howto`:
	- `SHUT_RD`: Schließen in Leserichtung $\to$ kein `read()` mehr möglich
	- `SHUT_WR`: Schließen in Schreibrichtung $\to$ kein `write()` mehr möglich
	- `SHUT_RDWR`: Schließen in beide Richtungen

### Adressierung

Aus Sicht des Client:
- Eigener TCP-Port: automatisch zugewisen (von Betriebssystem)
- Eigene IP-Adresse: automatisch zugewiesen (von IP basierend auf Routing)
- Server-TCP-Port & IP-Adresse: muss explizit angegeben werden (bei `connect()`)

Aus Sicht des Servers:
- Eigener TCP-Port: (i.d.R.) explizit angegeben (bei `bind()`)
- Eigene IP-Adresse: automatisch zugewiesen
- Client-TCP-Port & IP-Adresse: über `accept()` bestimmt

## Hilfsfunktionen

| **Gewünschte Informationen** | **TCP-Server** | **UDP-Server** |
| ---- | ---- | ---- |
| Quell-IP-Adresse,<br>Quell-Portnummer | `accept()` oder `getpeername()` | `revcfrom()` |
| Ziel-IP-Adresse | `getsockname()` | `recvmsg()` |
| Destination-Portnummer | `getsockname()` | `getsockname()` |

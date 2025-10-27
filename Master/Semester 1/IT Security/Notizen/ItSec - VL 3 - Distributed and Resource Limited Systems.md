Datum: 23.10.

# Cyber Security of Distributed and Recource-Limited Systems
[[Master/Semester 1/IT Security/Slides/03 Cyber Security of Distributed and Resource-constrained Systems.pdf|Folien]]

Wir haben ein System mit mehreren Parteien.

Die Parteien möchten untereinander geheim Informationen austauschen.
Wir möchten Operationen für Gruppenmitgliedschaft sicher umsetzen:
- Hinzufügen/Entfernen eines Nutzers
- Zusammenführen/Teilen mehrerer Gruppen

## Vertraulichkeit

Kann durch Verschlüsselung (z.B. IPsec) gewährleistet werden:
- Nachricht $m$
- Schlüssel $k$
- Verschlüsselung $E(m,k)$

Der Schlüssel $k$ muss *dynamisch* sein, wenn sich das System ändert.

### Needham-Schroeder-Protokoll

Zwei Parteien $u_{1},u_{2}$ möchten miteinander kommunizieren.
Es gibt einen Group Controller $GC$ in der Mitte.

Der $GC$ teilt sich einen Schlüssel jeweils mit $u_{1}$ und $u_{2}$ ($k_{1,GC}$ und $k_{2,GC}$)

Grundidee:
- $GC$ generiert einen Schlüssel $k_{1,2}$ für Kommunikation zwischen $u_{1}$ und $u_{2}$
- $GC$ schickt $k_{1,2}$ an $u_{1}$
- $GC$ schickt ein Ticket an $u_{1}$
- Das Ticket ist verschlüsselt mit $k_{2,GC}$ und enthält $k_{1,2}$
- $u_{1}$ schickt das Ticket an $u_{2}$

Nun haben beide den gemeinsamen Schlüssel $k_{1,2}$ und können damit Nachrichten verschlüsseln. Nur $u_{1}$ muss mit $GC$ kommunizieren.

Es werden auch immer Nonces hin und her gesendet (Werte zur einmaligen Verwendung), um sicherzugehen, dass Antworten vom $GC$ keine Aufzeichnungen vorheriger Konversationen sind (Replay Attack).

*Probleme:*
- $GC$ ist single point of failure
- Netzwerk-Mitgliedschaftsoperationen nicht unterstützt
- Anzahl paarweiser Schlüssel wächst quadratisch mit Mitgliederzahl

-> wir brauchen einen **Group Key**.

### Group Key
Anforderungen:
- Nur authorisierte Nutzer haben den Group Key
- Group Key ändert sich, wenn sich die Gruppe ändert
- Forward Secrecy: neue Nutzer erhalten keinen alten Group Key
- Backward Secrecy: verlassende Nutzer erhalten keinen neuen Group Key

*Konzept:* jeder Nutzer trägt zum Group Key bei (iterativer Diffie-Hellman-Algorithmus).

Vorteile:
- Es ist einfacher, vielen Nutzern anstelle von einem GC zu vertrauen
- kein Single Point of Failure
- Partitionen und Zusammenführung von Netzwerken möglich

Nachteil: bei Netzwerken mit hohem Paket-Loss ist die Schlüsselgenerierung schwierig


> [!info] *Grundlagen Diffie-Hellman*
> > Alice und Bob haben jeweils einen Private Key $p_{A},p_{B}$ und einen Public Key $pk_{A},pk_{B}$.
> > Die Kombination von $k_{A}$ und $pk_{B}$ ist gleich der Kombination von $pk_{A}$ und $k_{B}$. Dies ergibt ein *shared secret* zwischen Alice und Bob.
> 
> Berechnung: 
> - Alice und Bob einigen sich auf eine Primzahl $p$ und eine natürliche Zahl $g<p$. Alle Berechnungen sind dann Exponentation des Generators $g$ im $\mathbb{Z}_{p}$.
> - Alice und Bob wählen einen zufälligen Private Key $k_{A},k_{B} \in \mathbb{Z}_{p}$.
> - Die Public Keys sind: 
>	- $pk_{A}=g^{k_{A}} \mod p$
>	- $pk_{B}=g^{k_{B}} \mod p$
> - Das Shared Secret ist:
> 	- $(pk_{A})^{k_{B}} \mod p = (pk_{B})^{k_{A}} \mod p = k_{A,B}$
> 
> Letztendlich ist $k_{A,B}=g^{k_{A} \cdot k_{B}} \mod p$, ohne dass $k_{A}$ oder $k_{B}$ mit irgendwem ausgetauscht werden mussten.
> 
> Der Public Key heiß bei uns **Blind Key**, warum auch immer.

Grafische Darstellung:
![[Two-party Diffie Hellman.png]]

#### Tree-Based Group Diffie-Hellman (TGDH)

Wir haben unsere User in einem **Binärbaum**. 
- Ein Node besteht aus einem Public Key und einem Private Key.
- Jeder Nutzer ist ein Blattknoten.
- Um den private Key von einem inneren Knoten zu berechnen, verwendet man das Diffie-Hellman-Verfahren mit dem Private Key von einem Kind und dem Public Key vom anderen Kind.
- Das Shared Secret für die ganze Gruppe ist der Private Key vom Wurzelknoten
	- -> kann nur berechnet werden, wenn man mindestens einen private Key kennt, i.e. wenn man Teil der Gruppe ist.

Schlüsselberechnung aus Sicht des Users $u_{3}$:
![[Tree-based Group Diffie-Hellman.png]]

Join: 
ein neuer User muss sich mit irgendeinem Gruppenmitglied an einen neu geschaffenen inneren Knoten hängen. 
Alle Schlüsselpaare von den jeweiligen Elternknoten, bis rauf zum Wurzelknoten, werden dann neu berechnet.
Das ausgewählte Gruppenmitglied, das den Knoten wechselt, heißt *Sponsor*.

Leave: 
Der Nachbar-User vom verlassenden Mitglied wandert einen Node nach oben, dann passiert die Schlüsselberechnung bis rauf zum Wurzelknoten erneut.

Netzwerk-Zusammenführung oder -Trennung ist über diese Bäume ist ebenfalls möglich.

## Integrität und Authentizität

Wir haben die Situation, dass kein einzelner User einen geheimen Schlüssel allein bestimmen können soll.

Bei einem k-out-of-n secret sharing müssen mind. k User zusammenarbeiten, um das shared secret $s$ zu bestimmen.

Jeder user $i$ hat einen geheimen Schlüssel $s_{i}$.

**Linear Secret Sharing:**
Additive Rekonstruktion: $s=s_{1}+s_{2}+\dots+s_{n}$ 
-> n-out-of-n secret sharing

**Samir's Secret Sharing:**
Die $s_{i}$'s sind Punkte auf einem Polynom vom Grad $k-1$ (modulo Primzahl $p$). Nun kann man mit $k$ Punkten und Lagrange-Interpolation dieses Polynom berechnen. Das shared secret ist der y-Achsen-Abschnitt des Polynoms.
-> k-out-of-n secret sharing (threshold secret sharing).

> [!example] *E-Voting System*
> Es gibt einen Wähler $V$ und $n$ Instanzen der Behörde, $A_{1},\dots,A_{n}.$
> Die Behörden haben einen public key $e$, einen private key $d_{i}$ und Modulus $N$.
> 
> *Schritt 1:* Wähler verschlüsselt seine Stimme $x$ mit private key $r$.
> $$x'=x \cdot r^{e} \mod N$$
> Nun wird $x'$ an alle $n$ Behörden verschickt.
> 
> *Schritt 2:* Behörden erstellen Signaturen $s_{i}'$ der Stimme.
> $$s_{i}' = (x')^{d_{i}} \mod N$$
> Die Signaturen werden zurück an den Wähler geschickt.
> 
>*Schritt 3:* Der Wähler berechnet die Signatur $s$ für seine Stimme.
> $$\begin{align}s'&=\prod_{i=1}^{n}s_{i}' \\
s &= s'r^{-1}\mod N\end{align}$$
> Diese Signatur kann er nun anonym zusammen mit seiner Signatur an die Behörden schicken.
> 
> *Schritt 4:* Behörden können die Stimme verifizieren und zählen.
> $$s \stackrel{?}{=}Ver(x,e)$$
> 
> Man teilt das Ganze auf $n$ Authoritäten auf, damit nicht einzelne Behörden die Wahl verfälschen können (man braucht alle $n$ für die Signatur).


## Blobchain


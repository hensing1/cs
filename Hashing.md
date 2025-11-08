## Hashfunktionen
Eine Hashfunktion $h$ bildet Werte aus einem Universum $U$ auf einen Wertebereich der Größe $m$ ab, wobei $m \ll |U|$. 

Hashfunktionen können sehr gut für Datenstrukturen verwendet werden, bei denen man sehr schnelle Zugriffsoperationen umsetzen möchte. Hierbei wird ein Wert mit Schlüssel $k \in U$ an der Stelle $h(k)$ abgespeichert.
Da es hierbei zu Kollisionen kommen kann, ist es wichtig, dass $h^{-1}(i)=\set{k \in U \space | \space h(k)=i}$ für jedes $i$ etwa gleich groß ist, d.h. dass ungefähr immer gleich viele Werte auf denselben Hash abgebildet werden. Darüber hinaus sollten keine Gruppen von Werten, die sich im Anwendungsfall häufen könnten, denselben Hashwert erhalten (z.B. wäre eine Hashfunktion, die immer den Anfangsbuchstaben eines Strings nimmt, ungeeignet für das Abspeichern von Nachnamen).

Wie genau man seine Hashfunktion parametrisiert, damit diese Eigenschaften erfüllt sind, ist eher Kunst als Wissenschaft.

> [!info]- Beispiele für Hashfunktionen
> Für $U=\mathbb{N}$:
> - **Divisionsmethode**: $h(k)=k\mod m$
> 	- $m$ ist typischerweise Primzahl
> 	- $m$ sollte keine Zweierpotenz sein, da sonst alle höherwertigen Bits ignoriert werden, wodurch es öfter zu Häufungen kommen kann
> - **Multiplikationsmethode**: $\lfloor m(kA-\lfloor kA\rfloor)\rfloor$, also Semi-Zufällige nachkommastellen multipliziert mit irgendeinem Wert
> 	- $A=\Phi - 1$ ist hierfür ganz gut geeignet
>
> ---
> Für Strings:
> - Javas `int hashCode()` berechnet $\sum\limits_{i=0}^{l-1}s_{i}\cdot31^i$
> 
> ---
> Datenspeicherung:
>  - Fowler-Noll-Vo (FNV), jenkins (lookup3), MurmurHash
> 
> Kryptographie:
> - MD2, MD4, MD5 (alle unsicher)  
> - SHA-2, z.B. SHA-256 (Hash hat 256 bit)  
> - MD6, SHA-3 (Keccak)  
> - Bcrypt, Scrypt, LM-Hash, PBKDF2

Im Folgenden wird die Laufzeit einer Hashfunktion immer als $\Theta(1)$ angenommen.

## Handlen von Kollisionen
### Verkettete Liste
Wir haben an jedem $h(k)$ eine Verkettete Liste, wo die Elemente abgespeichert werden, die auf $h(k)$ abgebildet werden.

Wie lang ist erwartungsgemäß eine solche Liste?
Sei $\alpha=n/m$ der Auslastungsfaktor der Hashtabelle. Dann ist erwartungsgemäß, wenn von *uniformem Hashing* ausgeht, an jedem $h(k)$ eine Liste mit $\alpha$ Elementen.

Da für `Search(k)` und `Delete(k)` jeweils einmal die entsprechende verkettete Liste durchlaufen wird, beträgt für beide Operationen die erwartete Laufzeit $\Theta(1+\alpha)$ (kann praktisch natürlich mehr sein, im Worst Case $\Theta(n)$).[^1]

Für `Insert(x)` ist die Laufzeit $\Theta(1)$, wenn man nicht nach doppelten Elementen sucht. Sonst ist sie natürlich auch $\Theta(1+\alpha)$.

[^1]: Die erwartete Laufzeit für eine erfolgreiche Suche auszurechnen ist etwas tricky, da natürlich der gesuchte Wert wahrscheinlich in längeren Listen auftaucht. Konkret kommt $1+\frac{\alpha}{2}-\frac{1}{2m}$ raus, was auch in $\Theta(1+\alpha)$ liegt.

### Geschlossenes Hashung
auch: **Hashing mit offener Adressierung**

Idee: man erweitert seine Hashfunktion um einen zweiten Parameter, der von $0$ bis $m-1$ hochzählt: $h:U\times\set{0,1,\ldots,m-1}\rightarrow\set{0,1,\ldots,m-1}$. Man testet bei `Insert` nun solange $h(k,0),h(k,1),h(k,2),\ldots$ bis man ein freies Feld gefunden hat. 
Hierbei ist davon auszugehen, dass $h(k,0),h(k,1),\ldots,h(k,m-1)$ eine Permutation von $\set{0,1,\ldots,m-1}$ ist, dass man also auf keinem Feld zweimal nachguckt. Man nennt diese Permutation auch *Sondierungsreihenfolge*.

Wenn man nun nach einem Wert sucht, geht man nacheinander wieder $h(k,0),h(k,1),h(k,2),\ldots$ durch, bis man den gesuchten Wert gefunden hat. Trifft man irgendwann auf ein leeres Feld, kann man mit der Suche aufhören.

Das führt aber zu Problemen, wenn man Sachen wieder rauslöscht - dann weiß man nämlich nicht mehr, ob eine Lücke deshalb existiert, weil nie etwas eingefügt wurde, oder weil etwas gelöscht wurde (in letzterem Fall könnte der gesuchte Wert noch hinter der Lücke sein). Deshalb kann man ein zusätzliches Feld der Länge $m$ nehmen, in dem man speichert, ob an der Stelle $h(k)$ schon mal etwas gelöscht wurde. Dann kann man erst mit der Suche aufhören, wenn man ein leeres Feld findet, bei dem zusätzlich der Lösch-Wahrheitswert auf `false` steht.

Wenn man jetzt oft was aus der Tabelle rauslöscht, hat man natürlich irgendwann das Problem, dass in den meisten Feldern irgendwann schon mal was drin war, und deshalb im Extremfall bei einer erfolglosen Suche die gesamte Sondierungsreihenfolge abgearbeitet werden muss. Das ist natürlich extrem ineffizient, daher wird das geschlossene Hashing meistens nur dann verwendet, wenn man (fast) nie was löschen muss - in diesem Fall ist es tatsächlich effizienter als das Hashing mit verketteten Listen, da weniger Overhead vorhanden ist.

#### Definition der Sondierungsreihenfolge
##### Lineares Sondieren
`h(k,i)=( h'(k) + i ) mod m`

Der Nachteil an dieser Sondierung ist, dass die Tendenz besteht, lange zusammenhängende Blöcke zu bilden - je länger der Block, desto höher die Wahrscheinlichkeit, das nächste eingefügte Element an das Ende dieses Blocks gefügt wird - das ist natürlich doof für die Laufzeit, wenn immer riesige Blöcke abgesucht werden müssen

##### Quadratisches Sondieren
`h(k,i)=( h'(k) + i^2 ) mod m`

Besser als lineares Hashing, da z.B. $h(k_{1},0)=h(k_{2},1)\not\Rightarrow h(k_{1},1)=h(k_{2},2)$ (anders als beim linearen Hashing.

##### Doppeltes Hashing
Man nimmt eine zweite Hashfunktion $h''$:
`h(k,i)=( h'(k) + i * h''(k) ) mod m`

#### Laufzeit
Mit $\alpha=n/m$ als Auslasungsfaktor beträgt der Erwartungswert für die durchsuchten Positionen bei einer erfolglosen Suche höchstens $1/(1-\alpha)$.[^2]

Insgesamt liegt die Laufzeit von `Search(k)` in $\mathcal{O}(\frac{1}{\alpha}\ln(\frac{1}{1-\alpha}))$. Dass dieser Term so viel geringer ist als der für die erfolglose Suche liegt daran, dass man für die Suche nach dem $i$-ten eingefügten Element genau die Felder durchlaufen muss, die auch beim Einfügen durchlaufen werden mussten, und das wiederum kann man (wie oben) abschätzen durch $1/(1-(i/m))$.

Hier ist das ganze als Graph, in Blau ist der Worst-Case (bzw. die erfolglose Suche) und in Rot die erwartete Suchlaufzeit. Man sieht, dass selbst bei einem relativ hohen Auslastungsfaktor wie 0.8 die Werte immer noch relativ klein sind.
![[Laufzeit_Geschlossenes_Hashing.png|500]]

[^2]: Die Wahrscheinlichkeit, dass *mindestens* $i$ Positionen durchsucht werden, ist $Pr[X\geq i]=\frac{n}{m}\cdot \frac{n-1}{m-1} \ldots \frac{n-(i-2)}{m-(i-2)}\leq\alpha^{i-1}$. Damit ist $E[X]=\sum\limits_{i=1}^{\infty}Pr[X\geq i] \leq \sum\limits_{i=1}^{\infty}\alpha^{i-1}\leq \frac{1}{1-\alpha}$.
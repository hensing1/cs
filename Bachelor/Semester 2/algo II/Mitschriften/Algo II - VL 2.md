Datum: 19.04.
[[Folien-2023-4-18.pdf|Folien]]
[[Skript AlgoII.pdf|Skript:]] Seiten 14 bis 24

*Kapitel 2: Grundlagen*
# Rechnermodelle
## Mehr zu Turingmaschinen

![[Turingmaschine#Akzeptanzverhalten]]


![[Turingmaschine#Methoden zum Entwurf einer Turingmaschine]]

### Rechenzeit und Platzbedarf
> [!abstract] Definition
> Für eine $k$-Band-Turingmaschine $M$ beschreibt
> - $t_M(w)$ die Anzahl an Rechenschritten für eine Eingabe $w$ (**Rechenzeit**),
> - $s_M(w)$ die Anzahl der Speicherzellen (summiert über alle Bänder), auf denen sich bei der Bearbeitung der Eingabe $w$ mindestens einmal ein Kopf befunden hat (**Platzbedarf**),
> - $t_M(n)$ die *maximale Rechenzeit* bei Eingaben der Länge $n$,
> - $t_M(n)$ der *maximale Platzbedarf* bei Eingaben der Länge $n$.

> Eine $k$-Band-TM mit Rechenzeit $t(n)$ und Platzbedarf $s(n)$ kann durch eine 1-Band-TM mit Rechenzeit $\mathcal{O}(t(n)^2)$ und Platzbedarf $\mathcal{O}(s(n))$ simuliert werden.

Das geht, indem man eine TM mit $2k$ *Spuren* nimmt und auf jeder zweiten Spur den Zustand eines Bandes, und auf den dazwischenliegenden Spuren die Position des entsprechenden Kopfes durch ein Symbol an der entsprechenden Stelle, z.B. `#`, abspeichert. 
Ein simulierter Rechenschritt läuft dann wie folgt ab:
- Schiebe den Kopf solange nach rechts, bis alle `#`-Markierungen gesehen wurden. Merke dir im Zustand, welche Zeichen sich gerade an den Kopfpositionen befinden.
- Werte die Zustandsübergangsfunktion der simulierten TM aus und merke dir im Zustand deren neuen Zustand, die neuen Zeichen und die Bewegungen der Köpfe.
- Schiebe den Kopf wieder nach links zurück und aktualisiere die Bänder und Kopfpositionen entsprechend, bis alle $k$ Kopfpositionen gesehen wurden.

Da Köpfe bei jedem Schritt höchstens $t(n)$ Zellen voneinander entfernt sein können, muss die simulierende TM auch höchstens $t(n)$ Zellen hin- und zurückwandern. Dadurch liegt die Rechenzeit insgesamt in $\mathcal{O}(t(n)^{2})$.

## Registermaschinen
Wie auch schon in Algo I legen wir unseren algorithmischen Betrachtungen eine Registermaschine zugrunde. 
- Wir haben einen Instruktionszeiger $b$. Am Anfang gilt $b=1$.
- $c(i)$ bezeichnet den Inhalt des Registers an der Speicherstelle $i$. Es gilt $c(i) \in \mathbb{N}_{0}$.
	- $c(0)=0$
	- $c(1),\ldots,c(N)$ enthalten die Eingabe
	- alle anderen Register sind null
- Wir haben einen simplen Instruktionssatz (alle Befehle arbeiten mit dem Register $c(0)$ und einem weiteren):
	- Bedingte und unbedingte Sprungbefehle
	- Laden und Speichern
	- Simple Arithmetik
- Wir haben ein *logarithmisches Kostenmaß*, d.h. die Operationen dauern linear in der Länge der Eingabe

Man kann zeigen, dass man mit dieser Registermaschine eine Turinmaschine simulieren kann und andersrum. Die Turingmaschine benötigt dabei nur polynomiell mehr Laufzeit.

Wir nennen eine Register- oder Turingmaschine *$t(n)$-Zeitbschränkt*, wenn deren Rechenzeit für jedes $n\in\mathbb{N}$ und jede Eingabe der Länge $n$ durch eine Funktion $t(n)$ beschränkt ist.

![[Berechenbarkeitstheorie#Church-Turing-These]]
Datum: 30.01.

**Wiederholung**
TCP mit fork:
- nach fork: zwei Prozesse mit jeweils zwei Sockets
	- im parent-Prozess: schließe Connection-FD
	- im child-Prozess: schließe Listen-FD (beides mit close)
- `accept()` returnt immer dann, wenn eine neue Verbindung aufgebaut wurde
- `close()` schließt einen Socket nur dann, wenn keine aktive FD's mehr darauf zugreifen
	- merkt sich im Hintergrund, wieviele FD's (hier: wieviele Prozesse) auf diesen Socket zugreifen

Problem mit fork: langsam
Lösungen:
- Threads
- Pre-Forked Server
	- man macht beim Serverstart $n$ forks
	- Jeder Kindprozess macht `accept()` in Endlosschleife
	- Der Parent-Prozess tut nichts
	- Apache ist pre-forked
- Select Loop


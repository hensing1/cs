Datum: 03.05.
[[Folien-2023-5-03.pdf|Folien]]
[[Skript AlgoII.pdf|Skript:]] Seiten 38 bis 44
[Video](https://uni-bonn.sciebo.de/s/YVfBpu1J5oiqZGj#/files_mediaviewer/Vorlesung-04.mp4)

*Kapitel 3: Berchenbarkeitstheorie*
# Rekursiv aufzählbare Sprachen
![[Turingmaschine#^0f2a29]]

Zum Beispiel kann man die Haltesprache erkennen, indem man für eine Eingabe $\langle M \rangle w$ die Maschine $M$ auf die Eingabe $w$ simuliert und dann akzeptiert, wenn $M$ terminiert.

## Abschlusseigenschaften
### Schnitt und Vereinigung
![[Berechenbarkeitstheorie#^a14b13]]

*Beweis:*
Wenn $L_1$ und $L_2$ rekursiv aufzählbar sind, dann gibt es zwei Turingmaschinen $M_1$ und $M_2$, die jeweils $L_1$ und $L_2$ erkennen.

Um den Schnitt dieser beiden Sprachen zu berechnen, reicht es, erst $M_1$ und dann $M_2$ auf derselben Eingabe zu simulieren. Akzeptieren beide, wird die Eingabe auch akzeptiert. Anderenfalls wird verworfen bzw. nicht terminiert.

Die Vereinigung läuft genauso, nur dass man eine Eingabe akzeptiert, wenn $M_1$ *oder* $M_2$ sie akzeptieren. Um das korrekte Ergebnis zu berechnen, müssen $M_1$ und $M_2$ jedoch *parallel* simuliert werden. Das Wort wird dann akzeptiert, sobald es eine der beiden Maschinen akzeptiert hat.

### Komplement
![[Berechenbarkeitstheorie#^0b12fe]]

*Beweis:*
Man kann eine Turingmaschine bauen, die jedes Wort aus $L$ akzeptiert. Außerdem kann man eine zweite Turingmaschine bauen, die jedes Wort aus $\bar{L}$ akzeptiert. Simuliert man diese beiden Turingmaschinen parallel, ist es garantiert, dass eine von beiden mit dem korrekten Ergebnis terminiert.

*Konsequenz*
Weiß man über eine Sprache $L$, dass sie rekursiv aufzählbar aber nicht entscheidbar ist, dann kann $\bar{L}$ nicht rekursiv aufzählbar sein.

## Reduktionen
![[Reduktionen#^5e4d90]]

## Aufzähler
> Ein Aufzähler für eine Sprache $L$ ist einer Turingmaschine, die jedes Wort aus $L$ nach und nach auf ein zusätzliches Ausgabeband schreibt (sie erhält keine Eingabe).
> Sie schreibt kein Wort auf, welches nicht zu $L$ gehört, und für jedes Wort $w\in L$ gibt es einen Index $i_{w}\in \mathbb{N}$, sodass $w$ nach $i_w$ Schritten auf dem Ausgabeband steht.

Wenig überraschend ist eine Sprache genau dann rekursiv aufzählbar, wenn es einen Aufzähler für sie gibt:
- Mit einem Aufzähler kann man eine TM bauen, die eine Sprache erkennt. Hierfür muss man lediglich den Aufzähler so lange simulieren, bis er die Eingabe auf das Ausgabeband schreibt.
- Mit einer TM $M$, die eine Sprache erkennt, kann man einen Aufzähler für diese Sprache bauen. Hierfür simuliert man alle Wörter aus $\Sigma ^{\ast}$ parallel auf $M$: erst 1 Schritt für $w_1$, dann 2 Schritte für $w_1$ und $w_2$, dann 3 Schritte für $w_1$, $w_2$, und $w_3$, usw. Sobald ein Wort $w_{i}$ akzeptiert wird, wird es auf das Ausgabeband geschrieben.

Bei einem Aufzähler ist weder die Reihenfolge für die Wörter vorgegeben, noch wird verlangt, dass jedes Wort genau einmal auf das Ausgabeband geschrieben wird. 
Genau dann, wenn es einen *kanonischen Aufzähler* gibt, welcher alle Wörter in kanonischer Reihenfolge ausgibt, ist die Sprache entscheidbar.

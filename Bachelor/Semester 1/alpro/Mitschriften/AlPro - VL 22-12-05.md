Datum: 05.12.
Folien: [[04_Algorithmen_Teil_2_07.pdf|Algorithmen Teil 2 - 07]]

# AVL-Bäume
Wir besprechen das [[AVL-Bäume#Operationen#Delete|Löschen aus AVL-Bäumen]] (und die ganzen Rotationen im Allgemeinen).

Im Hinblick auf die Begrifflichkeiten wird betont, dass AVL-Bäume *geordnete Mengen* realisieren. Damit gehören sie zu den *assoziativen Containern*, die wiederum ein Subtyp der *iterierbaren Container* sind.

Von geordneten Mengen werden *geordnete Abbildungen* unterschieden. Abbildungen werden dadurch ausgezeichnet, dass es Key/Value-Paare mit untereinander vergleichbaren Keys gibt.
Insofern kann auch eine geordnete Abbildung durch einen AVL-Baum realisiert werden, da man darin die Keys speichern kann.

# Hashende Multimenge
Wir besprechen, wie man [[Hashing#Verkettete Liste|Hashtabellen mit verketteten Listen]] umsetzt. 
Die Anzahl der Buckets wird verdoppelt / halbiert, wenn $\alpha \geq 0.75$ bzw. $\alpha \leq 0.25$ ist. In welchen Bucket ein Element mit Schlüssel $k$ kommt, wird berechnet mit $h(k) \mod \text{Anzahl Buckets}$.
Datum: 22.12.
[[21VL-Scan-Euklidischer-Algorithmus.pdf|Folien]]

# Nochmal was zu Körpern
Betrachte $(\mathbb{Z}_{6},\odot_6)$.
Die Einheitengruppe davon ist $\set{[1],[5]}$. Man könnte dann ja jetzt auf die Idee kommen, dass $(\set{[0],[1],[5]},\oplus_6,\odot_6)$ ein Körper ist.
Das ist aber nicht so, denn dafür müsste $(\set{[0],[1],[5]},\oplus_6)$ eine abelsche Gruppe sein. $\oplus_{6}$ ist auf diese Menge aber gar keine Verknüpfung, da z.B. $[5] \oplus_6 [5] = [4] \not\in \set{[0],[1],[5]}$ - es ist also nicht abgeschlossen.

# Euklidischer Algorithmus

> Der euklidische Algorithmus berechnet den *[[Glossar#Größter gemeinsamer Teiler|größten gemeinsamen Teiler]]* zwischen zwei ganzen Zahlen.

Die Berechnung des GGT geht schnell, das Berechnen der Primfaktoren aber nicht. Das ist der Grund, warum man mit RSA schnell ver- und entschlüsseln kann, aber das Knacken der Verschlüsselung sehr lange dauert.

![[Euklidischer Algorithmus#Beschreibung]]

![[Euklidischer Algorithmus#Funktionsweise]]

Aus dem euklidischen Algorithmus ergibt sich nun folgendes Lemma:

> Für zwei Zahlen $a,b \in \mathbb{Z}$ mit $d=\text{ggT}(a,b)$ gibt es $x,y \in \mathbb{Z}$, sodass $ax+by=d$.

Sei $d=x_{i}$. Man kann jedes $x_{k}$ als *Linearkombination* der zwei vorhergehenden $x_k$s darstellen:
$$
\begin{aligned}
d=x_{i}&=x_{i-2}-q_{i-1} \cdot x_{i-1}\\
x_{i-1}&=x_{i-3}-q_{i-2} \cdot x_{i-2}\\
x_{i-2}&=x_{i-4}-q_{i-3} \cdot x_{i-3}\\
\vdots\\
x_{2}&=x_{0}-q_{1} \cdot x_{1}
\end{aligned}
$$
Wenn man nun in der ersten Zeile für $x_{i-1}$ die zweite Zeile einsetzt und ein bisschen umformt, erhält man:
$$
\begin{aligned}
d&=-q_{i-1} \cdot x_{i-3} + (1+q_{i-1}q_{i-2})x_{i-2}\\
&= a_{i-3} \cdot x_{i-3}+b_{i-2} \cdot x_{i-2} & \text{(Linearkombination!)}
\end{aligned}
$$

Jetzt kann man wiederum für $x_{i-2}$ einsetzen und erhält:
$$d=a_{i-4} \cdot x_{i-4} + b_{i-3} \cdot x_{i-3}$$
Das kann man nun immer so weitermachen, bis man mit $d=a_{0}x_{0}+b_{1}x_{1}$ eine Linearkombination für seine ursprünglichen Zahlen $x_0$ und $x_1$ gefunden hat. Die Koeffizienten setzen sich hierbei dann zusammen aus $q_1,q_2,\ldots,q_{i-1}$ aus dem Eulerschen Algorithmus.

![[Euklidischer Algorithmus#Laufzeit]]
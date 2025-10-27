Datum: 11.04.
Inhalt: [[ThR_LA_Skript.pdf]] - Seiten 12 bis 15

# Lineare Gleichungssysteme
## Gauß-Algorithmus
Ein LGS lässt sich vereinfacht mit einer *erweiterten Koeffizientenmatrix* darstellen:
$$
\begin{pmatrix}
    a_{1,1} & \ldots & a_{1,m}  &\bigm| & b_{1} \\
    \vdots  & \ddots & \vdots   &\bigm| & \vdots \\
    a_{n,1} & \ldots &  a_{n,m} &\bigm| & b_{n}
\end{pmatrix}
$$

Dies ist die übliche Darstellungsweise bei der Verwendung des Gauß-Algorithmus.

Der Gauß-Algorithmus fußt nun auf den folgenden Sätzen:

> **Skalierung von Gleichungen** 
> Die Gleichung $$a_{1}x_{1}+\ldots+a_{m}x_{m}=b$$ ist äquivalent zu der Gleichung $$\lambda a_{1}x_{1}+\ldots+\lambda a_{1}x_{1}=\lambda b$$ für $\lambda\neq 0$. Das bedeutet, man kann eine lineare Gleichung beliebig mit einem Faktor $\lambda$ skalieren.

> **Addition linearer Gleichungen**
> Der Ausdruck $$a_{1}x_{1}+\ldots+a_{m}x_{m}=b \land a_{1}'x_{1}+\ldots+a_{m}'x_{m}=b'$$ ist äquivalent zu $$a_{1}x_{1}+\ldots+a_{m}x_{m}=b \land (a_{1}'+\mu a_{1})x_{1}+\ldots+(a_{m}'+\mu a_m)x_{m}=b'+\mu b.$$ Das heißt, man kann zwei lineare Gleichungen miteinander Addieren (hierbei ist eine der Gleichungen mit einem Faktor $\mu$ skaliert).

Der Gauß-Algorithmus funktioniert nun derart, dass man sein LGS schrittweise in die Zeilenstufenform bekommt, welches man daraufhin einfach lösen kann:

*Schritt 1:*
Addiere die erste Zeile derart auf alle darunterliegenden Zeilen, dass dort die Koeffizienten für $x_1$ gleich 0 sind.

*Schritt 2:*
Wiederhole Schritt 1 für das Pivot-Element aus Zeile 2 (für diese Variable sollen alle Koeffizienten nach Zeile 2 gleich 0 sein).

$\ldots$
*Schritt $n$:*
Wir sind in der letzten Zeile angekommen. Wir haben nun ein LGS in Zeilenstufenform.
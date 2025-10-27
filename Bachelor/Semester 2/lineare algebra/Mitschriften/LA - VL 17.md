Datum: 15.06.
[[ThR_LA_Skript.pdf|Skript]] von Seite 77 bis 92

*Kapitel 7*
# Die Welt der Matrizen
## Einheitsmatrix

> Die Identitätsfunktion im $\mathbb{K}^{n}$ wird dargestellt durch die $(n \times n)$-*Einheitsmatrix*:
> $$\text{DM}(\text{id}_{\mathbb{K}^{n}})=E_{n}=\begin{pmatrix}1&0&\ldots&0\\0&1&\ldots&0\\\vdots&\vdots&\ddots&\vdots\\0&0&\ldots&1\end{pmatrix}$$

Für eine $(n \times m)$-Matrix gilt:
> $$\begin{gather}A  \cdot E_{m}=A\\ E_{n}\cdot A = A\end{gather}$$

## Invertierbarkeit von Matrizen

> Falls $A$ eine quadratische Matrix ist und eine injektive (und damit auch bijektive) Funktion $f$ darstellt, dann gibt es genau eine inverse Matrix $A^{-1}$, welche die Umkehrfunktion $f^{-1}$ darstellt und es gilt:
> - $A \cdot A^{-1}=A^{-1} \cdot A = E_{n}$
> - $(A^{-1})^{-1}=A$
> - $(A \cdot B)^{-1}=B^{-1} \cdot A^{-1}$

Wir unterscheiden jetzt nicht mehr zwischen einer Matrix und der durch die Matrix dargestellten Funktion:
- $A(x):=A \cdot x$
- $A[X]:=\set{A \cdot x \mid x \in X}$
- $A^{-1}[Y]:=\set{x \in \mathbb{K}^{m}\mid A \cdot x \in Y}$
- $\text{Kern}(A):=A ^{-1}[\set{0}]$

*Kapitel 8*
# Amwembdung von Martix c:
## Lineare Codes
Mit Matrizen über dem Grundkörper $\mathbb{Z}^{2}$ kann man wunderbar [[Korrektur von Übertragungsfehlern|fehlerkorrigierende]], lineare Codes darstellen: hat man einen $(n,m)$-Code, in welchem man ein Wort $a$ der Länge $m$ mit einem Code $c$ der Länge $n$ darstellt, kann man die Codierung durch eine $(n \times m)$-Matrix $A$ darstellen: $$A \cdot a=c.$$
Darüber hinaus kann man eine Prüfmatrix mit den Dimensionen $(\text{lb}(n+1) \times n)$ angeben, welche man mit einem empfangenen Codewort multiplizieren kann, wobei:
- der Nullvektor nur herauskommt, wenn keine Übertragungsfehler passiert sind, und
- bei 1-Bit-Fehlern der Index des entsprechenden Fehlers angegeben wird.

## Transformationen in der reellen Ebene
### Drehungen

Sei $a\in \mathbb{R}^{2}$ ein Vektor. Möchte man diesen Vektor um einen Winkel $\gamma$ rotieren, sodass der Vektor $b \in \mathbb{R}^{2}$ herauskommt, dann geht das mit:
$$D_{\gamma}(a)=\begin{pmatrix}\cos(\gamma)&-\sin(\gamma)\\\sin(\gamma)&\cos(\gamma)\end{pmatrix}\cdot a=b.$$

Entsprechend gilt für Winkel $\varphi, \psi$ : $$D_{\varphi+\psi}=D_{\varphi}\cdot D_{\psi}.$$
*Trigonomietrische Zusammenhänge für Sinus und Kosinus:*
$$\begin{gather}
\sin(\varphi\pm\psi)=\sin (\varphi) \cos(\psi) \pm \cos (\varphi) \sin (\psi)\\
\cos(\varphi\pm\psi)=\cos(\varphi)\cos(\psi) \mp \sin(\varphi)\sin(\psi)\\
\cos(-\varphi)=\cos(\varphi)\\
\sin(-\varphi)=-\sin(\varphi)
\end{gather}$$

Daraus folgt:

$D_{-\varphi}=\begin{pmatrix}\cos(-\varphi)&-\sin(-\varphi)\\ \sin(-\varphi)&\cos(-\varphi\end{pmatrix}=\begin{pmatrix}\cos(\varphi)&\sin(\varphi)\\-\sin(\varphi)&\cos(\varphi)\end{pmatrix}$

### Spiegelungen

Die Spiegelung an einer Achse, welche mit einem Winkel $\frac{\gamma}{2}$ durch den Nullpunkt verläuft, lässt sich mit folgender Matrix darstellen:
$$S_{\frac{\gamma}{2}}=\begin{pmatrix}\cos(\gamma)&\sin(\gamma)\\ \sin(\gamma)&-\cos(\gamma)\end{pmatrix}.$$

Somit gilt:
$$S_{\frac{\gamma}{2}}\cdot S_\frac{\gamma}{2}=E_{2}.$$
> Die Verknüpfung zweier Spiegelungen ist eine Drehung:
> $$S_{\frac{\varphi}{2}}\cdot S_{\frac{\psi}{2}}=D_{\varphi-\psi}$$

## Matrizen als elementare Umformungen

Die folgenden drei Matrizen $C$, $D$ und $E$ heißen *Elementarmatrizen*.

### Vertauschen von Zeilen
Die Matrix, welche in einer anderen Matrix die $r$-te und $s$-te Zeile miteinander vertauscht, heißt **$C(r,s)$**. Sie sieht so aus wie die Einheitsmatrix, nur dass $r$-te und $s$-te Spalte miteinander vertauscht wurden.

Konkret:
- $A \in \text{Mat}(m \times n, \mathbb{K})$
- $C(r,s)\in \text{Mat}(m\times m, \mathbb{K})$
- $A_{r,s \text{ vertauscht}}=C(r,s) \cdot A$
- $C(r,s)\cdot C(r,s)=E_{m}$

### Skalarmultiplikation einer Zeile
Die Matrix, welche die $r$-te Zeile einer anderen Matrix mit einem Faktor $\lambda$ skaliert, heißt **$D(r,\lambda)$**. 
Sie sieht so aus wie die Einheitsmatrix, nur dass $e_{rr}=\lambda$ statt 1 ist.

$A_{r \text{ skaliert}}=D(r,\lambda)\cdot A.$

### Addition zweier Zeilen
Die Matrix, welche in einer anderen Matrix das $\lambda$-fache der $s$-ten Spalte auf die $r$-te Spalte addiert, heißt $E(r,s,\lambda)$.
Sie sieht so aus wie die Einheitsmatrix, nur dass $e_{rs}=\lambda$ statt 0 ist (bzw. $1+\lambda$, falls $r=s$).

$A_{r=r+\lambda s}=E(r,s,\lambda)\cdot A.$


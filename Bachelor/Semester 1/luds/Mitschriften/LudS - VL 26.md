Datum: 24.01.
[[26VL-Scan-AL-Formeln-Normalformen.pdf|Folien]]

# Normalformen
Wir kennen die [[Boolesche Algebra#Konjunktive Normalform (KNF)|KNF]] und die [[Boolesche Algebra#Disjunktive Normalform (DNF)|DNF]] bereits aus der booleschen Algebra.

In der Aussagenlogik lautet die Definition wie folgt:
> [!Definition]
> $\varphi\in AL$ ist in **kojunktiver Normalform** (KNF, Konjunktion von Disjunktion), falls $$\varphi=\bigwedge\limits_{i=1}^{n}\left(\bigvee\limits_{j=1}^{m_{i}}l_{i,j}\right)$$
> für $n,m_1,m_2,\ldots,m_{n}\in \mathbb{N}$ und Literale $l_{i,j}$.
> 
> $\varphi$ ist in **disjunktiver Normalform** (DNF, Disjunktion von Konjunktionen), falls:
>$$\varphi=\bigvee\limits_{i=1}^{n}\left(\bigwedge\limits_{j=1}^{m_{i}}l_{i,j}\right)$$

Beweis, dass man jeden Ausdruck in (beiden) Normalformen darstellen kann:
im Grunde wieder mit Wahrheitstabelle

$\varphi_{\text{DNF}}=\lnot(\lnot\varphi_\text{DNF})$$=\lnot\bigvee\limits_{i=1}^{k}\left(\bigwedge\limits_{j=1}^{m_{i}}l_{i,j}\right)=\bigwedge\limits_{i=1}^{k}\lnot \left(\bigwedge\limits_{j=1}^{m_{i}}l_{i,j}\right)=\bigwedge\limits_{i=1}^{k}\left(\bigvee\limits_{j=1}^{m_{i}}\lnot l_{i,j}\right)=\varphi_{\text{KNF}}$

Das ist aber ***$\Huge\text{INEFFIZIENT!!}$***

Anstatt immer über die Wahrheitstabelle zu laufen, kann man eine Formel auch mit dem folgenden Algorithmus in eine Normalform umwandeln:
1. $(\varphi_{1} \leftrightarrow \varphi_{2})$ ersetzen durch $((\varphi_{1} \rightarrow \varphi_{2}) \land (\varphi_{2} \rightarrow \varphi_{1}))$
2. $(\varphi_{1} \rightarrow \varphi_{2})$ ersetzen durch $(\lnot \varphi_{1} \lor \varphi_{2})$
3. $\lnot\lnot \varphi$ ersetzen durch $\varphi$
4. ...

und so.


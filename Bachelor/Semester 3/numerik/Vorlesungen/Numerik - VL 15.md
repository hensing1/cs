Datum: 02.02.

# Nichtlineare Gleichungen

Anstatt $\sigma(x) = y$ lösen wir mit $\sigma(x) - y = 0$ eine Nullstellenaufgabe.

## Konvergenzbegriffe

### Heron-Verfahren
Verfahren zur Berechnung der $\nu$-ten Wurzel einer Zahl $a \in \mathbb{C}\setminus \set{0}$.

$$x_{k+1}=\frac{1}{\nu}\left((\nu-1)x_{k}+ \frac{a}{x_{k}^{\nu-1}}\right)$$

- abstoßender Fixpunkt: Steigung Größer als 1
- anziehender Fixpunkt: Steigung ist kleiner als 1
	- $\to f(x_{1})-f(x_{0}) < x_{1} - x_{0}$ 
	- *Kontraktion*

Banachscher Fixpunktsatz:
- Monotonie: man rückt mit jedem Iterationsschritt um die Lipschitz-Konstante $q$ näher an den Fixpunkt heran
- 
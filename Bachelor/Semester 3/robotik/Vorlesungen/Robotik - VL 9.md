Datum: 07.12.
[[Robotik_09_Zustandsrueckfuehrung.pdf]]

Übung: [[Uebung_08.pdf]]
# Zustandsrückführung

## Steuerbarkeit und Beobachtbarkeit

Wir möchten einen Regler gestalten für ein lineares System:
![[Systemregelung_2.png]]

Dafür interessiert uns zunächst, ob das System überhaupt steuerbar ist.

> Ein System ist **steuerbar**, wenn es immer eine Eingabe $u$ gibt, um jeden Punkt im Zustandsraum zu erreichen.

Für ein [[Robotik - VL 8#Lineare Systeme|lineares System]] $\dot x = Ax + Bu$, $y = Cx + Du$ hängt die Steuerbarkeit von $A$ und $B$ ab.

### Steuerbarkeitstest

Ein lineares System ist genau dann steuerbar, wenn die *Steuerbarkeitsmatrix* vollen Rang hat: $$\begin{pmatrix}B & AB & A^{2}B & \ldots & A^{n-1}B\end{pmatrix}$$
## Konzepte zur Regelung

- Man braucht eine Systembeschreibung
- Stabilität: man möchte ein Reglungsverhalten finden, sodass das System aus beliebigem Startzustand sich asymptotisch einem Fixpunkt annähert
- Steuerbarkeit: man möchte eine Kontrollaktion finden, um das System von einem Startzustand in einen Endzustand überführt wird
- Folgeverhalten: man möchte, dass das System einer Trajektorie folgt

### Proportionalregler (P-Regler)

Für ein System mit Ausgabe $y(t)$ und Referenzeingabe $y_{r}(t)$ beschreibt $e(t) = y(t) - y_{r}(t)$ die Fehlergröße.

Ein P-Regler bestimmt die Stellgröße mit $u(t) = k_{p}e(t)$, d.h. die Stellgröße ist proportional zur Fehlergröße.

Vorteil: man braucht nur wenig Information über sein System.

Verhalten: 
- ist $k_p$ klein, langsame Annäherung an Sollwert, aber $e(t)$ bleibt größer 0
- ist $k_p$ groß, schießt man über das Ziel hinaus und man erhält Oszillationen

Hysterese: reagiere nur verzögert auf Änderungen in der Fehlerfunktion.
$\to$ Effekt: Oszillationen werden verlangsamt, Systemzustand schwingt um den Referenzwert

### Zustandsrückführung

Wir entwerfen einen Regler mithilfe einer **Gainmatrix** $K$:

$u = -Kx$
$\dot x = Ax - BKx = (A-BK)x$

Das ist dann stabil, wenn $A-BK$ stabil ist (Eigenwerte von $A-BK$ sollen Realteil kleiner 0 haben).


Man kann auf die Stellgröße dann auch noch eine skalierte Referenzgröße $r$ aufaddieren


### Normalform

### Regler mit Integrator

Wir sammeln den Fehler auf in einem Integral und speichern das auch im Zustand.
Wenn das System eingeschwungen ist, ist die Änderung dieses Integrals gleich 0 und $y=r$.

Führt trotzdem zu Überschwingen
Datum: 09.04.
[[1.1-IntroHeiratsproblem.pdf|Folien]]

# Heiratsproblem

## Problemstellung

**Gegeben:**
- Mengen $M$ und $F$ an Männern und Frauen, $|M| = |F|$
- Jeder $m \in M$ hat [[Relationen#Totale Ordnung|Reihung]] $<_m$ aller $f \in F$
- Jede $f \in F$ hat Reihung $<_f$ aller $m \in M$

$\Rightarrow m_{1} <_{f} m_{2}$ bedeutet: $f$ würde lieber $m_1$ als $m_{2}$ heiraten.

**Gesucht:**
- *Stabile Paarung* von je einer Frau und einem Mann.

Eine Paarung ist eine [[Funktionen#Bijektive Funktion|bijektive Abbildung]] $H: M \to F$.
$(m,f) \in H \Rightarrow H(m) = f,\, H^{-1}(f)=m.$

> [!abstract] Definition *Instabile Paarung*
> Zwei Paarungen sind instabil, wenn es zwei Personen gibt, die miteinander glücklicher wären als mit ihren zugeordneten Partnern. $$\exists m \in M, f \in F: (m,f)\not\in H \land f <_{m} H(m) \land m <_{f} H^{-1}(f)$$
> 
> Eine stabile Lösung für das Heiratsproblem enthält keine instabilen Paarungen.

## Algorithmus nach Gale & Shapley (1962)

> **Gale_Shapley(M, F) -> H**
> $H = \set{}$
> `while` $\exists m \in M, m \not \in H$:
> > $m$ macht oberster Frau $f$ einen Antrag
> > `if` $f \not \in H$:
> > > $H \leftarrow H \cup (m,f)$
> > 
> > `else`:
> > > $m' := H(f)$
> > > `if` $m <_{f} m'$:
> > > > $H \leftarrow H \setminus (m',f)$
> > > > $H \leftarrow H \cup (m,f)$
> > > > $m'$ streicht $f$ von seiner Liste
> > > 
> > > `else`:
> > > > $m$ streicht $f$ von seiner Liste
> 
> `return` $H$

### Eigenschaften

- Der Algorithmus terminiert immer, da in jeder Iteration die Liste eines Mannes schrumpft
- Es wird immer eine stabile Lösung gefunden
- Der Algorithmus findet unter allen stabilen Paarungen diejenige, die *Männer-optimal* und *Frauen-pessimal* ist
- Das Ergebnis des Algorithmus ist eindeutig.
- Für $n = |M| = |F|$ ist die Laufzeit in $\mathcal{O}(n^{2})$
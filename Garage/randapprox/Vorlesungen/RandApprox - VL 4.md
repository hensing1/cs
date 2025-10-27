Datum: 18.10.

# Approximationsschema für Scheduling auf identischen Maschinen

![[Scheduling auf identischen Maschinen#^bc085a]]

## Erster Ansatz
Nenne Job $j$ klein, falls $p_{j}\leq \epsilon \frac{1}{m}\sum\limits_{k=1}^{n} p_{k}$ - ansonsten groß.

- Berechne optimalen Schedule auf großen Jobs (alle Möglichkeiten ausprobieren)
- Ergänze kleine Jobs mit `LeastLoaded`

*Wieviele große Jobs kann man haben?*
$\to$ höchstens $\frac{m}{\epsilon}$ viele

D.h. es gibt $m^{m/\epsilon}$ mögliche Schedules für die großen Jobs. Für konstant viele Maschinen erhält man also polynomielle Laufzeit für jedes $\epsilon>0$.

### Approximationsfaktor
Betrachte Maschine mit größter Last.

Fall 1:
- Maschine enthält nur große Jobs $\to$ Maschine hat Last höchstens OPT, denn Schedule auf großen Jobs hat Makespan höchstens OPT.

Fall 2:
- Enthält mindestens einen kleinen Job. 
  Im Moment bevor `LeastLoaded` letzten kleinen Job zuweist, ist die Last höchstens $\frac{1}{m}\sum\limits_{k=1}^{n}p_{k}$.
  $\to$ Gesamtlast $\leq \frac{1}{m}\sum\limits_{k=1}^{n}p_{k}+\epsilon \frac{1}{m}\sum\limits_{k=1}^{n}p_{k} \leq (1+\epsilon)C(\pi ^{\ast})$

Die Last der einzelnen Maschinen unterscheiden sich also nicht mehr als die Größe eines kleinen Jobs.

## Bin-Packing mit konstant vielen Objektgrößen

![[Bin Packing#^2cb13e]]

Spezialfall:
> *Eingabe*
> - $(s_{1},\ldots,s_{z})\in \mathbb{N}^{z}$
> - $(n_{1},\ldots n_{z})\in \mathbb{N}^{z}$
> - $n=\sum\limits_{i=1}^{z} n_{i}$
> - $T \in \mathbb{N}$
> - $n_{i}$ der Größe $s_{i}$
> 
> Nun gibt es höchstens $n_{k}$ Objekte der Größe höchstens $s_{k}$.

Sei $\text{BINS}(i_{1},\ldots,i_{z})$ der optimale Zielfunktionswert, wenn es $i_{k}\leq n_{k}$ Objekte der Größe $s_{k}$ gibt.

Für unser Scheduling-Dings interessiert uns $\text{BINS}(n_{1},\ldots,n_{z})$.


Datum: 12.01.
[[23VL-Scan-RSA-Verfahren-Analyse.pdf|Folien]]

# RSA-Kryptosystem
> Asymmetrische Verschlüsselung

Es gibt einen public key (zum Verschlüsseln) und einen private key (zum Entschlüsseln). Der Vorteil: man muss keine Schlüssel oder sonst irgendwas geheim austauschen.

## Euler'sche $\varphi$-Funktion

Zunächst mal: der *Restklassenring* $(\mathbb{Z}_{n},\oplus_{n},\odot_{n})$ ist kommutativer Ring mit $\mathbb{1}$.
> Im Restklassenring modulo $n$ hat ein Element $[\![a]\!]_{n}$ *genau dann* ein multiplikatives Inverses, wenn $\text{ggT}(a,n)=1$.

Diese invertierbaren Elemente heißen *Einheiten*.

Zum Zählen dieser Einheiten gibt es die **Euler'sche $\varphi$-Funktion**:
$\varphi(n)=|\mathbb{Z}_{n}^{*}|=|\!\set{x \in \set{1,\ldots,n} \mid \text{ggT}(x,n)=1}|$.

### Primzahlen
Sei $p$ eine Primzahl. Dann gilt: $$\varphi(p)=p-1.$$
Sei $n=p \cdot q$ mit $p$ und $q$ Primzahlen. Dann gilt:
$$\varphi(n)=\varphi(p) \cdot \varphi(q) = (p-1)(q-1).$$

### Satz von Euler
Seien $n\in \mathbb{N}$ und $a \in \mathbb{Z}$ teilerfremd. Dann gilt:
$$a^{\varphi(n)}\equiv 1 \!\!\!\!\mod n.$$
#### Verallgemeinerung
Sei $G=\set{a_{1}=e,a_2,\ldots,a_m}$ und $(G,\cdot)$ eine [[Gruppe#Definition|abelsche Gruppe]]. Dann gilt:
$$\forall g \in G : g^m=e.$$

## Schlüsselerzeugung
1. Wähle zwei große Primzahlen $p$ und $q$. Setze $n=p \cdot q$.

2. Wähle $e \in \mathbb{N}$ mit $\text{ggT}(e,\varphi(n))=1$. Der *Public Key* ist $(n,e)$.
3. Berechne $d \in \mathbb{N}$ mit $e \cdot d \equiv 1 \!\!\!\mod \varphi(n)$.[^1][^2]Der *Private Key* ist $(n,d)$.

[^1]: Man berechnet $d$ mit dem erweiterten Euklidischen Algorithmus, indem man die Gleichung $e \cdot d + \varphi(n) \cdot x = 1$ löst. Diese Lösung muss existieren, da $e$ und $\varphi(n)$ teilerfremd sind.
[^2]: $d=e^{-1} \text{ in } \mathbb{Z}/\varphi(n)$

## Ver- und entschlüsseln
Man verschlüsselt einen Buchstaben (bzw. in der Praxis einen Buchstabenblock) mit dem Public Key des Empfängers:
$$y = E(x)=x^{e} \!\!\!\!\!\mod n$$
Der Empfänger kann dies nun mithilfe seines Private Key entschlüsseln:
$$D(y) = y^{d} \!\!\!\!\!\mod n = x$$
Hierbei muss natürlich $x<n$ gelten, sonst funktioniert es nicht.

## Korrektheit
Zu zeigen:
$$D(E(x))=(x^{e} \!\!\!\!\mod n)^{d} \!\!\!\!\mod n = (x^{e})^{d} \!\!\!\!\mod n = x^{e \cdot d} \!\!\!\!\mod n \stackrel{!}= x$$
bzw.
$$\begin{align*}
&[\![(m^e)^d]\!]_{n}=[\![m]\!]_{n}\\
\iff & n=p \cdot q \mid m^{e \cdot d}-m
\end{align*}$$


**Fall 1**: weder $p$ noch $q$ teilt $m$
$$\begin{align*}
[\![m^{e \cdot d}]\!]_{n} &= [\![m^{1+h \cdot \varphi(n)}]\!]_{n} &(e \cdot d \equiv 1 \!\!\!\!\mod \varphi(n))\\
&= [\![m \cdot (m^{\varphi(n)})^h]\!]_{n}\\
&= [\![m]\!]_{n} \odot_{n} ([\![m^{\varphi(n)}]\!]_{n})^{h}\\
&= [\![m]\!]_{n} \odot_{n} (\mathbb{1}_{n})^{h} & \text{(Satz von Euler)}\\
&= [\![m]\!]_{n}
\end{align*}$$
**Fall 2**: entweder $p$ oder $q$ teilt $m$
- Gelte o.E. $p \mid m$ und $q \not \mid m$
- $\Rightarrow p \mid m^{e \cdot d}-m$
- z.Z.: $q \mid m^{e \cdot d}-m$

$$\begin{align*}
[\![m^{e \cdot d}]\!]_{q}&=[\![m]\!]_{q} \odot_{q} [\![m^{\varphi(n)}]\!]_{q}^{h}\\
&= [\![m]\!]_{q} \odot_{q} [\![(m^{\varphi(p)})^{\varphi(q)}]\!]_{q}^h\\
&= [\![m]\!]_{q} \odot_{q} (\mathbb{1}_{q})^h\\
&= [\![m]\!]_{q}
\end{align*}$$
**Fall 3**: sowohl $p$ als auch $q$ teilt $m$
$$p \mid m \land q \mid m \Rightarrow pq=n \mid m \Rightarrow [\![m]\!]_{n}=\mathbb{0}_{n}=[\![m^{ed}]\!]_{n}$$

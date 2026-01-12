[[atcg2-06-Laplace_Beltrami_Operator.pdf]]

## Dirichlet Energy

Situation: wir haben eine offene Menge $\Omega \in \mathbb{R}^{2}$ und Werte für die **Randpunkte** $\partial \Omega$ gegeben durch $g: \partial \Omega \to \mathbb{R}$.
Wir möchten eine Funktion $f: \Omega \to \mathbb{R}$ finden, mit $f(p)=g(p) \ \forall p \in \partial \Omega$, die "so flach wie möglich" ist.

Wir auch in [[CV 6 - Snake 🐍|Snakes (Computer Vision)]] definieren wir einen **Energieterm** für $f$, den wir minimieren möchten: $$E[f] = \frac{1}{2} \int_{\Omega}\|\nabla f(u) \|_{2}^{2}\,du.$$
Also einfach die durschnittliche quadrierte Länge des [[Analysis - VL 17#^71f57b|Gradienten]].
Dieser Term ist das *Dirichlet Energie-Integral* und ist analog zur kinetischen Energie $\frac{1}{2}mv^{2}$.

$f$ optimieren bedeutet, dass $\frac{d}{d \epsilon} E[f + \epsilon h]|_{\epsilon=0}=0$ für alle Funktionen $h$ mit $h(u)=0,\,\forall u \in \partial \Omega.$


## Definition
$$
\log_{n}(b) :\Leftrightarrow \text{Das, womit ich n potenzieren muss, damit b rauskommt"}
$$
Heißt: der Logarithmus zur Basis $n$ (also $\log_n(x)$) ist die Umkehrfunktion von $n^x$.

## Bezeichnungen
- $\log_2(x)=\text{lb}(x)=\text{ld}(x)$
- $\log_e(x)=\ln(x)$
- $\log_{10}(x)=\lg(x)$
- $\log^2(x)=(\log(x))^2$

## Rechenregeln
### Umkehrfunktion
$$
b^{\log_b(x)}=\log_b(b^x)=x
$$
### Produkt
$$
\log(a\cdot b)=\log(a)+\log(b)
$$
### Quotient
$$
\log(a/b)=\log(a)-\log(b)
$$
Und damit auch: $$\log(x)=-\log\left(\frac{1}{x}\right)$$
### Potenz
$$
\log(a^b)=b\cdot\log(a)
$$
### Wurzel
$$
\log(\sqrt[n]{x})=\frac{\log(x)}{n}
$$
### Sonstige Tricks
$$
\log_n(x/n)=\log_n(x)-1
$$
$$
a^{\log_n(b)}=b^{\log_n(a)}
$$
$$
\log_a(n) = \frac{\log_b(n)}{\log_b(a)}
$$
$$
\log(1/x)=-\log(x)
$$
$$
\lfloor\log_b(x)\rfloor+1=\text{Anzahl der Stellen von }x\text{ in Basis }b
$$
$$
\log\left(\prod\limits_{i=k}^{n}x_{i}\right)=\sum\limits_{i=k}^{n}\log (x_{i})
$$
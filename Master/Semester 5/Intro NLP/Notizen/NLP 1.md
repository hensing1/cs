[[NLP-Lecture1-2026.pdf]]

**Word tokens** sind die leerzeichengetrennten Teile in einem Satz. **Word types** sind die tokens *ohne Duplikate*.

Verteilung von word types folgt einer Zipf'schen Verteilung, $c(w) \propto \frac{1}{r(w)}$ bzw. $\log(c(w))\propto-\log(r(w))$, für Wort $w$, Anzahl (Frequenz) $c(w)$ und Rang $r(w)$

Tokenisierung hat edge cases: URLs, Emoticons, Satzzeichen, spezielle Charaktere, ...

## Stemming & Lemmatization
Worte auf ihren Wortstamm reduzieren, um word types zusammenzufassen

**Stemming:**
Suffixe entfernen mit einfachem Text replacement
Bsp.:
- organizes, organized, organizing -> organ

**Lemmatisierung:**
Auf korrekten Wortstamm zurückführen
Bsp.:
- organizes, organized, organizing -> organize
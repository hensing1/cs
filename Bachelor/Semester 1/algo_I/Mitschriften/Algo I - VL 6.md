Kapitel 4: *Dynamische Mengen*
[Vorlesung](https://uni-bonn.sciebo.de/s/7Gfq3hL6DaUYioC#/files_mediaviewer/Vorlesung%20-%20Kapitel%204-1.mp4)
Folien: [[Bachelor/Semester 1/algo_I/Skript & Folien/algo_I_04.pdf|Kapitel 4.1 und 4.2]]

> [!abstract] Definition
> **Dynamische Menge**
> Eine dynamische Menge ist hier definiert als eine Datenstruktur, welche Element/Schlüssel-Paare abspeichert und die folgenden Operationen unterstützt:
> - `Search(k)` - Sucht nach einem Element mit Schlüssel `k` und gibt dieses ggf. zurürck
> - `Insert(x)` - Fügt ein Element `x` hinzu mit Schlüssel `x.key`
> - `Delete(k)` - Löscht das Element mit dem Schlüssel `k`

# Felder und Listen
## Verkettete Liste
- Speichert Daten (unsortiert) in einer verketteten Liste

### Laufzeit
- `Search(k)`: $\mathcal{O}(n)$ - man geht einfach die Liste durch
- `Insert(x)`: $\mathcal{O}(1)$ - Element wird einfach an den Anfang / das Ende gesetzt (wenn man auf Duplikate testen will, ist man wieder bei $\mathcal{O}(n)$)
- `Delete(k)`: $\mathcal{O}(n)$

Zu langsam!!!!!

## Array List
Auch "Implementierung mit einem dynamischen Feld"

### Laufzeit
- `Search(k)`: $\mathcal{O}(n)$
- `Insert(x)`: $\mathcal{O}(1)$, falls Array noch nicht voll ist - $\mathcal{O}(n)$ anderenfalls, da man das Array ersetzen muss (z.B. mit einem der doppelten Größe) und alle Werte einzeln rüberkopieren muss
- `Delete(k)`: $\mathcal{\Theta}(n)$ - damit man keine Lücke in seiner Datenstruktur hinterlässt, müssen alle Einträge, die hinter dem gelöschten Element liegen, nach vorne wandern

Die *amortisierte Laufzeit* (heißt: die durchschnittliche Laufzeit) von `Insert` bei einem dynamischen Feld beträgt $\mathcal{O}(1)$, ist also gar nicht so schlecht. 
Bei vielen Anwendungsfällen macht die variable Laufzeit aber die Array List ungeeignet.

Wenn man diese Datenstruktur dahingehend anpasst, dass die Werte sortiert sind, sinkt die Laufzeit von `Search` auf $\mathcal{O}(\log n)$ und die von `Insert` ist in allen Fällen $\mathcal{O}(n)$.

# Suchbäume
## Binärer Suchbaum
> Ein Binärbaum, bei dem an jedem Knoten $v$ alle Kinder im linken Teilbaum kleiner, und alle Kinder im rechten Teilbaum größer sind als der Inhalt von $v$ (bzw. die jeweiligen Schlüssel der Inhalte).

## Suchbaum als dynamische Datenstruktur
- `Search(k)`: man startet am Wurzelknoten und springt, falls man das Element dort nicht findet, rekursiv entweder in den linken oder rechten Teilbaum. Falls ein solcher Teilbaum nicht existiert, gibt man einen Nullzeiger zurück.
- `Insert(x)`: man ruft `Search(x.key)` auf und hängt sein Element (sofern es noch nicht im Baum ist) unter den zurückgegebenen Nullzeiger.
- `Delete(k)`: Schritt 1: nach dem Element suchen. Danach wird es etwas tricky
	- 1. Fall: das Element ist ein Blatt. Dann kann man es einfach löschen
	- 2. Fall: das Element hat genau ein Kind. Dann nimmt man den Zeiger, der auf das zu löschende Element zeigt (sofern einer existiert), und richtet ihn auf dieses Kind. Dann kann man den Knoten löschen. Existiert keiner, ist der Kindknoten die neue Wurzel.
	- 3. Fall: das Element hat zwei Kinder. Dann sucht man sich das kleinste Element aus dem rechten Teilbaum (also das kleinste Element im Baum, das größer ist als `k`) und setzt es an die Stelle vom zu löschenden Knoten. Das Ergebnis ist weiterhin ein binärer Suchbaum.

Für einen Suchbaum der Höhe $h$ liegen alle drei Operationen in $\mathcal{O}(h+1)$.[^1][^2]
Der Grund, warum man es nicht in Abhängigkeit von $n$ angibt, ist, dass der Baum für dasselbe $n$ völlig unterschiedliche Höhen haben kann - im Worst case ist $h=n$, im Best Case ist $h=\lceil\log_2(n+1)-1\rceil$.[^3]

[^1]: Man nimmt "$+1$", damit auch der Fall $h=0$ korrekt abgedeckt ist.
[^2]: Ein Baum, der nur aus einem Wurzelknoten besteht, hat die Höhe 0.
[^3]: $n \leq \sum\limits_{i=0}^{h}2^{i}=2^{h+1}-1\Rightarrow h \geq \log_{2}(n+1)-1$
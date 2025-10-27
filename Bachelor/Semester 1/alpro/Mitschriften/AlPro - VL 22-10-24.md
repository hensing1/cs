Folien: [[02_Imperative_Programmierung_mit_C++_02.pdf|Imperative Programmierung mit C++ - 02]]
# Funktionen
- Man kann Dinge in Funktionen auslagern, um sie wiederzuverwenden, wow!
- Funktionen haben Rückgabetypen
- Funktionen haben Parameter
- Funktionen müssen, wenn der Rückgabetyp nicht `void` ist, irgendwas zurückgeben
- Man kann Funktionen überladen

**Eigenheiten von C++**
Der Kompiler kompiliert eine C++-Datei von oben nach unten, heißt, um eine Funktion irgendwo zu verwenden, muss sie vorher definiert worden sein. Heißt, entweder so:
```cpp
void party_time() {
	/* ... */
}

int main() {
	party_time();
}
```

oder so:

```cpp
void party_time();

int main() {
	party_time();
}

void party_time() {
	/* ... */
}
```

# Git
Git halt.

## Was manche nicht wissen
- Der HEAD gibt den aktuell zu betrachtenen Commit an. Er ist quasi ein Zeiger auf genau einen Commit im Repository.
- Alle aktuellen Änderungen: `git diff`
- Alle Unterschiede zwischen zwei Commits / Branches: 
  `git diff AUSGANGSPUNKT_1 AUSGANGSPUNKT_2`

Datum: 18.01.
[[05_Objektorientierte_Programmierung_mit_C++_07.pdf|Folien]]

# Generische Programmierung
Wir möchten **Typparameter** zulassen, damit wir Implementierungen unabhängig von einem konkreten Typen ermöglichen können.[^1]

[^1]: Z.B. wie bei Containern

## UML
![[UML#Generische Typen]]

## Umsetzung in C++
### Klassentemplates
In C++ werden Generics mit *Templates* umgesetzt. Der generische Code wird einmal pro verwendetem Typparameter kompiliert. Man spart sich dadurch einen Typecast pro Aufruf, was die Performance verbessert.

```cpp
template<class T> // "T" kann man nun innerhalb dieser Klasse wie einen Typen verwenden
class X {
private:
	T data;
}

int main() {
	X<int> x1;    // Typ: X mit Typparameter int
	X<X<int>> x2; // Typ: X mit Typparameter X<int>
}
```

Generics gibt es auch zu Hauf in der C++-Standardbibliothek.

### Umsetzung unterhalb von C++
Für jeden verschiedenen, verwendeten Typparameter muss einmal das Klassentemplate (statisch) *instanziiert* werden. Hierbei spricht man auch von *Type generators*.

Für jede Templateinstanz wird vom Compiler eine Kopie des Templatecodes angelegt. In jeder Kopie wird dann der generische Typ durch den entsprechenden verwendeten Typen ersetzt.

### Organisation des Codes
Wegen der statischen Typgeneration muss die *Implementierung* des Templates entweder:
- ans untere Ende der Headerdatei, oder
- in eine `.ipp`-Datei im include-Verzeichnis.

Wäre die Implementierung, wie üblich, in einer separaten und nicht eingebundenen `.cpp`-Datei, dann wüsste der Compiler nicht unbedingt, wie groß die Funktionsparameter oder lokalen Variablen der Methoden dieses Typs sind.

### Funktionstemplates
Neben Schablonen für Klassen gibt es auch Schablonen für Funktionen.

```cpp
template<class T>
void drucke_iterierbares(const T& x) {
	for (const auto& element : x) {
		std::cout << element << std::endl;
	}
}
```

Wenn man irgendwo im Code diese Funktion mit einem nicht-iterierbaren Typen aufrufen möchte, kann man es nicht kompilieren. Der Compiler kopiert & kompiliert diese Funktion einmal pro benötigten Typ.

### Templates mit zusätzlichen Konstanten
Man kann beliebig viele Typen in sein Template packen.
Man kann auch eine Kombination von generischen Typen und Konstanten haben - ein Beispiel dafür ist `std::array<T,N>`.
`std::array<double, 3>` ist dann ein Typ, der 3 doubles in einem Array speichert. Hat man zusätzlich `std::array<double, 4>`, dann wird dafür vom Compiler eine neue Typinstanz erstellt.

### Templatespezialisierung
Wenn man eine spezielle Implementierung für einen bestimmten Typen haben möchte, kann man das mit Templatespezialisierung machen. Z.B. gibt es eine spezielle Implementierung für `std::vector<bool>`, damit man acht bools pro Byte abspeichern kann.

Wenn man irgendwas partiell Spezialisiert hat (wenn eine Klasse mehrere generische Typen verwendet), wird bei der Templateinstanziierung immer das speziellste Template verwendet.

## Vererbung mit Templates
Gegeben eine Klasse `B<T>`, dann kann man auch z.B. von `B<int>` erben. `C<BaseClass>` steht *nicht* mit `C<SubClass>` in einer Vererbungshierarchie. Ansonsten wäre nämlich das Liskovsche Substitutionsprinzip verletzt.

Beispiel: `Liste<Katze>` ist keine Spezialisierung von `Liste<Tier>`, da sich Funktionsparameter kontravariant verhalten. `Liste<Katze>::add(Katze)` kann deshalb nicht `Liste<Tier>::add(Tier)` überschreiben.

## Iteratoren
Mit Iteratoren durchläuft man einen iterierbaren Container.
Ein iterierbarer Container `C` gibt mit `C.begin()` bzw. `C.cbegin()` einen Iterator zurück, der auf das erste (bzw. ein erstes) Element zeigt.
Der Iterator zeigt an, dass er das Ende erreicht hat, wenn er gleich dem Iterator `C.end()` bzw. `C.cend()` ist.

Ein Iterator hat die folgenden Typeigenschaften:
- Die Kategorie gibt an, welche Art von Iterator implementiert wird
	- konkret gibt es die Kategorien forward, bidirectional, random-access, output, input
- Der Iterator weiß, welcher grundlegende Elementtyp durchlaufen wird
- Arrayiteratoren speichern die Pointer-Differenz (die Distanz zwischen den Adressen zweier Elemente (glaub ich))
- Ein Pointer auf das aktuelle Element
- Eine Referenz auf das aktuelle Element

Eine eigene Iteratorimplementierung für eine verkettete Liste könnte also so aussehen:
```cpp
class mein_iterator : public std::iterator<  
	std::forward_iterator_tag, // iterator_category  
	Node,                      // value_type  
	std::ptrdiff_t,            // difference_type  
	Nodeptr,                   // pointer  
	Node&&                     // reference  
>  
{ 
private:
	pointer _p;
public:  
	mein_iterator(mein_iterator::pointer p) : _p(p) {} // zur Initial. durch Container
	mein_iterator& operator++() {                // ++it  
		if(_p) { _p = _p->next; }
		return *this;
	}   
	mein_iterator operator++(int) {              // it++ [int ist ein Dummyparameter]  
		mein_iterator retval = *this;
		++(*this);
		return retval;
	} 
	bool operator==(mein_iterator other) const { // it == anderer_it  
		return _p == other._p;
	} 
	bool operator!=(mein_iterator other) const { // it != anderer_it 
		return !(*this == other);
	}  
	reference operator*() const {return *_p;}    // *it  
};
```

Normalerweise definiert man die Iteratorklasse innerhalb vom Container.

```cpp
class Liste{  
public:  
	...  
	
	// Definition der Iteratorklasse innerhalb des Containers  
	class mein_iterator : public std::iterator< /* Wie oben */ > {  
		/* Wie oben */  
	};  
	
	mein_iterator begin() {return mein_iterator(this->head);}  
	mein_iterator end() {return mein_iterator::pointer(nullptr);}
	
	...
};
```
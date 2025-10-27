Datum: 23.01.
[[05_Objektorientierte_Programmierung_mit_C++_08.pdf|Folien]]

# Mehr zu Iteratoren
Es gibt Funktionen aus dem Standardpaket `<algorithm>`, um für iterierbare Container bestimmte Umformungen durchzuführen oder Eigenschaften festzustellen. 
Diese arbeiten mit dem Iterator des entsprechenden Containers.

```c++
std::set<int> zahlen({ 2, 6, 1, 3, 9, 4, 5 });  
auto ist_gerade = [] (int x) -> bool { return x % 2 == 0; };  
auto ist_fuenffach = [] (int x) -> bool { return x % 5 == 0; };  
auto ist_zehnfach = [] (int x) -> bool { return x % 10 == 0; };  

bool alle_gerade = std::all_of (begin(zahlen), end(zahlen), ist_gerade); // false  
bool irgendwer_fuenffach = std::any_of(begin(zahlen), end(zahlen), ist_fuenffach);
					                                                     // true  
bool keiner_zehnfach = std::none_of(begin(zahlen), end(zahlen), ist_zehnfach); // true
```

`begin(zahlen)` ist äquivalent zu `zahlen.begin()`.

Weitere Funktionen aus `<algorithm>`:
- `std::for_each(begin_it, end_it, fn)`: führt Funktion für jedes Objekt im iterierbaren Container aus
- `std::for_each_n(begin_it, n, fn)`: führt Funktion für die ersten `n` Objekte aus
- `std::count(begin_it, end_it, el)`: zählt, wie oft im Container `el` enthalten ist
- `std::count_if(begin_it, end_it, fn)`: zählt, wieviele Objekte im Container `fn` erfüllen
- ...
- `std::generate(begin_it, end_it, fn)`: füllt den Container mit den Rückgaben der Funktion `fn`
- `std::transform(source_cbegin_it, source_cend_it, target_begin_it, fn)`: tranformiert die Elemente des Containers mit `fn` und schreibt sie in einen Zielcontainer
	- Start- und Zielcontainer dürfen auch derselbe sein

# Der ganze Rest von C++
## Mehr Zugriffssteuerung

### Protected
Erlaubt den Zugriff von Subklassen auf Attribute von Überklassen. Funktioniert genau wie `protected` in anderen Programmiersprachen.

In UML kennzeichnet man `protected`-Attribute mit "#".

### Friend
Mit dem `friend`-Keyword kann man ausgewählten (Member-)Funktionen oder ausgewählten Klassen Zugriff auf private Membervariablen gestatten.

```c++
class Studi {  
private:  
	int matrikelnummer;  
	std::string vorname;  

// Erlaubt die Konstruktion std::cout << Studiobjekt;  
friend std::ostream& operator<<(std::ostream&, const Studi&);  
};  

// Überlade std::ostream & operator<<(std::ostream &os, const T&);  
std::ostream& operator<<(std::ostream &os, const Studi& s) { 
	return os << "Name: " << s.name << "; Matrikelnummer: " << s.matrikelnummer;  
} 

int main() {  
	Studi s(/* Konstruktorparameter */);  
	std::cout << s << std::endl;  
}
```

### Ändern von Const-Variablen
```c++
const_cast<T&>(x) = w // Fasst x vom Typ const T als T& auf und ändert dann den Wert
```

## Verschiedenes Gedöns
### Verschachtelte Klassen
Falls Klassen oder Structs zwar für Implementierungsdetails verwendet werden, aber nicht nach außen zur Verfügung gestellt werden sollen, kann man sie auch innerhalb einer anderen Klasse (üblicherweise als private Member einer Oberklasse) definieren.

```c++
class Liste {  
/* ... */  
private:  
	struct Node { /* ... */ }; // Implementierungsdetails  
/* ... */  
};
```

### Final
Verhindert weiteres Überschreiben einer Methode. Die Methode bleibt aber weiterhin virtuell, auch in den Subklassen.

### Destructors
Das Gegenteil von Constructors. Wird insbesondere dann verwendet, wenn man mit Rawpointern arbeitet. Sonnst muss und sollte kein Destructor implementiert werden.

Konstruktor für Typen `T`: `T::T(/*Params*/)`
Destruktor für Typen `T`: `T::~T(/*Params*/)`

### Static
Member, die unabhängig von einer Instanz existieren sollen, heißen *statisch* oder auch *Klassenmember*.

Wenn eine statische Membervariable instanziiert werden muss, sollte das in der *Quelldatei* geschehen. Sonst geschieht die Initialisierung bei jedem Einbinden des Headers.

### Enums
Gibt es auch in C++.

```c++
enum Farbe { rot, gruen, blau };  
Farbe x = rot;  
if (x == blau) {  
	std::cout << "Die Farbe ist blau." << std::endl;  
}
```

### Multiple Inheritance
Man kann in C++ von mehreren Klassen erben.
```c++
class D : public Base1, Base2 { }
```

Man muss aber darauf aufpassen, dass man den **Deadly Diamond of Death** vermeidet:
![[DDD.png|280]]

### Interfaces
Eine **abstrakte Klasse** ist eine Klasse, die mindestens eine *rein virtuelle Funktion*, also eine Funktion ohne Implementierung besitzt. Eine abstrakte Klasse kann nicht instanziiert werden.

Ein **Interface** in C++ ist eine abstrakte Klasse, die *ausschließlich* rein virtuelle Funktionen enthält.

#### UML
![[UML#Abstrakte Klassen und Interfaces]]

Datum: 16.01.
[[05_Objektorientierte_Programmierung_mit_C++_06.pdf|Folien]]

# Subtypenbeziehungen
## Typkonvertierung
Eine Typkonvertierung (type cast) findet dann statt, wenn ein Objekt mit Typ X gegeben ist, aber ein Typ Y benötigt wird. 

Es gibt *implizite* und *explizite* Casts. 
Ein impliziter Cast sieht so aus:

```cpp
short s = 4;
int a = 4;

// Implizite Umwandlung short -> int
int b = a + s;

// Implizite Umwandlung int -> double
double d = b;
```

Explizite casts gibt es (u.a.) als `static_cast<NeuerTyp>(...)` und `dynamic_cast<NeuerTyp>(...)`.
`static_cast` wird verwendet, um einen statischen Typen in einen anderen zu überführen, wofür der alte statische Typ in den neuen *überführbar* sein muss. Es finden dabei **keine Prüfungen zur Laufzeit** statt.

```cpp
long long int a = 4;  
 
// Compiler warnt wegen impliziter Konvertierung,  
// die eventuell verlustbehaftet ist  
int b = a;  
 
// Keine Warnung: Der Programmierer sagt explizit,  
// dass er genau diese Umwandlung möchte  
int b = static_cast<int>(a);
```

`static_cast` kann man auch dazu verwenden, um in der Vererbungshierarchie nach unten zu konvertieren:
```cpp
Derived d();
d.f(); // sei f() nicht virtuell. 

Base &bref = d;
bref.f(); // Base::f wird aufgerufen, da Überdeckung aufgehoben

// Derived &dref = bref;  // geht nicht
Derived &dref = static_cast<Derived&>(bref);// nicht zur Laufzeit überprüft, ob zulässig
											// -> undefined behavior falls verkehrt
dref.f(); // Derived::f aufgerufen - Überdeckung wiederhergestellt
```

Extra-Überprüfungen gehen mit `dynamic_cast`. Es muss der alte dynamische Typ in den neuen umwandelbar sein.
Falls nicht, wird die Exception `std::bad_cast` geworfen.

```cpp
Derived &dref = dynamic_cast<Derived&>(bref); // Überprüfung zur Laufzeit
```

### Typkonvertierung von Pointern
Für Pointer stehen analog `static_pointer_cast` und `dynamic_pointer_cast` zur Verfügung.
Ist die Zuweisung bei `dynamic_pointer_cast` nicht zulässig, wird keine Exception geworfen, sondern ein Nullpointer zurückgegeben.

## Ersetzbarkeit von Parametern und Rückgaben
Bei der Übergabe von Parametern dürfen (als Kopie sowie als Referenz) speziellere Typen übergeben werden:
```cpp
class B {  
public:  
	void f() {std::cout << "B::f" << std::endl;}  
	void virtual g() {std::cout << "B::g" << std::endl;}  
};  
class D: public B {  
public:  
	void g() override {std::cout << "D::g" << std::endl;}  
};  

void call_by_value(B b) { 
	b.f(); // Verwendet B::f(), denn b ist vom Typ B  
	b.g(); // Verwendet B::g(), denn b ist vom Typ B  
}  

void call_by_reference(B& b) {
	b.f(); // Verwendet B::f(), denn b ist vom Typ B-Ref  
	b.g(); // Verwendet D::g(), denn b ist vom Typ B-Ref
}

int main() {  
	D d;  
	call_by_value(d);
	call_by_reference(d);  
}
```

Genauso darf ein *speziellerer Typ* **zurückgegeben werden**.

### Überladene Funktionen
Übergibt man einer überladenen Funktion einen spezielleren Typen, sucht sich der Compiler (falls möglich) das am besten Passendste raus. Am Beispiel $B \leftarrow D \leftarrow E$:
```cpp
void f(const B&) { std::cout << "f(const B&)" << std::endl; }  
void f(const D&) { std::cout << "f(const D&)" << std::endl; }  
...  
f(E(0.9)); // druckt "func(const D&)".
```

```cpp
void f(const B&, const D&) { std::cout << "f(const B&, const D&)" << std::endl; }  
void f(const D&, const B&) { std::cout << "f(const D&, const B&)" << std::endl; }  
...  
f(E(0.9), B(1.0)); // druckt "f(const D&, const B&)"  
f(E(0.9), E(1.0)); // error: call of overloaded 'f(E&, E&)' is ambiguous
```

## Ko- und Kontravariantes Verhalten
Die *Parameter* in einer abgeleiteten Klasse dürfen nur allgemeiner werden. Das heißt **Kontravariantes Verhalten**, da es in die Umgekehrte Richtung der Vererbungshierarchie geht.

Die *Rückgabetypen* in einer abgeleiteten Klasse dürfen nur spezieller werden. Das heißt **Kovariantes Verhalten**.

![[SOLID-Prinzipien#Liskovsches Substitutionsprinzip]]

# Exceptions
Exceptions in C++ funktionieren genauso wie in C# oder Java.

Um seine eigene Exception zu definieren, erbt man von `std::exception` oder einem spezifischeren Typen wie `std::logic_error`.
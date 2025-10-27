Datum: 09.01.
Folien: [[05_Objektorientierte_Programmierung_mit_C++_04.pdf|Objektorientierte Programmierung mit C++ - 04]]

# Vererbung
> [!abstract] Typerweiterung
> Bei der **Typerweiterung** erbt eine Subklasse von einer Basisklasse und fügt eigene Attribute und Memberfunktionen hinzu - sie erweitert also die Funktionalität gegenüber der Basisklasse.
> Die privaten Membervariablen und Memberfunktionen der Oberklasse sind Teil der Unterklasse, sie dürfen aber in den hinzugefügten Memberfunktionen der Unterklasse nicht direkt verwendet werden.

## Qualified Identifier in C++
Ein Qualified Identifier ist ein Bezeichner für eine Klasse oder eine Funktion, welcher angibt, zu welcher Klasse / zu welchem Namespace er gehört. Das passiert mit dem Symbol `::`.

Steht nichts links von `::`, ist das der *absolute Pfad* im globalen Namespace.

Beispiel:
`MyClass::f()` - die Memberfunktion `f()` der Klasse `MyClass`
`::std::cout` - das Objekt `cout` gehört zum Namespace `std`, der wiederum teil des globalen Namespace ist.

Wenn man einen relativen Pfad angibt, wird der Namespace / die Klasse ganz links zuerst im aktuellen Namespace gesucht, und dann im darüberliegenden.

## Implementierung & Instanziierung

Bei der Instanziierung einer abgeleiteten Klasse wird zuerst der Konstruktor der Parent-Klasse aufgerufen.

```cpp
class BaseClass {  
public:  
	BaseClass() {std::cout << "BaseClass() ";}  
	BaseClass(int x) {std::cout << "BaseClass(" << x << ") ";}  
};

class DerivedClass : public BaseClass {  
public:  
	DerivedClass() : BaseClass(-100) {std::cout << "DerivedClass()";}  
	DerivedClass(int x) : BaseClass(x) {std::cout << "DerivedClass(" << x << ")";}  
}

int main() {  
	DerivedClass x; // BaseClass(-100) DerivedClass()  
	DerivedClass y(42); // BaseClass(42) DerivedClass(42)  
}
```

## Namehiding
Situation: man hat eine Klasse `B` und eine Klasse `D`, die von `B` erbt. 
Außerdem hat `B` eine öffentliche Memberfunktion `f()`.

Wenn nun `D` auch die Funktion `f()` implementiert, wird `B::f()` "überdeckt", d.h. ein Objekt `d` vom Typ `D` ruft mit `d.f()` seine eigene Funktion auf, und nicht die der Base-Klasse. Man kann die Base-Funktion trotzdem mit `d.B::f()` aufrufen.

$\rightarrow$ soll man nicht machen, denn ist nicht leicht nachzuvollziehen.


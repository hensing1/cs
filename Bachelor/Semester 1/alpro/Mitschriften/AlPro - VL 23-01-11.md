Datum: 11.01.
Folien: [[05_Objektorientierte_Programmierung_mit_C++_05.pdf|Objektorientierte Programmierung mit C++ - 05]]

# Typkonkretisierung
Wir möchten in Unterklassen Memberfunktionen *überschreiben* (nicht einfach nur verstecken).

Mal angenommen, `Polygon` erbt von `GeschlKurve` und hat eine (andere) Methode `getUmfang()`.

```cpp
void drucke_umfang(const GeschlKurve& K) {  
	std::cout << "Der Umfang ist" << K.getUmfang() << "." << std::endl;  
} 

int main() {  
	Polygon p = ...;  
	drucke_umfang(p);  
	// p wird als GeschlKurve-Ref übergeben.  
	// Falls getUmfang _verdeckt_ ist, wird GeschlKurve::getUmfang verwendet.  
	// Falls getUmfang _überschrieben_ ist, wird Polygon::getUmfang verwendet.  
}
```

Angenommen `D` *überschreibt* die Funktion `B::f` und wir haben ein `D`-Objekt `obj`.  
- Falls `obj` als `B`-Referenz oder `B`-Zeiger übergeben wird, dann entspricht `obj.f` der  
Memberfunktion `D::f`.
- Falls `obj` als `B`-Kopie übergeben wird, dann entspricht `obj.f` der Memberfunktion  
`B::f`.

Wenn `D` nur `B::f` *verdeckt*, wird in beiden Fällen `B::f` aufgerufen.


Eine überschreibbare Memberfunktion heißt auch **virtuell**. Ein Typ mit mindestens einer virtuellen Memberfunktion (egal ob er sie geerbt oder selbst deklariert hat) heißt **polymorph**.

## Umsetzung in C++

```cpp
class B {  
public:  
	virtual void f();  // B::f ist virtuell  
	void g();          // B::g ist nicht virtuell  
	void h();          // B::h ist nicht virtuell  
};  
class D : public B {   // D erbt von B  
public:  
	void f();          // D::f überschreibt B::f und ist virtuell  
	virtual void g();  // D::g verdeckt B::g und ist virtuell  
	void h();          // D::h verdeckt B::h und ist nicht virtuell  
//  void h() override; // erzeugt Compilerfehler, weil B::h nicht virtuell ist  
};
```

Um eindeutiger zu sein, hätte man in `D` auch `void f() override;` schreiben können.

Damit man eine Funktion überschreiben darf, müssen also die folgenden Bedingungen erfüllt sein:
- In der Überklasse muss die Funktion als `virtual` deklariert sein
- In der Unterklasse muss die Methodensignatur identisch sein
	- allgemeinere Parametertypen und speziellere Rückgabetypen sind erlaubt, ansonsten muss alles identisch sein (inkl. `const`- und Reference-Qualifiern)

## Abstrakte Methoden
Sollen Methoden in der Überklasse *rein* virtuell sein, also ohne dass eine Implementierung vorgegeben wird, heißt diese Methode **abstrakt**. In UML wird das mit `{abstract}` oder in kursiv angegeben.

In C++ wird eine virtuelle Memberfunktion dadurch virtuell, dass sie mit `= 0` beendet wird. Dann kann man die entsprechende Klasse nicht mehr instanziieren:

```cpp
class GeschlKurve {  
public:  
	virtual double getUmfang() const = 0; // Rein virtuelle Funktion  
};  
...  
int main() {  
	GeschlKurve g; // Compilerfehler - GeschlKurve enthält eine rein virtuell Funktion  
	Polygon p; // Da getUmfang in Polygon überschrieben wird, gelingt die Instanziierung  
}
```

## Darstellung im Speicher
> **Virtuelle Memberfunktionen** werden im Attributblock als `vtable` organisiert. Das ist eine Tabelle von Funktionszeigern. *Das Überschreiben ersetzen Einträge in der `vtable`.*

Welche (Member)funktion genau aufgerufen wird, steht bei nicht-virtuellen Funktio-  
nen zur Compilezeit fest. Bei virtuellen Memberfunktionen wird mithilfe der `vtable`  
zur Laufzeit bestimmt, welche Funktion genau aufgerufen wird.  

Die Funktionsauswahl zur Compilezeit nennt man **statisches Binden** und die Funkti-  
onsauswahl zur Laufzeit nennt man **dynamisches Binden**.

Bei der Übergabe by reference (oder mit Zeiger) werden also nicht-virtuelle Memberfunktionen statisch gebunden[^2], während virtuelle Memberfunktionen dynamsich gebunden werden[^3].

[^2]: dafür wird der statische Typ verwendet
[^3]: dafür wird der dynamische Typ verwendet

## Statische und dynamische Typen
Im folgenden Beispiel
```cpp
Derived d;  
Base& b = d;
```

verhält sich `b` wie eine `Derived`-Referenz. Der *statische Typ* von `b` ist `Base` und der *dynamische Typ* von `b` ist `Derived`.

Der statische Typ kann in C++ mit `decltype(EXPRESSION)` herausgefunden werden, der dynamische mit `typeid(EXPRESSION)`[^1].

[^1]: Für `typeid` braucht man `#include <typeinfo>`.
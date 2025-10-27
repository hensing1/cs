Datum: 12.12.21
Folien: [[04_Algorithmen_Teil_2_08.pdf|Algorithmen Teil 2 - 08]]

# Beliebige Vergleichsfunktionen
Wir möchten eine **[[Relationen#Totale Ordnung|totale Ordnung]]** unter einer Menge von Elementen schaffen. Wir brauchen das, damit wir *Assoziative Container* umsetzen können (Geordnete Mengen (z.B. AVL-Baum), Hashende Mengen (`set`), Abbildungen (`map`)).
Dafür müssen wir Objekte anhand einer bestimmten Messgröße miteinander vergleichen kann.
Diese Messgröße kann z.B. durch eine [[Hashing|Hashfunktion]] bestimmt werden.

Dafür braucht man einen Vergleichsoperator. In C++ kann man das mit einem *Funktionsobjekt* umsetzen.

## Funktionsobjekte in C++
### Implementierung als Klasse
Ein Objekt ist ein Funktionsobjekt, falls das Objekt den *Funktionsaufrufsoperator* implementiert.

Das ist eine Memberfunktion mit dem Namen `operator()`: 
`RÜCKGABETYP KLASSENNAME::operator() ( /* Parameter */  )`

```cpp
// HEADERDATEI  
class Zaehler {  
public:  
	Zaehler(int start); // Konstruktur  
	int operator() (void); // Gibt zurück wie oft der Zaehler verwendet wurde  
private:  
	int anzahl;  
};

// QUELLDATEI  
Zaehler::Zaehler(int start) : anzahl(start) {}  
int Zaehler::operator() (void) { return anzahl++; }  

// DEMO  
int main() {  
	Zaehler v(100); // Zaehler ist ein Funktionsobjekt  
	std::cout << v() << " " << v() << " " << v() << std::endl; // Druckt: '100 101 102'  
}
```

### Funktionen als Funktionsobjekt
Der Typ eines Funktionsobjekts ist `std::function<RÜCKGABETYP(PARAM1, PARAM2, ...)>`. Man kann einem Objekt mit diesem Typen eine beliebige Funktion mit dem entsprechenden Rückgabetyp und Parametern zuweisen:

```cpp
#include <functional> // Wird eingebunden um mit std::function zu arbeiten

int f() {...}  
bool g(int x, int y) {...}  

// Erzeugt ein (leeres) Funktionsobjekt das keine Parameter erhält und int-Werte produziert  
std::function<int(void)> fobj1;
fobj1 = f; // fobj1 speichert ein Funktionsobjekt dass zur Funktion f gehört  
// Erzeugt ein (leeres) Funktionsobjekt das zwei int-Parameter erhält und bool-Werte produziert  
std::function<bool(int, int)> fobj2;  
fobj2 = g; // fobj2 speichert ein Funktionsobjekt das zur Funktion g gehört
```

Man kann auch ein Klassen-Funktionsobjekt als Instanz von `std::function` nehmen.

### Lambdafunktionen
Lambdafunktionen werden zur Laufzeit definiert, haben keinen eigenen Namen und heißen daher auch *anonyme Funktionen*.

```cpp
std::function<RUECK(TYPPAR1, TYPPAR2, ...)> f =
	[cap1, cap2, ...] (TYPPAR1 par1, TYPPAR2 par2) -> RUECK {
		CODE
	};
```

`cap1` und `cap2` sind hierbei Namen von Variablen, welche zum Deklarationszeitpunkt definiert sind. Sie können via const value (standardmäßig), const reference, oder reference übergeben werden.

### Funktionspointer
Man kann auch (das kommt von C) Rawpointer auf Funktionen haben, das ist effizienter als Funktionsobjekte, aber nicht so gut wartbar. Hier in der Vorlesung machen wir das nicht.

## Abstrakte Datentypen und Datenstrukturen
Mit Funktionsobjekten übergibt man geordneten Mengen eine Compare-Funktion und hashenden Mengen eine Hash-Funktion.

In C++ gibt es folgende Datenstrukturen:

| **Abstrakter Datentyp**                           | **Datenstruktur**                                   |
| ------------------------------------------------- | --------------------------------------------------- |
| Stack                                             | `std::stack`                                        |
| Queue                                             | `std::queue`                                        |
| Liste                                             | `std::forward_list` bzw. `std::list`                |
| Array                                             | `std::vector`                                       |
| [[Heaps#Prioritätswarteschlange\|Priority Queue]] | `std::priority_queue`                               |
| geordnete [[Mengen\|Menge]]                       | `std::set` bzw. `std::multiset`                     |
| geordnete Abbildung                               | `std::map` bzw. `std::multimap`                     |
| [[Hashing\|hashende]] Menge                       | `std::unordered_set` bzw. `std::unordered_multiset` |
| hashende Abbildung                                | `std::unordered_map` bzw. `std::unordered_multimap` |


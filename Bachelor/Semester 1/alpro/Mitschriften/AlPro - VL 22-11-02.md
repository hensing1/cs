Folien: [[02_Imperative_Programmierung_mit_C++_05.pdf|Imperative Programmierung mit C++ - 05]]

# Objektorientierte Programmierung

## Objekte und Klassen

> [!abstract] Objekt
> Entgegen der imperativen Programmierung, bei denen Daten und der Code, der sie verarbeitet, getrennt voneinander vorliegen, werden in der OOP Daten und dazugehöriger Programmcode zu **Objekten** zusammengefasst.
> 
> Ein Objekt besitzt weiterhin die folgenden Dinge:
> - Einen *Objekttyp*
> - Memberfunktionen für Zugriff auf, und Verwaltung von, Objektdaten

Jeder Objekt stammt von einer zugehörigen Klasse, welche den Objekttyp und alle dazugehörigen Daten und Funktionen definiert. Ein Objekt heißt auch *Instanz* der entsprechenden Klasse.

## Anlegen einer Klasse in C++
Die Ordnerstruktur innerhalb eines C++-Projekts sieht folgendermaßen aus:
```
+--docs  
|  
+--examples  
|  |  
|  +--main.cpp  <- Für beispielhaften Code zur Verwendung der Klasse
|  
+--include  
|  |  
|  +--mein_namespace  
|     |  
|     + meine_klasse.hpp  <- Definition von Konstanten und Funktionen
...
|  
+--src  
|  |  
|  +--meine_klasse.cpp  <- Implementierung der Funktionen
...  
|  
CMakeLists.txt <- Vereinfacht den Kompilierungsprozess
```

### Headerdatei
```cpp
#ifndef __NAME_DER_KLASSE_HPP__  // Dieses Konstrukt hilft, bei größeren Projekten
#define __NAME_DER_KLASSE_HPP__  // zyklische Einbindungen zu vermeiden.

// Nötige Includes  
...  

namespace mein_namespace {  
	class NameDerKlasse {  
	public:  
		// Konstruktor(en) deklarieren:  
		NameDerKlasse();  
		...  
		// Deklaration der Memberfunktionen  
		RueckgabetypABC MemberfunktionABC( /* Parameter */ );  
		RueckgabetypDEF MemberfunktionDEF( /* Parameter */ );  
		...  
	private:  
		// Deklaration der Membervariablen  
		...  
	}; // <-- Nicht das Semikolon vergessen!  
}  
#endif
```

### Quelldatei
```cpp
// Für die Implementierung der Klasse wird die Klassendeklaration benötigt  
#include <mein_namespace/name_der_klasse.hpp>  

// Weitere Includes  
...  

// Der Namespace des Projekts wird auch für die Definition der Memberfunktion verwendet  
namespace mein_namespace {  

	// Der volle Name der Memberfunktion ist bei der Definition anzugeben  
	// Wir beginnen mit einem der Konstruktoren  
	NameDerKlasse::NameDerKlasse() {  
		...  
	}  
	// Nun werden die restlichen Memberfunktionen implementiert.  
	RueckgabetypABC NameDerKlasse::MemberfunktionABC( /* Parameter */ ) {  
		...  
	}  
	RueckgabetypDEF NameDerKlasse::MemberfunktionDEF( /* Parameter */ ) {  
		...  
	}  
}
```

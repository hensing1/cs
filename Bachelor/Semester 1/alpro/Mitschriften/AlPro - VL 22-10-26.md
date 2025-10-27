Folien: [[02_Imperative_Programmierung_mit_C++_03.pdf|Imperative Programmierung mit C++ - 03]]
# Ein- und Ausgabe von Text
## String Theory
`string` ist in C++ kein Datentyp, sondern eine Klasse. Um mit Strings zu arbeiten, muss man die Klasse vorher einbinden:

```cpp
#include <string>
...
std::string mein_text = "Hallo Mama";
```

Mit dem `+`-Operator können strings vereinigt werden.

```cpp
std::cout << "Hallo" + " " + "Mama" << std::endl;
```

### Konvertierung von und zu Strings
```cpp
#include <string>
...
std::string zahl = std::to_string(42);
int richtige_zahl = std::stoi("42");
double gleitkommazahl = std::stod("42.0000000001");
```

## I/O Stream
```cpp
#include <iostream>
#include <string>
...
// Eingabe:
std::string user_input;
std::cin >> user_input;
// Ausgabe:
std::cout << "Dankeschön" << std::endl;
```

# Arrays
## Arten von Arrays
### C-Arrays
- Sind in die Programmiersprache eingebacken und können nicht besonders viel (sind nur aufeinanderfolgende Speicheradressen)
```cpp
int mein_array[5]; //reserviert 5 aufeinander folgende Speicherpläzte für den Typ `int`
mein_array[3] = 19;
4[mein_array] = 20; // geht auch! Macht zwar niemand, aber geht auch!

int mein_anderes_array[4] = { 1, 2, 3, 4 }; // Vorbelegung mit Werten
int irgendein_müll = mein_anderes_array[8]; // Das geht! Kommt halt irgendein Müll bei raus, da irgendeine Speicheradresse als int erpretiert wird. Ist halt dein Problem

int länge_meines_anderen_arrays = sizeof(mein_anderes_array) / sizeof(int); // ein int belegt 4 Speicheradressen (4 Bytes)

char ich_bin_ein_string[] = "Hello World"; // -> char[11]

int random_noise[10]; // hier kann jetzt irgendwas drinstehen. Die Werte werden nicht vorbelegt.
```

### C++-Arrays (statisch)
Hier haben wir nun ein Objekt. Unter der Haube verhält es sich aber genauso wie ein C-Array.

```cpp
#include <array>
...
std::array<int, 3> mein_array = {1, 2, 3}; //Vorbelegtes Array der Länge 3
int irgendein_müll = mein_array[8]; // Das geht immer noch!

int länge_meines_arrays = mein_array.size();
```

### C++-Arrays (dynamisch)
```cpp
#include <vector>
...
std::vector<int> mein_array = {};
for (int i = 0; i < 5; i++) {
	mein_array.push_back(i);
}

int irgendein_müll = mein_array[8]; //jup

int länge_meines_arrays = mein_array.size();

std::vector<int> luftballons(99); // Dynamisches Array der Länge 99. Alle Werte sind mit 0 initialisiert, ungleich beim C-Array
```

Für den Zweck dieser Vorlesung ist mit "Array" ab sofort "dynamisches C++-Array" gemeint, da dies für die allermeisten Zwecke die bessere Wahl ist.

## Iteration über Arrays
### Range Based For-Loop
```cpp
std::array<int, 4> zahlen = {3, 6, 9, 12};

// Iteration mit Kopien der Zahlen (können verändert werden, wirkt sich nicht aufs Array aus)
for (int i : zahlen) {
	/*...*/
}

// Iteration mit Referenzen auf die Zahlen (können verändert werden, wirkt sich aufs Array aus)
for (int& i : zahlen) {
	/*...*/
}

// Iteration mit const-Referenzen auf die Zahlen (können nicht verändert werden)
for (const int& i : zahlen) {
	/*...*/
}
```

# Darstellung von Kram im Speicher
## Einteilung des virtuellen Adressraums
![[Speicherverwaltung in C++#Stackpeicher]]

![[Speicherverwaltung in C++#Heapspeicher]]

## Byte-Darstellung von Datentypen
Ein `int` besteht aus vier Bytes, die an vier aufeinanderfolgenden Speicheradressen im virtuellen Namensraum abgelegt werden (je zwei Hexziffern landen in einem Byte). Die Bytereihenfolge ist bei einer x86-64-Architektur [[Glossar#Little-Endian, Big-Endian|little-endian]].

# Call me, baby
## Call by Value
```cpp
void mach_was(int zahl) {
	zahl++;
	/* macht was */
}

int main() {
	int zahl = 5;
	mach_was(zahl);
	// zahl ist immer noch 5
}
```

## Call by Reference
```cpp
void swap(int& i, int& j) {
	int temp = i;
	i = j;
	j = temp;
}

int main() {
	int i = 5;
	int j = 10;
	swap(i, j);
	// j = 5 und i = 10
}
```

## Call by Const Reference
```cpp
// soll das Array nicht verändern, druckt ja nur aus
void druck_was_aus(const std::vector<std::string>& array) {
	/* druckt aus */
}

int main() {
	std::vector<std::string> worte = {"Eins", "Zwei", "Polizei"};
	druck_was_aus(worte);
}
```